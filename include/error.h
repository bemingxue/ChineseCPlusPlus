
namespace BE {

   // 一些错误信息的集合。
   namespace 错误集 {
    
      inline constexpr 类型错误 赋值自己错误 = C("试图自己赋值自己，但这不被允许！");

      inline constexpr 类型错误 赋值空指针错误 = C("试图赋值空指针，但这不被允许！");

      inline constexpr 类型错误 进制错误 = C("使用了函数库不支持的进制值！");

      inline constexpr 类型错误 转换错误 = C("进行转换操作时发生错误！");

      inline constexpr 类型错误 无效参数错误 = C("传入了被认为无效的参数值！");

      inline constexpr 类型错误 内存分配错误 = C("期望分配到内存，但失败！");

      inline constexpr 类型错误 严重内存分配错误 = C("期望分配到内存，但失败，但这次分配是必须的！");

      inline constexpr 类型错误 重复错误 = C("试图进行重复插入、删除等操作，但这不被允许！");

   }

   /**
    * \brief >>> 一个用于存储错误的类型，允许 const 时设置错误。
    */
   struct 错误类
   {

      /**
       * \brief >>> 获取错误信息。
       * 
       * \return 错误信息。
       */
      类型错误 获取错误() const noexcept
      {
         return 类中错误;
      }

      /**
       * \brief >>> 设置错误信息，允许 const 时修改
       * 
       * \param 错误项： 要设置的错误信息。
       * \return 
       */
      类型空的 设置错误(类型错误 错误项) const noexcept
      {
         类中错误 = 错误项;
      }

      /**
       * \brief >>> 重置错误信息为无错误，允许 const 时修改
       * 
       * \return 
       */
      类型空的 重置错误() const noexcept
      {
         类中错误 = 无错误;
      }

      /**
       * \brief >>> 判断是否产生了错误信息。
       * 
       * \return 有则返回假，否则返回真。
       */
      类型逻辑 无错误的() const noexcept
      {
         return 类中错误 == 无错误;
      }

      protected:

      mutable 类型错误 类中错误 = 无错误;

      public:

      /**
       * \brief >>> 允许转换为逻辑类型，用于判断是否有错误，explicit 的。
       * 
       * \return 没有错误返回真，否则返回假。
       */
      constexpr explicit operator 类型逻辑() const noexcept
      {
         return 类中错误 == 无错误;
      }
   };

   // 一种可以获取错误信息的类型的概念。
   template<typename TmpT>
   concept 错误类型 = requires(const TmpT X) {
      { X.获取错误() } -> 转换类型<类型错误>;
   };

}
