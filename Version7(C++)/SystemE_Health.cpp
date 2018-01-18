#include "SmartBed.h"
#include "SmartBracelet.h"
#include "SmartToilet.h"
#include "E_Card.h"
#include "SystemE_Health.h"
#include <iostream>
#include <vector>

using namespace std;

SystemE_Health::SystemE_Health() ://конструктор за змовчуванням
bed(1, SmartBed()),//додавання об'єкту до вектору 
bracelet(1,SmartBracelet()),//додавання об'єкту до вектору 
toilet(1,SmartToilet()),//додавання об'єкту до вектору 
cards(1, E_Card()),//додавання об'єкту до вектору 
etalon(1),//додавання еталонної велечини до вектору
invitationToClinic("It is necessary to undergo examination in the clinic"),
invitationToDoctor("It is necessary to undergo examination in the treatment doctor"),
recomendation("")//ініціалізація строки рекомендації
{
	
}

SystemE_Health::SystemE_Health(vector <float> etal, string recom) ://конструктор ініціалізації
bed(1, SmartBed()),//додавання об'єкту до вектору 
bracelet(1, SmartBracelet()),//додавання об'єкту до вектору 
toilet(1, SmartToilet()),//додавання об'єкту до вектору 
cards(1, E_Card()),//додавання об'єкту до вектору 
etalon(etal),//додавання еталонної велечини до вектору
invitationToClinic("It is necessary to undergo examination in the clinic"),
invitationToDoctor("It is necessary to undergo examination in the treatment doctor"),
recomendation(recom)//ініціалізація строки рекомендації
{
	
}

SystemE_Health::~SystemE_Health()//деструктор
{	
	
}

bool SystemE_Health::operator == (int month)//перевантаження оператора
{
	return(cards[0].GetLastVisit() == month);
}

std::string SystemE_Health::InvitationToDoctor(void)
{
	return invitationToDoctor;
}

std::string SystemE_Health::RecomendationOfTreatment()
{
	string pressure="", pulse="", encephlaogram="", urinalys="", kaplogram="";//змінні для рекомендаій щодо лікування
	if (cards[0].GetBadresults(0) == false || cards[0].GetBadresults(1) == false)//перевірка булевого результату аналізів денного та нічного тисків
	{
		pressure = "Your pressure isn't normal. Recommended drugs: Losartan or Valsartan, or Telmisartan.\n";//рекомендація щодо лікування
	}

	if (cards[0].GetBadresults(2) == false || cards[0].GetBadresults(3) == false)//перевірка булевого результату аналізів денного та нічного пульсів
	{
		pulse = "Your pulse isn't normal. Recommended drugs: Panangin or Persen\n";//рекомендація щодо лікування
	}

	if (cards[0].GetBadresults(4) == false)//перевірка булевого результату аналізів енцелограми
	{
		encephlaogram = "Your brain needs in vitamins for normal activity. Recomended drugs: Tiamin, Niacin, Piridoksin\n";//рекомендація щодо лікування
	}

	if (cards[0].GetBadresults(5) == false)//перевірка булевого результату аналізів каплограмми
	{
		kaplogram = "Your kaplogramm isn't normal. Recomended drugs: Nemozol or Vormil, or Mebendazol\n";//рекомендація щодо лікування
	}

	if (cards[0].GetBadresults(6) == false)//перевірка булевого результату ЗАС
	{
		urinalys = "Your general urine analysis isn't normal. Recomended drugs: Allopurinol or Blemaren\n";//рекомендація щодо лікування
	}

	recomendation = pressure + pulse + encephlaogram + urinalys + kaplogram;//об*єднання рекомендацій в одну
	return recomendation;
}

inline bool SystemE_Health::CompareDailyPressure(int index)//вбудована функція перевірки належності денного тиску до проміжку еталонних значень
{
	return (cards[0].GetDailyPressure(cards[0].GetSizeDailyPressure() - index) < etalon[0] || cards[0].GetDailyPressure(cards[0].GetSizeDailyPressure() - index) > etalon[1]);
}

inline bool SystemE_Health::CompareNightPressure(int index)//вбудована функція перевірки належності нічного тиску до проміжку еталонних значень
{
	return (cards[0].GetNightPressure(cards[0].GetSizeNightPressure() - index) < etalon[0] || cards[0].GetNightPressure(cards[0].GetSizeNightPressure() - index) > etalon[1]);
}

inline bool SystemE_Health :: CompareDailyPulse(int index)//вбудована функція перевірки належності денного пульсу до проміжку еталонних значень
{
	return (cards[0].GetDailyPulse(cards[0].GetSizeDailyPulse() - index) < etalon[2] || cards[0].GetDailyPulse(cards[0].GetSizeDailyPulse() - index) > etalon[3]);
}

