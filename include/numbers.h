
namespace BE {

   namespace 数学集 {

      // 圆周率 π 的值。
      template<标准数字类型 TmpNum = 类型浮点<>>
      inline constexpr const TmpNum 圆周率 = std::numbers::pi_v<T>;

      // 自然常数 e 的值。
      template<标准数字类型 TmpNum = 类型浮点<>>
      inline constexpr const TmpNum 自然常数 = std::numbers::e_v<T>;

      // 伽马常数 γ 的值。
      template<标准数字类型 TmpNum = 类型浮点<>>
      inline constexpr const TmpNum 伽马常数 = std::numbers::egamma_v<T>;

      // 黄金分割数 φ 的值。
      template<标准数字类型 TmpNum = 类型浮点<>>
      inline constexpr const TmpNum 黄金分割数 = std::numbers::phi_v<T>;

      // 计算 TmpV 的 TmpIndex 次方值，TmpIndex 只能是无符号整数类型。
      template<标准数字类型 auto TmpV, 类型无符<> TmpIndex, 标准数字类型 TmpNum = decltype(TmpV)>
      inline constexpr const TmpNum 整数幂 = 整数幂<TmpV, TmpIndex - 1, TmpNum> * TmpV;

      // 计算 TmpV 的 TmpIndex 次方值，TmpIndex 只能是无符号整数类型。
      template<标准数字类型 auto TmpV, 标准数字类型 TmpNum>
      inline constexpr const TmpNum 整数幂<TmpV, 0, TmpNum> = 1;

   }

}
