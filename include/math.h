
namespace BE {

   /**
    * \brief >>> 根据数值项的正负获取 1 或 -1。
    * 
    * \param 数值项： 待获取符号的数值。
    * \return 如果是正数，则返回 1；如果是负数，则返回 -1。
    */
   template<标准数字类型 TmpT>
   inline constexpr TmpT 获取符号(TmpT 数值项) noexcept
   {
      if constexpr (无符类型<TmpT>)
      {
         return 1;
      }

      else
      {
         return std::signbit(数值项)? -1 : 1;
      }
   }

   namespace 数学集 {

      /**
       * \brief >>> 获取 X 的绝对值，允许无符号整数，可编译期计算。
       * 
       * \param X： 待求绝对值的数。
       * \return X 的绝对值。
       */
      inline constexpr auto 绝对值(标准数字类型 auto X) noexcept
      {
         if constexpr (无符类型<decltype(X)>)
         {
            return X;
         }

         else
         {
            return X > 0 ? X : -X;
         }
      }

      /**
       * \brief >>> 获取 X 除 Y 的余数，可以是浮点数。
       * 
       * \param X： 被除数。
       * \param Y： 除数。
       * \return X 除 Y 的余数。
       */
      inline constexpr auto 取余(标准数字类型 auto X, 标准数字类型 auto Y) noexcept
      {
         return std::fmod(X, Y);
      }

      /**
       * \brief >>> 获取两个数字的正差值。
       * 
       * \param X： 数值。
       * \param Y： 数值。
       * \return 如 X > Y，则返回 X - Y；否则返回 +0。
       */
      inline constexpr auto 正差(标准数字类型 auto X, 标准数字类型 auto Y) noexcept
      {
         return std::fdim(X, Y);
      }

      /**
       * \brief >>> 获取线性插值的值。
       * 
       * \param X： 数值。
       * \param Y： 数值。
       * \param Z： 数值，如果 [0，1] 范围内为内插，否则为外插。
       * \return 算术 { X + Z(Y - X) } 值。
       */
      inline constexpr auto 线性插值(标准数字类型 auto X, 标准数字类型 auto Y, 标准数字类型 auto Z) noexcept
      {
         return std::lerp(X, Y, Z);
      }

      /**
       * \brief >>> 获取对数计算的结果。
       * 
       * \param X： 底数。
       * \param Y： 指数。
       * \return 算术 { log(X)^Y } 值。
       */
      inline constexpr auto 对数(标准数字类型 auto X, 标准数字类型 auto Y) noexcept
      {
         return std::log(Y) / std::log(X);
      }

      /**
       * \brief >>> 获取幂运算的结果。
       * 
       * \param X： 底数。
       * \param Y： 指数。
       * \return 算术 { X^Y } 值。
       */
      inline constexpr auto 幂(标准数字类型 auto X, 标准数字类型 auto Y) noexcept
      {
         return std::pow(X, Y);
      }

      /**
       * \brief >>> 获取开平方运算的结果。
       * 
       * \param X： 数值。
       * \return 算术 { 2√X } 值。
       */
      inline constexpr auto 开平方根(标准数字类型 auto X) noexcept
      {
         return std::sqrt(X);
      }

      /**
       * \brief >>> 获取开立方根运算的结果。
       * 
       * \param X： 数值。
       * \return 算术 { 3√X } 值。
       */
      inline constexpr auto 开立方根(标准数字类型 auto X) noexcept
      {
         return std::cbrt(X);
      }

      /**
       * \brief >>> 获取直角三角斜边的长度。
       * 
       * \param X： 边长。
       * \param Y： 边长。
       * \return 算术 { √(X^2 + Y^2) } 值，也可以表示二维坐标到原点的距离。
       */
      inline constexpr auto 三角斜边(标准数字类型 auto X, 标准数字类型 auto Y) noexcept
      {
         return std::hypot(X, Y);
      }
      
      /**
       * \brief >>> 获取三维坐标到原点的距离。
       * 
       * \param X： 坐标。
       * \param Y： 坐标。
       * \param Z： 坐标。
       * \return 算术 { √(X^2 + Y^2 + Z^2) } 值。
       */
      inline constexpr auto 三维向量(标准数字类型 auto X, 标准数字类型 auto Y, 标准数字类型 auto Z) noexcept
      {
         return std::hypot(X, Y, Z);
      }

