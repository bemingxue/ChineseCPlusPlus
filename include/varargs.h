
#include "./Pri/_varargs.h"

namespace BE {

   /**
    * \brief >>> 提供一种专门处理多个类型的模板类。
    */
   template<typename... STmpArgs>
   struct 变参处理类
   {
      // 变参的数量。
      static constexpr 类型长度 长度值 = sizeof...(STmpArgs);
   
      // 所有类型的总共占用的字节数。
      static constexpr 类型长度 总字节数 = X::R::VarArgsSumBytes<STmpArgs..., X::R::SVarArgsPho>::value;
      
      // 索引变参中指定索引位置的类型，如果越界则产生静态断言。
      template<类型长度 TmpIndex>
      using 索引参数 = X::R::VarArgsAtType<TmpIndex, STmpArgs..., X::R::SVarArgsPho>::type;

      // 索引变参中指定索引位置的类型占用的字节数，如果越界则产生静态断言。
      template<类型长度 TmpIndex>
      static constexpr 类型长度 索引占用 = sizeof(索引参数<TmpIndex>);

   };

}
