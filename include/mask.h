
namespace BE {

   // 一种 STmpT 能进行掩码操作的类型概念。
   template<typename TmpT>
   concept 位掩码类型 = requires (TmpT X, const TmpT Y) {
      { X = X | Y  } -> 相同类型<TmpT &>;     // 设置位。
      { X = X & ~Y } -> 相同类型<TmpT &>;     // 清除位。
      { static_cast<类型逻辑>(X & Y) };       // 判断位。
   };

   // 一种能够和整数类型进行位运算的类型概念。
   template<typename TmpT>
   concept 位运算类型 = requires(TmpT X) {
      { X |=  0 } -> 相同类型<TmpT &>;
      { X &=  0 } -> 相同类型<TmpT &>;
      { X ^=  0 } -> 相同类型<TmpT &>;
      { X <<= 0 } -> 相同类型<TmpT &>;
      { X >>= 0 } -> 相同类型<TmpT &>;

      { X |  0 } -> 转换类型<TmpT>;
      { X &  0 } -> 转换类型<TmpT>;
      { X ^  0 } -> 转换类型<TmpT>;
      { X << 0 } -> 转换类型<TmpT>;
      { X >> 0 } -> 转换类型<TmpT>;
      {   ~X   } -> 转换类型<TmpT>;
   };

   /**
    * \brief >>> 给设置项设置掩码。
    * 
    * \param 设置项： 进行设置的项。
    * \param 值项： 要设置的值。
    * \return 设置项。
    * \tparam TmpT： 任意可进行掩码运算的类型。
    */
   template<位掩码类型 TmpT>
   inline constexpr TmpT &设置掩码(TmpT &设置项, const TmpT &值项) noexcept
   {
      //   00100010
      // | 00010000
      // = 00110010
      
      return 设置项 = 设置项 | 值项;
   }

   /**
    * \brief >>> 清除项中的指定掩码。
    * 
    * \param 清除项： 进行清除的项。
    * \param 值项： 要清除的值。
    * \return 清除项。
    * \tparam TmpT： 任意可进行掩码运算的类型。
    */
   template<位掩码类型 TmpT>
   inline constexpr TmpT &清除掩码(TmpT &清除项, const TmpT &值项) noexcept
   {
      // 值项：
      // ~ 00000010
      // = 11111101

      // 清除项：
      //   00110010
      // & 11111101
      // = 00110000

      return 清除项 = 清除项 & ~值项;
   }

   /**
    * \brief >>> 判断是否设置了指定掩码。
    * 
    * \param 判断项： 进行判断的项。
    * \param 值项： 要判断的值。
    * \return 判断项。
    * \tparam TmpT： 任意可进行掩码运算的类型。
    */
   template<位掩码类型 TmpT>
   inline constexpr 类型逻辑 掩码判断(const TmpT &判断项, const TmpT &值项) noexcept
   {
      //   00110010
      // & 00010000
      // = 00010000
      //      or
      //   00110010
      // & 00001000
      // = 00000000

      return static_cast<类型逻辑>(判断项 & 值项);
   }

   /**
    * \brief >>> 从一个整数中获取指定位开始的指定长度位块信息。
    * 
    * \param 值项： 整数值。
    * \param 起始项： 起始位。
    * \param 长度项： 长度。
    * \return 存储在整数中的位块信息。
    * \tparam TmpT： 任意整数类型，建议使用无符号整数。
    */
   template<整数类型 TmpT>
   inline constexpr TmpT 获取位块(const TmpT &值项, 类型长度 起始项, 类型长度 长度项) noexcept
   {
      // 值项：
      // 01010000
      
      // 起始项： 4
      // 01010000 >> 4 = 00000101
      
      // 长度项： 3
      // 00000001 << 3 = 000001000 -> 8 - 1 = 7 -> 00000111
      
      //   00000101
      // & 00000111
      // = 00000101 = 5 Ok！

      return (值项 >> 起始项) & ((1 << 长度项) - 1);
   }

   /**
    * \brief >>> 设置整数中的指定位开始的指定长度位块信息。
    * 
    * \param 设置项： 进行设置的项。
    * \param 起始项： 起始位。
    * \param 长度项： 长度，也就是值项的前几位。
    * \param 值项： 要设置的值。
    * \return 设置项
    */
   template<整数类型 TmpT>
   inline constexpr TmpT &设置位块(TmpT &设置项, 类型长度 起始项, 类型长度 长度项, const typename T::STyp<TmpT>::type &值项) noexcept
   {
      // 值项：
      // 01010100

      // 长度项： 4 
      // 00000001 << 4 = 00010000 -> 16 - 1 = 15 -> 00001111

      // 值项： 19
      //   00010011
      // & 00001111
      // = 00000011
      
      // 起始项： 3
      // 00000011 << 3 = 00011000 

      // 00001111 << 3 = ~01111000 = 
      //   10000111
      // & 01010100
      // = 00000100
      // | 00011000
      // = 00011100 Ok！

      /*TmpT mask1 = (1 << 长度项) - 1;
      TmpT mask2 = ~(mask1 << 起始项);
      TmpT mask3 = (设置项 & mask2);
      TmpT mask4 = mask3 | (值项 << 起始项);*/

      return 设置项 = (设置项 & ~(((1 << 长度项) - 1) << 起始项)) | (值项 << 起始项);
   }

   /**
    * \brief >>> 将整数中指定位块中的全部位置为零。
    * 
    * \param 清除项： 进行清除的项。
    * \param 起始项： 起始位。
    * \param 长度项： 长度。
    * \return 清除项
    */
   template<整数类型 TmpT>
   inline constexpr TmpT &清除位块(TmpT &清除项, 类型长度 起始项, 类型长度 长度项) noexcept
   {
      return 清除项 = 清除项 & ~(~(1 << 长度项) << 起始项);
   }

