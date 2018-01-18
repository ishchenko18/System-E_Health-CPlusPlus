#include "SmartBed.h"
#include <iostream>

using namespace std;

SmartBed::SmartBed() ://����������� �� ������������
encephalography(false),//����������� ���������� �������������
pulse(0),//����������� ���������� ������ ������
pressure(0)//����������� ���������� ������ �����
{
	
}

SmartBed::SmartBed(bool engraphy, short _pulse, short _pressure) ://����������� �����������
encephalography(engraphy),//����������� ���������� �������������
pulse(_pulse),//����������� ���������� ������ ������
pressure(_pressure)//����������� ���������� ������ �����
{
	
}

SmartBed::~SmartBed()//����������
{
	
}

SmartBed SmartBed::operator =(SmartBed bed)//������������� ��������� ���������
{
	return SmartBed(this->encephalography, this->pulse, this->pressure);
}

void SmartBed::TakeTests(bool encel, short pulse, short pressure)//������� ������
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

