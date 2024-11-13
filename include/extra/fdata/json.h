
namespace BE::文件数据集 {

   enum class JSON类型枚举
   {
       无效,
       数组,
       对象,
       字符串,
       整数,
       浮点,
       逻辑,
       空值
   };

   struct JSON数组类;
   struct JSON对象类;

   /**
    * \brief >>> 用于存储基本 JSON 数据，即整数、浮点、逻辑、空值、字符串、对象和数组类型数据的类。
    */
   struct JSON基本数据存储类
   {
      using 存值类 = 类型字节[sizeof(T::IPTR)];
      using 整数类 = T::I64;
      using 浮点类 = T::F64;

      // 默认构造函数。
      JSON基本数据存储类() noexcept = default;

      // 移动构造函数，获取目标数据的所有权并清空对象。
      JSON基本数据存储类(JSON基本数据存储类 &&赋值项) noexcept
      {
         this->枚举值 = BE::交换赋值(赋值项.枚举值, JSON类型枚举::无效);
         std::memcpy(this->存储值, 赋值项.存储值, sizeof(this->存储值));
         std::memset(赋值项.存储值, 0, sizeof(赋值项.存储值));
      }

      // 复制构造函数，对于非字符串、数组、对象，直接按字节复制数据。
      JSON基本数据存储类(const JSON基本数据存储类 &赋值项) noexcept
      {
         this->operator=(赋值项);
      }

      // 复制赋值函数，对于非字符串、数组、对象，直接按字节复制数据。
      JSON基本数据存储类 &operator = (const JSON基本数据存储类 &赋值项) noexcept
      {
         if (赋值项.枚举值 == JSON类型枚举::字符串)
         {
            this->operator=(**赋值项.转为指定值<JSON类型枚举::字符串>());
         }
         else if (赋值项.枚举值 == JSON类型枚举::数组)
         {
            this->operator=(**赋值项.转为指定值<JSON类型枚举::数组>());
         }
         else if (赋值项.枚举值 == JSON类型枚举::对象)
         {
            this->operator=(**赋值项.转为指定值<JSON类型枚举::对象>());
         }
         else
         {
            this->释放();
            this->枚举值 = 赋值项.枚举值;
            std::memcpy(this->存储值, 赋值项.存储值, sizeof(this->存储值));
         }

         return *this;
      }

      // 允许赋值为任意整数类型。
      template<严格整数类型 TmpT>
      JSON基本数据存储类 &operator = (TmpT 赋值项) noexcept
      {
         if (this->枚举值 != JSON类型枚举::整数)
         {
            this->释放();
            this->枚举值 = JSON类型枚举::整数;
           *this->转为指定值<JSON类型枚举::整数>() = static_cast<整数类>(赋值项);
         }
         else
         {
           *this->转为指定值<JSON类型枚举::整数>() = static_cast<整数类>(赋值项);
         }

         return *this;
      }

      // 允许赋值为任意浮点类型。
      template<浮点类型 TmpT>
      JSON基本数据存储类 &operator = (TmpT 赋值项) noexcept
      {
         if (this->枚举值 != JSON类型枚举::浮点)
         {
            this->释放();
            this->枚举值 = JSON类型枚举::浮点;
           *this->转为指定值<JSON类型枚举::浮点>() = static_cast<浮点类>(赋值项);
         }
         else
         {
           *this->转为指定值<JSON类型枚举::浮点>() = static_cast<浮点类>(赋值项);
         }

         return *this;
      }

      // 允许赋值为一个 JSON 对象。
      JSON基本数据存储类 &operator = (const JSON对象类 &赋值项) noexcept;
      // 允许赋值为一个 JSON 数组。
      JSON基本数据存储类 &operator = (const JSON数组类 &赋值项) noexcept;

      // 允许将任意字符串类型赋值为字符串。
      template<字符串类型 TmpT>
      JSON基本数据存储类 &operator = (TmpT 赋值项) noexcept
      {
         if (this->枚举值 != JSON类型枚举::字符串)
         {
            this->释放();
            this->枚举值 = JSON类型枚举::字符串;
           *this->转为指定值<JSON类型枚举::字符串>() = BE::直接构造(BE::分配原始内存<字符串类>(1), 1, std::forward<TmpT>(赋值项));
         }
         else
         {
          **this->转为指定值<JSON类型枚举::字符串>() = 赋值项;
         }

         return *this;
      }

