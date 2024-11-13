
#define ����У���(LinkedObj, ...)   if(LinkedObj->���д��� == ::BE::����::�����ڴ�������) { return __VA_ARGS__; }

namespace BE {

   /**
    * \brief >>> һ��ʹ��ѭ���������ɵ�˫��������������������������������˫���������ע�⣬��Ȼʹ��ѭ������ʵ�֣��������齫�䵱��ѭ������ʹ�á�
    * \brief >>> ע�⣬�������ڳ�ʼ��ʱ����һ�������ͷ�ڵ㣬�������ڵ㹹��ʧ�ܣ��������������Ե������޷�ʹ�ã������ע���������Ϣ��
    * \tparam STmpT �����нڵ���������͡�
    */
   template<�������� STmpT>
   struct ������ : ������
   {
      using ��׼�����ʶ = void;

      // �����нڵ�Ļ����ṹ���洢ǰ��ڵ��Լ�����ָ�롣
      struct ���ڵ���
      {
         STmpT    *�ڵ�����;
         ���ڵ��� *ǰ�ڵ�;
         ���ڵ��� *��ڵ�;
      };

      // ������ֻ��������������˫�����������
      struct ֻ���������� final
      {
         ֻ����������() noexcept = default;

         ֻ����������(���ڵ��� *�ڵ���) noexcept : ��ǰ�ڵ�(�ڵ���) 
         {
         
         }

         const STmpT &operator * () noexcept
         {
            return *this->��ǰ�ڵ�->�ڵ�����;
         }

         const STmpT *operator -> () noexcept
         {
            return this->��ǰ�ڵ�->�ڵ�����;
         }

         ֻ���������� &operator ++ () noexcept
         {
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->��ڵ�;
            return *this;
         }

         ֻ���������� operator ++ (int) noexcept
         {
            ֻ���������� ��ʱ = *this;
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->��ڵ�;
            return ��ʱ;
         }

         ֻ���������� &operator -- () noexcept
         {
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->ǰ�ڵ�;
            return *this;
         }

         ֻ���������� operator -- (int) noexcept
         {
            ֻ���������� ��ʱ = *this;
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->ǰ�ڵ�;
            return ��ʱ;
         }

         �����߼� operator == (const ֻ���������� &�Ƚ���) const noexcept
         {
            return this->��ǰ�ڵ� == �Ƚ���.��ǰ�ڵ�;
         }

         // ��ȡ�洢�Ľڵ�ָ�룬���Ҫ��ȡ�ڵ㣬���޸Ľڵ��е����ݣ���������Ҫ��ʲô��
         ���ڵ��� *��ȡ�ڵ�() noexcept
         {
            return this->��ǰ�ڵ�;
         }

         private:
         ���ڵ��� *��ǰ�ڵ�;
      };

      // �����Ŀ�д������������˫�����������
      struct ��д�������� final
      {
         ��д��������() noexcept = default;

         ��д��������(���ڵ��� *�ڵ���) noexcept : ��ǰ�ڵ�(�ڵ���) 
         {
         
         }

         STmpT &operator * () noexcept
         {
            return *this->��ǰ�ڵ�->�ڵ�����;
         }

         STmpT *operator -> () noexcept
         {
            return this->��ǰ�ڵ�->�ڵ�����;
         }

         ��д�������� &operator ++ () noexcept
         {
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->��ڵ�;
            return *this;
         }

         ��д�������� operator ++ (int) noexcept
         {
            ��д�������� ��ʱ = *this;
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->��ڵ�;
            return ��ʱ;
         }

         ��д�������� &operator -- () noexcept
         {
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->ǰ�ڵ�;
            return *this;
         }

         ��д�������� operator -- (int) noexcept
         {
            ��д�������� ��ʱ = *this;
            this->��ǰ�ڵ� = this->��ǰ�ڵ�->ǰ�ڵ�;
            return ��ʱ;
         }

         �����߼� operator == (const ��д�������� &�Ƚ���) const noexcept
         {
            return this->��ǰ�ڵ� == �Ƚ���.��ǰ�ڵ�;
         }

         // ������ʽת��Ϊ�ɶ����������ͣ���Ϊ������ش�������ֻ����ֻ����������
         operator ֻ����������() noexcept
         {
            return ֻ����������(this->��ǰ�ڵ�);
         }

