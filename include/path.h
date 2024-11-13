
namespace BE {

   enum class �ļ����ö��
   {
      ���ļ� = (int)std::filesystem::file_type::none,
      ���豸 = (int)std::filesystem::file_type::block,
      �ַ��豸 = (int)std::filesystem::file_type::character,
      Ŀ¼ = (int)std::filesystem::file_type::directory,
      �ܵ� = (int)std::filesystem::file_type::fifo,
      ���� = (int)std::filesystem::file_type::regular,
      �׽��� = (int)std::filesystem::file_type::socket,
      �������� = (int)std::filesystem::file_type::symlink,
      ���� = (int)std::filesystem::file_type::unknown
   };

   /**
    * \brief >>> һ����װ std::filesystem �д�������ܵ��࣬�ṩ�������·����ϵͳ�ļ�������
    */
   struct ·����
   {
      using EGO = void;

      // �þ�̬��������ָ��·���Ƚ�ʱ���ǱȽ�·���ַ������ǱȽ�·��ָ���ϵͳ����
      static inline std::atomic_bool ·���Ƚ� = ��;

      // ��ǰϵͳ������·���ָ��ķָ�����
      static constexpr �����ַ� �ָ��� = static_cast<�����ַ�>(std::filesystem::path::preferred_separator);

      // Ĭ�Ϲ��캯����
      ·����() noexcept = default;

      // �������ַ������͸�ֵΪ·����
      ·����(�ַ������� auto &&��ֵ��) noexcept
      {
         this->����·�� = ::BE::��ȡ�ַ���(��ֵ��);
      }

      // �� std::filesystem::path ��ֵΪ·����
      ·����(const std::filesystem::path &��ֵ��) noexcept
      {
         this->����·�� = ��ֵ��;
      }

      /**
       * \brief >>> �������ַ������͵��ַ���ֵ��ֵ��·����
       * 
       * \param ��ֵ� Ҫ��ֵ�������ַ�������
       * \return this &
       */
      ·���� &��ֵ(�ַ������� auto &&��ֵ��) noexcept
      {
         this->����·�� = ::BE::��ȡ�ַ���(��ֵ��);
         return *this;
      }

      /**
       * \brief >>> �� std::filesystem::path ��ֵ��·����
       * 
       * \param ��ֵ� Ҫ��ֵ�� std::filesystem::path ����
       * \return this &
       */
      ·���� &��ֵ(const std::filesystem::path &��ֵ��) noexcept
      {
         this->����·�� = ��ֵ��;
         return *this;
      }

      /**
       * \brief >>> ��ȡ·���ĸ�·��������� "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� "C:\\Windows\\System32"��
       * 
       * \return ��·�����������򷵻ؿ�·����
       */
      ·���� ��ȡ��·��() const noexcept
      {
         return this->����·��.parent_path();
      }

      /**
       * \brief >>> ��ȡ·���еĸ���������� "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� "C:"��
       * 
       * \return �������������򷵻ؿ�·����
       */
      ·���� ��ȡ����() const noexcept
      {
         return this->����·��.root_name();
      }

      /**
       * \brief >>> ��ȡ·���еĸ�Ŀ¼������� "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� "\\"��
       * 
       * \return ��Ŀ¼���������򷵻ؿ�·����
       */
      ·���� ��ȡ��Ŀ¼() const noexcept
      {
         return this->����·��.root_directory();
      }

      /**
       * \brief >>> ��ȡ·���еĸ�·��������� "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� "C:\\"��
       * 
       * \return ��·�����������򷵻ؿ�·����
       */
      ·���� ��ȡ��·��() const noexcept
      {
         return this->����·��.root_path();
      }

      /**
       * \brief >>> ��ȡ·���е��ļ��������ƣ������ "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� "console.1"��
       * 
       * \return ���ɣ��������Ϊû�к�׺�����ļ������������򷵻ؿ�·����
       */
      ·���� ��ȡ����() const noexcept
      {
         return this->����·��.stem();
      }

      /**
       * \brief >>> ��ȡ·���е��ļ���׺��������� "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� ".exe"��
       * 
       * \return �ļ���׺�����������򷵻ؿ�·����
       */
      ·���� ��ȡ��׺() const noexcept
      {
         return this->����·��.extension();
      }

