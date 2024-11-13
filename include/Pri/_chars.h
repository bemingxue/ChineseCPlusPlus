
namespace BE::X::R {

   // 判断一个小于 1 的浮点数的小数部分是否有大于 Count 个 0。
   inline constexpr auto IsDecimalZeroCount(浮点类型 auto X, 类型进制 Binary, 类型长度 Count) noexcept
   {
      while (static_cast<T::IMAX>(X * 10) <= 0 && Count != 0)
      {
         X = X * 10 - static_cast<T::IMAX>(X * 10);
         Count--;
      }

      return Count == 0;
   }

}
