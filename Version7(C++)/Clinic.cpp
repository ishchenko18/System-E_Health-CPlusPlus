#include "Clinic.h"
#include "Doctor.h"
#include <iostream>

using namespace std;

const string Clinic::name = "Healthy&Happy";//����������� ���������

Clinic::Clinic()://����������� �� ������������
doctor(1, Doctor("", "", "Therapist", 1))//��������� ��*���� �� ����� �� �������
{
	
}

Clinic::~Clinic()//����������
{
	
}

void Clinic::SetListOfDoctor()
{
	string nameDoctor = doctor[0].GetFirstname() + doctor[0].GetSurname();//��*������� ������� �� ���� �����
	listOfDoctors.push_back(nameDoctor);
}

void Clinic::GetListOfDoctor()
{
	cout << "===========Doctors, who works in " << name << " clinic=========\n";
	copy(listOfDoctors.begin(), listOfDoctors.end(), ostream_iterator<string>(cout, " "));//��������� ������ ����� �����
	cout << endl;
}


