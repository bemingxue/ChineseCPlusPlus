
namespace BE::�ļ����ݼ� {

   enum class JSON����ö��
   {
       ��Ч,
       ����,
       ����,
       �ַ���,
       ����,
       ����,
       �߼�,
       ��ֵ
   };

   struct JSON������;
   struct JSON������;

   /**
    * \brief >>> ���ڴ洢���� JSON ���ݣ������������㡢�߼�����ֵ���ַ���������������������ݵ��ࡣ
    */
   struct JSON�������ݴ洢��
   {
      using ��ֵ�� = �����ֽ�[sizeof(T::IPTR)];
      using ������ = T::I64;
      using ������ = T::F64;

      // Ĭ�Ϲ��캯����
      JSON�������ݴ洢��() noexcept = default;

      // �ƶ����캯������ȡĿ�����ݵ�����Ȩ����ն���
      JSON�������ݴ洢��(JSON�������ݴ洢�� &&��ֵ��) noexcept
      {
         this->ö��ֵ = BE::������ֵ(��ֵ��.ö��ֵ, JSON����ö��::��Ч);
         std::memcpy(this->�洢ֵ, ��ֵ��.�洢ֵ, sizeof(this->�洢ֵ));
         std::memset(��ֵ��.�洢ֵ, 0, sizeof(��ֵ��.�洢ֵ));
      }

      // ���ƹ��캯�������ڷ��ַ��������顢����ֱ�Ӱ��ֽڸ������ݡ�
      JSON�������ݴ洢��(const JSON�������ݴ洢�� &��ֵ��) noexcept
      {
         this->operator=(��ֵ��);
      }

      // ���Ƹ�ֵ���������ڷ��ַ��������顢����ֱ�Ӱ��ֽڸ������ݡ�
      JSON�������ݴ洢�� &operator = (const JSON�������ݴ洢�� &��ֵ��) noexcept
      {
         if (��ֵ��.ö��ֵ == JSON����ö��::�ַ���)
         {
            this->operator=(**��ֵ��.תΪָ��ֵ<JSON����ö��::�ַ���>());
         }
         else if (��ֵ��.ö��ֵ == JSON����ö��::����)
         {
            this->operator=(**��ֵ��.תΪָ��ֵ<JSON����ö��::����>());
         }
         else if (��ֵ��.ö��ֵ == JSON����ö��::����)
         {
            this->operator=(**��ֵ��.תΪָ��ֵ<JSON����ö��::����>());
         }
         else
         {
            this->�ͷ�();
            this->ö��ֵ = ��ֵ��.ö��ֵ;
            std::memcpy(this->�洢ֵ, ��ֵ��.�洢ֵ, sizeof(this->�洢ֵ));
         }

         return *this;
      }

      // ����ֵΪ�����������͡�
      template<�ϸ��������� TmpT>
      JSON�������ݴ洢�� &operator = (TmpT ��ֵ��) noexcept
      {
         if (this->ö��ֵ != JSON����ö��::����)
         {
            this->�ͷ�();
            this->ö��ֵ = JSON����ö��::����;
           *this->תΪָ��ֵ<JSON����ö��::����>() = static_cast<������>(��ֵ��);
         }
         else
         {
           *this->תΪָ��ֵ<JSON����ö��::����>() = static_cast<������>(��ֵ��);
         }

         return *this;
      }

      // ����ֵΪ���⸡�����͡�
      template<�������� TmpT>
      JSON�������ݴ洢�� &operator = (TmpT ��ֵ��) noexcept
      {
         if (this->ö��ֵ != JSON����ö��::����)
         {
            this->�ͷ�();
            this->ö��ֵ = JSON����ö��::����;
           *this->תΪָ��ֵ<JSON����ö��::����>() = static_cast<������>(��ֵ��);
         }
         else
         {
           *this->תΪָ��ֵ<JSON����ö��::����>() = static_cast<������>(��ֵ��);
         }

         return *this;
      }

