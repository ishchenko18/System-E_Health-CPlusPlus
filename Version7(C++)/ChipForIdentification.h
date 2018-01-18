#if !defined(__E_Mediciana_ChipForIdentification_h)
#define __E_Mediciana_ChipForIdentification_h
#include <string>//���������� ������������� ����� ��� ������ � ������ string
#include <vector>//���������� ������������� ����� ��� ������ � ������ vector

using namespace std;//���������� �������� ����

/*!
\brief ���� ������� �� ������ � �����
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class ChipForIdentification//��������� �����
{
public:   
   string GetFirstname();///<����� ��� ���� �����������
   /*!
   \param fname ��*� ����������
   */
   void SetFirstname(string fname);///<����� ��� ���� �����������
   string GetSurname();///<����� ��� ������� �����������
   /*!
   \param sname ������� ����������
   */
   void SetSurname(string sname);///<����� ��� ������� �����������
   int GetBirthday();///<����� ��� ���� ���������� �����������
   /*!
   \param _birthday ���� ���������� �����������
   */
   void SetBirthday(int _birthday);///<����� ��� ���� ���������� �����������
   int GetTerm();///<����� ��� ������ 䳿 ���� �����������
   /*!
   \param _term ����� 䳿 ����
   */
   void SetTerm(int _term);///<����� ��� ������ 䳿 ���� �����������

   operator int() const//������ ������������ ����
   {
	   return birthday;
   }

   explicit operator string() const//���� ������������ ����
   {
	   return firstname;
   }

   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param ��� ���������
   */
   ChipForIdentification();///<����������� �� ������������
   /*!
   ��������� �����������, �� ����������� ���������\n
   ��������� ����������� ��������
   \param fname ��*� ����������
   \param sname ������� �����������
   \param _birthday ���� ����������
   \param  term ����� 䳿 ����
   */
   ChipForIdentification(string fname, string sname, int _birthday, int _term);///<����������� ������������
   /*!
   ��������� �����������, �� ���������� ���������
   \param ��� ���������
   */
   ~ChipForIdentification();///<����������

protected:
private:
	string firstname, ///<��*� ����������
		surname;///<������� �����������
	int birthday;///<���� ���������� 
	int term;///<����� 䳿 ����


};

#endif