
#include "Pri/_modifier.h"

#include "Pri/_concepts.h"

namespace BE {

   // ������ģ����ָ��������͹���Ϊ�档
   template<typename, bool... TmpArgs>
   concept ������ = (... && TmpArgs);

   // ������ģ����ָ��������͹�����һ��Ϊ�档
   template<typename, bool... TmpArgs>
   concept ���ͻ� = (... || TmpArgs);

   // ������ģ����ָ��������͹��򶼲�Ϊ�档
   template<typename, bool... TmpArgs>
   concept ���ͷ� =!(... && TmpArgs);

   // һ�� STmpT ��ȫ���� TmpU �� TmpArgs �б��е�����һ�����͵����͸������ʹ�� TmpU Ϊ SCur �����һ��Ϊ�档
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept ��ͬ���� = std::is_same_v<TmpU, X::T::SCur> || ����ֵ<std::is_same_v<TmpT, TmpU>, std::is_same_v<TmpT, TmpArgs>...>;

   // һ�� STmpT ����ת��Ϊ TmpU �Լ� TmpArgs ���������͵����͸���������á�
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept ת������ = ȫ��ֵ<std::is_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpU>>, std::is_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT ��һ���ַ����͵ĸ������ const��volatile�����á�
   template<typename TmpT>
   concept �ַ����� = ��ͬ����<std::remove_cvref_t<TmpT>, char, signed char, unsigned char, wchar_t, char16_t, char32_t, char8_t>;

   // һ�� STmpT ���з����������͵ĸ������ const��volatile�����á�
   template<typename TmpT>
   concept �з����� = ��ͬ����<std::remove_cvref_t<TmpT>, signed char, short, int, long, long long>;

   // һ�� STmpT ���޷����������͵ĸ������ bool������ const��volatile�����á�
   template<typename TmpT>
   concept �޷����� = ��ͬ����<std::remove_cvref_t<TmpT>, bool, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long>;

   // һ�� STmpT �Ǹ��������͵ĸ������ const��volatile�����á�
   template<typename TmpT>
   concept �������� = ��ͬ����<std::remove_cvref_t<TmpT>, float, double, long double>;

   // һ�� STmpT ���������ͣ������ַ����ĸ������ const��volatile�����á�
   template<typename TmpT>
   concept �������� = �з�����<TmpT> || �޷�����<TmpT> || �ַ�����<TmpT>;

   // һ�� STmpT ʱ�ϸ������ϵ��������ͣ����з����������޷������������Ҳ����� bool ���ַ����ͣ����� const��volatile�����á�
   template<typename TmpT>
   concept �ϸ��������� = (�з�����<TmpT> || �޷�����<TmpT>) && !��ͬ����<std::remove_cvref_t<TmpT>, bool>;

   // һ�� STmpT ��һ���ϸ������ϵ��������ͣ��������������������Ҳ������߼����ַ����ͣ����� const��volatile�����á�
   template<typename TmpT>
   concept �ϸ��������� = (�з�����<TmpT> || �޷�����<TmpT> || ��������<TmpT>) && !��ͬ����<std::remove_cvref_t<TmpT>, bool>;

   // һ�� STmpT �Ǳ�׼�������ͣ�Ҳ�������������������ַ����͵ĸ������ const��volatile�����á�
   template<typename TmpT>
   concept ��׼�������� = ��������<TmpT> || ��������<TmpT>;

   // һ�� STmpT �� void ���͵ĸ��
   template<typename TmpT>
   concept �յ����� = ��ͬ����<TmpT, void>;

   // һ�� STmpT �� nullptr_t ���͵ĸ��
   template<typename TmpT>
   concept ��ֵ���� = ��ͬ����<TmpT, std::nullptr_t>;

