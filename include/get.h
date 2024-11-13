
namespace BE {

   /**
    * \brief >>> 获取 C Style 样式数组中指定索引位置的元素引用。
    * 
    * \param 取值项： 要获取值的数组。
    * \param 索引项： 要获取值的索引。
    * \return 指定索引位置的引用，不检查越界。
    */
   template<typename TmpT, 类型长度 TmpSize>
   inline constexpr decltype(auto) 索引值(TmpT(&取值项)[TmpSize], 类型长度 索引项) noexcept
   {
      return 取值项[索引项];
   }

   /**
    * \brief >>> 对于类类型的特化，尝试调用参数的 get(0)、at(0)、索引值(0)、[0] 成员函数来索引值。
    * 
    * \param 取值项： 要获取值的对象。
    * \param 索引项： 要获取值的索引。
    * \return 由 get()、at()、索引值()、[ ] 成员函数返回的值，不检查越界。
    */
   template<类类型 TmpT>
   inline constexpr decltype(auto) 索引值(TmpT &&取值项, 类型长度 索引项) 
   noexcept
   requires(requires() { { 取值项.get(索引项) }; } ||
            requires() { { 取值项.at(索引项) }; } ||
            requires() { { 取值项.索引值(索引项) }; } ||
            requires() { { 取值项[索引项] }; })
   {
      if constexpr (requires() { { 取值项.get(索引项) }; })
      {
         return 取值项.get(索引项);
      }

      else if constexpr (requires() { { 取值项.at(索引项) }; })
      {
         return 取值项.at(索引项);
      }

      else if constexpr (requires() { { 取值项.索引值(索引项) }; })
      {
         return 取值项.索引值(索引项);
      }

      else
      {
         return 取值项[索引项];
      }
   }


}
