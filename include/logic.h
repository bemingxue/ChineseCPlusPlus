
namespace BE {

   /**
    * \brief >>> 进行逻辑异或判断的函数，即判断是否不相同。
    * 
    * \param 左值项： 要判断的值。
    * \param 右值项： 要判断的值。
    * \return 如果左值项和右值项不相同则返回真，否则返回假。
    */
   inline constexpr 类型逻辑 逻辑异或(类型逻辑 左值项, 类型逻辑 右值项) noexcept
   {
      return !左值项 != !右值项;
   }

}
