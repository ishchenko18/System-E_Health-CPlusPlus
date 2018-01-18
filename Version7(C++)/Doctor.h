#if !defined(__E_Mediciana_Doctor_h) DOCTOR_H
#define __E_Mediciana_Doctor_h DOCTOR_H
#include <string>
#include <vector>
#include <iostream>
#include "Person.h"

using namespace std;

/*!
\brief ���� ������� �� ���������� ������ ����������� �� ������������ �������.
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class Doctor : public Person
{
public:
   string MakeAppointment(void);///<����� ������� �� ����������� ����������� �������� ������ 
   string Examination(void);///<����� ������� �� ���������� ��������� ������ �����������
   /*!
   \param special ������������ �������� �����
   */
   void SetSpecialization(string special);///<����� ��� ������������ ������������ �������� �����
   /*!
   \param qualific ����� ����������� �������� �����
   */
   void SetQualification(int qualific);///<����� ��� ������������ ���� ����������� �������� �����

   friend ostream& operator << (ostream& os, const Doctor& doc);///<�������������� �������� ���������
   friend istream& operator >> (istream& is, Doctor& doc);///<�������������� �������� ��������
   /*!
   ��������� ���� �� ������� �����
   */
   void ShowInfo() override;///<³�������� ������� ��������� ����������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   Doctor();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param fname ��*� ����������
   \param sname ������� �����������
   \param special ������������ �����
   \param  qualific ����� ����������� �����
   */
   Doctor(string fname, string sname, string special, int qualific);///<����������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~Doctor();///<����������

protected:
private:
   string specialization;///<������������ �����
   int qualification;///<г���� ����������� �����
};

#endif