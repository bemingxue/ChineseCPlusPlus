
namespace BE {
   
   struct 字符串类;

   template<typename TmpT>
   struct 转字符串类 { };

   template<typename TmpT>
   concept 可转字符串类型 = requires(const TmpT & X) {
      { 转字符串类<TmpT>()(X) } -> 相同类型<字符串类>;
   };

   /**
    * \brief >>> 函数库中处理字符串的基本类型，从栈上分配内存并存储字符串，管理其生命周期。
    * \brief >>> 提供基本的字符串处理操作，可以赋值为任意字符类型的字符串，并允许转换为字符视图类型，如果要进行比较操作等应当尽可能使用字符视图进行。
    */
   struct 字符串类 : protected 原始空间类<类型字符>
   {
      // 启用全局运算符。
      using EGO = void;

      // 当前类的基类别名。
      using 类中基类 = 原始空间类<类型字符>;
      // 和字符串类相对应的 STL 标准字符串类别名。
      using 标准字符串类 = std::basic_string<类型字符>;

      // 直接提供基类的下标运算符即可。
      using 类中基类::operator[];

      // 使基类继承的错误类函数公开。
      using 类中基类::获取错误;
      using 类中基类::无错误的;
      using 类中基类::重置错误;
      using 类中基类::设置错误;

      using 类中基类::非空的;

      // 能够将字符串转换为其他 STL 标准字符串类型的函数类型。
      template<字符类型 TmpT>
      using 字符串转换函数 = std::basic_string<TmpT>(std::filesystem::path:: *)() const;

      // 表示转换为 STL string 字符串类型的函数指针。
      static constexpr 字符串转换函数<char>     窄字符   = &std::filesystem::path::string;
      // 表示转换为 STL wstring 字符串类型的函数指针。
      static constexpr 字符串转换函数<wchar_t>  宽字符   = &std::filesystem::path::wstring;
      // 表示转换为 STL u8string 字符串类型的函数指针。
      static constexpr 字符串转换函数<char8_t>  统一字符 = &std::filesystem::path::u8string;
      // 表示转换为 STL u16string 字符串类型的函数指针。
      static constexpr 字符串转换函数<char16_t> 宽16字符 = &std::filesystem::path::u16string;
      // 表示转换为 STL u32string 字符串类型的函数指针。
      static constexpr 字符串转换函数<char32_t> 宽32字符 = &std::filesystem::path::u32string;

      // 允许转字符串类操控类中所有成员。
      template<typename TmpT>
      friend struct 转字符串类;

      // 以存储的指针为迭代器，如果当前为空则返回空字符串，此时注意不要修改其中的任何内容。
      类型字符 *begin() noexcept { return const_cast<类型字符 *>(this->获取指针()); }
      类型字符 *end() noexcept { return const_cast<类型字符 *>(this->获取指针()) + this->获取长度(); }

      // 以存储的只读指针为迭代器，如果当前为空则返回空字符串。
      const 类型字符 *begin() const noexcept { return this->获取指针(); }
      const 类型字符 *end() const noexcept { return this->获取指针() + this->获取长度(); }

      // 默认构造函数。
      字符串类() noexcept : 类中基类()
      {

      }

      // 将任意字符串赋值到当前字符串对象中，长度项只有在 `赋值项` 为 `类型字符` 类型的字符串或者为 0 值时才有效。
      字符串类(字符串类型 auto &&赋值项, 类型长度 长度项 = 到末尾) noexcept
      {
         this->赋值(赋值项, 长度项);
      }

      // 将指定字符重复指定次数后赋值到当前字符串中。
      字符串类(类型字符 赋值项, 类型长度 长度项 = 1) noexcept
      {
         this->赋值(赋值项, 长度项);
      }

      // 复制构造函数。
      字符串类(const 字符串类 &赋值项) noexcept
      {
         this->赋值(赋值项);
      }

