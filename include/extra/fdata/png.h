
namespace BE {

   namespace 文件数据集 {

      /*********************************************
       * PNG 数据块种类：
       * - *IHDR 图像头部数据块。
       * -  cHRM 基色和白色点信息。
       * -  gAMA 图像的 γ 值。
       * -  sBIT 样本有效位数据块。
       * -  PLTE 调色板颜色数据块。
       * -  bKGD 背景颜色数据块。
       * -  hIST 直方图数据块。
       * -  tRNS 透明度数据块。
       * -  oFFs 专用公共数据块。
       * -  pHYs 物理像素尺寸数据块。
       * -  sCAL 专用公共数据块。
       * - *IDAT 图像数据块。
       * -  tIME 时间戳数据块。
       * -  tEXt 文本信息数据块。
       * -  zTXt 压缩文本信息数据块。
       * -  fRAc 专用公共数据块。
       * -  gIFg、gIFt、gIFx 专用公共数据块。
       * - *IEND 图像结束数据块。
       */

      // PNG 数据文件中 IHDR 数据块的信息结构。
      struct PNG头部结构
      {
         T::U32 图像宽度;
         T::U32 图像高度;
         T::U8  图像深度;
         T::U8  颜色类型;
         T::U8  压缩方法;
         T::U8  滤波器方法;
         T::U8  隔行扫描法;  // 为 1 时表示 ADAM7 扫描算法。
      };

      struct PNG数据块类
      {
         // PNG 数据文件的标识头占用的字节数。
         static constexpr 类型长度 头长度 = 8;
         // PNG 数据文件中数据块的字节序是否采用大端序存储。
         static constexpr 类型长度 存储大端序 = true;

         T::U32  块长度 = 0;      // 数据块的长度。
         类型字节 类型码[4];      // PNG 数据文件中表示数据库名称、
         字节类 数据块;
         T::U32 循环冗余码 = 0;   // CRC-32 循环冗余校验码

         /**
          * \brief >>> 从指定文件中读取 PNG 数据块。
          * 
          * \param 文件项： 要读取的 PNG 数据文件。
          * \return 是否完整的读取整个 PNG 数据块。
          */
         类型逻辑 读取数据块(文件类 &文件项) noexcept
         {
            if (文件项.打开否())
            {
               类型长度 读取长度 = 0;

               读取长度 += 文件项.读取字节对象(this->块长度);
               读取长度 += 文件项.读取字节对象(this->类型码);

               if (BE::大端序 != 存储大端序)
               {
                  BE::翻转字节序(this->块长度);
               }

               if (读取长度 == 8)
               {
                  // 让数据块的长度对齐到 8 字节的大小。
                  this->数据块.赋值(this->块长度 + (this->块长度 % 8ull));

                  读取长度 += 文件项.读取字节块(this->数据块.获取字节指针(), this->块长度);
                  读取长度 += 文件项.读取字节对象(this->循环冗余码);

                  if (BE::大端序 != 存储大端序)
                  {
                     BE::翻转字节序(this->循环冗余码);
                  }

                  return 读取长度 == 12ull + this->块长度;
               }
            }

            return 假;
         }

         /**
          * \brief >>> 如果你确定当前 PNG 数据库属于 IHDR 数据块，则可以使用此函数获取 IHDR 数据块的信息。
          * 
          * \return 数据块信息。
          */
         PNG头部结构 获取头部块信息() noexcept
         {
            PNG头部结构 返回值;

            this->数据块.设置范围(0) >> 返回值;

            if (BE::大端序 != 存储大端序)
            {
               BE::翻转字节序(返回值.图像宽度);
               BE::翻转字节序(返回值.图像高度);
            }
            // 其他一字节数据就不翻转了。

            return 返回值;
         }
      };

      struct PNG类
      {
         using 句柄类 = std::unordered_map<字符串类, PNG数据块类>;

         auto begin() noexcept { return this->类中数据块.begin(); }
         auto end() noexcept { return this->类中数据块.end(); }

         /**
          * \brief >>> 从指定路径上的 png 文件中读取 PNG 数据，注意不仅文件后缀名需要是 PNG，并且文件数据格式也必须是 PNG 的。
          * 
          * \param 路径项： 要读取的文件路径。
          * \return this &
          */
         PNG类 &读取文件(字符视图类 路径项) noexcept
         {
            this->清除();

            文件类 读取目标;
            PNG数据块类 读取块;

            读取目标.打开(路径项);

            if (字符视图类(C(".png"), 4, false) == 读取目标.获取后缀() && 读取目标.打开否() && 文件识别类(读取目标).PNG())
            {
               读取目标.头部偏移(PNG数据块类::头长度);
               
               while (读取目标.非末尾())
               {
                  if (读取块.读取数据块(读取目标))
                  {
                     this->类中数据块[字符串类(读取块.类型码 + 0, 读取块.类型码 + 4, 4)] = 读取块;
                  }
               }
            }

            return *this;
         }

         /**
          * \brief >>> 清除当前存储的 PNG 数据信息。
          * 
          * \return this &
          */
         PNG类 &清除() noexcept
         {
            this->类中数据块.clear();
            return *this;
         }

         /**
          * \brief >>> 函数检查当前是否存储数据，可用于读取 PNG 文件后判断是否读取成功。
          * 
          * \return 存储数据返回真，否则返回假。
          */
         类型逻辑 非空的() const noexcept
         {
            return !this->类中数据块.empty();
         }

         protected:

         句柄类 类中数据块;

         static PNG数据块类 空数据块;

         public:

         // 访问指定名称的 PNG 数据块，如果不存在则返回空数据块。
         PNG数据块类 &operator [] (字符视图类 键名项) noexcept
         {
            if (auto 数据块 = this->类中数据块.find(键名项); 数据块 != this->类中数据块.end())
            {
               return 数据块->second;
            }
            return 空数据块;
         }
      };

   }

}
