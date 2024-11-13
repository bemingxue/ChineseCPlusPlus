
namespace BE {

   struct 本地信息类
   {
      类型字符 货币符号 = C('￥');
      类型字符 数字分隔符 = C('\'');

      类型无符<> 数字分隔位 = 4;

      const 类型字符 *货币简称 = C("RMB");
      const 类型字符 *货币名称 = C("人民币");
      const 类型字符 *上午标识 = C("上午");
      const 类型字符 *下午标识 = C("下午");
      const 类型字符 *非数表示 = C("NaN");
      const 类型字符 *无穷表示 = C("Inf");
      const 类型字符 *真值表示 = C("True");
      const 类型字符 *假值表示 = C("False");

      const 类型字符 *星期名称[7] = { C("星期日"), C("星期一"), C("星期二"), C("星期三"), C("星期四"), C("星期五"), C("星期六") };

      static 本地信息类 &获取实例() noexcept
      {
         static 本地信息类 默认实例;
         return 默认实例;
      }
   };

}