      // 移动构造函数，获取目标中数据的所有权，并清除目标。
      字符串类(字符串类 &&赋值项) noexcept
      {
         this->类中基类::赋值(std::move(static_cast<类中基类 &>(赋值项)));
      }

      // 将迭代范围中的元素赋值到当前字符串中，如果长度不为 0 或默认值到末尾，请自行保证长度项的正确性。
      template<单向迭代类型 InputT>
      字符串类(InputT 开始项, InputT 结束项, 类型长度 长度项 = 到末尾) noexcept
      requires(安全赋值类型<类型字符, 模板解引类型<InputT>>)
      {
         this->赋值(开始项, 结束项, 长度项);
      }

      // 将整数按照指定方式转为字符串并赋值。
      template<严格整数类型 TmpT>
      字符串类(TmpT 赋值项, 类型进制 进制项 = 10, 类型字符 正号项 = C('\0'), 转换枚举 额外设定项 = 转换枚举{}) noexcept
      {
         this->赋值(赋值项, 进制项, 正号项, 额外设定项);
      }

      // 将浮点数按照指定方式转为字符串并赋值。
      template<浮点类型 TmpT>
      字符串类(TmpT 赋值项, 类型长度 精度项 = 默认精度, 类型进制 进制项 = 10, 类型字符 正号项 = C('\0'), 转换枚举 额外设定项 = 转换枚举{}) noexcept
      {
         this->赋值(赋值项, 精度项, 进制项, 正号项, 额外设定项);
      }

      /**
       * \brief >>> 将任意字符串赋值到当前字符串对象，对于非 `类型字符` 类型的字符串，除了为 0 值的，否则长度项无效；如果转换失败，则会赋值为空字符串。
       * 
       * \param 赋值项： 要赋值的任意字符串对象，如果是自己则函数无作为。
       * \param 长度项： 要赋值的字符串长度，默认为所有，如果为 0 则清空当前字符串，该参数仅在 `赋值项` 为 `类型字符` 类型的字符串时或者为 0 值时有效，此外函数不检查长度的正确性。
       * \return this &
       */
      字符串类 &赋值(字符串类型 auto &&赋值项, 类型长度 长度项 = 到末尾) noexcept
      {
         if (::BE::比较地址(*this, 赋值项) == 0)
         {
            return *this;
         }

         if (长度项 == 0)
         {
            return this->清除();
         }

         // 存储值保证转换后的字符串生命周期在赋值结束之前都有效。
         标准字符串类 存储值;
         // 存储转换后的字符串。
         const 类型字符 *字符串指针 = 空指针;

         长度项 = 长度项 == 到末尾 ? ::BE::获取字符串长度(赋值项) : 长度项;

         if ((字符串指针 = 转换任意字符串(::BE::获取字符串(赋值项), 长度项, 存储值))[0] != 0)
         {
            this->调整有效范围(长度项 + 1, false);
            this->类中基类::指针[长度项] = 0;

            ::BE::复制(this->类中基类::begin(), 字符串指针, 字符串指针 + 长度项);
         }

         return *this;
      }

      /**
       * \brief >>> 将指定字符重复指定次数后赋值到当前字符串中。
       * 
       * \param 赋值项： 要赋值的字符。
       * \param 长度项： 重复的次数，默认值为 1，如果为 0 则清空当前字符串。
       * \return this &
       */
      字符串类 &赋值(类型字符 赋值项, 类型长度 长度项 = 1) noexcept
      {
         if (长度项 == 0)
         {
            return this->清除();
         }

         this->调整有效范围(长度项 + 1, false);
         this->类中基类::指针[长度项] = 0;

         ::BE::值填充(this->类中基类::begin(), this->类中基类::begin() + 长度项, 赋值项);

         return *this;
      }

