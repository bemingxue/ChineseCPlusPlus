
namespace BE {

   /**
    * \brief >>> ��ת��ʼ��������Χ֮���Ԫ�ء�
    * 
    * \param ��ʼ� ������Χ��ʼ��
    * \param ����� ������Χ������
    * \return 
    * \tparam OutputT�� ��������˫������������ͣ��������Ԫ���ܹ������ƶ���ֵ��
    */
   template<��д��������<����ö��::˫��, T::SCur &&> OutputT, typename ODRT = ģ���������<OutputT>>
   inline constexpr ���Ϳյ� ��ת(OutputT ��ʼ��, OutputT ������)
   noexcept(noexcept(��ȫ��ֵ����<ODRT, ODRT &&>))
   {
      for (; ��ʼ�� != ������; ++��ʼ��)
      {
         std::remove_reference_t<ODRT> ��ʱֵ = std::move(*��ʼ��);
         (*��ʼ��) = std::move(*(--������));
         (*(������)) = std::move(��ʱֵ);

         // Ԫ��������ż��ʱ����Ҫ���жϷ�ֹ�������ʼ��֮ǰ��
         if (��ʼ�� == ������)
         {
            break;
         }
      }
   }

}
