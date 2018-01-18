#ifndef PERSON_H
#define PERSON_H
#include <string>

/*!
\brief ����, �� ��������������� ��� �����������
\author Ishchenko Vladyslav
\version 7
\date 8 ������ 2017
*/
class Person
{
	public:
		Person();///<����������� �� ������������
		Person(std::string fname, std::string sname);///<����������� �����������
		/*!
		������� ��� ��������� ���� �� ������� ������
		*/
		virtual void ShowInfo();
		/*!
		\return ��*� ������
		*/
		std::string GetFirstname();///<����� ��� ��������� ���� ������
		/*!
		\param fname ��*� ������
		*/
		void SetFirstname(std::string fname);///<����� ��� ������������ ���� ������
		/*!
		\return ������� ������
		*/
		std::string GetSurname();///<����� ��� ��������� ������� ������
		/*!
		\param sname ������� ������
		*/
		void SetSurname(std::string fname);///<����� ��� ������������ ������� ������
protected:
		std::string firstname,///<��'� ������
			surname;///<������� ������
	private:

};
#endif