   // һ�� STmpT �Լ� TmpArgs ������������ C Style �������͵ĸ������ const��volatile�����á�
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_array_v<std::remove_cvref_t<TmpT>>, std::is_array_v<std::remove_cvref_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ enum��enum class���͵ĸ������ const��volatile�����á�
   template<typename TmpT, typename... TmpArgs>
   concept ö������ = ȫ��ֵ<std::is_enum_v<std::remove_cvref_t<TmpT>>, std::is_enum_v<std::remove_cvref_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ union �ĸ������ const��volatile�����á�
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_union_v<std::remove_cvref_t<TmpT>>, std::is_union_v<std::remove_cvref_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ class��struct �ĸ������ const��volatile�����á�
   template<typename TmpT, typename... TmpArgs>
   concept ������ = ȫ��ֵ<std::is_class_v<std::remove_cvref_t<TmpT>>, std::is_class_v<std::remove_cvref_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs �����������Ǻ������͵ĸ������������ָ��������ɵ������͡�
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_function_v<TmpT>, std::is_function_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ָ�����͵ĸ������ const��volatile�����á�
   template<typename TmpT, typename... TmpArgs>
   concept ָ������ = ȫ��ֵ<std::is_pointer_v<std::remove_cvref_t<TmpT>>, std::is_pointer_v<std::remove_cvref_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ��������������ֵ�������͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept ��ֵ���� = ȫ��ֵ<std::is_lvalue_reference_v<TmpT>, std::is_lvalue_reference_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs ��������������ֵ�������͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept ��ֵ���� = ȫ��ֵ<std::is_rvalue_reference_v<TmpT>, std::is_rvalue_reference_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs �����������ǳ�Աָ��������͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept ��Աָ��������� = ȫ��ֵ<std::is_member_pointer_v<TmpT>, std::is_member_pointer_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs �����������ǳ�Աָ�뺯�����͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept ��Աָ�뺯������ = ȫ��ֵ<std::is_member_function_pointer_v<TmpT>, std::is_member_function_pointer_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs �����������ǳ�Աָ�����͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept ��Աָ������ = ȫ��ֵ<std::is_member_pointer_v<TmpT>, std::is_member_pointer_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs ��������������ֵ����ֵ�������͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_reference_v<TmpT>, std::is_reference_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ const ���η��������͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept ֻ������ = ȫ��ֵ<std::is_const_v<TmpT>, std::is_const_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ volatile ���η��������͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept �ױ����� = ȫ��ֵ<std::is_volatile_v<TmpT>, std::is_volatile_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ƽ�����͵ĸ���������á�
   template<typename TmpT, typename... TmpArgs>
   concept ƽ������ = ȫ��ֵ<std::is_trivial_v<std::remove_reference_t<TmpT>>, std::is_trivial_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ������������ƽ�����ƣ�Ҳ���ǿ���ֱ�ӽ����ڴ�临�Ƶ����͸���������á�
   template<typename TmpT, typename... TmpArgs>
   concept ƽ���������� = ȫ��ֵ<std::is_trivially_copyable_v<std::remove_reference_t<TmpT>>, std::is_trivially_copyable_v<std::remove_reference_t<TmpArgs>>...>;
   
   // һ�� STmpT �Լ� TmpArgs �����������Ǳ�׼���ֵ����͸����׼�������Ϳ���ʹ�� offsetof ��ȡ��Աƫ�������������á�
   template<typename TmpT, typename... TmpArgs>
   concept ��׼�������� = ȫ��ֵ<std::is_standard_layout_v<std::remove_reference_t<TmpT>>, std::is_standard_layout_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ���������͵�ÿһ��ֵ��ֻ��Ӧһ������ĸ���� float ������Ϊ NaN ��Ӧ���ֵ���������λ��������Ҳ���㣬�������á�
   template<typename TmpT, typename... TmpArgs>
   concept Ψһ�������� = ȫ��ֵ<std::has_unique_object_representations_v<std::remove_reference_t<TmpT>>, std::has_unique_object_representations_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ������������û�зǾ�̬���������͸���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_empty_v<std::remove_reference_t<TmpT>>, std::is_empty_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ���������Ͷ��ǳ����������á�void ��������κο��� cv �޶������͵ĸ��
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_object_v<TmpT>, std::is_object_v<TmpArgs>...>;

