
#include "Pri/_modifier.h"

#include "Pri/_concepts.h"

namespace BE {

   // 用于在模板中指定多个类型规则都为真。
   template<typename, bool... TmpArgs>
   concept 类型与 = (... && TmpArgs);

   // 用于在模板中指定多个类型规则有一个为真。
   template<typename, bool... TmpArgs>
   concept 类型或 = (... || TmpArgs);

   // 用于在模板中指定多个类型规则都不为真。
   template<typename, bool... TmpArgs>
   concept 类型非 =!(... && TmpArgs);

   // 一种 STmpT 完全等于 TmpU 或 TmpArgs 列表中的任意一种类型的类型概念，可以使用 TmpU 为 SCur 则概念一定为真。
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept 相同类型 = std::is_same_v<TmpU, X::T::SCur> || 有真值<std::is_same_v<TmpT, TmpU>, std::is_same_v<TmpT, TmpArgs>...>;

   // 一种 STmpT 可以转换为 TmpU 以及 TmpArgs 中所有类型的类型概念，无视引用。
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept 转换类型 = 全真值<std::is_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpU>>, std::is_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 是一种字符类型的概念，无视 const、volatile、引用。
   template<typename TmpT>
   concept 字符类型 = 相同类型<std::remove_cvref_t<TmpT>, char, signed char, unsigned char, wchar_t, char16_t, char32_t, char8_t>;

   // 一种 STmpT 是有符号整数类型的概念，无视 const、volatile、引用。
   template<typename TmpT>
   concept 有符类型 = 相同类型<std::remove_cvref_t<TmpT>, signed char, short, int, long, long long>;

   // 一种 STmpT 是无符号整数类型的概念，包括 bool，无视 const、volatile、引用。
   template<typename TmpT>
   concept 无符类型 = 相同类型<std::remove_cvref_t<TmpT>, bool, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long>;

   // 一种 STmpT 是浮点数类型的概念，无视 const、volatile、引用。
   template<typename TmpT>
   concept 浮点类型 = 相同类型<std::remove_cvref_t<TmpT>, float, double, long double>;

   // 一种 STmpT 是整数类型（包含字符）的概念，无视 const、volatile、引用。
   template<typename TmpT>
   concept 整数类型 = 有符类型<TmpT> || 无符类型<TmpT> || 字符类型<TmpT>;

   // 一种 STmpT 时严格意义上的整数类型，即有符号整数、无符号整数，并且不包含 bool 和字符类型，无视 const、volatile、引用。
   template<typename TmpT>
   concept 严格整数类型 = (有符类型<TmpT> || 无符类型<TmpT>) && !相同类型<std::remove_cvref_t<TmpT>, bool>;

   // 一种 STmpT 是一个严格意义上的数字类型，即整数、浮点数，并且不包含逻辑和字符类型，无视 const、volatile、引用。
   template<typename TmpT>
   concept 严格数字类型 = (有符类型<TmpT> || 无符类型<TmpT> || 浮点类型<TmpT>) && !相同类型<std::remove_cvref_t<TmpT>, bool>;

   // 一种 STmpT 是标准数字类型，也就是整数、浮点数、字符类型的概念，无视 const、volatile、引用。
   template<typename TmpT>
   concept 标准数字类型 = 整数类型<TmpT> || 浮点类型<TmpT>;

   // 一种 STmpT 是 void 类型的概念。
   template<typename TmpT>
   concept 空的类型 = 相同类型<TmpT, void>;

