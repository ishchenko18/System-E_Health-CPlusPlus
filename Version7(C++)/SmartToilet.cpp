#include "SmartToilet.h"
#include <iostream>

using namespace std;

SmartToilet::SmartToilet() ://����������� �� ������������
urinalysis(0),//����������� ���������� ������ ����
caplogramme(0)//����������� ���������� ����������
{
	
}

SmartToilet::SmartToilet(float urin, float caplo) ://����������� �����������
urinalysis(urin),//����������� ���������� ������ ����
caplogramme(caplo)//����������� ���������� ����������
{
	
}

SmartToilet::~SmartToilet()//����������
{
	
}

SmartToilet SmartToilet::operator +(int  i)//�������������� �������� ���������
{
	caplogramme += i;
	urinalysis = urinalysis;
	return *this;
}

void SmartToilet::TakeTests(float urinalys, float caplogr)
{
	urinalysis = urinalys;
	caplogramme = caplogr;
}

void SmartToilet::TakeTests(short caplogr)//������������� �������
{
	urinalysis = 0;
	caplogramme = caplogr;
}

float SmartToilet::GetUrinalysis()
{
	return urinalysis;
}

float SmartToilet::GetCaplogramme()
{
	return caplogramme;
}