      // 允许将任意类型赋值为逻辑值。
      JSON基本数据存储类 &operator = (类型逻辑 赋值项) noexcept
      {
         this->释放();
         this->枚举值 = JSON类型枚举::逻辑;
        *this->转为指定值<JSON类型枚举::逻辑>() = static_cast<bool>(赋值项);
         return *this;
      }

      // 将 JSON 数据赋值为 null 空值。
      JSON基本数据存储类 &operator = (类型空值) noexcept
      {
         this->释放();
         this->枚举值 = JSON类型枚举::空值;
         return *this;
      }

      /**
       * \brief >>> 根据当前的 JSON 枚举值释放对于的内存空间并释放对象，对于非字符串、数组、对象，无需释放。
       * 
       * \return this &
       */
      JSON基本数据存储类 &释放() noexcept
      {
         if (this->枚举值 == JSON类型枚举::字符串)
         {
            BE::释放原始内存(BE::直接析构(*this->转为指定值<JSON类型枚举::字符串>(), 1));
         }
         else if (this->枚举值 == JSON类型枚举::数组)
         {
            BE::释放原始内存(BE::直接析构(*this->转为指定值<JSON类型枚举::数组>(), 1));
         }
         else if (this->枚举值 == JSON类型枚举::对象)
         {
            BE::释放原始内存(BE::直接析构(*this->转为指定值<JSON类型枚举::对象>(), 1));
         }

         this->枚举值 = JSON类型枚举::无效;
         return *this;
      }

      /**
       * \brief >>> 根据指定枚举转换为对应的 JSON 数据存储对象，对于字符串、数组、对象，返回存储指针的指针，对于其他非无效，则返回对应类型的指针，如空值返回 nullptr，整数返回 `整数类*`。
       * \brief >>> 对于无效，则什么也不返回，即返回值类型为 void。
       * 
       * \return 对于枚举的对应存储格式类型。
       */
      template<JSON类型枚举 TmpEnum>
      decltype(auto) 转为指定值() noexcept
      {
         if constexpr (TmpEnum == JSON类型枚举::整数)
         {
            return reinterpret_cast<整数类 *>(this->存储值);
         }
         else if constexpr (TmpEnum == JSON类型枚举::浮点)
         {
            return reinterpret_cast<浮点类 *>(this->存储值);
         }
         else if constexpr (TmpEnum == JSON类型枚举::逻辑)
         {
            return reinterpret_cast<bool *>(this->存储值);
         }
         else if constexpr (TmpEnum == JSON类型枚举::字符串)
         {
            return reinterpret_cast<字符串类 **>(this->存储值);
         }
         else if constexpr (TmpEnum == JSON类型枚举::空值)
         {
            return nullptr;
         }
         else if constexpr (TmpEnum == JSON类型枚举::数组)
         {
            return reinterpret_cast<JSON数组类 **>(this->存储值);
         }
         else if constexpr (TmpEnum == JSON类型枚举::对象)
         {
            return reinterpret_cast<JSON对象类 **>(this->存储值);
         }
         else
         {
            return;
         }
      }

      /**
       * \brief >>> 根据指定枚举转换为对应的 JSON 数据存储对象，对于字符串、数组、对象，返回存储指针的指针，对于其他非无效，则返回对应类型的指针，如空值返回 nullptr，整数返回 `整数类*`。
       * \brief >>> 对于无效，则什么也不返回，即返回值类型为 void。
       *
       * \return 对于枚举的对应存储格式类型。
       */
      template<JSON类型枚举 TmpEnum>
      decltype(auto) 转为指定值() const noexcept
      {
         return BE::去除只读(*this).转为指定值<TmpEnum>();
      }

      // 安全析构函数，调用释放函数释放。
      ~JSON基本数据存储类() noexcept
      {
         this->释放();
      }

      // 存储值的类型，对于字符串、数组、对象，存储他们的指针值。
      alignas(8)
      存值类       存储值;
      JSON类型枚举 枚举值;
   };

   /**
    * \brief >>> 一个负责维护存储一些列 JSON 数据的可迭代类型。
    */
   struct JSON数组类
   {
      using 句柄类 = 可变数组类<JSON基本数据存储类>;

      auto begin() noexcept { return this->类中存储.begin(); };
      auto end() noexcept { return this->类中存储.end(); };

      auto begin() const noexcept { return this->类中存储.begin(); };
      auto end() const noexcept { return this->类中存储.end(); };

      // 默认构造函数。
      JSON数组类() noexcept = default;

      // 允许使用数组构造 JSON 数组。
      JSON数组类(const 句柄类 &赋值项) noexcept : 类中存储(赋值项)
      {

      }

