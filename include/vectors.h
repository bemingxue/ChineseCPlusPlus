
namespace BE {

   /**
    * \brief >>> �ṩһ�����鳤�ȿɱ������������֧�ֲ��롢ɾ���ȳ��������
    * \tparam TmpT�� ֧���ƶ���Ԫ�ء�
    */
   template<�������� TmpT>
   struct �ɱ������� : protected �����ռ���<TmpT>
   {

      using ��׼�����ʶ = void;
      using ���л��� = �����ռ���<TmpT>;

      using ���л���::begin;
      using ���л���::end;
      using ���л���::��ȡ����;
      using ���л���::��ȡ�ܳ���;
      using ���л���::��ȡָ��;
      using ���л���::operator[];
      using ���л���::operator �����߼�;

      // ʹ����̳еĴ����ຯ��������
      using ���л���::��ȡ����;
      using ���л���::�޴����;
      using ���л���::���ô���;
      using ���л���::���ô���;

      // Ĭ�Ϲ��캯����
      �ɱ�������() noexcept : ���л���() 
      {
      
      }

      // ��ȡĿ���е�������������Ȩ�����Ŀ�ꡣ
      �ɱ�������(�ɱ������� &&��ֵ��) noexcept
      {
         this->���л���::��ֵ(std::move(��ֵ��));
      }

      // ���ƹ��캯����
      �ɱ�������(const �ɱ������� &��ֵ��) noexcept
      {
         this->��ֵ(��ֵ��.begin(), ��ֵ��.end(), ��ֵ��.��ȡ����());
      }

