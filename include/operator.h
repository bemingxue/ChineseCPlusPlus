
namespace BE {

   /**
    * \brief >>> �ṩ������������� "==" �Ƚϵ��࣬����ʹ STmpT = void �õ��������ѡ�����͡�
    */
   template<typename TmpT = ���Ϳյ�, typename TmpU = TmpT>
   struct ���������
   {
      inline constexpr decltype(auto) operator () (const TmpT &��ֵ��, const TmpU &��ֵ��) noexcept
      {
         return ��ֵ�� == ��ֵ��;
      }
   };

   template<>
   struct ���������<���Ϳյ�>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&��ֵ��, TmpU &&��ֵ��) noexcept
      {
         return std::forward<TmpT>(��ֵ��) == std::forward<TmpU>(��ֵ��);
      }
   };

   /**
    * \brief >>> �ṩ������������� "!=" �Ƚϵ��࣬����ʹ STmpT = void �õ��������ѡ�����͡�
    */
   template<typename TmpT = ���Ϳյ�, typename TmpU = TmpT>
   struct ���㲻�����
   {
      inline constexpr decltype(auto) operator () (const TmpT &��ֵ��, const TmpU &��ֵ��) noexcept
      {
         return ��ֵ��!= ��ֵ��;
      }
   };

   template<>
   struct ���㲻�����<���Ϳյ�>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&��ֵ��, TmpU &&��ֵ��) noexcept
      {
         return std::forward<TmpT>(��ֵ��) != std::forward<TmpU>(��ֵ��);
      }
   };

   /**
    * \brief >>> �ṩ������������� "<" �Ƚϵ��࣬����ʹ STmpT = void �õ��������ѡ�����͡�
    */
   template<typename TmpT = ���Ϳյ�, typename TmpU = TmpT>
   struct ����С����
   {
      inline constexpr decltype(auto) operator () (const TmpT &��ֵ��, const TmpU &��ֵ��) noexcept
      {
         return ��ֵ�� < ��ֵ��;
      }
   };

   template<>
   struct ����С����<���Ϳյ�>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&��ֵ��, TmpU &&��ֵ��) noexcept
      {
         return std::forward<TmpT>(��ֵ��) < std::forward<TmpU>(��ֵ��);
      }
   };

   /**
    * \brief >>> �ṩ������������� "<=" �Ƚϵ��࣬����ʹ STmpT = void �õ��������ѡ�����͡�
    */
   template<typename TmpT = ���Ϳյ�, typename TmpU = TmpT>
   struct ����С�ڵ�����
   {
      inline constexpr decltype(auto) operator () (const TmpT &��ֵ��, const TmpU &��ֵ��) noexcept
      {
         return ��ֵ�� <= ��ֵ��;
      }
   };

   template<>
   struct ����С�ڵ�����<���Ϳյ�>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&��ֵ��, TmpU &&��ֵ��) noexcept
      {
         return std::forward<TmpT>(��ֵ��) <= std::forward<TmpU>(��ֵ��);
      }
   };

   /**
    * \brief >>> �ṩ������������� ">" �Ƚϵ��࣬����ʹ STmpT = void �õ��������ѡ�����͡�
    */
   template<typename TmpT = ���Ϳյ�, typename TmpU = TmpT>
   struct ���������
   {
      inline constexpr decltype(auto) operator () (const TmpT &��ֵ��, const TmpU &��ֵ��) noexcept
      {
         return ��ֵ�� > ��ֵ��;
      }
   };

   template<>
   struct ���������<���Ϳյ�>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&��ֵ��, TmpU &&��ֵ��) noexcept
      {
         return std::forward<TmpT>(��ֵ��) > std::forward<TmpU>(��ֵ��);
      }
   };

   /**
    * \brief >>> �ṩ������������� ">=" �Ƚϵ��࣬����ʹ STmpT = void �õ��������ѡ�����͡�
    */
   template<typename TmpT = ���Ϳյ�, typename TmpU = TmpT>
   struct ������ڵ�����
   {
      inline constexpr decltype(auto) operator () (const TmpT &��ֵ��, const TmpU &��ֵ��) noexcept
      {
         return ��ֵ�� >= ��ֵ��;
      }
   };

   template<>
   struct ������ڵ�����<���Ϳյ�>
   {
      template<typename TmpT, typename TmpU>
      inline constexpr decltype(auto) operator () (TmpT &&��ֵ��, TmpU &&��ֵ��) noexcept
      {
         return std::forward<TmpT>(��ֵ��) >= std::forward<TmpU>(��ֵ��);
      }
   };

}
