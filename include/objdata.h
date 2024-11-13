
namespace BE {

   /**
    * \brief >>> 提供一个允许你操控一个对象底层比特数据的可迭代类型，可以是数组、标准类型、类类型等等，类不允许默认构造，因为你不能操控一个空的对象，但类允许你重新赋值或者复制赋值、构造等。
    * \brief >>> 如果操控一个类类型对象，请注意内存对齐产生的额外字节空间，对于非平凡类型，也请注意其内部存储的虚函数表等数据，如果修改到这些，类不保证此安全
    * \brief >>> 另外，由于该类使用指针操控对象，因此请注意对象的生命周期，如果对象生命周期结束则在重赋值之前都不应当在此使用类中的函数。
    * \tparam STmpT： 要操控的对象类型。
    */
   template<对象类型 STmpT>
   struct 对象字节类
   {

      using 基准类 = T::U8;

      // STmpT 所占用的字节数。
      static constexpr 类型长度 对象占用 = sizeof(STmpT);
      // STmpT 所占用的比特数。
      static constexpr 类型长度 对象比特 = sizeof(STmpT) * 8;
      // 基准类型所占用的字节数。
      static constexpr 类型长度 基准占用 = sizeof(基准类);
      // 基准类型所占用的比特数。
      static constexpr 类型长度 基准比特 = sizeof(基准类) * 8;

      // 只读的比特类，也用于只读迭代器。
      struct 只读比特类
      {
         // 启用全局运算符。
         using EGO = void;

         只读比特类(const 只读比特类 &) noexcept = default;

         /**
          * \brief >>> 判断目标和当前的对象与索引是否相同。
          * 
          * \param 判断项： 要判断的项。
          * \return 相等则返回真，否则返回假。
          */
         类型逻辑 相等判断(const 只读比特类 &判断项) const noexcept
         {
            return this->类中对象 == 判断项.类中对象 && this->类中索引 == 判断项.类中索引;
         }

         /**
          * \brief >>> 比较两者的对象和索引，如果对象相同则比较索引，否则比较对象。
          * 
          * \param 判断项： 要比较的项。
          * \return 大于则返回大于零的值，等于则返回零，小于则返回小于零的值。
          */
         类型比较 比较判断(const 只读比特类 &判断项) const noexcept
         {
            return this->类中对象 == 判断项.类中对象 ? (this->类中索引 > 判断项.类中索引 ? 1 : this->类中索引 < 判断项.类中索引 ? -1 : 0) : (this->类中对象 > 判断项.类中对象 ? 1 : this->类中对象 < 判断项.类中对象 ? -1 : 0);
         }

         /**
          * \brief >>> 获取存储的索引值。
          * 
          * \return 索引。
          */
         类型长度 获取索引() const noexcept
         {
            return this->类中索引;
         }

         protected:

         struct 可写比特类;
         friend 对象字节类;
         friend 可写比特类;

         mutable STmpT  *类中对象;
         mutable 类型长度 类中索引;

         只读比特类(STmpT *对象项, 类型长度 索引项) noexcept 
            : 类中对象(对象项)
            , 类中索引(索引项)
         {

         }

         public:

         // 模拟迭代器解引用功能，使其成为一个迭代器。
         只读比特类 &operator * () noexcept
         {
            return *this;
         }

         // 增加索引值。
         只读比特类 &operator ++ () noexcept
         {
            return this->类中索引 += 1, *this;
         }

         // 减少索引值。
         只读比特类 &operator -- () noexcept
         {
            return this->类中索引 -= 1, *this;
         }

         // 允许转换为布尔类型的值。
         explicit operator bool() const noexcept
         {
            return !!::BE::获取位块(*(reinterpret_cast<const 基准类 *>(this->类中对象) + (this->类中索引 / 基准比特)), this->类中索引 % 基准比特, 1);
         }
      };

      struct 可写比特类
      {
         // 启用全局运算符。
         using EGO = void;

         可写比特类(const 可写比特类 &) noexcept = default;

         /**
          * \brief >>> 判断两个的指向的对象和索引是否相同。
          * 
          * \param 判断项： 要判断的项。
          * \return 相同则返回真，否则返回假。
          */
         类型逻辑 相等判断(const 可写比特类 &判断项) const noexcept
         {
            return this->类中对象 == 判断项.类中对象 && this->类中索引 == 判断项.类中索引;
         }

