#include "SmartToilet.h"
#include <iostream>

using namespace std;

SmartToilet::SmartToilet() ://конструктор за змовчуванням
urinalysis(0),//ініціалізація результату аналізу сечі
caplogramme(0)//ініціалізація результату каплограми
{
	
}

SmartToilet::SmartToilet(float urin, float caplo) ://конструктор ініціалізації
urinalysis(urin),//ініціалізація результату аналізу сечі
caplogramme(caplo)//ініціалізація результату каплограми
{
	
}

SmartToilet::~SmartToilet()//деструктор
{
	
}

SmartToilet SmartToilet::operator +(int  i)//перевантаження бінарного оператора
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

void SmartToilet::TakeTests(short caplogr)//перевантажена функція
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

