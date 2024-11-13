
namespace BE {

   /**
    * \brief >>> ��ָ��ֵ��������Χ�е�����Ԫ�ء�
    * 
    * \param ��ʼ� ������Χ��ʼ��
    * \param ����� ������Χ������
    * \param ���� Ҫ����ֵ��
    * \return 
    * \tparam TmpU�� ���Ը�ֵ��������ΧԪ�ص����͡�
    * \tparam OutputT�� �������㵥��������Ŀ�д���������͡�
    */
   template<typename TmpU, ��д��������<����ö��::����, TmpU> OutputT, typename ODRT = ģ���������<OutputT>>
   inline constexpr ���Ϳյ� ֵ���(OutputT ��ʼ��, OutputT ������, TmpU &&�����)
   noexcept(noexcept(��ȫ��ֵ����<ODRT, TmpU>))
   {
      for (; ��ʼ�� != ������; ++��ʼ��)
      {
         (*��ʼ��) = std::forward<TmpU>(�����);
      }
   }

   /**
    * \brief >>> ��ָ��ֵ��������Χ�е�����Ԫ�ء�
    * 
    * \param ����� �ɵ�������Ҫ��������������㵥���д��������
    * \param ���ֵ�� Ҫ����ֵ��
    * \return 
    * \tparam OutputT�� �ɵ������͡�
    * \tparam TmpU�� ���Ը�ֵ��������ΧԪ�ص����͡�
    */
   template<�������� OutputT, typename TmpU>
   inline constexpr ���Ϳյ� ֵ���(OutputT &&������, TmpU &&���ֵ)
   noexcept(noexcept(BE::ֵ���(BE::��ʼ(������), BE::����(������), std::forward<TmpU>(���ֵ))))
   requires(requires(){BE::ֵ���(BE::��ʼ(������), BE::����(������), std::forward<TmpU>(���ֵ)); })
   {
      BE::ֵ���(BE::��ʼ(������), BE::����(������), std::forward<TmpU>(���ֵ));
   }

   /**
    * \brief >>> ��ָ���ɵ��ö���ķ���ֵ����������Χ�ڵ�Ԫ�ء�
    * 
    * \param ��ʼ� ������Χ��ʼ��
    * \param ����� ������Χ������
    * \param ���� �ɵ��ö���
    * \return 
    * \tparam TmpCall�� �ɵ������ͣ��޲Σ�Ҫ�󷵻�ֵ�����ܹ���ֵ��������ΧԪ�����͡�
    * \tparam OutputT�� �������㵥��������Ŀ�д���������͡�
    */
   template<��������<> TmpCall, typename TmpRet = ģ�巵������<TmpCall>, 
            ��д��������<����ö��::����, TmpRet> OutputT, typename ODRT = ģ���������<OutputT>>
   inline constexpr ���Ϳյ� �������(OutputT ��ʼ��, OutputT ������, TmpCall &&�����)
   noexcept(noexcept(��ȫ��ֵ����<ODRT, TmpRet>))
   {
      for (; ��ʼ�� != ������; ++��ʼ��)
      {
         (*��ʼ��) = �����();
      }
   }

   /**
    * \brief >>> ��ָ���ɵ��ö���ķ���ֵ����������Χ�ڵ�Ԫ�ء�
    * 
    * \param ����� �ɵ�������Ҫ��������������㵥���д��������
    * \param ���ֵ�� �ɵ��ö���
    * \return 
    * \tparam OutputT�� �ɵ������͡�
    * \tparam TmpCall�� �ɵ������ͣ��޲Σ�Ҫ�󷵻�ֵ�����ܹ���ֵ��������ΧԪ�����͡�
    */
   template<�������� OutputT, ��������<> TmpCall>
   inline constexpr ���Ϳյ� �������(OutputT &&������, TmpCall &&���ֵ)
   noexcept(noexcept(BE::�������(BE::��ʼ(������), BE::����(������), std::forward<TmpCall>(���ֵ))))
   requires(requires(){BE::�������(BE::��ʼ(������), BE::����(������), std::forward<TmpCall>(���ֵ)); })
   {
      BE::�������(BE::��ʼ(������), BE::����(������), std::forward<TmpCall>(���ֵ));
   }

   /**
    * \brief >>> �������Χ�������������ֵ��ÿ������������������������
    * 
    * \param ��ʼ� ������Χ��ʼ��
    * \param ����� ������Χ������
    * \param ���� Ҫ����ֵ��
    * \return 
    * \tparam TmpT�� �ܹ����������Լ������͡�
    * \tparam OutputT�� �������㵥��������Ŀ�д���������ͣ����ҽ���������Ҫ�ܸ�ֵ TmpT��
    */
   template<���������� TmpT, ��д��������<����ö��::����, TmpT> OutputT, typename ODRT = ģ���������<OutputT>>
   inline constexpr ���Ϳյ� ��ֵ���(OutputT ��ʼ��, OutputT ������, TmpT &&�����)
   noexcept(noexcept(��ȫ��ֵ����<ODRT, TmpT>))
   {
      for (; ��ʼ�� != ������; ++��ʼ��, ++�����)
      {
         (*��ʼ��) = �����;
      }
   }

   /**
    * \brief >>> �������Χ�������������ֵ��ÿ������������������������
    * 
    * \param ����� �ɵ�������Ҫ��������������㵥���д��������
    * \param ���ֵ�� Ҫ����ֵ��
    * \return 
    * \tparam TmpT�� �ܹ����������Լ������͡�
    * \tparam OutputT�� �ɵ������ͣ����ҽ���������Ҫ�ܸ�ֵ TmpT��
    */
   template<���������� TmpT, �������� OutputT>
   inline constexpr ���Ϳյ� ��ֵ���(OutputT &&������, TmpT &&���ֵ)
   noexcept(noexcept(BE::��ֵ���(BE::��ʼ(������), BE::����(������), std::forward<TmpT>(���ֵ))))
   requires(requires(){BE::��ֵ���(BE::��ʼ(������), BE::����(������), std::forward<TmpT>(���ֵ)); })
   {
      BE::��ֵ���(BE::��ʼ(������), BE::����(������), std::forward<TmpT>(���ֵ));
   }

}
