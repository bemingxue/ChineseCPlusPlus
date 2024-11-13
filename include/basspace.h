
namespace BE {

   /**
    * \brief >>> 负责管理一片从内存中分配的空间的生命周期的可迭代类型，每次诞生新元素都将构造，每次删除或移出有效范围都将析构元素，不支持复制只能移动。
    * \brief >>> 虽然继承自原始空间类，但与原始空间类不满足多态性，不建议将其指针赋值给原始空间类指针，即使赋值也不应当使用会修改内存空间相关的函数。
    * \brief >>> 类型提供有效范围和无效范围支持，迭代器迭代有效范围。
    * \brief >>> 注意，如果分配内存失败则类会设置错误信息。
    * \brief >>> 继承自：原始空间类。
    * \tparam TmpT： 元素类型，最好能够支持安全移动构造和安全默认构造。
    */
   template<typename TmpT>
   struct 基本空间类 : /* 继承原始空间类简化一些操作 */ 原始空间类<TmpT>
   {
      // 当前类的基类别名。
      using 类中基类 = 原始空间类<TmpT>;

      // 默认构造函数。
      基本空间类() noexcept : 类中基类()
      {

      }

      // 从内存中分配指定长度的内存块但不进行构造。
      基本空间类(类型长度 长度项) noexcept : 类中基类(长度项)
      {

      }

      // 获取目标对象存储的数据的所有权，并清空对象。
      基本空间类(基本空间类 &&赋值项) noexcept : 类中基类(std::move(赋值项))
      {

      }

      // 复制构造函数，禁止使用。
      基本空间类(const 基本空间类 &) = delete;

      /**
       * \brief >>> 从内存中分配指定长度的内存块并对其中每个元素进行构造，并设置所有长度为长度项的值，如果内存分配失败则设置错误并结束函数。
       * 
       * \param 长度项： 指定分配的内存块的长度，如果和当前相同则直接重新构造。
       * \param 构造参数表： 传递给构造函数的参数表。
       * \return this &
       * \tparam TmpArgs： 能够被 STmpT 构造函数接受的类型表。
       */
      template<typename... TmpArgs>
      基本空间类 &赋值(类型长度 长度项, TmpArgs&&... 构造参数表) /* 覆写基类的赋值函数 */
      noexcept(noexcept(安全构造类型<TmpT, TmpArgs...>))
      requires(构造类型<TmpT, TmpArgs...>)
      {
         // 如果长度和当前总长度相同则直接重新构造所有元素。
         if (长度项 == this->获取总长度())
         {
            ::BE::重新构造(this->指针, 长度项, std::forward<TmpArgs>(构造参数表)...);
         }

         else
         {
            this->释放内存(this->指针, this->获取长度());

            // 检查内存分配是否成功。
            if (!(this->指针 = this->分配内存(长度项)))
            {
               this->设置错误(::BE::错误集::内存分配错误);

               this->总长度 = this->当前长度 = 0;
               return *this;
            }

            ::BE::直接构造(this->指针, 长度项, std::forward<TmpArgs>(构造参数表)...);
         }

         this->总长度 = this->当前长度 = 长度项;
         return *this;
      }

      /**
       * \brief >>> 将目标存储的数据所有权移动到当前对象中，并置空目标存储。
       * 
       * \param 赋值项： 要移动的对象。
       * \return this &
       */
      基本空间类 &赋值(基本空间类 &&赋值项) noexcept
      {
         this->类中基类::赋值(std::move(赋值项));
         return *this;
      }

      /**
       * \brief >>> 从内存中分配指定长度的内存块，但不对其中元素进行构造，只设置总长度而将当前长度归零，如果内存分配失败则设置错误并结束函数。
       * 
       * \param 长度项： 指定分配的内存块的长度。
       * \return this &
       */
      基本空间类 &赋值不构造(类型长度 长度项) noexcept
      {
         this->类中基类::赋值(长度项);
         return *this;
      }

