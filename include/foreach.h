
namespace BE {

   /**
    * \brief >>> 遍历迭代范围，并将迭代范围内的元素依次传递给调用项，如果调用项具有返回值并且返回值类型可以转换为类型逻辑，则如果返回的逻辑值为假则提前退出函数。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 调用项： 可调用对象。
    * \return 
    * \tparam InputT： 至少满足单向迭代器的可读迭代器类型。
    * \tparam TmpCall： 可调用类型，参数要能接收 InputT 的解引用类型。
    */
   template<单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>, 调用类型<IDRT> TmpCall>
   inline constexpr 类型空的 遍历(InputT 开始项, InputT 结束项, TmpCall &&调用项)
   noexcept(noexcept(安全调用类型<TmpCall, IDRT>))
   {
      for (; 开始项 != 结束项; ++开始项)
      {
         if constexpr (转换类型<模板返回类型<TmpCall, IDRT>, 类型逻辑>)
         {
            if (调用项((*开始项)) == 假)
            {
               break;
            }
         }

         else
         {
            调用项((*开始项));
         }
      }
   }

   /**
    * \brief >>> 遍历迭代范围，并将迭代范围内的元素依次传递给调用项，如果调用项具有返回值并且返回值类型可以转换为类型逻辑，则如果返回的逻辑值为假则提前退出函数。
    * 
    * \param 迭代项： 可迭代对象，其迭代器至少满足单向可读迭代器。
    * \param 调用项： 可调用对象。
    * \return 
    * \tparam InputT： 可迭代类型，其迭代器至少满足单向可读迭代器。
    * \tparam TmpCall： 可调用类型，参数要能接收 InputT 的解引用类型。
    */
   template<迭代类型 InputT, typename IDRT = 模板解引类型<模板迭代类型<InputT>>, 调用类型<IDRT> TmpCall>
   inline constexpr 类型空的 遍历(InputT &&迭代项, TmpCall &&调用项)
   noexcept(noexcept(BE::遍历(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpCall>(调用项))))
   requires(requires() { BE::遍历(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpCall>(调用项)); })
   {
      BE::遍历(BE::开始(迭代项), BE::结束(迭代项), std::forward<TmpCall>(调用项));
   }

}
