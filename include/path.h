
namespace BE {

   enum class 文件类别枚举
   {
      非文件 = (int)std::filesystem::file_type::none,
      块设备 = (int)std::filesystem::file_type::block,
      字符设备 = (int)std::filesystem::file_type::character,
      目录 = (int)std::filesystem::file_type::directory,
      管道 = (int)std::filesystem::file_type::fifo,
      常规 = (int)std::filesystem::file_type::regular,
      套接字 = (int)std::filesystem::file_type::socket,
      符号链接 = (int)std::filesystem::file_type::symlink,
      其他 = (int)std::filesystem::file_type::unknown
   };

   /**
    * \brief >>> 一个包装 std::filesystem 中大多数功能的类，提供更方便的路径和系统文件操作。
    */
   struct 路径类
   {
      using EGO = void;

      // 该静态变量用于指定路径比较时，是比较路径字符串还是比较路径指向的系统对象。
      static inline std::atomic_bool 路径比较 = 真;

      // 当前系统中用于路径分隔的分隔符。
      static constexpr 类型字符 分隔符 = static_cast<类型字符>(std::filesystem::path::preferred_separator);

      // 默认构造函数。
      路径类() noexcept = default;

      // 将任意字符串类型赋值为路径。
      路径类(字符串类型 auto &&赋值项) noexcept
      {
         this->类中路径 = ::BE::获取字符串(赋值项);
      }

      // 将 std::filesystem::path 赋值为路径。
      路径类(const std::filesystem::path &赋值项) noexcept
      {
         this->类中路径 = 赋值项;
      }

      /**
       * \brief >>> 将任意字符串类型的字符串值赋值给路径。
       * 
       * \param 赋值项： 要赋值的任意字符串对象。
       * \return this &
       */
      路径类 &赋值(字符串类型 auto &&赋值项) noexcept
      {
         this->类中路径 = ::BE::获取字符串(赋值项);
         return *this;
      }

      /**
       * \brief >>> 将 std::filesystem::path 赋值给路径。
       * 
       * \param 赋值项： 要赋值的 std::filesystem::path 对象。
       * \return this &
       */
      路径类 &赋值(const std::filesystem::path &赋值项) noexcept
      {
         this->类中路径 = 赋值项;
         return *this;
      }

      /**
       * \brief >>> 获取路径的父路径，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 "C:\\Windows\\System32"。
       * 
       * \return 父路径，不存在则返回空路径。
       */
      路径类 获取父路径() const noexcept
      {
         return this->类中路径.parent_path();
      }

      /**
       * \brief >>> 获取路径中的根名，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 "C:"。
       * 
       * \return 根名，不存在则返回空路径。
       */
      路径类 获取根名() const noexcept
      {
         return this->类中路径.root_name();
      }

      /**
       * \brief >>> 获取路径中的根目录，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 "\\"。
       * 
       * \return 根目录，不存在则返回空路径。
       */
      路径类 获取根目录() const noexcept
      {
         return this->类中路径.root_directory();
      }

      /**
       * \brief >>> 获取路径中的根路径，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 "C:\\"。
       * 
       * \return 根路径，不存在则返回空路径。
       */
      路径类 获取根路径() const noexcept
      {
         return this->类中路径.root_path();
      }

      /**
       * \brief >>> 获取路径中的文件主干名称，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 "console.1"。
       * 
       * \return 主干，可以理解为没有后缀名的文件名，不存在则返回空路径。
       */
      路径类 获取主干() const noexcept
      {
         return this->类中路径.stem();
      }

      /**
       * \brief >>> 获取路径中的文件后缀名，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 ".exe"。
       * 
       * \return 文件后缀名，不存在则返回空路径。
       */
      路径类 获取后缀() const noexcept
      {
         return this->类中路径.extension();
      }

      /**
       * \brief >>> 获取路径中的文件名，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 "console.1.exe"。
       * 
       * \return 文件名，即主干加上后缀，不存在则返回空路径。
       */
      路径类 获取文件名() const noexcept
      {
         return this->类中路径.filename();
      }

      /**
       * \brief >>> 获取路径中相对于根名的路径，如对于 "C:\\Windows\\System32\\console.1.exe" 路径，则返回 "System32\\console.1.exe"。
       * 
       * \return 相对于根路径的路径，不存在则返回空路径。
       */
      路径类 获取相对根路径() const noexcept
      {
         return this->类中路径.relative_path();
      }

