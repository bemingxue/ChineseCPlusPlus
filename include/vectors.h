
namespace BE {

   /**
    * \brief >>> 提供一种数组长度可变的数组容器，支持插入、删除等常规操作。
    * \tparam TmpT： 支持移动的元素。
    */
   template<对象类型 TmpT>
   struct 可变数组类 : protected 基本空间类<TmpT>
   {

      using 标准数组标识 = void;
      using 类中基类 = 基本空间类<TmpT>;

      using 类中基类::begin;
      using 类中基类::end;
      using 类中基类::获取长度;
      using 类中基类::获取总长度;
      using 类中基类::获取指针;
      using 类中基类::operator[];
      using 类中基类::operator 类型逻辑;

      // 使基类继承的错误类函数公开。
      using 类中基类::获取错误;
      using 类中基类::无错误的;
      using 类中基类::重置错误;
      using 类中基类::设置错误;

      // 默认构造函数。
      可变数组类() noexcept : 类中基类() 
      {
      
      }

      // 获取目标中的所有数据所有权并清空目标。
      可变数组类(可变数组类 &&赋值项) noexcept
      {
         this->类中基类::赋值(std::move(赋值项));
      }

      // 复制构造函数。
      可变数组类(const 可变数组类 &赋值项) noexcept
      {
         this->赋值(赋值项.begin(), 赋值项.end(), 赋值项.获取长度());
      }

