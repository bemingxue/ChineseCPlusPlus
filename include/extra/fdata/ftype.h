
namespace BE {

   namespace �ļ����ݼ� {

      using ����ʶ���� = T::U64;

      inline �����߼� �ļ�ʶ�����ж�(�ļ��� &Ŀ����, ����ʶ���� ʶ����, �ļ���::����ƫ�� ��ʼ�� = 0)
      {
         if (!Ŀ����.�򿪷�())
         {
            return ��;
         }

         ����ʶ���� ��ȡֵ = 0;
         �ļ���::����ƫ�� ��ǰƫ�� = Ŀ����.��ȡָ��λ��();
         
         Ŀ����.ͷ��ƫ��(��ʼ��);

         while (��ȡֵ < ʶ���� && Ŀ����.��ĩβ())
         {
            ��ȡֵ = (��ȡֵ << 8) | Ŀ����.��ȡ�ֽ�();
         }

         Ŀ����.ͷ��ƫ��(��ǰƫ��);
         return ��ȡֵ == ʶ����;
      }

      inline �����߼� �ļ�ʶ�����ж�(�ļ��� &Ŀ����, const ģ���б�����<�����ֽ�> &ʶ����, �ļ���::����ƫ�� ��ʼ�� = 0) noexcept
      {
         if (!Ŀ����.�򿪷�())
         {
            return ��;
         }

         �ļ���::����ƫ�� ��ǰƫ�� = Ŀ����.��ȡָ��λ��();
         
         Ŀ����.ͷ��ƫ��(��ʼ��);

         for (���ͳ��� ������ = 0; ������ != ʶ����.size() && Ŀ����.��ĩβ(); ++������)
         {
            if (Ŀ����.��ȡ�ֽ�() != *(ʶ����.begin() + ������))
            {
               Ŀ����.ͷ��ƫ��(��ǰƫ��);
               return ��;
            }
         }

         Ŀ����.ͷ��ƫ��(��ǰƫ��);
         return ��;
      }

      /**
       * \brief >>> һ�����з��ı��ļ�����ʶ����࣬�ṩһЩ����������ʶ��������ʽʶ��������һ��ʶ��ɹ������嶼ʶ��ɹ���
       */
      struct �ļ�ʶ����
      {

         �ļ�ʶ����(�ļ��� &�ļ���) noexcept : �����ļ�(�ļ���)
         {

         }

         �ļ�ʶ����(�ļ�ʶ���� &&) noexcept = delete;
         �ļ�ʶ����(const �ļ�ʶ���� &) noexcept = delete;
         �ļ�ʶ���� &operator = (�ļ�ʶ���� &&) noexcept = delete;
         �ļ�ʶ���� &operator = (const �ļ�ʶ���� &) noexcept = delete;

         �ļ�ʶ���� &PNG() noexcept
         {
            return this->operator()(0x89504E470D0A1A0A);
         }

         �ļ�ʶ���� &JPEG() noexcept
         {
            return this->operator()(0xFFD8FFE0);
         }

         �ļ�ʶ���� &JPG() noexcept
         {
            return this->operator()(0xFFD8FFE1);
         }

         �ļ�ʶ���� &GIF89() noexcept
         {
            return this->operator()(0x474946383961);
         }

         �ļ�ʶ���� &GIF87() noexcept
         {
            return this->operator()(0x474946383761);
         }

         �ļ�ʶ���� &GIF() noexcept
         {
            return this->GIF87(), this->GIF89();
         }

         �ļ�ʶ���� &MP3ID3v2() noexcept
         {
            return this->operator()(0x494433);
         }

         �ļ�ʶ���� &MP4ISOM() noexcept
         {
            return this->operator()(0x6674797069736F6D, 4);
         }

         �ļ�ʶ���� &DOCX() noexcept
         {
            return this->operator()(0x504B030414000600);
         }

         �ļ�ʶ���� &ZIP() noexcept
         {
            return this->operator()(0x504B0304);
         }

         �ļ�ʶ���� &RAR5() noexcept
         {
            return this->operator()(0x526172211A070100);
         }

         �ļ�ʶ���� &RAR4() noexcept
         {
            return this->operator()(0x526172211A0700);
         }

         �ļ�ʶ���� &ICON() noexcept
         {
            return this->operator()({ 0x00, 0x00, 0x01, 0x00 });
         }

         �ļ�ʶ���� &CURSOR() noexcept
         {
            return this->operator()({ 0x00, 0x00, 0x02, 0x00 });
         }

         private:

         �ļ���  &�����ļ�;
         �����߼� ���н�� = ��;

         �ļ�ʶ���� &operator () (����ʶ���� ʶ����, �ļ���::����ƫ�� ��ʼ�� = 0) noexcept
         {
            if (this->���н�� == ��)
            {
               this->���н�� = �ļ�ʶ�����ж�(this->�����ļ�, ʶ����, ��ʼ��);
            }
            return *this;
         }

         �ļ�ʶ���� &operator () (const ģ���б�����<�����ֽ�> &ʶ����, �ļ���::����ƫ�� ��ʼ�� = 0) noexcept
         {
            if (this->���н�� == ��)
            {
               this->���н�� = �ļ�ʶ�����ж�(this->�����ļ�, ʶ����, ��ʼ��);
            }
            return *this;
         }

         public:

         operator �����߼� () const noexcept
         {
            return this->���н��;
         }

         // ���жϵĽ������Ϊ�١�
         �ļ�ʶ���� &operator () () noexcept
         {
            this->���н�� = ��;
            return *this;
         }
      };

   }

};