      /**
       * \brief >>> 将指定迭代范围内的元素赋值到当前字符串中。
       * 
       * \param 开始项： 迭代范围的开始。
       * \param 结束项： 迭代范围的结束。
       * \param 长度项： 迭代范围的长度，默认自动计算，如果要提供请提供正确的长度，因为函数不对值不是 0 或 `到末尾` 的长度进行检查。
       * \return this &
       * \tparam InpuT： 至少满足单向迭代器需求并且其解引用类型能够安全赋值给 `类型字符` 类型。
       */
      template<单向迭代类型 InputT>
      字符串类 &赋值(InputT 开始项, InputT 结束项, 类型长度 长度项 = 到末尾) 
      noexcept
      requires(安全赋值类型<类型字符, 模板解引类型<InputT>>)
      {
         长度项 = 长度项 == 到末尾 ? ::BE::获取长度(开始项, 结束项) : 长度项;

         if (长度项 == 0)
         {
            return this->清除();
         }

         this->调整有效范围(长度项 + 1, false);
         this->类中基类::指针[长度项] = 0;

         ::BE::复制(this->类中基类::begin(), 开始项, 结束项);

         return *this;
      }

      /**
       * \brief >>> 将目标字符串中的所有数据所有权移动到当前字符串中，并清除目标字符串。
       * 
       * \param 赋值项： 要移动的目标。
       * \return this &
       */
      字符串类 &赋值(字符串类 &&赋值项) noexcept
      {
         this->类中基类::赋值(std::move(static_cast<类中基类 &>(赋值项)));
         return *this;
      }

      /**
       * \brief >>> 将指定整数按照指定方式转为字符串并赋值。
       * 
       * \param 赋值项： 要转换的整数。
       * \param 进制项： 进制值，默认为十进制，如果进制错误则设置错误并结束函数。
       * \param 正号项： 要显示的正号，如果为结束符则不显示正号。
       * \param 额外设定项： 转身的设定项，详细见 `转换枚举`。
       * \return this &
       * \tparam TmpT： 任意整数类型。
       */
      template<严格整数类型 TmpT>
      字符串类 &赋值(TmpT 赋值项, 类型进制 进制项 = 10, 类型字符 正号项 = C('\0'), 转换枚举 额外设定项 = 转换枚举{}) noexcept
      {
         if (::BE::进制集::进制判断(进制项) == 假)
         {
            this->设置错误(::BE::错误集::进制错误);
            return *this;
         }

         类型长度 所需长度 = ::BE::获取转为字符流长度(赋值项, 进制项, 正号项, 额外设定项);

         this->调整有效范围(所需长度 + 1, false);

         ::BE::转为字符流(this->指针, this->指针 + 所需长度, 赋值项, 进制项, 正号项, 额外设定项)[0] = 0;
      
         return *this;
      }

      /**
       * \brief >>> 将浮点数按照指定方式转为字符串并赋值。
       * 
       * \param 赋值项： 要转换的浮点数。
       * \param 精度项： 精度值，可以设定为很大值，函数会在特定地方自动停止，如果精度错误则设置错误并结束函数。
       * \param 进制项： 进制值，默认为十进制，如果进制错误则设置错误并结束函数。
       * \param 正号项： 要显示的正号，如果为结束符则不显示正号。
       * \param 额外设定项： 转换设定项，详细见 `转换枚举`。
       * \return this &
       * \tparam TmpT： 任意浮点类型。
       */
      template<浮点类型 TmpT>
      字符串类 &赋值(TmpT 赋值项, 类型长度 精度项 = 默认精度, 类型进制 进制项 = 10, 类型字符 正号项 = C('\0'), 转换枚举 额外设定项 = 转换枚举{})
      {
         if (::BE::进制集::进制判断(进制项) == 假)
         {
            this->设置错误(::BE::错误集::进制错误);
            return *this;
         }

         类型长度 所需长度 = ::BE::获取转为字符流长度(赋值项, 精度项, 进制项, 正号项, 额外设定项);

         this->调整有效范围(所需长度 + 1, false);

         ::BE::转为字符流(this->指针, this->指针 + 所需长度, 赋值项, 精度项, 进制项, 正号项, 额外设定项)[0] = 0;

         return *this;
      }

