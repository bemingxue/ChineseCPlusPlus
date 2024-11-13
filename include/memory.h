
namespace BE {

   // һ�� STmpT ���Խ��� STmpT = TmpArgs ��TmpArgs = 1����ֵ�������߽��� STmpT(TmpU, TmpArgs...) ������������͸��
   template<typename TmpT, typename... TmpArgs>
   concept �ɸ�ֵ�������� = (��ֵ����<TmpT, TmpArgs...> && sizeof...(TmpArgs) == 1) || ��������<TmpT, TmpArgs...>;

   // һ�� STmpT ���Խ��� STmpT = TmpArgs ��TmpArgs = 1����ȫ��ֵ�������߽��� STmpT(TmpU, TmpArgs...) ��ȫ������������͸��
   template<typename TmpT, typename... TmpArgs>
   concept �ɰ�ȫ��ֵ�������� = (��ȫ��ֵ����<TmpT, TmpArgs...> && sizeof...(TmpArgs) == 1) || ��ȫ��������<TmpT, TmpArgs...>;

   // �ڸ�ֵ�빹���ѡ���б�ʾʹ�ø�ֵ��
   inline constexpr �����߼� ѡ��ʹ�ø�ֵ = ��;

   // �ڸ�ֵ�빹���ѡ���б�ʾʹ�ù��졣
   inline constexpr �����߼� ѡ��ʹ�ù��� = ��;

   /**
    * \brief >>> ѡ��ʹ�ø�ֵ���ǹ��죬��� TmpArgs ֻ��һ�����жϣ���ֵ�͹�������ѡ��ֵ��Ȼ���жϰ�ȫ�ԡ�
    * 
    * \return `ѡ��ֵ` �� `ѡ����`
    */
   template<typename TmpT, typename... TmpArgs>
   inline consteval �����߼� ��ֵ����() noexcept
   {
      if constexpr (sizeof...(TmpArgs) == 1)
      {
         if constexpr (��ȫ��ֵ����<TmpT, TmpArgs...>)
         {
            return ѡ��ʹ�ø�ֵ;
         }
         else if constexpr (��ȫ��������<TmpT, TmpArgs...>)
         {
            return ѡ��ʹ�ù���;
         }
         else
         {
            return ѡ��ʹ�ø�ֵ;
         }
      }

      return ѡ��ʹ�ù���;
   }

   /**
    * \brief >>> ��ָ��ָ���ָ����д���ڴ��ȫ�����㡣
    * 
    * \param ָ��� ָ���ڴ���ָ�롣
    * \param ����� �ڴ��ĳ��ȡ�
    * \param ���ͳ���� �ڴ����ÿ��Ԫ�ص��ֽڳ��ȣ�Ĭ��Ϊ sizeof(STmpT)��
    * \return ָ����
    */
   template<typename TmpT>
   inline TmpT *�����(TmpT *ָ����, ���ͳ��� ������, ���ͳ��� ���ͳ����� = sizeof(TmpT)) noexcept
   {
      return ָ���� ? reinterpret_cast<TmpT *>(std::memset(ָ����, 0, ������ * ���ͳ�����)) : ��ָ��;
   }

   /**
    * \brief >>> ��ָ��ָ����ڴ���е�ָ������Ԫ��ȫ��������
    * 
    * \param ָ��� ָ���ڴ���ָ�롣
    * \param ����� �ڴ����Ԫ�ص�������
    * \return ָ����
    * \tparam TmpT�� �ڴ����Ԫ�ص����ͣ������ƽ������������������
    */
   template<typename TmpT>
   inline TmpT *ֱ������(TmpT *ָ����, ���ͳ��� ������) noexcept
   {
      if constexpr (!ƽ����������<TmpT>)
      {
         for (TmpT *������ = ָ����; ָ���� && static_cast<���ͳ���>(������ - ָ����) < ������; ++������)
         {
            ������->~TmpT();
         }
      }

      return ָ����;
   }

   /**
    * \brief >>> ��ָ��ָ����ڴ���й���ָ��������Ԫ�أ��������������
    * 
    * \param ָ��� ָ���ڴ���ָ�롣
    * \param ����� �ڴ����Ԫ�ص�������
    * \param ��������� Ҫ���ݸ����캯���Ĳ�����
    * \return ָ����
    */
   template<typename TmpT, typename... TmpArgs>
   inline TmpT *ֱ�ӹ���(TmpT *ָ����, ���ͳ��� ������, TmpArgs&&... ���������) noexcept
   {
      for (TmpT *������ = ָ����; ָ���� && static_cast<���ͳ���>(������ - ָ����) < ������; ++������)
      {
         new (reinterpret_cast<void *>(������)) TmpT(std::forward<TmpArgs>(���������)...);
      }

      return ָ����;
   }

   /**
    * \brief >>> �Ը�ֵ���е�ÿ��Ԫ���ƶ���ָ����ָ����ڴ���е�ÿ��Ԫ�ء�
    * 
    * \param ָ��� ָ���ڴ���ָ�롣
    * \param ��ֵ� Ҫ�����ƶ����ڴ�飬����ڴ��е�Ԫ�ض���δ�����ҷ�ƽ��������Ϊδ���塣
    * \param ����� �ڴ����Ԫ�ص�������
    * \return ָ����
    */
   template<typename TmpT, typename TmpU>
   inline TmpT *�ƶ�����(TmpT *ָ����, TmpU *��ֵ��, ���ͳ��� ������) noexcept
   {
      for (TmpT *������ = ָ����; ָ���� && static_cast<���ͳ���>(������ - ָ����) < ������; ++������)
      {
         new (reinterpret_cast<void *>(������)) TmpT(std::move(*��ֵ��));

         ++��ֵ��;
      }

      return ָ����;
   }

