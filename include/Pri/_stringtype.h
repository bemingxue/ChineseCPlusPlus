
namespace BE::X::R {

   // 获取指定字符类型的空字符串。
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
      else static_assert(false, "Unsupported character type. - 不支持的字符类型");
   }

   // 一种字符指针的概念。
   template<typename TmpT>
   concept CharPointerConcept = 指针类型<TmpT> && 字符类型<std::remove_pointer_t<TmpT>>;

   template<typename TmpT>
   concept CharNotIterator = (!迭代类型<TmpT> || !指针类型<模板迭代类型<TmpT>> || !字符类型<模板解引类型<模板迭代类型<TmpT>>>);

   // 如果 STmpT 不是字符串类型，则 CharT = void 且 value = false。
   template<typename TmpT>
   struct CharStringConceptType : std::false_type
   {
      using CharT = void;
      static const CharT *Get(TmpT) noexcept { return nullptr; }
   };

   template<typename TmpT>
   requires(数组类型<std::remove_reference_t<TmpT>> &&字符类型<std::remove_all_extents_t<std::remove_reference_t<TmpT>>>)
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_all_extents_t<std::remove_reference_t<TmpT>>;
      static const CharT *Get(TmpT t) noexcept { return t; }
   };

   template<typename TmpT>
   requires(指针类型<std::remove_reference_t<TmpT>> &&字符类型<std::remove_pointer_t<std::remove_reference_t<TmpT>>>)
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_pointer_t<std::remove_reference_t<TmpT>>;
      // 始终不会返回空指针，保证空指针安全。
      static const CharT *Get(TmpT t) noexcept { return t == nullptr ? GetEmptyString<CharT>() : t; }
   };

   template<迭代类型 TmpT>
   requires(!数组类型<TmpT> && 指针类型<模板迭代类型<TmpT>> && 字符类型<模板解引类型<模板迭代类型<TmpT>>>)
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_reference_t<模板解引类型<模板迭代类型<TmpT>>>;
      static const CharT *Get(TmpT t) noexcept { return BE::开始(t); }
   };

   template<typename TmpT>
   requires(CharNotIterator<TmpT> && requires(const TmpT X) { { X.data() }noexcept->CharPointerConcept; })
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_pointer_t<decltype(std::declval<TmpT &>().data())>;
      static const CharT *Get(TmpT t) noexcept { return t.data(); }
   };

   template<typename TmpT>
   requires(CharNotIterator<TmpT> && requires(const TmpT X) { { X.获取指针() } noexcept -> CharPointerConcept; } && !requires(const TmpT X) { { X.data() }noexcept->CharPointerConcept; })
   struct CharStringConceptType<TmpT> : std::true_type
   {
      using CharT = std::remove_pointer_t<decltype(std::declval<TmpT &>().获取指针())>;
      static const CharT *Get(TmpT t) noexcept { return t.获取指针(); }
   };

}