      /**
       * \brief >>> 从指定位置开始删除指定长度的字符串，如果长度加开始位置大于等于当前字符串长度则函数会直接进行截断。
       * 
       * \param 开始项： 开始删除的位置，如果超出当前长度则函数无作为。
       * \param 长度项： 要删除的字符数，默认为从开始到末尾，如果为 0 则函数无作为。
       * \return this &
       */
      字符串类 &删除(类型长度 开始项, 类型长度 长度项 = 到末尾) noexcept
      {
         if (开始项 >= this->获取长度() || 长度项 == 0)
         {
            return *this;
         }

         长度项 = ::BE::最小值(长度项, this->获取长度() - 开始项);

         // 如果是要删除从开始到末尾的所有，直接截断即可。
         if (长度项 + 开始项 >= this->获取长度())
         {
            this->指针[开始项] = 0;
            this->设置有效范围(开始项);
         }
         else
         {
            ::BE::复制(this->指针 + 开始项, this->指针 + 开始项 + 长度项, this->end());
            this->指针[this->获取长度() - 长度项] = 0;
            this->设置有效范围(this->获取长度() - 长度项 + 1);
         }

         return *this;
      }

      /**
       * \brief >>> 将指定字符串对象中的字符串值插入到当前字符串的指定位置。
       * 
       * \param 插入项： 要插入的字符串对象。
       * \param 开始项： 开始插入的位置，默认为到末尾，如果大于等于当前字符串长度则插入到字符串末尾。
       * \param 长度项： 要插入的字符串长度，默认为所有，该参数仅在 `插入项` 为 `类型字符` 类型的字符串或者参数值为 0 时有效。
       * \return this &
       */
      字符串类 &插入(字符串类型 auto &&插入项, 类型长度 开始项 = 到末尾, 类型长度 长度项 = 到末尾) noexcept
      {
         长度项 = 长度项 == 到末尾 ? ::BE::获取字符串长度(插入项) : 长度项;
         开始项 = ::BE::最小值(开始项, this->获取长度());

         if (长度项 == 0)
         {
            return *this;
         }

         标准字符串类 存储值;
         const 类型字符 *字符串指针 = 空指针;

         字符串指针 = 转换任意字符串(::BE::获取字符串(插入项), 长度项, 存储值);

         this->调整有效范围(this->获取长度() + 长度项 + 1, true);
         this->指针[this->获取长度()] = 0;

         ::BE::迭代插入(字符串指针, 字符串指针 + 长度项, this->指针 + 开始项, /* 原来的字符串末尾 */ this->指针 + this->获取长度() - 长度项, this->end());

         return *this;
      }

      /**
       * \brief >>> 将指定字符重复指定次数后插入到当前字符串的指定位置。
       * 
       * \param 插入项： 要插入的字符。
       * \param 重复项： 要插入的次数，默认为 1，如果为 0 则函数无作为。
       * \param 开始项： 开始插入的位置，默认为到末尾，如果大于等于当前字符串长度则插入到字符串末尾。
       * \return this &
       */
      字符串类 &插入(类型字符 插入项, 类型长度 重复项 = 1, 类型长度 开始项 = 到末尾) noexcept
      {
         开始项 = ::BE::最小值(开始项, this->获取长度());

         if (重复项 == 0)
         {
            return *this;
         }

         this->调整有效范围(this->获取长度() + 重复项 + 1, true);
         this->指针[this->获取长度()] = 0;

         ::BE::填充插入(插入项, this->指针 + 开始项, this->指针 + 开始项 + 重复项, this->指针 + this->获取长度() - 重复项, this->end());

         return *this;
      }