      /**
       * \brief >>> ��ȡ·���е��ļ���������� "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� "console.1.exe"��
       * 
       * \return �ļ����������ɼ��Ϻ�׺���������򷵻ؿ�·����
       */
      ·���� ��ȡ�ļ���() const noexcept
      {
         return this->����·��.filename();
      }

      /**
       * \brief >>> ��ȡ·��������ڸ�����·��������� "C:\\Windows\\System32\\console.1.exe" ·�����򷵻� "System32\\console.1.exe"��
       * 
       * \return ����ڸ�·����·�����������򷵻ؿ�·����
       */
      ·���� ��ȡ��Ը�·��() const noexcept
      {
         return this->����·��.relative_path();
      }

      /**
       * \brief >>> �����ж�·���Ƿ�Ϊ��·����
       * 
       * \return ���򷵻ؼ٣����򷵻��档
       */
      �����߼� �ǿյ�() const noexcept
      {
         return this->����·��.empty() == ��;
      }

      /**
       * \brief >>> ��ȡ���д洢��·����
       * 
       * \return std::filesystem::path ��ֻ�����á�
       */
      const std::filesystem::path &��ȡ��׼·��() const noexcept
      {
         return this->����·��;
      }

      /**
       * \brief >>> ��ȡ·���е�ԭʼ�ַ���ֵ��
       * 
       * \return �ַ���ֵ��
       */
      �ַ����� ��ȡ�ַ���() const noexcept
      {
         return this->����·��.u32string();
      }

      /**
       * \brief >>> ��ȡ��ʽ��Ϊ·����ʾ��ʽ����ַ�����
       * 
       * \return �ַ���ֵ��
       */
      �ַ����� ��ȡ·���ַ���() const noexcept
      {
         return this->����·��.generic_u32string();
      }

      /**
       * \brief >>> �����д洢���ַ���׷��һ���ַ�����
       * 
       * \param ׷��� Ҫ׷�ӵ��ַ�����
       * \return this &
       */
      ·���� &׷��(�ַ������� auto &&׷����) const noexcept
      {
         this->����·�� += ::BE::��ȡ�ַ���(׷����);
         return *this;
      }

      /**
       * \brief >>> ׷��һ���ַ�����·��ĩβ����ѡ���Ƿ���ӷָ�����
       * 
       * \param ׷��� Ҫ׷�ӵ��ַ�����
       * \return this &
       */
      ·���� &׷��Ŀ¼(�ַ������� auto &&׷����) const noexcept
      {
         this->����·�� /= ::BE::��ȡ�ַ���(׷����);
         return *this;
      }

      /**
       * \brief >>> ����ļ������ڵĻ���ɾ������
       * 
       * \return this &
       */
      ·���� &ɾ���ļ���() noexcept
      {
         this->����·��.remove_filename();
         return *this;
      }

      /**
       * \brief >>> ����ļ������ڵĻ����滻���������׷����Ϊ��ͬ��
       * 
       * \param �滻� Ҫ�滻���ַ�����
       * \return this &
       */
      ·���� &�滻�ļ���(�ַ������� auto &&�滻��) noexcept
      {
         this->����·��.replace_filename(::BE::��ȡ�ַ���(�滻��));
         return *this;
      }

      /**
       * \brief >>> �����׺�����ڵĻ����滻���������׷����Ϊ��ͬ��
       * 
       * \param �滻� Ҫ�滻���ַ�����
       * \return this &
       */
      ·���� &�滻��׺��(�ַ������� auto &&�滻��) noexcept
      {
         this->����·��.replace_extension(::BE::��ȡ�ַ���(�滻��));
         return *this;
      }

