
namespace BE {

   // һ�ֿ��Ա���ֵ��ֱ�Ӽ̳е����ͣ�Ҫ��Ϊ�����Ͳ��ҿɼ̳У���Ϊ�ǿ�����û�б��̳еı�Ҫ��
   template<typename TmpT>
   concept ��ֵ�ɼ̳����� = !��������<TmpT> && ��������<TmpT>;

   /**
    * \brief >>> һ�ִ洢���ֲ�ͬ���͵������ͣ��ṩ�����ػ���
    */
   template<typename TmpT, typename TmpU>
   struct ��ֵ��
   {

      /**
       * .
       */
      ��ֵ��() 
      noexcept(noexcept(��ȫĬ�Ϲ�������<TmpT> && ��ȫĬ�Ϲ�������<TmpU>()))
      requires(Ĭ�Ϲ�������<TmpT> && Ĭ�Ϲ�������<TmpU>)
         : ������ֵ(), ����βֵ() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      ��ֵ��(Tmp2T &&�׸�ֵ��, Tmp2U &&β��ֵ��)
      noexcept(noexcept(��ȫ��������<TmpT, Tmp2T> && ��ȫ��������<TmpU, Tmp2U>))
      requires(��������<TmpT, Tmp2T> && ��������<TmpU, Tmp2U>)
         : ������ֵ(std::forward<Tmp2T>(�׸�ֵ��))
         , ����βֵ(std::forward<Tmp2U>(β��ֵ��)) { }

      /**
       * \brief >>> ��ȡ��ֵ�е���ֵ��
       * 
       * \return ��ֵ���á�
       */
      TmpT &��ȡ��ֵ() noexcept 
      {  
         return ������ֵ;   
      }

      /**
       * \brief >>> ��ȡ��ֵ�е�βֵ��
       * 
       * \return βֵ���á�
       */
      TmpU &��ȡβֵ() noexcept
      {
         return ����βֵ;
      }

      const TmpT &��ȡ��ֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡ��ֵ();
      }