      /**
       * \brief >>> 如果在当前字符串中找到了目标项，则将其替换为替换项，否则无事发生。
       * 
       * \param 目标项： 要替换的目标。
       * \param 替换项： 要进行替换的字符串，可以为空字符串。
       * \return this &
       */
      字符串类 &替换(字符视图类 目标项, 字符视图类 替换项) noexcept
      {
         类型长度 索引;
         类型长度 最小长度 = ::BE::最小值(目标项.获取长度(), 替换项.获取长度());

         if ((索引 = this->获取视图().查找子串(目标项)) != 到末尾)
         {
            // 先只复制最小长度的字符串。
            ::BE::复制(this->指针 + 索引, 替换项.begin(), 替换项.begin() + 最小长度);

            // 对于替换的字符串小于目标字符串，则删除多余的字符。
            if (替换项.获取长度() < 目标项.获取长度())
            {
               this->删除(索引 + 最小长度, 目标项.获取长度() - 替换项.获取长度());
            }
            // 对于替换的字符串大于目标字符串，则插入剩余的字符。
            else if (替换项.获取长度() > 目标项.获取长度())
            {
               this->插入(替换项(最小长度), 索引 + 最小长度);
            }
         }

         return *this;
      }

      /**
       * \brief >>> 将当前字符串转换为原始字符串样式的副本并返回，即将所有需要使用转移字符表示的字符替换为对应的表示方式，如 `'` 替换为 '\\''
       * 
       * \return 转义后的字符串。
       */
      字符串类 转为原始字符串() const noexcept
      {
         字符串类 返回值;

         for (auto &迭代量 : *this)
         {
            switch (迭代量)
            {
               case C('\r'):
                  返回值.插入(C("\\r"));
                  break;
               case C('\n'):
                  返回值.插入(C("\\n"));
                  break;
               case C('\t'):
                  返回值.插入(C("\\t"));
                  break;
               case C('\"'):
                  返回值.插入(C("\\\""));
                  break;
               case C('\\'):
                  返回值.插入(C("\\\\"));
                  break;
               case C('\''):
                  返回值.插入(C("\\\'"));
                  break;
               default:
                  返回值.插入(迭代量);
                  break;
            }
         }

         return 返回值;
      }

      /**
       * \brief >>> 获取一个当前字符串的副本。
       * 
       * \return 当前字符串对象的副本。
       */
      字符串类 获取副本() const noexcept
      {
         return 字符串类(this->获取视图());
      }

      /**
       * \brief >>> 从左开始填充指定数量的字符直到字符串长度达到指定长度。
       * 
       * \param 长度项： 要填充到的长度，如果当前长度已经超出长度则函数无作为。
       * \param 填充项： 要填充的字符，默认为空格。
       * \return this &
       */
      字符串类 &从左填充(类型长度 长度项, 类型字符 填充项 = C(' ')) noexcept
      {
         for (类型长度 填充量 = 0; ; ++填充量)
         {
            if (this->获取长度() + 填充量 >= 长度项)
            {
               return this->插入(填充项, 填充量, 0);
            }
         }
      }

      /**
       * \brief >>> 从字符串末尾开始填充指定数量的字符直到字符串长度达到指定长度。
       * 
       * \param 长度项： 要填充到的长度，如果当前长度已经超出长度则函数无作为。
       * \param 填充项： 要填充的字符，默认为空格。
       * \return this &
       */
      字符串类 &从右填充(类型长度 长度项, 类型字符 填充项 = C(' ')) noexcept
      {
         for (类型长度 填充量 = 0; ; ++填充量)
         {
            if (this->获取长度() + 填充量 >= 长度项)
            {
               return this->插入(填充项, 填充量, 到末尾);
            }
         }
      }

      /**
       * \brief >>> 从左开始截取指定长度的字符串。
       * 
       * \param 长度项： 要截取的字符数，如果大于等于当前长度则相当于本身。
       * \return 新字符串。
       */
      字符串类 从左截取(类型长度 长度项) const noexcept
      {
         return this->获取视图().从左截取(长度项);
      }

      /**
       * \brief >>> 从末尾开始截取指定长度的字符串。
       * 
       * \param 长度项： 要截取的字符数，如果大于等于当前长度则相当于本身。
       * \return 新字符串。
       */
      字符串类 从右截取(类型长度 长度项) const noexcept
      {
         return this->获取视图().从右截取(长度项);
      }

