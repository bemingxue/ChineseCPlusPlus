
namespace BE {

   // namespace enum，提供一些计数类的类型枚举，可扩展。
   namespace 计数枚举
   {
      enum : int
      {
         // 包含步长、最小值、循环计数、计数次数的数字计数类型。
         数字计数 = 0, 
         // 从指定数字类型的最小值计数到最大值的数字计数类型。
         纯数计数 = 1,
         // 给定一个编译期列表，进行计数。
         列表计数 = 2,
         // 在大写英文字母之间进行计数的计数类型。
         大写字母 = 65,
         // 在小写英文字母之间进行计数的计数类型。
         小写字母 = 97,
      };
   };

   // 计数类模板，不能使用没有特化的版本。
   template<int TmpType, typename TmpT = void, auto... TmpArgs>
   struct 计数类
   {
      static_assert(false, "Counting classes without special cases - 未特例化的计数类");
   };

   /**
    * \brief >>> 一种在编译期决定计数范围的计数类型，可以是循环迭代，也可以是范围迭代，本身就是一种双向迭代器。
    * \brief >>> EGO 类型。
    * \tparam TmpT： 计数类型，必须满足数字概念且能够成为模板参数。
    * \tparam TmpMin： 计数的最小值，也是初始值。
    * \tparam TmpCount： 一次完整计数的次数。
    * \tparam TmpStep： 每次计数增长的值。
    * \tparam TmpRepeat： 是否循环计数，循环计数不提供 begin 和 end 成员函数。
    */
   template<数字类型 TmpT, TmpT TmpMin, TmpT TmpCount, TmpT TmpStep, 类型逻辑 TmpRepeat>
   struct 计数类<计数枚举::数字计数, TmpT, TmpMin, TmpCount, TmpStep, TmpRepeat>
   {
      // 启用全局运算符。
      using EGO = void;

      // 计数的最大值。
      static constexpr TmpT 最高值 = TmpCount * TmpStep + TmpMin;

      // 计数的迭代器，对于循环计数不提供。
      计数类 begin() const noexcept requires(!TmpRepeat) { return 计数类(); }
      计数类 end()   const noexcept requires(!TmpRepeat) { return 计数类(最高值); }

      计数类() noexcept : 类中当前(TmpMin) { }

      计数类(const 计数类 &复制项) noexcept : 类中当前(复制项.类中当前) { }

      /**
       * \brief >>> 重置计数为最小计数值。
       * 
       * \return this &
       */
      计数类 &重置() noexcept
      {
         类中当前 = TmpMin;

         return *this;
      }

      /**
       * \brief >>> 递增一次计数，如果计数已经使最大值且非循环计数则函数无作为。
       * 
       * \return this &
       */
      计数类 &递增() noexcept
      {
         if constexpr (TmpRepeat)
         {
            类中当前 += TmpStep;

            // 不包括最高值。
            if (类中当前 >= 最高值)
            {
               this->重置();
            }
         }

         else
         {
            if (类中当前 != 最高值)
            {
               类中当前 += TmpStep;
            }
         }

         return *this;
      }

      /**
       * \brief >>> 递减一次计数，如果计数已经使最小值且非循环计数则函数无作为。
       * 
       * \return this &
       */
      计数类 &递减() noexcept
      {
         if constexpr (TmpRepeat)
         {
            if (类中当前 <= TmpMin)
            {
               类中当前 = 最高值;
            }

            类中当前 -= TmpStep;
         }

         else
         {
            if (类中当前 != TmpMin)
            {
               类中当前 -= TmpStep;
            }
         }

         return *this;
      }

      /**
       * \brief >>> 获取当前的计数值。
       * 
       * \return 计数值的只读引用。
       */
      const TmpT &获取值() const noexcept
      {
         return 类中当前;
      }

      /**
       * \brief >>> 获取当前计数器的指针。
       * 
       * \return 计数器的只读指针。
       */
      const TmpT *绑定值() const noexcept
      {
         return &类中当前;
      }

