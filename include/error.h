
namespace BE {

   // һЩ������Ϣ�ļ��ϡ�
   namespace ���� {
    
      inline constexpr ���ʹ��� ��ֵ�Լ����� = C("��ͼ�Լ���ֵ�Լ������ⲻ������");

      inline constexpr ���ʹ��� ��ֵ��ָ����� = C("��ͼ��ֵ��ָ�룬���ⲻ������");

      inline constexpr ���ʹ��� ���ƴ��� = C("ʹ���˺����ⲻ֧�ֵĽ���ֵ��");

      inline constexpr ���ʹ��� ת������ = C("����ת������ʱ��������");

      inline constexpr ���ʹ��� ��Ч�������� = C("�����˱���Ϊ��Ч�Ĳ���ֵ��");

      inline constexpr ���ʹ��� �ڴ������� = C("�������䵽�ڴ棬��ʧ�ܣ�");

      inline constexpr ���ʹ��� �����ڴ������� = C("�������䵽�ڴ棬��ʧ�ܣ�����η����Ǳ���ģ�");

      inline constexpr ���ʹ��� �ظ����� = C("��ͼ�����ظ����롢ɾ���Ȳ��������ⲻ������");

   }

   /**
    * \brief >>> һ�����ڴ洢��������ͣ����� const ʱ���ô���
    */
   struct ������
   {

      /**
       * \brief >>> ��ȡ������Ϣ��
       * 
       * \return ������Ϣ��
       */
      ���ʹ��� ��ȡ����() const noexcept
      {
         return ���д���;
      }

      /**
       * \brief >>> ���ô�����Ϣ������ const ʱ�޸�
       * 
       * \param ����� Ҫ���õĴ�����Ϣ��
       * \return 
       */
      ���Ϳյ� ���ô���(���ʹ��� ������) const noexcept
      {
         ���д��� = ������;
      }

      /**
       * \brief >>> ���ô�����ϢΪ�޴������� const ʱ�޸�
       * 
       * \return 
       */
      ���Ϳյ� ���ô���() const noexcept
      {
         ���д��� = �޴���;
      }

      /**
       * \brief >>> �ж��Ƿ�����˴�����Ϣ��
       * 
       * \return ���򷵻ؼ٣����򷵻��档
       */
      �����߼� �޴����() const noexcept
      {
         return ���д��� == �޴���;
      }

      protected:

      mutable ���ʹ��� ���д��� = �޴���;

      public:

      /**
       * \brief >>> ����ת��Ϊ�߼����ͣ������ж��Ƿ��д���explicit �ġ�
       * 
       * \return û�д��󷵻��棬���򷵻ؼ١�
       */
      constexpr explicit operator �����߼�() const noexcept
      {
         return ���д��� == �޴���;
      }
   };

   // һ�ֿ��Ի�ȡ������Ϣ�����͵ĸ��
   template<typename TmpT>
   concept �������� = requires(const TmpT X) {
      { X.��ȡ����() } -> ת������<���ʹ���>;
   };

}
