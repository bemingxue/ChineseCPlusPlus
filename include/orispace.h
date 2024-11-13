
namespace BE {

   // 原始空间类存储数据的结构。
   template<typename TmpT>
   struct 原始空间结构
   {
      TmpT    *指针     = 空指针;
      类型长度 总长度   = 0;
      类型长度 当前长度 = 0;
   };

   /**
    * \brief >>> 从内存中分配内存空间并管理其生命周期的可迭代空间类，使用原始管理，即不构造、不析构，也不提供复制，只能移动。允许继承此类并修改内存分配和释放行为。
    * \brief >>> 类型提供有效范围和无效范围支持，迭代器迭代有效范围。
    * \brief >>> 注意，如果分配内存失败则类会设置错误信息。
    * \brief >>> 继承自：错误类。
    * \tparam TmpT： 数据类型，尽可能应当使用平凡类型，因为类型不会进行构造和析构。
    */
   template<typename TmpT>
   struct 原始空间类 : protected 原始空间结构<TmpT>, public 错误类
   {
      // 启用全局运算符。
      using EGO = void;

      // 存储数据的类型。
      using 类中数据类 = 原始空间结构<TmpT>;

      // 以当前存储的指针作为迭代器，注意空指针。
      TmpT *begin() noexcept { return this->获取指针(); }
      TmpT *end() noexcept { return this->获取指针() + this->获取长度(); }

      // 以当前存储的指针作为迭代器，注意空指针。
      const TmpT *begin() const noexcept { return this->获取指针(); }
      const TmpT *end() const noexcept { return this->获取指针() + this->获取长度(); }

      // 默认构造函数。
      原始空间类() noexcept
      {

      }

      // 分配指定长度的内存空间并且置零，如果内存分配失败则设置错误信息。
      原始空间类(类型长度 长度项) noexcept
      {
         this->赋值(长度项);
      }

      // 获取目标对象中数据的所有权，并清空目标对象。
      原始空间类(原始空间类 &&赋值项) noexcept
      {
         this->赋值(std::move(赋值项));
      }

      // 复制构造函数，禁止使用。
      原始空间类(const 原始空间类 &) noexcept = delete;

      /**
       * \brief >>> 为当前对象分配指定长度的内存空间并且置零，如果内存分配失败则使长度归零并设置错误信息。
       * 
       * \param 长度项： 指定分配的长度，如果长度和当前存储的总长度相同则只会清零当前指针指向的内存块，并将当前长度赋值为 0。
       * \return this &
       */
      原始空间类 &赋值(类型长度 长度项) noexcept
      {
         // 长度相同则只需清零当前指针指向的内存块
         if (长度项 == this->获取总长度())
         {
            ::BE::填充零(this->指针, 长度项);

            this->当前长度 = 0;
            return *this;
         }

         // 检查是否分配成功。
         if (!(this->指针 = this->分配内存(长度项)))
         {
            this->总长度 = this->当前长度 = 0;
            this->设置错误(::BE::错误集::内存分配错误);

            return *this;
         }

         ::BE::填充零(this->指针, 长度项);

         this->总长度 = 长度项;
         this->当前长度 = 0;
         return *this;
      }

      /**
       * \brief >>> 将目标对象中的数据所有权移动到当前对象中，并清空目标对象。
       * 
       * \param 赋值项： 要移动的对象。
       * \return this &
       */
      原始空间类 &赋值(原始空间类 &&赋值项) noexcept
      {
         static_cast<类中数据类 &>(*this) = ::BE::交换赋值(static_cast<类中数据类 &>(赋值项), 类中数据类{ });
         return *this;
      }

      /**
       * \brief >>> 直接设置有效范围的长度，如果大于总长度则设置为总长度的值。
       * 
       * \param 长度项： 要设置的值，默认为设置所有范围为有效范围。
       * \return this &
       */
      原始空间类 &设置有效范围(类型长度 长度项 = 到末尾) noexcept
      {
         this->当前长度 = ::BE::最小值(this->总长度, 长度项);
         return *this;
      }

      /**
       * \brief >>> 调整有效范围的长度，不同于设置，如果长度项大于当前总长度则会分配新的内存。
       * 
       * \param 长度项： 要调整的值。
       * \param 复制否： 如果分配新的内存，是否将原来有效范围中的数据复制到新内存中。
       * \param 有效范围否:  当需要复制时,是否只复制有效范围内容的数据,默认为 true。
       * \return this &
       */
      原始空间类 &调整有效范围(类型长度 长度项, 类型逻辑 复制否 = true, 类型逻辑 有效范围否 = true) noexcept
      {
         if (长度项 > this->总长度)
         {
            类型长度 原长度 = 有效范围否 ? this->当前长度 : this->总长度;
            TmpT *备份 = this->结束管理();

            // 分配内存失败则释放备份后立即退出函数。
            if (!this->赋值(长度项))
            {
               this->释放内存(备份);
               return *this;
            }

            if (复制否)
            {
               ::BE::复制(this->指针, 备份, 备份 + 原长度);
            }

            this->释放内存(备份);
         }

         // 大于当前长度或者小于当前长度都直接调整。
         this->当前长度 = 长度项;
         return *this;
      }

