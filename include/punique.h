
namespace BE {

   /**
    * \brief >>> Ψһ��Ķ�ֵ����ṹ��Ҳ�������ݽṹ���洢ָ��ͳ�����Ϣ��
    */
   template<typename TmpT>
   struct Ψһ��ṹ
   {
      TmpT    *ָ�� = ��ָ��;
      ���ͳ��� ���� = 0;
   };

   /**
    * \brief >>> һ���йܾ���Ψһ����Ȩָ��Ŀɵ����࣬�ṩ�ṩ���ͷ����Զ������������ڣ�����ֹ���Ʋ�����
    * \tparam TmpT�� Ҫ�йܵ����ͣ������ޱ߽����飬���Զ��Ż�Ϊ�������͡�
    * \tparam TmpCall�� ���ڹ���ָ����ͷ������ͣ�Ĭ��ʹ�� delete �����Ը� STmpT ����ޱ߽��������η����ཫĬ��ѡ�� delete[]��Ҫ�����ṩ��Ӧ������ TmpCall(STmpT *, ���ͳ���) ��ȫ�������������ҿɰ�ȫĬ�Ϲ������ƶ���
    */
   template<typename TmpT, ��ȫ��������<std::add_pointer_t<std::remove_all_extents_t<TmpT>>, ���ͳ���> TmpCall = Ĭ���ڴ��ͷ���<TmpT>, typename TmpU = std::remove_all_extents_t<TmpT>>
   struct Ψһ�� : /* �̳ж�ֵ�����Ż��ڴ�ռ�ռ�� */ protected ��ֵ��<Ψһ��ṹ<TmpU>, TmpCall>
   {
      // ����ȫ���������
      using EGO = void;

      // �Ե�ǰ�洢��ָ����Ϊ��������ע���ָ�롣
      TmpU *begin() noexcept { return this->��ȡָ��(); }
      TmpU *end() noexcept { return this->��ȡָ��() + this->��ȡ����(); }

      // �Ե�ǰ�洢��ָ����Ϊ��������ע���ָ�롣
      const TmpU *begin() const noexcept { return this->��ȡָ��(); }
      const TmpU *end() const noexcept { return this->��ȡָ��() + this->��ȡ����(); }

      // Ĭ�Ϲ��캯����
      Ψһ��() noexcept
      {

      }

      // ��ֵ�ͷ����Ĺ��캯����
      Ψһ��(TmpCall ������) noexcept
      {
         this->��ȡβֵ() = ������;
      }

      // �ƶ����캯����
      Ψһ��(Ψһ�� &&��ֵ��) noexcept
      {
         this->��ֵ(std::move(��ֵ��));
      }

      // ��ֵָ�롢���Ⱥ��ͷ������ͷ���Ĭ��ʹ��Ĭ�Ϲ���ġ�
      Ψһ��(TmpU *ָ����, ���ͳ��� ������, TmpCall ������ = TmpCall { }) noexcept
      {
         this->��ȡβֵ() = ������;
         this->��ֵ(ָ����, ������);
      }

      // ���ƹ��캯��������ʹ�á�
      Ψһ��(const Ψһ�� &) noexcept = delete;

      /**
       * \brief >>> ��ָ�븳ֵ����ǰ�����У����ṩָ��ָ���ڴ��ĳ�����Ϣ��
       * 
       * \param ָ��� Ҫ��ֵ��ָ�룬�����Ǻ͵�ǰ�洢����ͬ��ָ�롣
       * \param ����� ָ��ָ���ڴ��ĳ��ȣ����ָ�����ǿ�ָ�������Ǹ�ֵ 0��
       * \return this &
       */
      Ψһ�� &��ֵ(TmpU *ָ����, ���ͳ��� ������) noexcept
      {
         this->��ȡ��ֵ().ָ�� = ָ����;
         this->��ȡ��ֵ().���� = ָ���� == ��ָ�� ? 0 :������;
         return *this;
      }

      /**
       * \brief >>> ��ȡĿ��ָ�롢�����Լ��ͷ���������Ȩ�����ÿ�Ŀ�ꡣ
       * 
       * \param ��ֵ� Ҫ�ƽ�����Ȩ�Ķ���������Լ���������Ϊ��
       * \return this &
       */
      Ψһ�� &��ֵ(Ψһ�� &&��ֵ��) noexcept
      {
         // �Լ���ֵ���Լ�������Ϊ��
         if (::BE::�Ƚϵ�ַ(*this, ��ֵ��) == 0)
         {
            return *this;
         }

         this->��ȡ��ֵ() = ::BE::������ֵ(��ֵ��.��ȡ��ֵ(), Ψһ��ṹ<TmpU>{ });
         this->��ȡβֵ() = ::BE::������ֵ(��ֵ��.��ȡβֵ(), TmpCall{ });
         return *this;
      }

      /**
       * \brief >>> ��ȡ��ǰ����洢���ͷ�����
       * 
       * \return �ͷ������á�
       */
      TmpCall &��ȡ�ͷ���() noexcept
      {
         return this->��ȡβֵ();
      }

      /**
       * \brief >>> ʹ��ǰ���������ָ����йܣ��������ͷŶ����䷵�أ���������й���ָ����������ڡ�
       * 
       * \return �йܵ�ָ�룬û���й�ʱΪ��ָ�롣
       */
      TmpU *�����й�() noexcept
      {
         TmpU *����ֵ = ::BE::������ֵ(this->��ȡ��ֵ().ָ��, ��ָ��);
         
         this->��ȡ��ֵ().���� = 0;

         return ����ֵ;
      }

