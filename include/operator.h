
namespace BE {

   /**
    * \brief >>> 提供调用运算符进行 "==" 比较的类，允许使 STmpT = void 让调用运算符选择类型。
    */
   template<typename TmpT = 类型空的, typename TmpU = TmpT>
   struct 运算相等类
   {
      inline constexpr decltype(auto) operator () (const TmpT &左值项, const TmpU &右值项) noexcept
      {
         return 左值项 == 右值项;
      }
   };

   template<>
   struct 运算相等类<类型空的>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&左值项, TmpU &&右值项) noexcept
      {
         return std::forward<TmpT>(左值项) == std::forward<TmpU>(右值项);
      }
   };

   /**
    * \brief >>> 提供调用运算符进行 "!=" 比较的类，允许使 STmpT = void 让调用运算符选择类型。
    */
   template<typename TmpT = 类型空的, typename TmpU = TmpT>
   struct 运算不相等类
   {
      inline constexpr decltype(auto) operator () (const TmpT &左值项, const TmpU &右值项) noexcept
      {
         return 左值项!= 右值项;
      }
   };

   template<>
   struct 运算不相等类<类型空的>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&左值项, TmpU &&右值项) noexcept
      {
         return std::forward<TmpT>(左值项) != std::forward<TmpU>(右值项);
      }
   };

   /**
    * \brief >>> 提供调用运算符进行 "<" 比较的类，允许使 STmpT = void 让调用运算符选择类型。
    */
   template<typename TmpT = 类型空的, typename TmpU = TmpT>
   struct 运算小于类
   {
      inline constexpr decltype(auto) operator () (const TmpT &左值项, const TmpU &右值项) noexcept
      {
         return 左值项 < 右值项;
      }
   };

   template<>
   struct 运算小于类<类型空的>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&左值项, TmpU &&右值项) noexcept
      {
         return std::forward<TmpT>(左值项) < std::forward<TmpU>(右值项);
      }
   };

   /**
    * \brief >>> 提供调用运算符进行 "<=" 比较的类，允许使 STmpT = void 让调用运算符选择类型。
    */
   template<typename TmpT = 类型空的, typename TmpU = TmpT>
   struct 运算小于等于类
   {
      inline constexpr decltype(auto) operator () (const TmpT &左值项, const TmpU &右值项) noexcept
      {
         return 左值项 <= 右值项;
      }
   };

   template<>
   struct 运算小于等于类<类型空的>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&左值项, TmpU &&右值项) noexcept
      {
         return std::forward<TmpT>(左值项) <= std::forward<TmpU>(右值项);
      }
   };

   /**
    * \brief >>> 提供调用运算符进行 ">" 比较的类，允许使 STmpT = void 让调用运算符选择类型。
    */
   template<typename TmpT = 类型空的, typename TmpU = TmpT>
   struct 运算大于类
   {
      inline constexpr decltype(auto) operator () (const TmpT &左值项, const TmpU &右值项) noexcept
      {
         return 左值项 > 右值项;
      }
   };

   template<>
   struct 运算大于类<类型空的>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&左值项, TmpU &&右值项) noexcept
      {
         return std::forward<TmpT>(左值项) > std::forward<TmpU>(右值项);
      }
   };

   /**
    * \brief >>> 提供调用运算符进行 ">=" 比较的类，允许使 STmpT = void 让调用运算符选择类型。
    */
   template<typename TmpT = 类型空的, typename TmpU = TmpT>
   struct 运算大于等于类
   {
      inline constexpr decltype(auto) operator () (const TmpT &左值项, const TmpU &右值项) noexcept
      {
         return 左值项 >= 右值项;
      }
   };

   template<>
   struct 运算大于等于类<类型空的>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&左值项, TmpU &&右值项) noexcept
      {
         return std::forward<TmpT>(左值项) >= std::forward<TmpU>(右值项);
      }
   };

}