      // ʹ�õ�����Χ�е�ֵ�������顣
      template<����������� InputT, typename IDRT = ģ���������<InputT>>
      �ɱ�������(InputT ��ʼ��, InputT ������, ���ͳ��� ������ = ��ĩβ)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, IDRT>))
      requires(�ɸ�ֵ��������<TmpT, IDRT>)
      {
         this->��ֵ(��ʼ��, ������, ������);
      }

      // ʹ�ÿɵ��������еĵ�����Χ�������顣
      template<�������� TmpU, typename IDRT = ģ���������<ģ���������<TmpU>>>
      �ɱ�������(TmpU &&������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, IDRT>))
      requires(�ɸ�ֵ��������<TmpT, IDRT>)
      {
         this->��ֵ(std::forward<TmpU>(������));
      }

      // ʹ���б��еĳ�Ա�������顣
      template<typename TmpU>
      �ɱ�������(const ģ���б�����<TmpU> &�б���)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, const TmpU &>))
      requires(�ɸ�ֵ��������<TmpT, const TmpU &>)
      {
         this->��ֵ(�б���);
      }

      // ʹ�ò�������ָ�����ȵ����顣
      template<typename... TmpArgs>
      �ɱ�������(���ͳ��� ������, TmpArgs&&... ���������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, TmpArgs...>))
      requires(�ɸ�ֵ��������<TmpT, TmpArgs...>)
      {
         this->��ֵ(������, std::forward<TmpArgs>(���������)...);
      }

      // ʹ�õ�����ķ���ֵ����ָ�����ȵ����顣
      template<��������<> TmpCall, typename TmpRet = ģ�巵������<TmpCall>>
      �ɱ�������(���ͳ��� ������, TmpCall &&������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, TmpRet>))
      requires(�ɸ�ֵ��������<TmpT, TmpRet> && !�ɸ�ֵ��������<TmpT, TmpCall>) /* ��� TmpCall �ܹ���ֵ/���� �� STmpT ���Ե� ��ֵ/���� */
      {
         this->��ֵ(������, std::forward<TmpCall>(������));
      }

      /**
       * \brief >>> ��������Χ�еĳ�Ա ��ֵ/���� �������еĳ�Ա��Ҳ����ָ���������Ʒ�Χ��
       * 
       * \param ��ʼ� ������Χ��ʼ��
       * \param ����� ������Χ������
       * \param ����� ָ�����ȣ�Ĭ�Ϻ����Զ����㳤�ȣ����ָ���������������С�ڳ����򵽽��������򵽳��ȡ�
       * \return this &
       * \tparam InputT�� �������㵥����������͵Ŀɶ����������������Ԫ��Ҫ�ܸ�ֵ���쵽 TmpT��
       */
      template<����������� InputT, typename IDRT = ģ���������<InputT>>
      �ɱ������� &��ֵ(InputT ��ʼ��, InputT ������, ���ͳ��� ������ = ��ĩβ)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, IDRT>))
      requires(�ɸ�ֵ��������<TmpT, IDRT>)
      {
         ���ͳ��� ԭ���� = this->��ȡ����();

         ������ = ������ == ��ĩβ ? ::BE::��ȡ����(��ʼ��, ������) : ������;
         this->������Ч��Χ<false>(������);

         for (TmpT *������ = this->begin(); ������ != this->end() && ��ʼ�� != ������; ++������, ++��ʼ��)
         {
            ::BE::ѡ��ֵ(*������, ������ - this->begin(), ::BE::��Сֵ(ԭ����, ������), *��ʼ��);
         }

         return *this;
      }

      /**
       * \brief >>> ��ָ���ɵ��������еĵ�����Χֵ ��ֵ/���� �������еĳ�Ա��
       * 
       * \param ����� �ɵ�������
       * \return this &
       * \tparam TmpU�� �ɵ������ͣ��������Ԫ������Ҫ�ܸ�ֵ���쵽 TmpT��
       */
      template<�������� TmpU, typename IDRT = ģ���������<ģ���������<TmpU>>>
      �ɱ������� &��ֵ(TmpU &&������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, IDRT>))
      requires(�ɸ�ֵ��������<TmpT, IDRT>)
      {
         if constexpr (��������<TmpU>)
         {
            return this->��ֵ(::BE::��ʼ(������), ::BE::����(������), ::BE::��ȡ����(������));
         }
         else
         {
            return this->��ֵ(::BE::��ʼ(������), ::BE::����(������));
         }
      }

      /**
       * \brief >>> ��ָ���б��е�ֵ ��ֵ/���� �������еĳ�Ա��
       * 
       * \param �б�� Ҫ��ֵ���б�
       * \return this &
       * \tparam TmpU�� Ҫ���ܹ� const & ��ֵ���쵽 STmpT �����͡�
       */
      template<typename TmpU>
      �ɱ������� &��ֵ(const ģ���б�����<TmpU> &�б���)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, const TmpU &>))
      requires(�ɸ�ֵ��������<TmpT, const TmpU &>)
      {
         return this->��ֵ(�б���.begin(), �б���.end(), �б���.size());
      }

      /**
       * \brief >>> ��������ĳ��ȣ�����ÿ����Աʹ�ò������еĳ�Ա���� ��ֵ/���졣
       * 
       * \param ����� Ҫ�������ĳ��ȡ�
       * \param ��������� ���ݸ���Ա��ֵ��������캯���Ĳ�����
       * \return this &
       * \tparam TmpArgs�� �ܹ��� STmpT ��ֵ/���� �Ĳ�����ʾ�����Ϊ 0 ���ʾʹ��Ĭ�Ϲ��캯����
       */
      template<typename... TmpArgs>
      �ɱ������� &��ֵ(���ͳ��� ������, TmpArgs&&... ���������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, TmpArgs...>))
      requires(�ɸ�ֵ��������<TmpT, TmpArgs...>)
      {
         this->������Ч��Χ(������, std::forward<TmpArgs>(���������)...);
         return *this;
      }

      /**
       * \brief >>> ��������ĳ��ȣ�����ÿ����Ա��ʹ�õ�����ķ���ֵ���� ��ֵ/���졣
       * 
       * \param ����� Ҫ���õĳ��ȡ�
       * \param ����� �ɵ��ö���
       * \return this &
       * \tparam TmpCall�� �ɵ������ͣ��������κβ������䷵��ֵ����Ҫ�ܸ�ֵ���쵽 TmpT���������ֱ�Ӹ�ֵ����� STmpT ���Ե� ��ֵ���� �� TmpT��
       */
      template<��������<> TmpCall, typename TmpRet = ģ�巵������<TmpCall>>
      �ɱ������� &��ֵ(���ͳ��� ������, TmpCall &&������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, TmpRet>))
      requires(�ɸ�ֵ��������<TmpT, TmpRet> && !�ɸ�ֵ��������<TmpT, TmpCall>) /* ��� TmpCall �ܹ���ֵ/���� �� STmpT ���Ե� ��ֵ/���� */
      {
         ���ͳ��� ԭ���� = this->��ȡ����();

         this->������Ч��Χ(������);

         for (TmpT *������ = this->begin(); ������ != this->end(); ++������)
         {
            ::BE::ѡ��ֵ(*������, ������ - this->begin(), ::BE::��Сֵ(ԭ����, ������), ������());
         }

         return *this;
      }

      /**
       * \brief >>> ��ȡĿ���е�������������Ȩ�����Ŀ�ꡣ
       * 
       * \param ��ֵ� Ҫ�ƶ���Ŀ�ꡣ
       * \return this &
       */
      �ɱ������� &��ֵ(�ɱ������� &&��ֵ��) noexcept
      {
         this->���л���::��ֵ(std::move(��ֵ��));
         return *this;
      }

      /**
       * \brief >>> ��ȡ���������һ��Ԫ�ص����ã�ע������Խ�硣
       * 
       * \return Ԫ�����á�
       */
      TmpT &��ȡβֵ() noexcept
      {
         return this->operator[](this->��ȡ����() - 1);
      }

      /**
       * \brief >>> ��ȡ���������һ��Ԫ�ص�ֻ�����ã�ע������Խ�硣
       * 
       * \return Ԫ��ֻ�����á�
       */
      const TmpT &��ȡβֵ() const noexcept
      {
         return ::BE::ȥ��ֻ��(*this).��ȡβֵ();
      }

      /**
       * \brief >>> ɾ�������дӿ�ʼ�ʼ��ָ��������Ԫ�ء�
       * 
       * \param ��ʼ� Ҫɾ���Ŀ�ʼλ�ã����Խ����������Ϊ��
       * \param ����� Ҫɾ����Ԫ���������������Ϊ 0 ��������Ϊ��������Ͽ�ʼ�����ǰ���鳤����ɾ����ĩβ��
       * \return this &
       */
      �ɱ������� &ɾ��(���ͳ��� ��ʼ��, ���ͳ��� ������ = ��ĩβ) noexcept
      {
         if (��ʼ�� >= this->��ȡ����() || ������ == 0)
         {
            return *this;
         }

         // ��ǰ���ȼ�ȥ��ʼ�����������������ֵ��
         ������ = ::BE::��Сֵ(this->��ȡ����() - ��ʼ��, ������);

         // ����Ǵӿ�ʼ��һֱɾ����ĩβ�Ļ��Ͳ���Ҫ�ƶ�Ԫ�أ�ֱ�ӽضϼ��ɡ�
         if (��ʼ�� + ������ < this->��ȡ����())
         {
            TmpT *������ = this->begin() + ��ʼ��;
            TmpT *�ƶ������� = this->begin() + ��ʼ�� + ������;

            for (; �ƶ������� != this->end(); ++������, ++�ƶ�������)
            {
               *������ = std::move(*�ƶ�������);
            }
         }

         this->������Ч��Χ(this->��ȡ����() - ������);

         return *this;
      }

      /**
       * \brief >>> ������ָ�������Ĳ������� ��ֵ/���� �ķ�ʽ���뵽�����е�ָ��λ�á�
       * 
       * \param ����� Ҫ���� ��ֵ/���� ���
       * \param ����� Ҫ�����λ�ã�������ڵ�ǰ���鳤������뵽����ĩβ��
       * \param �ظ�� Ҫ����Ĵ�����Ĭ��Ϊ 1 �Σ����Ϊ 0 ��������Ϊ��
       * \return this &
       * \tparam TmpU�� �ܹ��� STmpT ���� ��ֵ/���� �����͡�
       */
      template<typename TmpU>
      �ɱ������� &����(TmpU &&������, ���ͳ��� ������ = ��ĩβ, ���ͳ��� �ظ��� = 1)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, TmpU>))
      requires(�ɸ�ֵ��������<TmpT, TmpU>)
      {
         if (�ظ��� == 0)
         {
            return *this;
         }

         ���ͳ��� ԭ���� = this->��ȡ����();
         ���ͳ��� �³��� = ԭ���� + �ظ���;

         ������ = ::BE::��Сֵ(������, ԭ����);

         this->������Ч��Χ<false>(�³���);

         TmpT *������ = this->begin() + �³��� - 1;
         TmpT *�ƶ������� = this->begin() + ԭ���� - 1;

         for (; �ƶ������� >= this->begin() + ������; --������, --�ƶ�������)
         {
            // ����ԭ��Χ֮���Ԫ�أ����ù��캯�������ƶ����죬����ʹ���ƶ���ֵ��
            if (������ >= this->begin() + ԭ����)
            {
               new(reinterpret_cast<void *>(������)) TmpT(std::move(*�ƶ�������));
            }
            else
            {
               *������ = std::move(*�ƶ�������);
            }
         }

         // �ϴ�ѭ����ɺ󣬵�����һ��ָ��Ҫ������������һ��Ԫ�ص�λ�á�
         for (; ������ >= this->begin() + ������; --������)
         {
            ::BE::ѡ��ֵ(*������, ������ - this->begin(), ԭ����, ������);
         }

         return *this;
      }

      /**
       * \brief >>> ��������Ԫ�ز��������� 0���������ͷ�ռ�õ��ڴ�ռ䡣
       * 
       * \return this &
       */
      �ɱ������� &���() noexcept
      {
         this->������Ч��Χ(0);
         return *this;
      }

      // ��ȫ����������
      ~�ɱ�������() noexcept
      {

      }

      // ��ȡĿ����������������Ȩ�����Ŀ�ꡣ
      �ɱ������� &operator = (�ɱ������� &&��ֵ��) noexcept
      {
         return this->��ֵ(std::move(��ֵ��));
      }

      // ���Ƹ�ֵ������
      �ɱ������� &operator = (const �ɱ������� &��ֵ��) noexcept
      {
         return this->��ֵ(��ֵ��.begin(), ��ֵ��.end(), ��ֵ��.��ȡ����());
      }

      // ʹ�ÿɵ�������ĵ�����Χֵ��ֵ���顣
      template<�������� TmpU, typename IDRT = ģ���������<ģ���������<TmpU>>>
      �ɱ������� &operator = (TmpU &&������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, IDRT>))
      requires(�ɸ�ֵ��������<TmpT, IDRT>)
      {
         return this->��ֵ(std::forward<TmpU>(������));
      }

      // ʹ���б��е�ֵ��ֵ���顣
      template<typename TmpU>
      �ɱ������� &operator = (const ģ���б�����<TmpU> &�б���)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, const TmpU &>))
      requires(�ɸ�ֵ��������<TmpT, const TmpU &>)
      {
         return this->��ֵ(�б���);
      }

   };

   // ����ʹ�õ������͵ĵ�����������Ԫ���Ƶ�ģ�����ͣ������Ƶ��� const��volatile��reference��
   template<�������� TmpT>
   �ɱ�������(TmpT &&) -> �ɱ�������<std::remove_cvref_t<ģ���������<ģ���������<TmpT>>>>;

   // ����ʹ�õ�����Χ�Ľ�����Ԫ���Ƶ�ģ�����ͣ������Ƶ��� const��volatile��reference��
   template<����������� TmpT>
   �ɱ�������(TmpT, TmpT) -> �ɱ�������<std::remove_cvref_t<ģ���������<TmpT>>>;

   // ����ʹ�õ�����Χ�Ľ�����Ԫ���Ƶ�ģ�����ͣ������Ƶ��� const��volatile��reference��
   template<����������� TmpT>
   �ɱ�������(TmpT, TmpT, ���ͳ���) -> �ɱ�������<std::remove_cvref_t<ģ���������<TmpT>>>;

   // ����ʹ�õ�����ķ���ֵ�Ƶ�ģ�����ͣ����ܻ��Ƶ��� const��volatile��reference��
   template<��������<> TmpCall>
   �ɱ�������(���ͳ���, TmpCall &&) -> �ɱ�������<ģ�巵������<TmpCall>>;

   // ����ʹ���б��Ƶ�ģ�����ͣ���Ҫ�� TmpArgs ���������Ͳ��������� TmpT��
   template<typename TmpT, typename... TmpArgs>
   requires(ȫ��ֵ<��ͬ����<TmpArgs, TmpT>...>)
   �ɱ�������(TmpT, TmpArgs...) -> �ɱ�������<TmpT>;

}
