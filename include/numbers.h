
namespace BE {

   namespace ��ѧ�� {

      // Բ���� �� ��ֵ��
      template<��׼�������� TmpNum = ���͸���<>>
      inline constexpr const TmpNum Բ���� = std::numbers::pi_v<T>;

      // ��Ȼ���� e ��ֵ��
      template<��׼�������� TmpNum = ���͸���<>>
      inline constexpr const TmpNum ��Ȼ���� = std::numbers::e_v<T>;

      // ٤���� �� ��ֵ��
      template<��׼�������� TmpNum = ���͸���<>>
      inline constexpr const TmpNum ٤���� = std::numbers::egamma_v<T>;

      // �ƽ�ָ��� �� ��ֵ��
      template<��׼�������� TmpNum = ���͸���<>>
      inline constexpr const TmpNum �ƽ�ָ��� = std::numbers::phi_v<T>;

      // ���� TmpV �� TmpIndex �η�ֵ��TmpIndex ֻ�����޷����������͡�
      template<��׼�������� auto TmpV, �����޷�<> TmpIndex, ��׼�������� TmpNum = decltype(TmpV)>
      inline constexpr const TmpNum ������ = ������<TmpV, TmpIndex - 1, TmpNum> * TmpV;

      // ���� TmpV �� TmpIndex �η�ֵ��TmpIndex ֻ�����޷����������͡�
      template<��׼�������� auto TmpV, ��׼�������� TmpNum>
      inline constexpr const TmpNum ������<TmpV, 0, TmpNum> = 1;

   }

}
