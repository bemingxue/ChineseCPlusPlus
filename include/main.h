
#ifndef _BE_BEIMINGXUE_H_
#define _BE_BEIMINGXUE_H_

// ����Ƿ�ʹ�� C++ �Լ��ַ��뻷���Ƿ�Ϊ Unicode��
#if !defined(UNICODE) || !defined(__cplusplus)
#error "This file should only be included in a C++ Unicode build"
#endif

// ���������Ƿ�֧�� C++20 �����ϰ汾��
#if !__has_include(<concepts>)
#error "Please use C++ 20 and above versions."
#endif

// ���ڽ��ַ����ַ�����ʾΪ��׼��ı�׼�ַ����͡�
#define C(MacroChar)    U ## MacroChar

// �������еı�׼��ͷ�ļ���
#include "./stl.h"

// �����������л�����Ϣ�Ķ��塣
#include "./basic.h"

// ��������һЩ����������Ϣ�Ķ��塣
#include "./config.h"

// ��������һЩ��������Ķ��塣
#include "./concepts.h"

// ��������һЩ�ַ�����Ļ������ܶ��塣
#include "./charset.h"

// ��������һЩ������Ķ��塣
#include "./error.h"

// (template type) ��������һЩ�����ģ�����ͱ����Ķ��塣
#include "./tmptype.h"

// (variable parameter) �ṩ����������͵Ĺ���ʵ�ֶ��塣
#include "./varargs.h"

// �ṩ���ָ�ֵ���ܵĶ��塣
#include "./assign.h"

// �ṩ���ֳ�����صĹ��ܵĶ��塣
#include "./size.h"

// �ṩ���ֽ�����ع��ܵĶ��塣
#include "./swap.h"

// �ṩ���ֻ�ȡ���ݵ���ع��ܵĶ��塣
#include "./get.h"

// �ṩ�����߼���صĹ��ܶ��塣
#include "./logic.h"

// �ṩ�͵�ַ��صĹ��ܶ��塣
#include "./address.h"

// �ṩ���ֵ�����صĹ��ܶ��塣
#include "./call.h"

// �ṩ������ֵ��Ϣ�Ĺ��ܶ��塣
#include "./limits.h"

// �ṩ������ֵ�����Ķ��塣
#include "./numbers.h"

// �ṩ������ѧ����Ĺ��ܶ��塣
#include "./math.h"

// (number compare) �ṩ���ְ�ȫ�����ֱȽϵĹ��ܶ��塣
#include "./numcmp.h"

// �ṩ�����������صĹ��ܶ��塣
#include "./random.h"

// (number count) �ṩ�������ּ�����ع��ܵĶ��塣
#include "./numcount.h"

// �ṩ��λ���͵�ʵ����淶��
#include "./unit.h"

// �ṩһЩ������ı��ػ���Ϣ��
#include "./locale.h"

// �ṩ�������롢λ������Ĺ��ܶ��塣
#include "./mask.h"

// �ṩ���ð�װ���͵�ʵ�֡�
#include "./reference.h"

// ��object data���ṩһ�����Դ������ײ�������ݵ����͡�
#include "./objdata.h"

// �ṩһ�����ڱ�ʾ����ת���趨��Ϣ��ö�١�
#include "./converset.h"

// �ṩȫ������������ض��塣
#include "./uoperator.h"

// �ṩһ�ֶ�ֵ���͵Ķ��塣
#include "./pair.h"

// �ṩһЩ����������ܵĵ������Ͷ��塣
#include "./operator.h"

// �ṩһЩ�����ĵ�������ع��ܵĶ��塣
#include "./iterator.h"

// �ṩһ������ĵ�����ʽ�Ĺ��ܶ��塣
#include "./enumeration.h"

// �ṩһЩ���������ع��ܵĶ��塣
#include "./fill.h"

// �ṩһЩ����������ع��ܵĶ��塣
#include "./copys.h"

// �ṩһЩ�����ƶ���ع��ܵĶ��塣
#include "./moves.h"

// �ṩһЩǨ����ع��ܵĶ��塣
#include "./migrate.h"

// �ṩһЩ�����㷨�Ķ��塣
#include "./insert.h"

// �ṩһЩ����������ع��ܵĶ��塣
#include "./foreach.h"

// �ṩһЩ��������ж���ع��ܵĶ��塣
#include "./compare.h"

// �ṩһЩ������ת��ع��ܵĶ��塣
#include "./overturn.h"

// �ṩһЩ����������ع��ܵĶ��塣
#include "./search.h"

// �ṩһЩ���ֵ����Сֵ��ع��ܵĶ��塣
#include "./maxin.h"

// �ṩһЩ���ƴ������ع��ܶ��塣
#include "./binary.h"

// �ṩһЩ�ַ������Ͷ�������ع��ܵ�ʵ�֡�
#include "./strings.h"

#include "./chars.h"

// �ṩһЩ�����ڴ��������ع��ܶ��塣
#include "./memory.h"

// (pointer unique) �ṩ����Ψһ����Ȩָ���йܵ����Ͷ��塣
#include "./punique.h"

// (original space) �ṩһ�ֶ��ڴ�ռ����ԭʼ����Ŀռ��ࡣ
#include "./orispace.h"

// (basic space) �ṩһ�ֶ��ڴ�ռ���л�������Ŀռ��ࡣ
#include "./basspace.h"

// �ṩһ�ַ�װ���ֽ����ݹ�������͡�
#include "./bytes.h"

// �ṩһ�ֶ�����ķ�װ��
#include "./array.h"

// �ṩһ�ֶ������洢���ڴ�������ͼ���ʵ����͡�
#include "./view.h"

// �ṩһ�ֶ���ʹ�������洢�ַ��������͵���ͼ���͡�
#include "./strview.h"

// �ṩһ���ַ���ת�����������͵Ĺ��ܡ�
#include "./stringto.h"

// �ṩһ���ַ������ʵ�֡�
#include "./string.h"

// �ṩһ�����ڽ��м�����������ת�ַ������ܡ�
#include "./numtostr.h"

// �ṩһЩ������תΪ�ַ����Ĺ��ܶ��塣
#include "./tostring.h"

// �ṩһ�����ڽ��м������Ķ���ת�ַ������ܡ�
#include "./objtostr.h"

// �ṩһ�ֽ�ָ�����ݺ��ַ�����ʽ���Ĺ��ܡ�
#include "./format.h"

// �ṩһ�ֿɱ�����������ʵ�֡�
#include "./vectors.h"

// �ṩһ��ջ������ʵ�֡�
#include "./stack.h"

// �ṩһ��ʹ��ѭ������ʵ�ֵ�˫������������
#include "./linked.h"

// �ṩ����ʱ�䴦���߼��ϵ�ʵ�֡�
#include "./times.h"

// �ṩһ�ֽ�������ʱ���������ʵ�֡�
#include "./datetime.h"

// ��pool thread���ṩһ�ּ��̳߳ص�ʵ�֡�
#include "./pthread.h" 

// �ṩ·�����ļ��������ع��ܶ��塣
#include "./path.h"

// �ṩ���ļ������ʵ�֡�
#include "./file.h"

#endif  // _BE_BEIMINGXUE_H_