      /**
       * \brief >>> 函数判断路径是否为空路径。
       * 
       * \return 空则返回假，否则返回真。
       */
      类型逻辑 非空的() const noexcept
      {
         return this->类中路径.empty() == 假;
      }

      /**
       * \brief >>> 获取类中存储的路径。
       * 
       * \return std::filesystem::path 类只读引用。
       */
      const std::filesystem::path &获取标准路径() const noexcept
      {
         return this->类中路径;
      }

      /**
       * \brief >>> 获取路径中的原始字符串值。
       * 
       * \return 字符串值。
       */
      字符串类 获取字符串() const noexcept
      {
         return this->类中路径.u32string();
      }

      /**
       * \brief >>> 获取格式化为路径表示形式后的字符串。
       * 
       * \return 字符串值。
       */
      字符串类 获取路径字符串() const noexcept
      {
         return this->类中路径.generic_u32string();
      }

      /**
       * \brief >>> 向类中存储的字符串追加一个字符串。
       * 
       * \param 追加项： 要追加的字符串。
       * \return this &
       */
      路径类 &追加(字符串类型 auto &&追加项) const noexcept
      {
         this->类中路径 += ::BE::获取字符串(追加项);
         return *this;
      }

      /**
       * \brief >>> 追加一个字符串到路径末尾，并选择是否添加分隔符。
       * 
       * \param 追加项： 要追加的字符串。
       * \return this &
       */
      路径类 &追加目录(字符串类型 auto &&追加项) const noexcept
      {
         this->类中路径 /= ::BE::获取字符串(追加项);
         return *this;
      }

      /**
       * \brief >>> 如果文件名存在的话则删除它。
       * 
       * \return this &
       */
      路径类 &删除文件名() noexcept
      {
         this->类中路径.remove_filename();
         return *this;
      }

      /**
       * \brief >>> 如果文件名存在的话则替换它，否则和追加行为相同。
       * 
       * \param 替换项： 要替换的字符串。
       * \return this &
       */
      路径类 &替换文件名(字符串类型 auto &&替换项) noexcept
      {
         this->类中路径.replace_filename(::BE::获取字符串(替换项));
         return *this;
      }

      /**
       * \brief >>> 如果后缀名存在的话则替换它，否则和追加行为相同。
       * 
       * \param 替换项： 要替换的字符串。
       * \return this &
       */
      路径类 &替换后缀名(字符串类型 auto &&替换项) noexcept
      {
         this->类中路径.replace_extension(::BE::获取字符串(替换项));
         return *this;
      }

      /**
       * \brief >>> 获取路径所指向的系统中文件的类别。
       * 
       * \return 文件类别，如果路径不存在则返回非文件。
       */
      文件类别枚举 获取文件类别() const noexcept
      {
         try {
            switch (std::filesystem::status(this->类中路径).type())
            {
               case std::filesystem::file_type::none:
                  return 文件类别枚举::非文件;
               case std::filesystem::file_type::block:
                  return 文件类别枚举::块设备;
               case std::filesystem::file_type::character:
                  return 文件类别枚举::字符设备;
               case std::filesystem::file_type::directory:
                  return 文件类别枚举::目录;
               case std::filesystem::file_type::fifo:
                  return 文件类别枚举::管道;
               case std::filesystem::file_type::regular:
                  return 文件类别枚举::常规;
               case std::filesystem::file_type::socket:
                  return 文件类别枚举::套接字;
               case std::filesystem::file_type::symlink:
                  return 文件类别枚举::符号链接;
               case std::filesystem::file_type::unknown:
                  return 文件类别枚举::其他;
            }
         } catch (...) {
            return 文件类别枚举::非文件;
         }
      }

      /**
       * \brief >>> 获取路径指向的文件的字节占用，如果路径不存在则返回 0。
       * 
       * \return 占用大小。
       */
      类型长度 获取文件大小() const noexcept
      {
         return std::filesystem::file_size(this->类中路径, this->类中错误码);
      }

      /**
       * \brief >>> 依据当前路径表示创建目录，如果目录已经存在则不做任何操作。
       * 
       * \return this &
       */
      路径类 &创建目录() noexcept
      {
         std::filesystem::create_directories(this->类中路径, this->类中错误码);
         return *this;
      }

