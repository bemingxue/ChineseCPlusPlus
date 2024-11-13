
namespace BE {

   // namespace enum���ṩһЩ�����������ö�٣�����չ��
   namespace ����ö��
   {
      enum : int
      {
         // ������������Сֵ��ѭ���������������������ּ������͡�
         ���ּ��� = 0, 
         // ��ָ���������͵���Сֵ���������ֵ�����ּ������͡�
         �������� = 1,
         // ����һ���������б����м�����
         �б���� = 2,
         // �ڴ�дӢ����ĸ֮����м����ļ������͡�
         ��д��ĸ = 65,
         // ��СдӢ����ĸ֮����м����ļ������͡�
         Сд��ĸ = 97,
      };
   };

   // ������ģ�壬����ʹ��û���ػ��İ汾��
   template<int TmpType, typename TmpT = void, auto... TmpArgs>
   struct ������
   {
      static_assert(false, "Counting classes without special cases - δ�������ļ�����");
   };

   /**
    * \brief >>> һ���ڱ����ھ���������Χ�ļ������ͣ�������ѭ��������Ҳ�����Ƿ�Χ�������������һ��˫���������
    * \brief >>> EGO ���͡�
    * \tparam TmpT�� �������ͣ������������ָ������ܹ���Ϊģ�������
    * \tparam TmpMin�� ��������Сֵ��Ҳ�ǳ�ʼֵ��
    * \tparam TmpCount�� һ�����������Ĵ�����
    * \tparam TmpStep�� ÿ�μ���������ֵ��
    * \tparam TmpRepeat�� �Ƿ�ѭ��������ѭ���������ṩ begin �� end ��Ա������
    */
   template<�������� TmpT, TmpT TmpMin, TmpT TmpCount, TmpT TmpStep, �����߼� TmpRepeat>
   struct ������<����ö��::���ּ���, TmpT, TmpMin, TmpCount, TmpStep, TmpRepeat>
   {
      // ����ȫ���������
      using EGO = void;

      // ���������ֵ��
      static constexpr TmpT ���ֵ = TmpCount * TmpStep + TmpMin;

      // �����ĵ�����������ѭ���������ṩ��
      ������ begin() const noexcept requires(!TmpRepeat) { return ������(); }
      ������ end()   const noexcept requires(!TmpRepeat) { return ������(���ֵ); }

      ������() noexcept : ���е�ǰ(TmpMin) { }

      ������(const ������ &������) noexcept : ���е�ǰ(������.���е�ǰ) { }

      /**
       * \brief >>> ���ü���Ϊ��С����ֵ��
       * 
       * \return this &
       */
      ������ &����() noexcept
      {
         ���е�ǰ = TmpMin;

         return *this;
      }

      /**
       * \brief >>> ����һ�μ�������������Ѿ�ʹ���ֵ�ҷ�ѭ��������������Ϊ��
       * 
       * \return this &
       */
      ������ &����() noexcept
      {
         if constexpr (TmpRepeat)
         {
            ���е�ǰ += TmpStep;

            // ���������ֵ��
            if (���е�ǰ >= ���ֵ)
            {
               this->����();
            }
         }

         else
         {
            if (���е�ǰ != ���ֵ)
            {
               ���е�ǰ += TmpStep;
            }
         }

         return *this;
      }

      /**
       * \brief >>> �ݼ�һ�μ�������������Ѿ�ʹ��Сֵ�ҷ�ѭ��������������Ϊ��
       * 
       * \return this &
       */
      ������ &�ݼ�() noexcept
      {
         if constexpr (TmpRepeat)
         {
            if (���е�ǰ <= TmpMin)
            {
               ���е�ǰ = ���ֵ;
            }

            ���е�ǰ -= TmpStep;
         }

         else
         {
            if (���е�ǰ != TmpMin)
            {
               ���е�ǰ -= TmpStep;
            }
         }

         return *this;
      }

      /**
       * \brief >>> ��ȡ��ǰ�ļ���ֵ��
       * 
       * \return ����ֵ��ֻ�����á�
       */
      const TmpT &��ȡֵ() const noexcept
      {
         return ���е�ǰ;
      }

      /**
       * \brief >>> ��ȡ��ǰ��������ָ�롣
       * 
       * \return ��������ֻ��ָ�롣
       */
      const TmpT *��ֵ() const noexcept
      {
         return &���е�ǰ;
      }

