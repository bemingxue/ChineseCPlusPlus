﻿
namespace BE {

   // 一些基本字符处理的集合。
   namespace 字符集 {

      struct 特殊符号枚举 {
         enum : 类型字符 {
            乘号 = C('×'),
            除号 = C('÷'),
            错误叉 = C('✗'),
            正确勾 = C('✓'),
            圆周率 = C('π'),
            商标符 = C('™'),
            版权符 = C('©'),
            千分符 = C('‰'),
            万分符 = C('‱'),
            黑色方块 = C('■'),
            空白方块 = C('□'),
            黑色右三角 = C('▶'),
            黑色左三角 = C('◀'),
            黑色上三角 = C('▲'),
            黑色下三角 = C('▼'),
            黑色五角星 = C('★')
         };
      };

      // 中文小写数字表示字符。
      inline constexpr 类型字符 小写数字表[] = { C('零'), C('一'), C('二'), C('三'), C('四'), C('五'), C('六'), C('七'), C('八'), C('九'), C('十') };
      // 中文大写数字表示字符。
      inline constexpr 类型字符 大写数字表[] = { C('零'), C('壹'), C('贰'), C('叁'), C('肆'), C('伍'), C('陆'), C('柒'), C('捌'), C('玖'), C('拾') };
      // 一种带圈的数字表示字符，没有 0 。
      inline constexpr 类型字符 圆圈数字表[] = { C(' '), C('①'), C('②'), C('③'), C('④'), C('⑤'), C('⑥'), C('⑦'), C('⑧'), C('⑨'), C('⑩') };

      /**
       * \brief >>> 判断字符是否为 [0, 9] 之间的字符、
       * 
       * \param 字符项： 要判断的字符。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 是数字字符(类型字符 字符项) noexcept
      {
         return 字符项 >= C('0') && 字符项 <= C('9');
      }

      /**
       * \brief >>> 判断字符是否为 [A, Z] 之间的大写英文字母。
       * 
       * \param 字符项： 要判断的字符。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 是大写字母(类型字符 字符项) noexcept
      {
         return 字符项 >= C('A') && 字符项 <= C('Z');
      }

      /**
       * \brief >>> 判断字符是否是 [a, z] 之间的小写英文字母。
       * 
       * \param 字符项： 要判断的字符。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 是小写字母(类型字符 字符项) noexcept
      {
         return 字符项 >= C('a') && 字符项 <= C('z');
      }

      /**
       * \brief >>> 判断字符是否是大写或者小写英文字母。
       * 
       * \param 字符项： 要判断的字符。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 是英文字母(类型字符 字符项) noexcept
      {
         return 是大写字母(字符项) || 是小写字母(字符项);
      }

      /**
       * \brief >>> 判断字符是否为空白字符，即空格、制表符、换行符、回车符。
       * 
       * \param 字符项： 要判断的字符。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 是空白字符(类型字符 字符项) noexcept
      {
         return 字符项 == C(' ') || 字符项 == C('\t') || 字符项 == C('\n') || 字符项 == C('\r');
      }

      /**
       * \brief >>> 判断字符是否为数字获取大小写英文字符。
       * 
       * \param 字符项： 要判断的字符。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 是数字英文(类型字符 字符项) noexcept
      {
         return 是数字字符(字符项) || 是英文字母(字符项);
      }

      /**
       * \brief >>> 判断字符是否是 [4e00, 9fa5] 之间也就是汉字字符。
       * 
       * \param 字符项： 要判断的字符。
       * \return 是则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 是汉字字符(类型字符 字符项) noexcept
      {
         return 字符项 >= C('\u4E00') && 字符项 <= C('\u9FA5');
      }

      /**
       * \brief >>> 将小写英文字母转换为大写英文字母。
       * 
       * \param 字符项： 要转换的字符。
       * \return 是小写英文字母的话，返回对应的大写英文字母，否则返回原字符。
       */
      inline constexpr 类型字符 转大写字母(类型字符 字符项) noexcept
      {
         return 是小写字母(字符项) ? (字符项 - 32) : 字符项;
      }

      /**
       * \brief >>> 将大写英文字母转换为小写英文字母。
       * 
       * \param 字符项： 要转换的字符。
       * \return 是大写英文字母的话，返回对应的小写英文字母，否则返回原字符。
       */
      inline constexpr 类型字符 转小写字母(类型字符 字符项) noexcept
      {
         return 是大写字母(字符项) ? (字符项 + 32) : 字符项;
      }

      /**
       * \brief >>> 将目标字符转换为 wchar_t 类型字符。
       * 
       * \param 字符项： 要转换的字符。
       * \return 转换后的字符，注意数据可能会丢失。
       */
      inline constexpr wchar_t 转宽字符(类型字符 字符项) noexcept
      {
         return static_cast<wchar_t>(字符项);
      }

      /**
       * \brief >>> 判断两个字符是否相同。
       * 
       * \param 左字符项： 左边的字符。
       * \param 右字符项： 右边的字符。
       * \param 区分大小写否： 是否区分大小写判断，默认区分。
       * \return 相同则返回真，否则返回假。
       */
      inline constexpr 类型逻辑 字符相等(类型字符 左字符项, 类型字符 右字符项, 类型逻辑 区分大小写否 = 真) noexcept
      {
         return 区分大小写否 ? (左字符项 == 右字符项) : (转大写字母(左字符项) == 转大写字母(右字符项));
      }

      /**
       * \brief >>> 判断字符项是否是正负号，并且同时判断 STmpT 是否位无符号整数，如果是则负号会返回 false，如果给定存储项，则存储符号。
       * 
       * \param 字符项： 要判断的字符。
       * \param 存储项： 存储正数或负数的存储项，如果为 nullptr 则不存储。
       * \return 是则返回真，否则返回假。
       */
      template<数字类型 TmpT = int>
      inline 类型逻辑 正负号判断(类型字符 字符项, TmpT *存储项 = 空指针) noexcept
      {
         if (字符项 == C('+') || 字符项 == C('-'))
         {
            if (字符项 == C('-') && 无符类型<TmpT>)
            {
               return false;
            }

            if (存储项 != 空指针)
            {
               *存储项 = 字符项 == C('+') ? 1 : -1;
            }

            return true;
         }

         return false;
      }

   }

}