   // 一种 STmpT 是 nullptr_t 类型的概念。
   template<typename TmpT>
   concept 空值类型 = 相同类型<TmpT, std::nullptr_t>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是 C Style 数组类型的概念，无视 const、volatile、引用。
   template<typename TmpT, typename... TmpArgs>
   concept 数组类型 = 全真值<std::is_array_v<std::remove_cvref_t<TmpT>>, std::is_array_v<std::remove_cvref_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是 enum、enum class类型的概念，无视 const、volatile、引用。
   template<typename TmpT, typename... TmpArgs>
   concept 枚举类型 = 全真值<std::is_enum_v<std::remove_cvref_t<TmpT>>, std::is_enum_v<std::remove_cvref_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是 union 的概念，无视 const、volatile、引用。
   template<typename TmpT, typename... TmpArgs>
   concept 联合类型 = 全真值<std::is_union_v<std::remove_cvref_t<TmpT>>, std::is_union_v<std::remove_cvref_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是 class、struct 的概念，无视 const、volatile、引用。
   template<typename TmpT, typename... TmpArgs>
   concept 类类型 = 全真值<std::is_class_v<std::remove_cvref_t<TmpT>>, std::is_class_v<std::remove_cvref_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是函数类型的概念，不包括函数指针等其他可调用类型。
   template<typename TmpT, typename... TmpArgs>
   concept 函数类型 = 全真值<std::is_function_v<TmpT>, std::is_function_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是指针类型的概念，无视 const、volatile、引用。
   template<typename TmpT, typename... TmpArgs>
   concept 指针类型 = 全真值<std::is_pointer_v<std::remove_cvref_t<TmpT>>, std::is_pointer_v<std::remove_cvref_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是左值引用类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 左值类型 = 全真值<std::is_lvalue_reference_v<TmpT>, std::is_lvalue_reference_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是右值引用类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 右值类型 = 全真值<std::is_rvalue_reference_v<TmpT>, std::is_rvalue_reference_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是成员指针对象类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 成员指针对象类型 = 全真值<std::is_member_pointer_v<TmpT>, std::is_member_pointer_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是成员指针函数类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 成员指针函数类型 = 全真值<std::is_member_function_pointer_v<TmpT>, std::is_member_function_pointer_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是成员指针类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 成员指针类型 = 全真值<std::is_member_pointer_v<TmpT>, std::is_member_pointer_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是左值或右值引用类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 引用类型 = 全真值<std::is_reference_v<TmpT>, std::is_reference_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是 const 修饰符修饰类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 只读类型 = 全真值<std::is_const_v<TmpT>, std::is_const_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是 volatile 修饰符修饰类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 易变类型 = 全真值<std::is_volatile_v<TmpT>, std::is_volatile_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是平凡类型的概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 平凡类型 = 全真值<std::is_trivial_v<std::remove_reference_t<TmpT>>, std::is_trivial_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是平凡复制，也就是可以直接进行内存间复制的类型概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 平凡复制类型 = 全真值<std::is_trivially_copyable_v<std::remove_reference_t<TmpT>>, std::is_trivially_copyable_v<std::remove_reference_t<TmpArgs>>...>;
   
   // 一种 STmpT 以及 TmpArgs 中所有类型是标准布局的类型概念，标准布局类型可以使用 offsetof 获取成员偏移量，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 标准布局类型 = 全真值<std::is_standard_layout_v<std::remove_reference_t<TmpT>>, std::is_standard_layout_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型的每一种值都只对应一个对象的概念，如 float 不是因为 NaN 对应多个值，存在填充位的类类型也不算，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 唯一对象类型 = 全真值<std::has_unique_object_representations_v<std::remove_reference_t<TmpT>>, std::has_unique_object_representations_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是没有非静态变量的类型概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 空类类型 = 全真值<std::is_empty_v<std::remove_reference_t<TmpT>>, std::is_empty_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型都是除函数、引用、void 类型外的任何可有 cv 限定的类型的概念。
   template<typename TmpT, typename... TmpArgs>
   concept 对象类型 = 全真值<std::is_object_v<TmpT>, std::is_object_v<TmpArgs>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型满足多态的类型概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 多态类型 = 全真值<std::is_polymorphic_v<std::remove_reference_t<TmpT>>, std::is_polymorphic_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是抽象的类型概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 抽象类型 = 全真值<std::is_abstract_v<std::remove_reference_t<TmpT>>, std::is_abstract_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是不可继承类型的概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 最终类型 = 全真值<std::is_final_v<std::remove_reference_t<TmpT>>, std::is_final_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型是聚合类型的概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 聚合类型 = 全真值<std::is_aggregate_v<std::remove_reference_t<TmpT>>, std::is_aggregate_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型都是可被 int 构造并且可相等比较，并且 STmpT(-1) < STmpT(0) 的类型概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 有符算术类型 = 全真值<std::is_signed_v<std::remove_reference_t<TmpT>>, std::is_signed_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型都是可被 int 构造并且可相等比较，并且 STmpT(-1) > STmpT(0) 的类型概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 无符算术类型 = 全真值<std::is_unsigned_v<std::remove_reference_t<TmpT>>, std::is_unsigned_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型都是具有具体长度的数组类型的概念，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 边界数组类型 = 全真值<std::is_bounded_array_v<std::remove_reference_t<TmpT>>, std::is_bounded_array_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 以及 TmpArgs 中所有类型都是没有具体长度的数组类型的概念，如 int[]，无视引用。
   template<typename TmpT, typename... TmpArgs>
   concept 无界数组类型 = 全真值<std::is_unbounded_array_v<std::remove_reference_t<TmpT>>, std::is_unbounded_array_v<std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 可以进行 STmpT(TmpArgs...) 构造的类型概念。
   template<typename TmpT, typename... TmpArgs>
   concept 构造类型 = std::is_constructible_v<TmpT, TmpArgs...>;

