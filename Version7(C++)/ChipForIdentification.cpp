#include "ChipForIdentification.h"
#include <iostream>

using namespace std;

ChipForIdentification::ChipForIdentification() ://����������� �� ������������
firstname(""),//����������� ���� �����������
surname(""),//����������� ������� �����������
birthday(0),//����������� ���� ����������
term(0)//����������� ������ 䳿 ������
{
	
}

ChipForIdentification::ChipForIdentification(string fname, string sname, int birthday1, int _term) ://����������� �����������
firstname(fname),//����������� ���� �����������
surname(sname),//����������� ������� �����������
birthday(birthday1),//����������� ���� ����������
term(_term)//����������� ������ 䳿 ������
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

ChipForIdentification::~ChipForIdentification()//����������
{
	
}