      /**
       * \brief >>> 如果当前路径指向的系统目标存在的话，则创建一个指定名称的硬链接，硬链接指向当前路径指向的系统目标。
       * \brief >>> 注意，硬链接只能在同文件系统中创建，主文件被删除不影响硬链接，因为他们共享一块存储空间。
       * 
       * \param 链接名： 要创建的硬链接的名称和路径。
       * \return this &
       */
      路径类 &创建硬链接(const 路径类 &链接名) noexcept
      {
         std::filesystem::create_hard_link(this->类中路径, 链接名.类中路径, this->类中错误码);
         return *this;
      }

      /**
       * \brief >>> 创建一个指向当前路径指向的系统目标的符号链接，如果当前路径没有指向系统中的任何文件对象，则创建出来的符号链接为死链接。
       * 
       * \param 链接名： 要创建的符号链接的名称和路径。
       * \return this &
       */
      路径类 &创建符号链接(const 路径类 &链接名) noexcept
      {
         std::filesystem::create_symlink(this->类中路径, 链接名.类中路径, this->类中错误码);
         return *this;
      }

      /**
       * \brief >>> 如果当前路径指向系统中的文件则返回这个文件的硬链接数。
       * 
       * \return 硬链接数，如果错误则返回 std::uintmax_t(-1)。
       */
      类型长度 获取硬链接数() const noexcept
      {
         return std::filesystem::hard_link_count(this->类中路径, this->类中错误码);
      }

      /**
       * \brief >>> 如果当前路径指向的是一个系统中的符号链接，则获取这个符号链接指向的目标路径。
       * 
       * \return 是则返回路径，否则返回空路径。
       */
      路径类 获取符号链接目标() const noexcept
      {
         return std::filesystem::read_symlink(this->类中路径, this->类中错误码);
      }

      /**
       * \brief >>> 函数判断路径指向的是否是一个存在的文件。
       * 
       * \return 是则返回真，否则返回假。
       */
      类型逻辑 文件判断() const noexcept
      {
         return this->获取文件类别() != 文件类别枚举::非文件;
      }

      /**
       * \brief >>> 删除路径指向的系统中存在的目标。
       * 
       * \param 递归否： 对于非空目录，是否递归删除目录中的所有内容，不是则函数只会删除空目录。
       * \return this &
       */
      路径类 &删除目标(类型逻辑 递归否 = 假) noexcept
      {
         递归否 ? (void)std::filesystem::remove_all(this->类中路径, this->类中错误码) : (void)std::filesystem::remove(this->类中路径, this->类中错误码);
         return *this;
      }

      /**
       * \brief >>> 将当前路径指向的系统中的目标迁移并重命名到目标路径上。
       * 
       * \param 目标项： 要移动到的目录路径。
       * \param 更新否： 如果迁移成功是否将当前路径指向更新为目标路径。
       * \return this &
       */
      路径类 迁移目标(const 路径类 &目标项, 类型逻辑 更新否 = 假) noexcept
      {
         std::filesystem::rename(this->类中路径, 目标项.类中路径, this->类中错误码);

         if (更新否 && this->类中错误码)
         {
            this->类中路径 = 目标项.类中路径;
         }

         return *this;
      }

      /**
       * \brief >>> 如果当前路径存在文件名，并且路径指向的文件存在，则重命名文件。
       * 
       * \param 名称项： 要重命名的文件名。
       * \param 更新否： 如果重命名成功是否将当前路径指向更新为新路径。
       * \return this &
       */
      路径类 &重命名(字符串类型 auto &&名称项, 类型逻辑 更新否 = 假) noexcept
      {
         std::filesystem::path 新路径 = this->类中路径;

         新路径.replace_filename(::BE::获取字符串(名称项));

         std::filesystem::rename(this->类中路径, 新路径, this->类中错误码);

         if (更新否 && this->类中错误码)
         {
            this->类中路径 = 新路径;
         }

         return *this;
      }

