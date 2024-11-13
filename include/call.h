
namespace BE {

   /**
    * \brief >>> 万能调用，调用任何可调用对象，也可以调用成员指针。
    * 
    * \param 调用项： 要调用的可调用对象。
    * \param 参数表： 要传递给调用项的参数表。
    * \return 调用后的返回值。
    */
   template<typename TmpCall, typename... TmpArgs>
   inline constexpr decltype(auto) 调用(TmpCall &&调用项, TmpArgs&&... 参数表) noexcept requires 调用类型<TmpCall, TmpArgs...>
   {
      return std::invoke(std::forward<TmpCall>(调用项), std::forward<TmpArgs>(参数表)...);
   }

}
