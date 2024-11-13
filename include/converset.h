
namespace BE {

   // 指定类型要转化为字符串可以指定的额外设定信息。
   enum class 转换枚举 : unsigned char
   {
      // 显示进制前缀。
      前缀显示 = (1 << 0),

      // 如果转换时出现英文字母则将其转换为小写。
      小写显示 = (1 << 1),

      // 是否使用分隔符。
      启用分隔 = (1 << 2),

      // 如果转换的小数长度不足时是否补充 0 到末尾。
      补充零值 = (1 << 3),

      // 规定字符类型是否参与格式化。
      字符格式 = (1 << 4),

      // 规定对于字符宽度作用于重复而非填充，此项高于字符格式。
      字符重复 = (1 << 5)
   };

   ::BE::转换枚举 operator | (::BE::转换枚举 左值项, ::BE::转换枚举 右值项) noexcept
   {
      return static_cast<::BE::转换枚举>(static_cast<::BE::模板枚举类型<::BE::转换枚举>>(左值项) | static_cast<::BE::模板枚举类型<::BE::转换枚举>>(右值项));
   }

   ::BE::转换枚举 operator & (::BE::转换枚举 左值项, ::BE::转换枚举 右值项) noexcept
   {
      return static_cast<::BE::转换枚举>(static_cast<::BE::模板枚举类型<::BE::转换枚举>>(左值项) & static_cast<::BE::模板枚举类型<::BE::转换枚举>>(右值项));
   }

   ::BE::转换枚举 operator ^ (::BE::转换枚举 左值项, ::BE::转换枚举 右值项) noexcept
   {
      return static_cast<::BE::转换枚举>(static_cast<::BE::模板枚举类型<::BE::转换枚举>>(左值项) ^ static_cast<::BE::模板枚举类型<::BE::转换枚举>>(右值项));
   }

   ::BE::转换枚举 operator ~ (::BE::转换枚举 项) noexcept
   {
      return static_cast<::BE::转换枚举>(~static_cast<::BE::模板枚举类型<::BE::转换枚举>>(项));
   }
}


