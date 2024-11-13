
namespace BE {

   namespace 错误集 {

      inline constexpr 类型错误 文件打开错误 = C("文件无法打开或者不存在！");

      inline constexpr 类型错误 文件已存在错误 = C("文件已经存在无需创建！");

      inline constexpr 类型错误 文件读取或写入错误 = C("文件无法进行读取或写入操作！");

   }

   /**
    * \brief >>> 提供基本的文件读写功能的类，支持原始字节流读取与多编码文本读取，以及文件创建、打开、关闭等操作，不支持复制构造和复制赋值。
    * \brief >>> 继承路径类，公开路径类中的部分成员函数。
    */
   struct 文件类 : protected 路径类, public 错误类
   {

      using 类型偏移 = std::streamoff;

      enum {
         默认模式 = (0 << 0),
         清除模式 = (1 << 0),     // 打开文件并清空文件内容。
         追加模式 = (1 << 1),     // 打开文件并移动到文件末尾。
      };

      // 当前类支持的文件编码。
      enum class 文件编码枚举 {
         UTF8,                   // 以 UTF-8 编码进行文本读写。
         ANSI                    // 以当前系统的默认 char 编码进行文本读写。
      };

      static constexpr int 打开样式 = std::ios::in | std::ios::out | std::ios::binary;

      // 允许访问路径类中的一些 const 成员函数，而防止使用文件类去修改保存的路径。
      using 路径类::operator const std::filesystem::path &;
      using 路径类::获取硬链接数;
      using 路径类::获取文件大小;
      using 路径类::获取后缀;
      using 路径类::获取文件名;
      using 路径类::获取父路径;
      using 路径类::获取文件类别;
      using 路径类::获取修改时间;
      using 路径类::获取路径字符串;
      using 路径类::获取字符串;
      using 路径类::获取标准路径;
      using 路径类::获取主干;
      using 路径类::获取根名;
      using 路径类::获取根目录;
      using 路径类::获取相对根路径;
      using 路径类::获取符号链接目标;
      using 路径类::创建硬链接;
      using 路径类::创建符号链接;
      using 路径类::空文件判断;
      using 路径类::分隔符;

      // 默认构造函数。
      文件类() noexcept = default;

      // 禁止复制构造。
      文件类(const 文件类 &) noexcept = delete;

      // 将目标中的文件所有权移动到当前文件中，同时移动其他信息。
      文件类(文件类 &&赋值项) noexcept
      {
         this->赋值(std::move(赋值项));
      }

      // 打开或创建路径表示的文件。
      文件类(字符视图类 路径项, int 模式项 = 默认模式) noexcept
      {
         this->打开或创建(路径项, 模式项);
      }

      /**
       * \brief >>> 关闭当前文件，打开一个已有的文件，如果文件不存在则结束函数。
       * 
       * \param 路径项： 要打开的文件路径。
       * \param 模式项： 要打开文件的额外模式。
       * \return this &
       */
      文件类 &打开(字符视图类 路径项, int 模式项 = 默认模式) noexcept
      {
         this->关闭();

         if (this->路径类::赋值(路径项).获取文件类别() != 文件类别枚举::常规)
         {
            this->错误类::设置错误(错误集::文件打开错误);
            return *this;
         }

         int 模式 = 打开样式 | (模式项 & 清除模式 ? std::ios::trunc : 0) | (模式项 & 追加模式 ? std::ios::app : 0);

         this->类中文件.open(this->获取标准路径(), 模式);
         return *this;
      }

      /**
       * \brief >>> 关闭当前文件，并在给定的路径上创建一个新的文件，如果文件已经存在则结束函数。
       * 
       * \param 路径项： 要创建的文件路径。
       * \param 模式项： 要创建文件的额外模式。
       * \return this &
       */
      文件类 &创建(字符视图类 路径项, int 模式项 = 默认模式) noexcept
      {
         this->关闭();

         if (this->路径类::赋值(路径项).获取文件类别() == 文件类别枚举::常规)
         {
            this->错误类::设置错误(错误集::文件已存在错误);
            return *this;
         }

         int 模式 = 打开样式 | (模式项 & 清除模式 ? std::ios::trunc : 0) | (模式项 & 追加模式 ? std::ios::app : 0);

         // in | out 无法创建文件，所以需要清除 in 模式
         ::BE::清除掩码(模式, std::ios::in);

         this->类中文件.open(this->获取标准路径(), 模式);
         return *this;
      }

      /**
       * \brief >>> 关闭当前文件，如果文件存在则打开它，否则创建它。
       * 
       * \param 路径项： 要打开或创建的文件路径。
       * \param 模式项： 要打开或创建文件的额外模式。
       * \return this &
       */
      文件类 &打开或创建(字符视图类 路径项, int 模式项 = 默认模式) noexcept
      {
         if (this->路径类::赋值(路径项).获取文件类别() == 文件类别枚举::常规)
         {
            return this->打开(路径项, 模式项);
         }

         return this->创建(路径项, 模式项);
      }

