
#include "./Pri/_tmptype.h"

namespace BE {

   // 一种 STmpT 的列表类型，如 int 列表类型为 std::initializer_list<int>。
   template<typename TmpT>
   using 模板列表类型 = std::initializer_list<TmpT>;

   // 一种 STmpT 会在传参中被退化的类型，如 int[] 会被退化位 int*。
   template<typename TmpT>
   using 模板退化类型 = std::decay_t<TmpT>;

   // 一种 STmpT 是枚举时，它的底层类型，如果不是枚举，则类型 error-type。
   template<typename TmpT>
   using 模板枚举类型 = std::underlying_type_t<TmpT>;

   // 一种 STmpT 进行解引用运算后的返回值类型，一般解引用的结果均为引用，如 int * 解引用为 int&，不能解引用则类型 error-type。
   template<typename TmpT>
   using 模板解引类型 = decltype(*std::declval<TmpT &>());

   // 一种 TmpArgs 中所有类型都可以转换为的共同类型，如果没有则类型 error-type。
   template<typename... TmpArgs>
   using 模板公共类型 = std::common_type_t<TmpArgs...>;

   // 一种 TmpArgs 中所有类型都可以转换为的共同引用类型，如果没有则类型 error-type。
   template<typename... TmpArgs>
   using 模板公共引用 = std::common_reference_t<TmpArgs...>;

   // 一种 TmpCall 进行 TmpCall(TmpArgs...) 调用时的返回值类型，如果 TmpCall 无符调用，则类型 error-type。
   template<typename TmpCall, typename... TmpArgs>
   using 模板返回类型 = std::invoke_result_t<TmpCall, TmpArgs...>;

   // 一种移除 STmpT 所有修饰符后的类型。
   template<typename TmpT>
   using 模板移除修饰 = typename X::R::RemoveAllModifier<TmpT>::type;

   // 一种移除 STmpT 所有修饰并将 TmpU 的所有修饰移动到 STmpT 上的类型。
   template<typename TmpT, typename TmpU>
   using 模板转移修饰 = typename X::R::MoveModifierType<TmpT, TmpU>::type;

   // 一种 STmpT 对应的无符号整数类型，对于无符号的则原样表示，对于有符号的 char、short、int、long、long long 提供对应的 unsigned 版本，对于枚举和字符，提供字节大小相同的无符号整数类型，否则类型 error-type。
   template<typename TmpT>
   using 模板无符整数 = std::make_unsigned_t<TmpT>;

   // 一种 STmpT 对应的有符号整数类型，对于有符号的则原样表示，对于无符号的 char、short、int、long、long long 提供对应的 signed 版本，对于枚举和字符，提供字节大小相同的有符号整数类型，否则类型 error-type。
   template<typename TmpT>
   using 模板有符整数 = std::make_signed_t<TmpT>;

   // 一种允许你使用编译期条件来选择类型，TmpCondition 为 true 时选择 TmpTrueT，TmpCondition 为 false 时选择 TmpFalseT。
   template<bool TmpCondition, typename TmpTrueT, typename TmpFalseT>
   using 模板条件类型 = std::conditional_t<TmpCondition, TmpTrueT, TmpFalseT>;

}
