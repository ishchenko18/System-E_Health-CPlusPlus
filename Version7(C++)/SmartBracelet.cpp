#include "SmartBracelet.h"
#include <iostream>

using namespace std;

SmartBracelet::SmartBracelet() ://конструктор за змовчуванням
pulse(0),//ініціалізація денного пульсу
pressure(0)//ініціалізація денного тиску
{
	
}

SmartBracelet::SmartBracelet(short _pulse, short _pressure) ://конструктор ініціалізації
pulse(_pulse),//ініціалізація денного пульсу
pressure(_pressure)//ініціалізація денного тиску
{
	
}

SmartBracelet::~SmartBracelet()//деструктор
{
	
}

SmartBracelet& SmartBracelet::operator ++()//Перевантаження унарного оператора постфіксного інкременту
{
	pulse += 1;
	pressure += 1;
	return *this;
}

SmartBracelet SmartBracelet::operator ++(int)//Перевантаження унарного оператора префіксного інкременту
{
	SmartBracelet bracelet = *this;
	++*this;
	return bracelet;
}

void SmartBracelet::TakeTests(short pulse, short pressure)
{
	this->pulse = pulse;
	this->pressure = pressure;
}

short SmartBracelet::GetPulse()
{
	return pulse;
}

short SmartBracelet::GetPressure()
{
	return pressure;
}