      // ����ֵΪһ�� JSON ����
      JSON�������ݴ洢�� &operator = (const JSON������ &��ֵ��) noexcept;
      // ����ֵΪһ�� JSON ���顣
      JSON�������ݴ洢�� &operator = (const JSON������ &��ֵ��) noexcept;

      // ���������ַ������͸�ֵΪ�ַ�����
      template<�ַ������� TmpT>
      JSON�������ݴ洢�� &operator = (TmpT ��ֵ��) noexcept
      {
         if (this->ö��ֵ != JSON����ö��::�ַ���)
         {
            this->�ͷ�();
            this->ö��ֵ = JSON����ö��::�ַ���;
           *this->תΪָ��ֵ<JSON����ö��::�ַ���>() = BE::ֱ�ӹ���(BE::����ԭʼ�ڴ�<�ַ�����>(1), 1, std::forward<TmpT>(��ֵ��));
         }
         else
         {
          **this->תΪָ��ֵ<JSON����ö��::�ַ���>() = ��ֵ��;
         }

         return *this;
      }

      // �����������͸�ֵΪ�߼�ֵ��
      JSON�������ݴ洢�� &operator = (�����߼� ��ֵ��) noexcept
      {
         this->�ͷ�();
         this->ö��ֵ = JSON����ö��::�߼�;
        *this->תΪָ��ֵ<JSON����ö��::�߼�>() = static_cast<bool>(��ֵ��);
         return *this;
      }

      // �� JSON ���ݸ�ֵΪ null ��ֵ��
      JSON�������ݴ洢�� &operator = (���Ϳ�ֵ) noexcept
      {
         this->�ͷ�();
         this->ö��ֵ = JSON����ö��::��ֵ;
         return *this;
      }

      /**
       * \brief >>> ���ݵ�ǰ�� JSON ö��ֵ�ͷŶ��ڵ��ڴ�ռ䲢�ͷŶ��󣬶��ڷ��ַ��������顢���������ͷš�
       * 
       * \return this &
       */
      JSON�������ݴ洢�� &�ͷ�() noexcept
      {
         if (this->ö��ֵ == JSON����ö��::�ַ���)
         {
            BE::�ͷ�ԭʼ�ڴ�(BE::ֱ������(*this->תΪָ��ֵ<JSON����ö��::�ַ���>(), 1));
         }
         else if (this->ö��ֵ == JSON����ö��::����)
         {
            BE::�ͷ�ԭʼ�ڴ�(BE::ֱ������(*this->תΪָ��ֵ<JSON����ö��::����>(), 1));
         }
         else if (this->ö��ֵ == JSON����ö��::����)
         {
            BE::�ͷ�ԭʼ�ڴ�(BE::ֱ������(*this->תΪָ��ֵ<JSON����ö��::����>(), 1));
         }

         this->ö��ֵ = JSON����ö��::��Ч;
         return *this;
      }

      /**
       * \brief >>> ����ָ��ö��ת��Ϊ��Ӧ�� JSON ���ݴ洢���󣬶����ַ��������顢���󣬷��ش洢ָ���ָ�룬������������Ч���򷵻ض�Ӧ���͵�ָ�룬���ֵ���� nullptr���������� `������*`��
       * \brief >>> ������Ч����ʲôҲ�����أ�������ֵ����Ϊ void��
       * 
       * \return ����ö�ٵĶ�Ӧ�洢��ʽ���͡�
       */
      template<JSON����ö�� TmpEnum>
      decltype(auto) תΪָ��ֵ() noexcept
      {
         if constexpr (TmpEnum == JSON����ö��::����)
         {
            return reinterpret_cast<������ *>(this->�洢ֵ);
         }
         else if constexpr (TmpEnum == JSON����ö��::����)
         {
            return reinterpret_cast<������ *>(this->�洢ֵ);
         }
         else if constexpr (TmpEnum == JSON����ö��::�߼�)
         {
            return reinterpret_cast<bool *>(this->�洢ֵ);
         }
         else if constexpr (TmpEnum == JSON����ö��::�ַ���)
         {
            return reinterpret_cast<�ַ����� **>(this->�洢ֵ);
         }
         else if constexpr (TmpEnum == JSON����ö��::��ֵ)
         {
            return nullptr;
         }
         else if constexpr (TmpEnum == JSON����ö��::����)
         {
            return reinterpret_cast<JSON������ **>(this->�洢ֵ);
         }
         else if constexpr (TmpEnum == JSON����ö��::����)
         {
            return reinterpret_cast<JSON������ **>(this->�洢ֵ);
         }
         else
         {
            return;
         }
      }