      /**
       * \brief >>> 判断两个计数器的当前计数值是否相等。
       * 
       * \param 判断项： 要判断的对象。
       * \return 相等返回真，否则返回假。
       */
      类型逻辑 相等判断(const 计数类 &判断项) const noexcept
      {
         return 类中当前 == 判断项.获取值();
      }

      /**
       * \brief >>> 比较两个计数器的当前计数值。
       * 
       * \param 判断项： 要比较的对象。
       * \return 大于返回 1，等于返回 0，小于返回 -1。
       */
      类型比较 比较判断(const 计数类 &判断项) const noexcept
      {
         return 类中当前 > 判断项.类中当前 ? 1 : (类中当前 < 判断项.类中当前 ? -1 : 0);
      }

      protected:
      
      // 负责计数的变量。
      TmpT 类中当前;

      // 私有的构造函数，供 end 函数使用。
      计数类(TmpT 初始项) noexcept : 类中当前(初始项) { }

      public:

      // 递增一次计数，如果计数已经使最大值且非循环计数则函数无作为。
      计数类 &operator ++ () noexcept
      {
         return this->递增();
      }

      // 递减一次计数，如果计数已经使最小值且非循环计数则函数无作为。
      计数类 &operator -- () noexcept
      {
         return this->递减();
      }

      // 获取当前的计数值的只读引用。
      const TmpT &operator * () const noexcept
      {
         return this->获取值();
      }

      // 获取当前计数器的只读指针。
      const TmpT *operator -> () const noexcept
      {
         return this->绑定值();
      }

   };

   /**
    * \brief >>> 提供计数范围从 0 到 STmpT 类型的最大值（不包括最大值）进行计数的计数类型。
    * \brief >>> EGO 类型。
    * \brief >>> 继承自： 计数类<数字计数, STmpT, STmpT{ 0 }, 数字信息类<STmpT>::最大值, STmpT{ 1 }, false>。
    * \tparam TmpT： 计数类型，必须是整数类型。
    */
   template<整数类型 TmpT>
   struct 计数类<计数枚举::纯数计数, TmpT>
        : 计数类<计数枚举::数字计数, TmpT, TmpT{ 0 }, 数字信息类<TmpT>::最大值, TmpT{ 1 }, false>
   {
      
   };
   
   /**
    * \brief >>> 一种遍历字母 A 到 Z 的计数类型。
    * \brief >>> EGO 类型。
    * \tparam TmpT： 计数类型，必须是字符类型。
    */
   template<字符类型 TmpT>
   struct 计数类<计数枚举::大写字母, TmpT>
        : 计数类<计数枚举::数字计数, TmpT, TmpT{ 65 }, TmpT{ 26 }, TmpT{ 1 }, false>
   {

   };

   /**
    * \brief >>> 一种遍历字母 a 到 z 的计数类型。
    * \brief >>> EGO 类型。
    * \tparam TmpT： 计数类型，必须是字符类型。
    */
   template<字符类型 TmpT>
   struct 计数类<计数枚举::小写字母, TmpT>
        : 计数类<计数枚举::数字计数, TmpT, TmpT{ 97 }, TmpT{ 26 }, TmpT{ 1 }, false>
   {

   };

   /**
    * \brief >>> 从 TmpMin 一步一步计数到 TmpMax 的普通计数类型，为 计数类 的一种特化别名，可以用在范围 for 循环中指定循环多少次。
    * \tparam TmpT： 计数类型，必须是整数类型。
    * \tparam TmpMin： 计数的最小值，也是初始值，默认为 0。
    * \tparam TmpMax： 计数的最大值，默认为 10。
    */
   template<整数类型 TmpT, TmpT TmpMin = 0, TmpT TmpMax = 10>
   using 范围计数类 = 计数类<计数枚举::数字计数, TmpT, TmpMin, TmpMax + TmpMin, TmpT{ 1 }, false>;

