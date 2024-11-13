
namespace BE {

   namespace X {

      // һЩ�������Ͷ���ļ��ϡ�
      namespace T {

         using I8   = std::int8_t;
         using I16  = std::int16_t;
         using I32  = std::int32_t;
         using I64  = std::int64_t;
         using IMAX = std::intmax_t;
         using IPTR = std::intptr_t;
         
         using U8   = std::uint8_t;
         using U16  = std::uint16_t;
         using U32  = std::uint32_t;
         using U64  = std::uint64_t;
         using UMAX = std::uintmax_t;
         using UPTR = std::uintptr_t;

         using F32  = float;
         using F64  = double;
         using FMAX = long double;

         using VERSION = float;

         // UTF-8 �����ַ������ַ��Ļ������͡�
         using UTF8C = char8_t;
         // UTF-8 �����д洢һ���ַ�����������������͡�
         using UTF8I = U32;

         // ��semantic current���������ͣ�ͨ�����ڱ�ʾĿ������塣
         struct SCur {};

         // ��semantic place holder���������ͣ�ͨ�����ڱ�ʾռλ�����塣
         struct SPho {};

         // ��semantic end���������ͣ�ͨ�����ڱ�ʾ���������塣
         struct SEnd {};

         // �������ͣ���ʾ�Լ����ͣ��ṩһ�� type ���ͳ�Ա�����ڻ�ȡ�������͡�
         template<typename T>
         struct STyp { using type = T; };

      }

      // һЩ������˽��ʹ�õļ��ϡ�
      namespace R {

         template<unsigned int N>
         struct IntegerClass
         {
            static_assert(false, "Unsupported integer class");
         };

         template<>
         struct IntegerClass<8>
         {
            using type = T::I8;
         };

         template<>
         struct IntegerClass<16>
         {
            using type = T::I16;
         };

         template<>
         struct IntegerClass<32>
         {
            using type = T::I32;
         };

         template<>
         struct IntegerClass<64>
         {
            using type = T::I64;
         };

         template<unsigned int N>
         struct UnsignedClass
         {
            static_assert(false, "Unsupported unsigned class");
         };

         template<>
         struct UnsignedClass<8>
         {
            using type = T::U8;
         };

         template<>
         struct UnsignedClass<16>
         {
            using type = T::U16;
         };

         template<>
         struct UnsignedClass<32>
         {
            using type = T::U32;
         };

         template<>
         struct UnsignedClass<64>
         {
            using type = T::U64;
         };

         template<unsigned int N>
         struct FloatingClass
         {
            static_assert(false, "Unsupported floating class");
         };

         template<>
         struct FloatingClass<32>
         {
            using type = T::F32;
         };

         template<>
         struct FloatingClass<64>
         {
            using type = T::F64;
         }; 

      }

      // һЩ���Ժ����ļ��ϡ�
      namespace S {



      }

   }

   namespace T = X::T;

   // �������ͣ�������������
   using ���ͳ��� = decltype(sizeof(int));

   // �洢��ϣֵ�����͡�
   using ���͹�ϣ = std::size_t;

   // ��ʾ�߼������͡�
   using �����߼� = bool;

   // ��ʾ���ص����͡�
   using ���ͱ��� = bool;

   // һ���ڱȽϲ����еķ���ֵ���ͣ������ 0 ͨ����ʾ���ڣ�С�� 0 ͨ����ʾС�ڣ����� 0 ͨ����ʾ��ȡ�
   using ���ͱȽ� = long long;

   // ����������ַ����͡�
   using �����ַ� = char32_t;

   // ���ڴ洢��С�ɱ�ʾ�洢��λֵ�����͡�
   using �����ֽ� = unsigned char;

   // nullptr �� ��ָ�� ��ʾ�����͡�
   using ���Ϳ�ֵ = decltype(nullptr);

   // ��ʾ�����ַ��������͡�
   using ���ʹ��� = const char32_t *;

   // void ���͡�
   using ���Ϳյ� = void;

   // ��ʾ����ֵ�����͡�
   using ���ͽ��� = unsigned char;

   // ����ʹ��ģ�����ָ��ָ�����ش�С���������͡�
   template<unsigned int N = 32>
   using �������� = typename X::R::IntegerClass<N>::type;

