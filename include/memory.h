
namespace BE {

   // 一种 STmpT 可以进行 STmpT = TmpArgs （TmpArgs = 1）赋值操作或者进行 STmpT(TmpU, TmpArgs...) 构造操作的类型概念。
   template<typename TmpT, typename... TmpArgs>
   concept 可赋值或构造类型 = (赋值类型<TmpT, TmpArgs...> && sizeof...(TmpArgs) == 1) || 构造类型<TmpT, TmpArgs...>;

   // 一种 STmpT 可以进行 STmpT = TmpArgs （TmpArgs = 1）安全赋值操作或者进行 STmpT(TmpU, TmpArgs...) 安全构造操作的类型概念。
   template<typename TmpT, typename... TmpArgs>
   concept 可安全赋值或构造类型 = (安全赋值类型<TmpT, TmpArgs...> && sizeof...(TmpArgs) == 1) || 安全构造类型<TmpT, TmpArgs...>;

   // 在赋值与构造的选择中表示使用赋值。
   inline constexpr 类型逻辑 选择使用赋值 = 真;

   // 在赋值与构造的选择中表示使用构造。
   inline constexpr 类型逻辑 选择使用构造 = 假;

   /**
    * \brief >>> 选择使用赋值还是构造，如果 TmpArgs 只有一个则将判断，赋值和构造优先选择赋值，然后判断安全性。
    * 
    * \return `选择赋值` 或 `选择构造`
    */
   template<typename TmpT, typename... TmpArgs>
   inline consteval 类型逻辑 赋值或构造() noexcept
   {
      if constexpr (sizeof...(TmpArgs) == 1)
      {
         if constexpr (安全赋值类型<TmpT, TmpArgs...>)
         {
            return 选择使用赋值;
         }
         else if constexpr (安全构造类型<TmpT, TmpArgs...>)
         {
            return 选择使用构造;
         }
         else
         {
            return 选择使用赋值;
         }
      }

      return 选择使用构造;
   }

   /**
    * \brief >>> 将指针指向的指定大写的内存块全部清零。
    * 
    * \param 指针项： 指向内存块的指针。
    * \param 长度项： 内存块的长度。
    * \param 类型长度项： 内存块中每个元素的字节长度，默认为 sizeof(STmpT)。
    * \return 指针项
    */
   template<typename TmpT>
   inline TmpT *填充零(TmpT *指针项, 类型长度 长度项, 类型长度 类型长度项 = sizeof(TmpT)) noexcept
   {
      return 指针项 ? reinterpret_cast<TmpT *>(std::memset(指针项, 0, 长度项 * 类型长度项)) : 空指针;
   }

   /**
    * \brief >>> 将指针指向的内存块中的指定数量元素全部析构。
    * 
    * \param 指针项： 指向内存块的指针。
    * \param 长度项： 内存块中元素的数量。
    * \return 指针项
    * \tparam TmpT： 内存块中元素的类型，如果是平凡类型则无需析构。
    */
   template<typename TmpT>
   inline TmpT *直接析构(TmpT *指针项, 类型长度 长度项) noexcept
   {
      if constexpr (!平凡复制类型<TmpT>)
      {
         for (TmpT *迭代量 = 指针项; 指针项 && static_cast<类型长度>(迭代量 - 指针项) < 长度项; ++迭代量)
         {
            迭代量->~TmpT();
         }
      }

      return 指针项;
   }

   /**
    * \brief >>> 在指针指向的内存块中构造指定数量的元素，不会进行析构。
    * 
    * \param 指针项： 指向内存块的指针。
    * \param 长度项： 内存块中元素的数量。
    * \param 构造参数表： 要传递给构造函数的参数表。
    * \return 指针项
    */
   template<typename TmpT, typename... TmpArgs>
   inline TmpT *直接构造(TmpT *指针项, 类型长度 长度项, TmpArgs&&... 构造参数表) noexcept
   {
      for (TmpT *迭代量 = 指针项; 指针项 && static_cast<类型长度>(迭代量 - 指针项) < 长度项; ++迭代量)
      {
         new (reinterpret_cast<void *>(迭代量)) TmpT(std::forward<TmpArgs>(构造参数表)...);
      }

      return 指针项;
   }

   /**
    * \brief >>> 对赋值项中的每个元素移动给指针项指向的内存块中的每个元素。
    * 
    * \param 指针项： 指向内存块的指针。
    * \param 赋值项： 要进行移动的内存块，如果内存中的元素都是未构造且非平凡的则行为未定义。
    * \param 长度项： 内存块中元素的数量。
    * \return 指针项
    */
   template<typename TmpT, typename TmpU>
   inline TmpT *移动构造(TmpT *指针项, TmpU *赋值项, 类型长度 长度项) noexcept
   {
      for (TmpT *迭代量 = 指针项; 指针项 && static_cast<类型长度>(迭代量 - 指针项) < 长度项; ++迭代量)
      {
         new (reinterpret_cast<void *>(迭代量)) TmpT(std::move(*赋值项));

         ++赋值项;
      }

      return 指针项;
   }