      /**
       * \brief >>> 获取正弦 sin 的值。
       * 
       * \param X： 弧度。
       * \return 算术 { sin(X) } 值。
       */
      inline constexpr auto 正弦(标准数字类型 auto X) noexcept
      {
         return std::sin(X);
      }

      /**
       * \brief >>> 获取余弦 cos 的值。
       * 
       * \param X： 弧度。
       * \return 算术 { cos(X) } 值。
       */
      inline constexpr auto 余弦(标准数字类型 auto X) noexcept
      {
         return std::cos(X);
      }

      /**
       * \brief >>> 获取正切 tan 的值。
       * 
       * \param X： 弧度。
       * \return 算术 { tan(X) } 值。
       */
      inline constexpr auto 正切(标准数字类型 auto X) noexcept
      {
         return std::tan(X);
      }

      /**
       * \brief >>> 获取反正弦 asin 的值。
       * 
       * \param X： 数值。
       * \return 算术 { asin(X) } 值。
       */
      inline constexpr auto 反正弦(标准数字类型 auto X) noexcept
      {
         return std::asin(X);
      }

      /**
       * \brief >>> 获取反余弦 acos 的值。
       * 
       * \param X： 数值。
       * \return 算术 { acos(X) } 值。
       */
      inline constexpr auto 反余弦(标准数字类型 auto X) noexcept
      {
         return std::acos(X);
      }

      /**
       * \brief >>> 获取反正切 atan 的值。
       * 
       * \param X： 数值。
       * \return 算术 { atan(X) } 值。
       */
      inline constexpr auto 反正切(标准数字类型 auto X) noexcept
      {
         return std::atan(X);
      }

      /**
       * \brief >>> 获取反正切 atan2 的值。
       * 
       * \param X： 数值。
       * \param Y： 数值。
       * \return 算术 { atan2(Y, X) } 值。
       */
      inline constexpr auto 反正切(标准数字类型 auto X, 标准数字类型 auto Y) noexcept
      {
         return std::atan2(Y, X);
      }

      /**
       * \brief >>> 获取双曲正弦 sinh 的值。
       * 
       * \param X： 弧度。
       * \return 算术 { sinh(X) } 值。
       */
      inline constexpr auto 双曲正弦(标准数字类型 auto X) noexcept
      {
         return std::sinh(X);
      }

      /**
       * \brief >>> 获取双曲余弦 cosh 的值。
       * 
       * \param X： 弧度。
       * \return 算术 { cosh(X) } 值。
       */
      inline constexpr auto 双曲余弦(标准数字类型 auto X) noexcept
      {
         return std::cosh(X);
      }

      /**
       * \brief >>> 获取双曲正切 tanh 的值。
       * 
       * \param X： 弧度。
       * \return 算术 { tanh(X) } 值。
       */
      inline constexpr auto 双曲正切(标准数字类型 auto X) noexcept
      {
         return std::tanh(X);
      }

      /**
       * \brief >>> 获取双曲反正弦 asinh 的值。
       * 
       * \param X： 数值。
       * \return 算术 { asinh(X) } 值。
       */
      inline constexpr auto 双曲反正弦(标准数字类型 auto X) noexcept
      {
         return std::asinh(X);
      }

      /**
       * \brief >>> 获取双曲反余弦 acosh 的值。
       * 
       * \param X： 数值。
       * \return 算术 { acosh(X) } 值。
       */
      inline constexpr auto 双曲反余弦(标准数字类型 auto X) noexcept
      {
         return std::acosh(X);
      }

      /**
       * \brief >>> 获取双曲反正切 atanh 的值。
       * 
       * \param X： 数值。
       * \return 算术 { atanh(X) } 值。
       */
      inline constexpr auto 双曲反正切(标准数字类型 auto X) noexcept
      {
         return std::atanh(X);
      }

      /**
       * \brief >>> 获取补误差的值。
       * 
       * \param X： 数值，如果为正无穷则结果为 0，负无穷则结果为 2。
       * \return 算术 { 1 - erf(X) } 值。
       */
      inline constexpr auto 补误差(标准数字类型 auto X) noexcept
      {
         return std::erfc(X);
      }

      /**
       * \brief >>> 获取伽马算术的值，也可以用于计算阶乘。
       * 
       * \param X： 数值，当要计算阶乘时，则应当加一，比如计算 5 的结果，则应当传入 6。
       * \return 算术 { Γ(X) } 值。
       */
      inline constexpr auto 伽马(标准数字类型 auto X) noexcept
      {
         return std::tgamma(X);
      }

