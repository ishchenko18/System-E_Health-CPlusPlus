#include "SmartBracelet.h"
#include <iostream>

using namespace std;

SmartBracelet::SmartBracelet() ://����������� �� ������������
pulse(0),//����������� ������� ������
pressure(0)//����������� ������� �����
{
	
}

SmartBracelet::SmartBracelet(short _pulse, short _pressure) ://����������� �����������
pulse(_pulse),//����������� ������� ������
pressure(_pressure)//����������� ������� �����
{
	
}

SmartBracelet::~SmartBracelet()//����������
{
	
}

SmartBracelet& SmartBracelet::operator ++()//�������������� �������� ��������� ������������ ����������
{
	pulse += 1;
	pressure += 1;
	return *this;
}

SmartBracelet SmartBracelet::operator ++(int)//�������������� �������� ��������� ����������� ����������
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