      /**
       * \brief >>> 将目标中的文件所有权移动到当前文件中，同时移动其他信息。
       * 
       * \param 赋值项： 要移动的文件。
       * \return this &
       */
      文件类 &赋值(文件类 &&赋值项) noexcept   /* 顺带覆写路径类中的赋值函数 */
      {
         this->类中文件 = std::move(赋值项.类中文件);
         this->类中路径 = std::move(赋值项.类中路径);
         this->类中错误 = std::move(赋值项.类中错误);
         this->类中错误码 = 赋值项.类中错误码;
         return *this;
      }

      /**
       * \brief >>> 关闭已经打开的文件。
       * 
       * \return this &
       */
      文件类 &关闭() noexcept
      {
         this->类中文件.close();
         return *this;
      }

      /**
       * \brief >>> 获取文件指针在文件中的位置。
       * 
       * \return 位置，即偏移。
       */
      类型偏移 获取指针位置() noexcept
      {
         return this->类中文件.tellg().operator std::streamoff();
      }

      /**
       * \brief >>> 从当前位置开始移动文件指针。
       * 
       * \param 偏移项： 要移动的长度，可以为负数。
       * \return this &
       */
      文件类 &当前偏移(类型偏移 偏移项) noexcept
      {
         this->类中文件.seekg(偏移项, std::ios::beg);
         return *this;
      }

      /**
       * \brief >>> 从文件起始点开始移动文件指针。
       * 
       * \param 偏移项： 要移动的长度，可以为负数。
       * \return this &
       */
      文件类 &头部偏移(类型偏移 偏移项) noexcept
      {
         this->类中文件.seekg(偏移项, std::ios::beg);
         return *this;
      }

      /**
       * \brief >>> 从文件的尾部开始移动文件指针。
       * 
       * \param 偏移项： 要移动的长度，可以为负数。
       * \return this &
       */
      文件类 &尾部偏移(类型偏移 偏移项) noexcept
      {
         this->类中文件.seekg(偏移项, std::ios::end);
         return *this;
      }

      /**
       * \brief >>> 向文件中读取指定长度的字节块到存储区中，如果读取失败则结束函数。
       * 
       * \param 存储项： 要存储读取内容的内存块。
       * \param 长度项： 要读取的字节数。
       * \return 实际读取的字节数，如果读取失败则返回 0。
       */
      类型长度 读取字节块(void *存储项, 类型长度 长度项) noexcept
      {
         try {
            return this->类中文件.read(reinterpret_cast<char *>(存储项), 长度项).gcount();
         } catch (...) {
            this->错误类::设置错误(错误集::文件读取或写入错误);
            return 0;
         }
      }
      
      /**
       * \brief >>> 从文件中读取一个字节数据并返回，如果读取失败则返回字节数据 0 。
       * 
       * \return 读取到的字节数据，如果读取失败则返回 0。
       */
      类型字节 读取字节() noexcept
      {
         类型字节 返回值 = 0;

         this->读取字节块(&返回值, 1);

         return 返回值;
      }

      /**
       * \brief >>> 向文件中写入指定长度的字节块，如果写入失败则结束函数。
       * 
       * \param 存储项： 要写入内容的内存块。
       * \param 长度项： 要写入的字节数。
       * \return 实际写入的字节数，如果写入失败则返回 0。
       */
      类型长度 写入字节块(const void *存储项, 类型长度 长度项) noexcept
      {
         try {
            this->类中文件.write(reinterpret_cast<const char *>(存储项), 长度项);
            return 长度项;
         } catch (...) {
            this->错误类::设置错误(错误集::文件读取或写入错误);
            return 0;
         }
      }

      /**
       * \brief >>> 将指定对象中的字节数据写入到文件中，如果写入失败则结束函数。
       * 
       * \param 写入项： 要写入的对象。
       * \return 实际写入的字节数，如果写入失败则返回 0。
       * \tparam TmpT： 任意类型。
       */
      template<typename TmpT>
      类型长度 写入字节对象(TmpT &&写入项) noexcept
      {
         return this->写入字节块(&写入项, sizeof(TmpT));
      }

      /**
       * \brief >>> 写入一个字节的数据到文件中，如果写入失败则结束函数。
       * 
       * \param 写入项： 要写入的字节数据。
       * \return this &
       */
      文件类 &写入字节(类型字节 写入项) noexcept
      {
         this->写入字节块(&写入项, 1);
         return *this;
      }

