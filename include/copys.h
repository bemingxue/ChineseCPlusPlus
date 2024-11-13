
namespace BE {

   /**
    * \brief >>> 将复制迭代范围内的元素复制到接收项中，接收项结束范围由复制结束项决定，接收和复制满足解引用类型相同为指针类型并且可平凡复制则使用 memmove 进行快速复制。
    * 
    * \param 接收项： 接收迭代范围开始。
    * \param 复制开始项： 复制迭代范围开始。
    * \param 复制结束项： 复制迭代范围结束。
    * \return 
    * \tparam InputT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam OutputT： 至少满足单向迭代器需求的可写迭代器类型。
    */
   template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>, 
            可写迭代类型<迭代枚举::单向, IDRT> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 复制(OutputT 接收项, InputT 复制开始项, InputT 复制结束项)
   noexcept(noexcept(安全赋值类型<ODRT, IDRT>))
   {
      if constexpr (相同类型<IDRT, ODRT> && 指针类型<InputT, OutputT> && 平凡复制类型<IDRT, ODRT>)
      {
         // 指针类型就是随机迭代器。
         std::memmove(接收项, 复制开始项, (复制结束项 - 复制开始项) * sizeof(IDRT));
      }

      else
      {
         for (; 复制开始项 != 复制结束项; ++复制开始项, ++接收项)
         {
            (*接收项) = (*复制开始项);
         }
      }
   }

   /**
    * \brief >>> 限定范围的，将复制迭代范围内的元素复制到接收迭代范围中，接收和复制满足解引用类型相同为指针类型并且可平凡复制则使用 memmove 进行快速复制。
    * 
    * \param 接收开始项： 接收迭代范围开始。
    * \param 接收结束项： 接收迭代范围结束。
    * \param 复制开始项： 复制迭代范围开始。
    * \param 复制结束项： 复制迭代范围结束。
    * \return 
    * \tparam InputT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam OutputT： 至少满足单向迭代器需求的可写迭代器类型。
    */
   template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>,
            可写迭代类型<迭代枚举::单向, IDRT> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 复制(OutputT 接收开始项, OutputT 接收结束项, InputT 复制开始项, InputT 复制结束项)
   noexcept(noexcept(安全赋值类型<ODRT, IDRT>))
   {
      if constexpr (相同类型<IDRT, ODRT> && 指针类型<InputT, OutputT> && 平凡复制类型<IDRT, ODRT>)
      {
         std::memmove(接收开始项, 复制开始项, std::min((复制结束项 - 复制开始项) * sizeof(IDRT), (接收结束项 - 接收开始项) * sizeof(IDRT)));
      }

      else
      {
         for (; 复制开始项 != 复制结束项 && 接收开始项 != 接收结束项; ++复制开始项, ++接收开始项)
         {
            (*接收开始项) = (*复制开始项);
         }
      }
   }

   /**
    * \brief >>> 将复制迭代范围中的元素复制到接收迭代范围中，接收和复制满足解引用类型相同为指针类型并且可平凡复制则使用 memmove 进行快速复制。
    * 
    * \param 接收项： 可迭代对象，接收迭代范围。
    * \param 复制项： 可迭代对象，复制迭代范围。
    * \return 
    * \tparam OutputT： 可迭代类型，具有至少满足单向迭代器需求的可写迭代器类型。
    * \tparam InputT： 可迭代类型，具有至少满足单向迭代器需求的可读迭代器类型。
    */
   template<迭代类型 OutputT, 迭代类型 InputT>
   inline constexpr 类型空的 复制(OutputT &&接收项, InputT &&复制项)
   noexcept(noexcept(BE::复制(BE::开始(接收项), BE::结束(接收项), BE::开始(复制项), BE::结束(复制项))))
   requires(requires() { BE::复制(BE::开始(接收项), BE::结束(接收项), BE::开始(复制项), BE::结束(复制项)); })
   {
      BE::复制(BE::开始(接收项), BE::结束(接收项), BE::开始(复制项), BE::结束(复制项));
   }

   /**
    * \brief >>> 从复制迭代范围的结束开始依次将元素复制到接收迭代范围中，不包括结束范围，接收迭代范围的结束由复制开始项决定。
    * 
    * \param 接收项： 接收迭代范围开始。
    * \param 复制开始项： 复制迭代范围开始，实际为结束。
    * \param 复制结束项： 复制迭代范围结束，实际为开始。
    * \return 
    * \tparam InputT： 至少满足双向迭代器需求的可读迭代器类型。
    * \tparam OutputT： 至少满足单向迭代器需求的可写迭代器类型。
    */
   template<双向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>,
            可写迭代类型<迭代枚举::单向, IDRT> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 逆向复制(OutputT 接收项, InputT 复制开始项, InputT 复制结束项)
   noexcept(noexcept(安全赋值类型<ODRT, IDRT>))
   {
      for (; 复制开始项 != 复制结束项; ++接收项)
      {
         (*接收项) = (*--复制结束项);
      }
   }

   /**
    * \brief >>> 将复制迭代范围从结束开始依次复制到接收迭代范围中，不包括结束范围。
    * 
    * \param 接收开始项： 接收迭代范围开始。
    * \param 接收结束项： 接收迭代范围结束。
    * \param 复制开始项： 复制迭代范围开始，实际为结束。
    * \param 复制结束项： 复制迭代范围结束，实际为开始。
    * \return 
    * \tparam InputT： 至少满足双向迭代器需求的可读迭代器类型。
    * \tparam OutputT： 至少满足单向迭代器需求的可写迭代器类型。
    */
   template<双向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>,
            可写迭代类型<迭代枚举::单向, IDRT> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 逆向复制(OutputT 接收开始项, OutputT 接收结束项, InputT 复制开始项, InputT 复制结束项)
   noexcept(noexcept(安全赋值类型<ODRT, IDRT>))
   {
      for (; 复制开始项 != 复制结束项 && 接收开始项 != 接收结束项; ++接收开始项)
      {
         (*接收开始项) = (*--复制结束项);
      }
   }

   /**
    * \brief >>> 从复制迭代范围的结束开始依次将元素复制到接收迭代范围中，不包括结束范围，接收迭代范围的结束由复制开始项决定。
    * 
    * \param 接收项： 可迭代对象，接收迭代范围。
    * \param 复制项： 可迭代对象，复制迭代范围。
    * \return 
    * \tparam OutputT： 可迭代类型，具有至少满足单向迭代器需求的可写迭代器类型。
    * \tparam InputT： 可迭代类型，具有至少满足双向迭代器需求的可读迭代器类型。
    */
   template<迭代类型 OutputT, 迭代类型 InputT>
   inline constexpr 类型空的 逆向复制(OutputT &&接收项, InputT &&复制项)
   noexcept(noexcept(BE::逆向复制(BE::开始(接收项), BE::结束(接收项), BE::开始(复制项), BE::结束(复制项))))
   requires(requires() { BE::逆向复制(BE::开始(接收项), BE::结束(接收项), BE::开始(复制项), BE::结束(复制项)); })
   {
      BE::逆向复制(BE::开始(接收项), BE::结束(接收项), BE::开始(复制项), BE::结束(复制项));
   }


}