      /**
       * \brief >>> 如果当路径指向的目录存在，则遍历它的同时计算深度。
       * 
       * \param 接收调用项： 可调用对象，每次遍历到一个非目录文件时调用。
       * \param 深入调用项： 可调用对象，每次遍历到一个目录时调用，当然也包括第一次进入函数时。
       * \param 退出调用项： 可调用对象或空指针，每次遍历完一个目录时调用，如果遍历目录失败也会调用，如果为空指针或其他类型则不调用。
       * \param 路径项： 开始遍历的路径，若非必要，应使用默认值。
       * \param 深度项： 开始遍历的深度，若非必要，应使用默认值。
       * \return 遍历到的非目录文件数量。
       * \tparam TmpReceivers： 可调用类型，接收一个无符号整数类型和路径类。
       * \tparam TmpEnter： 可调用类型，接收一个无符号整数类型和路径类，可以提供返回值为逻辑类型，如果为假则退出当前目录遍历。
       * \tparam TmpQuit： 可调用类型，也可以为其他类型，为可调用类型时，以当接收一个无符号整数类型和路径类参数。
       */
      template<调用类型<类型无符<>, 路径类> TmpReceivers, 调用类型<类型无符<>, 路径类> TmpEnter, typename TmpQuit = void *>
      类型长度 目录遍历(TmpReceivers &&接收调用项, TmpEnter &&深入调用项, TmpQuit &&退出调用项 = 空指针, const 路径类 *路径项 = 空指针, 类型无符<> 深度项 = 0) const noexcept
      {
         类型长度 统计值 = 0;

         std::filesystem::path 路径值{ 路径项 == 空指针 ? this->类中路径 : *路径项 };
         std::filesystem::directory_iterator 目录遍历器{ 路径值, this->类中错误码 };    /* 负责遍历目录的迭代器 */

         if (this->类中错误码.value() == 0)
         {
            if constexpr (调用返回类型<TmpEnter, 类型逻辑, 类型无符, 路径类>)
            {
               if (深入调用项(深度项, 路径值) == 假)
               {
                  goto GEXIT;
               }
            }
            else
            {
               深入调用项(深度项, 路径值);
            }

            for (auto &目录元素 : 目录遍历器)
            {
               if (目录元素.is_directory())
               {
                  // 递归调用以进入目录。
                  统计值 += this->目录遍历(接收调用项, 深入调用项, 退出调用项, &目录元素.path(), 深度项 + 1);
               }
               else
               {
                  接收调用项(深度项, 目录元素.path());
                  统计值 += 1;
               }
            }
         }

      GEXIT:
         if constexpr (调用类型<TmpQuit, 类型无符<>, 路径类>)
         {
            退出调用项(深度项, 路径值);
         }

         return 统计值;
      }

      /**
       * \brief >>> 获取存储系统错误信息的错误码对象。
       * 
       * \return std::error_code 类只读引用。
       */
      const std::error_code &获取系统错误码() const noexcept
      {
         return this->类中错误码;
      }

      /**
       * \brief >>> 将错误码清除为 0。
       * 
       * \return this &
       */
      路径类 &清除错误码() noexcept
      {
         this->类中错误码.clear();
         return *this;
      }

      /**
       * \brief >>> 获取当前程序工作目录相对于当前路径的相对路径，如当前工作目录为 "C:\\Windows\\System32" ，当前路径为 "C:\\Windows\\Console\\cmd.exe" 则返回 "..\\Console\\cmd.exe"。
       * 
       * \return 相对路径，如果无符组成相对路径或者不存在等则返回空路径。
       */
      路径类 获取相对路径() const noexcept
      {
         return std::filesystem::relative(this->类中路径, this->类中错误码);
      }

      /**
       * \brief >>> 如果当前路径指向系统中存在的文件，则获取文件被最后修改的时间，精确到秒。
       * 
       * \return 被修改的时间，注意返回的时间起始年和标准起始年可能不相同。
       */
      时间类 获取修改时间() const noexcept
      {
         return 时间类(时间集::本地化时间戳(std::filesystem::last_write_time(
            this->类中路径, this->类中错误码
         ).time_since_epoch().count() / std::filesystem::file_time_type::period::den * 时间集::除秒时), 时间集::系统起始年);
      }

      /**
       * \brief >>> 将错误码清除为 0。
       * 
       * \return const this &
       */
      const 路径类 &清除错误码() const noexcept
      {
         this->类中错误码.clear();
         return *this;
      }

