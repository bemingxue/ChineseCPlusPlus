
namespace BE::���缯 {

   // һЩ������ HTTP ͷ Content-Type ö��ֵ��
   enum class ���ı�����ͷö�� 
   {
      ���ı�,     // text/plain
      ������,   // multipart/form-data
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

   // һЩ������ HTTP ͷ���󷽷�ö��ֵ��
   enum class ���ı���������ö��
   {
      HGET,      // GET������ָ��ҳ����Ϣ��������ʵ�����塣
      HPOST,     // POST����ָ����Դ�ύ���ݽ��д������ݰ������������С�
      HPUT,      // PUT���ӿͻ�������������͵�����ȡ��ָ���ĵ������ݡ�
      HDELETE,   // DELETE�����������ɾ��ָ����ҳ�档
      HHEAD,     // HEAD�������� GET ����ֻ�������ص���Ӧ��û�о�������ݣ����ڻ�ȡ��ͷ��
      HOPTIONS,  // OPTIONS������ͻ��˲鿴�����������ܡ�
      HTRACE,    // TRACE�����Է������յ���������Ҫ���ڲ��Ի���ϡ�
      HCONNECT,  // CONNECT��Ԥ�����ܹ������Ӹ�Ϊ�ܵ���ʽ�Ĵ����������
   };

   // һЩ������ HTTP ״̬��ö��ֵ��
   enum class ���ı�����״̬ö��
   {
      �ɹ� = 200,         // 200 OK
      �Ѵ��� = 201,       // 201 Created
      ������ = 204,       // 204 No Content
      �ض��� = 301,       // 301 Moved Permanently
      ��ʱ�ض��� = 302,    // 302 Found
      δ�޸� = 304,       // 304 Not Modified
      �������� = 400,     // 400 Bad Request
      δ��Ȩ = 401,       // 401 Unauthorized
      ��ֹ = 403,         // 403 Forbidden
      δ�ҵ� = 404,       // 404 Not Found
      ���������� = 405,    // 405 Method Not Allowed
      ����ʱ = 408,     // 408 Request Timeout
      ��ͻ = 409,         // 409 Conflict
      ��Դ���� = 413,      // 413 Payload Too Large
      δ���� = 416,       // 416 Range Not Satisfiable
      �ڲ����� = 500,     // 500 Internal Server Error
      ���񲻿��� = 503,   // 503 Service Unavailable
      ���س�ʱ = 504,     // 504 Gateway Timeout
      �汾��֧�� = 505,    // 505 HTTP Version Not Supported
   };

   inline constexpr decltype(auto) ���ı��������д� = C("\r\n");
   inline constexpr decltype(auto) ���ı�����Э��汾 = C("HTTP/1.1");

   template<ö������ TmpEnum, ���ͳ��� TmpCount = static_cast<T::U32>(TmpEnum::END)>
   struct ���ı�����ģ����
   {
      /**
       * \brief >>> ��ȡ HTTP ͷָ�����ֵ��ַ���ֵ�� 
       * 
       * \param ���� Ҫ��ȡ��ö��ֵ��
       * \return ֻ���ַ������á�
       */
      const �ַ����� &��ȡ���(TmpEnum �����) const noexcept
      {
         return this->������ɱ�[static_cast<T::U32>(�����)];
      }

      /**
       * \brief >>> ���� HTTP ͷָ�����ֵ��ַ���ֵ��
       * 
       * \param ���� Ҫ���õ�ö��ֵ��
       * \param ��ֵ� Ҫ���õ��ַ���ֵ��
       * \return this &
       */
      ���ı�����ģ���� &�������(TmpEnum �����, �ַ���ͼ�� ��ֵ��) noexcept
      {
         this->������ɱ�[static_cast<T::U32>(�����)] = ��ֵ��;
         return *this;
      }

      /**
       * \brief >>> �������б����ʽ���� HTTP ͷָ�����ֵ��ַ���ֵ��
       * 
       * \param ��ֵ� Ҫ���õļ�ֵ���б���ö��ֵ���ַ���ֵ��ɡ�
       * \return this &
       */
      ���ı�����ģ���� &�������(const ģ���б�����<��ֵ��<TmpEnum, �ַ���ͼ��>> &��ֵ��) noexcept
      {
         for (const auto &������ : ��ֵ��)
         {
            this->������ɱ�[static_cast<T::U32>(������.��ȡ��ֵ())] = ������.��ȡβֵ();
         }

         return *this;
      }

      protected:

      �ַ����� ������ɱ�[TmpCount];
   };

   // HTTP ��Ӧͷ�����ö��ֵ��
   enum class ��Ӧͷ���ö�� : T::U32
   {
      ״̬��,       // statue code
      ���󷽷�,     // Allow
      �ĵ�����,     // Content-Encoding
      ���ݳ���,     // Content-Length
      ��������,     // Content-Type
      ����,         // GMT Date����ʽΪ��[day-name], [day] [month] [year] [hour]:[minute]:[second] GMT���������ڡ��·ݾ���Ӣ����д��
      �Զ�ˢ��,     // Refresh��ָʾ������Ե�����ʱ���ˢ���ĵ���
      ��������,     // Server
      ��Ȩ��Ϣ,     // WWW-Authenticate�������� 401 ״̬��ʱ���ṩ�����֤��Ϣ��
      END
   };

   struct ���ı�������Ӧͷ�� : ���ı�����ģ����<��Ӧͷ���ö��>
   {

      protected:

   };

}
