
namespace BE {

   /**
    * \brief >>> 依次比较两个迭代范围中的元素，将每个元素传递给调用项，如果调用项全部返回真并且两个迭代同时到末尾则函数返回真，否则返回假。
    * \brief >>> 对于随机迭代器，函数会先检查迭代范围长度，以优化性能。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 比较开始项： 比较迭代范围开始。
    * \param 比较结束项： 比较迭代范围结束。
    * \param 调用项： 可调用对象，默认使用 == 进行比较。
    * \return 全部相等则返回真，否则返回假。
    * \tparam TmpCompare： 类型逻辑，如果为 false 则函数不判断开始项是否抵达结束项，因此要设置为 false 请确保比较迭代范围小于开始迭代范围。
    * \tparam InputT，InputU： 至少满足单向迭代器的可读迭代器类型。
    * \tparam TmpCall： 可调用类型，接收 InputT 和 InputU 的解引用参数，返回值类型要能转换为逻辑类型。
    */
   template<类型逻辑 TmpCompare = true, 单向迭代类型 InputT, 单向迭代类型 InputU, typename IDRT = 模板解引类型<InputT>, 
            typename IDRU = 模板解引类型<InputU>, 比较调用类型<IDRT, IDRU> TmpCall = 运算相等类<>>
   inline constexpr 类型逻辑 相等(InputT 开始项, InputT 结束项, InputU 比较开始项, InputU 比较结束项, TmpCall &&调用项 = 运算相等类<>())
   noexcept(noexcept(安全调用类型<TmpCall, IDRT, IDRU>))
   {
      // 对于随机迭代器，可以在不影响性能的情况下检查迭代范围长度是否相等。
      if constexpr (随机迭代类型<InputT> && 随机迭代类型<InputU> && TmpCompare)
      {
         if (结束项 - 开始项 != 比较结束项 - 比较开始项)
         {
            return 假;
         }
      }

      while ((!TmpCompare || 开始项 != 结束项) && 比较开始项 != 比较结束项)
      {
         if (调用项(*开始项, *比较开始项) == 假)
         {
            return 假;
         }

         ++开始项;
         ++比较开始项;
      }

      return (!TmpCompare || 开始项 == 结束项) && 比较开始项 == 比较结束项;
   }

   /**
    * \brief >>> 从末尾开始（不包括末尾）依次比较两个迭代范围中的元素，如果调用项全部返回真并且两个迭代同时到开始则函数返回真，否则返回假。
    * 
    * \param 开始项： 迭代范围开始，实际为结束。
    * \param 结束项： 迭代范围结束，实际为开始。
    * \param 比较开始项： 比较迭代范围开始，实际为末尾。
    * \param 比较结束项： 比较迭代范围结束，实际为开始。
    * \param 调用项： 可调用对象，默认使用 == 进行比较。
    * \return 如果全部相等则返回真，否则返回假。
    * \tparam TmpCompare： 类型逻辑，如果为 false 则函数不判断开始项是否抵达开始项，因此要设置为 false 请确保比较迭代范围小于开始迭代范围。
    * \tparam InputT，InputU： 至少满足双向迭代器的可读迭代器类型。
    * \tparam TmpCall： 可调用类型，接收 InputT 和 InputU 的解引用参数，返回值类型要能转换为逻辑类型。
    */
   template<类型逻辑 TmpCompare = true, 双向迭代类型 InputT, 双向迭代类型 InputU, typename IDRT = 模板解引类型<InputT>,
            typename IDRU = 模板解引类型<InputU>, 比较调用类型<IDRT, IDRU> TmpCall = 运算相等类<>>
   inline constexpr 类型逻辑 逆向相等(InputT 开始项, InputT 结束项, InputU 比较开始项, InputU 比较结束项, TmpCall &&调用项 = 运算相等类<>())
   noexcept(noexcept(安全调用类型<TmpCall, IDRT, IDRU>))
   {
      // 对于随机迭代器，可以在不影响性能的情况下检查迭代范围长度是否相等。
      if constexpr (随机迭代类型<InputT> && 随机迭代类型<InputU> && TmpCompare)
      {
         if (结束项 - 开始项 != 比较结束项 - 比较开始项)
         {
            return 假;
         }
      }

      while ((!TmpCompare || 开始项 != 结束项) && 比较开始项 != 比较结束项)
      {
         if (调用项(*--结束项, *--比较结束项) == 假)
         {
            return 假;
         }
      }

      return (!TmpCompare || 开始项 == 结束项) && 比较开始项 == 比较结束项;
   }

   /**
    * \brief >>> 依次比较两个迭代范围中的元素，并将每个元素传递给调用项，不同的是函数比较 (比较结束项，比较开始项] 与 [开始项，结束项)。
    * \brief >>> 对于随机迭代器，函数会先检查迭代范围长度，以优化性能。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 比较开始项： 比较迭代范围开始，实际为末尾。
    * \param 比较结束项： 比较迭代范围结束，实际为开始。
    * \param 调用项： 可调用对象，默认使用 == 进行比较。
    * \return 如果全部相等则返回真，否则返回假。
    * \tparam TmpCompare： 类型逻辑，如果为 false 则函数不判断开始项是否抵达结束项，因此要设置为 false 请确保比较迭代范围小于开始迭代范围。
    * \tparam InputT： 至少满足单向迭代器的可读迭代器类型。
    * \tparam InputU： 至少满足双向迭代器的可读迭代器类型。
    * \tparam TmpCall： 可调用类型，接收 InputT 和 InputU 的解引用参数，返回值类型要能转换为逻辑类型。
    */
   template<类型逻辑 TmpCompare = true, 单向迭代类型 InputT, 双向迭代类型 InputU, typename IDRT = 模板解引类型<InputT>, 
            typename IDRU = 模板解引类型<InputU>, 比较调用类型<IDRT, IDRU> TmpCall = 运算相等类<>>
   inline constexpr 类型逻辑 翻转相等(InputT 开始项, InputT 结束项, InputU 比较开始项, InputU 比较结束项, TmpCall &&调用项 = 运算相等类<>())
   noexcept(noexcept(安全调用类型<TmpCall, IDRT, IDRU>))
   {
      // 对于随机迭代器，可以在不影响性能的情况下检查迭代范围长度是否相等。
      if constexpr (随机迭代类型<InputT> && 随机迭代类型<InputU> && TmpCompare)
      {
         if (结束项 - 开始项 != 比较结束项 - 比较开始项)
         {
            return 假;
         }
      }

      while ((!TmpCompare || 开始项 != 结束项) && 比较结束项 != 比较开始项)
      {
         if (调用项(*开始项, *--比较结束项) == 假)
         {
            return 假;
         }

         ++开始项;
      }

      return (!TmpCompare || 开始项 == 结束项) && 比较开始项 == 比较结束项;
   }

}
