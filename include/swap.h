
namespace BE {

   /**
    * \brief >>> 交换左右两项的值，如果存在安全的 swap 或者 交换 成员函数则调用他们进行交换，否则使用 std::swap 进行交换。
    * 
    * \param 左值项： 要交换的值。
    * \param 右值项： 要交换的值。
    * \return 左值项。
    */
   template<typename TmpT>
   inline constexpr TmpT &交换(TmpT &左值项, TmpT &右值项) noexcept
   {
      if constexpr (requires() { { 左值项.swap(右值项) } noexcept; })
      {
         左值项.swap(右值项);
      }

      else if constexpr (requires() { { 左值项.交换(右值项) } noexcept; })
      {
         左值项.交换(右值项);
      }

      else
      {
         std::swap(左值项, 右值项);
      }

      return 左值项;
   }

}
