#include "SmartBed.h"
#include <iostream>

using namespace std;

SmartBed::SmartBed() ://конструктор за змовчуванням
encephalography(false),//ініціалізація результату енцелографіки
pulse(0),//ініціалізація результату нічного пульсу
pressure(0)//ініціалізація результату нічного тиску
{
	
}

SmartBed::SmartBed(bool engraphy, short _pulse, short _pressure) ://конструктор ініціалізації
encephalography(engraphy),//ініціалізація результату енцелографіки
pulse(_pulse),//ініціалізація результату нічного пульсу
pressure(_pressure)//ініціалізація результату нічного тиску
{
	
}

SmartBed::~SmartBed()//деструктор
{
	
}

SmartBed SmartBed::operator =(SmartBed bed)//перевантження оператора присвоєння
{
	return SmartBed(this->encephalography, this->pulse, this->pressure);
}

void SmartBed::TakeTests(bool encel, short pulse, short pressure)//функція утиліта
{
	encephalography = encel;
	this->pulse = pulse;
	this->pressure = pressure;
}


bool SmartBed::GetEncephalography()
{
	return encephalography;
}

short SmartBed::GetPulse()
{
	return pulse;
}

short SmartBed::GetPressure()
{
	return pressure;
}

