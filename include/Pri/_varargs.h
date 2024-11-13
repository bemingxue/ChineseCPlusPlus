
namespace BE::X::R {

   struct SVarArgsPho { };

   template<typename TmpT, typename... TmpArgs>
   struct VarArgsSumBytes
   {
      static constexpr 类型长度 value = sizeof(TmpT) + VarArgsSumBytes<TmpArgs...>::value;
   };

   template<>
   struct VarArgsSumBytes<SVarArgsPho>
   {
      static constexpr 类型长度 value = 0;
   };

   template<类型长度 TmpIndex, typename TmpT, typename... TmpArgs>
   struct VarArgsAtType
   {
      using type = typename VarArgsAtType<TmpIndex - 1, TmpArgs...>::type;
   };

   template<typename TmpT, typename... TmpArgs>
   requires(!相同类型<TmpT, SVarArgsPho>)
   struct VarArgsAtType<0, TmpT, TmpArgs...>
   {
      using type = TmpT;
   };

   // 处理索引没有归 0 但变参已经结束的情况。
   template<类型长度 TmpIndex, typename... TmpArgs>
   struct VarArgsAtType<TmpIndex, SVarArgsPho, TmpArgs...>
   {
      static_assert(false, " Variable parameter index out of bounds - 变参索引越界！");

      using type = void;
   };

}