      /**
       * \brief >>> ��ȡ·����ָ���ϵͳ���ļ������
       * 
       * \return �ļ�������·���������򷵻ط��ļ���
       */
      �ļ����ö�� ��ȡ�ļ����() const noexcept
      {
         try {
            switch (std::filesystem::status(this->����·��).type())
            {
               case std::filesystem::file_type::none:
                  return �ļ����ö��::���ļ�;
               case std::filesystem::file_type::block:
                  return �ļ����ö��::���豸;
               case std::filesystem::file_type::character:
                  return �ļ����ö��::�ַ��豸;
               case std::filesystem::file_type::directory:
                  return �ļ����ö��::Ŀ¼;
               case std::filesystem::file_type::fifo:
                  return �ļ����ö��::�ܵ�;
               case std::filesystem::file_type::regular:
                  return �ļ����ö��::����;
               case std::filesystem::file_type::socket:
                  return �ļ����ö��::�׽���;
               case std::filesystem::file_type::symlink:
                  return �ļ����ö��::��������;
               case std::filesystem::file_type::unknown:
                  return �ļ����ö��::����;
            }
         } catch (...) {
            return �ļ����ö��::���ļ�;
         }
      }

      /**
       * \brief >>> ��ȡ·��ָ����ļ����ֽ�ռ�ã����·���������򷵻� 0��
       * 
       * \return ռ�ô�С��
       */
      ���ͳ��� ��ȡ�ļ���С() const noexcept
      {
         return std::filesystem::file_size(this->����·��, this->���д�����);
      }

      /**
       * \brief >>> ���ݵ�ǰ·����ʾ����Ŀ¼�����Ŀ¼�Ѿ����������κβ�����
       * 
       * \return this &
       */
      ·���� &����Ŀ¼() noexcept
      {
         std::filesystem::create_directories(this->����·��, this->���д�����);
         return *this;
      }

      /**
       * \brief >>> �����ǰ·��ָ���ϵͳĿ����ڵĻ����򴴽�һ��ָ�����Ƶ�Ӳ���ӣ�Ӳ����ָ��ǰ·��ָ���ϵͳĿ�ꡣ
       * \brief >>> ע�⣬Ӳ����ֻ����ͬ�ļ�ϵͳ�д��������ļ���ɾ����Ӱ��Ӳ���ӣ���Ϊ���ǹ���һ��洢�ռ䡣
       * 
       * \param �������� Ҫ������Ӳ���ӵ����ƺ�·����
       * \return this &
       */
      ·���� &����Ӳ����(const ·���� &������) noexcept
      {
         std::filesystem::create_hard_link(this->����·��, ������.����·��, this->���д�����);
         return *this;
      }

      /**
       * \brief >>> ����һ��ָ��ǰ·��ָ���ϵͳĿ��ķ������ӣ������ǰ·��û��ָ��ϵͳ�е��κ��ļ������򴴽������ķ�������Ϊ�����ӡ�
       * 
       * \param �������� Ҫ�����ķ������ӵ����ƺ�·����
       * \return this &
       */
      ·���� &������������(const ·���� &������) noexcept
      {
         std::filesystem::create_symlink(this->����·��, ������.����·��, this->���д�����);
         return *this;
      }

      /**
       * \brief >>> �����ǰ·��ָ��ϵͳ�е��ļ��򷵻�����ļ���Ӳ��������
       * 
       * \return Ӳ����������������򷵻� std::uintmax_t(-1)��
       */
      ���ͳ��� ��ȡӲ������() const noexcept
      {
         return std::filesystem::hard_link_count(this->����·��, this->���д�����);
      }

      /**
       * \brief >>> �����ǰ·��ָ�����һ��ϵͳ�еķ������ӣ����ȡ�����������ָ���Ŀ��·����
       * 
       * \return ���򷵻�·�������򷵻ؿ�·����
       */
      ·���� ��ȡ��������Ŀ��() const noexcept
      {
         return std::filesystem::read_symlink(this->����·��, this->���д�����);
      }

      /**
       * \brief >>> �����ж�·��ָ����Ƿ���һ�����ڵ��ļ���
       * 
       * \return ���򷵻��棬���򷵻ؼ١�
       */
      �����߼� �ļ��ж�() const noexcept
      {
         return this->��ȡ�ļ����() != �ļ����ö��::���ļ�;
      }