   // 一种 STmpT 可以进行 STmpT(TmpArgs...) 平凡构造的类型概念。
   template<typename TmpT, typename... TmpArgs>
   concept 平凡构造类型 = std::is_trivially_constructible_v<TmpT, TmpArgs...>;

   // 一种 STmpT 可以进行 STmpT(TmpArgs...) 安全构造的类型概念。
   template<typename TmpT, typename... TmpArgs>
   concept 安全构造类型 = std::is_nothrow_constructible_v<TmpT, TmpArgs...>;

   // 一种 STmpT 可以进行 STmpT() 构造的类型概念。
   template<typename TmpT>
   concept 默认构造类型 = std::is_default_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT() 平凡构造的类型概念。
   template<typename TmpT>
   concept 平凡默认构造类型 = std::is_trivially_default_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT() 安全构造的类型概念。
   template<typename TmpT>
   concept 安全默认构造类型 = std::is_nothrow_default_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT(const STmpT&) 构造的类型概念。
   template<typename TmpT>
   concept 复制构造类型 = std::is_copy_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT(const STmpT&) 平凡构造的类型概念。
   template<typename TmpT>
   concept 平凡复制构造类型 = std::is_trivially_copy_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT(const STmpT&) 安全构造的类型概念。
   template<typename TmpT>
   concept 安全复制构造类型 = std::is_nothrow_copy_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT(STmpT&&) 构造的类型概念。
   template<typename TmpT>
   concept 移动构造类型 = std::is_move_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT(STmpT&&) 平凡构造的类型概念。
   template<typename TmpT>
   concept 平凡移动构造类型 = std::is_trivially_move_constructible_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT(STmpT&&) 安全构造的类型概念。
   template<typename TmpT>
   concept 安全移动构造类型 = std::is_nothrow_move_constructible_v<TmpT>;

   // 一种 STmpT 可以与 TmpU 以及 TmpArgs 列表中的所有类型进行赋值运算的类型概念，允许使用 SCur 语义类型表示 TmpT，也可以给 SCur 添加修饰符，如 SCur & 表示 STmpT &。
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept 赋值类型 = 全真值<X::R::CorrectAssignmentConcept<TmpT &, TmpU>::value, X::R::CorrectAssignmentConcept<TmpT &, TmpArgs>::value...>;

   // 一种 STmpT 可以与 TmpU 以及 TmpArgs 列表中的所有类型进行平凡赋值运算的类型概念，允许使用 SCur 语义类型表示 TmpT，也可以给 SCur 添加修饰符，如 SCur & 表示 STmpT &。
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept 平凡赋值类型 = 全真值<X::R::CorrectTrivialAssignmentConcept<TmpT &, TmpU>::value, X::R::CorrectTrivialAssignmentConcept<TmpT &, TmpArgs>::value...>;

   // 一种 STmpT 可以与 TmpU 以及 TmpArgs 列表中的所有类型进行安全赋值运算的类型概念，允许使用 SCur 语义类型表示 TmpT，也可以给 SCur 添加修饰符，如 SCur & 表示 STmpT &。
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept 安全赋值类型 = 全真值<X::R::CorrectNothrowAssignmentConcept<TmpT &, TmpU>::value, X::R::CorrectNothrowAssignmentConcept<TmpT &, TmpArgs>::value...>;

