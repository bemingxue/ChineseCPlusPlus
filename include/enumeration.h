
namespace BE {

   /**
    * \brief >>> �ÿɵ������������ڵ�����ͬʱ��ȡ��ǰ������������Ҳ�������Զ��������ĳ�ʼֵ��һ�����ڷ�Χ for ѭ���н��а󶨣���ʹ�� && ��ʽ�����ҵ�һ��Ϊ������
    * \tparam TmpT�� ���е������ĵ������ͣ���������ֵ����ֵ���͡�
    * \tparam TmpIndex�� �������ͣ����ڱ�ʾ���������͡�
    * \tparam TmpCount�� �����߼������ڱ�ʾ end �Ƿ��ȡ������Χ���ȣ�Ĭ�ϲ���ȡ�Ա��ⲻ��Ҫ�Ŀ�����
    */
   template<�������� TmpT, �������� TmpIndex = ���ͳ���, �����߼� TmpCount = ��>
   struct �оٵ�����
   {
      // �������͵ĵ�������
      using ������ = ģ���������<TmpT>;
      // �������Ľ��������͡�
      using ֵ��   = ģ���������<������>;

      // ����ṹ����ֵ�Ľṹ��
      template<typename TmpU>
      struct ����ֵ��
      {
         TmpIndex ����ֵ;
         TmpU     ֵ;

         // ������и�ֵ������ֻҪ��������������Ļ���
         template<typename TmpV>
         constexpr ����ֵ�� &operator = (TmpV &&��ֵ��) 
         noexcept(noexcept(��ȫ��ֵ����<TmpU, TmpV>))
         requires(��ֵ����<TmpU, TmpV>)
         {
            this->ֵ = std::forward<TmpV>(��ֵ��);
            return *this;
         }

         // ��ʽת��Ϊ�����õ����͡�
         constexpr operator TmpU() noexcept
         {
            return this->ֵ;
         }
      };

      // ������������ͣ�����֧�� -> �����������һ���ڷ�Χ for ѭ����ʹ�ã����ֻ�ṩǰ׺ ++ �� -- �������
      struct �������
      {
         �������() noexcept : ��������(0), ���е�����(������()) 
         {
         
         }

         �������(TmpIndex ��ʼ��, ������ ������) noexcept : ��������(��ʼ��), ���е�����(������)
         {

         }

         decltype(auto) operator * () noexcept
         {
            return ����ֵ��<ֵ��> { ��������, *���е����� };
         }

         ������� &operator ++ () noexcept requires(requires(������ X) { ++X; })
         {
            return ++��������, ++���е�����, *this;
         }

         ������� &operator -- () noexcept requires(requires(������ X) { --X; })
         {
            return --��������, --���е�����, *this;
         }

         �����߼� operator == (const ������� &�Ƚ���) const noexcept
         {
            return ���е����� == �Ƚ���.���е�����;
         }

         protected:
         TmpIndex ��������;
         ������   ���е�����;
      };

      // ��ȡ��ʼ��������
      constexpr ������� begin() noexcept
      {
         return �������(������ʼ, ::BE::��ʼ(���е���));
      }

      // ��ȡ������������
      constexpr ������� end() noexcept
      {
         if constexpr (TmpCount)
         {
            return �������(::BE::��ȡ����(���е���), ::BE::����(���е���));
         }

         else
         {
            return �������(������ʼ, ::BE::����(���е���));
         }
      }

      // Ĭ�Ϲ��캯�����ṩҪ�����Ķ������ʼ��������ʼ����Ĭ��Ϊ 0��
      constexpr �оٵ�����(TmpT ������, TmpIndex ��ʼ�� = 0) noexcept : ���е���(������), ������ʼ(��ʼ��)
      {

      }

      protected:

      TmpT     ���е���;
      TmpIndex ������ʼ = 0;
   };

   // ģ���Ƶ�������ʹ�� TmpIndex �Ƶ��������͡�
   template<�������� TmpT, �������� TmpIndex>
   �оٵ�����(TmpT &&, TmpIndex) -> �оٵ�����<TmpT, TmpIndex>;

   template<�������� TmpT>
   �оٵ�����(TmpT &&) -> �оٵ�����<TmpT>;

}
