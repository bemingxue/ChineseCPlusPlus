
namespace BE {

   /**
    * \brief >>> 唯一类的对值对象结构，也就是数据结构，存储指针和长度信息。
    */
   template<typename TmpT>
   struct 唯一类结构
   {
      TmpT    *指针 = 空指针;
      类型长度 长度 = 0;
   };

   /**
    * \brief >>> 一个托管具有唯一所有权指针的可迭代类，提供提供的释放器自动管理生命周期，并禁止复制操作。
    * \tparam TmpT： 要托管的类型，对于无边界数组，将自动优化为基本类型。
    * \tparam TmpCall： 用于管理指针的释放器类型，默认使用 delete ，可以给 STmpT 添加无边界数组修饰符，类将默认选用 delete[]，要自主提供则应当满足 TmpCall(STmpT *, 类型长度) 安全调用条件，并且可安全默认构造与移动。
    */
   template<typename TmpT, 安全调用类型<std::add_pointer_t<std::remove_all_extents_t<TmpT>>, 类型长度> TmpCall = 默认内存释放类<TmpT>, typename TmpU = std::remove_all_extents_t<TmpT>>
   struct 唯一类 : /* 继承对值类以优化内存空间占用 */ protected 对值类<唯一类结构<TmpU>, TmpCall>
   {
      // 启用全局运算符。
      using EGO = void;

      // 以当前存储的指针作为迭代器，注意空指针。
      TmpU *begin() noexcept { return this->获取指针(); }
      TmpU *end() noexcept { return this->获取指针() + this->获取长度(); }

      // 以当前存储的指针作为迭代器，注意空指针。
      const TmpU *begin() const noexcept { return this->获取指针(); }
      const TmpU *end() const noexcept { return this->获取指针() + this->获取长度(); }

      // 默认构造函数。
      唯一类() noexcept
      {

      }

      // 赋值释放器的构造函数。
      唯一类(TmpCall 调用项) noexcept
      {
         this->获取尾值() = 调用项;
      }

      // 移动构造函数。
      唯一类(唯一类 &&赋值项) noexcept
      {
         this->赋值(std::move(赋值项));
      }

      // 赋值指针、长度和释放器，释放器默认使用默认构造的。
      唯一类(TmpU *指针项, 类型长度 长度项, TmpCall 调用项 = TmpCall { }) noexcept
      {
         this->获取尾值() = 调用项;
         this->赋值(指针项, 长度项);
      }

      // 复制构造函数，不可使用。
      唯一类(const 唯一类 &) noexcept = delete;

      /**
       * \brief >>> 将指针赋值到当前对象中，并提供指针指向内存块的长度信息。
       * 
       * \param 指针项： 要赋值的指针，可以是和当前存储的相同的指针。
       * \param 长度项： 指针指向内存块的长度，如果指针项是空指针则总是赋值 0。
       * \return this &
       */
      唯一类 &赋值(TmpU *指针项, 类型长度 长度项) noexcept
      {
         this->获取首值().指针 = 指针项;
         this->获取首值().长度 = 指针项 == 空指针 ? 0 :长度项;
         return *this;
      }

      /**
       * \brief >>> 获取目标指针、长度以及释放器的所有权，并置空目标。
       * 
       * \param 赋值项： 要移交所有权的对象，如果是自己则函数无作为。
       * \return this &
       */
      唯一类 &赋值(唯一类 &&赋值项) noexcept
      {
         // 自己赋值给自己，无作为。
         if (::BE::比较地址(*this, 赋值项) == 0)
         {
            return *this;
         }

         this->获取首值() = ::BE::交换赋值(赋值项.获取首值(), 唯一类结构<TmpU>{ });
         this->获取尾值() = ::BE::交换赋值(赋值项.获取尾值(), TmpCall{ });
         return *this;
      }

      /**
       * \brief >>> 获取当前对象存储的释放器。
       * 
       * \return 释放器引用。
       */
      TmpCall &获取释放器() noexcept
      {
         return this->获取尾值();
      }

      /**
       * \brief >>> 使当前对象结束对指针的托管，不进行释放而将其返回，因此请自行管理指针的生命周期。
       * 
       * \return 托管的指针，没有托管时为空指针。
       */
      TmpU *结束托管() noexcept
      {
         TmpU *返回值 = ::BE::交换赋值(this->获取首值().指针, 空指针);
         
         this->获取首值().长度 = 0;

         return 返回值;
      }

