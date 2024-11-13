
namespace BE {

   /**
    * \brief >>> 一种将所有数据看作为字节序进行处理的类型，允许你将任意类型的数据按字节进行读取或写入，并提供 << 和 >> 进行写入和读取。
    * \brief >>> 类通过当前有效范围表示 << 和 >> 读写位置，因此使用前使用 `设置范围` 函数设置有效范围也就是 << 和 >> 进行读写的起始位置。
    */
   struct 字节类 : protected 原始空间类<类型字节>
   {

      using 类中基类 = 原始空间类<类型字节>;

      using 类中基类::begin;
      using 类中基类::end;
      using 类中基类::获取总长度;
      using 类中基类::获取长度;
      using 类中基类::非空的;
      using 类中基类::operator bool;
      using 类中基类::operator[];
      
      // 使基类继承的错误类函数公开。
      using 类中基类::获取错误;
      using 类中基类::无错误的;
      using 类中基类::重置错误;
      using 类中基类::设置错误;

      // 默认构造函数。
      字节类() noexcept = default;

      // 释放当前并设置新的长度，使用指定值填充。
      字节类(类型长度 长度项, 类型字节 填充项 = 0) noexcept
      {
         this->赋值(长度项, 填充项);
      }

      // 释放当前并设置为目标长度，复制目标中的数据。
      字节类(const 字节类 &赋值项) noexcept
      {
         this->赋值(赋值项);
      }

      // 释放当前并获取目标中数据的所有权，清空目标。
      字节类(字节类 &&赋值项) noexcept
      {
         this->赋值(std::move(赋值项));
      }

      /**
       * \brief >>> 释放当前容器中存储的字节，并设置新的大小，用指定值填充容器。
       * 
       * \param 长度项： 要设置的长度。
       * \param 填充项： 要填充容器的值。
       * \return this &
       */
      字节类 &赋值(类型长度 长度项, 类型字节 填充项 = 0) noexcept
      {
         this->类中基类::释放();
         this->类中基类::调整有效范围(长度项);

         ::BE::填充零(this->类中基类::指针, this->当前长度);
         return *this;
      }

      /**
       * \brief >>> 释放当前字节容器中的字节，并分配新的内存空间，赋值为目标的字节数据。
       * 
       * \param 赋值项： 要赋值的字节数据。
       * \return this &
       */
      字节类 &赋值(const 字节类 &赋值项) noexcept
      {
         this->赋值(赋值项.获取长度(), 0);

         std::memcpy(this->指针, 赋值项.指针, this->获取长度());
         return *this;
      }

      /**
       * \brief >>> 将目标容器中的数据所有权移动到当前容器中并清空对象。
       * 
       * \param 赋值项： 要移动的字节数据。
       * \return this &
       */
      字节类 &赋值(字节类 &&赋值项) noexcept
      {
         this->类中基类::赋值(std::move(reinterpret_cast<类中基类 &>(赋值项)));

         return *this;
      }

      /**
       * \brief >>> 将指定对象按字节写入容器有效范围中指定索引位置。
       * 
       * \param 置入项： 要写入的字节数据。
       * \param 索引项： 要写入的索引位置，越界则函数无作为。
       * \return 实际写入的字节数。
       * \tparam TmpT： 任意类型。
       */
      template<typename TmpT>
      类型长度 写入数据(TmpT &&置入项, 类型长度 索引项) noexcept
      {
         if (索引项 >= this->获取长度())
         {
            return 0;
         }

         类型长度 置入长度 = sizeof(TmpT);

         std::memcpy(this->指针 + 索引项, &置入项, ::BE::最小值(置入长度, this->获取长度() - 索引项));

         return ::BE::最小值(置入长度, this->获取长度() - 索引项);
      }

      /**
       * \brief >>> 从字节容器有效范围中的指定索引位置读取数据到对象中。
       * 
       * \param 读取项： 要读取的对象。
       * \param 索引项： 要读取的索引位置，越界则函数无作为。
       * \return 实际读取的字节长度。
       * \tparam TmpT： 任意类型。
       */
      template<typename TmpT>
      类型长度 读取数据(TmpT &读取项, 类型长度 索引项) noexcept
      {
         if (索引项 >= this->获取长度())
         {
            return 0;
         }

         类型长度 读取长度 = sizeof(TmpT);

         std::memcpy(&读取项, this->指针 + 索引项, ::BE::最小值(读取长度, this->获取长度() - 索引项));

         return ::BE::最小值(读取长度, this->获取长度() - 索引项);
      }

      /**
       * \brief >>> 设置字节容器有效范围的长度。
       * 
       * \param 长度项： 要设置的范围长度，默认为 0，一般使用 << 写入数据后要重新读回数据需要进行此调整。
       * \return this &
       */
      字节类 &设置范围(类型长度 长度项 = 0) noexcept
      {
         this->设置有效范围(长度项);
         return *this;
      }

      /**
       * \brief >>> 获取字节容器中指向开始的指针。
       * 
       * \return 只读指针。
       */
      const 类型字节 *获取字节指针() const noexcept
      {
         return this->指针;
      }

      /**
       * \brief >>> 获取字节容器中指向开始的指针。
       * 
       * \return 指针。 
       */
      类型字节 *获取字节指针() noexcept
      {
         return this->指针;
      }

      // 拓展有效范围，并在新的有效范围中写入数据。
      template<typename TmpT>
      字节类 &operator << (TmpT &&写入项)
      noexcept
      {
         类型长度 前长度 = this->获取长度();

         this->调整有效范围(前长度 + sizeof(TmpT));
         this->写入数据(std::forward<TmpT>(写入项), 前长度);
         return *this;
      }

      // 拓展有效范围，并从新的有效范围中读取数据。
      template<typename TmpT>
      字节类 &operator >> (TmpT &读取项)
      noexcept
      {
         类型长度 前长度 = this->获取长度();

         this->调整有效范围(前长度 + sizeof(TmpT), true, false);
         this->读取数据(读取项, 前长度);
         return *this;
      }

      // 释放当前字节容器，分配新的内存空间，复制目标中的数据。
      字节类 &operator = (const 字节类 &赋值项) noexcept
      {
         return this->赋值(赋值项);
      }

      // 释放当前字节容器，获取目标中数据的所有权，清空目标。
      字节类 &operator = (字节类 &&赋值项) noexcept
      {
         return this->赋值(std::move(赋值项));
      }
   };

   /**
    * \brief >>> 翻转一个对象的底层存储字节序并将其返回，注意对于非平凡对象，使用请自行承担风险。
    * 
    * \param 目标项： 要翻转的对象。
    * \return 翻转后的对象。
    */
   template<typename TmpT>
   inline TmpT &&翻转字节序(TmpT &&目标项) noexcept
   {
      for (类型长度 起始量 = 0, 结束量 = sizeof(TmpT) - 1; 起始量 < 结束量; ++起始量, --结束量)
      {
         BE::交换(reinterpret_cast<类型字节 *>(&目标项)[起始量], reinterpret_cast<类型字节 *>(&目标项)[结束量]);
      }

      return std::forward<TmpT>(目标项);
   }

}
