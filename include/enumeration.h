
namespace BE {

   /**
    * \brief >>> 该可迭代类允许你在迭代的同时获取当前迭代的索引，也允许你自定义索引的初始值，一般用于范围 for 循环中进行绑定，请使用 && 形式，并且第一个为索引。
    * \tparam TmpT： 具有迭代器的迭代类型，可以是左值或右值类型。
    * \tparam TmpIndex： 整数类型，用于表示索引的类型。
    * \tparam TmpCount： 类型逻辑，用于表示 end 是否获取迭代范围长度，默认不获取以避免不需要的开销。
    */
   template<迭代类型 TmpT, 整数类型 TmpIndex = 类型长度, 类型逻辑 TmpCount = 假>
   struct 列举迭代类
   {
      // 迭代类型的迭代器。
      using 迭代类 = 模板迭代类型<TmpT>;
      // 迭代器的解引用类型。
      using 值类   = 模板解引类型<迭代类>;

      // 负责结构化绑值的结构。
      template<typename TmpU>
      struct 迭代值类
      {
         TmpIndex 迭代值;
         TmpU     值;

         // 允许进行赋值操作，只要解引用类型允许的话。
         template<typename TmpV>
         constexpr 迭代值类 &operator = (TmpV &&赋值项) 
         noexcept(noexcept(安全赋值类型<TmpU, TmpV>))
         requires(赋值类型<TmpU, TmpV>)
         {
            this->值 = std::forward<TmpV>(赋值项);
            return *this;
         }

         // 隐式转换为解引用的类型。
         constexpr operator TmpU() noexcept
         {
            return this->值;
         }
      };

      // 负责迭代的类型，但不支持 -> 运算符，由于一般在范围 for 循环中使用，因此只提供前缀 ++ 和 -- 运算符。
      struct 类迭代类
      {
         类迭代类() noexcept : 类中索引(0), 类中迭代器(迭代类()) 
         {
         
         }

         类迭代类(TmpIndex 起始项, 迭代类 迭代项) noexcept : 类中索引(起始项), 类中迭代器(迭代项)
         {

         }

         decltype(auto) operator * () noexcept
         {
            return 迭代值类<值类> { 类中索引, *类中迭代器 };
         }

         类迭代类 &operator ++ () noexcept requires(requires(迭代类 X) { ++X; })
         {
            return ++类中索引, ++类中迭代器, *this;
         }

         类迭代类 &operator -- () noexcept requires(requires(迭代类 X) { --X; })
         {
            return --类中索引, --类中迭代器, *this;
         }

         类型逻辑 operator == (const 类迭代类 &比较项) const noexcept
         {
            return 类中迭代器 == 比较项.类中迭代器;
         }

         protected:
         TmpIndex 类中索引;
         迭代类   类中迭代器;
      };

      // 获取开始迭代器。
      constexpr 类迭代类 begin() noexcept
      {
         return 类迭代类(类中起始, ::BE::开始(类中迭代));
      }

      // 获取结束迭代器。
      constexpr 类迭代类 end() noexcept
      {
         if constexpr (TmpCount)
         {
            return 类迭代类(::BE::获取长度(类中迭代), ::BE::结束(类中迭代));
         }

         else
         {
            return 类迭代类(类中起始, ::BE::结束(类中迭代));
         }
      }

      // 默认构造函数，提供要迭代的对象和起始索引，起始索引默认为 0。
      constexpr 列举迭代类(TmpT 迭代项, TmpIndex 起始项 = 0) noexcept : 类中迭代(迭代项), 类中起始(起始项)
      {

      }

      protected:

      TmpT     类中迭代;
      TmpIndex 类中起始 = 0;
   };

   // 模板推导，允许使用 TmpIndex 推导索引类型。
   template<迭代类型 TmpT, 整数类型 TmpIndex>
   列举迭代类(TmpT &&, TmpIndex) -> 列举迭代类<TmpT, TmpIndex>;

   template<迭代类型 TmpT>
   列举迭代类(TmpT &&) -> 列举迭代类<TmpT>;

}