   /**
    * \brief >>> 析构指针指向的内存块中的指定数量的元素，并重新构造。
    * 
    * \param 指针项： 指向内存块的指针。
    * \param 长度项： 内存块中元素的数量。
    * \param 构造参数表： 要传递给构造函数的参数表。
    * \return 指针项
    */
   template<typename TmpT, typename... TmpArgs>
   inline TmpT *重新构造(TmpT *指针项, 类型长度 长度项, TmpArgs&&... 构造参数表) noexcept
   {
      for (TmpT *迭代量 = 指针项; 指针项 && static_cast<类型长度>(迭代量 - 指针项) < 长度项; ++迭代量)
      {
         迭代量->~TmpT();

         new (reinterpret_cast<void *>(迭代量)) TmpT(std::forward<TmpArgs>(构造参数表)...);
      }

      return 指针项;
   }

   /**
    * \brief >>> 从系统中分配指定元素长度的内存，并不对这些内存进行构造。
    * 
    * \param 长度项： 要分配的元素数量。
    * \return 指向内存块的指针，如果分配失败，则返回空指针。
    */
   template<typename TmpT>
   inline TmpT *分配原始内存(类型长度 长度项) noexcept
   {
      try {
         TmpT  *tmp = reinterpret_cast<TmpT *>(::operator new(长度项 * sizeof(TmpT)));
         // ...
#ifdef _BE_TEST_OUTPUT_MEM_
         if (tmp)
            std::cout << "allocate memory: " << (void *)tmp << std::endl;
#endif
         return tmp;
      } catch (...) {
         return 空指针;
      }
   }

   /**
    * \brief >>> 释放内存块，但不进行析构。
    * 
    * \param 指针项： 指向内存块的指针。
    * \return 
    */
   template<typename TmpT>
   inline 类型空的 释放原始内存(TmpT *指针项) noexcept
   {
#ifdef _BE_TEST_OUTPUT_MEM_
      if (指针项)
         std::cout << "release memory: " << (void *)指针项 << std::endl;
#endif
      ::operator delete(reinterpret_cast<void *>(指针项));
   }
   
   /**
    * \brief >>> 函数自动根据索引、参数表选择使用赋值还是构造，如参数表的参数数量不等于 1 则总是使用构造，否则根据赋值优先、安全性选择赋值或者构造
    * 
    * \param 赋值项： 要进行赋值的对象。
    * \param 索引项： 对象在内存块中的位置。
    * \param 长度项： 内存块中元素的数量。
    * \param 参数表： 要传递给构造函数或赋值运算符的参数表。
    * \return 赋值项
    * \tparam TmpT： 要进行赋值的对象类型。
    * \tparam TmpArgs： 要传递给构造函数或赋值运算符的参数表。
    */
   template<typename TmpT, typename... TmpArgs>
   inline TmpT &选择赋值(TmpT &赋值项, 类型长度 索引项, 类型长度 长度项, TmpArgs&&... 参数表)
   noexcept(noexcept(可安全赋值或构造类型<TmpT, TmpArgs...>))
   requires(可赋值或构造类型<TmpT, TmpArgs...>)
   {
      // 如果不在范围内则元素可能被析构过，因此总是使用构造。
      if (索引项 >= 长度项)
      {
         ::BE::直接构造(::BE::获取地址(赋值项), 1, std::forward<TmpArgs>(参数表)...);
      }
      else
      {
         if constexpr (赋值或构造<TmpT, TmpArgs...>() == 选择使用赋值)
         {
            赋值项 = (std::forward<TmpArgs>(参数表), ...);
         }
         else
         {
            ::BE::重新构造(::BE::获取地址(赋值项), 1, std::forward<TmpArgs>(参数表)...);
         }
      }

      return 赋值项;
   }

   /**
    * \brief >>> 释放内存，使用 delete。
    */
   template<typename TmpT>
   struct 默认内存释放类
   {
      类型空的 operator () (TmpT *指针项, 类型长度) const noexcept
      {
         delete 指针项;
      }
   };

   /**
    * \brief >>> 释放内存，使用 delete[]。
    */
   template<typename TmpT>
   struct 默认内存释放类<TmpT[]>
   {
      类型空的 operator () (TmpT *指针项, 类型长度) const noexcept
      {
         delete[] 指针项;
      }
   };

   /**
    * \brief >>> 具有释放类操作但实际不进行任何操作的释放类。
    */
   template<typename TmpT>
   struct 默认假内存释放类
   {
      类型空的 operator () (TmpT *, 类型长度) const noexcept
      {

      }
   };

}