   // 一种 STmpT 可以进行 STmpT = STmpT 赋值的类型概念。
   template<typename TmpT>
   concept 复制赋值类型 = std::is_copy_assignable_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT = STmpT 平凡赋值的类型概念。
   template<typename TmpT>
   concept 平凡复制赋值类型 = std::is_trivially_copy_assignable_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT = STmpT 安全赋值的类型概念。
   template<typename TmpT>
   concept 安全复制赋值类型 = std::is_nothrow_copy_assignable_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT = STmpT 移动赋值的类型概念。
   template<typename TmpT>
   concept 移动赋值类型 = std::is_move_assignable_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT = STmpT 平凡移动赋值的类型概念。
   template<typename TmpT>
   concept 平凡移动赋值类型 = std::is_trivially_move_assignable_v<TmpT>;

   // 一种 STmpT 可以进行 STmpT = STmpT 安全移动赋值的类型概念。
   template<typename TmpT>
   concept 安全移动赋值类型 = std::is_nothrow_move_assignable_v<TmpT>;

   // 一种 STmpT 可以进行析构的类型概念。
   template<typename TmpT>
   concept 析构类型 = std::is_destructible_v<TmpT>;

   // 一种 STmpT 可以进行平凡析构的类型概念。
   template<typename TmpT>
   concept 平凡析构类型 = std::is_trivially_destructible_v<TmpT>;

   // 一种 STmpT 可以进行安全析构的类型概念。
   template<typename TmpT>
   concept 安全析构类型 = std::is_nothrow_destructible_v<TmpT>;

   // 一种 STmpT 具有虚析构函数的类型概念。
   template<typename TmpT>
   concept 虚析构类型 = std::has_virtual_destructor_v<TmpT>;

   // 一种 STmpT 继承自 TmpU 的类型概念，忽略 cv 修饰符，当是类类型时，即使 STmpT = TmpU 概念也算正确，因为满足 "is-a" 关系。
   template<typename TmpT, typename TmpU>
   concept 父子类型 = std::is_base_of_v<TmpU, TmpT>;

   // 一种 STmpT 可以安全转换位 TmpU 以及 TmpArgs 列表中的所有类型的概念，无视引用。
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept 安全转换类型 = 全真值<std::is_nothrow_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpU>>, std::is_nothrow_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpArgs>>...>;

   // 一种 STmpT 和 TmpU 布局兼容的类型概念。
   template<typename TmpT, typename TmpU>
   concept 布局兼容类型 = std::is_layout_compatible_v<TmpT, TmpU>;

   // 一种 TmpCall 可以进行 TmpCall(TmpArgs...) 调用的类型概念。 
   template<typename TmpCall, typename... TmpArgs>
   concept 调用类型 = std::is_invocable_v<TmpCall, TmpArgs...>;

   // 一种 TmpCall 可以进行 TmpCall(TmpArgs...) 安全调用的类型概念。
   template<typename TmpCall, typename... TmpArgs>
   concept 安全调用类型 = std::is_nothrow_invocable_v<TmpCall, TmpArgs...>;

   // 一种 TmpCall 可以进行 TmpCall(TmpArgs...) 调用并且返回值类型可以转换为 TmpRet 的类型概念。
   template<typename TmpCall, typename TmpRet, typename... TmpArgs>
   concept 调用返回类型 = std::is_invocable_r_v<TmpRet, TmpCall, TmpArgs...>;

   // 一种 TmpCall 可以进行 TmpCall(TmpArgs...) 安全调用并且返回值类型可以转换为 TmpRet 的类型概念。
   template<typename TmpCall, typename TmpRet, typename... TmpArgs>
   concept 安全调用返回类型 = std::is_nothrow_invocable_r_v<TmpRet, TmpCall, TmpArgs...>;



   //////////////////////////////////////////////////////////////////////////////////



   // 一种 const STmpT 可以与 const TmpU 进行 == 与 != 操作并且返回值类型可以转换为逻辑类型的概念。
   template<typename TmpT, typename TmpU = TmpT>
   concept 相等类型 = requires(const TmpT X, const TmpU Y) {
      { X == Y } -> 转换类型<类型逻辑>;
      { X != Y } -> 转换类型<类型逻辑>;
   };