      /**
       * \brief >>> 从数组指定位置插入一个 JSON 数据。
       * 
       * \param 插入项： 要插入的 JSON 数据。
       * \param 位置项： 要插入的位置，默认为数组末尾。
       * \return this &
       */
      JSON数组类 &插入(const JSON基本数据存储类 &插入项, 类型长度 位置项 = 到末尾) noexcept
      {
         this->类中存储.插入(插入项, 位置项);
         return *this;
      }

      /**
       * \brief >>> 从数组末尾插入一个无效的 JSON 数据并将其返回。
       * 
       * \return JSON 数据引用。
       */
      JSON基本数据存储类 &追加() noexcept
      {
         this->插入(JSON基本数据存储类(), 到末尾);
         return this->类中存储.获取尾值();
      }

      /**
       * \brief >>> 获取数组的长度。
       * 
       * \return 数组长度。
       */
      类型长度 获取长度() const noexcept
      {
         return this->类中存储.获取长度();
      }

      /**
       * \brief >>> 获取 JSON 数组用于管理数据的底层句柄。
       * 
       * \return 目标句柄的引用。
       */
      句柄类 &获取句柄() noexcept
      {
         return this->类中存储;
      }

      /**
       * \brief >>> 获取 JSON 数组用于管理数据的底层句柄。
       * 
       * \return 目标句柄的只读引用。
       */
      const 句柄类 &获取句柄() const noexcept
      {
         return this->类中存储;
      }

      // 安全析构函数，释放所有 JSON 数据。
      ~JSON数组类() noexcept
      {

      }

      protected:

      句柄类 类中存储;

      public:

      // 获取指定索引位置的 JSON 数据引用，注意越界。
      JSON基本数据存储类 &operator [] (类型长度 索引项) noexcept
      {
         return this->类中存储[索引项];
      }

   };

   template<typename TmpT>
   concept JSON数据类型 = 赋值类型<JSON基本数据存储类, TmpT>;

   /**
    * \brief >>> 一个负责维护一些列 JSON 数据及其名称的键值对可迭代类型。
    */
   struct JSON对象类
   {
      using 键值类 = 对值类<字符串类, JSON基本数据存储类>;
      using 句柄类 = std::unordered_map<字符串类, JSON基本数据存储类>;

      auto begin() noexcept { return this->类中存储.begin(); }
      auto end() noexcept { return this->类中存储.end(); }

      auto begin() const noexcept { return this->类中存储.begin(); }
      auto end() const noexcept { return this->类中存储.end(); }

      // 默认构造函数。
      JSON对象类() noexcept = default;

      // 允许使用键值对构造 JSON 对象。
      JSON对象类(const 句柄类 &赋值项) noexcept : 类中存储(赋值项)
      {

      }

      /**
       * \brief >>> 在对象中插入一个键值对，如果键名已存在，则行为为赋值，由于对象使用键值表示，因此无需提供索引。
       * 
       * \param 键名项： 要插入的键名。
       * \param 插入项： 要插入的 JSON 数据。
       * \return this &
       */
      JSON对象类 &插入(const 字符串类 &键名项, const JSON基本数据存储类 &插入项) noexcept
      {
         this->类中存储[键名项] = 插入项;
         return *this;
      }

      /**
       * \brief >>> 获取对象中的键值对数量。
       * 
       * \return 键值对数量。
       */
      类型长度 获取长度() const noexcept
      {
         return static_cast<类型长度>(this->类中存储.size());
      }

      /**
       * \brief >>> 从对象中获取指定键名对应的 JSON 数据，如果不存在则返回空指针，可以用于检查键是否存在。
       * 
       * \param 键名项： 要获取的键名。
       * \return JSON 数据指针，键名不存在则返回空指针。
       */
      JSON基本数据存储类 *获取(const 字符串类 &键名项) noexcept
      {
         if (auto 位置 = this->类中存储.find(键名项); 位置 != this->类中存储.end())
         {
            return &位置->second;
         }
         return 空指针;
      }

      /**
       * \brief >>> 获取 JSON 对象用于管理数据的底层句柄。
       * 
       * \return 目标句柄的引用。
       */
      句柄类 &获取句柄() noexcept
      {
         return this->类中存储;
      }

      /**
       * \brief >>> 获取 JSON 对象用于管理数据的底层句柄。
       * 
       * \return 目标句柄的只读引用。
       */
      const 句柄类 &获取句柄() const noexcept
      {
         return this->类中存储;
      }

