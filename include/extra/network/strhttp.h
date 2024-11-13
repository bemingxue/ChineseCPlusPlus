
namespace BE::网络集 {

   // 一些常见的 HTTP 头 Content-Type 枚举值。
   enum class 超文本传输头枚举 
   {
      纯文本,     // text/plain
      表单数据,   // multipart/form-data
      JPEG,      // image/jpeg
      PNG,       // image/png
      GIF,       // image/gif
      HTML,      // text/html
      CSS,       // text/css
      JSON,      // application/json
      XML,       // application/xml
      MP4,       // video/mp4
      MPEG,      // video/mpeg
      WAV,       // audio/wav
      PDF,       // application/pdf
   };

   // 一些常见的 HTTP 头请求方法枚举值。
   enum class 超文本传输请求枚举
   {
      HGET,      // GET，请求指定页面信息，并返回实体主体。
      HPOST,     // POST，向指定资源提交数据进行处理，数据包含在请求体中。
      HPUT,      // PUT，从客户端向服务器传送的数据取代指定文档的内容。
      HDELETE,   // DELETE，请求服务器删除指定的页面。
      HHEAD,     // HEAD，类似于 GET 请求，只不过返回的响应中没有具体的内容，用于获取报头。
      HOPTIONS,  // OPTIONS，允许客户端查看服务器的性能。
      HTRACE,    // TRACE，回显服务器收到的请求，主要用于测试或诊断。
      HCONNECT,  // CONNECT，预留给能够将链接改为管道方式的代理服务器。
   };

   // 一些常见的 HTTP 状态码枚举值。
   enum class 超文本传输状态枚举
   {
      成功 = 200,         // 200 OK
      已创建 = 201,       // 201 Created
      无内容 = 204,       // 204 No Content
      重定向 = 301,       // 301 Moved Permanently
      临时重定向 = 302,    // 302 Found
      未修改 = 304,       // 304 Not Modified
      错误请求 = 400,     // 400 Bad Request
      未授权 = 401,       // 401 Unauthorized
      禁止 = 403,         // 403 Forbidden
      未找到 = 404,       // 404 Not Found
      方法不允许 = 405,    // 405 Method Not Allowed
      请求超时 = 408,     // 408 Request Timeout
      冲突 = 409,         // 409 Conflict
      资源过大 = 413,      // 413 Payload Too Large
      未满足 = 416,       // 416 Range Not Satisfiable
      内部错误 = 500,     // 500 Internal Server Error
      服务不可用 = 503,   // 503 Service Unavailable
      网关超时 = 504,     // 504 Gateway Timeout
      版本不支持 = 505,    // 505 HTTP Version Not Supported
   };

   inline constexpr decltype(auto) 超文本传输新行串 = C("\r\n");
   inline constexpr decltype(auto) 超文本传输协议版本 = C("HTTP/1.1");

   template<枚举类型 TmpEnum, 类型长度 TmpCount = static_cast<T::U32>(TmpEnum::END)>
   struct 超文本传输模板类
   {
      /**
       * \brief >>> 获取 HTTP 头指定部分的字符串值。 
       * 
       * \param 组成项： 要获取的枚举值。
       * \return 只读字符串引用。
       */
      const 字符串类 &获取组成(TmpEnum 组成项) const noexcept
      {
         return this->类中组成表[static_cast<T::U32>(组成项)];
      }

      /**
       * \brief >>> 设置 HTTP 头指定部分的字符串值。
       * 
       * \param 组成项： 要设置的枚举值。
       * \param 赋值项： 要设置的字符串值。
       * \return this &
       */
      超文本传输模板类 &设置组成(TmpEnum 组成项, 字符视图类 赋值项) noexcept
      {
         this->类中组成表[static_cast<T::U32>(组成项)] = 赋值项;
         return *this;
      }

      /**
       * \brief >>> 按键对列表的形式设置 HTTP 头指定部分的字符串值。
       * 
       * \param 赋值项： 要设置的键值对列表，由枚举值和字符串值组成。
       * \return this &
       */
      超文本传输模板类 &设置组成(const 模板列表类型<对值类<TmpEnum, 字符视图类>> &赋值项) noexcept
      {
         for (const auto &迭代量 : 赋值项)
         {
            this->类中组成表[static_cast<T::U32>(迭代量.获取首值())] = 迭代量.获取尾值();
         }

         return *this;
      }

      protected:

      字符串类 类中组成表[TmpCount];
   };

   // HTTP 响应头的组成枚举值。
   enum class 响应头组成枚举 : T::U32
   {
      状态码,       // statue code
      请求方法,     // Allow
      文档编码,     // Content-Encoding
      数据长度,     // Content-Length
      数据类型,     // Content-Type
      日期,         // GMT Date，格式为：[day-name], [day] [month] [year] [hour]:[minute]:[second] GMT，其中星期、月份均用英文缩写。
      自动刷新,     // Refresh，指示浏览器以当多少时间后刷新文档。
      服务器名,     // Server
      授权信息,     // WWW-Authenticate，当包含 401 状态码时，提供身份验证信息。
      END
   };

   struct 超文本传输响应头类 : 超文本传输模板类<响应头组成枚举>
   {

      protected:

   };

}
