
#include "./Pri/_stringtype.h"

namespace BE {

   // 一种 STmpT 是 TmpChar 字符串类型的概念，包括字符数组、字符指针、迭代器底层为字符指针的可迭代类型、具有 data 获取字符指针成员函数的类型或具有 获取指针 获取字符指针成员函数的类型为字符串类型，默认 TmpChar 为任意字符类型，无视 CV 限定。
   template<typename TmpT, typename TmpChar = X::T::SCur>
   concept 字符串类型 = X::R::CharStringConceptType<TmpT>::value && 相同类型<std::remove_cv_t<typename X::R::CharStringConceptType<TmpT>::CharT>, std::remove_cv_t<TmpChar>>;

   // 一种 STmpT 是字符串类型中字符的类型，如果 STmpT 不是字符串类型则不满足约束。
   template<typename TmpT, 字符类型 TmpChar = typename X::R::CharStringConceptType<TmpT>::CharT>
   using 模板字符串字符 = TmpChar;

   /**
    * \brief >>> 获取任意字符串类型中存储的只读字符串。
    * 
    * \param 获取项： 要获取的对象。
    * \return 只读字符指针。
    * \tparam TmpT： 满足字符串类型要求的类型。
    */
   template<字符串类型 TmpT>
   inline decltype(auto) 获取字符串(TmpT &&获取项) noexcept
   {
      return X::R::CharStringConceptType<TmpT &&>::Get(获取项);
   }

   /**
    * \brief >>> 获取一个字符串类型的字符串长度。
    * 
    * \param 获取项： 要获取的对象。
    * \return 字符串长度。
    * \tparam TmpT： 满足字符串类型要求的类型。
    */
   template<字符串类型 TmpT>
   inline constexpr 类型长度 获取字符串长度(TmpT &&获取项) noexcept
   {
      // 长度类型包含数组。
      if constexpr (长度类型<TmpT>)
      {
         return ::BE::获取长度(std::forward<TmpT>(获取项));
      }

      else
      {
         return ::BE::获取长度(::BE::获取字符串(std::forward<TmpT>(获取项)));
      }
   }

   /**
    * \brief >>> 获取指定字符类型对应的空字符串，如果函数不支持该字符类型则产生静态断言。
    * 
    * \return 字符指针。
    */
   template<字符类型 TmpChar>
   inline constexpr const TmpChar *获取空字符串() noexcept
   {
      return ::BE::X::R::GetEmptyString<TmpChar>();
   }

   /**
    * \brief >>> 函数将字符串转换为当前系统字符编码的字符串类型。
    * 
    * \param 字符串项： 要转换的字符串。
    * \return 转换后的字符串类型。
    */
   template<字符串类型 TmpT>
   inline std::wstring 转为系统标准串(TmpT &&字符串项) noexcept
   {
      return std::filesystem::path(::BE::获取字符串(字符串项)).wstring();
   }

   /**
    * \brief >>> 获取任意字符串类型的哈希值。
    * 
    * \param 获取项： 要获取哈希的字符串对象。
    * \return 哈希值。
    * \see 哈希值计算方法：Windows STL hash 算法。
    */
   template<字符串类型 TmpT>
   inline constexpr 类型哈希 获取字符串哈希(TmpT &&获取项) noexcept
   {
      const 类型字节 *const 字节序 = reinterpret_cast<const 类型字节 *>(::BE::获取字符串(获取项));
      
      类型哈希 返回值 = 14695981039346656037ULL;

      for (类型长度 索引量 = 0; 索引量 < ::BE::获取字符串长度(获取项) * sizeof(模板字符串字符<TmpT>); ++索引量)
      {
         返回值 ^= static_cast<类型哈希>(字节序[索引量]);
         返回值 *= 1099511628211ULL;
      }

      return 返回值;
   }

   /**
    * \brief >>> 获取 UTF-8 字符串中第一个字符所占用的字节长度，如果判断失败获取为空则返回 0。
    * 
    * \param 字符串项： 要获取的 UTF-8 字符串。
    * \return 占用字节长度。
    */
   inline constexpr 类型长度 统一字符长度(const T::UTF8C *字符串项) noexcept
   {
      if (字符串项 == 空指针)
      {
         return 0;
      }

      return static_cast<类型字节>(字符串项[0]) <= 0B01111111 ? 1 :
             static_cast<类型字节>(字符串项[0]) <= 0B11011111 ? 2 :
             static_cast<类型字节>(字符串项[0]) <= 0B11101111 ? 3 :
             static_cast<类型字节>(字符串项[0]) <= 0B11110111 ? 4 :
             static_cast<类型字节>(字符串项[0]) <= 0B11111011 ? 5 :
             static_cast<类型字节>(字符串项[0]) <= 0B11111101 ? 6 : 0;
   }

   /**
    * \brief >>> 获取 UTF-8 字符串中第一个字符的编码，如果判断失败获取为空则返回 0。
    * 
    * \param 字符串项： 要获取的 UTF-8 字符串。
    * \return UTF-8 字符编码。
    */
   inline constexpr T::UTF8I 统一字符编码(const T::UTF8C *字符串项) noexcept
   {
      类型长度 字符长度 = ::BE::统一字符长度(字符串项);
      T::UTF8I 返回值 = 0;

      if (字符长度 == 0)
      {
         return 0;
      }

      // 如果字符长度为 1 则当前字节就是字符的编码，否则需要移除当前字节中的长度信息，获取首字节编码信息。
      返回值 = 字符长度 == 1 ? (static_cast<T::UTF8I>(字符串项[0]))
                             : (static_cast<类型字节>(static_cast<T::UTF8I>(字符串项[0]) << (字符长度 + 1) >> (字符长度 + 1)));

      for (const T::UTF8C *迭代量 = 字符串项 + 1; 迭代量 < 字符串项 + 字符长度; ++迭代量)
      {
         // 左移 6 以留出 6 位空间给下一字节。
         返回值 <<= 6;
         // 获取字节信息，不包括开头的 10 信息。
         返回值 |= static_cast<类型字节>(*迭代量) & 0B00111111;
      }

      return 返回值;

   }

   /**
    * \brief >>> 函数获取指定 UTF-8 字符串中字符的实际数量。
    * 
    * \param 字符串项： 要获取字符数量的 UTF-8 字符串。
    * \return 字符数量。
    */
   inline constexpr 类型长度 统一字符串长度(const T::UTF8C *字符串项) noexcept
   {
      类型长度 统计值 = 0;

      while (字符串项 != 空指针 && 字符串项[0] != 0)
      {
         统计值 += 1;
         字符串项 += ::BE::统一字符长度(字符串项);
      }

      return 统计值;
   }

}
