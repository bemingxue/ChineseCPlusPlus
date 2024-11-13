
namespace BE {

   /**
    * \brief >>> �ṩһ��������ٿ�һ������ײ�������ݵĿɵ������ͣ����������顢��׼���͡������͵ȵȣ��಻����Ĭ�Ϲ��죬��Ϊ�㲻�ܲٿ�һ���յĶ��󣬵������������¸�ֵ���߸��Ƹ�ֵ������ȡ�
    * \brief >>> ����ٿ�һ�������Ͷ�����ע���ڴ��������Ķ����ֽڿռ䣬���ڷ�ƽ�����ͣ�Ҳ��ע�����ڲ��洢���麯���������ݣ�����޸ĵ���Щ���಻��֤�˰�ȫ
    * \brief >>> ���⣬���ڸ���ʹ��ָ��ٿض��������ע�������������ڣ���������������ڽ��������ظ�ֵ֮ǰ����Ӧ���ڴ�ʹ�����еĺ�����
    * \tparam STmpT�� Ҫ�ٿصĶ������͡�
    */
   template<�������� STmpT>
   struct �����ֽ���
   {

      using ��׼�� = T::U8;

      // STmpT ��ռ�õ��ֽ�����
      static constexpr ���ͳ��� ����ռ�� = sizeof(STmpT);
      // STmpT ��ռ�õı�������
      static constexpr ���ͳ��� ������� = sizeof(STmpT) * 8;
      // ��׼������ռ�õ��ֽ�����
      static constexpr ���ͳ��� ��׼ռ�� = sizeof(��׼��);
      // ��׼������ռ�õı�������
      static constexpr ���ͳ��� ��׼���� = sizeof(��׼��) * 8;

      // ֻ���ı����࣬Ҳ����ֻ����������
      struct ֻ��������
      {
         // ����ȫ���������
         using EGO = void;

         ֻ��������(const ֻ�������� &) noexcept = default;

         /**
          * \brief >>> �ж�Ŀ��͵�ǰ�Ķ����������Ƿ���ͬ��
          * 
          * \param �ж�� Ҫ�жϵ��
          * \return ����򷵻��棬���򷵻ؼ١�
          */
         �����߼� ����ж�(const ֻ�������� &�ж���) const noexcept
         {
            return this->���ж��� == �ж���.���ж��� && this->�������� == �ж���.��������;
         }

         /**
          * \brief >>> �Ƚ����ߵĶ�������������������ͬ��Ƚ�����������Ƚ϶���
          * 
          * \param �ж�� Ҫ�Ƚϵ��
          * \return �����򷵻ش������ֵ�������򷵻��㣬С���򷵻�С�����ֵ��
          */
         ���ͱȽ� �Ƚ��ж�(const ֻ�������� &�ж���) const noexcept
         {
            return this->���ж��� == �ж���.���ж��� ? (this->�������� > �ж���.�������� ? 1 : this->�������� < �ж���.�������� ? -1 : 0) : (this->���ж��� > �ж���.���ж��� ? 1 : this->���ж��� < �ж���.���ж��� ? -1 : 0);
         }

         /**
          * \brief >>> ��ȡ�洢������ֵ��
          * 
          * \return ������
          */
         ���ͳ��� ��ȡ����() const noexcept
         {
            return this->��������;
         }

         protected:

         struct ��д������;
         friend �����ֽ���;
         friend ��д������;

         mutable STmpT  *���ж���;
         mutable ���ͳ��� ��������;

         ֻ��������(STmpT *������, ���ͳ��� ������) noexcept 
            : ���ж���(������)
            , ��������(������)
         {

         }

         public:

         // ģ������������ù��ܣ�ʹ���Ϊһ����������
         ֻ�������� &operator * () noexcept
         {
            return *this;
         }

         // ��������ֵ��
         ֻ�������� &operator ++ () noexcept
         {
            return this->�������� += 1, *this;
         }

         // ��������ֵ��
         ֻ�������� &operator -- () noexcept
         {
            return this->�������� -= 1, *this;
         }

         // ����ת��Ϊ�������͵�ֵ��
         explicit operator bool() const noexcept
         {
            return !!::BE::��ȡλ��(*(reinterpret_cast<const ��׼�� *>(this->���ж���) + (this->�������� / ��׼����)), this->�������� % ��׼����, 1);
         }
      };

      struct ��д������
      {
         // ����ȫ���������
         using EGO = void;

         ��д������(const ��д������ &) noexcept = default;

         /**
          * \brief >>> �ж�������ָ��Ķ���������Ƿ���ͬ��
          * 
          * \param �ж�� Ҫ�жϵ��
          * \return ��ͬ�򷵻��棬���򷵻ؼ١�
          */
         �����߼� ����ж�(const ��д������ &�ж���) const noexcept
         {
            return this->���ж��� == �ж���.���ж��� && this->�������� == �ж���.��������;
         }

