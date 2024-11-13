
namespace BE {

   namespace X {

      // 一些基本类型定义的集合。
      namespace T {

         using I8   = std::int8_t;
         using I16  = std::int16_t;
         using I32  = std::int32_t;
         using I64  = std::int64_t;
         using IMAX = std::intmax_t;
         using IPTR = std::intptr_t;
         
         using U8   = std::uint8_t;
         using U16  = std::uint16_t;
         using U32  = std::uint32_t;
         using U64  = std::uint64_t;
         using UMAX = std::uintmax_t;
         using UPTR = std::uintptr_t;

         using F32  = float;
         using F64  = double;
         using FMAX = long double;

         using VERSION = float;

         // UTF-8 编码字符串中字符的基本类型。
         using UTF8C = char8_t;
         // UTF-8 编码中存储一个字符编码所需的整数类型。
         using UTF8I = U32;

         // （semantic current）语义类型，通常用于表示目标的语义。
         struct SCur {};

         // （semantic place holder）语义类型，通常用于表示占位的语义。
         struct SPho {};

         // （semantic end）语义类型，通常用于表示结束的语义。
         struct SEnd {};

         // 语义类型，表示自己类型，提供一个 type 类型成员，用于获取自身类型。
         template<typename T>
         struct STyp { using type = T; };

      }

      // 一些函数库私有使用的集合。
      namespace R {

         template<unsigned int N>
         struct IntegerClass
         {
            static_assert(false, "Unsupported integer class");
         };

         template<>
         struct IntegerClass<8>
         {
            using type = T::I8;
         };

         template<>
         struct IntegerClass<16>
         {
            using type = T::I16;
         };

         template<>
         struct IntegerClass<32>
         {
            using type = T::I32;
         };

         template<>
         struct IntegerClass<64>
         {
            using type = T::I64;
         };

         template<unsigned int N>
         struct UnsignedClass
         {
            static_assert(false, "Unsupported unsigned class");
         };

         template<>
         struct UnsignedClass<8>
         {
            using type = T::U8;
         };

         template<>
         struct UnsignedClass<16>
         {
            using type = T::U16;
         };

         template<>
         struct UnsignedClass<32>
         {
            using type = T::U32;
         };

         template<>
         struct UnsignedClass<64>
         {
            using type = T::U64;
         };

         template<unsigned int N>
         struct FloatingClass
         {
            static_assert(false, "Unsupported floating class");
         };

         template<>
         struct FloatingClass<32>
         {
            using type = T::F32;
         };

         template<>
         struct FloatingClass<64>
         {
            using type = T::F64;
         }; 

      }

      // 一些测试函数的集合。
      namespace S {



      }

   }

   namespace T = X::T;

   // 长度类型，不包含负数。
   using 类型长度 = decltype(sizeof(int));

   // 存储哈希值的类型。
   using 类型哈希 = std::size_t;

   // 表示逻辑的类型。
   using 类型逻辑 = bool;

   // 表示比特的类型。
   using 类型比特 = bool;

   // 一般在比较操作中的返回值类型，如大于 0 通常表示大于，小于 0 通常表示小于，等于 0 通常表示相等。
   using 类型比较 = long long;

   // 函数库基本字符类型。
   using 类型字符 = char32_t;

   // 用于存储最小可表示存储单位值的类型。
   using 类型字节 = unsigned char;

   // nullptr 与 空指针 表示的类型。
   using 类型空值 = decltype(nullptr);

   // 表示错误字符串的类型。
   using 类型错误 = const char32_t *;

   // void 类型。
   using 类型空的 = void;

   // 表示进制值的类型。
   using 类型进制 = unsigned char;

   // 允许使用模板参数指定指定比特大小的整数类型。
   template<unsigned int N = 32>
   using 类型整数 = typename X::R::IntegerClass<N>::type;

   // 允许使用模板参数指定指定比特大小的无符号整数类型。
   template<unsigned int N = 32>
   using 类型无符 = typename X::R::UnsignedClass<N>::type;

   // 允许使用模板参数指定指定比特大小的浮点类型。
   template<unsigned int N = 64>
   using 类型浮点 = typename X::R::FloatingClass<N>::type;   

   // 在一些特殊函数中使用表示特殊效果的常量。
   inline constexpr 类型长度 到末尾 = static_cast<类型长度>(-1);

   // 浮点数转为字符串时支持的最大精度值。
   inline constexpr 类型长度 最大精度 = 256;

   // 浮点数转为字符串时，如果小数后面几位都是 0 则函数停止转换。
   inline constexpr 类型长度 连续零检查 = 3;

   // 浮点数转为字符串时，精度项的默认值。
   inline constexpr 类型长度 默认精度 = 6;

   // nullptr 的常量表示。
   inline constexpr 类型空值 空指针 = nullptr;

   // 错误字符串表示没有错误的常量。
   inline constexpr 类型错误 无错误 = C("没有错误信息。");

   // 表示当前系统是否为大端序的常量。
   inline constexpr 类型逻辑 大端序 = std::endian::native == std::endian::big;

   // true 的常量表示。
   inline constexpr 类型逻辑 真 = true;

   // false 的常量表示。
   inline constexpr 类型逻辑 假 = false;

   // 表示占位语义的常量。
   inline constexpr T::SPho  占位符 = {};

   // 表示结束语义的常量。
   inline constexpr T::SEnd  末尾值 = {};

   // 非类成员函数所使用存储错误信息的错误码。
   inline 类型错误 错误码 = 无错误;

   /**
    * \brief >>> 获取当前函数库的版本号，编译期函数。
    * 
    * \return 版本号。
    */
   inline consteval T::VERSION 获取版本号() noexcept
   {
      return 1.0f;
   }

   /**
    * \brief >>> 返回全局错误码并将全局错误码重置。
    * 
    * \return 错误信息。
    */
   inline 类型错误 获取错误码() noexcept
   {
      类型错误 错误 = 错误码;

      错误码 = 无错误;

      return 错误;
   }

   // 如果参数模板中的所有参数值都可以被转换为真则值为真，否则为假。
   template<auto... TmpArgs>
   inline constexpr 类型逻辑 全真值 = (static_cast<类型逻辑>(TmpArgs) && ...);

   // 如果参数模板中的至少一个参数值可以被转换为真则值为真，否则为假。
   template<auto... TmpArgs>
   inline constexpr 类型逻辑 有真值 = (static_cast<类型逻辑>(TmpArgs) || ...);

   /**
    * \brief >>> 去除参数项中的只读修饰符。
    * 
    * \param 参数项： 只读引用。
    * \return 去除只读修饰符后的参数项引用。
    */
   template<typename TmpT>
   inline constexpr TmpT &去除只读(const TmpT &参数项) noexcept
   {
      return const_cast<TmpT &>(参数项);
   }

   /**
    * \brief >>> 比较两者，并返回比较结果。
    * 
    * \param 左值项： 进行比较的对象。
    * \param 右值项： 进行比较的对象。
    * \return 左值项大于右值项则返回大于零的值，左值项小于右值项则返回小于零的值，相等则返回零。
    */
   template<typename TmpT>
   inline constexpr 类型比较 比较(TmpT &&左值项, typename T::STyp<TmpT>::type &&右值项) noexcept
   {
      return 左值项 > 右值项 ?  1 : (左值项 < 右值项 ? -1 : 0);
   }

}