      /**
       * \brief >>> ɾ��·��ָ���ϵͳ�д��ڵ�Ŀ�ꡣ
       * 
       * \param �ݹ�� ���ڷǿ�Ŀ¼���Ƿ�ݹ�ɾ��Ŀ¼�е��������ݣ���������ֻ��ɾ����Ŀ¼��
       * \return this &
       */
      ·���� &ɾ��Ŀ��(�����߼� �ݹ�� = ��) noexcept
      {
         �ݹ�� ? (void)std::filesystem::remove_all(this->����·��, this->���д�����) : (void)std::filesystem::remove(this->����·��, this->���д�����);
         return *this;
      }

      /**
       * \brief >>> ����ǰ·��ָ���ϵͳ�е�Ŀ��Ǩ�Ʋ���������Ŀ��·���ϡ�
       * 
       * \param Ŀ��� Ҫ�ƶ�����Ŀ¼·����
       * \param ���·� ���Ǩ�Ƴɹ��Ƿ񽫵�ǰ·��ָ�����ΪĿ��·����
       * \return this &
       */
      ·���� Ǩ��Ŀ��(const ·���� &Ŀ����, �����߼� ���·� = ��) noexcept
      {
         std::filesystem::rename(this->����·��, Ŀ����.����·��, this->���д�����);

         if (���·� && this->���д�����)
         {
            this->����·�� = Ŀ����.����·��;
         }

         return *this;
      }

      /**
       * \brief >>> �����ǰ·�������ļ���������·��ָ����ļ����ڣ����������ļ���
       * 
       * \param ����� Ҫ���������ļ�����
       * \param ���·� ����������ɹ��Ƿ񽫵�ǰ·��ָ�����Ϊ��·����
       * \return this &
       */
      ·���� &������(�ַ������� auto &&������, �����߼� ���·� = ��) noexcept
      {
         std::filesystem::path ��·�� = this->����·��;

         ��·��.replace_filename(::BE::��ȡ�ַ���(������));

         std::filesystem::rename(this->����·��, ��·��, this->���д�����);

         if (���·� && this->���д�����)
         {
            this->����·�� = ��·��;
         }

         return *this;
      }

      /**
       * \brief >>> �����·��ָ���Ŀ¼���ڣ����������ͬʱ������ȡ�
       * 
       * \param ���յ���� �ɵ��ö���ÿ�α�����һ����Ŀ¼�ļ�ʱ���á�
       * \param �������� �ɵ��ö���ÿ�α�����һ��Ŀ¼ʱ���ã���ȻҲ������һ�ν��뺯��ʱ��
       * \param �˳������ �ɵ��ö�����ָ�룬ÿ�α�����һ��Ŀ¼ʱ���ã��������Ŀ¼ʧ��Ҳ����ã����Ϊ��ָ������������򲻵��á�
       * \param ·��� ��ʼ������·�������Ǳ�Ҫ��Ӧʹ��Ĭ��ֵ��
       * \param ���� ��ʼ��������ȣ����Ǳ�Ҫ��Ӧʹ��Ĭ��ֵ��
       * \return �������ķ�Ŀ¼�ļ�������
       * \tparam TmpReceivers�� �ɵ������ͣ�����һ���޷����������ͺ�·���ࡣ
       * \tparam TmpEnter�� �ɵ������ͣ�����һ���޷����������ͺ�·���࣬�����ṩ����ֵΪ�߼����ͣ����Ϊ�����˳���ǰĿ¼������
       * \tparam TmpQuit�� �ɵ������ͣ�Ҳ����Ϊ�������ͣ�Ϊ�ɵ�������ʱ���Ե�����һ���޷����������ͺ�·���������
       */
      template<��������<�����޷�<>, ·����> TmpReceivers, ��������<�����޷�<>, ·����> TmpEnter, typename TmpQuit = void *>
      ���ͳ��� Ŀ¼����(TmpReceivers &&���յ�����, TmpEnter &&���������, TmpQuit &&�˳������� = ��ָ��, const ·���� *·���� = ��ָ��, �����޷�<> ����� = 0) const noexcept
      {
         ���ͳ��� ͳ��ֵ = 0;

         std::filesystem::path ·��ֵ{ ·���� == ��ָ�� ? this->����·�� : *·���� };
         std::filesystem::directory_iterator Ŀ¼������{ ·��ֵ, this->���д����� };    /* �������Ŀ¼�ĵ����� */

         if (this->���д�����.value() == 0)
         {
            if constexpr (���÷�������<TmpEnter, �����߼�, �����޷�, ·����>)
            {
               if (���������(�����, ·��ֵ) == ��)
               {
                  goto GEXIT;
               }
            }
            else
            {
               ���������(�����, ·��ֵ);
            }

            for (auto &Ŀ¼Ԫ�� : Ŀ¼������)
            {
               if (Ŀ¼Ԫ��.is_directory())
               {
                  // �ݹ�����Խ���Ŀ¼��
                  ͳ��ֵ += this->Ŀ¼����(���յ�����, ���������, �˳�������, &Ŀ¼Ԫ��.path(), ����� + 1);
               }
               else
               {
                  ���յ�����(�����, Ŀ¼Ԫ��.path());
                  ͳ��ֵ += 1;
               }
            }
         }

      GEXIT:
         if constexpr (��������<TmpQuit, �����޷�<>, ·����>)
         {
            �˳�������(�����, ·��ֵ);
         }

         return ͳ��ֵ;
      }