         // ��ȡ�洢�Ľڵ�ָ�룬���Ҫ��ȡ�ڵ㣬���޸Ľڵ��е����ݣ���������Ҫ��ʲô��
         ���ڵ��� *��ȡ�ڵ�() noexcept
         {
            return this->��ǰ�ڵ�;
         }

         private:
         ���ڵ��� *��ǰ�ڵ�;
      };

      // ʹ������ר����������ע����Ȼ�ײ����ѭ��������������ѭ��������
      ��д�������� begin() noexcept { return ��д��������(this->���б�ͷ->��ڵ�); }
      ��д�������� end()   noexcept { return ��д��������(this->���б�ͷ); }
      // ʹ������ר����������ע����Ȼ�ײ����ѭ��������������ѭ��������
      ֻ���������� begin() const noexcept { return ֻ����������(this->���б�ͷ->��ڵ�); }
      ֻ���������� end()   const noexcept { return ֻ����������(this->���б�ͷ); }

      // Ĭ�Ϲ��캯����
      ������() noexcept
      {
         this->��ʼ������();
      }

      // ���ƹ��캯����
      ������(const ������ &������) noexcept : ������()
      {
         this->��ֵ(������);
      }

      // �ƶ����캯����
      ������(������ &&��ֵ��) noexcept
      {
         // Ŀ������û�г�ʼ���ɹ���ֵʧ�ܣ���ô����Ҫ���г�ʼ����������Ҫ��ʼ����
         if (��ֵ��.���д��� == ::BE::����::�����ڴ�������)
         {
            this->��ʼ������();
            return;
         }

         this->���б�ͷ = ::BE::������ֵ(��ֵ��.���б�ͷ, ��ָ��);
         this->���г��� = ::BE::������ֵ(��ֵ��.���г���, 0);
         this->���д��� = ::BE::������ֵ(��ֵ��.���д���, ::BE::�޴���);
         
         ��ֵ��.��ʼ������();
      }

      // �õ�����Χ�е�Ԫ�س�ʼ������������Ԫ��Ҫ�ܱ� STmpT ���졣
      template<����������� InputT, typename IDRT = ģ���������<InputT>>
      ������(InputT ��ʼ��, InputT ������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, IDRT>))
      requires(�ɸ�ֵ��������<STmpT, IDRT>) : ������()
      {
         this->��ֵ(��ʼ��, ������);
      }

