
namespace BE::X::R {

   // 更好的赋值判断概念，允许使用 SCur 特殊语义类型表示自己并且移动 SCur 的修饰符。
   template<typename TmpT, typename TmpU>
   struct CorrectAssignmentConcept
   {
      static inline constexpr auto value = std::is_assignable_v<TmpT, TmpU>;
   };

   template<typename TmpT, typename TmpU>
   requires(std::is_same_v<typename RemoveAllModifier<TmpU>::type, T::SCur>)
   struct CorrectAssignmentConcept<TmpT, TmpU>
   {
      static inline constexpr auto value = std::is_assignable_v<TmpT, typename MoveModifierType<TmpT, TmpU>::type>;
   };

   template<typename TmpT, typename TmpU>
   struct CorrectTrivialAssignmentConcept
   {
      static inline constexpr auto value = std::is_trivially_assignable_v<TmpT, TmpU>;
   };

   template<typename TmpT>
   struct CorrectTrivialAssignmentConcept<TmpT, X::T::SCur>
   {
      static inline constexpr auto value = std::is_trivially_assignable_v<TmpT, TmpT>;
   };

   template<typename TmpT, typename TmpU>
   struct CorrectNothrowAssignmentConcept
   {
      static inline constexpr auto value = std::is_nothrow_assignable_v<TmpT, TmpU>;
   };

   template<typename TmpT>
   struct CorrectNothrowAssignmentConcept<TmpT, X::T::SCur>
   {
      static inline constexpr auto value = std::is_nothrow_assignable_v<TmpT, TmpT>;
   };

}
