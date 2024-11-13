
namespace BE {

   // 一种可以被对值类直接继承的类型，要求为空类型并且可继承，因为非空类型没有被继承的必要。
   template<typename TmpT>
   concept 对值可继承类型 = !最终类型<TmpT> && 空类类型<TmpT>;

   /**
    * \brief >>> 一种存储两种不同类型的类类型，提供多种特化。
    */
   template<typename TmpT, typename TmpU>
   struct 对值类
   {

      /**
       * .
       */
      对值类() 
      noexcept(noexcept(安全默认构造类型<TmpT> && 安全默认构造类型<TmpU>()))
      requires(默认构造类型<TmpT> && 默认构造类型<TmpU>)
         : 类中首值(), 类中尾值() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      对值类(Tmp2T &&首赋值项, Tmp2U &&尾赋值项)
      noexcept(noexcept(安全构造类型<TmpT, Tmp2T> && 安全构造类型<TmpU, Tmp2U>))
      requires(构造类型<TmpT, Tmp2T> && 构造类型<TmpU, Tmp2U>)
         : 类中首值(std::forward<Tmp2T>(首赋值项))
         , 类中尾值(std::forward<Tmp2U>(尾赋值项)) { }

      /**
       * \brief >>> 获取对值中的首值。
       * 
       * \return 首值引用。
       */
      TmpT &获取首值() noexcept 
      {  
         return 类中首值;   
      }

      /**
       * \brief >>> 获取对值中的尾值。
       * 
       * \return 尾值引用。
       */
      TmpU &获取尾值() noexcept
      {
         return 类中尾值;
      }

      const TmpT &获取首值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取首值();
      }

