
namespace BE::X::R {

   // �ж�һ��С�� 1 �ĸ�������С�������Ƿ��д��� Count �� 0��
   inline constexpr auto IsDecimalZeroCount(�������� auto X, ���ͽ��� Binary, ���ͳ��� Count) noexcept
   {
      while (static_cast<T::IMAX>(X * 10) <= 0 && Count != 0)
      {
         X = X * 10 - static_cast<T::IMAX>(X * 10);
         Count--;
      }

      return Count == 0;
   }

}
