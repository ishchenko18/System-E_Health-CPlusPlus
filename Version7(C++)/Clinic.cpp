#include "Clinic.h"
#include "Doctor.h"
#include <iostream>

using namespace std;

const string Clinic::name = "Healthy&Happy";//ініціалізація константи

Clinic::Clinic()://конструктор за змовчуванням
doctor(1, Doctor("", "", "Therapist", 1))//створення об*єкту та запис до вектору
{
	
}

Clinic::~Clinic()//деструктор
{
	
}

void Clinic::SetListOfDoctor()
{
	string nameDoctor = doctor[0].GetFirstname() + doctor[0].GetSurname();//об*єднання прізвища та імені лікаря
	listOfDoctors.push_back(nameDoctor);
}

void Clinic::GetListOfDoctor()
{
	cout << "===========Doctors, who works in " << name << " clinic=========\n";
	copy(listOfDoctors.begin(), listOfDoctors.end(), ostream_iterator<string>(cout, " "));//виведення списку лікарів клініки
	cout << endl;
}


