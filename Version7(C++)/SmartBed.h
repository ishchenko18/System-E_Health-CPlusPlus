
#if !defined(__E_Mediciana_SmartBed_h)
#define __E_Mediciana_SmartBed_h

/*!
\brief ���� ������� �� ������ ���������� ������ �� ��� ���
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class SmartBed
{
public:
	/*!
	\param encel - ��������� ������������� 
	\param pulse - ��������� ������ ������ 
	\param pressure - ��������� ������ �����
	*/
   void TakeTests(bool encel, short pulse, short pressure);///<����� ������� �� ������ ������

   /*!
   \return ��������� �������������
   */
   bool GetEncephalography();///<����� ��� ������������� �����������

   /*!
   \return ��������� ������ ������
   */
   short GetPulse();///<����� ��� ������ ������ �����������

   /*!
   \return ��������� ������ �����
   */
   short GetPressure();///<����� ��� ������ ����� �����������
   
   SmartBed operator =(SmartBed bed);///<�������������� ��������� ���������

   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   SmartBed();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param engraphy ��������� ������������
   \param _pulse ����� �����
   \param _pressure ����� ����
   */
   SmartBed(bool engraphy, short _pulse, short _pressure);///<����������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~SmartBed();///<����������

protected:
private:
	/*!
	\param encel - ��������� ������������� pulse - ��������� ������ ������ pressure - ��������� ������ �����
	*/
   bool encephalography;///<��������� �����������
   short pulse;///<ͳ���� �����
   short pressure;///<ͳ���� ����


};

#endif