      /**
       * \brief >>> ��ȡ��ǰ����洢��ָ�롣
       * 
       * \return ָ�롣
       */
      TmpU *��ȡָ��() noexcept
      {
         return this->��ȡ��ֵ().ָ��;
      }

      /**
       * \brief >>> ��ȡ��ǰ����洢��ָ�롣
       * 
       * \return ֻ��ָ�롣
       */
      const TmpU *��ȡָ��() const noexcept
      {
         return this->��ȡ��ֵ().ָ��;
      }

      /**
       * \brief >>> ��ȡ��ֵʱ�ṩ�ĳ�����Ϣ��
       * 
       * \return ������Ϣ��
       */
      ���ͳ��� ��ȡ����() const noexcept
      {
         return this->��ȡ��ֵ().����;
      }

      /**
       * \brief >>> �ж����ߴ洢��ָ���Ƿ���ͬ��
       * 
       * \param �Ƚ�� Ҫ�ȽϵĶ���
       * \return ��ͬ�򷵻��棬����١�
       */
      �����߼� ����ж�(const Ψһ�� &�Ƚ���) const noexcept
      {
         return this->��ȡָ��() == �Ƚ���.��ȡָ��();
      }

      /**
       * \brief >>> �жϵ�ǰ�����йܵ�ָ����Ŀ��ָ���Ƿ���ͬ��
       * 
       * \param �Ƚ�� Ҫ�Ƚϵ�ָ�롣
       * \return ��ͬ�򷵻��棬����١�
       */
      �����߼� ����ж�(const void *�Ƚ���) const noexcept
      {
         return this->��ȡָ��() == �Ƚ���;
      }

      /**
       * \brief >>> �Ƚ����ߴ洢��ָ��ֵ��
       * 
       * \param �Ƚ�� Ҫ�ȽϵĶ���
       * \return �����ǰָ�����Ŀ���ָ���򷵻ش��������������򷵻��㣬���򷵻�С���������
       */
      ���ͱȽ� �Ƚ��ж�(const Ψһ�� &�Ƚ���) const noexcept
      {
         return this->��ȡָ��() - �Ƚ���.��ȡָ��();
      }

      /**
       * \brief >>> �Ƚϵ�ǰ�����йܵ�ָ��ֵ��Ŀ��ָ��ֵ��
       * 
       * \param �Ƚ�� Ҫ�Ƚϵ�ָ�롣
       * \return �����ǰָ�����Ŀ���ָ���򷵻ش��������������򷵻��㣬���򷵻�С���������
       */
      ���ͱȽ� �Ƚ��ж�(const void *�Ƚ���) const noexcept
      {
         return this->��ȡָ��() - �Ƚ���;
      }

      /**
       * \brief >>> �����ͷ�������洢��ָ��󣬽�ָ��ͳ����ÿա�
       * 
       * \return this &
       */
      Ψһ�� &�ͷ�() noexcept
      {
         this->��ȡβֵ()(this->��ȡ��ֵ().ָ��, this->��ȡ��ֵ().����);
         this->��ȡ��ֵ().ָ�� = ��ָ��;
         this->��ȡ��ֵ().���� = 0;
         return *this;
      }

      /**
       * \brief >>> �������ߴ洢��ָ�롢���Ⱥ��ͷ�����
       * 
       * \param ����� Ҫ���н����Ķ���
       * \return this &
       */
      Ψһ�� &����(Ψһ�� &������) noexcept
      {
         ::BE::����(this->��ȡ��ֵ(), ������.��ȡ��ֵ());
         ::BE::����(this->��ȡβֵ(), ������.��ȡβֵ());
         return *this;
      }

      /**
       * \brief >>> �жϵ�ǰ�洢��ָ���Ƿ�Ϊ��ָ�롣
       * 
       * \return ���ǿ�ָ���򷵻��棬����١�
       */
      �����߼� �ǿյ�() const noexcept
      {
         return this->��ȡָ��() != ��ָ��;
      }

      // ��ȫ���������������ͷź�����
      ~Ψһ��() noexcept
      {
         this->�ͷ�();
      }

      // ��ֹ���Ƹ�ֵ����ֹ���á�
      Ψһ�� &operator = (const Ψһ�� &) noexcept = delete;

      // �ƶ���ֵ������ָ�롢���Ⱥ��ͷ�����
      Ψһ�� &operator = (Ψһ�� &&��ֵ��) noexcept
      {
         this->��ֵ(std::move(��ֵ��));
         return *this;
      }

      // ��ֵ��ָ��ֱ���ͷŲ��ÿյ�ǰ�йܵ�ָ�롣
      Ψһ�� &operator = (���Ϳ�ֵ) noexcept
      {
         this->�ͷ�();
         return *this;
      }

      // ��ȡ�洢��ָ�룬ע���ָ�롣
      TmpU *operator -> () noexcept
      {
         return this->��ȡָ��();
      }

      // ��ȡ�洢��ֻ��ָ�룬ע���ָ�롣
      const TmpU *operator -> () const noexcept
      {
         return this->��ȡָ��();
      }

      // ��ȡ�洢��ָ��ָ����ڴ���еĵ� n ��Ԫ�����ã�ע���ָ���Խ�硣
      TmpU &operator [] (���ͳ��� ������) noexcept
      {
         return this->��ȡָ��()[������];
      }

      // ��ȡ�洢��ָ��ָ����ڴ���еĵ� n ��Ԫ��ֻ�����ã�ע���ָ���Խ�硣
      const TmpU &operator [] (���ͳ��� ������) const noexcept
      {
         return this->��ȡָ��()[������];
      }

      // ��ǰ�洢��ָ�벻�ǿ�ָ���򷵻��棬����١�
      explicit operator �����߼� () const noexcept
      {
         return this->�ǿյ�();
      }

   };

}