      /**
       * \brief >>> 从指定位置开始截取指定长度的字符串。
       * 
       * \param 开始项： 开始截取的位置，如果超出当前长度则函数会直接返回空字符串。
       * \param 长度项： 要截取的字符数，默认为从开始到末尾，为 0 则返回空字符串。
       * \return 新字符串。
       */
      字符串类 截取(类型长度 开始项, 类型长度 长度项 = 到末尾) const noexcept
      {
         return this->获取视图().截取(开始项, 长度项);
      }

      /**
       * \brief >>> 获取存储字符串的指针，如果是空指针则返回空字符串。
       * 
       * \return 存储字符串的只读指针。
       */
      const 类型字符 *获取指针() const noexcept /* 覆写基类获取指针函数 */
      {
         return this->类中基类::获取指针() == 空指针 ? C("") : this->类中基类::获取指针();
      }

      /**
       * \brief >>> 让当前对象不再维护内部存储空间，并将其返回，由调用者负责管理空间的生命周期，注意如果没有存储数据会返回空指针。
       * 
       * \return 内部指针。
       */
      类型字符 *结束管理() noexcept /* 覆写基类结束管理函数 */
      {
         return this->类中基类::结束管理();
      }

      /**
       * \brief >>> 获取视图并设置视图的区分大小写属性。
       * 
       * \param 区分大小写否： 视图是否区分大小写匹配，默认为真。
       * \return 当前存储字符串的视图。
       */
      字符视图类 获取视图(类型逻辑 区分大小写否 = 真) const noexcept
      {
         return 字符视图类(this->获取指针(), this->获取长度(), 区分大小写否);
      }

      /**
       * \brief >>> 获取字符串长度，不包含结束符。
       * 
       * \return 字符串长度。
       */
      类型长度 获取长度() const noexcept /* 覆写基类获取长度函数 */
      {
         return this->类中基类::获取长度() == 0 ? 0 : this->类中基类::获取长度() - 1;
      }

      /**
       * \brief >>> 获取当前字符串对象指针中总共占用的内存块长度，包含结束符。
       * 
       * \return 总长度。
       */
      类型长度 获取总长度() const noexcept /* 覆写基类获取总长度函数 */
      {
         return this->类中基类::获取总长度();
      }
      
      /**
       * \brief >>> 判断两个字符串对象是否相等。
       * 
       * \param 比较项： 要比较的视图。
       * \return 相等则返回真，否则返回假。
       */
      类型逻辑 相等判断(const 字符视图类 &比较项) const noexcept
      {
         // error：期望调用视图的等于运算符但这里实际调用的字符串类相等运算符造成死循环。
         // *this == 比较项;

         return this->获取视图() == 比较项;
      }

      /**
       * \brief >>> 比较两个字符串对象，如果长度相等则比较他们的哈希码。
       * 
       * \param 比较项： 要比较的视图。
       * \return 当前字符串对象大于目标则返回大于零的值，等于则返回零，否则返回小于零的值。
       */
      类型比较 比较判断(const 字符视图类 &比较项) const noexcept
      {
         return this->获取视图().比较判断(比较项);
      }

      /**
       * \brief >>> 清除字符串内容，其实际就是将长度置为零。
       * 
       * \return this &
       */
      字符串类 &清除() noexcept /* 覆写基类清除函数 */
      {
         this->设置有效范围(0);
         return *this;
      }

      /**
       * \brief >>> 将当前存储的字符串转换为 STL 字符串类型，如果转换失败则返回空字符串并设置错误。
       * 
       * \param 调用项： 要转换的目标，使用当前类中已经定义好的各项静态成员即可。
       * \return 转换后的字符串。
       */
      template<字符类型 TmpChar>
      std::basic_string<TmpChar> 转为标准字符串(字符串转换函数<TmpChar> 调用项) const noexcept
      {
         try {
            return (std::filesystem::path(this->获取指针()).*调用项)();
         } catch (...) {
            this->设置错误(::BE::错误集::转换错误);
            return std::basic_string<TmpChar>();
         }
      }

