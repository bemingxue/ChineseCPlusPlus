
namespace BE {

   /**
    * \brief >>> 翻转开始到结束范围之间的元素。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \return 
    * \tparam OutputT： 至少满足双向迭代器的类型，其解引用元素能够进行移动赋值。
    */
   template<可写迭代类型<迭代枚举::双向, T::SCur &&> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 翻转(OutputT 开始项, OutputT 结束项)
   noexcept(noexcept(安全赋值类型<ODRT, ODRT &&>))
   {
      for (; 开始项 != 结束项; ++开始项)
      {
         std::remove_reference_t<ODRT> 临时值 = std::move(*开始项);
         (*开始项) = std::move(*(--结束项));
         (*(结束项)) = std::move(临时值);

         // 元素数量是偶数时，需要此判断防止结束项到开始项之前。
         if (开始项 == 结束项)
         {
            break;
         }
      }
   }

}
