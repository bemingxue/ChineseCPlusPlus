
namespace BE {

   /**
    * \brief >>> 将移动迭代范围内的元素以移动语义复制到接收迭代范围内，接收迭代范围结束由移动结束范围决定。
    * 
    * \param 接收项： 接收迭代范围开始。
    * \param 移动开始项： 移动迭代范围开始。
    * \param 移动结束项： 移动迭代范围结束。
    * \return 
    * \tparam InpuT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam OutputT： 至少满足单向迭代器需求的可写迭代器类型，其解引用值要能被接收迭代范围内元素移动赋值。
    */
   template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>, 
            可写迭代类型<迭代枚举::单向, std::remove_reference_t<IDRT>&&> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 移动复制(InputT 接收项, OutputT 移动开始项, OutputT 移动结束项)
   noexcept(noexcept(安全赋值类型<IDRT, std::remove_reference_t<ODRT>&&>))
   {
      for (; 移动开始项 != 移动结束项; ++移动开始项, ++接收项)
      {
         (*接收项) = std::move(*移动开始项);
      }
   }

   /**
    * \brief >>> 将移动迭代范围内的元素以移动语义复制到接收迭代范围内。
    * 
    * \param 接收开始项： 接收迭代范围开始。
    * \param 接收结束项： 接收迭代范围结束。
    * \param 移动开始项： 移动迭代范围开始。
    * \param 移动结束项： 移动迭代范围结束。
    * \return 
    * \tparam InpuT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam OutputT： 至少满足单向迭代器需求的可写迭代器类型，其解引用值要能被接收迭代范围内元素移动赋值。
    */
   template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>,
            可写迭代类型<迭代枚举::单向, std::remove_reference_t<IDRT>&&> OutputT, typename ODRT = 模板解引类型<OutputT>>
   inline constexpr 类型空的 移动复制(InputT 接收开始项, InputT 接收结束项, OutputT 移动开始项, OutputT 移动结束项)
   noexcept(noexcept(安全赋值类型<IDRT, std::remove_reference_t<ODRT>&&>))
   {
      for (; 接收开始项 != 接收结束项 && 移动开始项 != 移动结束项; ++接收开始项, ++移动开始项)
      {
         (*接收开始项) = std::move(*移动开始项);
      }
   }

   /**
    * \brief >>> 将移动迭代范围内的元素以移动语义复制到接收迭代范围内。
    * 
    * \param 接收项： 可迭代对象，其迭代器要求至少满足单向可写迭代器。。
    * \param 移动项： 可迭代对象，其迭代器要求至少满足单向可读迭代器。
    * \return 
    * \tparam OutputT： 可迭代类型，其迭代器要求至少满足单向可写迭代器。
    * \tparam InputT： 可迭代类型，其迭代器要求至少满足单向可读迭代器。
    */
   template<迭代类型 OutputT, 迭代类型 InputT>
   inline constexpr 类型空的 移动复制(OutputT &&接收项, InputT &&移动项)
   noexcept(noexcept(BE::移动复制(BE::开始(接收项), BE::结束(接收项), BE::开始(移动项), BE::结束(移动项))))
   requires(requires(){BE::移动复制(BE::开始(接收项), BE::结束(接收项), BE::开始(移动项), BE::结束(移动项));})
   {
      BE::移动复制(BE::开始(接收项), BE::结束(接收项), BE::开始(移动项), BE::结束(移动项));
   }

}