         /**
          * \brief >>> 比较两者的对象和索引，如果对象相同则比较索引，否则比较对象。
          * 
          * \param 判断项： 要比较的项。
          * \return 大于则返回大于零的值，等于则返回零，小于则返回小于零的值。
          */
         类型比较 比较判断(const 可写比特类 &判断项) const noexcept
         {
            return this->类中对象 == 判断项.类中对象 ? (this->类中索引 > 判断项.类中索引 ? 1 : this->类中索引 < 判断项.类中索引 ? -1 : 0) : (this->类中对象 > 判断项.类中对象 ? 1 : this->类中对象 < 判断项.类中对象 ? -1 : 0);
         }

         /**
          * \brief >>> 获取当前比特所在对象的索引。
          * 
          * \return 索引。
          */
         类型长度 获取索引() const noexcept
         {
            return this->类中索引;
         }

         protected:

         friend 对象字节类;

         mutable STmpT  *类中对象;
         mutable 类型长度 类中索引;

         可写比特类(STmpT *对象项, 类型长度 索引项) noexcept 
            : 类中对象(对象项)
            , 类中索引(索引项)
         {

         }

         public:

         // 模拟迭代器解引用功能，使其成为一个迭代器。
         可写比特类 &operator * () noexcept
         {
            return *this;
         }

         // 增加索引值。
         可写比特类 &operator ++ () noexcept
         {
            return this->类中索引 += 1, *this;
         }

         // 减少索引值。
         可写比特类 &operator -- () noexcept
         {
            return this->类中索引 -= 1, *this;
         }

         // 设置当前索引表示的比特的值。
         可写比特类 &operator = (bool 赋值项) noexcept
         {
            ::BE::设置位块(*(reinterpret_cast<基准类 *>(this->类中对象) + (this->类中索引 / 基准比特)), this->类中索引 % 基准比特, 1, 赋值项);

            return *this;
         }

         // 允许转换为布尔类型的值。
         explicit operator bool() const noexcept
         {
            return !!::BE::获取位块(*(reinterpret_cast<基准类 *>(this->类中对象) + (this->类中索引 / 基准比特)), this->类中索引 % 基准比特, 1);
         }

         // 允许隐式转换为只读比特类。
         operator 只读比特类() const noexcept
         {
            return 只读比特类(类中对象, 类中索引);
         }

      };

      // 使用专属迭代器类型进行迭代。
      可写比特类 begin() noexcept { return 可写比特类(类中对象, 0); }
      可写比特类 end()   noexcept { return 可写比特类(类中对象, 对象比特); }
      // 使用专属迭代器类型进行迭代。
      只读比特类 begin() const noexcept { return 只读比特类(类中对象, 0); }
      只读比特类 end()   const noexcept { return 只读比特类(类中对象, 对象比特); }

      // 构造函数，存储一个左值对象的指针。
      对象字节类(STmpT &赋值项) noexcept : 类中对象(&赋值项) 
      {
      
      }

      /**
       * \brief >>> 获取存储的对象的指针。
       * 
       * \return 对象的指针。
       */
      STmpT &获取对象() noexcept
      {
         return *类中对象;
      }

      /**
       * \brief >>> 获取 STmpT 所占用的比特总数，也就是迭代范围的最大范围。
       * 
       * \return 比特数。
       */
      static consteval 类型长度 获取长度() noexcept
      {
         return 对象比特;
      }

      protected:

      STmpT *类中对象;

      public:

      // 允许重新赋值，使其存储另一个左值对象的指针。
      对象字节类 &operator = (STmpT &赋值项) noexcept
      {
         类中对象 = &赋值项;

         return *this;
      }

      // 获取指定索引处的比特值，注意越界操作。
      可写比特类 operator [] (类型长度 索引量) noexcept
      {
         return 可写比特类(类中对象, 索引量);
      }

      // 获取指定索引处的比特值，注意越界操作。
      只读比特类 operator [] (类型长度 索引量) const noexcept
      {
         return 只读比特类(类中对象, 索引量);
      }
   };
   
   /**
    * \brief >>> 获取一个对象的底层字节序，并允许你访问和修改它。
    * 
    * \param 获取项： 要获取的对象。
    * \return 一个对象字节类对象
    */
   template<对象类型 TmpT>
   对象字节类<TmpT> 获取字节序(TmpT &获取项) noexcept
   {
      return 对象字节类<TmpT>(获取项);
   }

}
