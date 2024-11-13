
namespace BE::X::R {

   // ��ȡָ���ַ����͵Ŀ��ַ�����
   template<typename TmpChar>
   inline constexpr const TmpChar *GetEmptyString() noexcept
   {
      if constexpr (std::is_same_v<std::remove_cvref_t<TmpChar>, char>) return "";
      else if constexpr (std::is_same_v<std::remove_cvref_t<TmpChar>, wchar_t>) return L"";
      else if constexpr (std::is_same_v<std::remove_cvref_t<TmpChar>, char16_t>) return u"";
      else if constexpr (std::is_same_v<std::remove_cvref_t<TmpChar>, char32_t>) return U"";
      else if constexpr (std::is_same_v<std::remove_cvref_t<TmpChar>, char8_t>) return u8"";
      else if constexpr (std::is_same_v<std::remove_cvref_t<TmpChar>, signed char>) return "";
      else if constexpr (std::is_same_v<std::remove_cvref_t<TmpChar>, unsigned char>) return "";
      else static_assert(false, "Unsupported character type. - ��֧�ֵ��ַ�����");
   }

   // һ���ַ�ָ��ĸ��
   template<typename TmpT>
   concept CharPointerConcept = ָ������<TmpT> && �ַ�����<std::remove_pointer_t<TmpT>>;

   template<typename TmpT>
   concept CharNotIterator = (!��������<TmpT> || !ָ������<ģ���������<TmpT>> || !�ַ�����<ģ���������<ģ���������<TmpT>>>);

   // ��� STmpT �����ַ������ͣ��� CharT = void �� value = false��
   template<typename TmpT>
   struct CharStringConceptType : std::false_type
   {
      using CharT = void;
      static const CharT *Get(TmpT) noexcept { return nullptr; }
   };

   template<typename TmpT>
   requires(��������<std::remove_reference_t<TmpT>> &&�ַ�����<std::remove_all_extents_t<std::remove_reference_t<TmpT>>>)
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_all_extents_t<std::remove_reference_t<TmpT>>;
      static const CharT *Get(TmpT t) noexcept { return t; }
   };

   template<typename TmpT>
   requires(ָ������<std::remove_reference_t<TmpT>> &&�ַ�����<std::remove_pointer_t<std::remove_reference_t<TmpT>>>)
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_pointer_t<std::remove_reference_t<TmpT>>;
      // ʼ�ղ��᷵�ؿ�ָ�룬��֤��ָ�밲ȫ��
      static const CharT *Get(TmpT t) noexcept { return t == nullptr ? GetEmptyString<CharT>() : t; }
   };

   template<�������� TmpT>
   requires(!��������<TmpT> && ָ������<ģ���������<TmpT>> && �ַ�����<ģ���������<ģ���������<TmpT>>>)
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_reference_t<ģ���������<ģ���������<TmpT>>>;
      static const CharT *Get(TmpT t) noexcept { return BE::��ʼ(t); }
   };

   template<typename TmpT>
   requires(CharNotIterator<TmpT> && requires(const TmpT X) { { X.data() }noexcept->CharPointerConcept; })
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_pointer_t<decltype(std::declval<TmpT &>().data())>;
      static const CharT *Get(TmpT t) noexcept { return t.data(); }
   };

   template<typename TmpT>
   requires(CharNotIterator<TmpT> && requires(const TmpT X) { { X.��ȡָ��() } noexcept -> CharPointerConcept; } && !requires(const TmpT X) { { X.data() }noexcept->CharPointerConcept; })
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_pointer_t<decltype(std::declval<TmpT &>().��ȡָ��())>;
      static const CharT *Get(TmpT t) noexcept { return t.��ȡָ��(); }
   };

}
