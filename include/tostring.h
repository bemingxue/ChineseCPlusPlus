
namespace BE {

   // 定义一些对齐操作的枚举值。
   enum class 对齐枚举 : unsigned char
   {
      左对齐, 右对齐, 居中对齐
   };

   /**
    * \brief >>> 使用给定的对齐方式对齐字符串。
    * 
    * \param 对齐项： 要对齐的字符串。
    * \param 长度项： 要对齐的长度，如果字符串本身长度已经超过长度项则函数无作为。
    * \param 填充项： 要填充的字符。
    * \param 对齐方式项： 对齐方式。
    * \return 
    */
   inline 类型空的 字符串对齐(字符串类 &对齐项, 类型长度 长度项, 类型字符 填充项, 对齐枚举 对齐方式项) noexcept
   {
      if (对齐方式项 == 对齐枚举::左对齐)
      {
         对齐项.从右填充(长度项, 填充项);
      }
      else if (对齐方式项 == 对齐枚举::右对齐)
      {
         对齐项.从左填充(长度项, 填充项);
      }

      // 暂未制作居中对齐。
      else
      {

      }
   }

   // 允许将逻辑类型转换为字符串类。
   template<>
   struct 转字符串类<bool>
   {
      字符串类 operator () (const bool &转换项) const noexcept
      {
         return 转换项 ? 本地信息类::获取实例().真值表示 : 本地信息类::获取实例().假值表示;
      }
   };

   // 允许将字符类型转换为字符串类。
   template<>
   struct 转字符串类<类型字符>
   {
      字符串类 operator () (const 类型字符 &转换项, 类型长度 重复项 = 1) const noexcept
      {
         return 字符串类(转换项, 重复项);
      }
   };

   // 允许将字符串类型转换为字符串类。
   template<字符串类型 TmpT>
   struct 转字符串类<TmpT>
   {
      字符串类 operator () (const TmpT &转换项) const noexcept
      {
         return 字符串类(转换项);
      }
   };

   // 允许将指针类型转换为字符串类，注意为字符指针时将使用 <字符串类型 STmpT> 特化而非当前特化。
   template<指针类型 TmpT>
   requires(!字符串类型<TmpT>)
   struct 转字符串类<TmpT>
   {
      字符串类 operator () (const TmpT &转换项) const noexcept
      {
         // error： static_cast 无法将指针转换为整数类型。
         // return 字符串类(static_cast<T::UPTR>(转换项), 16).从左填充(16, C('0'));s

         return 字符串类((T::UPTR)转换项, 16).从左填充(16, C('0'));
      }
   };

   // 允许将字节类型转换为 \x00 形式的字符串。
   template<>
   struct 转字符串类<类型字节>
   {
      字符串类 operator () (const 类型字节 &转换项) const noexcept
      {
         return 字符串类("\\x") << 字符串类(转换项, 16);
      }
   };

   // 允许将整数类型转换为字符串类。
   template<严格整数类型 TmpT>
   struct 转字符串类<TmpT>
   {
      字符串类 operator () (const TmpT &转换项, 类型进制 进制项 = 10, 类型字符 正号项 = C('\0'), 转换枚举 额外设定项 = 转换枚举{}) const noexcept
      {
         return 字符串类(转换项, 进制项, 正号项, 额外设定项);
      }
   };

   // 允许将浮点类型转换为字符串类。
   template<浮点类型 TmpT>
   struct 转字符串类<TmpT>
   {
      字符串类 operator () (const TmpT &转换项, 类型长度 精度项 = 默认精度, 类型进制 进制项 = 10, 类型字符 正号项 = C('\0'), 转换枚举 额外设定项 = 转换枚举{}) const noexcept
      {
         return 字符串类(转换项, 精度项, 进制项, 正号项, 额外设定项);
      }
   };

   // 允许将对象字节类中的每个比特转换为字符串类。
   template<对象类型 TmpT>
   struct 转字符串类<对象字节类<TmpT>>
   {
      字符串类 operator () (const 对象字节类<TmpT> &转换项)
      {
         字符串类 返回值;

         返回值.调整有效范围(转换项.获取长度() + 转换项.获取长度() / 8);
         返回值.调整有效范围(0);

         for (auto &迭代量 : 转换项)
         {
            if (迭代量.获取索引() % 8 == 0 && 迭代量.获取索引() != 0)
            {
               返回值 += C(' ');
            }
            返回值 += C('0') + 迭代量.operator bool();
         }

         return 返回值;
      }
   };

   // 获取数字字符串类中的字符串将其复制后返回。
   template<>
   struct 转字符串类<数字字符串类>
   {
      字符串类 operator () (const 数字字符串类 &转换项) const noexcept
      {
         return 转换项.获取字符串();
      }
   };

   // 允许将字节类转换为指定 [:\\xffffff...] 形式的字符串。
   template<>
   struct 转字符串类<字节类>
   {
      字符串类 operator () (const 字节类 &转换项) const noexcept
      {
         字符串类 返回值 = C("[:\\x");

         for (auto &迭代量 : 转换项)
         {
            返回值 << 字符串类(迭代量, 16, 0, 转换枚举::小写显示).从左填充(2, C('0')) << C(" ");
         }

         return 返回值 << C("]");
      }
   };

   template<可转字符串类型 TmpT, typename... TmpArgs>
   字符串类 转为字符串(const TmpT &转换项, TmpArgs&&... 额外参数项)
   requires(调用类型<转字符串类<TmpT>, const TmpT&, TmpArgs...>)
   {
      return 转字符串类<TmpT>()(转换项, std::forward<TmpArgs>(额外参数项)...);
   }

}
