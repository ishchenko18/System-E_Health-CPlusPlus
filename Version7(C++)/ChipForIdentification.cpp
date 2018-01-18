#include "ChipForIdentification.h"
#include <iostream>

using namespace std;

ChipForIdentification::ChipForIdentification() ://конструктор за змовчуванням
firstname(""),//ініціалізація імені користувачу
surname(""),//ініціалізація прізвища користувачу
birthday(0),//ініціалізація дати народження
term(0)//ініціалізація строку дії картки
{
	
}

ChipForIdentification::ChipForIdentification(string fname, string sname, int birthday1, int _term) ://конструктор ініціалізації
firstname(fname),//ініціалізація імені користувачу
surname(sname),//ініціалізація прізвища користувачу
birthday(birthday1),//ініціалізація дати народження
term(_term)//ініціалізація строку дії картки
{

}

string ChipForIdentification::GetFirstname()
{
	return firstname;
}

void ChipForIdentification::SetFirstname(string fname)
{
	firstname = fname;
}

string ChipForIdentification::GetSurname()
{
	return surname;
}

void ChipForIdentification::SetSurname(string sname)
{
	surname = sname;
}

int ChipForIdentification::GetBirthday()
{
	return birthday;
}

void ChipForIdentification::SetBirthday(int _birthday)
{
	birthday = _birthday;
}

int ChipForIdentification::GetTerm()
{
	return term;
}

void ChipForIdentification::SetTerm(int _term)
{
	term = _term;
}

ChipForIdentification::~ChipForIdentification()//деструктор
{
	
}


