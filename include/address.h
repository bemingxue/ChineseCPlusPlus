
namespace BE {

   /**
    * \brief >>> ���� & ��������أ���ȡ���������ĵ�ֵַ��
    * 
    * \param ����� Ҫ��ȡ��ַ�Ķ���
    * \return ��ֵַ����ָ�롣
    */
   template<typename TmpT>
   inline constexpr decltype(auto) ��ȡ��ַ(TmpT &������) noexcept
   {
      return std::addressof(������);
   }

   /**
    * \brief >>> �Ƚ���������ĵ�ֵַ��
    * 
    * \param ��ֵ� Ҫ�ȽϵĶ���
    * \param ��ֵ� Ҫ�ȽϵĶ���
    * \return ����������ֵ���ַ������ֵ�����������ֵ���ַ������ֵ�С��������ֵ���ַС����ֵ�
    */
   template<typename TmpT, typename TmpU>
   inline constexpr ���ͱȽ� �Ƚϵ�ַ(TmpT &��ֵ��, TmpU &��ֵ��) noexcept
   {
      return static_cast<���ͱȽ�>(reinterpret_cast<const �����ֽ�*>(��ȡ��ַ(��ֵ��)) -  reinterpret_cast<const �����ֽ�*>(��ȡ��ַ(��ֵ��)));
   }

}