      /**
       * \brief >>> ����ָ��ö��ת��Ϊ��Ӧ�� JSON ���ݴ洢���󣬶����ַ��������顢���󣬷��ش洢ָ���ָ�룬������������Ч���򷵻ض�Ӧ���͵�ָ�룬���ֵ���� nullptr���������� `������*`��
       * \brief >>> ������Ч����ʲôҲ�����أ�������ֵ����Ϊ void��
       *
       * \return ����ö�ٵĶ�Ӧ�洢��ʽ���͡�
       */
      template<JSON����ö�� TmpEnum>
      decltype(auto) תΪָ��ֵ() const noexcept
      {
         return BE::ȥ��ֻ��(*this).תΪָ��ֵ<TmpEnum>();
      }

      // ��ȫ���������������ͷź����ͷš�
      ~JSON�������ݴ洢��() noexcept
      {
         this->�ͷ�();
      }

      // �洢ֵ�����ͣ������ַ��������顢���󣬴洢���ǵ�ָ��ֵ��
      alignas(8)
      ��ֵ��       �洢ֵ;
      JSON����ö�� ö��ֵ;
   };

   /**
    * \brief >>> һ������ά���洢һЩ�� JSON ���ݵĿɵ������͡�
    */
   struct JSON������
   {
      using ����� = �ɱ�������<JSON�������ݴ洢��>;

      auto begin() noexcept { return this->���д洢.begin(); };
      auto end() noexcept { return this->���д洢.end(); };

      auto begin() const noexcept { return this->���д洢.begin(); };
      auto end() const noexcept { return this->���д洢.end(); };

      // Ĭ�Ϲ��캯����
      JSON������() noexcept = default;

      // ����ʹ�����鹹�� JSON ���顣
      JSON������(const ����� &��ֵ��) noexcept : ���д洢(��ֵ��)
      {

      }

      /**
       * \brief >>> ������ָ��λ�ò���һ�� JSON ���ݡ�
       * 
       * \param ����� Ҫ����� JSON ���ݡ�
       * \param λ��� Ҫ�����λ�ã�Ĭ��Ϊ����ĩβ��
       * \return this &
       */
      JSON������ &����(const JSON�������ݴ洢�� &������, ���ͳ��� λ���� = ��ĩβ) noexcept
      {
         this->���д洢.����(������, λ����);
         return *this;
      }

      /**
       * \brief >>> ������ĩβ����һ����Ч�� JSON ���ݲ����䷵�ء�
       * 
       * \return JSON �������á�
       */
      JSON�������ݴ洢�� &׷��() noexcept
      {
         this->����(JSON�������ݴ洢��(), ��ĩβ);
         return this->���д洢.��ȡβֵ();
      }

      /**
       * \brief >>> ��ȡ����ĳ��ȡ�
       * 
       * \return ���鳤�ȡ�
       */
      ���ͳ��� ��ȡ����() const noexcept
      {
         return this->���д洢.��ȡ����();
      }

      /**
       * \brief >>> ��ȡ JSON �������ڹ������ݵĵײ�����
       * 
       * \return Ŀ���������á�
       */
      ����� &��ȡ���() noexcept
      {
         return this->���д洢;
      }

      /**
       * \brief >>> ��ȡ JSON �������ڹ������ݵĵײ�����
       * 
       * \return Ŀ������ֻ�����á�
       */
      const ����� &��ȡ���() const noexcept
      {
         return this->���д洢;
      }

