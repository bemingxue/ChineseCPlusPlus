
namespace BE {

   /**
    * \brief >>> 将迭代范围中的元素移动到目标项的位置及其之后，请确保这三个迭代器处于同一连续存储空间，如果满足随机迭代器要求和平凡复制要求，函数将会采用 memmove 函数进行复制。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 目标项： 目标位置。
    * \return 
    * \tparam OutputT： 至少满足单向迭代器类型的可写迭代器类型。
    */
   template<可写迭代类型<迭代枚举::单向, T::SCur &&> OutputT>
   inline constexpr 类型空的 左迁移(OutputT 开始项, OutputT 结束项, OutputT 目标项)
   noexcept(noexcept(安全移动赋值类型<模板解引类型<OutputT>>))
   {
      if constexpr (指针类型<OutputT> && 平凡赋值类型<模板解引类型<OutputT>>)
      {
         std::memmove(目标项, 开始项, sizeof(模板解引类型<OutputT>) * (结束项 - 开始项));
      }

      else
      {
         for (; 开始项 != 结束项; ++目标项, ++开始项)
         {
            (*目标项) = std::move(*开始项);
         }
      }
   }

   /**
    * \brief >>> 将迭代范围中的元素移动到目标项的位置及其之前，请确保这三个迭代器处于同一连续存储空间。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 目标项： 目标位置。
    * \return 
    * \tparam OutputT： 为了防止数据覆盖，使用自减，为此需要保证至少满足双向迭代器类型的可写迭代器类型。
    */
   template<可写迭代类型<迭代枚举::双向, T::SCur &&> OutputT>
   inline constexpr 类型空的 右迁移(OutputT 开始项, OutputT 结束项, OutputT 目标项)
   noexcept(noexcept(安全移动赋值类型<模板解引类型<OutputT>>))
   {
      for (; 开始项 != 结束项; --目标项)
      {
         (*目标项) = std::move(*--结束项);
      }
   }

}
