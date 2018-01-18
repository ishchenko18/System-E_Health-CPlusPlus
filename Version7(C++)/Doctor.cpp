#include "Doctor.h"
#include "Person.h"
#include <iostream>
#include <ctime>

using namespace std;

Doctor::Doctor():Person("","")//конструктор за змовчуванням
{
	specialization = "";//ініціалізація спеціалізації
	qualification = 0;//ініціалізація рівня кваліфікації
}

Doctor::Doctor(string fname, string sname, string special, int qualific) : Person(fname,sname)//конструктор ініціалізації
{
	specialization = special;//ініціалізація спеціалізації
	qualification = qualific;//ініціалізація рівня кваліфікації
}

Doctor::~Doctor()//деструктор
{
	
}
void Doctor::ShowInfo()
{
	cout << "Name of your treatment doctor: " << firstname + " " + surname << endl;
}

ostream& operator<<(ostream& os, const Doctor& doc)
{
	os << doc.firstname << " "<<doc.surname;
	return os;
}

istream& operator >> (istream& is, Doctor& docs)
{
	cout << "Enter name of your treatment doctor: ";
	is >> docs.firstname;
	cout << "Enter surname of your treatment doctor: ";
	is >> docs.surname;
	return is;
}

void Doctor::SetSpecialization(string special)
{
	specialization = special;//встановлення спеціалізації лікуючого лікаря
}

void Doctor::SetQualification(int qualific)
{
	qualification = qualific;//встановлення кваліфікації лікуючого лікаря
}

string Doctor::MakeAppointment(void)
{
	string appointment;//призначення лікаря
	cout << "Enter appointment of your treatment doctor: ";
	cin >> appointment;//введення призначення
	return appointment;
}

string Doctor::Examination(void)
{
	srand(time(0));

	int choose;

	choose = rand() % 3 + 1;

	switch (choose)
	{
	case 1:
		return "Everythink is OK";
		break;
	case 2:
		return "You need in some treatment";
		break;
	case 3:
		return "You need hospital treatment";
		break;
	default:
		cout << "Something bed happend in program\n";
		return 0;
		break;
	}
}