      // 安全析构函数，释放所有 JSON 数据。
      ~JSON对象类() noexcept
      {

      }

      protected:

      句柄类 类中存储;

      public:

      // 根据键名返回指定 JSON 数据的引用，如果键名不存在则创建它。
      JSON基本数据存储类 &operator () (const 字符串类 &键名项) noexcept
      {
         return this->类中存储[键名项];
      }

      template<JSON数据类型 TmpT>
      JSON对象类 &operator () (const 字符串类 &键名项, TmpT &&赋值项) noexcept
      {
         this->类中存储[键名项] = 赋值项;
         return *this;
      }
   };

   inline JSON基本数据存储类 &BE::文件数据集::JSON基本数据存储类::operator = (const JSON数组类 &赋值项) noexcept
   {
      if (this->枚举值 != JSON类型枚举::数组)
      {
         this->释放();
         this->枚举值 = JSON类型枚举::数组;
        *this->转为指定值<JSON类型枚举::数组>() = BE::直接构造(BE::分配原始内存<JSON数组类>(1), 1, 赋值项.获取句柄());
      }
      else
      {
         (*this->转为指定值<JSON类型枚举::数组>())->获取句柄() = 赋值项.获取句柄();
      }

      return *this;
   }

   JSON基本数据存储类 &BE::文件数据集::JSON基本数据存储类::operator = (const JSON对象类 &赋值项) noexcept
   {
      if (this->枚举值 != JSON类型枚举::对象)
      {
         this->释放();
         this->枚举值 = JSON类型枚举::对象;
        *this->转为指定值<JSON类型枚举::对象>() = BE::直接构造(BE::分配原始内存<JSON对象类>(1), 1, 赋值项.获取句柄());
      }
      else
      {
         (*this->转为指定值<JSON类型枚举::对象>())->获取句柄() = 赋值项.获取句柄();
      }

      return *this;
   }

}

namespace BE {

   template<>
   struct 转字符串类<文件数据集::JSON类型枚举>
   {
      字符串类 operator () (const 文件数据集::JSON类型枚举 &枚举值) const noexcept
      {
         switch (枚举值)
         {
            case 文件数据集::JSON类型枚举::数组:
               return C("[:enum 数组 - ARRAY]");
            case 文件数据集::JSON类型枚举::对象:
               return C("[:enum 对象 - OBJECT]");
            case 文件数据集::JSON类型枚举::字符串:
               return C("[:enum 字符串 - STRING]");
            case 文件数据集::JSON类型枚举::整数:
               return C("[:enum 整数 - INTEGER]");
            case 文件数据集::JSON类型枚举::浮点:
               return C("[:enum 浮点 - FLOAT]");
            case 文件数据集::JSON类型枚举::逻辑:
               return C("[:enum 布尔 - BOOLEAN]");
            case 文件数据集::JSON类型枚举::空值:
               return C("[:enum 空值 - NULL]");
            default:
               return C("[:enum 无效 - INVALID]");
         }
      }
   };

   template<>
   struct 转字符串类<文件数据集::JSON对象类>;

   template<>
   struct 转字符串类<文件数据集::JSON数组类>
   {
      字符串类 operator () (const 文件数据集::JSON数组类 &转换项, 字符视图类 换行符项 = C("\n"), 类型长度 缩进项 = 4, 类型长度 起始缩进项 = 0) const noexcept;
   };

