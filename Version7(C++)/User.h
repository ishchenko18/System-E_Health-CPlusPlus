#if !defined(__E_Mediciana_User_h) USER_H
#define __E_Mediciana_User_h USER_H

#include <string>
#include "Person.h"

using namespace std;

class Doctor;
class SystemE_Health;
class ChipForIdentification;

/*!
\brief ���� ����� ����������� �������
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class User : public Person
{
public:
   void Survey(void);///<����� ������� �� ����������� ���������� ������������
   void VisitDoctor(void);///<����� ������� �� ���������� ����� ������������
   void ShowInfo() override;///<����� �������� ������� �� ��*� �����������

   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   User();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param engraphy ��������� ������������
   \param fname ��'� �����������
   \param sname ������� �����������
   */
   User(string fname, string sname);///<����������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~User();///<����������

   ChipForIdentification* chipForIdentification;///<��������� �� ��'���
   Doctor* doctor;///<��������� �� ��'���
   SystemE_Health* systemE_Health;///<��������� �� ��'���

protected:
private:
   
};

#endif