      const TmpU &��ȡβֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡβֵ();
      }

      protected:

      TmpT ������ֵ;
      TmpU ����βֵ;

      public:

      template<typename Tmp2T, typename Tmp2U>
      ��ֵ�� & operator = (const ��ֵ��<Tmp2T, Tmp2U> &��ֵ��) 
      noexcept
      requires(��ֵ����<TmpT, Tmp2T> &&��ֵ����<TmpU, Tmp2U>)
      {
         this->��ȡ��ֵ() = ��ֵ��.��ȡ��ֵ();
         this->��ȡβֵ() = ��ֵ��.��ȡβֵ();
         return *this;
      }
   };

   /**
    * \brief >>> ��ֵ���ػ������� TmpT����Ϊ�����Ͳ��ҿɼ̳�ʱ����ֱ��˽�м̳� STmpT �Խ�ʡ�ڴ�ռ�ռ�á�
    * \brief >>> [extends] private STmpT 
    */
   template<��ֵ�ɼ̳����� TmpT, typename TmpU>
   struct ��ֵ��<TmpT, TmpU> : private TmpT
   {

      /**
       * .
       */
      ��ֵ��()
      noexcept(noexcept(��ȫĬ�Ϲ�������<TmpT> && ��ȫĬ�Ϲ�������<TmpU>))
      requires(Ĭ�Ϲ�������<TmpT> && Ĭ�Ϲ�������<TmpU>)
         : TmpT(), ����ֵ��() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      ��ֵ��(Tmp2T &&�׸�ֵ��, Tmp2U &&β��ֵ��)
      noexcept(noexcept(��ȫ��������<TmpT, Tmp2T> && ��ȫ��������<TmpU, Tmp2U>))
      requires(��������<TmpT, Tmp2T> && ��������<TmpU, Tmp2U>)
         : TmpT(std::forward<Tmp2T>(�׸�ֵ��))
         , ����ֵ��(std::forward<Tmp2U>(β��ֵ��)) { }

      /**
       * \brief >>> ��ȡ��ֵ�е���ֵ��Ҳ���Ǳ���
       * 
       * \return ��ֵ���á�
       */
      TmpT &��ȡ��ֵ() noexcept
      {
         return *this;
      }

      /**
       * \brief >>> ��ȡ��ֵ�е�βֵ��
       * 
       * \return βֵ���á�
       */
      TmpU &��ȡβֵ() noexcept
      {
         return ����ֵ��;
      }

      const TmpT &��ȡ��ֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡ��ֵ();
      }

      const TmpU &��ȡβֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡβֵ();
      }

      protected:

      TmpU ����ֵ��;

      public:

      template<typename Tmp2T, typename Tmp2U>
      ��ֵ�� & operator = (const ��ֵ��<Tmp2T, Tmp2U> &��ֵ��) 
      noexcept
      requires(��ֵ����<TmpT, Tmp2T> &&��ֵ����<TmpU, Tmp2U>)
      {
         this->��ȡ��ֵ() = ��ֵ��.��ȡ��ֵ();
         this->��ȡβֵ() = ��ֵ��.��ȡβֵ();
         return *this;
      }
   };

   /**
    * \brief >>> ��ֵ���ػ������� TmpU����Ϊ�����Ͳ��ҿɼ̳�ʱ����ֱ��˽�м̳� TmpU �Խ�ʡ�ڴ�ռ�ռ�á�
    * \brief >>> [extends] private TmpU
    */
   template<typename TmpT, ��ֵ�ɼ̳����� TmpU>
   struct ��ֵ��<TmpT, TmpU> : private TmpU
   {

      /**
       * .
       */
      ��ֵ��()
         noexcept(noexcept(��ȫĬ�Ϲ�������<TmpT> &&��ȫĬ�Ϲ�������<TmpU>))
         requires(Ĭ�Ϲ�������<TmpT> &&Ĭ�Ϲ�������<TmpU>)
      : TmpU(), ����ֵ��() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      ��ֵ��(Tmp2T &&�׸�ֵ��, Tmp2U &&β��ֵ��)
         noexcept(noexcept(��ȫ��������<TmpT, Tmp2T> &&��ȫ��������<TmpU, Tmp2U>))
         requires(��������<TmpT, Tmp2T> &&��������<TmpU, Tmp2U>)
      : TmpU(std::forward<Tmp2U>(β��ֵ��))
         , ����ֵ��(std::forward<Tmp2T>(�׸�ֵ��)) { }

      /**
       * \brief >>> ��ȡ��ֵ�е�βֵ��Ҳ���Ǳ���
       *
       * \return βֵ���á�
       */
      TmpU &��ȡβֵ() noexcept
      {
         return *this;
      }

      /**
       * \brief >>> ��ȡ��ֵ�е���ֵ��
       *
       * \return ��ֵ���á�
       */
      TmpT &��ȡ��ֵ() noexcept
      {
         return ����ֵ��;
      }

      const TmpT &��ȡ��ֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡ��ֵ();
      }

      const TmpU &��ȡβֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡβֵ();
      }

      protected:

      TmpT ����ֵ��;
      
      public:

      template<typename Tmp2T, typename Tmp2U>
      ��ֵ�� & operator = (const ��ֵ��<Tmp2T, Tmp2U> &��ֵ��) 
      noexcept
      requires(��ֵ����<TmpT, Tmp2T> &&��ֵ����<TmpU, Tmp2U>)
      {
         this->��ȡ��ֵ() = ��ֵ��.��ȡ��ֵ();
         this->��ȡβֵ() = ��ֵ��.��ȡβֵ();
         return *this;
      }
   };

   /**
    * \brief >>> ��ֵ���ػ������� STmpT �� TmpU�����Ϊ�����Ͳ��ҿɼ̳�ʱ����ֱ��˽�м̳� STmpT �� TmpU �Խ�ʡ�ڴ�ռ�ռ�á�
    * \brief >>> [extends] private STmpT, private TmpU
    */
   template<��ֵ�ɼ̳����� TmpT, ��ֵ�ɼ̳����� TmpU>
   struct ��ֵ��<TmpT, TmpU> : private TmpT, private TmpU
   {

      /**
       * .
       */
      ��ֵ��()
         noexcept(noexcept(��ȫĬ�Ϲ�������<TmpT> && ��ȫĬ�Ϲ�������<TmpU>))
         requires(Ĭ�Ϲ�������<TmpT> && Ĭ�Ϲ�������<TmpU>)
      : TmpT(), TmpU() { }

      /**
       * .
       */
      template<typename Tmp2T, typename Tmp2U>
      ��ֵ��(Tmp2T &&�׸�ֵ��, Tmp2U &&β��ֵ��)
         noexcept(noexcept(��ȫ��������<TmpT, Tmp2T> && ��ȫ��������<TmpU, Tmp2U>))
         requires(��������<TmpT, Tmp2T> && ��������<TmpU, Tmp2U>)
      : TmpT(std::forward<Tmp2T>(�׸�ֵ��)), TmpU(std::forward<Tmp2U>(β��ֵ��)) { }

      /**
       * \brief >>> ��ȡ��ֵ�е���ֵ��Ҳ���Ǳ���
       *
       * \return ��ֵ���á�
       */
      TmpT &��ȡ��ֵ() noexcept
      {
         return *this;
      }

      /**   
      * \brief >>> ��ȡ��ֵ�е�βֵ��Ҳ���Ǳ���
      *
      * \return βֵ���á�
      */
      TmpU &��ȡβֵ() noexcept
      {
         return *this;
      }

      const TmpT &��ȡ��ֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡ��ֵ();
      }

      const TmpU &��ȡβֵ() const noexcept
      {
         return const_cast<��ֵ�� *>(this)->��ȡβֵ();
      }
      
      public:

      template<typename Tmp2T, typename Tmp2U>
      ��ֵ�� & operator = (const ��ֵ��<Tmp2T, Tmp2U> &��ֵ��) 
      noexcept
      requires(��ֵ����<TmpT, Tmp2T> &&��ֵ����<TmpU, Tmp2U>)
      {
         this->��ȡ��ֵ() = ��ֵ��.��ȡ��ֵ();
         this->��ȡβֵ() = ��ֵ��.��ȡβֵ();
         return *this;
      }
   };

   // ��ֵ��ģ���Ƶ���
   template<typename TmpT, typename TmpU>
   ��ֵ��(TmpT, TmpU) -> ��ֵ��<TmpT, TmpU>;

}
