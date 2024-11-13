
namespace BE::X::R {

   struct SVarArgsPho { };

   template<typename TmpT, typename... TmpArgs>
   struct VarArgsSumBytes
   {
      static constexpr ���ͳ��� value = sizeof(TmpT) + VarArgsSumBytes<TmpArgs...>::value;
   };

   template<>
   struct VarArgsSumBytes<SVarArgsPho>
   {
      static constexpr ���ͳ��� value = 0;
   };

   template<���ͳ��� TmpIndex, typename TmpT, typename... TmpArgs>
   struct VarArgsAtType
   {
      using type = typename VarArgsAtType<TmpIndex - 1, TmpArgs...>::type;
   };

   template<typename TmpT, typename... TmpArgs>
   requires(!��ͬ����<TmpT, SVarArgsPho>)
   struct VarArgsAtType<0, TmpT, TmpArgs...>
   {
      using type = TmpT;
   };

   // ��������û�й� 0 ������Ѿ������������
   template<���ͳ��� TmpIndex, typename... TmpArgs>
   struct VarArgsAtType<TmpIndex, SVarArgsPho, TmpArgs...>
   {
      static_assert(false, " Variable parameter index out of bounds - �������Խ�磡");

      using type = void;
   };

}
