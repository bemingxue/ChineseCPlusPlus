
namespace BE {

   /**
    * \brief >>> �������������ֵ��������ڰ�ȫ�� swap ���� ���� ��Ա������������ǽ��н���������ʹ�� std::swap ���н�����
    * 
    * \param ��ֵ� Ҫ������ֵ��
    * \param ��ֵ� Ҫ������ֵ��
    * \return ��ֵ�
    */
   template<typename TmpT>
   inline constexpr TmpT &����(TmpT &��ֵ��, TmpT &��ֵ��) noexcept
   {
      if constexpr (requires() { { ��ֵ��.swap(��ֵ��) } noexcept; })
      {
         ��ֵ��.swap(��ֵ��);
      }

      else if constexpr (requires() { { ��ֵ��.����(��ֵ��) } noexcept; })
      {
         ��ֵ��.����(��ֵ��);
      }

      else
      {
         std::swap(��ֵ��, ��ֵ��);
      }

      return ��ֵ��;
   }

}