      /**
       * \brief >>> 获取当前对象存储的指针。
       * 
       * \return 指针。
       */
      TmpU *获取指针() noexcept
      {
         return this->获取首值().指针;
      }

      /**
       * \brief >>> 获取当前对象存储的指针。
       * 
       * \return 只读指针。
       */
      const TmpU *获取指针() const noexcept
      {
         return this->获取首值().指针;
      }

      /**
       * \brief >>> 获取赋值时提供的长度信息。
       * 
       * \return 长度信息。
       */
      类型长度 获取长度() const noexcept
      {
         return this->获取首值().长度;
      }

      /**
       * \brief >>> 判断两者存储的指针是否相同。
       * 
       * \param 比较项： 要比较的对象。
       * \return 相同则返回真，否则假。
       */
      类型逻辑 相等判断(const 唯一类 &比较项) const noexcept
      {
         return this->获取指针() == 比较项.获取指针();
      }

      /**
       * \brief >>> 判断当前对象托管的指针与目标指针是否相同。
       * 
       * \param 比较项： 要比较的指针。
       * \return 相同则返回真，否则假。
       */
      类型逻辑 相等判断(const void *比较项) const noexcept
      {
         return this->获取指针() == 比较项;
      }

      /**
       * \brief >>> 比较两者存储的指针值。
       * 
       * \param 比较项： 要比较的对象。
       * \return 如果当前指针大于目标的指针则返回大于零的数，相等则返回零，否则返回小于零的数。
       */
      类型比较 比较判断(const 唯一类 &比较项) const noexcept
      {
         return this->获取指针() - 比较项.获取指针();
      }

      /**
       * \brief >>> 比较当前对象托管的指针值与目标指针值。
       * 
       * \param 比较项： 要比较的指针。
       * \return 如果当前指针大于目标的指针则返回大于零的数，相等则返回零，否则返回小于零的数。
       */
      类型比较 比较判断(const void *比较项) const noexcept
      {
         return this->获取指针() - 比较项;
      }

      /**
       * \brief >>> 调用释放器处理存储的指针后，将指针和长度置空。
       * 
       * \return this &
       */
      唯一类 &释放() noexcept
      {
         this->获取尾值()(this->获取首值().指针, this->获取首值().长度);
         this->获取首值().指针 = 空指针;
         this->获取首值().长度 = 0;
         return *this;
      }

      /**
       * \brief >>> 交换两者存储的指针、长度和释放器。
       * 
       * \param 交换项： 要进行交换的对象。
       * \return this &
       */
      唯一类 &交换(唯一类 &交换项) noexcept
      {
         ::BE::交换(this->获取首值(), 交换项.获取首值());
         ::BE::交换(this->获取尾值(), 交换项.获取尾值());
         return *this;
      }

      /**
       * \brief >>> 判断当前存储的指针是否为空指针。
       * 
       * \return 不是空指针则返回真，否则假。
       */
      类型逻辑 非空的() const noexcept
      {
         return this->获取指针() != 空指针;
      }

      // 安全析构函数，调用释放函数。
      ~唯一类() noexcept
      {
         this->释放();
      }

      // 禁止复制赋值，防止误用。
      唯一类 &operator = (const 唯一类 &) noexcept = delete;

      // 移动赋值，交换指针、长度和释放器。
      唯一类 &operator = (唯一类 &&赋值项) noexcept
      {
         this->赋值(std::move(赋值项));
         return *this;
      }

      // 赋值空指针直接释放并置空当前托管的指针。
      唯一类 &operator = (类型空值) noexcept
      {
         this->释放();
         return *this;
      }

      // 获取存储的指针，注意空指针。
      TmpU *operator -> () noexcept
      {
         return this->获取指针();
      }

      // 获取存储的只读指针，注意空指针。
      const TmpU *operator -> () const noexcept
      {
         return this->获取指针();
      }

      // 获取存储的指针指向的内存块中的第 n 个元素引用，注意空指针和越界。
      TmpU &operator [] (类型长度 索引项) noexcept
      {
         return this->获取指针()[索引项];
      }

      // 获取存储的指针指向的内存块中的第 n 个元素只读引用，注意空指针和越界。
      const TmpU &operator [] (类型长度 索引项) const noexcept
      {
         return this->获取指针()[索引项];
      }

      // 当前存储的指针不是空指针则返回真，否则假。
      explicit operator 类型逻辑 () const noexcept
      {
         return this->非空的();
      }

   };

}
