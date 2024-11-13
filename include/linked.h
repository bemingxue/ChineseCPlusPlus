
#define 链表校验宏(LinkedObj, ...)   if(LinkedObj->类中错误 == ::BE::错误集::严重内存分配错误) { return __VA_ARGS__; }

namespace BE {

   /**
    * \brief >>> 一种使用循环链表构成的双向链表容器，允许基本的链表操作和双向迭代器，注意，虽然使用循环链表实现，但不建议将其当作循环链表使用。
    * \brief >>> 注意，链表会在初始化时构建一个特殊的头节点，如果这个节点构建失败，则整个链表都以当废弃无法使用，因此请注意其错误信息。
    * \tparam STmpT 链表中节点的数据类型。
    */
   template<对象类型 STmpT>
   struct 链表类 : 错误类
   {
      using 标准数组标识 = void;

      // 链表中节点的基本结构，存储前后节点以及数据指针。
      struct 表节点类
      {
         STmpT    *节点数据;
         表节点类 *前节点;
         表节点类 *后节点;
      };

      // 链表的只读迭代器，满足双向迭代器需求。
      struct 只读迭代器类 final
      {
         只读迭代器类() noexcept = default;

         只读迭代器类(表节点类 *节点项) noexcept : 当前节点(节点项) 
         {
         
         }

         const STmpT &operator * () noexcept
         {
            return *this->当前节点->节点数据;
         }

         const STmpT *operator -> () noexcept
         {
            return this->当前节点->节点数据;
         }

         只读迭代器类 &operator ++ () noexcept
         {
            this->当前节点 = this->当前节点->后节点;
            return *this;
         }

         只读迭代器类 operator ++ (int) noexcept
         {
            只读迭代器类 临时 = *this;
            this->当前节点 = this->当前节点->后节点;
            return 临时;
         }

         只读迭代器类 &operator -- () noexcept
         {
            this->当前节点 = this->当前节点->前节点;
            return *this;
         }

         只读迭代器类 operator -- (int) noexcept
         {
            只读迭代器类 临时 = *this;
            this->当前节点 = this->当前节点->前节点;
            return 临时;
         }

         类型逻辑 operator == (const 只读迭代器类 &比较项) const noexcept
         {
            return this->当前节点 == 比较项.当前节点;
         }

         // 获取存储的节点指针，如果要获取节点，并修改节点中的数据，请明白你要做什么。
         表节点类 *获取节点() noexcept
         {
            return this->当前节点;
         }

         private:
         表节点类 *当前节点;
      };

      // 链表的可写迭代器，满足双向迭代器需求。
      struct 可写迭代器类 final
      {
         可写迭代器类() noexcept = default;

         可写迭代器类(表节点类 *节点项) noexcept : 当前节点(节点项) 
         {
         
         }

         STmpT &operator * () noexcept
         {
            return *this->当前节点->节点数据;
         }

         STmpT *operator -> () noexcept
         {
            return this->当前节点->节点数据;
         }

         可写迭代器类 &operator ++ () noexcept
         {
            this->当前节点 = this->当前节点->后节点;
            return *this;
         }

         可写迭代器类 operator ++ (int) noexcept
         {
            可写迭代器类 临时 = *this;
            this->当前节点 = this->当前节点->后节点;
            return 临时;
         }

         可写迭代器类 &operator -- () noexcept
         {
            this->当前节点 = this->当前节点->前节点;
            return *this;
         }

         可写迭代器类 operator -- (int) noexcept
         {
            可写迭代器类 临时 = *this;
            this->当前节点 = this->当前节点->前节点;
            return 临时;
         }

         类型逻辑 operator == (const 可写迭代器类 &比较项) const noexcept
         {
            return this->当前节点 == 比较项.当前节点;
         }

         // 允许隐式转换为可读迭代器类型，因为链表相关处理函数只处理只读迭代器。
         operator 只读迭代器类() noexcept
         {
            return 只读迭代器类(this->当前节点);
         }