   // 一种 const STmpT 可以与 const TmpU 进行 > 、 >= 、 < 、 <= 操作并且返回值类型可以转换为逻辑类型的概念。
   template<typename TmpT, typename TmpU = TmpT>
   concept 比较类型 = requires(const TmpT X, const TmpU Y) {
      { X >  Y } -> 转换类型<类型逻辑>;
      { X >= Y } -> 转换类型<类型逻辑>;
      { X <  Y } -> 转换类型<类型逻辑>;
      { X <= Y } -> 转换类型<类型逻辑>;
   };

   // 一种 const STmpT 可以与 const TmpU 进行 ==、!=、>、>=、<、<= 操作并且返回值类型可以转换为逻辑类型的概念。
   template<typename TmpT, typename TmpU = TmpT>
   concept 逻辑类型 = 相等类型<TmpT, TmpU> && 比较类型<TmpT, TmpU>;

   // 一种 STmpT 可以和 TmpU 进行 +、-、*、/ 操作并且返回值类型可以转换为 TmpT，以及 +=、-=、*=、/= 操作返回值类型可以转换为 STmpT& 的概念，指定 TmpModel 还表示可以进行 % 和 %= 运算。
   template<typename TmpT, typename TmpU = TmpT, 类型逻辑 TmpModel = false>
   concept 算术类型 = requires(TmpT X, TmpU Y) {

      { X + Y } -> 转换类型<TmpT>;
      { X - Y } -> 转换类型<TmpT>;
      { X * Y } -> 转换类型<TmpT>;
      { X / Y } -> 转换类型<TmpT>;

      { X += Y } -> 相同类型<TmpT&>;
      { X -= Y } -> 相同类型<TmpT&>;
      { X *= Y } -> 相同类型<TmpT&>;
      { X /= Y } -> 相同类型<TmpT&>;

   } && (TmpModel &&requires(TmpT X, TmpU Y) {
      { X %  Y }-> 转换类型<TmpT>;
      { X %= Y }-> 相同类型<TmpT&>;
   });

   // 一种 STmpT 可以进行 ++STmpT 与 --STmpT 操作并且返回本身的类型概念。
   template<typename TmpT>
   concept 自增减类型 = requires(TmpT X) {
      { ++X } -> 相同类型<TmpT&>;
      { --X } -> 相同类型<TmpT&>;
   };

   // 一种具有整数性质并且可以和 T::IMAX 进行算术、逻辑、比较、赋值的类型概念。
   template<typename TmpT>
   concept 泛整数类型 = 算术类型<TmpT, TmpT, 真> && 算术类型<TmpT, T::IMAX, 真> && 逻辑类型<TmpT> && 逻辑类型<TmpT, T::IMAX> && 赋值类型<TmpT, T::IMAX> && 自增减类型<TmpT>;

   // 一种具有浮点性质并且可以和 T::FMAX 进行算术、逻辑、比较、赋值的类型概念，并且可以转换为 T::IMAX 类型。
   template<typename TmpT>
   concept 泛浮点类型 = 算术类型<TmpT> && 算术类型<TmpT, T::FMAX> && 逻辑类型<TmpT> && 逻辑类型<TmpT, T::FMAX> && 赋值类型<TmpT, T::FMAX> && 自增减类型<TmpT> && 转换类型<TmpT, T::IMAX>;

   // 一种能进行算术、逻辑、比较、默认构造、自增减，并且还能和 int 类型进行算术、逻辑、比较、赋值的类型概念。
   template<typename TmpT>
   concept 数字类型 = 泛整数类型<TmpT> || 泛浮点类型<TmpT>;

   // 一种 STmpT 能够和 nullptr 进行 ==、!= 操作并且可以赋值为 nullptr 的概念。
   template<typename TmpT>
   concept 可空类型 = 相等类型<TmpT, std::nullptr_t> && 赋值类型<TmpT, std::nullptr_t>;

   // 一种 TmpCall 可以进行 TmpCall(STmpT, TmpU) 调用并且返回值类型可以转换为类型逻辑的类型概念。
   template<typename TmpCall, typename TmpT, typename TmpU>
   concept 比较调用类型 = 调用返回类型<TmpCall, 类型逻辑, TmpT, TmpU>;

   // 一种 STmpT 可以使用 插入 成员函数向 STmpT 内添加 TmpU 类型的类型概念。
   template<typename TmpT, typename TmpU>
   concept 可增加容器类型 = requires(TmpT X, TmpU Y) {
      X.插入(Y);
   };

}
