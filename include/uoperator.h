
/////////////////////////////////////////////////////////////////////////////////
// 
//  ���ݳ�Ա�����Զ��ṩ +��-��*��/��%��<<��>>��&��|��^��==��!=��<��<=��>��>=��--��++ ��
//  �����ʵ�֣���Ҫ���������ж��� EGO ��Ա���ͣ����ھ������Ͳ�ǿ�󣩡�
// 
/////////////////////////////////////////////////////////////////////////////



// ����ȫ���������Enable global operators���ĸ�������� EGO ��Ա���ͣ����ڲ������������Ҫ���ƹ��캯����
template<typename TmpT, bool TmpCopy = false>
concept EGO = (TmpCopy || std::is_copy_constructible_v<TmpT>) && requires() { typename std::remove_cvref_t<TmpT>::EGO; };

// ȫ������������� += �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator + (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� += ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp += std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� -= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator - (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� -= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp -= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� *= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator * (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� *= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp *= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� /= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator / (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� /= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp /= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� %= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator % (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� %= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp %= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� <<= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator << (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� <<= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp <<= std::forward<TmpU>(��ֵ��);

   return tmp;
}


// ȫ������������� >>= �͸��ƹ���ʵ�֡�   
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator >> (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� >>= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp >>= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� &= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator & (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� &= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp &= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� |= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator | (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� |= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp |= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� ^= �͸��ƹ���ʵ�֡�
template<EGO TmpT, typename TmpU>
inline constexpr decltype(auto) operator ^ (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� ^= ��ֵ�� }; } )
{
   std::remove_reference_t<TmpT> tmp = std::forward<TmpT>(��ֵ��);

   tmp ^= std::forward<TmpU>(��ֵ��);

   return tmp;
}

// ȫ������������� ����ж� ��Ա���������жϡ�
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator == (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ��.����ж�(��ֵ��) }; })
{
   return ��ֵ��.����ж�(��ֵ��);
}

// ȫ������������� ����ж� ��Ա���������жϣ�Ҫ�� ����ж� �����ķ���ֵ�ܹ����� ! ���㡣
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator != (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { !��ֵ��.����ж�(��ֵ��) }; })
{
   return !��ֵ��.����ж�(��ֵ��);
}

// ȫ������������� �Ƚ��ж� ��Ա���������жϣ�Ҫ�� �Ƚ��ж� �����ķ���ֵ����Ϊ ���ͱȽϡ�
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator < (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ��.�Ƚ��ж�(��ֵ��) } -> BE::��ͬ����<BE::���ͱȽ�>; })
{
   return ��ֵ��.�Ƚ��ж�(��ֵ��) < 0;
}

// ȫ������������� �Ƚ��ж� ��Ա���������жϣ�Ҫ�� �Ƚ��ж� �����ķ���ֵ����Ϊ ���ͱȽϡ�
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator <= (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ��.�Ƚ��ж�(��ֵ��) } -> BE::��ͬ����<BE::���ͱȽ�>; })
{
   return ��ֵ��.�Ƚ��ж�(��ֵ��) <= 0;
}

// ȫ������������� �Ƚ��ж� ��Ա���������жϣ�Ҫ�� �Ƚ��ж� �����ķ���ֵ����Ϊ ���ͱȽϡ�
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator > (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ��.�Ƚ��ж�(��ֵ��) } -> BE::��ͬ����<BE::���ͱȽ�>; })
{
   return ��ֵ��.�Ƚ��ж�(��ֵ��) > 0;
}

// ȫ������������� �Ƚ��ж� ��Ա���������жϣ�Ҫ�� �Ƚ��ж� �����ķ���ֵ����Ϊ ���ͱȽϡ�
template<EGO<true> TmpT, typename TmpU>
inline constexpr decltype(auto) operator >= (TmpT &&��ֵ��, TmpU &&��ֵ��)
noexcept
requires(requires() { { ��ֵ��.�Ƚ��ж�(��ֵ��) } -> BE::��ͬ����<BE::���ͱȽ�>; })
{
   return ��ֵ��.�Ƚ��ж�(��ֵ��) >= 0;
}

// ȫ������������� STmpT += 1 ��ʵ�� ++TmpT��
template<EGO<true> TmpT>
inline constexpr decltype(auto) operator ++ (TmpT &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� += 1 }; })
{
   return ��ֵ�� += 1;
}

// ȫ������������� STmpT += 1 �� ++STmpT ��ʵ�� STmpT++��
template<EGO TmpT>
inline constexpr decltype(auto) operator ++ (TmpT &&��ֵ��, int)
noexcept
requires(requires() { { ��ֵ�� += 1 }; } || requires() { { ++��ֵ�� }; })
{
   std::remove_reference_t<TmpT> tmp(��ֵ��);

   if constexpr (requires() { { ��ֵ�� += 1 }; })
   {
      ��ֵ�� += 1;
   }

   else
   {
      ++��ֵ��;
   }

   return tmp;
}

// ȫ������������� STmpT -= 1 ��ʵ�� --TmpT��
template<EGO<true> TmpT>
inline constexpr decltype(auto) operator -- (TmpT &&��ֵ��)
noexcept
requires(requires() { { ��ֵ�� -= 1 }; })
{
   return ��ֵ�� -= 1;
}

// ȫ������������� STmpT -= 1 ��ʵ�� STmpT--��
template<EGO TmpT>
inline constexpr decltype(auto) operator -- (TmpT &&��ֵ��, int)
noexcept
requires(requires() { { ��ֵ�� -= 1 }; } || requires() { { --��ֵ�� }; })
{
   std::remove_reference_t<TmpT> tmp(��ֵ��);

   if constexpr (requires() { { ��ֵ�� -= 1 }; })
   {
      ��ֵ�� -= 1;
   }

   else
   {
      --��ֵ��;
   }

   return tmp;
}

// ȫ������������� *STmpT.��ȡָ��() ��ʵ�� *TmpT��
template<EGO<true> TmpT>
inline constexpr decltype(auto) operator * (TmpT &&��ֵ��)
noexcept
requires(requires() { { *��ֵ��.��ȡָ��() }; })
{
   return *��ֵ��.��ȡָ��();
}