      /**
       * \brief >>> 获取向上舍入的值。
       * 
       * \param X： 数值。
       * \return 不小于 X 的最近整数。
       */
      inline constexpr auto 向上舍入(标准数字类型 auto X) noexcept
      {
         return std::ceil(X);
      }

      /**
       * \brief >>> 获取向下舍入的值。
       * 
       * \param X： 数值。
       * \return 不大于 X 的最近整数。
       */
      inline constexpr auto 向下舍入(标准数字类型 auto X) noexcept
      {
         return std::floor(X);
      }

      /**
       * \brief >>> 获取向零舍入的值，行为类似于 int(X)。
       * 
       * \param X： 数值。
       * \return 最接近 0 的最近整数。
       */
      inline constexpr auto 向零舍入(标准数字类型 auto X) noexcept
      {
         return std::trunc(X);
      }

      /**
       * \brief >>> 获取向近舍入的值，以 0.5 为界限，行为类似于四舍五入，但只舍入一位小数。
       * 
       * \param X： 数值。
       * \return 最接近 X 的最近整数。
       */
      inline constexpr auto 向近舍入(标准数字类型 auto X) noexcept
      {
         return std::round(X);
      }

      /**
       * \brief >>> 将一个浮点数拆分为小数部分和指数部分并返回。
       * 
       * \param X： 数值。
       * \return 具有两个成员的结构体，成员“小数”为小数部分，成员“指数”为指数部分。
       */
      inline constexpr auto 分解幂(标准数字类型 auto X) noexcept
      {
         struct
         {
            decltype(std::frexp(X, nullptr)) 小数;
            类型整数<> 指数;

         } 返回值{ };

         返回值.小数 = std::frexp(X, &返回值.指数);

         return 返回值;
      }

      /**
       * \brief >>> 将一个小数和指数重新组合为一个浮点数。
       * 
       * \param X： 小数部分。
       * \param Y： 指数部分。
       * \return 算术 { X × 2^Y } 值。
       */
      inline constexpr auto 组合幂(标准数字类型 auto X, 类型整数<> &&Y) noexcept
      {
         return std::ldexp(X, Y);
      }

      /**
       * \brief >>> 获取浮点数的小数和整数部分。
       * 
       * \param X： 浮点数。
       * \return 一个结构体，成员“整数”为整数部分，成员“小数”为小数部分。
       */
      inline constexpr auto 分解浮点(标准数字类型 auto X) noexcept
      {
         struct
         {
            std::remove_reference_t<decltype(X)> 整数;
            std::remove_reference_t<decltype(X)> 小数;

         } 返回值 { };

         返回值.小数 = std::modf(X, &返回值.整数);

         return 返回值;
      }

      /**
       * \brief >>> 通过判断符号位来判断负数，因此可以判断 -0、-NaN、-Inf。
       * 
       * \param X： 数值。
       * \return 是否为负数。
       */
      inline constexpr auto 负数判断(标准数字类型 auto X) noexcept
      {
         return std::signbit(X);
      }

      /**
       * \brief >>> 判断数字是否为非数。
       * 
       * \param X： 数值。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr auto 非数判断(标准数字类型 auto X) noexcept
      {
         if constexpr (整数类型<decltype(X)>)
         {
            return false;
         }

         else
         {
            return std::isnan(X);
         }
      }

      /**
       * \brief >>> 判断数字是否为无穷。
       * 
       * \param X： 数值。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr auto 无限判断(标准数字类型 auto X) noexcept
      {
         if constexpr (整数类型<decltype(X)>)
         {
            return false;
         }

         else
         {
            return std::isinf(X);
         }
      }

      /**
       * \brief >>> 计算贝塔函数的值。
       * 
       * \param X： 数值。
       * \param Y： 数值。
       * \return 算术 { β(X，Y) } 值。
       */
      inline constexpr auto 贝塔(标准数字类型 auto X, 标准数字类型 auto Y) noexcept
      {
         return std::beta(X, Y);
      }

      /**
       * \brief >>> 计算指数积分的值。
       * 
       * \param X： 数值，为 ±0 时返回 -Inf。
       * \return 指数积分值。
       */
      inline constexpr auto 指数积分(标准数字类型 auto X) noexcept
      {
         return std::expint(X);
      }

      /**
       * \brief >>> 计算黎曼函数的值。
       * 
       * \param X： 数值。
       * \return 黎曼函数值。
       */
      inline constexpr auto 黎曼(标准数字类型 auto X) noexcept
      {
         return std::riemann_zeta(X);
      }

   }

}
