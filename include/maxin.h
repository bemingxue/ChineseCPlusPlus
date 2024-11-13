
namespace BE {

   /**
    * \brief >>> 获取两个值中的最大值，使用 > 运算符判断。
    * 
    * \param 左值项： 要判断的只读引用。
    * \param 右值项： 要判断的只读引用。
    * \return 最大值的只读引用。
    * \tparam TmpT： 能够进行 >、>=、<、<= 的类型，并且返回值可以转换为逻辑类型，具体类型由左值项决定。
    */
   template<比较类型 TmpT>
   inline constexpr const TmpT &最大值(const TmpT &左值项, const typename T::STyp<TmpT>::type &右值项) noexcept
   {
      return (左值项 > 右值项)? 左值项 : 右值项;
   }

   /**
    * \brief >>> 获取两个值中的最小值，使用 < 运算符判断。
    * 
    * \param 左值项： 要判断的只读引用。
    * \param 右值项： 要判断的只读引用。
    * \return 最小值的只读引用。
    * \tparam TmpT： 能够进行 >、>=、<、<= 的类型，并且返回值可以转换为逻辑类型，具体类型由左值项决定。
    */
   template<比较类型 TmpT>
   inline constexpr const TmpT &最小值(const TmpT &左值项, const typename T::STyp<TmpT>::type &右值项) noexcept
   {
      return (左值项 > 右值项) ? 右值项 : 左值项;
   }

}