      /**
       * \brief >>> 设置有效范围的长度，如果是扩充则构造元素，如果是缩减则析构元素，如果相同则无作为。
       * 
       * \param 长度项： 指定有效范围的长度。
       * \param 构造参数表： 传递给构造函数的参数表，对于缩减可以不提供，但这也意味 STmpT 必须能够默认构造。
       * \return this &
       * \tparam TmpArgs： 能够被 STmpT 构造函数接受的类型表。
       */
      template<typename... TmpArgs>
      基本空间类 &设置有效范围(类型长度 长度项, TmpArgs&&... 构造参数表) /* 覆写基类的设置有效范围 */
      noexcept(noexcept(安全构造类型<TmpT, TmpArgs...>))
      requires(构造类型<TmpT, TmpArgs...>)
      {
         // 如果长度项大于总长度则不做任何操作。
         if (长度项 > this->获取总长度())
         {
            return *this;
         }
         // 长度项大于时构造多出来的元素。
         else if (长度项 > this->获取长度())
         {
            ::BE::直接构造(this->获取指针() + this->获取长度(), 长度项 - this->获取长度(), std::forward<TmpArgs>(构造参数表)...);
         }
         // 长度项小于时析构多出来的元素。
         else if (长度项 < this->获取长度())
         {
            ::BE::直接析构(this->获取指针() + 长度项, this->获取长度() - 长度项);
         }

         // 对于长度项等于当前长度的情况，不做任何操作。
         this->当前长度 = 长度项;
         return *this;
      }

      /**
       * \brief >>> 设置有效范围的长度，如果大于当前总长度则分配新内存，并移动原来的数据到新内存中（这要求 STmpT 支持移动构造），构造新元素，释放旧内存，否则只构造或析构元素。
       * \brief >>> 如果内存分配失败则设置错误并结束函数。
       * 
       * \param 长度项： 指定有效范围的长度。
       * \param 构造参数表： 传递给构造函数的参数表，对于缩减可以不提供，但这也意味 STmpT 必须能够默认构造。
       * \return this &
       * \tparam TmpConstruct： 是否构造新的内存空间。
       * \tparam TmpArgs： 能够被 STmpT 构造函数接受的类型表。
       */
      template<类型逻辑 TmpConstrcut = true, typename... TmpArgs>
      基本空间类 &调整有效范围(类型长度 长度项, TmpArgs&&... 构造参数表) /* 覆写基类的调整有效范围 */
      noexcept(noexcept((安全构造类型<TmpT, TmpArgs...> || !TmpConstrcut) && 安全移动构造类型<TmpT>))
      requires((构造类型<TmpT, TmpArgs...> || !TmpConstrcut) && 移动构造类型<TmpT>)
      {
         if (长度项 > this->获取总长度())
         {
            类型长度 原长度 = this->获取长度();
            // 结束管理会置空长度。
            TmpT *备份 = this->结束管理();
            
            // 判断是否分配内存失败。
            if (!(this->指针 = this->分配内存(长度项)))
            {
               this->设置错误(::BE::错误集::内存分配错误);
               return *this;
            }

            // 移动原来的数据到新内存中。
            ::BE::移动构造(this->指针, 备份, 原长度);

            if constexpr (TmpConstrcut)
            {
               // 构造新元素。
               ::BE::直接构造(this->指针 + 原长度, 长度项 - 原长度, std::forward<TmpArgs>(构造参数表)...);
            }

            this->释放内存(备份, 原长度);
            this->总长度 = this->当前长度 = 长度项;
         }
         // 对于缩减、扩充、相同的情况，交由设置有效范围函数处理。
         else
         {
            this->设置有效范围(长度项, std::forward<TmpArgs>(构造参数表)...);
         }

         return *this;
      }

      /**
       * \brief >>> 析构有效范围内的原始，并释放当前存储的所有内存，置空对象。
       * 
       * \return this &
       */
      基本空间类 &释放() noexcept /* 覆写基类的释放 */
      {
         ::BE::直接析构(this->指针, this->获取长度());
         
         this->类中基类::释放();
         
         return *this;
      }

      // 安全析构函数，负责析构元素。
      ~基本空间类() noexcept
      {
         // 析构所有有效范围内的元素，释放交由基类负责。
         ::BE::直接析构(this->指针, this->获取长度());
      }

      // 复制赋值运算符，禁止使用。
      基本空间类 &operator = (const 基本空间类 &) = delete;

      // 获取目标对象存储的数据的所有权，并清空对象。
      基本空间类 &operator = (基本空间类 &&赋值项) noexcept
      {
         return this->赋值(std::move(赋值项));
      }

      protected:

      // 析构指定长度的元素并释放内存。
      类型空的 释放内存(TmpT *指针项, 类型长度 长度项) noexcept /* 覆写基类的释放内存 */
      {
         ::BE::直接析构(指针项, 长度项);
         ::BE::释放原始内存(指针项);
      }
   };

}
