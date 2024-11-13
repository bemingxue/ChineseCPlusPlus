
namespace BE {

   /**
    * \brief >>> 比较两个数字是否相等，对于浮点数，总是计算精度保证如 0.1 + 0.2 = 0.3，对于整数，保证无符号和有符号整数之间不发生转换比较。
    * 
    * \param 左值项： 要比较的数值。
    * \param 右值项： 要比较的数值。
    * \return 相同则返回真，否则返回假。
    */
   template<标准数字类型 TmpT, 标准数字类型 TmpU>
   inline constexpr 类型逻辑 安全数字相等(TmpT 左值项, TmpU 右值项) noexcept
   {
      // 安全比较浮点数。
      if constexpr (浮点类型<TmpT>)
      {
         return BE::数学集::绝对值(左值项 - 右值项) <= 数字信息类<TmpT>::误差值;
      }

      else if (浮点类型<TmpU>)
      {
         return BE::数学集::绝对值(左值项 - 右值项) <= 数字信息类<TmpU>::误差值;
      }

      // 对于逻辑类型没有有符号与无符号之分，直接比较即可。
      else if constexpr (相同类型<TmpT, bool> || 相同类型<TmpU, bool> || (有符类型<TmpT> && 有符类型<TmpU>))
      {
         return 左值项 == 右值项;
      }

      else if constexpr (有符类型<TmpT>)
      {
         // 将有符号的转为无符号，因为无符号整数能够存储有符号整数的所有正数。
         return 左值项 >= 0 && 右值项 == 模板无符整数<TmpU>(左值项);
      }

      else
      {
         return 右值项 >= 0 && 左值项 == 模板无符整数<TmpT>(右值项);
      }
   }

   /**
    * \brief >>> 比较两个数字是否不相等，对于浮点数，总是计算精度保证如 0.1 + 0.2 = 0.3，对于整数，保证无符号和有符号整数之间不发生转换比较。
    * 
    * \param 左值项： 要比较的数值。
    * \param 右值项： 要比较的数值。
    * \return 不相等则返回真，否则返回假。
    */
   inline constexpr 类型逻辑 安全数字不等(标准数字类型 auto 左值项, 标准数字类型 auto 右值项) noexcept
   {
      return !安全数字相等(左值项, 右值项);
   }

   /**
    * \brief >>> 比较两个数字，左边的是否小于右边，对于浮点数，总是保证精度，对于整数，保证无符号和有符号整数之间不发生转换比较，如 -1 与 1u 返回 true 而不是 false。
    * 
    * \param 左值项： 要比较的数值。
    * \param 右值项： 要比较的数值。
    * \return 小于则返回真，否则返回假。
    */
   template<标准数字类型 TmpT, 标准数字类型 TmpU>
   inline constexpr 类型逻辑 安全数字小于(TmpT 左值项, TmpU 右值项) noexcept
   {
      // 安全比较浮点数。
      if constexpr (浮点类型<TmpT>)
      {
         return 左值项 < 右值项 - 数字信息类<TmpT>::误差值;
      }

      else if (浮点类型<TmpU>)
      {
         return 左值项 - 数字信息类<TmpU>::误差值 < 右值项;
      }

      // 对于逻辑类型没有有符号与无符号之分，直接比较即可。
      else if constexpr (相同类型<TmpT, bool> || 相同类型<TmpU, bool> || (有符类型<TmpT> && 有符类型<TmpU>))
      {
         return 左值项 < 右值项;
      }

      else if constexpr (有符类型<TmpT>)
      {
         // 将有符号的转为无符号，因为无符号整数能够存储有符号整数的所有正数。
         return 左值项 < 0 || 右值项 > 模板无符整数<TmpT>(左值项);
      }

      else
      {
         return 右值项 >= 0 && 左值项 < 模板无符整数<TmpU>(右值项);
      }
   }

   /**
    * \brief >>> 比较两个数字，左边的是否大于右边，对于浮点数，总是保证精度，对于整数，保证无符号和有符号整数之间不发生转换比较。
    * 
    * \param 左值项： 要比较的数值。
    * \param 右值项： 要比较的数值。
    * \return 大于则返回真，否则返回假。
    */
   inline constexpr 类型逻辑 安全数字大于(标准数字类型 auto 左值项, 标准数字类型 auto 右值项) noexcept
   {
      return 安全数字小于(右值项, 左值项);
   }

   /**
    * \brief >>> 比较两个数字，左边的是否小于等于右边，对于浮点数，总是保证精度，对于整数，保证无符号和有符号整数之间不发生转换比较。
    * 
    * \param 左值项： 要比较的数值。
    * \param 右值项： 要比较的数值。
    * \return 小于等于则返回真，否则返回假。
    */
   inline constexpr 类型逻辑 安全数字小于等于(标准数字类型 auto 左值项, 标准数字类型 auto 右值项) noexcept
   {
      return !安全数字小于(右值项, 左值项);
   }

   /**
    * \brief >>> 比较两个数字，左边的是否大于等于右边，对于浮点数，总是保证精度，对于整数，保证无符号和有符号整数之间不发生转换比较。
    * 
    * \param 左值项： 要比较的数值。
    * \param 右值项： 要比较的数值。
    * \return 小于等于则返回真，否则返回假。
    */
   inline constexpr 类型逻辑 安全数字大于等于(标准数字类型 auto 左值项, 标准数字类型 auto 右值项) noexcept
   {
      return !安全数字小于(左值项, 右值项);
   }

   /**
    * \brief >>> 安全的判断数字是否在给定类型的取值范围内。
    * 
    * \param 判断项： 要判断的数值。
    * \return 如果数字在给定类型的取值范围内，则返回真，否则返回假。
    */
   template<标准数字类型 TmpT, 标准数字类型 TmpU>
   inline constexpr 类型逻辑 在范围(TmpU 判断项) noexcept
   {
      return 安全数字大于等于(判断项, 数字信息类<TmpT>::最小值) && 安全数字小于等于(判断项, 数字信息类<TmpT>::最大值);
   }

}
