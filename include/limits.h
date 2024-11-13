
namespace BE {

   /**
    * \brief >>> 存储数字：最大值、最小值、误差值、正无穷值、非数值、存储位、最大整数位。等基本数据信息的类型。
    * \tparam TmpT： 任意类型，但没有自定义特化时只有 STmpT 为标准数字类型时才有有效值。
    */
   template<typename TmpT>
   struct 数字信息类
   {
      private:

      using limits = std::numeric_limits<TmpT>;

      public:

      // 对于 STmpT 的可存储最大值。
      static constexpr auto 最小值 = limits::min();

      // 对于 STmpT 的可存储最小值。
      static constexpr auto 最大值 = limits::max();

      // 对于 STmpT 是浮点数时的误差值。
      static constexpr auto 误差值 = limits::epsilon();

      // 对于 STmpT 是浮点数时的正无穷值。
      static constexpr auto 正无穷 = limits::infinity();

      // 对于 STmpT 是浮点数时的正非数值。
      static constexpr auto 非数值 = limits::quiet_NaN();

      // 对于 STmpT 其存储数据所占用的位数，如三十二位整数为 31 这是因为符号位并不算在其中。
      static constexpr auto 存储位 = limits::digits;

      // 对于 STmpT 其存储数据最大可完整存储的整数位数，如三十二位整数可以完整存储 0 - 999999999 之间的整数，但不能完整存储 1000000000  - 9999999999  之间的所有数字。 
      static constexpr auto 最大整数位 = limits::digits10;

   };

}