      /**
       * \brief >>> 将文件中指定字节数据读取到给定对象中，如果读取失败则结束函数。
       * 
       * \param 读取项： 要读取的对象。
       * \return 实际读取的字节数，如果读取失败则返回 0，如果读取长度和 sizeof(TmpT) 不同则对象可能是不完整的，请勿使用。
       * \tparam TmpT： 任意类型。
       */
      template<typename TmpT>
      类型长度 读取字节对象(TmpT &读取项) noexcept
      {
         return this->读取字节块(&读取项, sizeof(TmpT));
      }

      /**
       * \brief >>> 将字符串以指定编码写入到文件中，请确保给定的编码和文件编码一致。
       * 
       * \param 写入项： 要写入的字符串。
       * \param 编码项： 要写入文件的文本编码，默认 UTF8。
       * \return 实际写入的字节数，如果写入失败则返回 0。
       */
      类型长度 写入字符串(字符视图类 写入项, 文件编码枚举 编码项 = 文件编码枚举::UTF8) noexcept
      {
         if (this->打开否() == 假)
         {
            return 0;
         }

         try {
            std::filesystem::path 待转换串{ std::basic_string_view<类型字符>(写入项.获取指针(), 写入项.获取长度()) };

            if (编码项 == 文件编码枚举::UTF8)
            {
               std::u8string 转换串 = 待转换串.u8string();
               return this->写入字节块(转换串.c_str(), 转换串.length() * sizeof(char8_t));
            }
            else if (编码项 == 文件编码枚举::ANSI)
            {
               std::string 转换串 = 待转换串.string();
               return this->写入字节块(转换串.c_str(), 转换串.length() * sizeof(char));
            }

         } catch (const std::exception &) {
            this->设置错误(错误集::转换错误);
            return 0;
         }
      }

      /**
       * \brief >>> 将文件中的所有内容以指定文本编码的形式读取到字符串中并返回。
       * \brief >>> 请确保文件中的编码和你指定的编码一致，否则可能产生错误。
       * 
       * \param 编码项： 要读取文件的文本编码，默认 UTF8。
       * \return 字符串，如果没有打开文件或者内存分配失败则返回空字符串。
       */
      字符串类 全文读取(文件编码枚举 编码项 = 文件编码枚举::UTF8) noexcept
      {
         字符串类 返回值;

         if (this->打开否())
         {
            类型长度 文件长度 = this->获取文件大小();
            类型偏移 指针位置 = this->获取指针位置();
            类型长度 读取长度 = 0;
            类型字节 *内存块  = ::BE::分配原始内存<类型字节>(文件长度 + 4);

            if (内存块 == 空指针)
            {
               this->设置错误(错误集::内存分配错误);
               return 返回值;
            }

            std::memset(内存块, 0, 文件长度 + 4);

            this->头部偏移(0);
            
            if ((读取长度 = this->读取字节块(内存块, 文件长度)) != 0)
            {
               if (编码项 == 文件编码枚举::UTF8)
               {
                  返回值.赋值(reinterpret_cast<char8_t *>(内存块));
               }
               else if (编码项 == 文件编码枚举::ANSI)
               {
                  返回值.赋值(reinterpret_cast<char *>(内存块));
               }
            }

            this->头部偏移(指针位置);

            ::BE::释放原始内存(内存块);
         }

         return 返回值;
      }

      /**
       * \brief >>> 将文件从头开始的所有字节数据读取到字节类中并返回。
       * 
       * \return 字节类。
       */
      字节类 全字节读取() noexcept
      {
         字节类 返回值;
         类型偏移 指针位置 = this->获取指针位置();

         if (this->打开否())
         {
            返回值.赋值(this->获取文件大小());

            if (返回值.获取总长度() != 0)
            {
               this->头部偏移(0);
               this->读取字节块(返回值.获取字节指针(), 返回值.获取长度());
               this->头部偏移(指针位置);
            }
         }

         return 返回值;
      }

      /**
       * \brief >>> 判断是否已经打开了文件。
       * 
       * \return 打开则返回真，否则返回假。
       */
      类型逻辑 打开否() const noexcept
      {
         return this->类中文件.is_open();
      }

      /**
       * \brief >>> 判断文件指针是否在文件的末尾。
       * 
       * \return 是则返回假，否则返回真。
       */
      类型逻辑 非末尾() const noexcept
      {
         return this->类中文件.eof() == 假;
      }

      // 安全析构函数，自动关闭文件。
      ~文件类() noexcept
      {
         this->关闭();
      }

      protected:

      std::fstream 类中文件;

      public:

      // 将目标中的文件所有权移动到当前文件中，同时移动其他信息。
      文件类 &operator = (文件类 &&赋值项) noexcept  /* 顺带覆写路径类中的赋值函数 */
      {
         return this->赋值(std::move(赋值项));
      }

      // 禁止复制赋值。
      文件类 &operator = (const 文件类 &) = delete;

      // 如果打开文件并且没有错误则返回真，否则返回假。
      explicit operator bool() const noexcept
      {
         return this->打开否() && this->无错误的();
      }
   };

}
