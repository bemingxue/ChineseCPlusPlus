
namespace BE {

   /**
    * \brief >>> 用指定值填充迭代范围中的所有元素。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 填充项： 要填充的值。
    * \return 
    * \tparam TmpU： 可以赋值给迭代范围元素的类型。
    * \tparam OutputT： 至少满足单向迭代器的可写迭代器类型。
    */
   template<typename TmpU, 可写迭代类型<迭代枚举::单向, TmpU> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 值填充(OutputT 开始项, OutputT 结束项, TmpU &&填充项)
   noexcept(noexcept(安全赋值类型<ODRT, TmpU>))
   {
      for (; 开始项 != 结束项; ++开始项)
      {
         (*开始项) = std::forward<TmpU>(填充项);
      }
   }

   /**
    * \brief >>> 用指定值填充迭代范围中的所有元素。
    * 
    * \param 迭代项： 可迭代对象，要求迭代器至少满足单向可写迭代器。
    * \param 填充值： 要填充的值。
    * \return 
    * \tparam OutputT： 可迭代类型。
    * \tparam TmpU： 可以赋值给迭代范围元素的类型。
    */
   template<迭代类型 OutputT, typename TmpU>
   inline constexpr 类型空的 值填充(OutputT &&迭代项, TmpU &&填充值)
   noexcept(noexcept(BE::值填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpU>(填充值))))
   requires(requires(){BE::值填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpU>(填充值)); })
   {
      BE::值填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpU>(填充值));
   }

   /**
    * \brief >>> 用指定可调用对象的返回值来填充迭代范围内的元素。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 填充项： 可调用对象。
    * \return 
    * \tparam TmpCall： 可调用类型，无参，要求返回值类型能够赋值给迭代范围元素类型。
    * \tparam OutputT： 至少满足单向迭代器的可写迭代器类型。
    */
   template<调用类型<> TmpCall, typename TmpRet = 模板返回类型<TmpCall>, 
            可写迭代类型<迭代枚举::单向, TmpRet> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 调用填充(OutputT 开始项, OutputT 结束项, TmpCall &&填充项)
   noexcept(noexcept(安全赋值类型<ODRT, TmpRet>))
   {
      for (; 开始项 != 结束项; ++开始项)
      {
         (*开始项) = 填充项();
      }
   }

   /**
    * \brief >>> 用指定可调用对象的返回值来填充迭代范围内的元素。
    * 
    * \param 迭代项： 可迭代对象，要求迭代器至少满足单向可写迭代器。
    * \param 填充值： 可调用对象。
    * \return 
    * \tparam OutputT： 可迭代类型。
    * \tparam TmpCall： 可调用类型，无参，要求返回值类型能够赋值给迭代范围元素类型。
    */
   template<迭代类型 OutputT, 调用类型<> TmpCall>
   inline constexpr 类型空的 调用填充(OutputT &&迭代项, TmpCall &&填充值)
   noexcept(noexcept(BE::调用填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpCall>(填充值))))
   requires(requires(){BE::调用填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpCall>(填充值)); })
   {
      BE::调用填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpCall>(填充值));
   }

   /**
    * \brief >>> 向迭代范围不断填充填充向的值，每次填充填充项都会进行依次自增。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 填充项： 要填充的值。
    * \return 
    * \tparam TmpT： 能够进行自增自减的类型。
    * \tparam OutputT： 至少满足单向迭代器的可写迭代器类型，并且解引用类型要能赋值 TmpT。
    */
   template<自增减类型 TmpT, 可写迭代类型<迭代枚举::单向, TmpT> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 增值填充(OutputT 开始项, OutputT 结束项, TmpT &&填充项)
   noexcept(noexcept(安全赋值类型<ODRT, TmpT>))
   {
      for (; 开始项 != 结束项; ++开始项, ++填充项)
      {
         (*开始项) = 填充项;
      }
   }

   /**
    * \brief >>> 向迭代范围不断填充填充向的值，每次填充填充项都会进行依次自增。
    * 
    * \param 迭代项： 可迭代对象，要求迭代器至少满足单向可写迭代器。
    * \param 填充值： 要填充的值。
    * \return 
    * \tparam TmpT： 能够进行自增自减的类型。
    * \tparam OutputT： 可迭代类型，并且解引用类型要能赋值 TmpT。
    */
   template<自增减类型 TmpT, 迭代类型 OutputT>
   inline constexpr 类型空的 增值填充(OutputT &&迭代项, TmpT &&填充值)
   noexcept(noexcept(BE::增值填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpT>(填充值))))
   requires(requires(){BE::增值填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpT>(填充值)); })
   {
      BE::增值填充(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpT>(填充值));
   }

}