      // ��ȫ�����������ͷ����� JSON ���ݡ�
      ~JSON������() noexcept
      {

      }

      protected:

      ����� ���д洢;

      public:

      // ��ȡָ������λ�õ� JSON �������ã�ע��Խ�硣
      JSON�������ݴ洢�� &operator [] (���ͳ��� ������) noexcept
      {
         return this->���д洢[������];
      }

   };

   template<typename TmpT>
   concept JSON�������� = ��ֵ����<JSON�������ݴ洢��, TmpT>;

   /**
    * \brief >>> һ������ά��һЩ�� JSON ���ݼ������Ƶļ�ֵ�Կɵ������͡�
    */
   struct JSON������
   {
      using ��ֵ�� = ��ֵ��<�ַ�����, JSON�������ݴ洢��>;
      using ����� = std::unordered_map<�ַ�����, JSON�������ݴ洢��>;

      auto begin() noexcept { return this->���д洢.begin(); }
      auto end() noexcept { return this->���д洢.end(); }

      auto begin() const noexcept { return this->���д洢.begin(); }
      auto end() const noexcept { return this->���д洢.end(); }

      // Ĭ�Ϲ��캯����
      JSON������() noexcept = default;

      // ����ʹ�ü�ֵ�Թ��� JSON ����
      JSON������(const ����� &��ֵ��) noexcept : ���д洢(��ֵ��)
      {

      }

      /**
       * \brief >>> �ڶ����в���һ����ֵ�ԣ���������Ѵ��ڣ�����ΪΪ��ֵ�����ڶ���ʹ�ü�ֵ��ʾ����������ṩ������
       * 
       * \param ����� Ҫ����ļ�����
       * \param ����� Ҫ����� JSON ���ݡ�
       * \return this &
       */
      JSON������ &����(const �ַ����� &������, const JSON�������ݴ洢�� &������) noexcept
      {
         this->���д洢[������] = ������;
         return *this;
      }

      /**
       * \brief >>> ��ȡ�����еļ�ֵ��������
       * 
       * \return ��ֵ��������
       */
      ���ͳ��� ��ȡ����() const noexcept
      {
         return static_cast<���ͳ���>(this->���д洢.size());
      }

      /**
       * \brief >>> �Ӷ����л�ȡָ��������Ӧ�� JSON ���ݣ�����������򷵻ؿ�ָ�룬�������ڼ����Ƿ���ڡ�
       * 
       * \param ����� Ҫ��ȡ�ļ�����
       * \return JSON ����ָ�룬�����������򷵻ؿ�ָ�롣
       */
      JSON�������ݴ洢�� *��ȡ(const �ַ����� &������) noexcept
      {
         if (auto λ�� = this->���д洢.find(������); λ�� != this->���д洢.end())
         {
            return &λ��->second;
         }
         return ��ָ��;
      }

      /**
       * \brief >>> ��ȡ JSON �������ڹ������ݵĵײ�����
       * 
       * \return Ŀ���������á�
       */
      ����� &��ȡ���() noexcept
      {
         return this->���д洢;
      }

      /**
       * \brief >>> ��ȡ JSON �������ڹ������ݵĵײ�����
       * 
       * \return Ŀ������ֻ�����á�
       */
      const ����� &��ȡ���() const noexcept
      {
         return this->���д洢;
      }

      // ��ȫ�����������ͷ����� JSON ���ݡ�
      ~JSON������() noexcept
      {

      }

      protected:

      ����� ���д洢;

      public:

      // ���ݼ�������ָ�� JSON ���ݵ����ã���������������򴴽�����
      JSON�������ݴ洢�� &operator () (const �ַ����� &������) noexcept
      {
         return this->���д洢[������];
      }

      template<JSON�������� TmpT>
      JSON������ &operator () (const �ַ����� &������, TmpT &&��ֵ��) noexcept
      {
         this->���д洢[������] = ��ֵ��;
         return *this;
      }
   };

