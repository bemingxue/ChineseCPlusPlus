
namespace BE {

   template<typename TmpT>
   struct ��ͼ��ṹ
   {
      TmpT *����ָ��;

      TmpT **��ȡָ������() const noexcept
      {
         return const_cast<TmpT **>(&����ָ��);
      }
   };

   /**
    * \brief >>> Ϊ�����洢���ݵ��ڴ���ṩ��ͼ�Ŀɵ������ͣ�ֻ��ȡ�ڴ��ͳ��ȣ���������κζ���ĸ��ƣ���Ҳ��ע�⣬���ԭ���ݵĶ����������ڽ������벻Ҫ��ʹ�ô˶���
    * \brief >>> ���Ҫ��ֵֻ�����ݣ���ôӦ���� STmpT Ϊ const ��������ͼ�౾��Ϊ const������ᵼ��һЩ�����޷�ʹ�á�
    * \tparam TmpT�� ���ݵ����͡�
    */
   template<typename TmpT, typename TmpBase = ��ͼ��ṹ<TmpT>>
   struct ��ͼ�� : protected TmpBase
   {
      using ��׼�����ʶ = void;
      // ����ȫ���������
      using EGO = void;

      using ���л��� = TmpBase;

      // �������е�ָ����Ϊ��������ע���ָ�롣
      TmpT *begin() noexcept { return this->��ȡָ��(); }
      TmpT *end() noexcept { return this->��ȡָ��() + this->���г���; }

      // �������е�ָ����Ϊֻ��ָ����Ϊ��������ע���ָ�롣
      const TmpT *begin() const noexcept { return this->��ȡָ��(); }
      const TmpT *end() const noexcept { return this->��ȡָ��() + this->���г���; }

      // Ĭ�Ϲ��캯����
      ��ͼ��() noexcept : ���л���(��ָ��), ���г���(0)
      {

      }

      // ��ָ����ָ����ڴ����ָ��������Ԫ��Ϊ��ͼ��
      ��ͼ��(TmpT *ָ����, ���ͳ��� ������) noexcept : ���л���(ָ����), ���г���(������)
      {

      }

      // ���ڿɵ������ͣ������������ʼλ�õĵ� n ��Ԫ��Ϊ��ͼ��
      template<�������� TmpU>
      ��ͼ��(TmpU &&��ֵ��, ���ͳ��� ������ = ��ĩβ) noexcept requires(ת������<ģ���������<TmpU>, TmpT *>)
      {
         this->��ֵ(::BE::��ʼ(��ֵ��), ������ == ��ĩβ ? ::BE::��ȡ����(��ֵ��) : ������);
      }

      // ��Ϊһ����ͨ���ͣ�ֱ��ǳ���Ƽ��ɡ�
      ��ͼ��(const ��ͼ�� &) noexcept = default;
      ��ͼ��(��ͼ�� &&) noexcept = default;

      /**
       * \brief >>> ��ָ����ָ����ڴ����ָ��������Ԫ��Ϊ��ͼ��
       * 
       * \param ָ��� ָ���ڴ���ָ�롣
       * \param ����� �ڴ����Ԫ�ص�������
       * \return this &
       */
      ��ͼ�� &��ֵ(TmpT *ָ����, ���ͳ��� ������) noexcept
      {
         *this->��ȡָ������() = ָ����;
         this->���г��� = ������;
         return *this;
      }

      /**
       * \brief >>> ���ڿɵ������ͣ������������ʼλ�õĵ� n ��Ԫ��Ϊ��ͼ��
       * 
       * \param ��ֵ� �ɵ�������
       * \param ����� Ԫ�����������ΪĬ��ֵ���Զ����㳤�ȡ�
       * \return this &
       * \tparam TmpU�� �ɵ������ͣ��������Ҫ��ת��Ϊ STmpT *
       */
      template<�������� TmpU>
      ��ͼ�� &��ֵ(TmpU &&��ֵ��, ���ͳ��� ������ = ��ĩβ) noexcept
      requires(ת������<ģ���������<TmpU>, TmpT *>)
      {
         return this->��ֵ(::BE::��ʼ(��ֵ��), ������ == ��ĩβ ? ::BE::��ȡ����(��ֵ��) : ������);
      }

      /**
       * \brief >>> ��ȡ��ͼ�е�Ԫ��������
       * 
       * \return Ԫ��������
       */
      ���ͳ��� ��ȡ����() const noexcept
      {
         return this->���г���;
      }

      /**
       * \brief >>> ��ȡ��ͼ�е� n ��Ԫ�ص����á�
       * 
       * \param ����� ������ע��Խ���жϡ�
       * \return Ԫ�����á�
       */
      TmpT &����ֵ(���ͳ��� ������) noexcept
      {
         return (this->��ȡָ��())[������];
      }

      /**
       * \brief >>> ��ȡ��ͼ�е� n ��Ԫ�ص�ֻ�����á�
       * 
       * \param ����� ������ע��Խ���жϡ�
       * \return Ԫ��ֻ�����á�
       */
      const TmpT &����ֵ(���ͳ��� ������) const noexcept
      {
         return ::BE::ȥ��ֻ��(*this).����ֵ(������);
      }

      /**
       * \brief >>> ��ȡ��ͼ�е����һ��Ԫ�ص����á�
       * 
       * \return Ԫ�����ã�ע��Խ���жϡ�
       */
      TmpT &��ȡβֵ() noexcept
      {
         return (this->��ȡָ��())[this->���г��� - 1];
      }