      /**
       * \brief >>> �ж������������ĵ�ǰ����ֵ�Ƿ���ȡ�
       * 
       * \param �ж�� Ҫ�жϵĶ���
       * \return ��ȷ����棬���򷵻ؼ١�
       */
      �����߼� ����ж�(const ������ &�ж���) const noexcept
      {
         return ���е�ǰ == �ж���.��ȡֵ();
      }

      /**
       * \brief >>> �Ƚ������������ĵ�ǰ����ֵ��
       * 
       * \param �ж�� Ҫ�ȽϵĶ���
       * \return ���ڷ��� 1�����ڷ��� 0��С�ڷ��� -1��
       */
      ���ͱȽ� �Ƚ��ж�(const ������ &�ж���) const noexcept
      {
         return ���е�ǰ > �ж���.���е�ǰ ? 1 : (���е�ǰ < �ж���.���е�ǰ ? -1 : 0);
      }

      protected:
      
      // ��������ı�����
      TmpT ���е�ǰ;

      // ˽�еĹ��캯������ end ����ʹ�á�
      ������(TmpT ��ʼ��) noexcept : ���е�ǰ(��ʼ��) { }

      public:

      // ����һ�μ�������������Ѿ�ʹ���ֵ�ҷ�ѭ��������������Ϊ��
      ������ &operator ++ () noexcept
      {
         return this->����();
      }

      // �ݼ�һ�μ�������������Ѿ�ʹ��Сֵ�ҷ�ѭ��������������Ϊ��
      ������ &operator -- () noexcept
      {
         return this->�ݼ�();
      }

      // ��ȡ��ǰ�ļ���ֵ��ֻ�����á�
      const TmpT &operator * () const noexcept
      {
         return this->��ȡֵ();
      }

      // ��ȡ��ǰ��������ֻ��ָ�롣
      const TmpT *operator -> () const noexcept
      {
         return this->��ֵ();
      }

   };

   /**
    * \brief >>> �ṩ������Χ�� 0 �� STmpT ���͵����ֵ�����������ֵ�����м����ļ������͡�
    * \brief >>> EGO ���͡�
    * \brief >>> �̳��ԣ� ������<���ּ���, STmpT, STmpT{ 0 }, ������Ϣ��<STmpT>::���ֵ, STmpT{ 1 }, false>��
    * \tparam TmpT�� �������ͣ��������������͡�
    */
   template<�������� TmpT>
   struct ������<����ö��::��������, TmpT>
        : ������<����ö��::���ּ���, TmpT, TmpT{ 0 }, ������Ϣ��<TmpT>::���ֵ, TmpT{ 1 }, false>
   {
      
   };
   
   /**
    * \brief >>> һ�ֱ�����ĸ A �� Z �ļ������͡�
    * \brief >>> EGO ���͡�
    * \tparam TmpT�� �������ͣ��������ַ����͡�
    */
   template<�ַ����� TmpT>
   struct ������<����ö��::��д��ĸ, TmpT>
        : ������<����ö��::���ּ���, TmpT, TmpT{ 65 }, TmpT{ 26 }, TmpT{ 1 }, false>
   {

   };

   /**
    * \brief >>> һ�ֱ�����ĸ a �� z �ļ������͡�
    * \brief >>> EGO ���͡�
    * \tparam TmpT�� �������ͣ��������ַ����͡�
    */
   template<�ַ����� TmpT>
   struct ������<����ö��::Сд��ĸ, TmpT>
        : ������<����ö��::���ּ���, TmpT, TmpT{ 97 }, TmpT{ 26 }, TmpT{ 1 }, false>
   {

   };

   /**
    * \brief >>> �� TmpMin һ��һ�������� TmpMax ����ͨ�������ͣ�Ϊ ������ ��һ���ػ��������������ڷ�Χ for ѭ����ָ��ѭ�����ٴΡ�
    * \tparam TmpT�� �������ͣ��������������͡�
    * \tparam TmpMin�� ��������Сֵ��Ҳ�ǳ�ʼֵ��Ĭ��Ϊ 0��
    * \tparam TmpMax�� ���������ֵ��Ĭ��Ϊ 10��
    */
   template<�������� TmpT, TmpT TmpMin = 0, TmpT TmpMax = 10>
   using ��Χ������ = ������<����ö��::���ּ���, TmpT, TmpMin, TmpMax + TmpMin, TmpT{ 1 }, false>;

