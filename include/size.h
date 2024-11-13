
namespace BE {

   // ���� STmpT �Ķ��볤�ȡ�
   template<typename TmpT>
   inline constexpr ���ͳ��� ���볤�� = std::alignment_of_v<TmpT>;

   // ���� STmpT ������ά�ȣ����ڷ��������ͣ���ʾֵ 0��
   template<typename TmpT>
   inline constexpr ���ͳ��� ����ά�� = std::rank_v<TmpT>;

   /**
    * \brief >>> ��ȡ����ĳ��ȣ����������㡣
    * 
    * \return ���鳤�ȡ�
    * \tparam TmpT�� ����������ͣ��������ַ����͡�
    */
   template<typename TmpT, ���ͳ��� TmpSize>
   inline constexpr ���ͳ��� ��ȡ����(TmpT(&)[TmpSize]) 
   noexcept 
   requires(!�ַ�����<TmpT>)
   {
      return TmpSize;
   }

   /**
    * \brief >>> ����ַ�������ػ�����ȡ�ַ����鳤�ȵ������������������������㡣
    * 
    * \return �ַ����鳤�ȡ�
    */
   template<�ַ����� TmpT, ���ͳ��� TmpSize>
   inline constexpr ���ͳ��� ��ȡ����(TmpT(&)[TmpSize])
   noexcept
   {
      return TmpSize > 0 ? TmpSize - 1 : 0;
   }

   /**
    * \brief >>> ��ȡ�ַ���ָ���е��ַ�����
    * 
    * \param ����� Ҫ��ȡ���ַ�ָ�����
    * \return �ַ��������Ϊ��ָ���򷵻� 0��
    * \tparam TmpT�� �����ַ�ָ�����͡�
    */
   template<ָ������ TmpT>
   inline constexpr ���ͳ��� ��ȡ����(TmpT ������)
   noexcept
   requires(!��������<TmpT> && �ַ�����<ģ���������<TmpT>>)
   {
      return ������ == ��ָ�� ? 0 : std::basic_string_view<std::remove_pointer_t<TmpT>>(������).length();
   }

   /**
    * \brief >>> ���Ե��ö���� size��length����ȡ���� ��ȫ������ȡ������Ϣ��
    * 
    * \param ����� Ҫ��ȡ�Ķ���Ҫ���������Ͳ��Ҿ��а�ȫ�� size��length����ȡ���� ���������е�һ�������ҷ���ֵ���Ϳ���ת��Ϊ���ͳ��ȡ�
    * \return ��ȡ���ĳ��ȡ�
    */
   inline constexpr ���ͳ��� ��ȡ����(������ auto &&������) 
   noexcept
   requires(requires() { { ������.size() } noexcept -> ת������<���ͳ���>; } ||
            requires() { { ������.length() } noexcept -> ת������<���ͳ���>; } ||
            requires() { { ������.��ȡ����() } noexcept -> ת������<���ͳ���>; })
   {
      if constexpr (requires() { { ������.size() } noexcept -> ת������<���ͳ���>; })
      {
         return ������.size();
      }

      else if constexpr (requires() { { ������.length() } noexcept -> ת������<���ͳ���>; })
      {
         return ������.length();
      }

      else
      {
         return ������.��ȡ����();
      }
   }

   // ���Ա� BE::��ȡ���� ��ȡ������Ϣ�����͸��
   template<typename TmpT>
   concept �������� = requires(TmpT X) { BE::��ȡ����(X); };

}
