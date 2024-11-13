
namespace BE {

   namespace 配置集 {

      /**
       * \brief >>> 对于末尾迭代函数获取字符数组的末尾迭代时，是否以数组最后一个成员作为结束迭代。
       * \brief > default: false
       * \brief > config: `_BE_CONFIG_GET_ITERATOR_STRING_END_`
       */
      inline constexpr 类型逻辑 末尾迭代对字符数组获取末尾 =

#ifndef _BE_CONFIG_GET_ITERATOR_STRING_END_
         false;
#else
         _BE_CONFIG_GET_ITERATOR_STRING_END_;
#endif




   }

}
