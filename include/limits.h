
namespace BE {

   /**
    * \brief >>> �洢���֣����ֵ����Сֵ�����ֵ��������ֵ������ֵ���洢λ���������λ���Ȼ���������Ϣ�����͡�
    * \tparam TmpT�� �������ͣ���û���Զ����ػ�ʱֻ�� STmpT Ϊ��׼��������ʱ������Чֵ��
    */
   template<typename TmpT>
   struct ������Ϣ��
   {
      private:

      using limits = std::numeric_limits<TmpT>;

      public:

      // ���� STmpT �Ŀɴ洢���ֵ��
      static constexpr auto ��Сֵ = limits::min();

      // ���� STmpT �Ŀɴ洢��Сֵ��
      static constexpr auto ���ֵ = limits::max();

      // ���� STmpT �Ǹ�����ʱ�����ֵ��
      static constexpr auto ���ֵ = limits::epsilon();

      // ���� STmpT �Ǹ�����ʱ��������ֵ��
      static constexpr auto ������ = limits::infinity();

      // ���� STmpT �Ǹ�����ʱ��������ֵ��
      static constexpr auto ����ֵ = limits::quiet_NaN();

      // ���� STmpT ��洢������ռ�õ�λ��������ʮ��λ����Ϊ 31 ������Ϊ����λ�����������С�
      static constexpr auto �洢λ = limits::digits;

      // ���� STmpT ��洢�������������洢������λ��������ʮ��λ�������������洢 0 - 999999999 ֮��������������������洢 1000000000  - 9999999999  ֮����������֡� 
      static constexpr auto �������λ = limits::digits10;

   };

}
