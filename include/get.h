
namespace BE {

   /**
    * \brief >>> ��ȡ C Style ��ʽ������ָ������λ�õ�Ԫ�����á�
    * 
    * \param ȡֵ� Ҫ��ȡֵ�����顣
    * \param ����� Ҫ��ȡֵ��������
    * \return ָ������λ�õ����ã������Խ�硣
    */
   template<typename TmpT, ���ͳ��� TmpSize>
   inline constexpr decltype(auto) ����ֵ(TmpT(&ȡֵ��)[TmpSize], ���ͳ��� ������) noexcept
   {
      return ȡֵ��[������];
   }

   /**
    * \brief >>> ���������͵��ػ������Ե��ò����� get(0)��at(0)������ֵ(0)��[0] ��Ա����������ֵ��
    * 
    * \param ȡֵ� Ҫ��ȡֵ�Ķ���
    * \param ����� Ҫ��ȡֵ��������
    * \return �� get()��at()������ֵ()��[ ] ��Ա�������ص�ֵ�������Խ�硣
    */
   template<������ TmpT>
   inline constexpr decltype(auto) ����ֵ(TmpT &&ȡֵ��, ���ͳ��� ������) 
   noexcept
   requires(requires() { { ȡֵ��.get(������) }; } ||
            requires() { { ȡֵ��.at(������) }; } ||
            requires() { { ȡֵ��.����ֵ(������) }; } ||
            requires() { { ȡֵ��[������] }; })
   {
      if constexpr (requires() { { ȡֵ��.get(������) }; })
      {
         return ȡֵ��.get(������);
      }

      else if constexpr (requires() { { ȡֵ��.at(������) }; })
      {
         return ȡֵ��.at(������);
      }

      else if constexpr (requires() { { ȡֵ��.����ֵ(������) }; })
      {
         return ȡֵ��.����ֵ(������);
      }

      else
      {
         return ȡֵ��[������];
      }
   }


}
