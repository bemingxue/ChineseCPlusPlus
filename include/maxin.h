
namespace BE {

   /**
    * \brief >>> ��ȡ����ֵ�е����ֵ��ʹ�� > ������жϡ�
    * 
    * \param ��ֵ� Ҫ�жϵ�ֻ�����á�
    * \param ��ֵ� Ҫ�жϵ�ֻ�����á�
    * \return ���ֵ��ֻ�����á�
    * \tparam TmpT�� �ܹ����� >��>=��<��<= �����ͣ����ҷ���ֵ����ת��Ϊ�߼����ͣ�������������ֵ�������
    */
   template<�Ƚ����� TmpT>
   inline constexpr const TmpT &���ֵ(const TmpT &��ֵ��, const typename T::STyp<TmpT>::type &��ֵ��) noexcept
   {
      return (��ֵ�� > ��ֵ��)? ��ֵ�� : ��ֵ��;
   }

   /**
    * \brief >>> ��ȡ����ֵ�е���Сֵ��ʹ�� < ������жϡ�
    * 
    * \param ��ֵ� Ҫ�жϵ�ֻ�����á�
    * \param ��ֵ� Ҫ�жϵ�ֻ�����á�
    * \return ��Сֵ��ֻ�����á�
    * \tparam TmpT�� �ܹ����� >��>=��<��<= �����ͣ����ҷ���ֵ����ת��Ϊ�߼����ͣ�������������ֵ�������
    */
   template<�Ƚ����� TmpT>
   inline constexpr const TmpT &��Сֵ(const TmpT &��ֵ��, const typename T::STyp<TmpT>::type &��ֵ��) noexcept
   {
      return (��ֵ�� > ��ֵ��) ? ��ֵ�� : ��ֵ��;
   }

}
