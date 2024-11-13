
namespace BE {

   /**
    * \brief >>> 一个模仿引用的类型，主要用于在模板参数传参中能够传递真正的引用。
    * \tparam STmpT 被引用的对象类型。
    */
   template<对象类型 STmpT>
   struct 引用类
   {

      using 模板参数类型 = STmpT;

      引用类(STmpT &赋值项) noexcept : 类中指针(&赋值项) 
      {
      
      }

      /**
       * \brief >>> 获取引用的对象。
       * 
       * \return 对象的引用。
       */
      STmpT &获取对象() noexcept
      {
         return *this->类中指针;
      }

      /**
       * \brief >>> 获取引用的对象。
       * 
       * \return 对象的只读引用。
       */
      const STmpT &获取对象() const noexcept
      {
         return *this->类中指针;
      }

      protected:

      STmpT *类中指针;

      public:

      // 就像 STmpT = TmpT 赋值的赋值引用的对象。
      template<typename TmpT>
      引用类 &operator = (TmpT &&赋值项)
      noexcept(noexcept(安全赋值类型<STmpT, TmpT>))
      requires(赋值类型<STmpT, TmpT>)
      {
         *this->类中指针 = std::forward<TmpT>(赋值项);
         return *this;
      }

      // 就像 STmpT(TmpArgs...) 调用的调用引用的对象。
      template<typename... TmpArgs, typename TmpRet = 模板返回类型<STmpT, TmpArgs...>>
      TmpRet operator () (TmpArgs &&... 参数表)
      noexcept(noexcept(安全调用类型<STmpT, TmpArgs...>))
      requires(调用类型<STmpT, TmpArgs...>)
      {
         return (*this->类中指针)(std::forward<TmpArgs>(参数表)...);
      }

      // 就像 STmpT[TmpT] 索引引用的对象。
      template<typename TmpT>
      decltype(auto) operator [] (TmpT &&下标项)
      noexcept(noexcept(requires(STmpT X) { { X[下标项] }noexcept; }))
      requires(requires(STmpT X) { { X[下标项] }; })
      {
         return (*this->类中指针)[std::forward<TmpT>(下标项)];
      }
      
      // 获取引用的对象地址而非引用类对象本身的地址。
      STmpT *operator & () noexcept
      {
         return this->类中指针;
      }

      operator STmpT &() noexcept
      {
         return *this->类中指针;
      }

      operator const STmpT &() const noexcept
      {
         return *this->类中指针;
      }

   };

   /**
    * \brief >>> 将赋值项使用引用类包装。
    * 
    * \param 赋值项： 被包装的对象。
    * \return 一个引用类对象。
    */
   template<typename TmpT>
   引用类<TmpT> 创建引用(TmpT &赋值项) noexcept
   {
      return 引用类<TmpT>(赋值项);
   }

   /**
    * \brief >>> 将赋值项使用引用类包装。
    * 
    * \param 赋值项： 被包装的对象。
    * \return 一个引用类对象。
    */
   template<typename TmpT>
   引用类<const TmpT> 创建只读引用(const TmpT &赋值项) noexcept
   {
      return 引用类<const TmpT>(赋值项);
   }

}