      // 使用迭代范围中的值构造数组。
      template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>>
      可变数组类(InputT 开始项, InputT 结束项, 类型长度 长度项 = 到末尾)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, IDRT>))
      requires(可赋值或构造类型<TmpT, IDRT>)
      {
         this->赋值(开始项, 结束项, 长度项);
      }

      // 使用可迭代对象中的迭代范围构造数组。
      template<迭代类型 TmpU, typename IDRT = 模板解引类型<模板迭代类型<TmpU>>>
      可变数组类(TmpU &&迭代项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, IDRT>))
      requires(可赋值或构造类型<TmpT, IDRT>)
      {
         this->赋值(std::forward<TmpU>(迭代项));
      }

      // 使用列表中的成员构造数组。
      template<typename TmpU>
      可变数组类(const 模板列表类型<TmpU> &列表项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, const TmpU &>))
      requires(可赋值或构造类型<TmpT, const TmpU &>)
      {
         this->赋值(列表项);
      }

      // 使用参数表构造指定长度的数组。
      template<typename... TmpArgs>
      可变数组类(类型长度 长度项, TmpArgs&&... 构造参数表)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, TmpArgs...>))
      requires(可赋值或构造类型<TmpT, TmpArgs...>)
      {
         this->赋值(长度项, std::forward<TmpArgs>(构造参数表)...);
      }

      // 使用调用项的返回值构造指定长度的数组。
      template<调用类型<> TmpCall, typename TmpRet = 模板返回类型<TmpCall>>
      可变数组类(类型长度 长度项, TmpCall &&调用项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, TmpRet>))
      requires(可赋值或构造类型<TmpT, TmpRet> && !可赋值或构造类型<TmpT, TmpCall>) /* 如果 TmpCall 能够赋值/构造 给 STmpT 则以当 赋值/构造 */
      {
         this->赋值(长度项, std::forward<TmpCall>(调用项));
      }

      /**
       * \brief >>> 将迭代范围中的成员 赋值/构造 到数组中的成员，也可以指定长度限制范围。
       * 
       * \param 开始项： 迭代范围开始。
       * \param 结束项： 迭代范围结束。
       * \param 长度项： 指定长度，默认函数自动计算长度，如果指定，则如果结束项小于长度则到结束，否则到长度。
       * \return this &
       * \tparam InputT： 至少满足单向迭代器类型的可读迭代器，其解引用元素要能赋值或构造到 TmpT。
       */
      template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>>
      可变数组类 &赋值(InputT 开始项, InputT 结束项, 类型长度 长度项 = 到末尾)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, IDRT>))
      requires(可赋值或构造类型<TmpT, IDRT>)
      {
         类型长度 原长度 = this->获取长度();

         长度项 = 长度项 == 到末尾 ? ::BE::获取长度(开始项, 结束项) : 长度项;
         this->调整有效范围<false>(长度项);

         for (TmpT *迭代量 = this->begin(); 迭代量 != this->end() && 开始项 != 结束项; ++迭代量, ++开始项)
         {
            ::BE::选择赋值(*迭代量, 迭代量 - this->begin(), ::BE::最小值(原长度, 长度项), *开始项);
         }

         return *this;
      }

      /**
       * \brief >>> 将指定可迭代对象中的迭代范围值 赋值/构造 到数组中的成员。
       * 
       * \param 迭代项： 可迭代对象。
       * \return this &
       * \tparam TmpU： 可迭代类型，其迭代器元素类型要能赋值或构造到 TmpT。
       */
      template<迭代类型 TmpU, typename IDRT = 模板解引类型<模板迭代类型<TmpU>>>
      可变数组类 &赋值(TmpU &&迭代项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, IDRT>))
      requires(可赋值或构造类型<TmpT, IDRT>)
      {
         if constexpr (长度类型<TmpU>)
         {
            return this->赋值(::BE::开始(迭代项), ::BE::结束(迭代项), ::BE::获取长度(迭代项));
         }
         else
         {
            return this->赋值(::BE::开始(迭代项), ::BE::结束(迭代项));
         }
      }

      /**
       * \brief >>> 将指定列表中的值 赋值/构造 到数组中的成员。
       * 
       * \param 列表项： 要赋值的列表。
       * \return this &
       * \tparam TmpU： 要求能够 const & 赋值或构造到 STmpT 的类型。
       */
      template<typename TmpU>
      可变数组类 &赋值(const 模板列表类型<TmpU> &列表项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, const TmpU &>))
      requires(可赋值或构造类型<TmpT, const TmpU &>)
      {
         return this->赋值(列表项.begin(), 列表项.end(), 列表项.size());
      }

      /**
       * \brief >>> 调整数组的长度，并对每个成员使用参数表中的成员进行 赋值/构造。
       * 
       * \param 长度项： 要调整到的长度。
       * \param 构造参数表： 传递给成员赋值运算符或构造函数的参数。
       * \return this &
       * \tparam TmpArgs： 能够被 STmpT 赋值/构造 的参数表示，如果为 0 则表示使用默认构造函数。
       */
      template<typename... TmpArgs>
      可变数组类 &赋值(类型长度 长度项, TmpArgs&&... 构造参数表)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, TmpArgs...>))
      requires(可赋值或构造类型<TmpT, TmpArgs...>)
      {
         this->调整有效范围(长度项, std::forward<TmpArgs>(构造参数表)...);
         return *this;
      }

      /**
       * \brief >>> 设置数组的长度，并对每个成员都使用调用项的返回值进行 赋值/构造。
       * 
       * \param 长度项： 要设置的长度。
       * \param 调用项： 可调用对象。
       * \return this &
       * \tparam TmpCall： 可调用类型，不接受任何参数，其返回值类型要能赋值或构造到 TmpT，如果其能直接赋值或构造给 STmpT 则以当 赋值或构造 给 TmpT。
       */
      template<调用类型<> TmpCall, typename TmpRet = 模板返回类型<TmpCall>>
      可变数组类 &赋值(类型长度 长度项, TmpCall &&调用项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, TmpRet>))
      requires(可赋值或构造类型<TmpT, TmpRet> && !可赋值或构造类型<TmpT, TmpCall>) /* 如果 TmpCall 能够赋值/构造 给 STmpT 则以当 赋值/构造 */
      {
         类型长度 原长度 = this->获取长度();

         this->调整有效范围(长度项);

         for (TmpT *迭代量 = this->begin(); 迭代量 != this->end(); ++迭代量)
         {
            ::BE::选择赋值(*迭代量, 迭代量 - this->begin(), ::BE::最小值(原长度, 长度项), 调用项());
         }

         return *this;
      }

      /**
       * \brief >>> 获取目标中的所有数据所有权并清空目标。
       * 
       * \param 赋值项： 要移动的目标。
       * \return this &
       */
      可变数组类 &赋值(可变数组类 &&赋值项) noexcept
      {
         this->类中基类::赋值(std::move(赋值项));
         return *this;
      }

      /**
       * \brief >>> 获取数组中最后一个元素的引用，注意数组越界。
       * 
       * \return 元素引用。
       */
      TmpT &获取尾值() noexcept
      {
         return this->operator[](this->获取长度() - 1);
      }

      /**
       * \brief >>> 获取数组中最后一个元素的只读引用，注意数组越界。
       * 
       * \return 元素只读引用。
       */
      const TmpT &获取尾值() const noexcept
      {
         return ::BE::去除只读(*this).获取尾值();
      }

      /**
       * \brief >>> 删除数组中从开始项开始的指定数量的元素。
       * 
       * \param 开始项： 要删除的开始位置，如果越界则函数无作为。
       * \param 长度项： 要删除的元素数量，如果长度为 0 则函数无作为，如果加上开始项超过当前数组长度则删除到末尾。
       * \return this &
       */
      可变数组类 &删除(类型长度 开始项, 类型长度 长度项 = 到末尾) noexcept
      {
         if (开始项 >= this->获取长度() || 长度项 == 0)
         {
            return *this;
         }

         // 当前长度减去开始项就是所允许的最长长度值。
         长度项 = ::BE::最小值(this->获取长度() - 开始项, 长度项);

         // 如果是从开始项一直删除到末尾的话就不需要移动元素，直接截断即可。
         if (开始项 + 长度项 < this->获取长度())
         {
            TmpT *迭代量 = this->begin() + 开始项;
            TmpT *移动迭代量 = this->begin() + 开始项 + 长度项;

            for (; 移动迭代量 != this->end(); ++迭代量, ++移动迭代量)
            {
               *迭代量 = std::move(*移动迭代量);
            }
         }

         this->设置有效范围(this->获取长度() - 长度项);

         return *this;
      }

      /**
       * \brief >>> 函数将指定数量的插入项以 赋值/构造 的方式插入到数组中的指定位置。
       * 
       * \param 插入项： 要进行 赋值/构造 的项。
       * \param 索引项： 要插入的位置，如果大于当前数组长度则插入到数组末尾。
       * \param 重复项： 要插入的次数，默认为 1 次，如果为 0 则函数无作为。
       * \return this &
       * \tparam TmpU： 能够被 STmpT 进行 赋值/构造 的类型。
       */
      template<typename TmpU>
      可变数组类 &插入(TmpU &&插入项, 类型长度 索引项 = 到末尾, 类型长度 重复项 = 1)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, TmpU>))
      requires(可赋值或构造类型<TmpT, TmpU>)
      {
         if (重复项 == 0)
         {
            return *this;
         }

         类型长度 原长度 = this->获取长度();
         类型长度 新长度 = 原长度 + 重复项;

         索引项 = ::BE::最小值(索引项, 原长度);

         this->调整有效范围<false>(新长度);

         TmpT *迭代量 = this->begin() + 新长度 - 1;
         TmpT *移动迭代量 = this->begin() + 原长度 - 1;

         for (; 移动迭代量 >= this->begin() + 索引项; --迭代量, --移动迭代量)
         {
            // 对于原范围之外的元素，调用构造函数进行移动构造，否则使用移动赋值。
            if (迭代量 >= this->begin() + 原长度)
            {
               new(reinterpret_cast<void *>(迭代量)) TmpT(std::move(*移动迭代量));
            }
            else
            {
               *迭代量 = std::move(*移动迭代量);
            }
         }

         // 上次循环完成后，迭代量一定指向要插入的序列最后一个元素的位置。
         for (; 迭代量 >= this->begin() + 索引项; --迭代量)
         {
            ::BE::选择赋值(*迭代量, 迭代量 - this->begin(), 原长度, 插入项);
         }

         return *this;
      }

      /**
       * \brief >>> 析构所有元素并将长度清 0，但不会释放占用的内存空间。
       * 
       * \return this &
       */
      可变数组类 &清除() noexcept
      {
         this->设置有效范围(0);
         return *this;
      }

      // 安全析构函数。
      ~可变数组类() noexcept
      {

      }

      // 获取目标中所有数据所有权并清空目标。
      可变数组类 &operator = (可变数组类 &&赋值项) noexcept
      {
         return this->赋值(std::move(赋值项));
      }

      // 复制赋值函数。
      可变数组类 &operator = (const 可变数组类 &赋值项) noexcept
      {
         return this->赋值(赋值项.begin(), 赋值项.end(), 赋值项.获取长度());
      }

      // 使用可迭代对象的迭代范围值赋值数组。
      template<迭代类型 TmpU, typename IDRT = 模板解引类型<模板迭代类型<TmpU>>>
      可变数组类 &operator = (TmpU &&迭代项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, IDRT>))
      requires(可赋值或构造类型<TmpT, IDRT>)
      {
         return this->赋值(std::forward<TmpU>(迭代项));
      }

      // 使用列表中的值赋值数组。
      template<typename TmpU>
      可变数组类 &operator = (const 模板列表类型<TmpU> &列表项)
      noexcept(noexcept(可安全赋值或构造类型<TmpT, const TmpU &>))
      requires(可赋值或构造类型<TmpT, const TmpU &>)
      {
         return this->赋值(列表项);
      }

   };

   // 允许使用迭代类型的迭代器解引用元素推导模板类型，不会推导出 const、volatile、reference。
   template<迭代类型 TmpT>
   可变数组类(TmpT &&) -> 可变数组类<std::remove_cvref_t<模板解引类型<模板迭代类型<TmpT>>>>;

   // 允许使用迭代范围的解引用元素推导模板类型，不会推导出 const、volatile、reference。
   template<单向迭代类型 TmpT>
   可变数组类(TmpT, TmpT) -> 可变数组类<std::remove_cvref_t<模板解引类型<TmpT>>>;

   // 允许使用迭代范围的解引用元素推导模板类型，不会推导出 const、volatile、reference。
   template<单向迭代类型 TmpT>
   可变数组类(TmpT, TmpT, 类型长度) -> 可变数组类<std::remove_cvref_t<模板解引类型<TmpT>>>;

   // 允许使用调用项的返回值推导模板类型，可能会推导出 const、volatile、reference。
   template<调用类型<> TmpCall>
   可变数组类(类型长度, TmpCall &&) -> 可变数组类<模板返回类型<TmpCall>>;

   // 允许使用列表推导模板类型，这要求 TmpArgs 中所有类型参数都等于 TmpT。
   template<typename TmpT, typename... TmpArgs>
   requires(全真值<相同类型<TmpArgs, TmpT>...>)
   可变数组类(TmpT, TmpArgs...) -> 可变数组类<TmpT>;

}