   inline JSON�������ݴ洢�� &BE::�ļ����ݼ�::JSON�������ݴ洢��::operator = (const JSON������ &��ֵ��) noexcept
   {
      if (this->ö��ֵ != JSON����ö��::����)
      {
         this->�ͷ�();
         this->ö��ֵ = JSON����ö��::����;
        *this->תΪָ��ֵ<JSON����ö��::����>() = BE::ֱ�ӹ���(BE::����ԭʼ�ڴ�<JSON������>(1), 1, ��ֵ��.��ȡ���());
      }
      else
      {
         (*this->תΪָ��ֵ<JSON����ö��::����>())->��ȡ���() = ��ֵ��.��ȡ���();
      }

      return *this;
   }

   JSON�������ݴ洢�� &BE::�ļ����ݼ�::JSON�������ݴ洢��::operator = (const JSON������ &��ֵ��) noexcept
   {
      if (this->ö��ֵ != JSON����ö��::����)
      {
         this->�ͷ�();
         this->ö��ֵ = JSON����ö��::����;
        *this->תΪָ��ֵ<JSON����ö��::����>() = BE::ֱ�ӹ���(BE::����ԭʼ�ڴ�<JSON������>(1), 1, ��ֵ��.��ȡ���());
      }
      else
      {
         (*this->תΪָ��ֵ<JSON����ö��::����>())->��ȡ���() = ��ֵ��.��ȡ���();
      }

      return *this;
   }

}

namespace BE {

   template<>
   struct ת�ַ�����<�ļ����ݼ�::JSON����ö��>
   {
      �ַ����� operator () (const �ļ����ݼ�::JSON����ö�� &ö��ֵ) const noexcept
      {
         switch (ö��ֵ)
         {
            case �ļ����ݼ�::JSON����ö��::����:
               return C("[:enum ���� - ARRAY]");
            case �ļ����ݼ�::JSON����ö��::����:
               return C("[:enum ���� - OBJECT]");
            case �ļ����ݼ�::JSON����ö��::�ַ���:
               return C("[:enum �ַ��� - STRING]");
            case �ļ����ݼ�::JSON����ö��::����:
               return C("[:enum ���� - INTEGER]");
            case �ļ����ݼ�::JSON����ö��::����:
               return C("[:enum ���� - FLOAT]");
            case �ļ����ݼ�::JSON����ö��::�߼�:
               return C("[:enum ���� - BOOLEAN]");
            case �ļ����ݼ�::JSON����ö��::��ֵ:
               return C("[:enum ��ֵ - NULL]");
            default:
               return C("[:enum ��Ч - INVALID]");
         }
      }
   };

   template<>
   struct ת�ַ�����<�ļ����ݼ�::JSON������>;

   template<>
   struct ת�ַ�����<�ļ����ݼ�::JSON������>
   {
      �ַ����� operator () (const �ļ����ݼ�::JSON������ &ת����, �ַ���ͼ�� ���з��� = C("\n"), ���ͳ��� ������ = 4, ���ͳ��� ��ʼ������ = 0) const noexcept;
   };

