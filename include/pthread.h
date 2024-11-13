
namespace BE {

   struct 线程池类
   {
      using 线程类 = std::jthread;
      using 条件锁类 = std::condition_variable;
      using 互斥锁类 = std::mutex;
      using 唯一锁类 = std::unique_lock<互斥锁类>;
      using 任务函数 = std::function<void()>;

      static constexpr 类型长度 默认线程数 = 4;

      线程池类(类型长度 数量项 = 默认线程数) noexcept
      {
         this->类中状态 = 假;
         this->类中工作数 = 0;

         // 创建线程。
         while (数量项 != 0)
         {
            this->类中线程池.插入([this] () noexcept {
               // 循环并尝试捕获任务。
               while (true)
               {
                  任务函数 捕获函数;

                  {
                     唯一锁类 唯一锁 { this->类中互斥锁 };

                     // 如果当前线程池被释放或者任务队列中存在任务则唤醒线程。
                     this->类中条件变量.wait(唯一锁, [this] { return this->类中状态 || this->类中队列.非空的(); });

                     // 线程被唤醒时如果线程池被释放并且队列为空则结束线程。
                     if (this->类中状态 && !this->类中队列.非空的())
                     {
                        return;
                     }

                     // 从队列中捕获出任务。
                     捕获函数 = std::move(*--this->类中队列.end());

                     this->类中队列.删除(--this->类中队列.end());
                     this->类中工作数 += 1;
                  }

                  // 执行任务，不加锁。
                  捕获函数();

                  {
                     唯一锁类 唯一锁 { this->类中互斥锁 };
                     this->类中工作数 -= 1;
                  }
               }
            });

            数量项 -= 1;
         }

      }

      /**
       * \brief >>> 向任务队列中添加新的任务，函数会将函数和参数进行绑定并添加到队列末尾（首）中。
       * 
       * \param 任务项： 任务函数。
       * \param 参数表： 任务函数的参数表。
       * \return 
       */
      template<typename... TmpArgs, 调用类型<TmpArgs...> TmpCall>
      类型空的 添加任务(TmpCall &&任务项, TmpArgs &&... 参数表) 
      noexcept
      {
         任务函数 新任务 = std::bind_front(std::forward<TmpCall>(任务项), std::forward<TmpArgs>(参数表)...);

         {
            唯一锁类 唯一锁 { this->类中互斥锁 };

            if (this->类中状态)
            {
               return;
            }

            // 将新任务添加到队列首。
            this->类中队列.插入(std::move(新任务), this->类中队列.begin());
         }

         // 通知一个正在被阻塞的线程有新任务了。
         this->类中条件变量.notify_one();
      }

      /**
       * \brief >>> 获取线程池中线程的数量。
       * 
       * \return 线程数量。
       */
      类型长度 获取线程数() const noexcept
      {
         return this->类中线程池.获取长度();
      }

      /**
       * \brief >>> 获取队列中剩余的任务数量。
       * 
       * \return 任务数量。
       */
      类型长度 获取队列长度() const noexcept
      {
         return this->类中队列.获取长度();
      }

      /**
       * \brief >>> 获取正在工作的线程数量。
       * 
       * \return 正在工作的线程数量。
       */
      类型长度 获取工作线程数() const noexcept
      {
         return this->类中工作数;
      }

      // 等待所有任务和线程结束并安全析构。
      ~线程池类() noexcept
      {
         {
            唯一锁类 唯一锁 { this->类中互斥锁 };
            this->类中状态 = 真;
         }

         // 通知所有线程。
         this->类中条件变量.notify_all();

         // 等待所有线程都结束。
         for (线程类 &线程 : this->类中线程池)
         {
            线程.join();
         }
      }

      protected:

      链表类<线程类> 类中线程池;
      链表类<任务函数> 类中队列;

      条件锁类 类中条件变量;
      互斥锁类 类中互斥锁;
      类型逻辑 类中状态;
      类型长度 类中工作数;


   };

}
