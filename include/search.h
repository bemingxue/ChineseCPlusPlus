
namespace BE {

   /**
    * \brief >>> 查找函数返回的类型，存储索引和迭代器。
    * \tparam InputT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam TmpT：   数字类型，用于存储索引。
    */
   template<typename InputT, 数字类型 TmpT>
   struct 查找值类
   {
      using Ty = 模板解引类型<InputT>;

      // error : 由于有宏“迭代”，因此这里不能命名为“迭代” 
      // InputT 迭代;

      InputT 迭代器;
      TmpT   索引;

      operator Ty () noexcept
      {
         return *迭代器;
      }
   };

   /**
    * \brief >>> 在迭代范围中查找指定值，默认使用 == 运算符进行比较判断。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 查找项： 要查找的值。
    * \param 调用项： 可调用对象，用于比较的函数，默认使用 == 运算符。
    * \return 一个存储索引和迭代器的值，如果没有找到则索引为到末尾，迭代器等于结束项。
    * \tparam TmpRet： 索引的数字类型，默认为类型长度。
    * \tparam InputT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam TmpTarget： 要查找的值的类型。
    * \tparam TmpCall： 可调用类型，至少接收两个参数，分别是 InputT 的解引用类型和 TmpTarget 类型，并且返回值类型要能够被转换为类型逻辑。
    */
   template<数字类型 TmpRet = 类型长度, 单向迭代类型 InputT, typename IDRT = 模板解引类型<InputT>, 
            typename TmpTarget, 比较调用类型<IDRT, TmpTarget> TmpCall = 运算相等类<>>
   inline constexpr 查找值类<InputT, TmpRet> 查找(InputT 开始项, InputT 结束项, TmpTarget &&查找项, TmpCall &&调用项 = 运算相等类<>())
   noexcept(noexcept(安全调用类型<TmpCall, IDRT, TmpTarget>))
   {
      for (TmpRet 索引量 = 0; ; ++索引量, ++开始项)
      {
         if (开始项 == 结束项)
         {
            return { 结束项, TmpRet(到末尾) };
         }

         if (调用项(*开始项, 查找项) == 真)
         {
            return { 开始项, 索引量 };
         }
      }
   }

   /**
    * \brief >>> 在迭代范围中查找集合迭代范围中存在的元素值，默认使用 == 运算符进行比较判断。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 集合开始项： 集合迭代范围开始。
    * \param 集合结束项： 集合迭代范围结束。
    * \param 调用项： 可调用对象，用于比较的函数，默认使用 == 运算符。
    * \return 一个存储索引和迭代器的值，如果没有找到则索引为到末尾，迭代器等于结束项。
    * \tparam TmpRet： 索引的数字类型，默认为类型长度。
    * \tparam InputT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam InputU： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam TmpCall： 可调用类型，至少接收两个参数，分别是 InputT 的解引用类型和 InputU 的解引用类型，并且返回值类型要能够被转换为类型逻辑。
    */
   template<数字类型 TmpRet = 类型长度, 单向迭代类型 InputT, 单向迭代类型 InputU, 
            typename IDRT = 模板解引类型<InputT>, typename IDRU = 模板解引类型<InputU>,
            比较调用类型<IDRT, IDRU> TmpCall = 运算相等类<>>
   inline constexpr 查找值类<InputT, TmpRet> 查找集合(InputT 开始项, InputT 结束项, InputU 集合开始项, InputU 集合结束项, TmpCall &&调用项 = 运算相等类<>())
   noexcept(noexcept(安全调用类型<TmpCall, IDRT, IDRU>))
   {
      for (TmpRet 索引量 = 0; ; ++索引量, ++开始项)
      {
         if (开始项 == 结束项)
         {
            return { 结束项, TmpRet(到末尾) };
         }

         if (BE::查找(集合开始项, 集合结束项, *开始项, 调用项).迭代器 != 集合结束项)
         {
            return { 开始项, 索引量 };
         }
      }
   }

   /**
    * \brief >>> 在迭代范围中查找和块范围中元素值全部相等的位置，默认使用 == 运算符进行比较判断。
    * 
    * \param 开始项： 迭代范围开始。
    * \param 结束项： 迭代范围结束。
    * \param 块开始项： 块范围开始。
    * \param 块结束项： 块范围结束。
    * \param 调用项： 可调用对象，用于比较的函数，默认使用 == 运算符。
    * \return 一个存储索引和迭代器的值，索引和迭代器为块范围中第一个元素的，如果没有找到则索引为到末尾，迭代器等于结束项。
    * \tparam TmpRet： 索引的数字类型，默认为类型长度。
    * \tparam InputT： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam InputU： 至少满足单向迭代器需求的可读迭代器类型。
    * \tparam TmpCall： 可调用类型，至少接收两个参数，分别是 InputT 的解引用类型和 InputU 的解引用类型，并且返回值类型要能够被转换为类型逻辑。
    */
   template<数字类型 TmpRet = 类型长度, 单向迭代类型 InputT, 单向迭代类型 InputU, 
            typename IDRT = 模板解引类型<InputT>, typename IDRU = 模板解引类型<InputU>,
            比较调用类型<IDRT, IDRU> TmpCall = 运算相等类<>>
   inline constexpr 查找值类<InputT, TmpRet> 查找块(InputT 开始项, InputT 结束项, InputU 块开始项, InputU 块结束项, TmpCall &&调用项 = 运算相等类<>())
   noexcept(noexcept(安全调用类型<TmpCall, IDRT, IDRU>))
   {
      for (TmpRet 索引量 = 0; 开始项 != 结束项; ++索引量, ++开始项)
      {
         if constexpr (随机迭代类型<InputT> && 随机迭代类型<InputU>)
         {
            if (结束项 - 开始项 < 块结束项 - 块开始项)
            {
               return { 结束项, TmpRet(到末尾) };
            }
         }

         if (BE::相等<false>(开始项, 结束项, 块开始项, 块结束项, 调用项) == 真)
         {
            return { 开始项, 索引量 };
         }
      }

      return { 结束项, TmpRet(到末尾) };
   }

}
