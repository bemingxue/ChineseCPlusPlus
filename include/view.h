
namespace BE {

   template<typename TmpT>
   struct 视图类结构
   {
      TmpT *类中指针;

      TmpT **获取指针引用() const noexcept
      {
         return const_cast<TmpT **>(&类中指针);
      }
   };

   /**
    * \brief >>> 为连续存储数据的内存块提供视图的可迭代类型，只获取内存块和长度，不会进行任何多余的复制，但也请注意，如果原数据的对象生命周期结束，请不要再使用此对象。
    * \brief >>> 如果要赋值只读数据，那么应当让 STmpT 为 const 而非让视图类本身为 const，否则会导致一些函数无法使用。
    * \tparam TmpT： 数据的类型。
    */
   template<typename TmpT, typename TmpBase = 视图类结构<TmpT>>
   struct 视图类 : protected TmpBase
   {
      using 标准数组标识 = void;
      // 启用全局运算符。
      using EGO = void;

      using 类中基类 = TmpBase;

      // 返回类中的指针作为迭代器，注意空指针。
      TmpT *begin() noexcept { return this->获取指针(); }
      TmpT *end() noexcept { return this->获取指针() + this->类中长度; }

      // 返回类中的指针作为只读指针作为迭代器，注意空指针。
      const TmpT *begin() const noexcept { return this->获取指针(); }
      const TmpT *end() const noexcept { return this->获取指针() + this->类中长度; }

      // 默认构造函数。
      视图类() noexcept : 类中基类(空指针), 类中长度(0)
      {

      }

      // 以指针项指向的内存块中指定数量的元素为视图。
      视图类(TmpT *指针项, 类型长度 长度项) noexcept : 类中基类(指针项), 类中长度(长度项)
      {

      }

      // 对于可迭代类型，以其迭代器开始位置的第 n 个元素为视图。
      template<迭代类型 TmpU>
      视图类(TmpU &&赋值项, 类型长度 长度项 = 到末尾) noexcept requires(转换类型<模板迭代类型<TmpU>, TmpT *>)
      {
         this->赋值(::BE::开始(赋值项), 长度项 == 到末尾 ? ::BE::获取长度(赋值项) : 长度项);
      }

      // 作为一个普通类型，直接浅复制即可。
      视图类(const 视图类 &) noexcept = default;
      视图类(视图类 &&) noexcept = default;

      /**
       * \brief >>> 以指针项指向的内存块中指定数量的元素为视图。
       * 
       * \param 指针项： 指向内存块的指针。
       * \param 长度项： 内存块中元素的数量。
       * \return this &
       */
      视图类 &赋值(TmpT *指针项, 类型长度 长度项) noexcept
      {
         *this->获取指针引用() = 指针项;
         this->类中长度 = 长度项;
         return *this;
      }

      /**
       * \brief >>> 对于可迭代类型，以其迭代器开始位置的第 n 个元素为视图。
       * 
       * \param 赋值项： 可迭代对象。
       * \param 长度项： 元素数量，如果为默认值则自动计算长度。
       * \return this &
       * \tparam TmpU： 可迭代类型，其迭代器要能转换为 STmpT *
       */
      template<迭代类型 TmpU>
      视图类 &赋值(TmpU &&赋值项, 类型长度 长度项 = 到末尾) noexcept
      requires(转换类型<模板迭代类型<TmpU>, TmpT *>)
      {
         return this->赋值(::BE::开始(赋值项), 长度项 == 到末尾 ? ::BE::获取长度(赋值项) : 长度项);
      }

      /**
       * \brief >>> 获取视图中的元素数量。
       * 
       * \return 元素数量。
       */
      类型长度 获取长度() const noexcept
      {
         return this->类中长度;
      }

      /**
       * \brief >>> 获取视图中第 n 个元素的引用。
       * 
       * \param 索引项： 索引，注意越界判断。
       * \return 元素引用。
       */
      TmpT &索引值(类型长度 索引项) noexcept
      {
         return (this->获取指针())[索引项];
      }

      /**
       * \brief >>> 获取视图中第 n 个元素的只读引用。
       * 
       * \param 索引项： 索引，注意越界判断。
       * \return 元素只读引用。
       */
      const TmpT &索引值(类型长度 索引项) const noexcept
      {
         return ::BE::去除只读(*this).索引值(索引项);
      }

      /**
       * \brief >>> 获取视图中的最后一个元素的引用。
       * 
       * \return 元素引用，注意越界判断。
       */
      TmpT &获取尾值() noexcept
      {
         return (this->获取指针())[this->类中长度 - 1];
      }