   template<>
   struct 转字符串类<文件数据集::JSON对象类>
   {
      字符串类 operator () (const 文件数据集::JSON对象类 &转换项, 字符视图类 换行符项 = C("\n"), 类型长度 缩进项 = 4, 类型长度 起始缩进项 = 0) const noexcept
      {
         字符串类 返回值 = 格式化串(C("{:*}"), C('{'), 起始缩进项);
         类型长度 起始缩进 = 起始缩进项;
         类型长度 转换长度 = 0;

         for (auto &&[键名, 值] : 转换项)
         {
            if (换行符项.获取长度() != 0)
            {
               返回值 << 换行符项 << 字符串类(C(' '), 起始缩进项 + 缩进项);
            }

            if (值.枚举值 != 文件数据集::JSON类型枚举::无效)
            {
               返回值 << C('\"') << 键名.转为原始字符串() << C('\"') << C(':');

               if (值.枚举值 == 文件数据集::JSON类型枚举::对象)
               {
                  返回值 << this->operator()(**值.转为指定值<文件数据集::JSON类型枚举::对象>(), 换行符项, 缩进项, 起始缩进项 + 缩进项);
               }
               else if (值.枚举值 == 文件数据集::JSON类型枚举::数组)
               {
                  返回值 << 转字符串类<文件数据集::JSON数组类>()(**值.转为指定值<文件数据集::JSON类型枚举::数组>(), 换行符项, 缩进项, 起始缩进项 + 缩进项);
               }
               else if (值.枚举值 == 文件数据集::JSON类型枚举::字符串)
               {
                  返回值 << C('\"') << (**值.转为指定值<文件数据集::JSON类型枚举::字符串>()).转为原始字符串() << C('\"');
               }
               else if (值.枚举值 == 文件数据集::JSON类型枚举::整数)
               {
                  返回值 << (*值.转为指定值<文件数据集::JSON类型枚举::整数>());
               }
               else if (值.枚举值 == 文件数据集::JSON类型枚举::浮点)
               {
                  返回值 << (*值.转为指定值<文件数据集::JSON类型枚举::浮点>());
               }
               else if (值.枚举值 == 文件数据集::JSON类型枚举::逻辑)
               {
                  返回值 << ((*值.转为指定值<文件数据集::JSON类型枚举::逻辑>()) ? C("true") : C("false"));
               }
               else if (值.枚举值 == 文件数据集::JSON类型枚举::空值)
               {
                  返回值 << C("null");
               }
            }

            if (++转换长度 < 转换项.获取长度())
            {
               返回值 << C(',');
            }
            
         }

         if (换行符项.获取长度() != 0)
         {
            返回值 << 换行符项 << 字符串类(C(' '), 起始缩进);
         }

         return 返回值 << 格式化串(C("{:*}"), C('}'), 起始缩进);
      }
   };

   inline 字符串类 BE::转字符串类<文件数据集::JSON数组类>::operator()(const 文件数据集::JSON数组类 &转换项, 字符视图类 换行符项, 类型长度 缩进项, 类型长度 起始缩进项) const noexcept
   {
      字符串类 返回值 = 格式化串(C("{:*}"), C('['), 起始缩进项);
      类型长度 起始缩进 = 起始缩进项;
      类型长度 转换长度 = 0;

      for (auto &迭代量 : 转换项)
      {
         if (换行符项.获取长度() != 0)
         {
            返回值 << 换行符项 << 字符串类(C(' '), 起始缩进项 + 缩进项);
         }

         if (迭代量.枚举值 != 文件数据集::JSON类型枚举::无效)
         {

            if (迭代量.枚举值 == 文件数据集::JSON类型枚举::对象)
            {
               返回值 << 转字符串类<文件数据集::JSON对象类>()(**迭代量.转为指定值<文件数据集::JSON类型枚举::对象>(), 换行符项, 缩进项, 起始缩进项 + 缩进项);
            }
            else if (迭代量.枚举值 == 文件数据集::JSON类型枚举::数组)
            {
               返回值 << this->operator()(**迭代量.转为指定值<文件数据集::JSON类型枚举::数组>(), 换行符项, 缩进项, 起始缩进项 + 缩进项);
            }
            else if (迭代量.枚举值 == 文件数据集::JSON类型枚举::字符串)
            {
               返回值 << C('\"') << (**迭代量.转为指定值<文件数据集::JSON类型枚举::字符串>()).转为原始字符串() << C('\"');
            }
            else if (迭代量.枚举值 == 文件数据集::JSON类型枚举::整数)
            {
               返回值 << (*迭代量.转为指定值<文件数据集::JSON类型枚举::整数>());
            }
            else if (迭代量.枚举值 == 文件数据集::JSON类型枚举::浮点)
            {
               返回值 << (*迭代量.转为指定值<文件数据集::JSON类型枚举::浮点>());
            }
            else if (迭代量.枚举值 == 文件数据集::JSON类型枚举::逻辑)
            {
               返回值 << ((*迭代量.转为指定值<文件数据集::JSON类型枚举::逻辑>()) ? C("true") : C("false"));
            }
            else if (迭代量.枚举值 == 文件数据集::JSON类型枚举::空值)
            {
               返回值 << C("null");
            }
         }

         if (++转换长度 < 转换项.获取长度())
         {
            返回值 << C(',');
         }

      }

      if (换行符项.获取长度() != 0)
      {
         返回值 << 换行符项 << 字符串类(C(' '), 起始缩进);
      }

      return 返回值 << 格式化串(C("{:*}"), C(']'), 起始缩进);
   }

}
