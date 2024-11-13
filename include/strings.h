
#include "./Pri/_stringtype.h"

namespace BE {

   // һ�� STmpT �� TmpChar �ַ������͵ĸ�������ַ����顢�ַ�ָ�롢�������ײ�Ϊ�ַ�ָ��Ŀɵ������͡����� data ��ȡ�ַ�ָ���Ա���������ͻ���� ��ȡָ�� ��ȡ�ַ�ָ���Ա����������Ϊ�ַ������ͣ�Ĭ�� TmpChar Ϊ�����ַ����ͣ����� CV �޶���
   template<typename TmpT, typename TmpChar = X::T::SCur>
   concept �ַ������� = X::R::CharStringConceptType<TmpT>::value && ��ͬ����<std::remove_cv_t<typename X::R::CharStringConceptType<TmpT>::CharT>, std::remove_cv_t<TmpChar>>;

   // һ�� STmpT ���ַ����������ַ������ͣ���� STmpT �����ַ�������������Լ����
   template<typename TmpT, �ַ����� TmpChar = typename X::R::CharStringConceptType<TmpT>::CharT>
   using ģ���ַ����ַ� = TmpChar;

   /**
    * \brief >>> ��ȡ�����ַ��������д洢��ֻ���ַ�����
    * 
    * \param ��ȡ� Ҫ��ȡ�Ķ���
    * \return ֻ���ַ�ָ�롣
    * \tparam TmpT�� �����ַ�������Ҫ������͡�
    */
   template<�ַ������� TmpT>
   inline decltype(auto) ��ȡ�ַ���(TmpT &&��ȡ��) noexcept
   {
      return X::R::CharStringConceptType<TmpT &&>::Get(��ȡ��);
   }

   /**
    * \brief >>> ��ȡһ���ַ������͵��ַ������ȡ�
    * 
    * \param ��ȡ� Ҫ��ȡ�Ķ���
    * \return �ַ������ȡ�
    * \tparam TmpT�� �����ַ�������Ҫ������͡�
    */
   template<�ַ������� TmpT>
   inline constexpr ���ͳ��� ��ȡ�ַ�������(TmpT &&��ȡ��) noexcept
   {
      // �������Ͱ������顣
      if constexpr (��������<TmpT>)
      {
         return ::BE::��ȡ����(std::forward<TmpT>(��ȡ��));
      }

      else
      {
         return ::BE::��ȡ����(::BE::��ȡ�ַ���(std::forward<TmpT>(��ȡ��)));
      }
   }

   /**
    * \brief >>> ��ȡָ���ַ����Ͷ�Ӧ�Ŀ��ַ��������������֧�ָ��ַ������������̬���ԡ�
    * 
    * \return �ַ�ָ�롣
    */
   template<�ַ����� TmpChar>
   inline constexpr const TmpChar *��ȡ���ַ���() noexcept
   {
      return ::BE::X::R::GetEmptyString<TmpChar>();
   }

   /**
    * \brief >>> �������ַ���ת��Ϊ��ǰϵͳ�ַ�������ַ������͡�
    * 
    * \param �ַ���� Ҫת�����ַ�����
    * \return ת������ַ������͡�
    */
   template<�ַ������� TmpT>
   inline std::wstring תΪϵͳ��׼��(TmpT &&�ַ�����) noexcept
   {
      return std::filesystem::path(::BE::��ȡ�ַ���(�ַ�����)).wstring();
   }

   /**
    * \brief >>> ��ȡ�����ַ������͵Ĺ�ϣֵ��
    * 
    * \param ��ȡ� Ҫ��ȡ��ϣ���ַ�������
    * \return ��ϣֵ��
    * \see ��ϣֵ���㷽����Windows STL hash �㷨��
    */
   template<�ַ������� TmpT>
   inline constexpr ���͹�ϣ ��ȡ�ַ�����ϣ(TmpT &&��ȡ��) noexcept
   {
      const �����ֽ� *const �ֽ��� = reinterpret_cast<const �����ֽ� *>(::BE::��ȡ�ַ���(��ȡ��));
      
      ���͹�ϣ ����ֵ = 14695981039346656037ULL;

      for (���ͳ��� ������ = 0; ������ < ::BE::��ȡ�ַ�������(��ȡ��) * sizeof(ģ���ַ����ַ�<TmpT>); ++������)
      {
         ����ֵ ^= static_cast<���͹�ϣ>(�ֽ���[������]);
         ����ֵ *= 1099511628211ULL;
      }

      return ����ֵ;
   }