      /**
       * \brief >>> ��ȡ�洢ϵͳ������Ϣ�Ĵ��������
       * 
       * \return std::error_code ��ֻ�����á�
       */
      const std::error_code &��ȡϵͳ������() const noexcept
      {
         return this->���д�����;
      }

      /**
       * \brief >>> �����������Ϊ 0��
       * 
       * \return this &
       */
      ·���� &���������() noexcept
      {
         this->���д�����.clear();
         return *this;
      }

      /**
       * \brief >>> ��ȡ��ǰ������Ŀ¼����ڵ�ǰ·�������·�����統ǰ����Ŀ¼Ϊ "C:\\Windows\\System32" ����ǰ·��Ϊ "C:\\Windows\\Console\\cmd.exe" �򷵻� "..\\Console\\cmd.exe"��
       * 
       * \return ���·��������޷�������·�����߲����ڵ��򷵻ؿ�·����
       */
      ·���� ��ȡ���·��() const noexcept
      {
         return std::filesystem::relative(this->����·��, this->���д�����);
      }

      /**
       * \brief >>> �����ǰ·��ָ��ϵͳ�д��ڵ��ļ������ȡ�ļ�������޸ĵ�ʱ�䣬��ȷ���롣
       * 
       * \return ���޸ĵ�ʱ�䣬ע�ⷵ�ص�ʱ����ʼ��ͱ�׼��ʼ����ܲ���ͬ��
       */
      ʱ���� ��ȡ�޸�ʱ��() const noexcept
      {
         return ʱ����(ʱ�伯::���ػ�ʱ���(std::filesystem::last_write_time(
            this->����·��, this->���д�����
         ).time_since_epoch().count() / std::filesystem::file_time_type::period::den * ʱ�伯::����ʱ), ʱ�伯::ϵͳ��ʼ��);
      }

      /**
       * \brief >>> �����������Ϊ 0��
       * 
       * \return const this &
       */
      const ·���� &���������() const noexcept
      {
         this->���д�����.clear();
         return *this;
      }

      /**
       * \brief >>> �Ƚ�����·������� `·����ͬ` ��̬����Ϊ����Ƚ����ߵ�·���ַ����������ж�����ָ���ϵͳ�ж����Ƿ���ͬ��
       * 
       * \param �Ƚ�� Ҫ�Ƚϵ�·����
       * \return ��ͬ�򷵻��棬���򷵻ؼ١�
       */
      �����߼� ����ж�(const ·���� &�Ƚ���) const noexcept
      {
         return ·����::·���Ƚ� ? (this->����·�� == �Ƚ���.����·��) : (std::filesystem::equivalent(this->����·��, �Ƚ���.����·��, this->���д�����));
      }

      /**
       * \brief >>> ���ж�·��ָ���Ŀ���Ƿ���ϵͳ�д��ڣ�Ȼ���ж����Ƿ�Ϊ���ļ����߿�Ŀ¼��
       * 
       * \return ���ļ����Ŀ¼�򷵻��棬���򷵻ؼ١�
       */
      �����߼� ���ļ��ж�() const noexcept
      {
         return std::filesystem::is_empty(this->����·��, this->���д�����);
      }

