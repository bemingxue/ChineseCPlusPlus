
namespace BE {

   // 对于 STmpT 的对齐长度。
   template<typename TmpT>
   inline constexpr 类型长度 对齐长度 = std::alignment_of_v<TmpT>;

   // 对于 STmpT 的数组维度，对于非数组类型，表示值 0。
   template<typename TmpT>
   inline constexpr 类型长度 数组维度 = std::rank_v<TmpT>;

   /**
    * \brief >>> 获取数组的长度，编译期运算。
    * 
    * \return 数组长度。
    * \tparam TmpT： 数组基本类型，不能是字符类型。
    */
   template<typename TmpT, 类型长度 TmpSize>
   inline constexpr 类型长度 获取长度(TmpT(&)[TmpSize]) 
   noexcept 
   requires(!字符类型<TmpT>)
   {
      return TmpSize;
   }

   /**
    * \brief >>> 针对字符数组的特化，获取字符数组长度但不包含结束符，编译期运算。
    * 
    * \return 字符数组长度。
    */
   template<字符类型 TmpT, 类型长度 TmpSize>
   inline constexpr 类型长度 获取长度(TmpT(&)[TmpSize])
   noexcept
   {
      return TmpSize > 0 ? TmpSize - 1 : 0;
   }

   /**
    * \brief >>> 获取字符串指针中的字符数。
    * 
    * \param 参数项： 要获取的字符指针对象。
    * \return 字符数，如果为空指针则返回 0。
    * \tparam TmpT： 任意字符指针类型。
    */
   template<指针类型 TmpT>
   inline constexpr 类型长度 获取长度(TmpT 参数项)
   noexcept
   requires(!数组类型<TmpT> && 字符类型<模板解引类型<TmpT>>)
   {
      return 参数项 == 空指针 ? 0 : std::basic_string_view<std::remove_pointer_t<TmpT>>(参数项).length();
   }

   /**
    * \brief >>> 尝试调用对象的 size、length、获取长度 安全函数获取长度信息。
    * 
    * \param 参数项： 要获取的对象，要求是类类型并且具有安全的 size、length、获取长度 三个函数中的一个，并且返回值类型可以转换为类型长度。
    * \return 获取到的长度。
    */
   inline constexpr 类型长度 获取长度(类类型 auto &&参数项) 
   noexcept
   requires(requires() { { 参数项.size() } noexcept -> 转换类型<类型长度>; } ||
            requires() { { 参数项.length() } noexcept -> 转换类型<类型长度>; } ||
            requires() { { 参数项.获取长度() } noexcept -> 转换类型<类型长度>; })
   {
      if constexpr (requires() { { 参数项.size() } noexcept -> 转换类型<类型长度>; })
      {
         return 参数项.size();
      }

      else if constexpr (requires() { { 参数项.length() } noexcept -> 转换类型<类型长度>; })
      {
         return 参数项.length();
      }

      else
      {
         return 参数项.获取长度();
      }
   }

   // 可以被 BE::获取长度 获取长度信息的类型概念。
   template<typename TmpT>
   concept 长度类型 = requires(TmpT X) { BE::获取长度(X); };

}
