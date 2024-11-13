
namespace BE {

   /**
    * \brief >>> 一种管理 C Type 数组的可迭代类型，以允许复制，不过不支持长度 0 的数组。
    * \brief >>> 此外，类还提供了二维数组的索引方法（不过是先索引行再索引列，这点有些不同），支持二维数组，但底层依旧是使用一维数组进行的存储。
    * \tparam TmpT： 数组元素类型，满足对象类型概念。
    * \tparam TmpW： 数组宽度，即数组的列数。
    * \tparam TmpH： 数组高度，即数组的行数，默认为 1。
    */
   template<对象类型 TmpT, 类型长度 TmpW, 类型长度 TmpH = 1>
   struct 标准数组类
   {
      using 标准数组标识 = void;

      // 不能为 0 长度的数组。
      static_assert(TmpW * TmpH > 0, "Array length cannot be zero - 数组长度不能为 0！");

      // 以数组本身为迭代器。
      TmpT *begin() noexcept {  return 数组; }
      TmpT *end() noexcept {  return 数组 + TmpW * TmpH; }

      // 以数组本身为只读迭代器。
      TmpT const *begin() const noexcept {  return 数组; }
      TmpT const *end() const noexcept {  return 数组 + TmpW * TmpH; }

      /**
       * \brief >>> 获取数组中指定位置的元素值。
       * 
       * \param 索引项： 索引，注意越界。
       * \return 元素引用。
       */
      constexpr TmpT &索引值(类型长度 索引项) noexcept
      {
         return 数组[索引项];
      }

      /**
       * \brief >>> 获取数组中指定位置的元素值。
       * 
       * \param 索引项： 索引，注意越界。
       * \return 元素只读引用。
       */
      constexpr const TmpT &索引值(类型长度 索引项) const noexcept
      {
         return 数组[索引项];
      }

      /**
       * \brief >>> 获取数组中第几行第几列的元素引用。
       * 
       * \param 行索引项： 行索引，注意越界。
       * \param 列索引项： 列索引，注意越界。
       * \return 元素引用。
       */
      constexpr TmpT &索引值(类型长度 行索引项, 类型长度 列索引项) noexcept
      {
         return 数组[行索引项 * TmpW + 列索引项];
      }

      /**
       * \brief >>> 获取数组中第几行第几列的元素只读引用。
       * 
       * \param 行索引项： 行索引，注意越界。
       * \param 列索引项： 列索引，注意越界。
       * \return 元素只读引用。
       */
      constexpr const TmpT &索引值(类型长度 行索引项, 类型长度 列索引项) const noexcept
      {
         return 数组[行索引项 * TmpW + 列索引项];
      }

      /**
       * \brief >>> 获取数组中最后一个元素的引用。
       * 
       * \return 元素引用。
       */
      constexpr TmpT &获取尾值() noexcept
      {
         return 数组[TmpW * TmpH - 1];
      }

      /**
       * \brief >>> 获取数组中最后一个元素的只读引用。
       * 
       * \return 元素只读引用。
       */
      constexpr const TmpT &获取尾值() const noexcept
      {
         return 数组[TmpW * TmpH - 1];
      }

      /**
       * \brief >>> 获取数组的长度，即数组中元素的总数量。
       * 
       * \return 元素总数量。
       */
      constexpr 类型长度 获取长度() const noexcept
      {
         return TmpW * TmpH;
      }

      /**
       * \brief >>> 获取数组中的行数。
       * 
       * \return 行数。
       */
      constexpr 类型长度 获取行数() const noexcept
      {
         return TmpH;
      }

      /**
       * \brief >>> 获取数组中的列数。
       * 
       * \return 列数。
       */
      constexpr 类型长度 获取列数() const noexcept
      {
         return TmpW;
      }

      /**
       * \brief >>> 获取数组的指针。
       * 
       * \return 数组指针。
       */
      constexpr TmpT *获取指针() noexcept
      {
         return 数组;
      }

      /**
       * \brief >>> 获取数组的只读指针。
       * 
       * \return 数组只读指针。
       */
      constexpr const TmpT *获取指针() const noexcept
      {
         return 数组;
      }

      // 获取数组中第几个元素的引用，注意越界。
      constexpr TmpT &operator[](类型长度 索引项) noexcept
      {
         return this->索引值(索引项);
      }

      // 获取数组中第几个元素的只读引用，注意越界。
      constexpr const TmpT &operator[](类型长度 索引项) const noexcept
      {
         return this->索引值(索引项);
      }

      // 获取数组中第几行第几列的元素引用，注意越界。
      constexpr TmpT &operator()(类型长度 行索引项, 类型长度 列索引项) noexcept
      {
         return this->索引值(行索引项, 列索引项);
      }

      // 获取数组中第几行第几列的元素只读引用，注意越界。
      constexpr const TmpT &operator()(类型长度 行索引项, 类型长度 列索引项) const noexcept
      {
         return this->索引值(行索引项, 列索引项);
      }

      // 存储的一维数组。
      TmpT 数组[TmpW * TmpH];
   };

   // 模板推导，以第一个参数类型为基准。
   template<typename TmpT, typename... TmpArgs>
   标准数组类(TmpT, TmpArgs...) -> 标准数组类<TmpT, sizeof...(TmpArgs) + 1>;

}