      protected:

      mutable std::error_code ���д�����;
      std::filesystem::path   ����·��;

      public:

      // ���������ַ��������е��ַ���ֵ��ֵ��·���С�
      ·���� &operator = (�ַ������� auto &&��ֵ��) noexcept
      {
         this->����·�� = ::BE::��ȡ�ַ���(��ֵ��);
         return *this;
      }

      // ���� std::filesystem::path ��ֵ��·���С�
      ·���� &operator = (const std::filesystem::path &��ֵ��) noexcept
      {
         this->����·�� = ��ֵ��;
         return *this;
      }

      // �������ַ��������е��ַ���ֵ׷�ӵ���ǰ·��ĩβ��
      ·���� &operator += (�ַ������� auto &&׷����) noexcept
      {
         this->����·�� += ::BE::��ȡ�ַ���(׷����);
         return *this;
      }

      // �������ַ��������е��ַ���ֵ׷�ӵ���ǰ·��ĩβ����ѡ���Ƿ���ӷָ�����
      ·���� &operator /= (�ַ������� auto &&׷����) noexcept
      {
         this->����·�� /= ::BE::��ȡ�ַ���(׷����);
         return *this;
      }

      // ������ʽת��Ϊ std::filesystem::path��
      operator const std::filesystem::path &() const noexcept
      {
         return this->����·��;
      }

   };

   /**
    * \brief >>> ��ȡ��ǰ������Ŀ¼�ĸ�����
    * 
    * \return ����Ŀ¼������
    */
   inline ·���� ��ȡ����Ŀ¼() noexcept
   {
      return std::filesystem::current_path();
   }

   /**
    * \brief >>> ���õ�ǰ����Ĺ���Ŀ¼��
    * 
    * \param ·��� Ҫ���õ�·����
    * \return ������Ϣ��
    */
   inline std::error_code ���ù���Ŀ¼(const ·���� &·����) noexcept
   {
      std::error_code ������;

      std::filesystem::current_path(·����.��ȡ��׼·��(), ������);

      return ������;
   }

   /**
    * \brief >>> ��ȡ��ǰϵͳ����ʱĿ¼������
    * 
    * \return ϵͳ��ʱĿ¼������
    */
   inline ·���� ��ȡ��ʱĿ¼() noexcept
   {
      return std::filesystem::temp_directory_path();
   }

   // ��·������·���ַ�������ʽתΪ�ַ�����
   template<>
   struct ת�ַ�����<·����>
   {
      �ַ����� operator () (const ·���� &·����) const noexcept
      {
         return ·����.��ȡ·���ַ���();
      }
   };

   // ���ļ����ö���е�ÿ��ö��ֵ��תΪ�ɶ����ַ�����
   template<>
   struct ת�ַ�����<�ļ����ö��>
   {
      �ַ����� operator () (const �ļ����ö�� &ö����) const noexcept
      {
         switch (ö����)
         {
            case �ļ����ö��::���豸:
               return C("[:enum ���豸 - BLOCK]");
            case �ļ����ö��::�ַ��豸:
               return C("[:enum �ַ��豸 - CHARACTER]");
            case �ļ����ö��::Ŀ¼:
               return C("[:enum Ŀ¼ - DIRECTORY]");
            case �ļ����ö��::�ܵ�:
               return C("[:enum �ܵ� - PIPE]");
            case �ļ����ö��::����:
               return C("[:enum ���� - REGULAR]");
            case �ļ����ö��::�׽���:
               return C("[:enum �׽��� - SOCKET]");
            case �ļ����ö��::��������:
               return C("[:enum �������� - SYMLINK]");
            case �ļ����ö��::����:
               return C("[:enum ���� - UNKNOWN]");
            default:
               return C("[:enum ���ļ� - NONFILE]");
         }
      }
   };

   // �� std::error_code �еĴ�����Ϣ�ַ���ת��Ϊ�ַ����ࡣ
   template<>
   struct ת�ַ�����<std::error_code>
   {
      �ַ����� operator () (const std::error_code &������) const noexcept
      {
         return ������.message();
      }
   };

}
