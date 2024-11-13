
// 迭代传参简化宏。
#define 迭代(MacorObj)  ::BE::开始(MacorObj), ::BE::结束(MacorObj)

namespace BE {

   // 一种描述迭代器类型的枚举。
   enum class 迭代枚举 {
      单向, 双向, 随机
   };

   // 一种能够使用解引用运算符解引的类型。
   template<typename TmpT>
   concept 解引类型 = requires(TmpT X) {

      typename 模板解引类型<TmpT>;
      
      { *X } -> 相同类型<模板解引类型<TmpT>>;
   
   };

   // 一种能够使用前置自增运算符的类型。
   template<typename TmpT>
   concept 单向迭代类型 = 解引类型<TmpT> && 相等类型<TmpT> && 复制赋值类型<TmpT> && 复制构造类型<TmpT> && requires(TmpT X) {
   
      { ++X } -> 相同类型<TmpT &>;
   
   };

   // 一种能够使用前置自减运算符的类型。
   template<typename TmpT>
   concept 双向迭代类型 = 单向迭代类型<TmpT> && requires(TmpT X) {

      { --X } -> 相同类型<TmpT &>;

   };

   // 一种能够使用 +、-、+=、-= 整数并且能使用 STmpT - STmpT 获取间距，使用 STmpT[0] 访问元素，还能进行比较的类型概念。 
   template<typename TmpT>
   concept 随机迭代类型 = 双向迭代类型<TmpT> && 比较类型<TmpT> && requires(TmpT X) {

      { X + 0 } -> 转换类型<TmpT>;
      { X - 0 } -> 转换类型<TmpT>;
      { X - X } -> 转换类型<T::IPTR>;

      { X += 0 } -> 相同类型<TmpT &>;
      { X -= 0 } -> 相同类型<TmpT &>;

      { X[0] } -> 相同类型<模板解引类型<TmpT>>;

   };

   // 一种能够赋值 TmpU 以及 TmpArgs 列表中所有类型的类型，使用 TmpEnum 确定迭代器类型。
   template<typename TmpT, 迭代枚举 TmpEnum, typename TmpU, typename... TmpArgs>
   concept 可写迭代类型 = 赋值类型<模板解引类型<TmpT>, TmpU, TmpArgs...> && (TmpEnum == 迭代枚举::单向 ? 单向迭代类型<TmpT> : TmpEnum == 迭代枚举::双向 ? 双向迭代类型<TmpT> : 随机迭代类型<TmpT>);

   // 具备 begin 和 end 成员函数并且返回值类型至少满足单向迭代器需求的类型。
   template<typename TmpT>
   concept 迭代类类型 = requires(TmpT X) {

      { X.begin() } noexcept -> 单向迭代类型;
      { X.end()   } noexcept -> 单向迭代类型;

   };

   /**
    * \brief >>> 获取数组的开始迭代器。
    * 
    * \param 数组项： 要获取的数组。
    * \return 数组的开始迭代器。
    */
   template<typename TmpT, 类型长度 TmpSize>
   inline constexpr TmpT *开始(TmpT(&数组项)[TmpSize]) noexcept
   {
      return 数组项 + 0;
   }

   /**
    * \brief >>> 获取数组的结束迭代器，对于字符数组，返回其最后一个元素表示结束。
    * 
    * \param 数组项： 要获取的数组。
    * \return 数组的结束迭代器。
    */
   template<typename TmpT, 类型长度 TmpSize>
   inline constexpr TmpT *结束(TmpT(&数组项)[TmpSize]) noexcept
   {
      if constexpr (字符类型<TmpT>)
      {
         return TmpSize == 0 ? 数组项 + TmpSize : 数组项 + TmpSize - 1;
      }

      else
      {
         return 数组项 + TmpSize;
      }
   }

   /**
    * \brief >>> 获取满足迭代类类型需求的 begin 迭代器。
    * 
    * \param 迭代项： 要获取的对象。
    * \return 由 begin 成员函数返回的迭代器。
    */
   inline constexpr decltype(auto) 开始(迭代类类型 auto &&迭代项) noexcept
   {
      return 迭代项.begin();
   }

   /**
    * \brief >>> 获取满足迭代类类型需求的 end 迭代器。
    * 
    * \param 迭代项： 要获取的对象。
    * \return 由 end 成员函数返回的迭代器。
    */
   inline constexpr decltype(auto) 结束(迭代类类型 auto &&迭代项) noexcept
   {
      return 迭代项.end();
   }

   // 一种能够通过全局的 BE::开始() 和 BE::结束() 函数获取迭代器的类型。
   template<typename TmpT>
   concept 迭代类型 = requires(TmpT X) {
      { BE::开始(X) };
      { BE::结束(X) };
   };

   /**
    * \brief >>> 获取迭代范围的长度，对于非随机迭代器，将使用循环进行计数，如果开始项无符抵达结束项，则将死循环。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \return 迭代范围长度。
    * \tparam OutputT： 至少满足单向迭代器需求的可读迭代器类型。
    */
   template<单向迭代类型 OutputT>
   inline constexpr 类型长度 获取长度(OutputT &&开始项, OutputT &&结束项) noexcept
   {
      if constexpr (随机迭代类型<OutputT>)
      {
         return static_cast<类型长度>(结束项 - 开始项);
      }

      else
      {
         // 如果开始项无符抵达结束项，则将死循环。
         for (类型长度 计数量 = 0; ; ++开始项, ++计数量)
         {
            if (开始项 == 结束项)
            {
               return 计数量;
            }
         }

         assert(false);
      }
   }

   /**
    * \brief >>> 对于拥有迭代器却没有获取长度相关成员函数的类型，使用迭代器获取长度。
    * 
    * \param 获取项： 要获取的对象。
    * \return 长度。
    * \tparam TmpT： 至少满足迭代类类型需求的类型。
    */
   template<迭代类类型 TmpT>
   inline constexpr 类型长度 获取长度(TmpT &&获取项) noexcept
   requires(!requires() { { 获取项.size() } noexcept -> 转换类型<类型长度>; } &&
            !requires() { { 获取项.length() } noexcept -> 转换类型<类型长度>; } &&
            !requires() { { 获取项.获取长度() } noexcept -> 转换类型<类型长度>; })
   {
      return ::BE::获取长度(::BE::开始(获取项), ::BE::结束(获取项));
   }

   // 一种 STmpT 类型的迭代器类型，要求 STmpT 应当是可迭代器类型，如果不算则类型 error-type。
   template<typename TmpT>
   using 模板迭代类型 = decltype(BE::开始(std::declval<TmpT &>()));

}
