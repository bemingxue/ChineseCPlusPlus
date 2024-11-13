
namespace BE {

   /**
    * \brief >>> 无视 & 运算符重载，获取参数项对象的地址值。
    * 
    * \param 参数项： 要获取地址的对象。
    * \return 地址值，即指针。
    */
   template<typename TmpT>
   inline constexpr decltype(auto) 获取地址(TmpT &参数项) noexcept
   {
      return std::addressof(参数项);
   }

   /**
    * \brief >>> 比较两个对象的地址值。
    * 
    * \param 左值项： 要比较的对象。
    * \param 右值项： 要比较的对象。
    * \return 大于零则左值项地址大于右值项，等于零则左值项地址等于右值项，小于零则左值项地址小于右值项。
    */
   template<typename TmpT, typename TmpU>
   inline constexpr 类型比较 比较地址(TmpT &左值项, TmpU &右值项) noexcept
   {
      return static_cast<类型比较>(reinterpret_cast<const 类型字节*>(获取地址(左值项)) -  reinterpret_cast<const 类型字节*>(获取地址(右值项)));
   }

}
