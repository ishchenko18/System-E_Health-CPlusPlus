#include "Person.h"
#include <string>
#include <iostream>

Person::Person() :
firstname(""),//������������ ����
surname("")//������������ �������
{

}

Person::Person(std::string fname, std::string sname) :
firstname(fname),//������������ ����
surname(sname)//������������ �������
{
	
}void Person::ShowInfo()
{
	std::cout << "Firstname: " << firstname << "\nSurname: " << surname;
}

std::string Person::GetFirstname()//��������� ����
{
	return firstname;
}

void Person::SetFirstname(std::string fname)//������������ ����
{
	firstname = fname;
}

std::string Person::GetSurname()//��������� �������
{
	return surname;
}

void Person::SetSurname(std::string sname)//������������ �������
{
	surname = sname;
}