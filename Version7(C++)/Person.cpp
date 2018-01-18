#include "Person.h"
#include <string>
#include <iostream>

Person::Person() :
firstname(""),//встанволення імені
surname("")//встанволення прізвища
{

}

Person::Person(std::string fname, std::string sname) :
firstname(fname),//встанволення імені
surname(sname)//встанволення прізвища
{
	
}void Person::ShowInfo()
{
	std::cout << "Firstname: " << firstname << "\nSurname: " << surname;
}

std::string Person::GetFirstname()//Отримання імені
{
	return firstname;
}

void Person::SetFirstname(std::string fname)//Встановлення імені
{
	firstname = fname;
}

std::string Person::GetSurname()//Отримання прізвища
{
	return surname;
}

void Person::SetSurname(std::string sname)//встановлення прізвища
{
	surname = sname;
}