      // ���б����е�Ԫ�س�ʼ���������б���Ԫ��Ҫ�ܱ� STmpT ���졣
      template<typename TmpT>
      ������(const ģ���б�����<TmpT> &�б���)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, TmpT>))
      requires(�ɸ�ֵ��������<STmpT, TmpT>) : ������()
      {
         this->��ֵ(�б���);
      }

      // �ÿɵ��������еĵ�����Χ��Ԫ�س�ʼ������������Ԫ��Ҫ�ܱ� STmpT ���졣
      template<�������� TmpT, typename IDRT = ģ���������<ģ���������<TmpT>>>
      ������(TmpT &&������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, IDRT>))
      requires(�ɸ�ֵ��������<STmpT, IDRT>) : ������()
      {
         this->��ֵ(std::forward<TmpT>(������));
      }

      // ��ʼ��ָ�����ȵ�������ÿ���ڵ㶼ʹ�� ��������� �еĲ������й��졣
      template<typename... TmpArgs>
      ������(���ͳ��� ������, TmpArgs&&... ���������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, TmpArgs...>))
      requires(�ɸ�ֵ��������<STmpT, TmpArgs...>) : ������()
      {
         this->��ֵ(������, ���������...);
      }

      // ��ʼ��ָ�����ȵ�������ÿ���ڵ㶼ʹ�� ������ ����ֵ���й��졣
      template<��������<> TmpCall, typename TmpRet = ģ�巵������<TmpCall>>
      ������(���ͳ��� ������, TmpCall &&������)
      noexcept(noexcept(��ȫ��������<TmpCall> && �ɰ�ȫ��ֵ��������<STmpT, TmpRet>))
      requires(�ɸ�ֵ��������<STmpT, TmpRet>) : ������()
      {
         this->��ֵ(������, std::forward<TmpCall>(������));
      }

      /**
       * \brief >>> �Ե�����Χ�е�Ԫ�� ��ֵ/���� ��������
       * 
       * \param ��ʼ� ������Χ��ʼ��
       * \param ����� ������Χ������
       * \return this &
       * \tparam InputT�� �������㵥�����������Ŀɶ����������ͣ������������Ҫ�ܱ� STmpT ��ֵ/���졣
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      template<����������� InputT, typename IDRT = ģ���������<InputT>>
      ������ &��ֵ(InputT ��ʼ��, InputT ������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, IDRT>))
      requires(�ɸ�ֵ��������<STmpT, IDRT>)
      {
         ����У���(this, *this);

         ���ڵ��� *��ǰ�ڵ� = this->���б�ͷ->��ڵ�;
         ���ڵ��� *�½ڵ�ͷ = ��ָ��;
         ���ڵ��� *�½ڵ�β = ��ָ��;
         ���ͳ���  �±����� = 0;

         this->���г��� = 0;

         for (; ��ʼ�� != ������; ++��ʼ��)
         {
            // �������еĽڵ㣬ִ�и�ֵ���ع����������ʡȥ�����½ڵ�Ĺ��̡�
            if (��ǰ�ڵ� != this->���б�ͷ)
            {
               ::BE::ѡ��ֵ(*��ǰ�ڵ�->�ڵ�����, 0, 1, *��ʼ��);
               
               ��ǰ�ڵ� = ��ǰ�ڵ�->��ڵ�;
               
               this->���г��� += 1;
            }
            // ����ڵ㲻�㣬�򴴽�һ��˫��������
            else
            {
               ���ڵ��� *�½ڵ� = �����ڵ�(*��ʼ��);

               if (�½ڵ� == ��ָ��)
               {
                  this->���д��� = ::BE::����::�ڴ�������;
                  this->�ͷ�����ڵ�(�½ڵ�ͷ, �½ڵ�β);
                  return *this;
               }

               if (�½ڵ�ͷ == ��ָ��)
               {
                  �½ڵ�ͷ = �½ڵ�;
                  �½ڵ�β = �½ڵ�;
               }
               else
               {
                  �½ڵ�β->��ڵ� = �½ڵ�;
                  �½ڵ�β->��ڵ�->ǰ�ڵ� = �½ڵ�β;
                  �½ڵ�β = �½ڵ�β->��ڵ�;
               }

               �±����� += 1;
            }
         }

         // �±����Ȳ�Ϊ 0 ��ʾ��ǰ�ڵ㲻������Ҫ�����µĽڵ㣬��˽�˫�������еĽڵ���롣
         if (�±����� != 0)
         {
            this->����ڵ�(��ǰ�ڵ�, �½ڵ�ͷ, �½ڵ�β, �±�����);
         }
         // �����ǰ�ڵ㲻��ͷ�ڵ�������ж���Ľڵ㣬��Ҫɾ����
         else if (��ǰ�ڵ� != this->���б�ͷ)
         {
            this->ɾ���ڵ�(��ǰ�ڵ�, this->���б�ͷ);
         }
         // ����ڵ������ոպã�����Ҫ�κβ����ɾ����

         return *this;
      }

      /**
       * \brief >>> ��ָ���ɵ��������еĵ�����Χ��Ԫ�� ��ֵ/���� �������С�
       * 
       * \param ����� �ɵ�������
       * \return this &
       * \tparam TmpT�� �ɵ������ͣ������Ԫ��Ҫ�ܱ� STmpT ��ֵ/���졣
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      template<�������� TmpT, typename IDRT = ģ���������<ģ���������<TmpT>>>
      ������ &��ֵ(TmpT &&������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, IDRT>))
      requires(�ɸ�ֵ��������<STmpT, IDRT>)
      {
         return this->��ֵ(::BE::��ʼ(������), ::BE::����(������));
      }

      /**
       * \brief >>> ���б����е�Ԫ�� ��ֵ/���� �������С�
       * 
       * \param �б�� Ҫ��ֵ���б�
       * \return this &
       * \tparam TmpT�� �б������ͣ���Ԫ��Ҫ�ܱ� STmpT ��ֵ/���졣
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      template<typename TmpT>
      ������ &��ֵ(const ģ���б�����<TmpT> &�б���)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, TmpT>))
      requires(�ɸ�ֵ��������<STmpT, TmpT>)
      {
         return this->��ֵ(�б���.begin(), �б���.end());
      }

      /**
       * \brief >>> �������� ��ֵ/���� ָ�������Ľڵ㣬ÿ���ڵ㶼ʹ�� ��������� �еĲ������� ��ֵ/���졣
       * 
       * \param ����� Ҫ�����Ľڵ�������
       * \param ����������� ÿ���ڵ�Ĺ����������
       * \return this &
       * \tparam TmpArgs�� Ҫ������Ĳ����ܹ��� STmpT ��ֵ/���죬���Ҳ����û�в�������ʾĬ�Ϲ��졣
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      template<typename... TmpArgs>
      ������ &��ֵ(���ͳ��� ������, TmpArgs&&... ���������)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, TmpArgs...>))
      requires(�ɸ�ֵ��������<STmpT, TmpArgs...>)
      {
         ����У���(this, *this);

         ���ڵ��� *��ǰ�ڵ� = this->���б�ͷ->��ڵ�;
         ���ڵ��� *�½ڵ�ͷ = ��ָ��;
         ���ڵ��� *�½ڵ�β = ��ָ��;
         ���ͳ���  �±����� = 0;

         this->���г��� = 0;

         // �������еĽڵ㣬ִ�и�ֵ���ع����������ʡȥ�����½ڵ�Ĺ��̡�
         if (������ != 0)
         {
            for (���ͳ��� ���� = 0; ���� != ������; ++����)
            {
               // �������еĽڵ㣬ִ�и�ֵ���ع����������ʡȥ�����½ڵ�Ĺ��̡�
               if (��ǰ�ڵ� != this->���б�ͷ)
               {
                  ::BE::ѡ��ֵ(*��ǰ�ڵ�->�ڵ�����, 0, 1, ���������...);

                  ��ǰ�ڵ� = ��ǰ�ڵ�->��ڵ�;

                  this->���г��� += 1;
               }
               // ����ڵ㲻�㣬�򴴽�һ��˫��������
               else
               {
                  ���ڵ��� *�½ڵ� = �����ڵ�(���������...);

                  if (�½ڵ� == ��ָ��)
                  {
                     this->���д��� = ::BE::����::�ڴ�������;
                     this->�ͷ�����ڵ�(�½ڵ�ͷ, �½ڵ�β);
                     return *this;
                  }

                  if (�½ڵ�ͷ == ��ָ��)
                  {
                     �½ڵ�ͷ = �½ڵ�;
                     �½ڵ�β = �½ڵ�;
                  }
                  else
                  {
                     �½ڵ�β->��ڵ� = �½ڵ�;
                     �½ڵ�β->��ڵ�->ǰ�ڵ� = �½ڵ�β;
                     �½ڵ�β = �½ڵ�β->��ڵ�;
                  }

                  �±����� += 1;
               }
            }
         }

         // �±����Ȳ�Ϊ 0 ��ʾ��ǰ�ڵ㲻������Ҫ�����µĽڵ㣬��˽�˫�������еĽڵ���롣
         if (�±����� != 0)
         {
            this->����ڵ�(��ǰ�ڵ�, �½ڵ�ͷ, �½ڵ�β, �±�����);
         }
         // �����ǰ�ڵ㲻��ͷ�ڵ�������ж���Ľڵ㣬��Ҫɾ����
         else if (��ǰ�ڵ� != this->���б�ͷ)
         {
            this->ɾ���ڵ�(��ǰ�ڵ�, this->���б�ͷ);
         }
         // ����ڵ������ոպã�����Ҫ�κβ����ɾ����

         return *this;
      }

      /**
       * \brief >>> �������� ��ֵ/���� ָ�������Ľڵ㣬ÿ���ڵ㶼ʹ�� ������ �ķ���ֵ���� ��ֵ/���졣
       * 
       * \param ����� Ҫ�����Ľڵ�������
       * \param ����� �ɵ��ö���
       * \return this &
       * \tparam TmpCall�� �ɵ������ͣ��䷵��ֵҪ�ܱ� STmpT ��ֵ/���졣
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      template<��������<> TmpCall, typename TmpRet = ģ�巵������<TmpCall>>
      ������ &��ֵ(���ͳ��� ������, TmpCall &&������)
      noexcept(noexcept(��ȫ��������<TmpCall> && �ɰ�ȫ��ֵ��������<STmpT, TmpRet>))
      requires(�ɸ�ֵ��������<STmpT, TmpRet>)
      {
         ����У���(this, *this);

         ���ڵ��� *��ǰ�ڵ� = this->���б�ͷ->��ڵ�;
         ���ڵ��� *�½ڵ�ͷ = ��ָ��;
         ���ڵ��� *�½ڵ�β = ��ָ��;
         ���ͳ���  �±����� = 0;

         this->���г��� = 0;

         // �������еĽڵ㣬ִ�и�ֵ���ع����������ʡȥ�����½ڵ�Ĺ��̡�
         if (������ != 0)
         {
            for (���ͳ��� ���� = 0; ���� != ������; ++����)
            {
               // �������еĽڵ㣬ִ�и�ֵ���ع����������ʡȥ�����½ڵ�Ĺ��̡�
               if (��ǰ�ڵ� != this->���б�ͷ)
               {
                  ::BE::ѡ��ֵ(*��ǰ�ڵ�->�ڵ�����, 0, 1, ������());

                  ��ǰ�ڵ� = ��ǰ�ڵ�->��ڵ�;

                  this->���г��� += 1;
               }
               // ����ڵ㲻�㣬�򴴽�һ��˫��������
               else
               {
                  ���ڵ��� *�½ڵ� = �����ڵ�(������());

                  if (�½ڵ� == ��ָ��)
                  {
                     this->���д��� = ::BE::����::�ڴ�������;
                     this->�ͷ�����ڵ�(�½ڵ�ͷ, �½ڵ�β);
                     return *this;
                  }

                  if (�½ڵ�ͷ == ��ָ��)
                  {
                     �½ڵ�ͷ = �½ڵ�;
                     �½ڵ�β = �½ڵ�;
                  }
                  else
                  {
                     �½ڵ�β->��ڵ� = �½ڵ�;
                     �½ڵ�β->��ڵ�->ǰ�ڵ� = �½ڵ�β;
                     �½ڵ�β = �½ڵ�β->��ڵ�;
                  }

                  �±����� += 1;
               }
            }
         }

         // �±����Ȳ�Ϊ 0 ��ʾ��ǰ�ڵ㲻������Ҫ�����µĽڵ㣬��˽�˫�������еĽڵ���롣
         if (�±����� != 0)
         {
            this->����ڵ�(��ǰ�ڵ�, �½ڵ�ͷ, �½ڵ�β, �±�����);
         }
         // �����ǰ�ڵ㲻��ͷ�ڵ�������ж���Ľڵ㣬��Ҫɾ����
         else if (��ǰ�ڵ� != this->���б�ͷ)
         {
            this->ɾ���ڵ�(��ǰ�ڵ�, this->���б�ͷ);
         }
         // ����ڵ������ոպã�����Ҫ�κβ����ɾ����

         return *this;
      }

      /**
       * \brief >>> ��ȡĿ����������������Դ����Ȩ�����³�ʼ��Ŀ��������
       * 
       * \param ��ֵ� Ҫ�ƶ���������
       * \return this &
       * \note �������Ŀ�������Ƿ��ʼ��ʧ�ܡ�
       */
      ������ &��ֵ(������ &&��ֵ��) noexcept
      {
         ����У���((&��ֵ��), *this);

         // �ͷ�ԭ�������е���Դ��
         this->�ͷ�();
         ::BE::�ͷ�ԭʼ�ڴ�(this->���б�ͷ);

         this->���б�ͷ = ::BE::������ֵ(��ֵ��.���б�ͷ, ��ָ��);
         this->���г��� = ::BE::������ֵ(��ֵ��.���г���, 0);
         this->���д��� = ::BE::������ֵ(��ֵ��.���д���, ::BE::�޴���);

         // ��Ҫ���³�ʼ�����������¹�����ͷ��
         ��ֵ��.��ʼ������();
         return *this;
      }

      /**
       * \brief >>> �������������е���Դ��
       * 
       * \param ����� Ҫ������Ŀ�ꡣ
       * \return this &
       * \note ������鵱ǰ������Ŀ�������Ƿ��ʼ��ʧ�ܡ�
       */
      ������ &����(������ &������) noexcept
      {
         ����У���(this, *this);
         ����У���((&������), *this);

         ::BE::����(this->���б�ͷ, ������.���б�ͷ);
         ::BE::����(this->���г���, ������.���г���);
         ::BE::����(this->���д���, ������.���д���);

         return *this;
      }

      /**
       * \brief >>> ��������ָ������������ʾ��λ��֮ǰ����һ���½ڵ㣬�ڵ�ʹ�ò�������� ��ֵ/���졣
       * 
       * \param ����� Ҫ������
       * \param λ��� Ҫ�����λ�ã�Ĭ��Ϊ����ĩβ��
       * \return ������
       * \tparam TmpT�� Ҫ����������ͣ�Ҫ�ܱ� STmpT ��ֵ/���졣
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      template<typename TmpT>
      ��д�������� ����(TmpT &&������, ֻ���������� λ���� = ֻ����������())
      noexcept(noexcept(��ȫ��������<STmpT, TmpT>))
      requires(��������<STmpT, TmpT>)
      {
         ����У���(this, λ����.��ȡ�ڵ�());
         
         λ���� = λ����.��ȡ�ڵ�() == ��ָ�� ? this->end() : λ����;

         ���ڵ��� *�½ڵ� = �����ڵ�(std::forward<TmpT>(������));

         if (�½ڵ� == ��ָ��)
         {
            this->���д��� = ::BE::����::�ڴ�������;
            return λ����.��ȡ�ڵ�();
         }

         return this->����ڵ�(λ����.��ȡ�ڵ�(), �½ڵ�, �½ڵ�, 1);
      }

      /**
       * \brief >>> ɾ��������ָ����������ʾ�ķ�Χ�еĽڵ㣬������������
       * 
       * \param ��ʼ� ��ʼɾ����λ�á�
       * \param ����� ����ɾ����λ�ã�Ĭ�Ͼ�ɾ����ʼ�
       * \return �������ɾ����Χ��ĩβ��
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      ��д�������� ɾ��(ֻ���������� ��ʼ��, ֻ���������� ������ = ֻ����������()) noexcept
      {
         ����У���(this, ��ʼ��.��ȡ�ڵ�());

         ������ = ������.��ȡ�ڵ�() == ��ָ�� ? ++ֻ����������(��ʼ��.��ȡ�ڵ�()) : ������;

         return this->ɾ���ڵ�(��ʼ��.��ȡ�ڵ�(), ������.��ȡ�ڵ�());
      }

      /**
       * \brief >>> ��ȡ���������һ���ڵ���Ԫ�ص����ã�ע��Խ����ʻ���������ʡ�
       * 
       * \return Ԫ�����á�
       */
      STmpT &��ȡβֵ() noexcept
      {
         return *this->���б�ͷ->ǰ�ڵ�->�ڵ�����;
      }

      /**
       * \brief >>> ��ȡ���������һ���ڵ���Ԫ�ص�ֻ�����ã�ע��Խ����ʻ���������ʡ�
       * 
       * \return Ԫ��ֻ�����á�
       */
      const STmpT &��ȡβֵ() const noexcept
      {
         return *this->���б�ͷ->ǰ�ڵ�->�ڵ�����;
      }

      /**
       * \brief >>> ��ȡ�����нڵ��������������ͷ�ڵ㡣
       * 
       * \return �ڵ�������
       */
      ���ͳ��� ��ȡ����() const noexcept
      {
         return this->���г���;
      }

      /**
       * \brief >>> �����ж������Ƿ�Ϊ�գ����Ƿ�ֻ��ͷ�ڵ㡣
       * 
       * \return ��Ϊ���򷵻��棬���򷵻ؼ١�
       */
      �����߼� �ǿյ�() const noexcept
      {
         return this->���б�ͷ != ��ָ�� && this->���г��� != 0;
      }

      /**
       * \brief >>> �ͷ������г���ͷ�ڵ�������нڵ㡣
       * 
       * \return this &
       * \note ��������Ƿ��ʼ��ʧ�ܡ�
       */
      ������ &�ͷ�() noexcept
      {
         ����У���(this, *this);

         ���ڵ��� *��ǰ�ڵ� = this->���б�ͷ->��ڵ�;

         while (��ǰ�ڵ� != this->���б�ͷ)
         {
            ���ڵ��� *ǰ�ڵ� = ��ǰ�ڵ�;
            ��ǰ�ڵ� = ��ǰ�ڵ�->��ڵ�;

            �ͷŽڵ�(ǰ�ڵ�);
         }

         this->���г��� = 0;
         this->���б�ͷ->ǰ�ڵ� = this->���б�ͷ->��ڵ� = this->���б�ͷ;

         return *this;
      }

      ~������()
      {
         this->�ͷ�();
         ::BE::�ͷ�ԭʼ�ڴ�(this->���б�ͷ);
      }

      protected:

      // һ�����洢�κ����ݵ�����ͷ�ڵ㡣
      ���ڵ��� *���б�ͷ = ��ָ��;
      ���ͳ���  ���г��� = 0;

      // ��ʼ����ͷ��ֻ�����һ�Σ������ʼ��ʧ�����������ش���
      ���Ϳյ� ��ʼ������() noexcept
      {
         this->���б�ͷ = ::BE::����ԭʼ�ڴ�<���ڵ���>(1);

         if (this->���б�ͷ == ��ָ��)
         {
            this->���д��� = ::BE::����::�����ڴ�������;
            return;
         }

         this->���б�ͷ->ǰ�ڵ� = this->���б�ͷ->��ڵ� = this->���б�ͷ;
         this->���г��� = 0;
      }

      // �ӱ��л�ȡָ�������Ľڵ㣬�������������Χ�򷵻ؿ�ָ�롣
      ���ڵ��� *��ȡ�ڵ�(���ͳ��� ������) noexcept
      {
         ���ڵ��� *��ǰ�ڵ� = this->���б�ͷ;
         
         if (������ >= this->���г���)
         {
            return ��ָ��;
         }

         // ����������ڳ��ȵ�һ����ӱ�ͷ�����ң�������ǰ���ң������Ч�ʡ�
         if (������ >= this->���г��� / 2)
         {
            ������ = this->���г��� - ������;

            // �����ҡ�
            for (��ǰ�ڵ� = ��ǰ�ڵ�->ǰ�ڵ�; ������ != 0; --������, ��ǰ�ڵ� = ��ǰ�ڵ�->ǰ�ڵ�);
         }
         else
         {
            for (��ǰ�ڵ� = ��ǰ�ڵ�->��ڵ�; ������ != 0; --������, ��ǰ�ڵ� = ��ǰ�ڵ�->��ڵ�);
         }

         return ��ǰ�ڵ�;
      }

      // ɾ��������ָ����Χ�Ľڵ㣬�����������ڵ㣬����ָ�����һ���ڵ��ָ�롣
      ���ڵ��� *ɾ���ڵ�(���ڵ��� *��ʼ��, ���ڵ��� *������) noexcept
      {
         if (��ʼ�� != ������)
         {
            ��ʼ��->ǰ�ڵ�->��ڵ� = ������;
            ������->ǰ�ڵ� = ��ʼ��->ǰ�ڵ�;

            while (��ʼ�� != ������)
            {
               // ��ͼɾ����ͷ�ڵ㲻��������
               assert(��ʼ�� != this->���б�ͷ);
               
               ���ڵ��� *ǰ�ڵ� = ��ʼ��;
               ��ʼ�� = ��ʼ��->��ڵ�;

               �ͷŽڵ�(ǰ�ڵ�);
               this->���г��� -= 1;
            }
            
         }

         return ������;
      }

      // ��ָ����Χ�Ľڵ���뵽ָ��λ��֮����������������������Զ����㳤���
      ���ڵ��� *����ڵ�(���ڵ��� *λ����, ���ڵ��� *��ʼ��, ���ڵ��� *������, ���ͳ��� ������ = ��ĩβ) noexcept
      {
         //          |top|
         //
         //   |1| <-> |2| <-> |3|
         ��ʼ��->ǰ�ڵ� = λ����->ǰ�ڵ�;
         ������->��ڵ� = λ����;
         λ����->ǰ�ڵ�->��ڵ� = ��ʼ��;
         λ����->ǰ�ڵ� = ������;
 
         if (������ == ��ĩβ)
         {
            // Ҫ����ķ�Χ������Ϊ�գ���˵���ʼ����ڽ�����ʱҲ��һ����
            this->���г��� += 1;

            while (��ʼ�� != ������)
            {
               ��ʼ�� = ��ʼ��->��ڵ�;
               this->���г��� += 1;
            }
         }
         else
         {
            this->���г��� += ������;
         }

         return λ����;
      }

      // �����ڵ㣬����ڵ����ݲ����䷵�ء�
      template<typename... TmpArgs>
      static ���ڵ��� *�����ڵ�(TmpArgs&&... ���������) noexcept(noexcept(��ȫ��������<STmpT, TmpArgs...>))
      {
         ���ڵ��� *����ֵ = ::BE::����ԭʼ�ڴ�<���ڵ���>(1);

         if (����ֵ != ��ָ��)
         {
            ����ֵ->�ڵ����� = ::BE::����ԭʼ�ڴ�<STmpT>(1);

            if (����ֵ->�ڵ����� != ��ָ��)
            {
               ::BE::ֱ�ӹ���(����ֵ->�ڵ�����, 1, std::forward<TmpArgs>(���������)...);
               ����ֵ->ǰ�ڵ� = ����ֵ->��ڵ� = ��ָ��;
            }
            else
            {
               ::BE::�ͷ�ԭʼ�ڴ�(����ֵ);
               ����ֵ = ��ָ��;
            }
         }

         return ����ֵ;
      }

      // �ͷŽڵ㣬�����ڵ����ݣ�ʼ����Ϊ�ڵ���ǿ�ʱ����ڵ�����Ҳ�ǿա�
      static ���Ϳյ� �ͷŽڵ�(���ڵ��� *�ڵ���) noexcept
      {
         if (�ڵ��� != ��ָ��)
         {
            ::BE::ֱ������(�ڵ���->�ڵ�����, 1);
            ::BE::�ͷ�ԭʼ�ڴ�(�ڵ���->�ڵ�����);
            ::BE::�ͷ�ԭʼ�ڴ�(�ڵ���);
         }
      }

      static ���Ϳյ� �ͷ�����ڵ�(���ڵ��� *��ʼ��, ���ڵ��� *������) noexcept
      {
         while (��ʼ�� != ��ָ��)
         {
            ���ڵ��� *ǰ�ڵ� = ��ʼ��;
            ��ʼ�� = ��ʼ��->��ڵ�;

            �ͷŽڵ�(ǰ�ڵ�);
         }
      }

      public:

      // ʹ�ÿɵ��������еĵ�����ΧԪ�ؽ��и�ֵ��
      template<�������� TmpT>
      ������ &operator = (TmpT &&��ֵ��)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, TmpT>))
      requires(�ɸ�ֵ��������<STmpT, TmpT>)
      {
         return this->��ֵ(std::forward<TmpT>(��ֵ��));
      }

      // ʹ��Ŀ���б��е�Ԫ�ظ�ֵ������
      template<typename TmpT>
      ������ &operator = (const ģ���б�����<TmpT> &��ֵ��)
      noexcept(noexcept(�ɰ�ȫ��ֵ��������<STmpT, TmpT>))
      requires(�ɸ�ֵ��������<STmpT, TmpT>)
      {
         return this->��ֵ(��ֵ��);
      }

      // ��ȡĿ����������Դ������Ȩ�����³�ʼ��Ŀ�ꡣ
      ������ &operator = (������ &&��ֵ��) noexcept
      {
         return this->��ֵ(std::move(��ֵ��));
      }

      // ���޵��������֧�֣��������飬��Ϊ����������Ч�ʹ��ͣ�ע��Խ����ʡ�
      STmpT &operator [] (���ͳ��� ������) noexcept
      {
         return *this->��ȡ�ڵ�(������)->�ڵ�����;
      }

      // ���޵��������֧�֣��������飬��Ϊ����������Ч�ʹ��ͣ�ע��Խ����ʡ�
      const STmpT &operator[] (���ͳ��� ������) const noexcept
      {
         return ::BE::ȥ��ֻ��(*this)[������];
      }

   };

}

#undef ����У���