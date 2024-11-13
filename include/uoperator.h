
/////////////////////////////////////////////////////////////////////////////////
// 
//  依据成员函数自动提供 +、-、*、/、%、<<、>>、&、|、^、==、!=、<、<=、>、>=、--、++ 运
//  算符的实现，需要在类类型中定义 EGO 成员类型（对于具体类型不强求）。
// 
/////////////////////////////////////////////////////////////////////////////



// 启用全局运算符（Enable global operators）的概念，即具有 EGO 成员类型，对于部分运算符还需要复制构造函数。
template<typename TmpT, bool TmpCopy = false>
concept EGO = (TmpCopy || std::is_copy_constructible_v<TmpT>) && requires() { typename std::remove_cvref_t<TmpT>::EGO; };

// 全局运算符，调用 += 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator + (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 += 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp += std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 -= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator - (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 -= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp -= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 *= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator * (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 *= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp *= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 /= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator / (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 /= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp /= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 %= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator % (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 %= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp %= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 <<= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator << (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 <<= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp <<= std::forward<TmpU>(右值项);

   return tmp;
}


// 全局运算符，调用 >>= 和复制构造实现。   
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator >> (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 >>= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp >>= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 &= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator & (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 &= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp &= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 |= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator | (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 |= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp |= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 ^= 和复制构造实现。
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator ^ (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项 ^= 右值项 }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(左值项);

   tmp ^= std::forward<TmpU>(右值项);

   return tmp;
}

// 全局运算符，调用 相等判断 成员函数进行判断。
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator == (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项.相等判断(右值项) }; })
{
   return 左值项.相等判断(右值项);
}

// 全局运算符，调用 相等判断 成员函数进行判断，要求 相等判断 函数的返回值能够进行 ! 运算。
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator != (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { !左值项.相等判断(右值项) }; })
{
   return !左值项.相等判断(右值项);
}

// 全局运算符，调用 比较判断 成员函数进行判断，要求 比较判断 函数的返回值类型为 类型比较。
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator < (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项.比较判断(右值项) } -> BE::相同类型<BE::类型比较>; })
{
   return 左值项.比较判断(右值项) < 0;
}

// 全局运算符，调用 比较判断 成员函数进行判断，要求 比较判断 函数的返回值类型为 类型比较。
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator <= (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项.比较判断(右值项) } -> BE::相同类型<BE::类型比较>; })
{
   return 左值项.比较判断(右值项) <= 0;
}

// 全局运算符，调用 比较判断 成员函数进行判断，要求 比较判断 函数的返回值类型为 类型比较。
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator > (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项.比较判断(右值项) } -> BE::相同类型<BE::类型比较>; })
{
   return 左值项.比较判断(右值项) > 0;
}

// 全局运算符，调用 比较判断 成员函数进行判断，要求 比较判断 函数的返回值类型为 类型比较。
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator >= (TmpT &&左值项, TmpU &&右值项)
noexcept
requires(requires() { { 左值项.比较判断(右值项) } -> BE::相同类型<BE::类型比较>; })
{
   return 左值项.比较判断(右值项) >= 0;
}

// 全局运算符，调用 STmpT += 1 来实现 ++TmpT。
template<EGO<true> TmpT>
inline constexpr decltype(auto) operator ++ (TmpT &&左值项)
noexcept
requires(requires() { { 左值项 += 1 }; })
{
   return 左值项 += 1;
}

// 全局运算符，调用 STmpT += 1 或 ++STmpT 来实现 STmpT++。
template<EGO TmpT>
inline constexpr decltype(auto) operator ++ (TmpT &&左值项, int)
noexcept
requires(requires() { { 左值项 += 1 }; } || requires() { { ++左值项 }; })
{
   std::remove_reference_t<TmpT> tmp(左值项);

   if constexpr (requires() { { 左值项 += 1 }; })
   {
      左值项 += 1;
   }

   else
   {
      ++左值项;
   }

   return tmp;
}

// 全局运算符，调用 STmpT -= 1 来实现 --TmpT。
template<EGO<true> TmpT>
inline constexpr decltype(auto) operator -- (TmpT &&左值项)
noexcept
requires(requires() { { 左值项 -= 1 }; })
{
   return 左值项 -= 1;
}

// 全局运算符，调用 STmpT -= 1 来实现 STmpT--。
template<EGO TmpT>
inline constexpr decltype(auto) operator -- (TmpT &&左值项, int)
noexcept
requires(requires() { { 左值项 -= 1 }; } || requires() { { --左值项 }; })
{
   std::remove_reference_t<TmpT> tmp(左值项);

   if constexpr (requires() { { 左值项 -= 1 }; })
   {
      左值项 -= 1;
   }

   else
   {
      --左值项;
   }

   return tmp;
}

// 全局运算符，调用 *STmpT.获取指针() 来实现 *TmpT。
template<EGO<true> TmpT>
inline constexpr decltype(auto) operator * (TmpT &&左值项)
noexcept
requires(requires() { { *左值项.获取指针() }; })
{
   return *左值项.获取指针();
}