      /**
       * \brief >>> 比较两个路径，如果 `路径相同` 静态对象为真则比较两者的路径字符串，否则判断他们指向的系统中对象是否相同。
       * 
       * \param 比较项： 要比较的路径。
       * \return 相同则返回真，否则返回假。
       */
      类型逻辑 相等判断(const 路径类 &比较项) const noexcept
      {
         return 路径类::路径比较 ? (this->类中路径 == 比较项.类中路径) : (std::filesystem::equivalent(this->类中路径, 比较项.类中路径, this->类中错误码));
      }

      /**
       * \brief >>> 先判断路径指向的目标是否在系统中存在，然后判断其是否为空文件或者空目录。
       * 
       * \return 空文件或空目录则返回真，否则返回假。
       */
      类型逻辑 空文件判断() const noexcept
      {
         return std::filesystem::is_empty(this->类中路径, this->类中错误码);
      }

      protected:

      mutable std::error_code 类中错误码;
      std::filesystem::path   类中路径;

      public:

      // 允许将任意字符串对象中的字符串值赋值到路径中。
      路径类 &operator = (字符串类型 auto &&赋值项) noexcept
      {
         this->类中路径 = ::BE::获取字符串(赋值项);
         return *this;
      }

      // 允许将 std::filesystem::path 赋值到路径中。
      路径类 &operator = (const std::filesystem::path &赋值项) noexcept
      {
         this->类中路径 = 赋值项;
         return *this;
      }

      // 将任意字符串对象中的字符串值追加到当前路径末尾。
      路径类 &operator += (字符串类型 auto &&追加项) noexcept
      {
         this->类中路径 += ::BE::获取字符串(追加项);
         return *this;
      }

      // 将任意字符串对象中的字符串值追加到当前路径末尾，并选择是否添加分隔符。
      路径类 &operator /= (字符串类型 auto &&追加项) noexcept
      {
         this->类中路径 /= ::BE::获取字符串(追加项);
         return *this;
      }

      // 允许隐式转换为 std::filesystem::path。
      operator const std::filesystem::path &() const noexcept
      {
         return this->类中路径;
      }

   };

   /**
    * \brief >>> 获取当前程序工作目录的副本。
    * 
    * \return 工作目录副本。
    */
   inline 路径类 获取工作目录() noexcept
   {
      return std::filesystem::current_path();
   }

   /**
    * \brief >>> 设置当前程序的工作目录。
    * 
    * \param 路径项： 要设置的路径。
    * \return 错误信息。
    */
   inline std::error_code 设置工作目录(const 路径类 &路径项) noexcept
   {
      std::error_code 错误码;

      std::filesystem::current_path(路径项.获取标准路径(), 错误码);

      return 错误码;
   }

   /**
    * \brief >>> 获取当前系统的临时目录副本。
    * 
    * \return 系统临时目录副本。
    */
   inline 路径类 获取临时目录() noexcept
   {
      return std::filesystem::temp_directory_path();
   }

   // 将路径类以路径字符串的形式转为字符串。
   template<>
   struct 转字符串类<路径类>
   {
      字符串类 operator () (const 路径类 &路径项) const noexcept
      {
         return 路径项.获取路径字符串();
      }
   };

   // 将文件类别枚举中的每个枚举值都转为可读的字符串。
   template<>
   struct 转字符串类<文件类别枚举>
   {
      字符串类 operator () (const 文件类别枚举 &枚举项) const noexcept
      {
         switch (枚举项)
         {
            case 文件类别枚举::块设备:
               return C("[:enum 块设备 - BLOCK]");
            case 文件类别枚举::字符设备:
               return C("[:enum 字符设备 - CHARACTER]");
            case 文件类别枚举::目录:
               return C("[:enum 目录 - DIRECTORY]");
            case 文件类别枚举::管道:
               return C("[:enum 管道 - PIPE]");
            case 文件类别枚举::常规:
               return C("[:enum 常规 - REGULAR]");
            case 文件类别枚举::套接字:
               return C("[:enum 套接字 - SOCKET]");
            case 文件类别枚举::符号链接:
               return C("[:enum 符号链接 - SYMLINK]");
            case 文件类别枚举::其他:
               return C("[:enum 其他 - UNKNOWN]");
            default:
               return C("[:enum 非文件 - NONFILE]");
         }
      }
   };

   // 将 std::error_code 中的错误信息字符串转换为字符串类。
   template<>
   struct 转字符串类<std::error_code>
   {
      字符串类 operator () (const std::error_code &错误码) const noexcept
      {
         return 错误码.message();
      }
   };

}
