
// �������μ򻯺ꡣ
#define ����(MacorObj)  ::BE::��ʼ(MacorObj), ::BE::����(MacorObj)

namespace BE {

   // һ���������������͵�ö�١�
   enum class ����ö�� {
      ����, ˫��, ���
   };

   // һ���ܹ�ʹ�ý�������������������͡�
   template<typename TmpT>
   concept �������� = requires(TmpT X) {

      typename ģ���������<TmpT>;
      
      { *X } -> ��ͬ����<ģ���������<TmpT>>;
   
   };

   // һ���ܹ�ʹ��ǰ����������������͡�
   template<typename TmpT>
   concept ����������� = ��������<TmpT> && �������<TmpT> && ���Ƹ�ֵ����<TmpT> && ���ƹ�������<TmpT> && requires(TmpT X) {
   
      { ++X } -> ��ͬ����<TmpT &>;
   
   };

   // һ���ܹ�ʹ��ǰ���Լ�����������͡�
   template<typename TmpT>
   concept ˫��������� = �����������<TmpT> && requires(TmpT X) {

      { --X } -> ��ͬ����<TmpT &>;

   };

   // һ���ܹ�ʹ�� +��-��+=��-= ����������ʹ�� STmpT - STmpT ��ȡ��࣬ʹ�� STmpT[0] ����Ԫ�أ����ܽ��бȽϵ����͸�� 
   template<typename TmpT>
   concept ����������� = ˫���������<TmpT> && �Ƚ�����<TmpT> && requires(TmpT X) {

      { X + 0 } -> ת������<TmpT>;
      { X - 0 } -> ת������<TmpT>;
      { X - X } -> ת������<T::IPTR>;

      { X += 0 } -> ��ͬ����<TmpT &>;
      { X -= 0 } -> ��ͬ����<TmpT &>;

      { X[0] } -> ��ͬ����<ģ���������<TmpT>>;

   };

   // һ���ܹ���ֵ TmpU �Լ� TmpArgs �б����������͵����ͣ�ʹ�� TmpEnum ȷ�����������͡�
   template<typename TmpT, ����ö�� TmpEnum, typename TmpU, typename... TmpArgs>
   concept ��д�������� = ��ֵ����<ģ���������<TmpT>, TmpU, TmpArgs...> && (TmpEnum == ����ö��::���� ? �����������<TmpT> : TmpEnum == ����ö��::˫�� ? ˫���������<TmpT> : �����������<TmpT>);

   // �߱� begin �� end ��Ա�������ҷ���ֵ�����������㵥���������������͡�
   template<typename TmpT>
   concept ���������� = requires(TmpT X) {

      { X.begin() } noexcept -> �����������;
      { X.end()   } noexcept -> �����������;

   };

   /**
    * \brief >>> ��ȡ����Ŀ�ʼ��������
    * 
    * \param ����� Ҫ��ȡ�����顣
    * \return ����Ŀ�ʼ��������
    */
   template<typename TmpT, ���ͳ��� TmpSize>
   inline constexpr TmpT *��ʼ(TmpT(&������)[TmpSize]) noexcept
   {
      return ������ + 0;
   }

   /**
    * \brief >>> ��ȡ����Ľ����������������ַ����飬���������һ��Ԫ�ر�ʾ������
    * 
    * \param ����� Ҫ��ȡ�����顣
    * \return ����Ľ�����������
    */
   template<typename TmpT, ���ͳ��� TmpSize>
   inline constexpr TmpT *����(TmpT(&������)[TmpSize]) noexcept
   {
      if constexpr (�ַ�����<TmpT>)
      {
         return TmpSize == 0 ? ������ + TmpSize : ������ + TmpSize - 1;
      }

      else
      {
         return ������ + TmpSize;
      }
   }

   /**
    * \brief >>> ��ȡ������������������ begin ��������
    * 
    * \param ����� Ҫ��ȡ�Ķ���
    * \return �� begin ��Ա�������صĵ�������
    */
   inline constexpr decltype(auto) ��ʼ(���������� auto &&������) noexcept
   {
      return ������.begin();
   }

   /**
    * \brief >>> ��ȡ������������������ end ��������
    * 
    * \param ����� Ҫ��ȡ�Ķ���
    * \return �� end ��Ա�������صĵ�������
    */
   inline constexpr decltype(auto) ����(���������� auto &&������) noexcept
   {
      return ������.end();
   }

   // һ���ܹ�ͨ��ȫ�ֵ� BE::��ʼ() �� BE::����() ������ȡ�����������͡�
   template<typename TmpT>
   concept �������� = requires(TmpT X) {
      { BE::��ʼ(X) };
      { BE::����(X) };
   };

   /**
    * \brief >>> ��ȡ������Χ�ĳ��ȣ����ڷ��������������ʹ��ѭ�����м����������ʼ���޷��ִ���������ѭ����
    * 
    * \param ��ʼ� ������Χ��ʼ��
    * \param ����� ������Χ������
    * \return ������Χ���ȡ�
    * \tparam OutputT�� �������㵥�����������Ŀɶ����������͡�
    */
   template<����������� OutputT>
   inline constexpr ���ͳ��� ��ȡ����(OutputT &&��ʼ��, OutputT &&������) noexcept
   {
      if constexpr (�����������<OutputT>)
      {
         return static_cast<���ͳ���>(������ - ��ʼ��);
      }

      else
      {
         // �����ʼ���޷��ִ���������ѭ����
         for (���ͳ��� ������ = 0; ; ++��ʼ��, ++������)
         {
            if (��ʼ�� == ������)
            {
               return ������;
            }
         }

         assert(false);
      }
   }

   /**
    * \brief >>> ����ӵ�е�����ȴû�л�ȡ������س�Ա���������ͣ�ʹ�õ�������ȡ���ȡ�
    * 
    * \param ��ȡ� Ҫ��ȡ�Ķ���
    * \return ���ȡ�
    * \tparam TmpT�� �������������������������͡�
    */
   template<���������� TmpT>
   inline constexpr ���ͳ��� ��ȡ����(TmpT &&��ȡ��) noexcept
   requires(!requires() { { ��ȡ��.size() } noexcept -> ת������<���ͳ���>; } &&
            !requires() { { ��ȡ��.length() } noexcept -> ת������<���ͳ���>; } &&
            !requires() { { ��ȡ��.��ȡ����() } noexcept -> ת������<���ͳ���>; })
   {
      return ::BE::��ȡ����(::BE::��ʼ(��ȡ��), ::BE::����(��ȡ��));
   }

   // һ�� STmpT ���͵ĵ��������ͣ�Ҫ�� STmpT Ӧ���ǿɵ��������ͣ�������������� error-type��
   template<typename TmpT>
   using ģ��������� = decltype(BE::��ʼ(std::declval<TmpT &>()));

}
