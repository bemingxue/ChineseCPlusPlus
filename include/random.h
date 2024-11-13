
namespace BE {

   // �ṩһЩ��Ϊרҵ�����������ͷֲ��ȡ�
   namespace ����� {

      using ����ͬ�������� = std::minstd_rand;

      using ÷ɭ��ת������ = std::mt19937_64;

      using 쳲����������� = std::ranlux48_base;

      using Ĭ��ʹ�������� = std::default_random_engine;

      /**
       * \brief >>> ʹ������������������������ע�������������Ч�ʲ��ߣ��Ҷ��ڲ�֧������������ɵ��豸���佫ʹ��Ĭ�����������������ɡ�
       * 
       * \return ���ɵ����������
       */
      std::random_device::result_type �������() noexcept
      {
         static std::random_device rd { };

         return rd.operator()();
      }

      // ���������Ĭ��ʹ�õ�����ʵ����
      inline Ĭ��ʹ�������� Ĭ������{ �������() };

      // ����һ�� 0 - 1 �ĸ���ֵ�������������ֵ��
      using ��Ŭ�����ʷֲ��� = std::bernoulli_distribution;

      // ����һ����Сֵ�����ֵ���������������������Сֵ�����ֵ��
      template<�������� TmpT = ��������<>>
      using ���������ֲ��� = std::uniform_int_distribution<TmpT>;

      // ����һ����Сֵ�����ֵ���������ʵ����������Сֵ�����ֵ��
      template<�������� TmpT = ���͸���<>>
      using ����ʵ���ֲ��� = std::uniform_real_distribution<TmpT>;

      // ����һ�� 0 - 1 �ĸ���ֵ��һ���������������ֵԽ�ӽ� 1 �����ɵ�������ӽ����������ĸ���Խ�󣬷���ӽ� 0 �ĸ��ʾ�Խ��
      template<�������� TmpT = ��������<>>
      using ��Ŭ���Ƚ��ֲ��� = std::binomial_distribution<TmpT>;

      // ����һ������ 0 �ķ�ɢ�������������������������Խ�ӽ���ɢ�������ɵĸ��ʾ�Խ�ߡ�
      template<�������� TmpT = ��������<>>
      using ���ɷֲ��� = std::poisson_distribution<TmpT>;

      // ����һ������ 0 �ķ�ɢ���������������ʵ��������Խ�ӽ���ɢ�������ɵĸ��ʾ�Խ�ߡ�
      template<�������� TmpT = ���͸���<>>
      using ����ָ���ֲ��� = std::exponential_distribution<TmpT>;

      // ����һ����ֵ�ʹ��� 0 �ı�׼����������ʵ�������ֲַ�������̬�ֲ�����Խ�ӽ���ֵ���ɵĸ���Խ�ߣ���׼�����ڿ�����һ���ߵ����ʡ�
      template<�������� TmpT = ���͸���<>>
      using ��̬�ֲ��� = std::normal_distribution<TmpT>;

   }

   /**
    * \brief >>> ʹ�þ��ȷֲ�����ָ�����䷶Χ�ڵ����������
    * 
    * \param ��С� ��С����ֵ��
    * \param ���� �������ֵ��
    * \param ����� Ҫʹ�õ��������档
    * \return ��Χ [min, max] ��������������
    * \tparam TmpRet�� ������������͡�
    * \tparam TmpEng�� �����������������͡�
    */
   template<�������� TmpRet = ��������<>, typename TmpEng = �����::Ĭ��ʹ�������� &>
   inline constexpr TmpRet �����(TmpRet ��С��, TmpRet �����, TmpEng &&������ = �����::Ĭ������) noexcept
   {
      return �����::���������ֲ���<TmpRet> { ��С��, ����� } (������);
   }

   /**
    * \brief >>> ʹ�þ��ȷֲ�����ָ�� 0 - 1 ��Χ�ڵ����ʵ����
    * 
    * \param ����� Ҫʹ�õ��������档
    * \return ��Χ [0, 1] ��������ʵ����
    * \tparam TmpRet�� ���ʵ�������͡�
    * \tparam TmpEng�� �����������������͡�
    */
   template<�������� TmpRet = ���͸���<>, typename TmpEng = �����::Ĭ��ʹ�������� &>
   inline constexpr TmpRet �����(TmpEng &&������ = �����::Ĭ������) noexcept
   {
      return �����::����ʵ���ֲ���<TmpRet> { 0, 1} (������);
   }

}