      /**
       * \brief >>> 返回存储的指针并置空当前对象，并且不再负责对返回的指针的生命周期管理。
       * 
       * \return 存储的指针。
       */
      TmpT *结束管理() noexcept
      {
         TmpT *返回值 = ::BE::交换赋值(this->指针, 空指针);

         this->当前长度 = this->总长度 = 0;
         return 返回值;
      }

      /**
       * \brief >>> 获取当前对象中存储的指针。
       * 
       * \return 存储的指针。
       */
      TmpT *获取指针() noexcept
      {
         return this->指针;
      }

      /**
       * \brief >>> 获取当前对象中存储的指针。
       * 
       * \return 存储的只读指针。
       */
      const TmpT *获取指针() const noexcept
      {
         return this->指针;
      }

      /**
       * \brief >>> 获取当前对象中有效范围的长度。
       * 
       * \return 有效范围长度。
       */
      类型长度 获取长度() const noexcept
      {
         return this->当前长度;
      }

      /**
       * \brief >>> 获取当前对象中存储的总长度。
       * 
       * \return 总长度。
       */
      类型长度 获取总长度() const noexcept
      {
         return this->总长度;
      }

      /**
       * \brief >>> 判断两者存储的指针是否相同。
       * 
       * \param 比较项： 要比较的对象。
       * \return 相同返回真，否则返回假。
       */
      类型逻辑 相等判断(const 原始空间类 &比较项) const noexcept
      {
         return this->获取指针() == 比较项.获取指针();
      }

      /**
       * \brief >>> 比较两者存储的指针。
       * 
       * \param 比较项： 要比较的对象。
       * \return 如果当前指针大于目标指针则返回大于零的值，等于则返回零，小于则返回小于零的值。
       */
      类型逻辑 比较判断(const 原始空间类 &比较项) const noexcept
      {
         return this->获取指针() - 比较项.获取指针();
      }

      /**
       * \brief >>> 释放当前对象中存储的指针并置空当前对象。
       * 
       * \return this &
       */
      原始空间类 &释放() noexcept
      {
         this->释放内存(this->指针);
         
         this->指针 = 空指针;
         this->当前长度 = this->总长度 = 0;
         return *this;
      }

      /**
       * \brief >>> 交换当前对象和目标对象中的数据。
       * 
       * \param 交换项： 要交换的对象。
       * \return this &
       */
      原始空间类 &交换(原始空间类 &交换项) noexcept
      {
         ::BE::交换(static_cast<类中数据类 &>(*this), static_cast<类中数据类 &>(交换项));
         return *this;
      }

      /**
       * \brief >>> 判断当前存储的指针指向是否为空。
       * 
       * \return 不为空则返回真，否则返回假。
       */
      类型逻辑 非空的() const noexcept
      {
         return this->获取指针() != 空指针;
      }

      // 安全析构函数，调用释放函数。
      ~原始空间类() noexcept
      {
         this->释放();
      }

      // 复制赋值运算符，禁止使用。
      原始空间类 &operator = (const 原始空间类 &) noexcept = delete;

      // 获取目标对象中数据的所有权，并清空目标对象。
      原始空间类 &operator = (原始空间类 &&赋值项) noexcept
      {
         return this->赋值(std::move(赋值项));
      }

      // 获取存储的指针指向的内存块的第 n 个元素的引用，注意空指针和越界访问。
      TmpT &operator [] (类型长度 索引项) noexcept
      {
         return this->指针[索引项];
      }

      // 获取存储的指针指向的内存块的第 n 个元素的只读引用，注意空指针和越界访问。
      const TmpT &operator [] (类型长度 索引项) const noexcept
      {
         return this->指针[索引项];
      }

      // 如果既没有错误也不是空指针则返回真，否则返回假，explicit 的。
      explicit operator 类型逻辑() const noexcept
      {
         return this->非空的() && this->无错误的();
      }

      protected:

      // 释放内存时调用的函数。
      类型空的 释放内存(TmpT *指针项) noexcept
      {
         ::BE::释放原始内存(指针项);
      }

      // 分配内存时的调用的函数。
      TmpT *分配内存(类型长度 长度项) noexcept
      {
         return ::BE::分配原始内存<TmpT>(长度项);
      }

   };

}
