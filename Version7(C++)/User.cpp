#include "User.h"
#include "Doctor.h"
#include "Person.h"
#include "SystemE_Health.h"
#include "ChipForIdentification.h"
#include <string>
#include <iostream>

using namespace std;

User::User() : Person(), chipForIdentification(new ChipForIdentification)//����������� �� ������������
{

}

User::User(string fname, string sname) : Person(fname, sname), chipForIdentification(new ChipForIdentification)//����������� �����������
{

}

User::~User()//����������
{
	chipForIdentification->~ChipForIdentification();
}
void User::ShowInfo()
{
	std::cout << "\nWelcome to system " << firstname << " " << surname << endl;//��������� ���������
}

void User::Survey(void)
{
	cout << "You undergo a medical examination" << endl;
}

void User::VisitDoctor(void)
{
	cout << "You undergo medical examination in the treatment doctor" << endl;
}