   // һ�� STmpT �Լ� TmpArgs ���������������̬�����͸���������á�
   template<typename TmpT, typename... TmpArgs>
   concept ��̬���� = ȫ��ֵ<std::is_polymorphic_v<std::remove_reference_t<TmpT>>, std::is_polymorphic_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs �����������ǳ�������͸���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_abstract_v<std::remove_reference_t<TmpT>>, std::is_abstract_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs �����������ǲ��ɼ̳����͵ĸ���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �������� = ȫ��ֵ<std::is_final_v<std::remove_reference_t<TmpT>>, std::is_final_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs �����������Ǿۺ����͵ĸ���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �ۺ����� = ȫ��ֵ<std::is_aggregate_v<std::remove_reference_t<TmpT>>, std::is_aggregate_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ���������Ͷ��ǿɱ� int ���첢�ҿ���ȱȽϣ����� STmpT(-1) < STmpT(0) �����͸���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �з��������� = ȫ��ֵ<std::is_signed_v<std::remove_reference_t<TmpT>>, std::is_signed_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ���������Ͷ��ǿɱ� int ���첢�ҿ���ȱȽϣ����� STmpT(-1) > STmpT(0) �����͸���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �޷��������� = ȫ��ֵ<std::is_unsigned_v<std::remove_reference_t<TmpT>>, std::is_unsigned_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ���������Ͷ��Ǿ��о��峤�ȵ��������͵ĸ���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �߽��������� = ȫ��ֵ<std::is_bounded_array_v<std::remove_reference_t<TmpT>>, std::is_bounded_array_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �Լ� TmpArgs ���������Ͷ���û�о��峤�ȵ��������͵ĸ���� int[]���������á�
   template<typename TmpT, typename... TmpArgs>
   concept �޽��������� = ȫ��ֵ<std::is_unbounded_array_v<std::remove_reference_t<TmpT>>, std::is_unbounded_array_v<std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT ���Խ��� STmpT(TmpArgs...) ��������͸��
   template<typename TmpT, typename... TmpArgs>
   concept �������� = std::is_constructible_v<TmpT, TmpArgs...>;

   // һ�� STmpT ���Խ��� STmpT(TmpArgs...) ƽ����������͸��
   template<typename TmpT, typename... TmpArgs>
   concept ƽ���������� = std::is_trivially_constructible_v<TmpT, TmpArgs...>;

   // һ�� STmpT ���Խ��� STmpT(TmpArgs...) ��ȫ��������͸��
   template<typename TmpT, typename... TmpArgs>
   concept ��ȫ�������� = std::is_nothrow_constructible_v<TmpT, TmpArgs...>;

   // һ�� STmpT ���Խ��� STmpT() ��������͸��
   template<typename TmpT>
   concept Ĭ�Ϲ������� = std::is_default_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT() ƽ����������͸��
   template<typename TmpT>
   concept ƽ��Ĭ�Ϲ������� = std::is_trivially_default_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT() ��ȫ��������͸��
   template<typename TmpT>
   concept ��ȫĬ�Ϲ������� = std::is_nothrow_default_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT(const STmpT&) ��������͸��
   template<typename TmpT>
   concept ���ƹ������� = std::is_copy_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT(const STmpT&) ƽ����������͸��
   template<typename TmpT>
   concept ƽ�����ƹ������� = std::is_trivially_copy_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT(const STmpT&) ��ȫ��������͸��
   template<typename TmpT>
   concept ��ȫ���ƹ������� = std::is_nothrow_copy_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT(STmpT&&) ��������͸��
   template<typename TmpT>
   concept �ƶ��������� = std::is_move_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT(STmpT&&) ƽ����������͸��
   template<typename TmpT>
   concept ƽ���ƶ��������� = std::is_trivially_move_constructible_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT(STmpT&&) ��ȫ��������͸��
   template<typename TmpT>
   concept ��ȫ�ƶ��������� = std::is_nothrow_move_constructible_v<TmpT>;

   // һ�� STmpT ������ TmpU �Լ� TmpArgs �б��е��������ͽ��и�ֵ��������͸������ʹ�� SCur �������ͱ�ʾ TmpT��Ҳ���Ը� SCur ������η����� SCur & ��ʾ STmpT &��
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept ��ֵ���� = ȫ��ֵ<X::R::CorrectAssignmentConcept<TmpT &, TmpU>::value, X::R::CorrectAssignmentConcept<TmpT &, TmpArgs>::value...>;

   // һ�� STmpT ������ TmpU �Լ� TmpArgs �б��е��������ͽ���ƽ����ֵ��������͸������ʹ�� SCur �������ͱ�ʾ TmpT��Ҳ���Ը� SCur ������η����� SCur & ��ʾ STmpT &��
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept ƽ����ֵ���� = ȫ��ֵ<X::R::CorrectTrivialAssignmentConcept<TmpT &, TmpU>::value, X::R::CorrectTrivialAssignmentConcept<TmpT &, TmpArgs>::value...>;

   // һ�� STmpT ������ TmpU �Լ� TmpArgs �б��е��������ͽ��а�ȫ��ֵ��������͸������ʹ�� SCur �������ͱ�ʾ TmpT��Ҳ���Ը� SCur ������η����� SCur & ��ʾ STmpT &��
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept ��ȫ��ֵ���� = ȫ��ֵ<X::R::CorrectNothrowAssignmentConcept<TmpT &, TmpU>::value, X::R::CorrectNothrowAssignmentConcept<TmpT &, TmpArgs>::value...>;