   template<>
   struct ת�ַ�����<�ļ����ݼ�::JSON������>
   {
      �ַ����� operator () (const �ļ����ݼ�::JSON������ &ת����, �ַ���ͼ�� ���з��� = C("\n"), ���ͳ��� ������ = 4, ���ͳ��� ��ʼ������ = 0) const noexcept
      {
         �ַ����� ����ֵ = ��ʽ����(C("{:*}"), C('{'), ��ʼ������);
         ���ͳ��� ��ʼ���� = ��ʼ������;
         ���ͳ��� ת������ = 0;

         for (auto &&[����, ֵ] : ת����)
         {
            if (���з���.��ȡ����() != 0)
            {
               ����ֵ << ���з��� << �ַ�����(C(' '), ��ʼ������ + ������);
            }

            if (ֵ.ö��ֵ != �ļ����ݼ�::JSON����ö��::��Ч)
            {
               ����ֵ << C('\"') << ����.תΪԭʼ�ַ���() << C('\"') << C(':');

               if (ֵ.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
               {
                  ����ֵ << this->operator()(**ֵ.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>(), ���з���, ������, ��ʼ������ + ������);
               }
               else if (ֵ.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
               {
                  ����ֵ << ת�ַ�����<�ļ����ݼ�::JSON������>()(**ֵ.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>(), ���з���, ������, ��ʼ������ + ������);
               }
               else if (ֵ.ö��ֵ == �ļ����ݼ�::JSON����ö��::�ַ���)
               {
                  ����ֵ << C('\"') << (**ֵ.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::�ַ���>()).תΪԭʼ�ַ���() << C('\"');
               }
               else if (ֵ.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
               {
                  ����ֵ << (*ֵ.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>());
               }
               else if (ֵ.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
               {
                  ����ֵ << (*ֵ.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>());
               }
               else if (ֵ.ö��ֵ == �ļ����ݼ�::JSON����ö��::�߼�)
               {
                  ����ֵ << ((*ֵ.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::�߼�>()) ? C("true") : C("false"));
               }
               else if (ֵ.ö��ֵ == �ļ����ݼ�::JSON����ö��::��ֵ)
               {
                  ����ֵ << C("null");
               }
            }

            if (++ת������ < ת����.��ȡ����())
            {
               ����ֵ << C(',');
            }
            
         }

         if (���з���.��ȡ����() != 0)
         {
            ����ֵ << ���з��� << �ַ�����(C(' '), ��ʼ����);
         }

         return ����ֵ << ��ʽ����(C("{:*}"), C('}'), ��ʼ����);
      }
   };

   inline �ַ����� BE::ת�ַ�����<�ļ����ݼ�::JSON������>::operator()(const �ļ����ݼ�::JSON������ &ת����, �ַ���ͼ�� ���з���, ���ͳ��� ������, ���ͳ��� ��ʼ������) const noexcept
   {
      �ַ����� ����ֵ = ��ʽ����(C("{:*}"), C('['), ��ʼ������);
      ���ͳ��� ��ʼ���� = ��ʼ������;
      ���ͳ��� ת������ = 0;

      for (auto &������ : ת����)
      {
         if (���з���.��ȡ����() != 0)
         {
            ����ֵ << ���з��� << �ַ�����(C(' '), ��ʼ������ + ������);
         }

         if (������.ö��ֵ != �ļ����ݼ�::JSON����ö��::��Ч)
         {

            if (������.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
            {
               ����ֵ << ת�ַ�����<�ļ����ݼ�::JSON������>()(**������.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>(), ���з���, ������, ��ʼ������ + ������);
            }
            else if (������.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
            {
               ����ֵ << this->operator()(**������.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>(), ���з���, ������, ��ʼ������ + ������);
            }
            else if (������.ö��ֵ == �ļ����ݼ�::JSON����ö��::�ַ���)
            {
               ����ֵ << C('\"') << (**������.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::�ַ���>()).תΪԭʼ�ַ���() << C('\"');
            }
            else if (������.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
            {
               ����ֵ << (*������.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>());
            }
            else if (������.ö��ֵ == �ļ����ݼ�::JSON����ö��::����)
            {
               ����ֵ << (*������.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::����>());
            }
            else if (������.ö��ֵ == �ļ����ݼ�::JSON����ö��::�߼�)
            {
               ����ֵ << ((*������.תΪָ��ֵ<�ļ����ݼ�::JSON����ö��::�߼�>()) ? C("true") : C("false"));
            }
            else if (������.ö��ֵ == �ļ����ݼ�::JSON����ö��::��ֵ)
            {
               ����ֵ << C("null");
            }
         }

         if (++ת������ < ת����.��ȡ����())
         {
            ����ֵ << C(',');
         }

      }

      if (���з���.��ȡ����() != 0)
      {
         ����ֵ << ���з��� << �ַ�����(C(' '), ��ʼ����);
      }

      return ����ֵ << ��ʽ����(C("{:*}"), C(']'), ��ʼ����);
   }

}