   // ����ʹ��ģ�����ָ��ָ�����ش�С���޷����������͡�
   template<unsigned int N = 32>
   using �����޷� = typename X::R::UnsignedClass<N>::type;

   // ����ʹ��ģ�����ָ��ָ�����ش�С�ĸ������͡�
   template<unsigned int N = 64>
   using ���͸��� = typename X::R::FloatingClass<N>::type;   

   // ��һЩ���⺯����ʹ�ñ�ʾ����Ч���ĳ�����
   inline constexpr ���ͳ��� ��ĩβ = static_cast<���ͳ���>(-1);

   // ������תΪ�ַ���ʱ֧�ֵ���󾫶�ֵ��
   inline constexpr ���ͳ��� ��󾫶� = 256;

   // ������תΪ�ַ���ʱ�����С�����漸λ���� 0 ����ֹͣת����
   inline constexpr ���ͳ��� �������� = 3;

   // ������תΪ�ַ���ʱ���������Ĭ��ֵ��
   inline constexpr ���ͳ��� Ĭ�Ͼ��� = 6;

   // nullptr �ĳ�����ʾ��
   inline constexpr ���Ϳ�ֵ ��ָ�� = nullptr;

   // �����ַ�����ʾû�д���ĳ�����
   inline constexpr ���ʹ��� �޴��� = C("û�д�����Ϣ��");

   // ��ʾ��ǰϵͳ�Ƿ�Ϊ�����ĳ�����
   inline constexpr �����߼� ����� = std::endian::native == std::endian::big;

   // true �ĳ�����ʾ��
   inline constexpr �����߼� �� = true;

   // false �ĳ�����ʾ��
   inline constexpr �����߼� �� = false;

   // ��ʾռλ����ĳ�����
   inline constexpr T::SPho  ռλ�� = {};

   // ��ʾ��������ĳ�����
   inline constexpr T::SEnd  ĩβֵ = {};

   // �����Ա������ʹ�ô洢������Ϣ�Ĵ����롣
   inline ���ʹ��� ������ = �޴���;

   /**
    * \brief >>> ��ȡ��ǰ������İ汾�ţ������ں�����
    * 
    * \return �汾�š�
    */
   inline consteval T::VERSION ��ȡ�汾��() noexcept
   {
      return 1.0f;
   }

   /**
    * \brief >>> ����ȫ�ִ����벢��ȫ�ִ��������á�
    * 
    * \return ������Ϣ��
    */
   inline ���ʹ��� ��ȡ������() noexcept
   {
      ���ʹ��� ���� = ������;

      ������ = �޴���;

      return ����;
   }

   // �������ģ���е����в���ֵ�����Ա�ת��Ϊ����ֵΪ�棬����Ϊ�١�
   template<auto... TmpArgs>
   inline constexpr �����߼� ȫ��ֵ = (static_cast<�����߼�>(TmpArgs) && ...);

   // �������ģ���е�����һ������ֵ���Ա�ת��Ϊ����ֵΪ�棬����Ϊ�١�
   template<auto... TmpArgs>
   inline constexpr �����߼� ����ֵ = (static_cast<�����߼�>(TmpArgs) || ...);

   /**
    * \brief >>> ȥ���������е�ֻ�����η���
    * 
    * \param ����� ֻ�����á�
    * \return ȥ��ֻ�����η���Ĳ��������á�
    */
   template<typename TmpT>
   inline constexpr TmpT &ȥ��ֻ��(const TmpT &������) noexcept
   {
      return const_cast<TmpT &>(������);
   }

   /**
    * \brief >>> �Ƚ����ߣ������رȽϽ����
    * 
    * \param ��ֵ� ���бȽϵĶ���
    * \param ��ֵ� ���бȽϵĶ���
    * \return ��ֵ�������ֵ���򷵻ش������ֵ����ֵ��С����ֵ���򷵻�С�����ֵ������򷵻��㡣
    */
   template<typename TmpT>
   inline constexpr ���ͱȽ� �Ƚ�(TmpT &&��ֵ��, typename T::STyp<TmpT>::type &&��ֵ��) noexcept
   {
      return ��ֵ�� > ��ֵ�� ?  1 : (��ֵ�� < ��ֵ�� ? -1 : 0);
   }

}