   /**
    * \brief >>> 提供一个使用 T::UMAX 存储数据的变量为位块，提供各种操作对其中的每个位进行操作或者切片，也允许隐式转换位 T::UMAX &。
    */
   struct 位块类
   {

      // 进行位块切片返回的类。
      struct 类中位块设置类
      {

         // 设置位块中的值。
         constexpr 类中位块设置类 &operator = (const T::UMAX 设置项) noexcept
         {
            ::BE::设置位块(this->类中位块, this->类中起始, this->类中长度, 设置项);
            return *this;
         }

         // 清除位块中的所有位。
         constexpr 类中位块设置类 &operator = (类型空值) noexcept
         {
            ::BE::清除位块(this->类中位块, this->类中起始, this->类中长度);
            return *this;
         }

         // 获取位块的值。
         constexpr operator T::UMAX() const noexcept
         {
            return ::BE::获取位块(this->类中位块, this->类中起始, this->类中长度);
         }

         protected:

         // 私有构造函数，只允许位块类调用。
         constexpr 类中位块设置类(T::UMAX &类中位块, 类型长度 类中起始, 类型长度 类中长度) noexcept : 类中位块(类中位块), 类中起始(类中起始), 类中长度(类中长度)
         {

         }

         // 私有移动构造函数，用于位块类进行返回。
         constexpr 类中位块设置类(类中位块设置类 &&设置项) noexcept : 类中位块(设置项.类中位块), 类中起始(设置项.类中起始), 类中长度(设置项.类中长度)
         {

         }

         // 复制构造函数，禁止复制。
         constexpr 类中位块设置类(const 类中位块设置类 &) noexcept = delete;

         T::UMAX &类中位块;
         类型长度 类中起始;
         类型长度 类中长度;
      
         friend 位块类;
      };

      // 启用全局运算符。
      using EGO = void;

      // 默认构造函数。
      constexpr 位块类() noexcept : 类中位块(0) 
      {
      
      }

      // 使用指定值初始化位块。
      constexpr 位块类(const T::UMAX 设置项) noexcept : 类中位块(设置项)
      {

      }

      /**
       * \brief >>> 将当前位块位指定值。
       * 
       * \param 设置项： 要设置的值。
       * \return this &
       */
      constexpr 位块类 &赋值(const T::UMAX 设置项) noexcept
      {
         this->类中位块 = 设置项;
         return *this;
      }

      /**
       * \brief >>> 设置位块中的指定位。
       * 
       * \param 索引项： 要设置的索引。 
       * \param 设置项： 要设置的值。
       * \return this &
       */
      constexpr 位块类 &设置位(类型长度 索引项, 类型比特 设置项) noexcept
      {
         ::BE::设置位块(this->类中位块, 索引项, 1, 设置项);
         return *this;
      }

      /**
       * \brief >>> 获取位块中的指定位。
       * 
       * \param 索引项： 要获取的索引。
       * \return 1 或 0。
       */
      constexpr 类型比特 获取位(类型长度 索引项) const noexcept
      {
         return static_cast<类型比特>(::BE::获取位块(this->类中位块, 索引项, 1));
      }

      /**
       * \brief >>> 设置当前位块中的指定子位块的值。
       * 
       * \param 起始项： 起始位。
       * \param 长度项： 长度，也就是值项的前几位。
       * \param 设置项： 要设置的值。
       * \return this &
       */
      constexpr 位块类 &设置位块(类型长度 起始项, 类型长度 长度项, const T::UMAX 设置项) noexcept
      {
         ::BE::设置位块(this->类中位块, 起始项, 长度项, 设置项);
         return *this;
      }

      /**
       * \brief >>> 获取当前位块中的指定子位块中的值。
       * 
       * \param 起始项： 起始位。
       * \param 长度项： 长度。
       * \return 子位块中表示的整数值。
       */
      constexpr T::UMAX 获取位块(类型长度 起始项, 类型长度 长度项) const noexcept
      {
         return ::BE::获取位块(this->类中位块, 起始项, 长度项);
      }

      /**
       * \brief >>> 获取指定位块，可以对其进行赋值、取值和清除等操作。
       * 
       * \param 起始项： 起始位。
       * \param 长度项： 长度。
       * \return 可以对位块进行赋值、取值和清除操作的类，注意你不应该使用变量来接受该返回值。
       */
      constexpr 类中位块设置类 获取设置位块(类型长度 起始项, 类型长度 长度项) noexcept
      {
         return 类中位块设置类(this->类中位块, 起始项, 长度项);
      }

      /**
       * \brief >>> 获取位块能够存储位的数量。
       * 
       * \return 位的数量，也就是 T::UMAX 的位的数量。
       */
      static constexpr 类型长度 获取长度() noexcept
      {
         return sizeof(T::UMAX) * 8;
      }

      protected:

      // 一个整数变量用于表示位块。
      T::UMAX 类中位块;

      public:

      // 使用当前值设置位块值。
      constexpr 位块类 &operator = (const T::UMAX 设置项) noexcept
      {
         this->类中位块 = 设置项;
         return *this;
      }

      // 获取指定子位块，允许赋值、取值和清除等操作。
      constexpr 类中位块设置类 operator () (类型长度 起始项, 类型长度 长度项 = 1) noexcept
      {
         return 类中位块设置类(this->类中位块, 起始项, 长度项);
      }

      // 允许获取位块的只读引用。
      constexpr operator const T::UMAX &() const noexcept
      {
         return this->类中位块;
      }

      // 允许获取位块的可修改引用。
      constexpr operator T::UMAX &() noexcept
      {
         return this->类中位块;
      }

   };

}