   // һ�� STmpT ���Խ��� STmpT = STmpT ��ֵ�����͸��
   template<typename TmpT>
   concept ���Ƹ�ֵ���� = std::is_copy_assignable_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT = STmpT ƽ����ֵ�����͸��
   template<typename TmpT>
   concept ƽ�����Ƹ�ֵ���� = std::is_trivially_copy_assignable_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT = STmpT ��ȫ��ֵ�����͸��
   template<typename TmpT>
   concept ��ȫ���Ƹ�ֵ���� = std::is_nothrow_copy_assignable_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT = STmpT �ƶ���ֵ�����͸��
   template<typename TmpT>
   concept �ƶ���ֵ���� = std::is_move_assignable_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT = STmpT ƽ���ƶ���ֵ�����͸��
   template<typename TmpT>
   concept ƽ���ƶ���ֵ���� = std::is_trivially_move_assignable_v<TmpT>;

   // һ�� STmpT ���Խ��� STmpT = STmpT ��ȫ�ƶ���ֵ�����͸��
   template<typename TmpT>
   concept ��ȫ�ƶ���ֵ���� = std::is_nothrow_move_assignable_v<TmpT>;

   // һ�� STmpT ���Խ������������͸��
   template<typename TmpT>
   concept �������� = std::is_destructible_v<TmpT>;

   // һ�� STmpT ���Խ���ƽ�����������͸��
   template<typename TmpT>
   concept ƽ���������� = std::is_trivially_destructible_v<TmpT>;

   // һ�� STmpT ���Խ��а�ȫ���������͸��
   template<typename TmpT>
   concept ��ȫ�������� = std::is_nothrow_destructible_v<TmpT>;

   // һ�� STmpT �������������������͸��
   template<typename TmpT>
   concept ���������� = std::has_virtual_destructor_v<TmpT>;

   // һ�� STmpT �̳��� TmpU �����͸������ cv ���η�������������ʱ����ʹ STmpT = TmpU ����Ҳ����ȷ����Ϊ���� "is-a" ��ϵ��
   template<typename TmpT, typename TmpU>
   concept �������� = std::is_base_of_v<TmpU, TmpT>;

   // һ�� STmpT ���԰�ȫת��λ TmpU �Լ� TmpArgs �б��е��������͵ĸ���������á�
   template<typename TmpT, typename TmpU, typename... TmpArgs>
   concept ��ȫת������ = ȫ��ֵ<std::is_nothrow_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpU>>, std::is_nothrow_convertible_v<std::remove_reference_t<TmpT>, std::remove_reference_t<TmpArgs>>...>;

   // һ�� STmpT �� TmpU ���ּ��ݵ����͸��
   template<typename TmpT, typename TmpU>
   concept ���ּ������� = std::is_layout_compatible_v<TmpT, TmpU>;

   // һ�� TmpCall ���Խ��� TmpCall(TmpArgs...) ���õ����͸�� 
   template<typename TmpCall, typename... TmpArgs>
   concept �������� = std::is_invocable_v<TmpCall, TmpArgs...>;

   // һ�� TmpCall ���Խ��� TmpCall(TmpArgs...) ��ȫ���õ����͸��
   template<typename TmpCall, typename... TmpArgs>
   concept ��ȫ�������� = std::is_nothrow_invocable_v<TmpCall, TmpArgs...>;

   // һ�� TmpCall ���Խ��� TmpCall(TmpArgs...) ���ò��ҷ���ֵ���Ϳ���ת��Ϊ TmpRet �����͸��
   template<typename TmpCall, typename TmpRet, typename... TmpArgs>
   concept ���÷������� = std::is_invocable_r_v<TmpRet, TmpCall, TmpArgs...>;

   // һ�� TmpCall ���Խ��� TmpCall(TmpArgs...) ��ȫ���ò��ҷ���ֵ���Ϳ���ת��Ϊ TmpRet �����͸��
   template<typename TmpCall, typename TmpRet, typename... TmpArgs>
   concept ��ȫ���÷������� = std::is_nothrow_invocable_r_v<TmpRet, TmpCall, TmpArgs...>;



   //////////////////////////////////////////////////////////////////////////////////



   // һ�� const STmpT ������ const TmpU ���� == �� != �������ҷ���ֵ���Ϳ���ת��Ϊ�߼����͵ĸ��
   template<typename TmpT, typename TmpU = TmpT>
   concept ������� = requires(const TmpT X, const TmpU Y) {
      { X == Y } -> ת������<�����߼�>;
      { X != Y } -> ת������<�����߼�>;
   };

