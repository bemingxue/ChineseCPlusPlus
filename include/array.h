
namespace BE {

   /**
    * \brief >>> һ�ֹ��� C Type ����Ŀɵ������ͣ��������ƣ�������֧�ֳ��� 0 �����顣
    * \brief >>> ���⣬�໹�ṩ�˶�ά������������������������������������У������Щ��ͬ����֧�ֶ�ά���飬���ײ�������ʹ��һά������еĴ洢��
    * \tparam TmpT�� ����Ԫ�����ͣ�����������͸��
    * \tparam TmpW�� �����ȣ��������������
    * \tparam TmpH�� ����߶ȣ��������������Ĭ��Ϊ 1��
    */
   template<�������� TmpT, ���ͳ��� TmpW, ���ͳ��� TmpH = 1>
   struct ��׼������
   {
      using ��׼�����ʶ = void;

      // ����Ϊ 0 ���ȵ����顣
      static_assert(TmpW * TmpH > 0, "Array length cannot be zero - ���鳤�Ȳ���Ϊ 0��");

      // �����鱾��Ϊ��������
      TmpT *begin() noexcept {  return ����; }
      TmpT *end() noexcept {  return ���� + TmpW * TmpH; }

      // �����鱾��Ϊֻ����������
      TmpT const *begin() const noexcept {  return ����; }
      TmpT const *end() const noexcept {  return ���� + TmpW * TmpH; }

      /**
       * \brief >>> ��ȡ������ָ��λ�õ�Ԫ��ֵ��
       * 
       * \param ����� ������ע��Խ�硣
       * \return Ԫ�����á�
       */
      constexpr TmpT &����ֵ(���ͳ��� ������) noexcept
      {
         return ����[������];
      }

      /**
       * \brief >>> ��ȡ������ָ��λ�õ�Ԫ��ֵ��
       * 
       * \param ����� ������ע��Խ�硣
       * \return Ԫ��ֻ�����á�
       */
      constexpr const TmpT &����ֵ(���ͳ��� ������) const noexcept
      {
         return ����[������];
      }

      /**
       * \brief >>> ��ȡ�����еڼ��еڼ��е�Ԫ�����á�
       * 
       * \param ������� ��������ע��Խ�硣
       * \param ������� ��������ע��Խ�硣
       * \return Ԫ�����á�
       */
      constexpr TmpT &����ֵ(���ͳ��� ��������, ���ͳ��� ��������) noexcept
      {
         return ����[�������� * TmpW + ��������];
      }

      /**
       * \brief >>> ��ȡ�����еڼ��еڼ��е�Ԫ��ֻ�����á�
       * 
       * \param ������� ��������ע��Խ�硣
       * \param ������� ��������ע��Խ�硣
       * \return Ԫ��ֻ�����á�
       */
      constexpr const TmpT &����ֵ(���ͳ��� ��������, ���ͳ��� ��������) const noexcept
      {
         return ����[�������� * TmpW + ��������];
      }

      /**
       * \brief >>> ��ȡ���������һ��Ԫ�ص����á�
       * 
       * \return Ԫ�����á�
       */
      constexpr TmpT &��ȡβֵ() noexcept
      {
         return ����[TmpW * TmpH - 1];
      }

      /**
       * \brief >>> ��ȡ���������һ��Ԫ�ص�ֻ�����á�
       * 
       * \return Ԫ��ֻ�����á�
       */
      constexpr const TmpT &��ȡβֵ() const noexcept
      {
         return ����[TmpW * TmpH - 1];
      }

      /**
       * \brief >>> ��ȡ����ĳ��ȣ���������Ԫ�ص���������
       * 
       * \return Ԫ����������
       */
      constexpr ���ͳ��� ��ȡ����() const noexcept
      {
         return TmpW * TmpH;
      }

      /**
       * \brief >>> ��ȡ�����е�������
       * 
       * \return ������
       */
      constexpr ���ͳ��� ��ȡ����() const noexcept
      {
         return TmpH;
      }

      /**
       * \brief >>> ��ȡ�����е�������
       * 
       * \return ������
       */
      constexpr ���ͳ��� ��ȡ����() const noexcept
      {
         return TmpW;
      }

      /**
       * \brief >>> ��ȡ�����ָ�롣
       * 
       * \return ����ָ�롣
       */
      constexpr TmpT *��ȡָ��() noexcept
      {
         return ����;
      }

      /**
       * \brief >>> ��ȡ�����ֻ��ָ�롣
       * 
       * \return ����ֻ��ָ�롣
       */
      constexpr const TmpT *��ȡָ��() const noexcept
      {
         return ����;
      }

      // ��ȡ�����еڼ���Ԫ�ص����ã�ע��Խ�硣
      constexpr TmpT &operator[](���ͳ��� ������) noexcept
      {
         return this->����ֵ(������);
      }

      // ��ȡ�����еڼ���Ԫ�ص�ֻ�����ã�ע��Խ�硣
      constexpr const TmpT &operator[](���ͳ��� ������) const noexcept
      {
         return this->����ֵ(������);
      }

      // ��ȡ�����еڼ��еڼ��е�Ԫ�����ã�ע��Խ�硣
      constexpr TmpT &operator()(���ͳ��� ��������, ���ͳ��� ��������) noexcept
      {
         return this->����ֵ(��������, ��������);
      }

      // ��ȡ�����еڼ��еڼ��е�Ԫ��ֻ�����ã�ע��Խ�硣
      constexpr const TmpT &operator()(���ͳ��� ��������, ���ͳ��� ��������) const noexcept
      {
         return this->����ֵ(��������, ��������);
      }

      // �洢��һά���顣
      TmpT ����[TmpW * TmpH];
   };

   // ģ���Ƶ����Ե�һ����������Ϊ��׼��
   template<typename TmpT, typename... TmpArgs>
   ��׼������(TmpT, TmpArgs...) -> ��׼������<TmpT, sizeof...(TmpArgs) + 1>;

}