         /**
          * \brief >>> �Ƚ����ߵĶ�������������������ͬ��Ƚ�����������Ƚ϶���
          * 
          * \param �ж�� Ҫ�Ƚϵ��
          * \return �����򷵻ش������ֵ�������򷵻��㣬С���򷵻�С�����ֵ��
          */
         ���ͱȽ� �Ƚ��ж�(const ��д������ &�ж���) const noexcept
         {
            return this->���ж��� == �ж���.���ж��� ? (this->�������� > �ж���.�������� ? 1 : this->�������� < �ж���.�������� ? -1 : 0) : (this->���ж��� > �ж���.���ж��� ? 1 : this->���ж��� < �ж���.���ж��� ? -1 : 0);
         }

         /**
          * \brief >>> ��ȡ��ǰ�������ڶ����������
          * 
          * \return ������
          */
         ���ͳ��� ��ȡ����() const noexcept
         {
            return this->��������;
         }

         protected:

         friend �����ֽ���;

         mutable STmpT  *���ж���;
         mutable ���ͳ��� ��������;

         ��д������(STmpT *������, ���ͳ��� ������) noexcept 
            : ���ж���(������)
            , ��������(������)
         {

         }

         public:

         // ģ������������ù��ܣ�ʹ���Ϊһ����������
         ��д������ &operator * () noexcept
         {
            return *this;
         }

         // ��������ֵ��
         ��д������ &operator ++ () noexcept
         {
            return this->�������� += 1, *this;
         }

         // ��������ֵ��
         ��д������ &operator -- () noexcept
         {
            return this->�������� -= 1, *this;
         }

         // ���õ�ǰ������ʾ�ı��ص�ֵ��
         ��д������ &operator = (bool ��ֵ��) noexcept
         {
            ::BE::����λ��(*(reinterpret_cast<��׼�� *>(this->���ж���) + (this->�������� / ��׼����)), this->�������� % ��׼����, 1, ��ֵ��);

            return *this;
         }

         // ����ת��Ϊ�������͵�ֵ��
         explicit operator bool() const noexcept
         {
            return !!::BE::��ȡλ��(*(reinterpret_cast<��׼�� *>(this->���ж���) + (this->�������� / ��׼����)), this->�������� % ��׼����, 1);
         }

         // ������ʽת��Ϊֻ�������ࡣ
         operator ֻ��������() const noexcept
         {
            return ֻ��������(���ж���, ��������);
         }

      };

      // ʹ��ר�����������ͽ��е�����
      ��д������ begin() noexcept { return ��д������(���ж���, 0); }
      ��д������ end()   noexcept { return ��д������(���ж���, �������); }
      // ʹ��ר�����������ͽ��е�����
      ֻ�������� begin() const noexcept { return ֻ��������(���ж���, 0); }
      ֻ�������� end()   const noexcept { return ֻ��������(���ж���, �������); }

      // ���캯�����洢һ����ֵ�����ָ�롣
      �����ֽ���(STmpT &��ֵ��) noexcept : ���ж���(&��ֵ��) 
      {
      
      }

      /**
       * \brief >>> ��ȡ�洢�Ķ����ָ�롣
       * 
       * \return �����ָ�롣
       */
      STmpT &��ȡ����() noexcept
      {
         return *���ж���;
      }

      /**
       * \brief >>> ��ȡ STmpT ��ռ�õı���������Ҳ���ǵ�����Χ�����Χ��
       * 
       * \return ��������
       */
      static consteval ���ͳ��� ��ȡ����() noexcept
      {
         return �������;
      }

      protected:

      STmpT *���ж���;

      public:

      // �������¸�ֵ��ʹ��洢��һ����ֵ�����ָ�롣
      �����ֽ��� &operator = (STmpT &��ֵ��) noexcept
      {
         ���ж��� = &��ֵ��;

         return *this;
      }

      // ��ȡָ���������ı���ֵ��ע��Խ�������
      ��д������ operator [] (���ͳ��� ������) noexcept
      {
         return ��д������(���ж���, ������);
      }

      // ��ȡָ���������ı���ֵ��ע��Խ�������
      ֻ�������� operator [] (���ͳ��� ������) const noexcept
      {
         return ֻ��������(���ж���, ������);
      }
   };
   
   /**
    * \brief >>> ��ȡһ������ĵײ��ֽ��򣬲���������ʺ��޸�����
    * 
    * \param ��ȡ� Ҫ��ȡ�Ķ���
    * \return һ�������ֽ������
    */
   template<�������� TmpT>
   �����ֽ���<TmpT> ��ȡ�ֽ���(TmpT &��ȡ��) noexcept
   {
      return �����ֽ���<TmpT>(��ȡ��);
   }

}