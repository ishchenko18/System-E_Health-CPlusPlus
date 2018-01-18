#if !defined(__E_Mediciana_Clinic_h)
#define __E_Mediciana_Clinic_h
#include <string>//���������� ������������� ����� ��� ������ � ������ string
#include <vector>//���������� ������������� ����� ��� ������ � ������ vector

using namespace std;

class Doctor;//���������� �����

/*!
\brief ���� ����� ����� � ��� ����������� ����������
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class Clinic//��������� �����
{
public:
   void SetListOfDoctor();///<����� ��� ������ ����� �����(��*���� ������� �� ��*� �����, � ���� ������ �� ������ �����
   void GetListOfDoctor();///<����� ��� ������ ����� �����
   
   /*!
   \return ����� �����
   \param ��� ���������
   */
   static const string GetName()///<�������� �� ���������� ������� ��� ��������� ����� �����
   {
	   return name;
   }
   
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   Clinic();///<����������� �� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~Clinic();///<����������
  
   vector<Doctor> doctor;///<������ ��'����

private:
   static const string name;///<����� �����
   vector <string> listOfDoctors;///<������ ����� �����
};

#endif