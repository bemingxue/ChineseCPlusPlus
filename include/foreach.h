
namespace BE {

   /**
    * \brief >>> ����������Χ������������Χ�ڵ�Ԫ�����δ��ݸ�����������������з���ֵ���ҷ���ֵ���Ϳ���ת��Ϊ�����߼�����������ص��߼�ֵΪ������ǰ�˳�������
    * 
    * \param ��ʼ� ������Χ��ʼ��
    * \param ����� ������Χ������
    * \param ����� �ɵ��ö���
    * \return 
    * \tparam InputT�� �������㵥��������Ŀɶ����������͡�
    * \tparam TmpCall�� �ɵ������ͣ�����Ҫ�ܽ��� InputT �Ľ��������͡�
    */
   template<����������� InputT, typename IDRT = ģ���������<InputT>, ��������<IDRT> TmpCall>
   inline constexpr ���Ϳյ� ����(InputT ��ʼ��, InputT ������, TmpCall &&������)
   noexcept(noexcept(��ȫ��������<TmpCall, IDRT>))
   {
      for (; ��ʼ�� != ������; ++��ʼ��)
      {
         if constexpr (ת������<ģ�巵������<TmpCall, IDRT>, �����߼�>)
         {
            if (������((*��ʼ��)) == ��)
            {
               break;
            }
         }

         else
         {
            ������((*��ʼ��));
         }
      }
   }

   /**
    * \brief >>> ����������Χ������������Χ�ڵ�Ԫ�����δ��ݸ�����������������з���ֵ���ҷ���ֵ���Ϳ���ת��Ϊ�����߼�����������ص��߼�ֵΪ������ǰ�˳�������
    * 
    * \param ����� �ɵ���������������������㵥��ɶ���������
    * \param ����� �ɵ��ö���
    * \return 
    * \tparam InputT�� �ɵ������ͣ���������������㵥��ɶ���������
    * \tparam TmpCall�� �ɵ������ͣ�����Ҫ�ܽ��� InputT �Ľ��������͡�
    */
   template<�������� InputT, typename IDRT = ģ���������<ģ���������<InputT>>, ��������<IDRT> TmpCall>
   inline constexpr ���Ϳյ� ����(InputT &&������, TmpCall &&������)
   noexcept(noexcept(BE::����(BE::��ʼ(������), BE::����(������), std::forward<TmpCall>(������))))
   requires(requires() { BE::����(BE::��ʼ(������), BE::����(������), std::forward<TmpCall>(������)); })
   {
      BE::����(BE::��ʼ(������), BE::����(������), std::forward<TmpCall>(������));
   }

}
