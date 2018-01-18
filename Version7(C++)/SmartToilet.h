

#if !defined(__E_Mediciana_SmartToilet_h)
#define __E_Mediciana_SmartToilet_h

/*!
\brief ���� ������� �� ������ �������� �������� ������
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class SmartToilet
{
public:
	/*!
	\param urinal - ��������� ���������� ������ ����
	\param caplograme - ��������� ����������
	*/
   void TakeTests(float urinal,float caplograme);///<����� ������� �� ������ ������

   /*!
   \param urinal - ��������� ���������� ������ ����
   \param caplograme - ��������� ����������
   */
   void TakeTests(short caplograme);///<�������������� ����� TakeTests

   /*!
   \return ��������� ���������� ������ ����
   */
   float GetUrinalysis();///<����� ��� ��� �����������

   /*!
   \return ��������� ������������
   */
   float GetCaplogramme();///<����� ��� ����������� �����������
   
   SmartToilet operator +(int  i);///<�������������� �������� ��������� 
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   SmartToilet();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param urin ��������� ������ ����
   \param caplo ��������� ����������
   */
   SmartToilet(float urin, float caplo);///<����������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~SmartToilet();///<����������

protected:
private:
   float urinalysis;///<��������� ������ ����
   float caplogramme;///<��������� ������ ����������
};

#endif