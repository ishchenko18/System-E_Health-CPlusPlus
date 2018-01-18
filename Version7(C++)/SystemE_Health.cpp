#include "SmartBed.h"
#include "SmartBracelet.h"
#include "SmartToilet.h"
#include "E_Card.h"
#include "SystemE_Health.h"
#include <iostream>
#include <vector>

using namespace std;

SystemE_Health::SystemE_Health() ://����������� �� ������������
bed(1, SmartBed()),//��������� ��'���� �� ������� 
bracelet(1,SmartBracelet()),//��������� ��'���� �� ������� 
toilet(1,SmartToilet()),//��������� ��'���� �� ������� 
cards(1, E_Card()),//��������� ��'���� �� ������� 
etalon(1),//��������� �������� �������� �� �������
invitationToClinic("It is necessary to undergo examination in the clinic"),
invitationToDoctor("It is necessary to undergo examination in the treatment doctor"),
recomendation("")//����������� ������ ������������
{
	
}

SystemE_Health::SystemE_Health(vector <float> etal, string recom) ://����������� �����������
bed(1, SmartBed()),//��������� ��'���� �� ������� 
bracelet(1, SmartBracelet()),//��������� ��'���� �� ������� 
toilet(1, SmartToilet()),//��������� ��'���� �� ������� 
cards(1, E_Card()),//��������� ��'���� �� ������� 
etalon(etal),//��������� �������� �������� �� �������
invitationToClinic("It is necessary to undergo examination in the clinic"),
invitationToDoctor("It is necessary to undergo examination in the treatment doctor"),
recomendation(recom)//����������� ������ ������������
{
	
}

SystemE_Health::~SystemE_Health()//����������
{	
	
}

bool SystemE_Health::operator == (int month)//�������������� ���������
{
	return(cards[0].GetLastVisit() == month);
}

std::string SystemE_Health::InvitationToDoctor(void)
{
	return invitationToDoctor;
}

std::string SystemE_Health::RecomendationOfTreatment()
{
	string pressure="", pulse="", encephlaogram="", urinalys="", kaplogram="";//���� ��� ���������� ���� ��������
	if (cards[0].GetBadresults(0) == false || cards[0].GetBadresults(1) == false)//�������� �������� ���������� ������ ������� �� ������ �����
	{
		pressure = "Your pressure isn't normal. Recommended drugs: Losartan or Valsartan, or Telmisartan.\n";//������������ ���� ��������
	}

	if (cards[0].GetBadresults(2) == false || cards[0].GetBadresults(3) == false)//�������� �������� ���������� ������ ������� �� ������ ������
	{
		pulse = "Your pulse isn't normal. Recommended drugs: Panangin or Persen\n";//������������ ���� ��������
	}

	if (cards[0].GetBadresults(4) == false)//�������� �������� ���������� ������ �����������
	{
		encephlaogram = "Your brain needs in vitamins for normal activity. Recomended drugs: Tiamin, Niacin, Piridoksin\n";//������������ ���� ��������
	}

	if (cards[0].GetBadresults(5) == false)//�������� �������� ���������� ������ �����������
	{
		kaplogram = "Your kaplogramm isn't normal. Recomended drugs: Nemozol or Vormil, or Mebendazol\n";//������������ ���� ��������
	}

	if (cards[0].GetBadresults(6) == false)//�������� �������� ���������� ���
	{
		urinalys = "Your general urine analysis isn't normal. Recomended drugs: Allopurinol or Blemaren\n";//������������ ���� ��������
	}

	recomendation = pressure + pulse + encephlaogram + urinalys + kaplogram;//��*������� ������������ � ����
	return recomendation;
}

inline bool SystemE_Health::CompareDailyPressure(int index)//��������� ������� �������� ��������� ������� ����� �� ������� ��������� �������
{
	return (cards[0].GetDailyPressure(cards[0].GetSizeDailyPressure() - index) < etalon[0] || cards[0].GetDailyPressure(cards[0].GetSizeDailyPressure() - index) > etalon[1]);
}

inline bool SystemE_Health::CompareNightPressure(int index)//��������� ������� �������� ��������� ������ ����� �� ������� ��������� �������
{
	return (cards[0].GetNightPressure(cards[0].GetSizeNightPressure() - index) < etalon[0] || cards[0].GetNightPressure(cards[0].GetSizeNightPressure() - index) > etalon[1]);
}

inline bool SystemE_Health :: CompareDailyPulse(int index)//��������� ������� �������� ��������� ������� ������ �� ������� ��������� �������
{
	return (cards[0].GetDailyPulse(cards[0].GetSizeDailyPulse() - index) < etalon[2] || cards[0].GetDailyPulse(cards[0].GetSizeDailyPulse() - index) > etalon[3]);
}

inline bool SystemE_Health :: CompareNightPulse(int index)//��������� ������� �������� ��������� ������ ������ �� ������� ��������� �������
{
	return (cards[0].GetNightPulse(cards[0].GetSizeNightPulse() - index) < etalon[2] || cards[0].GetNightPulse(cards[0].GetSizeNightPulse() - index) > etalon[3]);
}

