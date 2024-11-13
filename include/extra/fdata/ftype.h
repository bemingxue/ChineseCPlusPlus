
namespace BE {

   namespace 文件数据集 {

      using 类型识别码 = T::U64;

      inline 类型逻辑 文件识别码判断(文件类 &目标项, 类型识别码 识别项, 文件类::类型偏移 初始项 = 0)
      {
         if (!目标项.打开否())
         {
            return 假;
         }

         类型识别码 读取值 = 0;
         文件类::类型偏移 当前偏移 = 目标项.获取指针位置();
         
         目标项.头部偏移(初始项);

         while (读取值 < 识别项 && 目标项.非末尾())
         {
            读取值 = (读取值 << 8) | 目标项.读取字节();
         }

         目标项.头部偏移(当前偏移);
         return 读取值 == 识别项;
      }

      inline 类型逻辑 文件识别码判断(文件类 &目标项, const 模板列表类型<类型字节> &识别项, 文件类::类型偏移 初始项 = 0) noexcept
      {
         if (!目标项.打开否())
         {
            return 假;
         }

         文件类::类型偏移 当前偏移 = 目标项.获取指针位置();
         
         目标项.头部偏移(初始项);

         for (类型长度 索引量 = 0; 索引量 != 识别项.size() && 目标项.非末尾(); ++索引量)
         {
            if (目标项.读取字节() != *(识别项.begin() + 索引量))
            {
               目标项.头部偏移(当前偏移);
               return 假;
            }
         }

         目标项.头部偏移(当前偏移);
         return 真;
      }

      /**
       * \brief >>> 一个进行非文本文件类型识别的类，提供一些常见的类型识别，允许链式识别，其中有一次识别成功则整体都识别成功。
       */
      struct 文件识别类
      {

         文件识别类(文件类 &文件项) noexcept : 类中文件(文件项)
         {

         }

         文件识别类(文件识别类 &&) noexcept = delete;
         文件识别类(const 文件识别类 &) noexcept = delete;
         文件识别类 &operator = (文件识别类 &&) noexcept = delete;
         文件识别类 &operator = (const 文件识别类 &) noexcept = delete;

         文件识别类 &PNG() noexcept
         {
            return this->operator()(0x89504E470D0A1A0A);
         }

         文件识别类 &JPEG() noexcept
         {
            return this->operator()(0xFFD8FFE0);
         }

         文件识别类 &JPG() noexcept
         {
            return this->operator()(0xFFD8FFE1);
         }

         文件识别类 &GIF89() noexcept
         {
            return this->operator()(0x474946383961);
         }

         文件识别类 &GIF87() noexcept
         {
            return this->operator()(0x474946383761);
         }

         文件识别类 &GIF() noexcept
         {
            return this->GIF87(), this->GIF89();
         }

         文件识别类 &MP3ID3v2() noexcept
         {
            return this->operator()(0x494433);
         }

         文件识别类 &MP4ISOM() noexcept
         {
            return this->operator()(0x6674797069736F6D, 4);
         }

         文件识别类 &DOCX() noexcept
         {
            return this->operator()(0x504B030414000600);
         }

         文件识别类 &ZIP() noexcept
         {
            return this->operator()(0x504B0304);
         }

         文件识别类 &RAR5() noexcept
         {
            return this->operator()(0x526172211A070100);
         }

         文件识别类 &RAR4() noexcept
         {
            return this->operator()(0x526172211A0700);
         }

         文件识别类 &ICON() noexcept
         {
            return this->operator()({ 0x00, 0x00, 0x01, 0x00 });
         }

         文件识别类 &CURSOR() noexcept
         {
            return this->operator()({ 0x00, 0x00, 0x02, 0x00 });
         }

         private:

         文件类  &类中文件;
         类型逻辑 类中结果 = 假;

         文件识别类 &operator () (类型识别码 识别项, 文件类::类型偏移 初始项 = 0) noexcept
         {
            if (this->类中结果 == 假)
            {
               this->类中结果 = 文件识别码判断(this->类中文件, 识别项, 初始项);
            }
            return *this;
         }

         文件识别类 &operator () (const 模板列表类型<类型字节> &识别项, 文件类::类型偏移 初始项 = 0) noexcept
         {
            if (this->类中结果 == 假)
            {
               this->类中结果 = 文件识别码判断(this->类中文件, 识别项, 初始项);
            }
            return *this;
         }

         public:

         operator 类型逻辑 () const noexcept
         {
            return this->类中结果;
         }

         // 将判断的结果重置为假。
         文件识别类 &operator () () noexcept
         {
            this->类中结果 = 假;
            return *this;
         }
      };

   }

};