   // һ�� const STmpT ������ const TmpU ���� > �� >= �� < �� <= �������ҷ���ֵ���Ϳ���ת��Ϊ�߼����͵ĸ��
   template<typename TmpT, typename TmpU = TmpT>
   concept �Ƚ����� = requires(const TmpT X, const TmpU Y) {
      { X >  Y } -> ת������<�����߼�>;
      { X >= Y } -> ת������<�����߼�>;
      { X <  Y } -> ת������<�����߼�>;
      { X <= Y } -> ת������<�����߼�>;
   };

   // һ�� const STmpT ������ const TmpU ���� ==��!=��>��>=��<��<= �������ҷ���ֵ���Ϳ���ת��Ϊ�߼����͵ĸ��
   template<typename TmpT, typename TmpU = TmpT>
   concept �߼����� = �������<TmpT, TmpU> && �Ƚ�����<TmpT, TmpU>;

   // һ�� STmpT ���Ժ� TmpU ���� +��-��*��/ �������ҷ���ֵ���Ϳ���ת��Ϊ TmpT���Լ� +=��-=��*=��/= ��������ֵ���Ϳ���ת��Ϊ STmpT& �ĸ��ָ�� TmpModel ����ʾ���Խ��� % �� %= ���㡣
   template<typename TmpT, typename TmpU = TmpT, �����߼� TmpModel = false>
   concept �������� = requires(TmpT X, TmpU Y) {

      { X + Y } -> ת������<TmpT>;
      { X - Y } -> ת������<TmpT>;
      { X * Y } -> ת������<TmpT>;
      { X / Y } -> ת������<TmpT>;

      { X += Y } -> ��ͬ����<TmpT&>;
      { X -= Y } -> ��ͬ����<TmpT&>;
      { X *= Y } -> ��ͬ����<TmpT&>;
      { X /= Y } -> ��ͬ����<TmpT&>;

   } && (TmpModel &&requires(TmpT X, TmpU Y) {
      { X %  Y }-> ת������<TmpT>;
      { X %= Y }-> ��ͬ����<TmpT&>;
   });

   // һ�� STmpT ���Խ��� ++STmpT �� --STmpT �������ҷ��ر�������͸��
   template<typename TmpT>
   concept ���������� = requires(TmpT X) {
      { ++X } -> ��ͬ����<TmpT&>;
      { --X } -> ��ͬ����<TmpT&>;
   };

   // һ�־����������ʲ��ҿ��Ժ� T::IMAX �����������߼����Ƚϡ���ֵ�����͸��
   template<typename TmpT>
   concept ���������� = ��������<TmpT, TmpT, ��> && ��������<TmpT, T::IMAX, ��> && �߼�����<TmpT> && �߼�����<TmpT, T::IMAX> && ��ֵ����<TmpT, T::IMAX> && ����������<TmpT>;

   // һ�־��и������ʲ��ҿ��Ժ� T::FMAX �����������߼����Ƚϡ���ֵ�����͸�����ҿ���ת��Ϊ T::IMAX ���͡�
   template<typename TmpT>
   concept ���������� = ��������<TmpT> && ��������<TmpT, T::FMAX> && �߼�����<TmpT> && �߼�����<TmpT, T::FMAX> && ��ֵ����<TmpT, T::FMAX> && ����������<TmpT> && ת������<TmpT, T::IMAX>;

   // һ���ܽ����������߼����Ƚϡ�Ĭ�Ϲ��졢�����������һ��ܺ� int ���ͽ����������߼����Ƚϡ���ֵ�����͸��
   template<typename TmpT>
   concept �������� = ����������<TmpT> || ����������<TmpT>;

   // һ�� STmpT �ܹ��� nullptr ���� ==��!= �������ҿ��Ը�ֵΪ nullptr �ĸ��
   template<typename TmpT>
   concept �ɿ����� = �������<TmpT, std::nullptr_t> && ��ֵ����<TmpT, std::nullptr_t>;

   // һ�� TmpCall ���Խ��� TmpCall(STmpT, TmpU) ���ò��ҷ���ֵ���Ϳ���ת��Ϊ�����߼������͸��
   template<typename TmpCall, typename TmpT, typename TmpU>
   concept �Ƚϵ������� = ���÷�������<TmpCall, �����߼�, TmpT, TmpU>;

   // һ�� STmpT ����ʹ�� ���� ��Ա������ STmpT ����� TmpU ���͵����͸��
   template<typename TmpT, typename TmpU>
   concept �������������� = requires(TmpT X, TmpU Y) {
      X.����(Y);
   };

}
