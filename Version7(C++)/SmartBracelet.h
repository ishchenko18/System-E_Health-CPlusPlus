#if !defined(__E_Mediciana_SmartBracelet_h)
#define __E_Mediciana_SmartBracelet_h

/*!
\brief ���� ������� �� ������ ������ �����
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class SmartBracelet//��������� �����
{
public:
	/*!
	\param pulse - ��������� ������� ������ 
	\param pressure - ��������� ������� �����
	*/
   void TakeTests(short pulse,short pressure);///<����� ������� �� ������ ������

   /*!
   \return ��������� ������� �����
   */
   short GetPulse();///<����� ������� ������ �����������

   /*!
   \return ��������� ������� �����
   */
   short GetPressure();///<����� ������� ����� �����������
   
   SmartBracelet& operator ++();///<�������������� �������� ��������� ������������ ����������

   SmartBracelet operator ++(int);///<�������������� �������� ��������� ����������� ����������

   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   SmartBracelet();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param _pulse ������ �����
   \param _pressure ������ ����
   */
   SmartBracelet(short _pulse, short _pressure);///<����������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~SmartBracelet();///<����������

protected:
private:
   short pulse;///<������ �����
   short pressure;///<������ ����

};

#endif