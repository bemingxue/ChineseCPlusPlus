
namespace BE {

   /**
    * \brief >>> ��������ֵ��ֵ����ԭ����ֵ���ء�
    * 
    * \param �ܸ�ֵ� �ܸ�ֵ�
    * \param ��ֵ� ��ֵ�
    * \return ��ֵǰԭ����ֵ��
    * \tparam TmpT�� �����ƶ����첢���ܹ���ֵΪ TmpU �����͡�
    * \tparam TmpU�� �ܹ��� STmpT ��ֵ�����͡�
    */
   template<typename TmpT, typename TmpU>
   inline constexpr TmpT ������ֵ(TmpT &�ܸ�ֵ��, TmpU &&��ֵ��)
   noexcept(noexcept(��ȫ�ƶ���������<TmpT> && ��ȫ��ֵ����<TmpT, TmpU>))
   requires(�ƶ���������<TmpT> && ��ֵ����<TmpT, TmpU>)
   {
      TmpT �洢 = std::move(�ܸ�ֵ��);

      �ܸ�ֵ�� = std::forward<TmpU>(��ֵ��);

      return �洢;
   }

}
