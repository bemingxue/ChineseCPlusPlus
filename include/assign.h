
namespace BE {

   /**
    * \brief >>> 给参数赋值新值并将原来的值返回。
    * 
    * \param 受赋值项： 受赋值项。
    * \param 赋值项： 赋值项。
    * \return 赋值前原来的值。
    * \tparam TmpT： 满足移动构造并且能够赋值为 TmpU 的类型。
    * \tparam TmpU： 能够被 STmpT 赋值的类型。
    */
   template<typename TmpT, typename TmpU>
   inline constexpr TmpT 交换赋值(TmpT &受赋值项, TmpU &&赋值项)
   noexcept(noexcept(安全移动构造类型<TmpT> && 安全赋值类型<TmpT, TmpU>))
   requires(移动构造类型<TmpT> && 赋值类型<TmpT, TmpU>)
   {
      TmpT 存储 = std::move(受赋值项);

      受赋值项 = std::forward<TmpU>(赋值项);

      return 存储;
   }

}