         // 获取存储的节点指针，如果要获取节点，并修改节点中的数据，请明白你要做什么。
         表节点类 *获取节点() noexcept
         {
            return this->当前节点;
         }

         private:
         表节点类 *当前节点;
      };

      // 使用链表专属迭代器，注意虽然底层采用循环链表，但请勿循环迭代。
      可写迭代器类 begin() noexcept { return 可写迭代器类(this->类中表头->后节点); }
      可写迭代器类 end()   noexcept { return 可写迭代器类(this->类中表头); }
      // 使用链表专属迭代器，注意虽然底层采用循环链表，但请勿循环迭代。
      只读迭代器类 begin() const noexcept { return 只读迭代器类(this->类中表头->后节点); }
      只读迭代器类 end()   const noexcept { return 只读迭代器类(this->类中表头); }

      // 默认构造函数。
      链表类() noexcept
      {
         this->初始化链表();
      }

      // 复制构造函数。
      链表类(const 链表类 &复制项) noexcept : 链表类()
      {
         this->赋值(复制项);
      }

      // 移动构造函数。
      链表类(链表类 &&赋值项) noexcept
      {
         // 目标链表没有初始化成功则赋值失败，那么就需要进行初始化，否则不需要初始化。
         if (赋值项.类中错误 == ::BE::错误集::严重内存分配错误)
         {
            this->初始化链表();
            return;
         }

         this->类中表头 = ::BE::交换赋值(赋值项.类中表头, 空指针);
         this->类中长度 = ::BE::交换赋值(赋值项.类中长度, 0);
         this->类中错误 = ::BE::交换赋值(赋值项.类中错误, ::BE::无错误);
         
         赋值项.初始化链表();
      }

      // 用迭代范围中的元素初始化链表，迭代元素要能被 STmpT 构造。
      template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>>
      链表类(InputT 开始项, InputT 结束项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, IDRT>))
      requires(可赋值或构造类型<STmpT, IDRT>) : 链表类()
      {
         this->赋值(开始项, 结束项);
      }