inline bool SystemE_Health :: CompareEncephalogram(int index)//��������� ������� �������� ���������� �������������
{
	return (cards[0].GetEncelograph(cards[0].GetSizeEncephalograph() - index));
}

inline bool SystemE_Health :: CompareUrinalysis(int index)//��������� ������� �������� �������� ������ ���������� ���������� ������ ����
{
	return (cards[0].GetUrinalysis(cards[0].GetSizeUrinalysis() - index) < etalon[4]);
}

inline bool SystemE_Health::CompareCaplogramme(int index)//��������� ������� �������� �������� ������ ���������� ����������
{
	return (cards[0].GetKaplograms(cards[0].GetSizeCaplogramme() - index) < etalon[4]);
}

bool SystemE_Health::Compare(void)
{
	bool result=true;

	if ((CompareDailyPressure(1)) ||
		(CompareDailyPressure(2)) ||
		(CompareDailyPressure(3)))//�������� ����� ���������� ������� ����� �� ��������� ��� ����������� ��������
	{
		cards[0].SetBadresults(false, 0);//������������ �������� �������� ���������� ������
		result = false;
	}

	if (CompareNightPressure(1) ||
		CompareNightPressure(2) ||
		CompareNightPressure(3))//�������� ����� ���������� ������ ����� �� ��������� ��� ����������� ��������
	{
		cards[0].SetBadresults(false, 1);//������������ �������� �������� ���������� ������
		result = false;
	}

	if ( CompareDailyPulse(1)||
		 CompareDailyPulse(2)||
		 CompareDailyPulse(3))//�������� ����� ���������� ������� ������ �� ��������� ��� ����������� ��������
	{
		cards[0].SetBadresults(false, 2);//������������ �������� �������� ���������� ������
		result = false;
	}

	if ( CompareNightPulse(1)||
		 CompareNightPulse(2)||
		 CompareNightPulse(3))//�������� ����� ���������� ������ ������ �� ��������� ��� ����������� ��������
	{
		cards[0].SetBadresults(false, 3);//������������ �������� �������� ���������� ������
		result = false;
	}

	if (!CompareEncephalogram(1) || !CompareEncephalogram(2) || !CompareEncephalogram(3))//�������� ����� ���������� ������������ �� ��������� ���������� ��������
	{
		cards[0].SetBadresults(false, 4);//������������ �������� �������� ���������� ������
		result = false;
	}

	if (CompareUrinalysis(1) || CompareUrinalysis(2) || CompareUrinalysis(3))//�������� ����� ���������� ���������� ������ ���� �� ��������� ��� ����������� ��������
	{
		cards[0].SetBadresults(false, 6);//������������ �������� �������� ���������� ������
		result = false;
	}

	if (CompareCaplogramme(1) || CompareCaplogramme(2) || CompareCaplogramme(3))//�������� ����� ���������� ����������� �� ��������� ��� ����������� ��������
	{
		cards[0].SetBadresults(false, 5);//������������ �������� �������� ���������� ������
		result = false;
	}

	return result;
}

std::string SystemE_Health::SendInvation(void)
{
	return invitationToClinic;
}
\
void SystemE_Health::ResultsOfSurvey(string resultsurvey)
{
	cout << resultsurvey << endl;
	cards[0].SetResultOfSurvey(resultsurvey);
}

void SystemE_Health::DataInCard()
{
	cards[0].SetDailyPulse(bracelet[0].GetPulse());//����� ���������� ������� ������ �� ���������� ������ � �����-��������
	cards[0].SetDailyPressure(bracelet[0].GetPressure());//����� ���������� ������� ����� �� ���������� ������ � �����-��������
	cards[0].SetNightPulse(bed[0].GetPulse());//����� ���������� ������ ������ �� ���������� ������ � �����-����
	cards[0].SetNightPressure(bed[0].GetPressure());//����� ���������� ������ ����� �� ���������� ������ � �����-����
	cards[0].SetEncelograph(bed[0].GetEncephalography());//����� ���������� ������������ �� ���������� ������ � �����-����
	cards[0].SetKaplogram(toilet[0].GetCaplogramme());//����� ���������� ����������� �� ���������� ������ � �����-�������
	cards[0].SetUrinalys(toilet[0].GetUrinalysis());//����� ���������� ��� �� ���������� ������ � �����-�������
}

void SystemE_Health::GetEtalon()
{
	copy(etalon.begin(), etalon.end(), ostream_iterator<float>(cout, " "));//����� ��� ������� ��������� ������� 
}

void SystemE_Health::SetEtalon()
{
	etalon.push_back(110);//��������� ������ ��� ������������ ����� �� ������ �������
	etalon.push_back(125);//��������� ������� ��� ������������ ����� �� ������ �������
	etalon.push_back(60);//��������� ������ ��� ������ �� ������ �������
	etalon.push_back(80);//��������� ������� ��� ������ �� ������ �������
	etalon.push_back(3);//����� ���� ������ ���������� ������ ���� �� ����������
}