      /**
       * \brief >>> ��ȡ��ͼ�е����һ��Ԫ�ص�ֻ�����á�
       * 
       * \return Ԫ��ֻ�����ã�ע��Խ���жϡ�
       */
      const TmpT &��ȡβֵ() const noexcept
      {
         return ::BE::ȥ��ֻ��(*this).��ȡβֵ();
      }
     
      /**
       * \brief >>> ��ȡ������ͼ��ָ�롣
       * 
       * \return ָ�롣
       */
      TmpT *��ȡָ��() noexcept
      {
         return *this->��ȡָ������();
      }

      /**
       * \brief >>> ��ȡ������ͼ��ָ�롣
       * 
       * \return ֻ��ָ�롣
       */
      const TmpT *��ȡָ��() const noexcept
      {
         return *this->��ȡָ������();
      }

      /**
       * \brief >>> ����ʼ��ȡָ�����ȵ�����ͼ��
       * 
       * \param ����� Ҫ��ȡ�ĳ��ȣ�������ڵ�ǰ�������൱�ڱ����ĸ�����
       * \return ����ͼ��
       */
      ��ͼ�� �����ȡ(���ͳ��� ������) noexcept
      {
         return ��ͼ��(this->��ȡָ��(), ::BE::��Сֵ(this->���г���, ������));
      }

      /**
       * \brief >>> ���ҿ�ʼ��ȡָ�����ȵ�����ͼ��
       * 
       * \param ����� Ҫ��ȡ�ĳ��ȣ�������ڵ�ǰ�������൱�ڱ����ĸ�����
       * \return ����ͼ��
       */
      ��ͼ�� ���ҽ�ȡ(���ͳ��� ������) noexcept
      {
         ������ = ::BE::��Сֵ(this->���г���, ������);

         return ��ͼ��(this->��ȡָ��() + this->���г��� - ������, ������);
      }

      /**
       * \brief >>> ��ָ��λ�ÿ�ʼ��ȡָ�����ȵ�����ͼ��
       * 
       * \param ��ʼ� ��ʼλ�ã�������ڵ��ڵ�ǰ�����򷵻ؿ���ͼ��
       * \param ����� Ҫ��ȡ�ĳ��ȣ�������Ͽ�ʼλ�ô��ڵ�ǰ�������ȡ��ĩβ��
       * \return ����ͼ��
       */
      ��ͼ�� ��ȡ(���ͳ��� ��ʼ��, ���ͳ��� ������) noexcept
      {
         if (��ʼ�� >= this->���г���)
         {
            return ��ͼ��();
         }

         return ��ͼ��(this->��ȡָ��() + ��ʼ��, ::BE::��Сֵ(this->���г��� - ��ʼ��, ������));
      }

      /**
       * \brief >>> �жϵ�ǰ��ͼ�Ƿ�Ϊ�ա�
       * 
       * \return ���ǿ��򷵻��棬����١�
       */
      �����߼� �ǿյ�() const noexcept
      {
         return this->��ȡָ��() != ��ָ�� && this->���г��� != 0;
      }

      protected:

      // �洢���ȵĳ�Ա��
      ���ͳ��� ���г���;

      public:

      // ������ͨ���ͣ�ֱ��ǳ���Ƽ��ɡ�
      ��ͼ�� &operator = (const ��ͼ�� &) noexcept = default;
      ��ͼ�� &operator = (��ͼ�� &&) noexcept = default;

      // ������ֵ�ɵ������ͣ���ֵʱ�Զ����㳤�ȡ�
      template<�������� TmpU>
      ��ͼ�� &operator = (TmpU &&��ֵ��) noexcept requires(ת������<ģ���������<TmpU>, TmpT *> && ��ֵ����<TmpU>)
      {
         return this->��ֵ(::BE::��ʼ(��ֵ��), ::BE::��ȡ����(��ֵ��));
      }

      // ��ȡ�� n ��Ԫ�ص����ã�ע��Խ���жϡ�
      TmpT &operator [] (���ͳ��� ������) noexcept
      {
         return this->����ֵ(������);
      }

      // ��ȡ�� n ��Ԫ�ص�ֻ�����ã�ע��Խ���жϡ�
      const TmpT &operator [] (���ͳ��� ������) const noexcept
      {
         return this->����ֵ(������);
      }

      // ��ȡ���������޸İ汾����ȡ��ָ��λ�ÿ�ʼ��ָ�����ȵ���ͼ����ֵ���Լ���
      ��ͼ�� &operator () (���ͳ��� ��ʼ��, ���ͳ��� ������ = ��ĩβ) noexcept
      {
         return *this = this->��ȡ(��ʼ��, ������);
      }

      // �жϵ�ǰ��ͼ�Ƿ�Ϊ�գ����ǿ��򷵻��棬����١�
      explicit operator �����߼�() const noexcept
      {
         return this->�ǿյ�();
      }

   };

   // ��ָ����������Ƶ���
   template<typename TmpT>
   ��ͼ��(TmpT *, ���ͳ���) -> ��ͼ��<TmpT>;

   // ��һ���ɵ������Ͳ��������Ƶ���
   template<�������� TmpT>
   ��ͼ��(TmpT &&) -> ��ͼ��<std::remove_reference_t<ģ���������<ģ���������<TmpT>>>>;

   // ��һ���ɵ������Ͳ����ͳ��Ȳ��������Ƶ���
   template<�������� TmpT>
   ��ͼ��(TmpT &&, ���ͳ���) -> ��ͼ��<std::remove_reference_t<ģ���������<ģ���������<TmpT>>>>;

}