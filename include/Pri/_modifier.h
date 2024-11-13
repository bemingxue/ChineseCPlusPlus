
namespace BE::X::R {

   // 更好的 const 类型移除，支持引用、数组。
   template<typename TmpT>
   struct RemoveConstType
   {
      using type = TmpT;
   };

   template<typename TmpT>
   struct RemoveConstType<const TmpT>
   {
      using type = TmpT;
   };

   template<typename TmpT>
   struct RemoveConstType<const TmpT &>
   {
      using type = TmpT &;
   };

   template<typename TmpT>
   struct RemoveConstType<const TmpT &&>
   {
      using type = TmpT &&;
   };

   template<typename TmpT, 类型长度 TmpSize>
   struct RemoveConstType<const TmpT[TmpSize]>
   {
      using type = TmpT[TmpSize];
   };

   // 移除所有修饰符。
   template<typename TmpT>
   struct RemoveAllModifier
   {
      using type = TmpT;
   };

   template<typename TmpT>
   struct RemoveAllModifier<const TmpT>
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   template<typename TmpT>
   requires(!std::is_const_v<TmpT>)
   struct RemoveAllModifier<volatile TmpT>
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   template<typename TmpT>
   struct RemoveAllModifier<TmpT &>
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   template<typename TmpT>
   struct RemoveAllModifier<TmpT &&>
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   template<typename TmpT>
   struct RemoveAllModifier<TmpT *>
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   template<typename TmpT, 类型长度 TmpSize>
   requires(!std::is_const_v<TmpT> && !std::is_volatile_v<TmpT>)
   struct RemoveAllModifier<TmpT[TmpSize]>
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   template<typename TmpT>
   requires(!std::is_const_v<TmpT> && !std::is_volatile_v<TmpT>)
   struct RemoveAllModifier<TmpT[]>
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   // 移除 STmpT 的所有修饰符并将 TmpU 的 const、volatile、 &、 &&、 *、 [] 修饰符移动到 STmpT 上。
   template<typename TmpT, typename TmpU>
   struct MoveModifierType
   {
      using type = typename RemoveAllModifier<TmpT>::type;
   };

   template<typename TmpT, typename TmpU>
   struct MoveModifierType<TmpT, const TmpU>
   {
      using type = const typename MoveModifierType<TmpT, typename RemoveConstType<TmpU>::type>::type;
   };

   template<typename TmpT, typename TmpU>
   struct MoveModifierType<TmpT, TmpU &>
   {
      using type = typename MoveModifierType<TmpT, std::remove_reference_t<TmpU>>::type &;
   };

   template<typename TmpT, typename TmpU>
   struct MoveModifierType<TmpT, TmpU &&>
   {
      using type = typename MoveModifierType<TmpT, std::remove_reference_t<TmpU>>::type &&;
   };

   template<typename TmpT, typename TmpU>
   struct MoveModifierType<TmpT, TmpU *>
   {
      using type = typename MoveModifierType<TmpT, std::remove_pointer_t<TmpU>>::type *;
   };

   template<typename TmpT, typename TmpU>
   requires(!std::is_const_v<TmpU>)                // volatile 与 const 同级，让其优先去除 const。
   struct MoveModifierType<TmpT, volatile TmpU>
   {
      using type = volatile typename MoveModifierType<TmpT, TmpU>::type;
   };

   template<typename TmpT, typename TmpU, 类型长度 TmpSize>
   requires(!std::is_const_v<TmpU> && !std::is_volatile_v<TmpU>)
   struct MoveModifierType<TmpT, TmpU[TmpSize]>
   {
      using type = typename MoveModifierType<TmpT, std::remove_all_extents_t<TmpU>>::type[TmpSize];
   };

}
