#include <iostream>
#include "Errors.h"

using namespace std;

Errors::Errors(int t) :typeOfException(t)
{

}

Errors::~Errors()
{

}

void Errors::eVariety()
{
	cout << "You chose wrong variant. Please, choose one of the variety\n";
	cin.get();
}

void Errors::eNumber()
{
	cout << "You entered not a number\n";
	cin.get();
}

void Errors::eRhesus()
{
	cout << "You entered wrong data. Enter \'+\' or \'-\'.\n";
	cin.get();
}

void Errors::eBlood()
{
	cout << "Group of blood should be 1,2,3 or 4\n";
	cin.get();
}

void Errors::eGender()
{
	cout << "You should enter \'male\' or \'female\'\n";
	cin.get();
}

void Errors::error() // вибір типу помилки
{
	switch (typeOfException)//<  визначити тип помилки
	{
	case 1:
	{ 
		eVariety(); 
		break;
	}
	case 2:
	{
		eNumber();
		break;
	}
	case 3:
	{
		eRhesus();
		break;
	}
	case 4:
	{
		eBlood();
		break;
	}
	case 5:
	{
		eGender();
		break;
	}
	}
}