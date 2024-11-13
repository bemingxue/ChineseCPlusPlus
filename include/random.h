
namespace BE {

   // 提供一些较为专业的随机数引擎和分布等。
   namespace 随机集 {

      using 线性同余引擎类 = std::minstd_rand;

      using 梅森旋转引擎类 = std::mt19937_64;

      using 斐波拉契引擎类 = std::ranlux48_base;

      using 默认使用引擎类 = std::default_random_engine;

      /**
       * \brief >>> 使用真随机数引擎生成随机数，注意真随机数生成效率不高，且对于不支持真随机数生成的设备，其将使用默认随机数引擎进行生成。
       * 
       * \return 生成的真随机数。
       */
      std::random_device::result_type 真随机数() noexcept
      {
         static std::random_device rd { };

         return rd.operator()();
      }

      // 随机数函数默认使用的引擎实例。
      inline 默认使用引擎类 默认引擎{ 真随机数() };

      // 给定一个 0 - 1 的概率值，生成随机布尔值。
      using 伯努利概率分布类 = std::bernoulli_distribution;

      // 给定一个最小值和最大值，生成随机整数，包括最小值和最大值。
      template<整数类型 TmpT = 类型整数<>>
      using 均匀整数分布类 = std::uniform_int_distribution<TmpT>;

      // 给定一个最小值和最大值，生成随机实数，包括最小值和最大值。
      template<浮点类型 TmpT = 类型浮点<>>
      using 均匀实数分布类 = std::uniform_real_distribution<TmpT>;

      // 给定一个 0 - 1 的概率值和一个整数，如果概率值越接近 1 则生成的随机数接近给定整数的概率越大，否则接近 0 的概率就越大。
      template<整数类型 TmpT = 类型整数<>>
      using 伯努利迫近分布类 = std::binomial_distribution<TmpT>;

      // 给定一个大于 0 的分散参数，生成随机正整数，数字越接近分散参数生成的概率就越高。
      template<整数类型 TmpT = 类型整数<>>
      using 泊松分布类 = std::poisson_distribution<TmpT>;

      // 给定一个大于 0 的分散参数，生成随机正实数，数字越接近分散参数生成的概率就越高。
      template<浮点类型 TmpT = 类型浮点<>>
      using 泊松指数分布类 = std::exponential_distribution<TmpT>;

      // 给定一个均值和大于 0 的标准差，生成随机正实数，数字分布服从正态分布，即越接近均值生成的概率越高，标准差由于控制这一曲线的曲率。
      template<浮点类型 TmpT = 类型浮点<>>
      using 正态分布类 = std::normal_distribution<TmpT>;

   }

   /**
    * \brief >>> 使用均匀分布生成指定区间范围内的随机整数。
    * 
    * \param 最小项： 最小区间值。
    * \param 最大项： 最大区间值。
    * \param 引擎项： 要使用的生成引擎。
    * \return 范围 [min, max] 区间的随机整数。
    * \tparam TmpRet： 随机整数的类型。
    * \tparam TmpEng： 随机数生成引擎的类型。
    */
   template<整数类型 TmpRet = 类型整数<>, typename TmpEng = 随机集::默认使用引擎类 &>
   inline constexpr TmpRet 随机数(TmpRet 最小项, TmpRet 最大项, TmpEng &&引擎项 = 随机集::默认引擎) noexcept
   {
      return 随机集::均匀整数分布类<TmpRet> { 最小项, 最大项 } (引擎项);
   }

   /**
    * \brief >>> 使用均匀分布生成指定 0 - 1 范围内的随机实数。
    * 
    * \param 引擎项： 要使用的生成引擎。
    * \return 范围 [0, 1] 区间的随机实数。
    * \tparam TmpRet： 随机实数的类型。
    * \tparam TmpEng： 随机数生成引擎的类型。
    */
   template<浮点类型 TmpRet = 类型浮点<>, typename TmpEng = 随机集::默认使用引擎类 &>
   inline constexpr TmpRet 随机数(TmpEng &&引擎项 = 随机集::默认引擎) noexcept
   {
      return 随机集::均匀实数分布类<TmpRet> { 0, 1} (引擎项);
   }

}
