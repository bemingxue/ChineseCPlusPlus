
#include "./Pri/_varargs.h"

namespace BE {

   /**
    * \brief >>> �ṩһ��ר�Ŵ��������͵�ģ���ࡣ
    */
   template<typename... STmpArgs>
   struct ��δ�����
   {
      // ��ε�������
      static constexpr ���ͳ��� ����ֵ = sizeof...(STmpArgs);
   
      // �������͵��ܹ�ռ�õ��ֽ�����
      static constexpr ���ͳ��� ���ֽ��� = X::R::VarArgsSumBytes<STmpArgs..., X::R::SVarArgsPho>::value;
      
      // ���������ָ������λ�õ����ͣ����Խ���������̬���ԡ�
      template<���ͳ��� TmpIndex>
      using �������� = X::R::VarArgsAtType<TmpIndex, STmpArgs..., X::R::SVarArgsPho>::type;

      // ���������ָ������λ�õ�����ռ�õ��ֽ��������Խ���������̬���ԡ�
      template<���ͳ��� TmpIndex>
      static constexpr ���ͳ��� ����ռ�� = sizeof(��������<TmpIndex>);

   };

}
