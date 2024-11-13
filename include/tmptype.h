
#include "./Pri/_tmptype.h"

namespace BE {

   // һ�� STmpT ���б����ͣ��� int �б�����Ϊ std::initializer_list<int>��
   template<typename TmpT>
   using ģ���б����� = std::initializer_list<TmpT>;

   // һ�� STmpT ���ڴ����б��˻������ͣ��� int[] �ᱻ�˻�λ int*��
   template<typename TmpT>
   using ģ���˻����� = std::decay_t<TmpT>;

   // һ�� STmpT ��ö��ʱ�����ĵײ����ͣ��������ö�٣������� error-type��
   template<typename TmpT>
   using ģ��ö������ = std::underlying_type_t<TmpT>;

   // һ�� STmpT ���н����������ķ���ֵ���ͣ�һ������õĽ����Ϊ���ã��� int * ������Ϊ int&�����ܽ����������� error-type��
   template<typename TmpT>
   using ģ��������� = decltype(*std::declval<TmpT &>());

   // һ�� TmpArgs ���������Ͷ�����ת��Ϊ�Ĺ�ͬ���ͣ����û�������� error-type��
   template<typename... TmpArgs>
   using ģ�幫������ = std::common_type_t<TmpArgs...>;

   // һ�� TmpArgs ���������Ͷ�����ת��Ϊ�Ĺ�ͬ�������ͣ����û�������� error-type��
   template<typename... TmpArgs>
   using ģ�幫������ = std::common_reference_t<TmpArgs...>;

   // һ�� TmpCall ���� TmpCall(TmpArgs...) ����ʱ�ķ���ֵ���ͣ���� TmpCall �޷����ã������� error-type��
   template<typename TmpCall, typename... TmpArgs>
   using ģ�巵������ = std::invoke_result_t<TmpCall, TmpArgs...>;

   // һ���Ƴ� STmpT �������η�������͡�
   template<typename TmpT>
   using ģ���Ƴ����� = typename X::R::RemoveAllModifier<TmpT>::type;

   // һ���Ƴ� STmpT �������β��� TmpU �����������ƶ��� STmpT �ϵ����͡�
   template<typename TmpT, typename TmpU>
   using ģ��ת������ = typename X::R::MoveModifierType<TmpT, TmpU>::type;

   // һ�� STmpT ��Ӧ���޷����������ͣ������޷��ŵ���ԭ����ʾ�������з��ŵ� char��short��int��long��long long �ṩ��Ӧ�� unsigned �汾������ö�ٺ��ַ����ṩ�ֽڴ�С��ͬ���޷����������ͣ��������� error-type��
   template<typename TmpT>
   using ģ���޷����� = std::make_unsigned_t<TmpT>;

   // һ�� STmpT ��Ӧ���з����������ͣ������з��ŵ���ԭ����ʾ�������޷��ŵ� char��short��int��long��long long �ṩ��Ӧ�� signed �汾������ö�ٺ��ַ����ṩ�ֽڴ�С��ͬ���з����������ͣ��������� error-type��
   template<typename TmpT>
   using ģ���з����� = std::make_signed_t<TmpT>;

   // һ��������ʹ�ñ�����������ѡ�����ͣ�TmpCondition Ϊ true ʱѡ�� TmpTrueT��TmpCondition Ϊ false ʱѡ�� TmpFalseT��
   template<bool TmpCondition, typename TmpTrueT, typename TmpFalseT>
   using ģ���������� = std::conditional_t<TmpCondition, TmpTrueT, TmpFalseT>;

}