   /**
    * \brief >>> һ�����ڱ��� TmpV��TmpArgs... ���б�ɵ����������ͣ��б��ȱ�����ڻ�ȡ����һ��
    * \tparam TmpT�� �������ͣ������ǿ�Ϊģ����������͡�
    * \tparam TmpV��TmpArgs�� �б��Ԫ�أ���������ͬ���͡�
    */
   template<typename TmpT, TmpT TmpV, TmpT... TmpArgs>
   struct ������<����ö��::�б����, TmpT, TmpV, TmpArgs...>
   {
      // ����ȫ���������
      using EGO = void;

      // �б�ĳ��ȣ�Ҳ���б�����ܹ��ﵽ�����ֵ����
      static constexpr ���ͳ��� �б��� = sizeof...(TmpArgs) + 1;
      // �洢�б����ֵ��
      static constexpr TmpT     �б�����[�б���] = { TmpV, TmpArgs... };

      // ʹ�ñ���������Ϊ��������
      ������ begin() const noexcept { return ������(); }
      ������ end()   const noexcept { return ������(�б���); }

      // Ĭ�Ϲ��캯������ʼ������ֵΪ 0��
      ������() noexcept : ���е�ǰ(0) { }

      // ���ƹ��캯�������Ƽ���ֵ��
      ������(const ������ &������) noexcept : ���е�ǰ(������.���е�ǰ) { }

      /**
       * \brief >>> ������������Ϊ��ʼֵ��
       * 
       * \return this &
       */
      ������ &����() noexcept
      {
         ���е�ǰ = 0;

         return *this;
      }

      /**
       * \brief >>> ����������һ�Σ�����Ѿ��ﵽ�б��ĩβ֮���һ��Ԫ�������κβ�����
       * 
       * \return this &
       */
      ������ &����() noexcept
      {
         ���е�ǰ = ���е�ǰ + 1 <= �б��� ? ���е�ǰ + 1 : ���е�ǰ;

         return *this;
      }

      /**
       * \brief >>> �ݼ�һ�μ�����������Ѿ��ﵽ�б�Ŀ�ͷ֮ǰ��һ��Ԫ�������κβ�����
       * 
       * \return this &
       */
      ������ &�ݼ�() noexcept
      {
         ���е�ǰ = ���е�ǰ != 0 ? ���е�ǰ - 1 : 0;

         return *this;
      }

      /**
       * \brief >>> ��ȡ��ǰ��������ʾ��ֵ��
       * 
       * \return 
       */
      const TmpT &��ȡֵ() const noexcept
      {
         return �б�����[���е�ǰ];
      }

      /**
       * \brief >>> �жϼ����Ƿ�ĩβ��
       * 
       * \return ��������棬����١�
       */
      �����߼� ��ĩβ() const noexcept
      {
         return ���е�ǰ == �б���;
      }

      // �ж������������Ƿ���ȡ�
      �����߼� ����ж�(const ������ &�ж���) const noexcept
      {
         return ���е�ǰ == �ж���.���е�ǰ;
      }

      // �Ƚ������������Ĵ�С��
      ���ͱȽ� �Ƚ��ж�(const ������ &�ж���) const noexcept
      {
         return ���е�ǰ > �ж���.���е�ǰ ? 1 : (���е�ǰ < �ж���.���е�ǰ ? -1 : 0);
      }

      protected:

      // ��������ı�����
      ���ͳ��� ���е�ǰ = 0;

      // ˽�еĹ��캯������ end ����ʹ�á�
      ������(���ͳ��� ��ʼ��) noexcept : ���е�ǰ(��ʼ��) { }

      public:

      // ��ȡ��ǰ��������ʾ��ֵ��ֻ�����á�
      const TmpT &operator * () const noexcept
      {
         return this->��ȡֵ();
      }

      // ��ȡ��ǰ��������ʾ��ֵ��ֻ��ָ�롣
      const TmpT *operator -> () const noexcept
      {
         return &�б�����[���е�ǰ];
      }

      // ����������һ�Σ�����Ѿ��ﵽ�б��ĩβ֮���һ��Ԫ�������κβ�����
      ������ &operator ++ () noexcept
      {
         return this->����();
      }

      // �ݼ�һ�μ�����������Ѿ��ﵽ�б�Ŀ�ͷ֮ǰ��һ��Ԫ�������κβ�����
      ������ &operator -- () noexcept
      {
         return this->�ݼ�();
      }

      // �������û�еִ�ĩβ�򷵻��棬���򷵻ؼ١�
      explicit operator bool() const noexcept
      {
         return !this->��ĩβ();
      }
   };

}
