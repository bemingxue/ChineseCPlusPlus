
#ifndef _BE_BEIMINGXUE_H_
#define _BE_BEIMINGXUE_H_

// 检查是否使用 C++ 以及字符码环境是否为 Unicode。
#if !defined(UNICODE) || !defined(__cplusplus)
#error "This file should only be included in a C++ Unicode build"
#endif

// 检查编译器是否支持 C++20 及以上版本。
#if !__has_include(<concepts>)
#error "Please use C++ 20 and above versions."
#endif

// 用于将字符或字符串表示为标准库的标准字符类型。
#define C(MacroChar)    U ## MacroChar

// 包含所有的标准库头文件。
#include "./stl.h"

// 函数库中所有基本信息的定义。
#include "./basic.h"

// 函数库中一些基本配置信息的定义。
#include "./config.h"

// 函数库中一些基本概念的定义。
#include "./concepts.h"

// 函数库中一些字符处理的基本功能定义。
#include "./charset.h"

// 函数库中一些错误处理的定义。
#include "./error.h"

// (template type) 函数库中一些特殊的模板类型别名的定义。
#include "./tmptype.h"

// (variable parameter) 提供处理多种类型的功能实现定义。
#include "./varargs.h"

// 提供各种赋值功能的定义。
#include "./assign.h"

// 提供各种长度相关的功能的定义。
#include "./size.h"

// 提供各种交换相关功能的定义。
#include "./swap.h"

// 提供各种获取数据的相关功能的定义。
#include "./get.h"

// 提供各种逻辑相关的功能定义。
#include "./logic.h"

// 提供和地址相关的功能定义。
#include "./address.h"

// 提供各种调用相关的功能定义。
#include "./call.h"

// 提供各种数值信息的功能定义。
#include "./limits.h"

// 提供各种数值常数的定义。
#include "./numbers.h"

// 提供各种数学运算的功能定义。
#include "./math.h"

// (number compare) 提供各种安全的数字比较的功能定义。
#include "./numcmp.h"

// 提供各种随机数相关的功能定义。
#include "./random.h"

// (number count) 提供各种数字计数相关功能的定义。
#include "./numcount.h"

// 提供单位类型的实现与规范。
#include "./unit.h"

// 提供一些函数库的本地化信息。
#include "./locale.h"

// 提供各种掩码、位块操作的功能定义。
#include "./mask.h"

// 提供引用包装类型的实现。
#include "./reference.h"

// （object data）提供一个可以处理对象底层比特数据的类型。
#include "./objdata.h"

// 提供一种用于表示数字转换设定信息的枚举。
#include "./converset.h"

// 提供全局运算符的重载定义。
#include "./uoperator.h"

// 提供一种对值类型的定义。
#include "./pair.h"

// 提供一些仿运算符功能的调用类型定义。
#include "./operator.h"

// 提供一些基本的迭代器相关功能的定义。
#include "./iterator.h"

// 提供一种特殊的迭代方式的功能定义。
#include "./enumeration.h"

// 提供一些迭代填充相关功能的定义。
#include "./fill.h"

// 提供一些迭代复制相关功能的定义。
#include "./copys.h"

// 提供一些迭代移动相关功能的定义。
#include "./moves.h"

// 提供一些迁移相关功能的定义。
#include "./migrate.h"

// 提供一些插入算法的定义。
#include "./insert.h"

// 提供一些迭代遍历相关功能的定义。
#include "./foreach.h"

// 提供一些迭代相等判断相关功能的定义。
#include "./compare.h"

// 提供一些迭代翻转相关功能的定义。
#include "./overturn.h"

// 提供一些迭代查找相关功能的定义。
#include "./search.h"

// 提供一些最大值与最小值相关功能的定义。
#include "./maxin.h"

// 提供一些进制处理的相关功能定义。
#include "./binary.h"

// 提供一些字符串类型定义与相关功能的实现。
#include "./strings.h"

#include "./chars.h"

// 提供一些基本内存操作的相关功能定义。
#include "./memory.h"

// (pointer unique) 提供进行唯一所有权指针托管的类型定义。
#include "./punique.h"

// (original space) 提供一种对内存空间进行原始管理的空间类。
#include "./orispace.h"

// (basic space) 提供一种对内存空间进行基本管理的空间类。
#include "./basspace.h"

// 提供一种封装对字节数据管理的类型。
#include "./bytes.h"

// 提供一种对数组的封装。
#include "./array.h"

// 提供一种对连续存储的内存块进行视图访问的类型。
#include "./view.h"

// 提供一种对于使用连续存储字符串的类型的视图类型。
#include "./strview.h"

// 提供一种字符串转换到其他类型的功能。
#include "./stringto.h"

// 提供一种字符串类的实现。
#include "./string.h"

// 提供一种用于进行简便操作的数字转字符串功能。
#include "./numtostr.h"

// 提供一些基本的转为字符串的功能定义。
#include "./tostring.h"

// 提供一种用于进行简便操作的对象转字符串功能。
#include "./objtostr.h"

// 提供一种将指定数据和字符串格式化的功能。
#include "./format.h"

// 提供一种可变数组容器的实现。
#include "./vectors.h"

// 提供一种栈容器的实现。
#include "./stack.h"

// 提供一种使用循环链表实现的双向链表容器。
#include "./linked.h"

// 提供基本时间处理工具集合的实现。
#include "./times.h"

// 提供一种进行日期时间管理的类的实现。
#include "./datetime.h"

// （pool thread）提供一种简单线程池的实现。
#include "./pthread.h" 

// 提供路径和文件处理的相关功能定义。
#include "./path.h"

// 提供简单文件处理的实现。
#include "./file.h"

#endif  // _BE_BEIMINGXUE_H_
