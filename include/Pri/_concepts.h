
namespace BE::X::R {

   // ���õĸ�ֵ�жϸ������ʹ�� SCur �����������ͱ�ʾ�Լ������ƶ� SCur �����η���
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