      /**
       * \brief >>> 获取视图中的最后一个元素的只读引用。
       * 
       * \return 元素只读引用，注意越界判断。
       */
      const TmpT &获取尾值() const noexcept
      {
         return ::BE::去除只读(*this).获取尾值();
      }
     
      /**
       * \brief >>> 获取保存视图的指针。
       * 
       * \return 指针。
       */
      TmpT *获取指针() noexcept
      {
         return *this->获取指针引用();
      }

      /**
       * \brief >>> 获取保存视图的指针。
       * 
       * \return 只读指针。
       */
      const TmpT *获取指针() const noexcept
      {
         return *this->获取指针引用();
      }

      /**
       * \brief >>> 从左开始截取指定长度的子视图。
       * 
       * \param 长度项： 要截取的长度，如果大于当前长度则相当于本身的副本。
       * \return 子视图。
       */
      视图类 从左截取(类型长度 长度项) noexcept
      {
         return 视图类(this->获取指针(), ::BE::最小值(this->类中长度, 长度项));
      }

      /**
       * \brief >>> 从右开始截取指定长度的子视图。
       * 
       * \param 长度项： 要截取的长度，如果大于当前长度则相当于本身的副本。
       * \return 子视图。
       */
      视图类 从右截取(类型长度 长度项) noexcept
      {
         长度项 = ::BE::最小值(this->类中长度, 长度项);

         return 视图类(this->获取指针() + this->类中长度 - 长度项, 长度项);
      }

      /**
       * \brief >>> 从指定位置开始截取指定长度的子视图。
       * 
       * \param 开始项： 开始位置，如果大于等于当前长度则返回空视图。
       * \param 长度项： 要截取的长度，如果加上开始位置大于当前长度则截取到末尾。
       * \return 子视图。
       */
      视图类 截取(类型长度 开始项, 类型长度 长度项) noexcept
      {
         if (开始项 >= this->类中长度)
         {
            return 视图类();
         }

         return 视图类(this->获取指针() + 开始项, ::BE::最小值(this->类中长度 - 开始项, 长度项));
      }

      /**
       * \brief >>> 判断当前视图是否不为空。
       * 
       * \return 不是空则返回真，否则假。
       */
      类型逻辑 非空的() const noexcept
      {
         return this->获取指针() != 空指针 && this->类中长度 != 0;
      }

      protected:

      // 存储长度的成员。
      类型长度 类中长度;

      public:

      // 对于普通类型，直接浅复制即可。
      视图类 &operator = (const 视图类 &) noexcept = default;
      视图类 &operator = (视图类 &&) noexcept = default;

      // 对于左值可迭代类型，赋值时自动计算长度。
      template<迭代类型 TmpU>
      视图类 &operator = (TmpU &&赋值项) noexcept requires(转换类型<模板迭代类型<TmpU>, TmpT *> && 左值类型<TmpU>)
      {
         return this->赋值(::BE::开始(赋值项), ::BE::获取长度(赋值项));
      }

      // 获取第 n 个元素的引用，注意越界判断。
      TmpT &operator [] (类型长度 索引项) noexcept
      {
         return this->索引值(索引项);
      }

      // 获取第 n 个元素的只读引用，注意越界判断。
      const TmpT &operator [] (类型长度 索引项) const noexcept
      {
         return this->索引值(索引项);
      }

      // 截取函数的自修改版本，截取从指定位置开始的指定长度的视图并赋值给自己。
      视图类 &operator () (类型长度 开始项, 类型长度 长度项 = 到末尾) noexcept
      {
         return *this = this->截取(开始项, 长度项);
      }

      // 判断当前视图是否为空，不是空则返回真，否则假。
      explicit operator 类型逻辑() const noexcept
      {
         return this->非空的();
      }

   };

   // 以指针参数进行推导。
   template<typename TmpT>
   视图类(TmpT *, 类型长度) -> 视图类<TmpT>;

   // 以一个可迭代类型参数进行推导。
   template<迭代类型 TmpT>
   视图类(TmpT &&) -> 视图类<std::remove_reference_t<模板解引类型<模板迭代类型<TmpT>>>>;

   // 以一个可迭代类型参数和长度参数进行推导。
   template<迭代类型 TmpT>
   视图类(TmpT &&, 类型长度) -> 视图类<std::remove_reference_t<模板解引类型<模板迭代类型<TmpT>>>>;

}