   /**
    * \brief >>> 一种用于遍历 TmpV，TmpArgs... 的列表可迭代计数类型，列表长度必须大于获取等于一。
    * \tparam TmpT： 计数类型，必须是可为模板参数的类型。
    * \tparam TmpV，TmpArgs： 列表的元素，必须是相同类型。
    */
   template<typename TmpT, TmpT TmpV, TmpT... TmpArgs>
   struct 计数类<计数枚举::列表计数, TmpT, TmpV, TmpArgs...>
   {
      // 启用全局运算符。
      using EGO = void;

      // 列表的长度，也是列表计数能够达到的最大值。。
      static constexpr 类型长度 列表长度 = sizeof...(TmpArgs) + 1;
      // 存储列表的数值。
      static constexpr TmpT     列表序列[列表长度] = { TmpV, TmpArgs... };

      // 使用本身类型作为迭代器。
      计数类 begin() const noexcept { return 计数类(); }
      计数类 end()   const noexcept { return 计数类(列表长度); }

      // 默认构造函数，初始化计数值为 0。
      计数类() noexcept : 类中当前(0) { }

      // 复制构造函数，复制计数值。
      计数类(const 计数类 &复制项) noexcept : 类中当前(复制项.类中当前) { }

      /**
       * \brief >>> 将计数器重置为初始值。
       * 
       * \return this &
       */
      计数类 &重置() noexcept
      {
         类中当前 = 0;

         return *this;
      }

      /**
       * \brief >>> 递增计数器一次，如果已经达到列表的末尾之后的一个元素则不做任何操作。
       * 
       * \return this &
       */
      计数类 &递增() noexcept
      {
         类中当前 = 类中当前 + 1 <= 列表长度 ? 类中当前 + 1 : 类中当前;

         return *this;
      }

      /**
       * \brief >>> 递减一次计数器，如果已经达到列表的开头之前的一个元素则不做任何操作。
       * 
       * \return this &
       */
      计数类 &递减() noexcept
      {
         类中当前 = 类中当前 != 0 ? 类中当前 - 1 : 0;

         return *this;
      }

      /**
       * \brief >>> 获取当前计数器表示的值。
       * 
       * \return 
       */
      const TmpT &获取值() const noexcept
      {
         return 列表序列[类中当前];
      }

      /**
       * \brief >>> 判断计数是否到末尾。
       * 
       * \return 是则符号真，否则假。
       */
      类型逻辑 是末尾() const noexcept
      {
         return 类中当前 == 列表长度;
      }

      // 判断两个计数器是否相等。
      类型逻辑 相等判断(const 计数类 &判断项) const noexcept
      {
         return 类中当前 == 判断项.类中当前;
      }

      // 比较两个计数器的大小。
      类型比较 比较判断(const 计数类 &判断项) const noexcept
      {
         return 类中当前 > 判断项.类中当前 ? 1 : (类中当前 < 判断项.类中当前 ? -1 : 0);
      }

      protected:

      // 负责计数的变量。
      类型长度 类中当前 = 0;

      // 私有的构造函数，供 end 函数使用。
      计数类(类型长度 初始项) noexcept : 类中当前(初始项) { }

      public:

      // 获取当前计数器表示的值的只读引用。
      const TmpT &operator * () const noexcept
      {
         return this->获取值();
      }

      // 获取当前计数器表示的值的只读指针。
      const TmpT *operator -> () const noexcept
      {
         return &列表序列[类中当前];
      }

      // 递增计数器一次，如果已经达到列表的末尾之后的一个元素则不做任何操作。
      计数类 &operator ++ () noexcept
      {
         return this->递增();
      }

      // 递减一次计数器，如果已经达到列表的开头之前的一个元素则不做任何操作。
      计数类 &operator -- () noexcept
      {
         return this->递减();
      }

      // 如果计数没有抵达末尾则返回真，否则返回假。
      explicit operator bool() const noexcept
      {
         return !this->是末尾();
      }
   };

}