      // 获取任意字符串类型中的字符串。
      字符串类 &operator = (字符串类型 auto &&赋值项) noexcept
      {
         return this->赋值(赋值项);
      }

      // 复制赋值运算符。
      字符串类 &operator = (const 字符串类 &赋值项) noexcept
      {
         return this->赋值(赋值项);
      }

      // 移动赋值运算符，获取目标中数据的所有权，并清除目标。
      字符串类 &operator = (字符串类 &&赋值项) noexcept
      {
         return this->赋值(std::move(赋值项));
      }

      // 将指定字符赋值到当前字符串中。
      字符串类 &operator = (类型字符 赋值项) noexcept
      {
         return this->赋值(赋值项, 1);
      }

      // 将指定字符串对象插入到当前字符串末尾。
      字符串类 &operator += (字符串类型 auto &&插入项) noexcept
      {
         return this->插入(插入项);
      }

      // 将指定字符插入到当前字符串末尾。
      字符串类 &operator += (类型字符 插入项) noexcept
      {
         return this->插入(插入项);
      }

      // 允许将任意可转为字符串类的类型插入到当前字符串末尾。
      template<可转字符串类型 TmpT>
      requires(!相同类型<TmpT, 类型字符> && !字符串类型<TmpT>)
      字符串类 &operator += (TmpT &&插入项) noexcept
      {
         return this->插入(转字符串类<TmpT>()(std::forward<TmpT>(插入项)));
      }

      // 将指定字符串对象插入到当前字符串的末尾，相比于 += 支持链式使用。
      字符串类 &operator << (字符串类型 auto &&插入项) noexcept
      {
         return this->插入(插入项);
      }

      // 将指定字符插入到当前字符串的末尾，相比于 += 支持链式使用。
      字符串类 &operator << (类型字符 插入项) noexcept
      {
         return this->插入(插入项);
      }

      // 允许将任意可转为字符串类的类型插入到当前字符串的末尾，相比于 += 支持链式使用。
      template<可转字符串类型 TmpT>
      requires(!相同类型<TmpT, 类型字符> && !字符串类型<TmpT>)
      字符串类 &operator << (TmpT &&插入项) noexcept
      {
         return this->插入(转字符串类<TmpT>()(std::forward<TmpT>(插入项)));
      }

      // 允许隐式转换为字符视图类型，这是无过多开销的。
      operator 字符视图类() const noexcept
      {
         return this->获取视图();
      }

      // 如果长度不为零且无错误则返回真，否则返回假。
      explicit operator 类型逻辑() const noexcept
      {
         return this->获取长度() != 0 && this->无错误的();
      }

      protected:

      // 将任意字符串指针转换为函数库字符串，如果转换失败则返回空字符串。
      template<字符类型 TmpChar>
      static const 类型字符 *转换任意字符串(const TmpChar *指针项, 类型长度 &长度项, 标准字符串类 &存储项) noexcept
      {
         if constexpr (相同类型<TmpChar, 类型字符>)
         {
            return 指针项;
         }

         else
         {
            try {
               存储项 = std::filesystem::path(指针项).u32string();
               长度项 = 存储项.length();
               return 存储项.data();
            } catch (const std::exception &e) {
               std::cout << e.what() << std::endl;
               长度项 = 0;
               return C("");
            }
         }
      }

      public:

      类型逻辑 operator == (const 字符串类 &比较项) const noexcept
      {
         return this->相等判断(比较项);
      }

   };

}

namespace std {

   // 重载 std::hash 运算符，使得字符串对象可以作为哈希表的键值。
   template<>
   struct hash<::BE::字符串类> 
   {
      size_t operator()(const ::BE::字符串类 &字符串项) const noexcept
      {
         return static_cast<size_t>(::BE::获取字符串哈希(字符串项));
      }
   };
}
