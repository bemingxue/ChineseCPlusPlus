
namespace BE {

   /**
    * \brief >>> ���ܵ��ã������κοɵ��ö���Ҳ���Ե��ó�Աָ�롣
    * 
    * \param ����� Ҫ���õĿɵ��ö���
    * \param ������ Ҫ���ݸ�������Ĳ�����
    * \return ���ú�ķ���ֵ��
    */
   template<typename TmpCall, typename... TmpArgs>
   inline constexpr decltype(auto) ����(TmpCall &&������, TmpArgs&&... ������) noexcept requires ��������<TmpCall, TmpArgs...>
   {
      return std::invoke(std::forward<TmpCall>(������), std::forward<TmpArgs>(������)...);
   }

}
