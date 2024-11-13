
namespace BE {

   /**
    * \brief >>> һ��ģ�����õ����ͣ���Ҫ������ģ������������ܹ��������������á�
    * \tparam STmpT �����õĶ������͡�
    */
   template<�������� STmpT>
   struct ������
   {

      using ģ��������� = STmpT;

      ������(STmpT &��ֵ��) noexcept : ����ָ��(&��ֵ��) 
      {
      
      }

      /**
       * \brief >>> ��ȡ���õĶ���
       * 
       * \return ��������á�
       */
      STmpT &��ȡ����() noexcept
      {
         return *this->����ָ��;
      }

      /**
       * \brief >>> ��ȡ���õĶ���
       * 
       * \return �����ֻ�����á�
       */
      const STmpT &��ȡ����() const noexcept
      {
         return *this->����ָ��;
      }

      protected:

      STmpT *����ָ��;

      public:

      // ���� STmpT = TmpT ��ֵ�ĸ�ֵ���õĶ���
      template<typename TmpT>
      ������ &operator = (TmpT &&��ֵ��)
      noexcept(noexcept(��ȫ��ֵ����<STmpT, TmpT>))
      requires(��ֵ����<STmpT, TmpT>)
      {
         *this->����ָ�� = std::forward<TmpT>(��ֵ��);
         return *this;
      }

      // ���� STmpT(TmpArgs...) ���õĵ������õĶ���
      template<typename... TmpArgs, typename TmpRet = ģ�巵������<STmpT, TmpArgs...>>
      TmpRet operator () (TmpArgs &&... ������)
      noexcept(noexcept(��ȫ��������<STmpT, TmpArgs...>))
      requires(��������<STmpT, TmpArgs...>)
      {
         return (*this->����ָ��)(std::forward<TmpArgs>(������)...);
      }

      // ���� STmpT[TmpT] �������õĶ���
      template<typename TmpT>
      decltype(auto) operator [] (TmpT &&�±���)
      noexcept(noexcept(requires(STmpT X) { { X[�±���] }noexcept; }))
      requires(requires(STmpT X) { { X[�±���] }; })
      {
         return (*this->����ָ��)[std::forward<TmpT>(�±���)];
      }
      
      // ��ȡ���õĶ����ַ���������������ĵ�ַ��
      STmpT *operator & () noexcept
      {
         return this->����ָ��;
      }

      operator STmpT &() noexcept
      {
         return *this->����ָ��;
      }

      operator const STmpT &() const noexcept
      {
         return *this->����ָ��;
      }

   };

   /**
    * \brief >>> ����ֵ��ʹ���������װ��
    * 
    * \param ��ֵ� ����װ�Ķ���
    * \return һ�����������
    */
   template<typename TmpT>
   ������<TmpT> ��������(TmpT &��ֵ��) noexcept
   {
      return ������<TmpT>(��ֵ��);
   }

   /**
    * \brief >>> ����ֵ��ʹ���������װ��
    * 
    * \param ��ֵ� ����װ�Ķ���
    * \return һ�����������
    */
   template<typename TmpT>
   ������<const TmpT> ����ֻ������(const TmpT &��ֵ��) noexcept
   {
      return ������<const TmpT>(��ֵ��);
   }

}