   /**
    * \brief >>> ����ָ��ָ����ڴ���е�ָ��������Ԫ�أ������¹��졣
    * 
    * \param ָ��� ָ���ڴ���ָ�롣
    * \param ����� �ڴ����Ԫ�ص�������
    * \param ��������� Ҫ���ݸ����캯���Ĳ�����
    * \return ָ����
    */
   template<typename TmpT, typename... TmpArgs>
   inline TmpT *���¹���(TmpT *ָ����, ���ͳ��� ������, TmpArgs&&... ���������) noexcept
   {
      for (TmpT *������ = ָ����; ָ���� && static_cast<���ͳ���>(������ - ָ����) < ������; ++������)
      {
         ������->~TmpT();

         new (reinterpret_cast<void *>(������)) TmpT(std::forward<TmpArgs>(���������)...);
      }

      return ָ����;
   }

   /**
    * \brief >>> ��ϵͳ�з���ָ��Ԫ�س��ȵ��ڴ棬��������Щ�ڴ���й��졣
    * 
    * \param ����� Ҫ�����Ԫ��������
    * \return ָ���ڴ���ָ�룬�������ʧ�ܣ��򷵻ؿ�ָ�롣
    */
   template<typename TmpT>
   inline TmpT *����ԭʼ�ڴ�(���ͳ��� ������) noexcept
   {
      try {
         TmpT  *tmp = reinterpret_cast<TmpT *>(::operator new(������ * sizeof(TmpT)));
         // ...
#ifdef _BE_TEST_OUTPUT_MEM_
         if (tmp)
            std::cout << "allocate memory: " << (void *)tmp << std::endl;
#endif
         return tmp;
      } catch (...) {
         return ��ָ��;
      }
   }

   /**
    * \brief >>> �ͷ��ڴ�飬��������������
    * 
    * \param ָ��� ָ���ڴ���ָ�롣
    * \return 
    */
   template<typename TmpT>
   inline ���Ϳյ� �ͷ�ԭʼ�ڴ�(TmpT *ָ����) noexcept
   {
#ifdef _BE_TEST_OUTPUT_MEM_
      if (ָ����)
         std::cout << "release memory: " << (void *)ָ���� << std::endl;
#endif
      ::operator delete(reinterpret_cast<void *>(ָ����));
   }
   
   /**
    * \brief >>> �����Զ�����������������ѡ��ʹ�ø�ֵ���ǹ��죬�������Ĳ������������� 1 ������ʹ�ù��죬������ݸ�ֵ���ȡ���ȫ��ѡ��ֵ���߹���
    * 
    * \param ��ֵ� Ҫ���и�ֵ�Ķ���
    * \param ����� �������ڴ���е�λ�á�
    * \param ����� �ڴ����Ԫ�ص�������
    * \param ������ Ҫ���ݸ����캯����ֵ������Ĳ�����
    * \return ��ֵ��
    * \tparam TmpT�� Ҫ���и�ֵ�Ķ������͡�
    * \tparam TmpArgs�� Ҫ���ݸ����캯����ֵ������Ĳ�����
    */
   template<typename TmpT, typename... TmpArgs>
   inline TmpT &ѡ��ֵ(TmpT &��ֵ��, ���ͳ��� ������, ���ͳ��� ������, TmpArgs&&... ������)
   noexcept(noexcept(�ɰ�ȫ��ֵ��������<TmpT, TmpArgs...>))
   requires(�ɸ�ֵ��������<TmpT, TmpArgs...>)
   {
      // ������ڷ�Χ����Ԫ�ؿ��ܱ����������������ʹ�ù��졣
      if (������ >= ������)
      {
         ::BE::ֱ�ӹ���(::BE::��ȡ��ַ(��ֵ��), 1, std::forward<TmpArgs>(������)...);
      }
      else
      {
         if constexpr (��ֵ����<TmpT, TmpArgs...>() == ѡ��ʹ�ø�ֵ)
         {
            ��ֵ�� = (std::forward<TmpArgs>(������), ...);
         }
         else
         {
            ::BE::���¹���(::BE::��ȡ��ַ(��ֵ��), 1, std::forward<TmpArgs>(������)...);
         }
      }

      return ��ֵ��;
   }

   /**
    * \brief >>> �ͷ��ڴ棬ʹ�� delete��
    */
   template<typename TmpT>
   struct Ĭ���ڴ��ͷ���
   {
      ���Ϳյ� operator () (TmpT *ָ����, ���ͳ���) const noexcept
      {
         delete ָ����;
      }
   };

   /**
    * \brief >>> �ͷ��ڴ棬ʹ�� delete[]��
    */
   template<typename TmpT>
   struct Ĭ���ڴ��ͷ���<TmpT[]>
   {
      ���Ϳյ� operator () (TmpT *ָ����, ���ͳ���) const noexcept
      {
         delete[] ָ����;
      }
   };

   /**
    * \brief >>> �����ͷ��������ʵ�ʲ������κβ������ͷ��ࡣ
    */
   template<typename TmpT>
   struct Ĭ�ϼ��ڴ��ͷ���
   {
      ���Ϳյ� operator () (TmpT *, ���ͳ���) const noexcept
      {

      }
   };

}
