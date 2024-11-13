
namespace BE::X::R {

   // ���õ� const �����Ƴ���֧�����á����顣
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

   template<typename TmpT, ���ͳ��� TmpSize>
   struct RemoveConstType<const TmpT[TmpSize]>
   {
      using type = TmpT[TmpSize];
   };

   // �Ƴ��������η���
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

   template<typename TmpT, ���ͳ��� TmpSize>
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

   // �Ƴ� STmpT ���������η����� TmpU �� const��volatile�� &�� &&�� *�� [] ���η��ƶ��� STmpT �ϡ�
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
   requires(!std::is_const_v<TmpU>)                // volatile �� const ͬ������������ȥ�� const��
   struct MoveModifierType<TmpT, volatile TmpU>
   {
      using type = volatile typename MoveModifierType<TmpT, TmpU>::type;
   };

   template<typename TmpT, typename TmpU, ���ͳ��� TmpSize>
   requires(!std::is_const_v<TmpU> && !std::is_volatile_v<TmpU>)
   struct MoveModifierType<TmpT, TmpU[TmpSize]>
   {
      using type = typename MoveModifierType<TmpT, std::remove_all_extents_t<TmpU>>::type[TmpSize];
   };

}
