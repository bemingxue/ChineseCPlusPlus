
namespace BE {

   /**
    * \brief >>> 一个使用单向链表实现的栈功能类，支持元素的压栈、弹出等，并存储栈的长度，不提供构造函数。
    * \tparam TmpT： 栈中元素的类型。
    */
   template<typename TmpT>
   struct 栈表类 : 错误类
   {
      struct 栈节点类
      {
         TmpT    *节点数据;
         栈节点类 *后节点;
      };

      /**
       * \brief >>> 向栈中压入一个新的元素。
       * 
       * \param 构造参数表： 要传递给新元素的构造参数表。
       * \return this &
       * \tparam TmpArgs： 可以被 STmpT 构造函数接受的参数表。
       */
      template<typename... TmpArgs>
      栈表类 &插入(TmpArgs&&... 构造参数表)
      noexcept(noexcept(安全构造类型<TmpT, TmpArgs...>))
      requires(构造类型<TmpT, TmpArgs...>)
      {
         栈节点类 *新节点 = 创建节点<TmpT>(std::forward<TmpArgs>(构造参数表)...);

         if (新节点 == 空指针)
         {
            this->类中错误 = ::BE::错误集::内存分配错误;
            return *this;
         }

         if (this->类中栈顶 == 空指针)
         {
            this->类中栈顶 = 新节点;
         }
         else
         {
            新节点->后节点 = this->类中栈顶;
            this->类中栈顶 = 新节点;
         }

         this->类中长度 += 1;
         return *this;
      }

      /**
       * \brief >>> 向栈顶压入一个新的元素，插入函数的别名。
       * 
       * \param 构造参数表： 要传递给新元素的构造参数表。
       * \return this &
       * \tparam TmpArgs： 可以被 STmpT 构造函数接受的参数表。
       */
      template<typename... TmpArgs>
      栈表类 &压栈(TmpArgs&&... 构造参数表)
      noexcept(noexcept(安全构造类型<TmpT, TmpArgs...>))
      requires(构造类型<TmpT, TmpArgs...>)
      {
         return 插入(std::forward<TmpArgs>(构造参数表)...);
      }

      /**
       * \brief >>> 从栈中弹出一个元素。
       * 
       * \return this &
       */
      栈表类 &删除() noexcept
      {
         if (this->类中栈顶 != 空指针)
         {
            栈节点类 *前节点 = this->类中栈顶;
            this->类中栈顶 = this->类中栈顶->后节点;
            this->类中长度 -= 1;

            释放节点(前节点);
         }

         return *this;
      }

      /**
       * \brief >>> 从栈顶弹出一个元素，删除函数的别名。
       * 
       * \return this &
       */
      栈表类 &弹出() noexcept
      {
         return this->删除();
      }

      /**
       * \brief >>> 弹出栈顶元素，将其指针返回，如果栈为空则返回空指针，注意自行手动管理指针的生命周期。
       * 
       * \return 被弹出的元素指针或空指针。
       */
      TmpT *删除并获取() noexcept
      {
         if (this->类中栈顶 != 空指针)
         {
            TmpT *返回值 = this->类中栈顶->节点数据;
            栈节点类 *前节点 = this->类中栈顶;
            this->类中栈顶 = this->类中栈顶->后节点;
            this->类中长度 -= 1;

            ::BE::释放原始内存(前节点);
            return 返回值;
         }

         return 空指针;
      }

      /**
       * \brief >>> 弹出栈顶元素，将其指针返回，如果栈为空则返回空指针，注意自行手动管理指针的生命周期。
       * 
       * \return 栈顶元素指针或空指针。
       */
      TmpT *弹出并获取() noexcept
      {
         return this->删除并获取();
      }

      /**
       * \brief >>> 获取当前栈的长度。
       * 
       * \return 栈的长度，即元素数量。
       */
      类型长度 获取长度() const noexcept
      {
         return this->类中长度;
      }

      /**
       * \brief >>> 判断栈是否为空。
       * 
       * \return 空则返回假，否则返回真。
       */
      类型逻辑 非空的() const noexcept
      {
         return this->类中栈顶 != 空指针;
      }

      /**
       * \brief >>> 获取栈顶的元素。
       * 
       * \return 栈顶元素引用。
       */
      TmpT &获取元素() noexcept
      {
         return *this->类中栈顶->节点数据;
      }

      /**
       * \brief >>> 获取栈顶的元素。
       * 
       * \return 栈顶元素只读引用。
       */
      const TmpT &获取元素() const noexcept
      {
         return *this->类中栈顶->节点数据;
      }

      /**
       * \brief >>> 释放栈中的所有元素。
       * 
       * \return this &
       */
      栈表类 &释放() noexcept
      {
         while (this->类中栈顶 != 空指针)
         {
            栈节点类 *前节点 = this->类中栈顶;
            this->类中栈顶 = this->类中栈顶->后节点;

            释放节点(前节点);
         }

         this->类中长度 = 0;
         return *this;
      }

      ~栈表类() noexcept
      {
         this->释放();
      }

      protected:

      栈节点类 *类中栈顶 = 空指针;
      类型长度  类中长度 = 0;
   
      // 创建一个节点，构造其中的数据，并将其返回，如果分配失败则返回空指针。
      template<typename TmpU, typename... TmpArgs>
      static 栈节点类 *创建节点(TmpArgs&&... 构造参数表) noexcept(noexcept(安全构造类型<TmpT, TmpArgs...>))
      {
         栈节点类 *返回值 = ::BE::分配原始内存<栈节点类>(1);

         if (返回值 != 空指针)
         {
            返回值->节点数据 = ::BE::分配原始内存<TmpU>(1);

            if (返回值->节点数据 != 空指针)
            {
               ::BE::直接构造(返回值->节点数据, 1, std::forward<TmpArgs>(构造参数表)...);
               返回值->后节点 = 空指针;
            }
            else
            {
               ::BE::释放原始内存(返回值);
               返回值 = 空指针;
            }
         }

         return 返回值;
      }

      // 释放一个节点，析构其中的数据，始终认为节点项中的数据不为空指针。
      static 类型空的 释放节点(栈节点类 *节点项) noexcept
      {
         if (节点项 != 空指针)
         {
            ::BE::直接析构(节点项->节点数据, 1);
            ::BE::释放原始内存(节点项->节点数据);
            ::BE::释放原始内存(节点项);
         }
      }
   };

}