inline bool SystemE_Health :: CompareNightPulse(int index)//вбудована функція перевірки належності нічного пульсу до проміжку еталонних значень
{
	return (cards[0].GetNightPulse(cards[0].GetSizeNightPulse() - index) < etalon[2] || cards[0].GetNightPulse(cards[0].GetSizeNightPulse() - index) > etalon[3]);
}

inline bool SystemE_Health :: CompareEncephalogram(int index)//вбудована функція перевірки результату енцефалограми
{
	return (cards[0].GetEncelograph(cards[0].GetSizeEncephalograph() - index));
}

inline bool SystemE_Health :: CompareUrinalysis(int index)//вбудована функція перевірки загальної оцінки результату загального аналізу сечі
{
	return (cards[0].GetUrinalysis(cards[0].GetSizeUrinalysis() - index) < etalon[4]);
}

inline bool SystemE_Health::CompareCaplogramme(int index)//вбудована функція перевірки загальної оцінки результату каплограми
{
	return (cards[0].GetKaplograms(cards[0].GetSizeCaplogramme() - index) < etalon[4]);
}

bool SystemE_Health::Compare(void)
{
	bool result=true;

	if ((CompareDailyPressure(1)) ||
		(CompareDailyPressure(2)) ||
		(CompareDailyPressure(3)))//перевірка трьох результатів денного тиску на належність межі етеалонного значення
	{
		cards[0].SetBadresults(false, 0);//встановлення булевого значення результату аналізу
		result = false;
	}

	if (CompareNightPressure(1) ||
		CompareNightPressure(2) ||
		CompareNightPressure(3))//перевірка трьох результатів нічного тиску на належність межі етеалонного значення
	{
		cards[0].SetBadresults(false, 1);//встановлення булевого значення результату аналізу
		result = false;
	}

	if ( CompareDailyPulse(1)||
		 CompareDailyPulse(2)||
		 CompareDailyPulse(3))//перевірка трьох результатів денного пульсу на належність межі етеалонного значення
	{
		cards[0].SetBadresults(false, 2);//встановлення булевого значення результату аналізу
		result = false;
	}

	if ( CompareNightPulse(1)||
		 CompareNightPulse(2)||
		 CompareNightPulse(3))//перевірка трьох результатів нічного пульсу на належність межі етеалонного значення
	{
		cards[0].SetBadresults(false, 3);//встановлення булевого значення результату аналізу
		result = false;
	}

	if (!CompareEncephalogram(1) || !CompareEncephalogram(2) || !CompareEncephalogram(3))//перевірка трьох результатів енцелограмми на належність еталонному значенню
	{
		cards[0].SetBadresults(false, 4);//встановлення булевого значення результату аналізу
		result = false;
	}

	if (CompareUrinalysis(1) || CompareUrinalysis(2) || CompareUrinalysis(3))//перевірка трьох результатів загального аналізу сечі на належність межі етеалонного значення
	{
		cards[0].SetBadresults(false, 6);//встановлення булевого значення результату аналізу
		result = false;
	}

	if (CompareCaplogramme(1) || CompareCaplogramme(2) || CompareCaplogramme(3))//перевірка трьох результатів каплограмми на належність межі етеалонного значення
	{
		cards[0].SetBadresults(false, 5);//встановлення булевого значення результату аналізу
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
	cards[0].SetDailyPulse(bracelet[0].GetPulse());//запис результату денного пульсу до електронної картки з смарт-браслету
	cards[0].SetDailyPressure(bracelet[0].GetPressure());//запис результату денного тиску до електронної картки з смарт-браслету
	cards[0].SetNightPulse(bed[0].GetPulse());//запис результату нічного пульсу до електронної картки з смарт-ліжка
	cards[0].SetNightPressure(bed[0].GetPressure());//запис результату нічного тиску до електронної картки з смарт-ліжка
	cards[0].SetEncelograph(bed[0].GetEncephalography());//запис результату енцелограмми до електронної картки з смарт-ліжка
	cards[0].SetKaplogram(toilet[0].GetCaplogramme());//запис результату каплограмми до електронної картки з смарт-туалету
	cards[0].SetUrinalys(toilet[0].GetUrinalysis());//запис результату ЗАС до електронної картки з смарт-туалету
}

void SystemE_Health::GetEtalon()
{
	copy(etalon.begin(), etalon.end(), ostream_iterator<float>(cout, " "));//Гетер для вектору еталонних значень 
}

void SystemE_Health::SetEtalon()
{
	etalon.push_back(110);//Занесення нижньої межі артеріального тиску до списку еталонів
	etalon.push_back(125);//Занесення верхньої межі артеріального тиску до списку еталонів
	etalon.push_back(60);//Занесення нижньої межі пульсу до списку еталонів
	etalon.push_back(80);//Занесення верхньої межі пульсу до списку еталонів
	etalon.push_back(3);//Нижня межа оцінки результатів аналізів сечі та каплограми
}