   /**
    * \brief >>> ��ȡ UTF-8 �ַ����е�һ���ַ���ռ�õ��ֽڳ��ȣ�����ж�ʧ�ܻ�ȡΪ���򷵻� 0��
    * 
    * \param �ַ���� Ҫ��ȡ�� UTF-8 �ַ�����
    * \return ռ���ֽڳ��ȡ�
    */
   inline constexpr ���ͳ��� ͳһ�ַ�����(const T::UTF8C *�ַ�����) noexcept
   {
      if (�ַ����� == ��ָ��)
      {
         return 0;
      }

      return static_cast<�����ֽ�>(�ַ�����[0]) <= 0B01111111 ? 1 :
             static_cast<�����ֽ�>(�ַ�����[0]) <= 0B11011111 ? 2 :
             static_cast<�����ֽ�>(�ַ�����[0]) <= 0B11101111 ? 3 :
             static_cast<�����ֽ�>(�ַ�����[0]) <= 0B11110111 ? 4 :
             static_cast<�����ֽ�>(�ַ�����[0]) <= 0B11111011 ? 5 :
             static_cast<�����ֽ�>(�ַ�����[0]) <= 0B11111101 ? 6 : 0;
   }

   /**
    * \brief >>> ��ȡ UTF-8 �ַ����е�һ���ַ��ı��룬����ж�ʧ�ܻ�ȡΪ���򷵻� 0��
    * 
    * \param �ַ���� Ҫ��ȡ�� UTF-8 �ַ�����
    * \return UTF-8 �ַ����롣
    */
   inline constexpr T::UTF8I ͳһ�ַ�����(const T::UTF8C *�ַ�����) noexcept
   {
      ���ͳ��� �ַ����� = ::BE::ͳһ�ַ�����(�ַ�����);
      T::UTF8I ����ֵ = 0;

      if (�ַ����� == 0)
      {
         return 0;
      }

      // ����ַ�����Ϊ 1 ��ǰ�ֽھ����ַ��ı��룬������Ҫ�Ƴ���ǰ�ֽ��еĳ�����Ϣ����ȡ���ֽڱ�����Ϣ��
      ����ֵ = �ַ����� == 1 ? (static_cast<T::UTF8I>(�ַ�����[0]))
                             : (static_cast<�����ֽ�>(static_cast<T::UTF8I>(�ַ�����[0]) << (�ַ����� + 1) >> (�ַ����� + 1)));

      for (const T::UTF8C *������ = �ַ����� + 1; ������ < �ַ����� + �ַ�����; ++������)
      {
         // ���� 6 ������ 6 λ�ռ����һ�ֽڡ�
         ����ֵ <<= 6;
         // ��ȡ�ֽ���Ϣ����������ͷ�� 10 ��Ϣ��
         ����ֵ |= static_cast<�����ֽ�>(*������) & 0B00111111;
      }

      return ����ֵ;

   }

   /**
    * \brief >>> ������ȡָ�� UTF-8 �ַ������ַ���ʵ��������
    * 
    * \param �ַ���� Ҫ��ȡ�ַ������� UTF-8 �ַ�����
    * \return �ַ�������
    */
   inline constexpr ���ͳ��� ͳһ�ַ�������(const T::UTF8C *�ַ�����) noexcept
   {
      ���ͳ��� ͳ��ֵ = 0;

      while (�ַ����� != ��ָ�� && �ַ�����[0] != 0)
      {
         ͳ��ֵ += 1;
         �ַ����� += ::BE::ͳһ�ַ�����(�ַ�����);
      }

      return ͳ��ֵ;
   }

}