      const TmpU &获取尾值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取尾值();
      }

      protected:

      TmpT 类中首值;
      TmpU 类中尾值;

      public:

      template<typename Tmp2T, typename Tmp2U>
      对值类 & operator = (const 对值类<Tmp2T, Tmp2U> &赋值项) 
      noexcept
      requires(赋值类型<TmpT, Tmp2T> &&赋值类型<TmpU, Tmp2U>)
      {
         this->获取首值() = 赋值项.获取首值();
         this->获取尾值() = 赋值项.获取尾值();
         return *this;
      }
   };

   /**
    * \brief >>> 对值类特化，对于 TmpT，其为空类型并且可继承时，将直接私有继承 STmpT 以节省内存空间占用。
    * \brief >>> [extends] private STmpT 
    */
   template<对值可继承类型 TmpT, typename TmpU>
   struct 对值类<TmpT, TmpU> : private TmpT
   {

      /**
       * .
       */
      对值类()
      noexcept(noexcept(安全默认构造类型<TmpT> && 安全默认构造类型<TmpU>))
      requires(默认构造类型<TmpT> && 默认构造类型<TmpU>)
         : TmpT(), 类中值项() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      对值类(Tmp2T &&首赋值项, Tmp2U &&尾赋值项)
      noexcept(noexcept(安全构造类型<TmpT, Tmp2T> && 安全构造类型<TmpU, Tmp2U>))
      requires(构造类型<TmpT, Tmp2T> && 构造类型<TmpU, Tmp2U>)
         : TmpT(std::forward<Tmp2T>(首赋值项))
         , 类中值项(std::forward<Tmp2U>(尾赋值项)) { }

      /**
       * \brief >>> 获取对值中的首值，也就是本身。
       * 
       * \return 首值引用。
       */
      TmpT &获取首值() noexcept
      {
         return *this;
      }

      /**
       * \brief >>> 获取对值中的尾值。
       * 
       * \return 尾值引用。
       */
      TmpU &获取尾值() noexcept
      {
         return 类中值项;
      }

      const TmpT &获取首值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取首值();
      }

      const TmpU &获取尾值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取尾值();
      }

      protected:

      TmpU 类中值项;

      public:

      template<typename Tmp2T, typename Tmp2U>
      对值类 & operator = (const 对值类<Tmp2T, Tmp2U> &赋值项) 
      noexcept
      requires(赋值类型<TmpT, Tmp2T> &&赋值类型<TmpU, Tmp2U>)
      {
         this->获取首值() = 赋值项.获取首值();
         this->获取尾值() = 赋值项.获取尾值();
         return *this;
      }
   };

   /**
    * \brief >>> 对值类特化，对于 TmpU，其为空类型并且可继承时，将直接私有继承 TmpU 以节省内存空间占用。
    * \brief >>> [extends] private TmpU
    */
   template<typename TmpT, 对值可继承类型 TmpU>
   struct 对值类<TmpT, TmpU> : private TmpU
   {

      /**
       * .
       */
      对值类()
         noexcept(noexcept(安全默认构造类型<TmpT> &&安全默认构造类型<TmpU>))
         requires(默认构造类型<TmpT> &&默认构造类型<TmpU>)
      : TmpU(), 类中值项() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      对值类(Tmp2T &&首赋值项, Tmp2U &&尾赋值项)
         noexcept(noexcept(安全构造类型<TmpT, Tmp2T> &&安全构造类型<TmpU, Tmp2U>))
         requires(构造类型<TmpT, Tmp2T> &&构造类型<TmpU, Tmp2U>)
      : TmpU(std::forward<Tmp2U>(尾赋值项))
         , 类中值项(std::forward<Tmp2T>(首赋值项)) { }

      /**
       * \brief >>> 获取对值中的尾值，也就是本身。
       *
       * \return 尾值引用。
       */
      TmpU &获取尾值() noexcept
      {
         return *this;
      }

      /**
       * \brief >>> 获取对值中的首值。
       *
       * \return 首值引用。
       */
      TmpT &获取首值() noexcept
      {
         return 类中值项;
      }

      const TmpT &获取首值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取首值();
      }

      const TmpU &获取尾值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取尾值();
      }

      protected:

      TmpT 类中值项;
      
      public:

      template<typename Tmp2T, typename Tmp2U>
      对值类 & operator = (const 对值类<Tmp2T, Tmp2U> &赋值项) 
      noexcept
      requires(赋值类型<TmpT, Tmp2T> &&赋值类型<TmpU, Tmp2U>)
      {
         this->获取首值() = 赋值项.获取首值();
         this->获取尾值() = 赋值项.获取尾值();
         return *this;
      }
   };

   /**
    * \brief >>> 对值类特化，对于 STmpT 和 TmpU，其均为空类型并且可继承时，将直接私有继承 STmpT 和 TmpU 以节省内存空间占用。
    * \brief >>> [extends] private STmpT, private TmpU
    */
   template<对值可继承类型 TmpT, 对值可继承类型 TmpU>
   struct 对值类<TmpT, TmpU> : private TmpT, private TmpU
   {

      /**
       * .
       */
      对值类()
         noexcept(noexcept(安全默认构造类型<TmpT> && 安全默认构造类型<TmpU>))
         requires(默认构造类型<TmpT> && 默认构造类型<TmpU>)
      : TmpT(), TmpU() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      对值类(Tmp2T &&首赋值项, Tmp2U &&尾赋值项)
         noexcept(noexcept(安全构造类型<TmpT, Tmp2T> && 安全构造类型<TmpU, Tmp2U>))
         requires(构造类型<TmpT, Tmp2T> && 构造类型<TmpU, Tmp2U>)
      : TmpT(std::forward<Tmp2T>(首赋值项)), TmpU(std::forward<Tmp2U>(尾赋值项)) { }

      /**
       * \brief >>> 获取对值中的首值，也就是本身。
       *
       * \return 首值引用。
       */
      TmpT &获取首值() noexcept
      {
         return *this;
      }

      /**   
      * \brief >>> 获取对值中的尾值，也就是本身。
      *
      * \return 尾值引用。
      */
      TmpU &获取尾值() noexcept
      {
         return *this;
      }

      const TmpT &获取首值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取首值();
      }

      const TmpU &获取尾值() const noexcept
      {
         return const_cast<对值类 *>(this)->获取尾值();
      }
      
      public:

      template<typename Tmp2T, typename Tmp2U>
      对值类 & operator = (const 对值类<Tmp2T, Tmp2U> &赋值项) 
      noexcept
      requires(赋值类型<TmpT, Tmp2T> &&赋值类型<TmpU, Tmp2U>)
      {
         this->获取首值() = 赋值项.获取首值();
         this->获取尾值() = 赋值项.获取尾值();
         return *this;
      }
   };

   // 对值类模板推导。
   template<typename TmpT, typename TmpU>
   对值类(TmpT, TmpU) -> 对值类<TmpT, TmpU>;

}