      // 用列表项中的元素初始化链表，列表项元素要能被 STmpT 构造。
      template<typename TmpT>
      链表类(const 模板列表类型<TmpT> &列表项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, TmpT>))
      requires(可赋值或构造类型<STmpT, TmpT>) : 链表类()
      {
         this->赋值(列表项);
      }

      // 用可迭代对象中的迭代范围中元素初始化链表，迭代元素要能被 STmpT 构造。
      template<迭代类型 TmpT, typename IDRT = 模板解引类型<模板迭代类型<TmpT>>>
      链表类(TmpT &&迭代项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, IDRT>))
      requires(可赋值或构造类型<STmpT, IDRT>) : 链表类()
      {
         this->赋值(std::forward<TmpT>(迭代项));
      }

      // 初始化指定长度的链表，每个节点都使用 构造参数表 中的参数进行构造。
      template<typename... TmpArgs>
      链表类(类型长度 长度项, TmpArgs&&... 构造参数表)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, TmpArgs...>))
      requires(可赋值或构造类型<STmpT, TmpArgs...>) : 链表类()
      {
         this->赋值(长度项, 构造参数表...);
      }

      // 初始化指定长度的链表，每个节点都使用 调用项 返回值进行构造。
      template<调用类型<> TmpCall, typename TmpRet = 模板返回类型<TmpCall>>
      链表类(类型长度 长度项, TmpCall &&调用项)
      noexcept(noexcept(安全调用类型<TmpCall> && 可安全赋值或构造类型<STmpT, TmpRet>))
      requires(可赋值或构造类型<STmpT, TmpRet>) : 链表类()
      {
         this->赋值(长度项, std::forward<TmpCall>(调用项));
      }

      /**
       * \brief >>> 以迭代范围中的元素 赋值/构造 到链表。
       * 
       * \param 开始项： 迭代范围开始。
       * \param 结束项： 迭代范围结束。
       * \return this &
       * \tparam InputT： 至少满足单向迭代器需求的可读迭代器类型，其解引用类型要能被 STmpT 赋值/构造。
       * \note 函数检查是否初始化失败。
       */
      template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>>
      链表类 &赋值(InputT 开始项, InputT 结束项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, IDRT>))
      requires(可赋值或构造类型<STmpT, IDRT>)
      {
         链表校验宏(this, *this);

         表节点类 *当前节点 = this->类中表头->后节点;
         表节点类 *新节点头 = 空指针;
         表节点类 *新节点尾 = 空指针;
         类型长度  新表长度 = 0;

         this->类中长度 = 0;

         for (; 开始项 != 结束项; ++开始项)
         {
            // 对于已有的节点，执行赋值或重构造操作，而省去创建新节点的过程。
            if (当前节点 != this->类中表头)
            {
               ::BE::选择赋值(*当前节点->节点数据, 0, 1, *开始项);
               
               当前节点 = 当前节点->后节点;
               
               this->类中长度 += 1;
            }
            // 如果节点不足，则创建一个双向链表。
            else
            {
               表节点类 *新节点 = 创建节点(*开始项);

               if (新节点 == 空指针)
               {
                  this->类中错误 = ::BE::错误集::内存分配错误;
                  this->释放区间节点(新节点头, 新节点尾);
                  return *this;
               }

               if (新节点头 == 空指针)
               {
                  新节点头 = 新节点;
                  新节点尾 = 新节点;
               }
               else
               {
                  新节点尾->后节点 = 新节点;
                  新节点尾->后节点->前节点 = 新节点尾;
                  新节点尾 = 新节点尾->后节点;
               }

               新表长度 += 1;
            }
         }

         // 新表长度不为 0 表示当前节点不够，需要插入新的节点，因此将双向链表中的节点插入。
         if (新表长度 != 0)
         {
            this->插入节点(当前节点, 新节点头, 新节点尾, 新表长度);
         }
         // 如果当前节点不是头节点则表明有多余的节点，需要删除。
         else if (当前节点 != this->类中表头)
         {
            this->删除节点(当前节点, this->类中表头);
         }
         // 否则节点数量刚刚好，不需要任何插入和删除。

         return *this;
      }

      /**
       * \brief >>> 将指定可迭代对象中的迭代范围中元素 赋值/构造 到链表中。
       * 
       * \param 迭代项： 可迭代对象。
       * \return this &
       * \tparam TmpT： 可迭代类型，其迭代元素要能被 STmpT 赋值/构造。
       * \note 函数检查是否初始化失败。
       */
      template<迭代类型 TmpT, typename IDRT = 模板解引类型<模板迭代类型<TmpT>>>
      链表类 &赋值(TmpT &&迭代项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, IDRT>))
      requires(可赋值或构造类型<STmpT, IDRT>)
      {
         return this->赋值(::BE::开始(迭代项), ::BE::结束(迭代项));
      }

      /**
       * \brief >>> 以列表项中的元素 赋值/构造 到链表中。
       * 
       * \param 列表项： 要赋值的列表
       * \return this &
       * \tparam TmpT： 列表项类型，其元素要能被 STmpT 赋值/构造。
       * \note 函数检查是否初始化失败。
       */
      template<typename TmpT>
      链表类 &赋值(const 模板列表类型<TmpT> &列表项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, TmpT>))
      requires(可赋值或构造类型<STmpT, TmpT>)
      {
         return this->赋值(列表项.begin(), 列表项.end());
      }

      /**
       * \brief >>> 在链表中 赋值/构造 指定数量的节点，每个节点都使用 构造参数表 中的参数进行 赋值/构造。
       * 
       * \param 长度项： 要创建的节点数量。
       * \param 构造参数表： 每个节点的构造参数表。
       * \return this &
       * \tparam TmpArgs： 要求里面的参数能够被 STmpT 赋值/构造，因此也可以没有参数，表示默认构造。
       * \note 函数检查是否初始化失败。
       */
      template<typename... TmpArgs>
      链表类 &赋值(类型长度 长度项, TmpArgs&&... 构造参数表)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, TmpArgs...>))
      requires(可赋值或构造类型<STmpT, TmpArgs...>)
      {
         链表校验宏(this, *this);

         表节点类 *当前节点 = this->类中表头->后节点;
         表节点类 *新节点头 = 空指针;
         表节点类 *新节点尾 = 空指针;
         类型长度  新表长度 = 0;

         this->类中长度 = 0;

         // 对于已有的节点，执行赋值或重构造操作，而省去创建新节点的过程。
         if (长度项 != 0)
         {
            for (类型长度 索引 = 0; 索引 != 长度项; ++索引)
            {
               // 对于已有的节点，执行赋值或重构造操作，而省去创建新节点的过程。
               if (当前节点 != this->类中表头)
               {
                  ::BE::选择赋值(*当前节点->节点数据, 0, 1, 构造参数表...);

                  当前节点 = 当前节点->后节点;

                  this->类中长度 += 1;
               }
               // 如果节点不足，则创建一个双向链表。
               else
               {
                  表节点类 *新节点 = 创建节点(构造参数表...);

                  if (新节点 == 空指针)
                  {
                     this->类中错误 = ::BE::错误集::内存分配错误;
                     this->释放区间节点(新节点头, 新节点尾);
                     return *this;
                  }

                  if (新节点头 == 空指针)
                  {
                     新节点头 = 新节点;
                     新节点尾 = 新节点;
                  }
                  else
                  {
                     新节点尾->后节点 = 新节点;
                     新节点尾->后节点->前节点 = 新节点尾;
                     新节点尾 = 新节点尾->后节点;
                  }

                  新表长度 += 1;
               }
            }
         }

         // 新表长度不为 0 表示当前节点不够，需要插入新的节点，因此将双向链表中的节点插入。
         if (新表长度 != 0)
         {
            this->插入节点(当前节点, 新节点头, 新节点尾, 新表长度);
         }
         // 如果当前节点不是头节点则表明有多余的节点，需要删除。
         else if (当前节点 != this->类中表头)
         {
            this->删除节点(当前节点, this->类中表头);
         }
         // 否则节点数量刚刚好，不需要任何插入和删除。

         return *this;
      }

      /**
       * \brief >>> 在链表中 赋值/构造 指定数量的节点，每个节点都使用 调用项 的返回值进行 赋值/构造。
       * 
       * \param 长度项： 要创建的节点数量。
       * \param 调用项： 可调用对象。
       * \return this &
       * \tparam TmpCall： 可调用类型，其返回值要能被 STmpT 赋值/构造。
       * \note 函数检查是否初始化失败。
       */
      template<调用类型<> TmpCall, typename TmpRet = 模板返回类型<TmpCall>>
      链表类 &赋值(类型长度 长度项, TmpCall &&调用项)
      noexcept(noexcept(安全调用类型<TmpCall> && 可安全赋值或构造类型<STmpT, TmpRet>))
      requires(可赋值或构造类型<STmpT, TmpRet>)
      {
         链表校验宏(this, *this);

         表节点类 *当前节点 = this->类中表头->后节点;
         表节点类 *新节点头 = 空指针;
         表节点类 *新节点尾 = 空指针;
         类型长度  新表长度 = 0;

         this->类中长度 = 0;

         // 对于已有的节点，执行赋值或重构造操作，而省去创建新节点的过程。
         if (长度项 != 0)
         {
            for (类型长度 索引 = 0; 索引 != 长度项; ++索引)
            {
               // 对于已有的节点，执行赋值或重构造操作，而省去创建新节点的过程。
               if (当前节点 != this->类中表头)
               {
                  ::BE::选择赋值(*当前节点->节点数据, 0, 1, 调用项());

                  当前节点 = 当前节点->后节点;

                  this->类中长度 += 1;
               }
               // 如果节点不足，则创建一个双向链表。
               else
               {
                  表节点类 *新节点 = 创建节点(调用项());

                  if (新节点 == 空指针)
                  {
                     this->类中错误 = ::BE::错误集::内存分配错误;
                     this->释放区间节点(新节点头, 新节点尾);
                     return *this;
                  }

                  if (新节点头 == 空指针)
                  {
                     新节点头 = 新节点;
                     新节点尾 = 新节点;
                  }
                  else
                  {
                     新节点尾->后节点 = 新节点;
                     新节点尾->后节点->前节点 = 新节点尾;
                     新节点尾 = 新节点尾->后节点;
                  }

                  新表长度 += 1;
               }
            }
         }

         // 新表长度不为 0 表示当前节点不够，需要插入新的节点，因此将双向链表中的节点插入。
         if (新表长度 != 0)
         {
            this->插入节点(当前节点, 新节点头, 新节点尾, 新表长度);
         }
         // 如果当前节点不是头节点则表明有多余的节点，需要删除。
         else if (当前节点 != this->类中表头)
         {
            this->删除节点(当前节点, this->类中表头);
         }
         // 否则节点数量刚刚好，不需要任何插入和删除。

         return *this;
      }

      /**
       * \brief >>> 获取目标链表中链表的资源所有权并重新初始化目标链表。
       * 
       * \param 赋值项： 要移动的链表。
       * \return this &
       * \note 函数检查目标链表是否初始化失败。
       */
      链表类 &赋值(链表类 &&赋值项) noexcept
      {
         链表校验宏((&赋值项), *this);

         // 释放原来链表中的资源。
         this->释放();
         ::BE::释放原始内存(this->类中表头);

         this->类中表头 = ::BE::交换赋值(赋值项.类中表头, 空指针);
         this->类中长度 = ::BE::交换赋值(赋值项.类中长度, 0);
         this->类中错误 = ::BE::交换赋值(赋值项.类中错误, ::BE::无错误);

         // 需要重新初始化链表以重新构建表头。
         赋值项.初始化链表();
         return *this;
      }

      /**
       * \brief >>> 交换两个链表中的资源。
       * 
       * \param 交换项： 要交换的目标。
       * \return this &
       * \note 函数检查当前链表和目标链表是否初始化失败。
       */
      链表类 &交换(链表类 &交换项) noexcept
      {
         链表校验宏(this, *this);
         链表校验宏((&交换项), *this);

         ::BE::交换(this->类中表头, 交换项.类中表头);
         ::BE::交换(this->类中长度, 交换项.类中长度);
         ::BE::交换(this->类中错误, 交换项.类中错误);

         return *this;
      }

      /**
       * \brief >>> 在链表中指定迭代器所表示的位置之前插入一个新节点，节点使用插入项进行 赋值/构造。
       * 
       * \param 插入项： 要插入的项。
       * \param 位置项： 要插入的位置，默认为链表末尾。
       * \return 插入项
       * \tparam TmpT： 要插入的项类型，要能被 STmpT 赋值/构造。
       * \note 函数检查是否初始化失败。
       */
      template<typename TmpT>
      可写迭代器类 插入(TmpT &&插入项, 只读迭代器类 位置项 = 只读迭代器类())
      noexcept(noexcept(安全构造类型<STmpT, TmpT>))
      requires(构造类型<STmpT, TmpT>)
      {
         链表校验宏(this, 位置项.获取节点());
         
         位置项 = 位置项.获取节点() == 空指针 ? this->end() : 位置项;

         表节点类 *新节点 = 创建节点(std::forward<TmpT>(插入项));

         if (新节点 == 空指针)
         {
            this->类中错误 = ::BE::错误集::内存分配错误;
            return 位置项.获取节点();
         }

         return this->插入节点(位置项.获取节点(), 新节点, 新节点, 1);
      }

      /**
       * \brief >>> 删除链表中指定迭代器表示的范围中的节点，不包括结束项
       * 
       * \param 开始项： 开始删除的位置。
       * \param 结束项： 结束删除的位置，默认就删除开始项。
       * \return 结束项，即删除范围的末尾。
       * \note 函数检查是否初始化失败。
       */
      可写迭代器类 删除(只读迭代器类 开始项, 只读迭代器类 结束项 = 只读迭代器类()) noexcept
      {
         链表校验宏(this, 开始项.获取节点());

         结束项 = 结束项.获取节点() == 空指针 ? ++只读迭代器类(开始项.获取节点()) : 结束项;

         return this->删除节点(开始项.获取节点(), 结束项.获取节点());
      }

      /**
       * \brief >>> 获取链表中最后一个节点中元素的引用，注意越界访问或空链表访问。
       * 
       * \return 元素引用。
       */
      STmpT &获取尾值() noexcept
      {
         return *this->类中表头->前节点->节点数据;
      }

      /**
       * \brief >>> 获取链表中最后一个节点中元素的只读引用，注意越界访问或空链表访问。
       * 
       * \return 元素只读引用。
       */
      const STmpT &获取尾值() const noexcept
      {
         return *this->类中表头->前节点->节点数据;
      }

      /**
       * \brief >>> 获取链表中节点的数量，不包括头节点。
       * 
       * \return 节点数量。
       */
      类型长度 获取长度() const noexcept
      {
         return this->类中长度;
      }

      /**
       * \brief >>> 函数判断链表是否为空，即是否只有头节点。
       * 
       * \return 不为空则返回真，否则返回假。
       */
      类型逻辑 非空的() const noexcept
      {
         return this->类中表头 != 空指针 && this->类中长度 != 0;
      }

      /**
       * \brief >>> 释放链表中除了头节点外的所有节点。
       * 
       * \return this &
       * \note 函数检查是否初始化失败。
       */
      链表类 &释放() noexcept
      {
         链表校验宏(this, *this);

         表节点类 *当前节点 = this->类中表头->后节点;

         while (当前节点 != this->类中表头)
         {
            表节点类 *前节点 = 当前节点;
            当前节点 = 当前节点->后节点;

            释放节点(前节点);
         }

         this->类中长度 = 0;
         this->类中表头->前节点 = this->类中表头->后节点 = this->类中表头;

         return *this;
      }

      ~链表类()
      {
         this->释放();
         ::BE::释放原始内存(this->类中表头);
      }

      protected:

      // 一个不存储任何数据的链表头节点。
      表节点类 *类中表头 = 空指针;
      类型长度  类中长度 = 0;

      // 初始化表头，只会调用一次，如果初始化失败则设置严重错误。
      类型空的 初始化链表() noexcept
      {
         this->类中表头 = ::BE::分配原始内存<表节点类>(1);

         if (this->类中表头 == 空指针)
         {
            this->类中错误 = ::BE::错误集::严重内存分配错误;
            return;
         }

         this->类中表头->前节点 = this->类中表头->后节点 = this->类中表头;
         this->类中长度 = 0;
      }

      // 从表中获取指定索引的节点，如果索引超出范围则返回空指针。
      表节点类 *获取节点(类型长度 索引项) noexcept
      {
         表节点类 *当前节点 = this->类中表头;
         
         if (索引项 >= this->类中长度)
         {
            return 空指针;
         }

         // 如果索引大于长度的一般则从表头向后查找，否则向前查找，以提高效率。
         if (索引项 >= this->类中长度 / 2)
         {
            索引项 = this->类中长度 - 索引项;

            // 向后查找。
            for (当前节点 = 当前节点->前节点; 索引项 != 0; --索引项, 当前节点 = 当前节点->前节点);
         }
         else
         {
            for (当前节点 = 当前节点->后节点; 索引项 != 0; --索引项, 当前节点 = 当前节点->后节点);
         }

         return 当前节点;
      }

      // 删除链表中指定范围的节点，不包括结束节点，返回指向最后一个节点的指针。
      表节点类 *删除节点(表节点类 *开始项, 表节点类 *结束项) noexcept
      {
         if (开始项 != 结束项)
         {
            开始项->前节点->后节点 = 结束项;
            结束项->前节点 = 开始项->前节点;

            while (开始项 != 结束项)
            {
               // 试图删除表头节点不被允许。
               assert(开始项 != this->类中表头);
               
               表节点类 *前节点 = 开始项;
               开始项 = 开始项->后节点;

               释放节点(前节点);
               this->类中长度 -= 1;
            }
            
         }

         return 结束项;
      }

      // 将指定范围的节点插入到指定位置之后，如果给定长度项则函数将自动计算长度项。
      表节点类 *插入节点(表节点类 *位置项, 表节点类 *开始项, 表节点类 *结束项, 类型长度 长度项 = 到末尾) noexcept
      {
         //          |top|
         //
         //   |1| <-> |2| <-> |3|
         开始项->前节点 = 位置项->前节点;
         结束项->后节点 = 位置项;
         位置项->前节点->后节点 = 开始项;
         位置项->前节点 = 结束项;
 
         if (长度项 == 到末尾)
         {
            // 要插入的范围不可能为空，因此当开始项等于结束项时也算一个。
            this->类中长度 += 1;

            while (开始项 != 结束项)
            {
               开始项 = 开始项->后节点;
               this->类中长度 += 1;
            }
         }
         else
         {
            this->类中长度 += 长度项;
         }

         return 位置项;
      }

      // 创建节点，构造节点数据并将其返回。
      template<typename... TmpArgs>
      static 表节点类 *创建节点(TmpArgs&&... 构造参数表) noexcept(noexcept(安全构造类型<STmpT, TmpArgs...>))
      {
         表节点类 *返回值 = ::BE::分配原始内存<表节点类>(1);

         if (返回值 != 空指针)
         {
            返回值->节点数据 = ::BE::分配原始内存<STmpT>(1);

            if (返回值->节点数据 != 空指针)
            {
               ::BE::直接构造(返回值->节点数据, 1, std::forward<TmpArgs>(构造参数表)...);
               返回值->前节点 = 返回值->后节点 = 空指针;
            }
            else
            {
               ::BE::释放原始内存(返回值);
               返回值 = 空指针;
            }
         }

         return 返回值;
      }

      // 释放节点，析构节点数据，始终认为节点项非空时，其节点数据也非空。
      static 类型空的 释放节点(表节点类 *节点项) noexcept
      {
         if (节点项 != 空指针)
         {
            ::BE::直接析构(节点项->节点数据, 1);
            ::BE::释放原始内存(节点项->节点数据);
            ::BE::释放原始内存(节点项);
         }
      }

      static 类型空的 释放区间节点(表节点类 *开始项, 表节点类 *结束项) noexcept
      {
         while (开始项 != 空指针)
         {
            表节点类 *前节点 = 开始项;
            开始项 = 开始项->后节点;

            释放节点(前节点);
         }
      }

      public:

      // 使用可迭代对象中的迭代范围元素进行赋值。
      template<迭代类型 TmpT>
      链表类 &operator = (TmpT &&赋值项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, TmpT>))
      requires(可赋值或构造类型<STmpT, TmpT>)
      {
         return this->赋值(std::forward<TmpT>(赋值项));
      }

      // 使用目标列表中的元素赋值链表。
      template<typename TmpT>
      链表类 &operator = (const 模板列表类型<TmpT> &赋值项)
      noexcept(noexcept(可安全赋值或构造类型<STmpT, TmpT>))
      requires(可赋值或构造类型<STmpT, TmpT>)
      {
         return this->赋值(赋值项);
      }

      // 获取目标中所有资源的所有权并重新初始化目标。
      链表类 &operator = (链表类 &&赋值项) noexcept
      {
         return this->赋值(std::move(赋值项));
      }

      // 有限的随机访问支持，但不建议，因为这在链表中效率过低，注意越界访问。
      STmpT &operator [] (类型长度 索引项) noexcept
      {
         return *this->获取节点(索引项)->节点数据;
      }

      // 有限的随机访问支持，但不建议，因为这在链表中效率过低，注意越界访问。
      const STmpT &operator[] (类型长度 索引项) const noexcept
      {
         return ::BE::去除只读(*this)[索引项];
      }

   };

}

#undef 链表校验宏
