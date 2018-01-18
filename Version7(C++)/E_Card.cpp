#include "E_Card.h"
#include "Errors.h"
#include <cctype>   // для функции isdigit
#include <cstdlib>  // для функции atoi
#include <iostream>
#include <vector>

using namespace std;

E_Card::E_Card() ://конструктор за змовчуванням
age(0),
groupOfBlood(0),
rh('0'),
weight(0),
height(0),
lastvisit(0),
sex(""),
chronicIllness(0),
nightpressure(0),
dailypressure(0),
nightpulse(0),
dailypulse(0),
encelograph(0),
kaplogram(0),
urinalysis(0),
diagnosis(0),
appointment(0),
resultofsurvey(0)
{
	
}

E_Card::E_Card(int _age, int groupblood, char _rh, float _weight, float _height, int lastvis, string _sex, vector <string>  _chronicIll, vector <int> pressurenight, vector <int> pressureday,
	vector <int> pulsenight, vector <int> pulseday, vector <bool> encelogra, vector <float> kaplo, vector <float> urinal, vector <string> diagnos, vector <string> appoint, vector <string> resultsurv) ://конструктор ініціалізації
	age(_age),
	groupOfBlood(groupblood),
	rh(_rh),
	weight(_weight),
	height(_height),
	lastvisit(lastvis),
	sex(_sex),
	chronicIllness(_chronicIll),
	nightpressure(pressurenight),
	dailypressure(pressureday),
	nightpulse(pulsenight),
	dailypulse(pulseday),
	encelograph(encelogra),
	kaplogram(kaplo),
	urinalysis(urinal),
	diagnosis(diagnos),
	appointment(appoint),
	resultofsurvey(resultsurv)
{
	
}

E_Card::~E_Card()//деструктор
{
	
}

void E_Card::Write()//початкова ініціалізація атрибутів електронної картки
{
	char exit='n';//умова виходу
	string ill;
	char helpString[256];
	
	system("cls");

	cout << "=====You should enter beginner data for elecronic card=====\n";
	cout << "Your age: " << age <<endl;

	do{
		try
		{
			cout << "Your group of blood: ";
			cin >> helpString;

			if (!isdigit(helpString[0]))//перевірка на число
			{
				throw Errors(2);
			}
			if (atoi(helpString) != 1 && atoi(helpString) != 2 && atoi(helpString) != 3 && atoi(helpString) != 4)//перевірка на коректність вводу групи крові
			{
				throw Errors(4);
			}
		}
		catch (Errors er)
		{
			//==============перевірка на тип помилки=================
			er.error();
			//========================================

			cin.get();
		}
	} while (!isdigit(helpString[0]) || (atoi(helpString) != 1 && atoi(helpString) != 2 && atoi(helpString) != 3 && atoi(helpString) != 4));

	groupOfBlood = atoi(helpString);// групи крові

	do{
		try
		{
			cout << "Your rhesus factor(\'+\' or \'-\'): ";
			cin >> rh;//введення резус-фактору

			if (rh != '+' && rh != '-')//перевірка на коретність введеного резус фактору
			{
				throw Errors(3);
			}
		}
		catch (Errors er)
		{
			er.error();
			cin.get();
		}
	} while (rh != '+' && rh != '-');

	do{
		try
		{
			cout << "Your weight = ";
			cin >> helpString;//введення ваги

			if (!isdigit(helpString[0]))//перевірка на число
			{
				throw Errors(2);
			}
		}
		catch (Errors er)
		{
			er.error();
			cin.get();
		}
	} while (!isdigit(helpString[0]));

	weight = atof(helpString);//перетворення числа

	do{

		try
		{
			cout << "Your height = ";
			cin >> helpString;//введення висоти

			if (!isdigit(helpString[0]))//перевірка на число
			{
				throw Errors(2);
			}
		}
		catch (Errors er)
		{
			er.error();
			cin.get();
		}
	} while (!isdigit(helpString[0]));

	height = atof(helpString);//перетворення числа

	do{

		try
		{
			cout << "What's your gender(male or female): ";
			cin >> sex;//введення 
			
			if (sex!= "male" && sex != "female")//перевірка на коректність введеної статі
			{
				throw Errors(5);
			}
		}
		catch (Errors er)
		{
			er.error();
			cin.get();
		}
	} while (sex != "male" && sex != "female");

	do
	{
		cout << "Do you have chronic illnes? y/n\n";
		cin >> exit;

		if (exit != 'y' && exit != 'n')//перевірка коректності вводу
		{
			cout << "You should choose \'y\' or \'n\'\n";
		}
		cin.get();
	} while (exit != 'y' && exit != 'n');

	if (exit == 'y')
	{
		do
		{
			cout << "Enter name of your ill: ";
			cin >> ill;//введення хронічної хвороби
			SetChroniIllnes(ill);//додавання хронічної хвороби до вектору

			do
			{
				cout << "You wanna to add more disease? y/n" << endl;
				cin >> exit;

				if (exit != 'y' && exit != 'n')//перевірка коректності вводу
				{
					cout << "You should choose \'y\' or \'n\'\n";
				}
				cin.get();

			} while (exit != 'y' && exit != 'n');
		} while (exit == 'y');
	}

	for (int i = 0; i < 7; i++)
	{
		badresults[i] = true;//встановлення стандартного значення результату аналізу
	}
}

void E_Card::Read(void)//виведення інформації з електронної картки
{
	cout << "========Information from you electronic card========"<<endl;

	cout << "Age: " << GetAge() << endl;//виведення віку
	cout << "Weight: " << GetWeight() << endl;//виведення ваги
	cout << "Height :" << GetHeight() << endl;//виведення зросту
	cout << "Group of blood: " << GetGroupOfBlood() << endl;//виведення групи крові
	cout << "Rhesus factor: " << GetRh() << endl;//виведення резус-фактору
	cout << "Sex: " << GetSex() << endl;//виведення статі

	cout << "====list of your daily pressure====\n";
	copy(dailypressure.begin(), dailypressure.end(), ostream_iterator<int>(cout, " "));//виведення результатів денного тиску
	cout << endl;

	cout << "====list of your night pressure====\n";
	copy(nightpressure.begin(), nightpressure.end(), ostream_iterator<int>(cout, " "));//виведення результатів нічного тиску
	cout << endl;

	cout << "====list of your daily pulse====\n";
	copy(dailypulse.begin(), dailypulse.end(), ostream_iterator<int>(cout, " "));//виведення результатів денного пульсу
	cout << endl;

	cout << "====list of your night pulse====\n";
	copy(nightpulse.begin(), nightpulse.end(), ostream_iterator<int>(cout, " "));//виведення результатів нічного пульсу
	cout << endl;

	cout << "====list of results your encelograms====\n";
	copy(encelograph.begin(), encelograph.end(), ostream_iterator<int>(cout, " "));//виведення результатів енцелограмми
	cout << endl;

	cout << "====list of results your kaplogramms====\n";
	copy(kaplogram.begin(), kaplogram.end(), ostream_iterator<int>(cout, " "));//виведення результатів каплограмми
	cout << endl;

	cout << "====list of results your urinalysis====\n";
	copy(urinalysis.begin(), urinalysis.end(), ostream_iterator<int>(cout, " "));//виведення результатів загального аналізу сечі
	cout << endl;

	cout << "====list of your diagnosis====\n";
	GetDiagnosis();//виведення списку діагнозів
	cout << endl;

	cout << "====list of your appointments====\n";
	GetAppointments();//виведення списку призначень
	cout << endl;

	cout << "====list of result surveys====\n";
	GetResultsOfSurvey();//виведення списку результатів огляду

	cin.get();
}

void E_Card::Change(void)//зміна інформації в електронній картці
{
	char choose, helpString[256];
	do
	{
		system("cls");
		cout << "=========Changing information in electronic card==========\n";
		cout << "What do you want change in card:\n1 - Age\n2 - Weight\n3 - Height\n4 - Exit\n";
		cin >> choose;//вибір варіанту
		switch (choose)
		{
		case '1':
			do{
				try
				{
					cout << "Your current  age: " << age << "\nEnter age: ";
					cin >> helpString;//введення ваги

					if (!isdigit(helpString[0]))
					{
						throw Errors(2);
					}
				}
				catch (Errors er)
				{
					er.error();
					cin.get();
				}
			} while (!isdigit(helpString[0]));

			age = atoi(helpString);
			break;
		case '2':
			do{
				try
				{
					cout << "Your current  weight: " << weight << "\nEnter weight: ";
					cin >> helpString;//введення ваги

					if (!isdigit(helpString[0]))
					{
						throw Errors(2);
					}
				}
				catch (Errors er)
				{
					er.error();
					cin.get();
				}
			} while (!isdigit(helpString[0]));

			weight = atof(helpString);
			break;
		case '3':
			do{

				try
				{
					cout << "Your current  height: " << height << "\nEnter height: ";
					cin >> helpString;//введення висоти

					if (!isdigit(helpString[0]))
					{
						throw Errors(2);
					}
				}
				catch (Errors er)
				{
					er.error();
					cin.get();
				}
			} while (!isdigit(helpString[0]));
			
			height = atof(helpString);
			break;
		case '4':
			break;
		default:
			cout << "You chose wrong figure!\n";
			break;
		}
	} while (choose!='4');
	cin.get();
}

int E_Card::GetSizeDailyPressure()
{
	return dailypressure.size();
}

int E_Card::GetSizeNightPressure()
{
	return nightpressure.size();
}

int E_Card::GetSizeDailyPulse()
{
	return dailypulse.size();
}

int E_Card::GetSizeNightPulse()
{
	return nightpulse.size();
}

int E_Card::GetSizeEncephalograph()
{
	return encelograph.size();
}

int E_Card::GetSizeUrinalysis()
{
	return urinalysis.size();
}

int E_Card::GetSizeCaplogramme()
{
	return kaplogram.size();
}

int E_Card::GetSizeDiagnosis()
{
	return diagnosis.size();
}

void E_Card::SetBadresults(bool result, int index)
{
	badresults[index] = result;
}

bool E_Card::GetBadresults(int index)
{
	return badresults[index];
}

int E_Card::GetAge()
{
	return age;
}

void E_Card::SetAge(int age)
{
	this->age = age;
}

int E_Card::GetLastVisit()
{
	return lastvisit;
}

void E_Card::SetLastVisit(int lastvisit)
{
	this->lastvisit = lastvisit;
}

int E_Card::GetGroupOfBlood()
{
	return groupOfBlood;
}

void E_Card::SetGroupOfBlood(int groupBlood)
{
	groupOfBlood = groupBlood;
}

char E_Card::GetRh()
{
	return rh;
}

void E_Card::SetRh(char rh)
{
	this->rh = rh;
}

float E_Card::GetWeight()
{
	return weight;
}

void E_Card::SetWeight(float weight)
{
	this->weight=weight;
}

float E_Card::GetHeight()
{
	return height;
}

void E_Card::SetHeight(float height)
{
	this->height = height;
}

string E_Card::GetSex()
{
	return sex;
}

void E_Card::SetSex(string sex)
{
	this->sex = sex;
}

void E_Card::GetChronicIllnes()
{
	copy(chronicIllness.begin(), chronicIllness.end(), ostream_iterator<string>(cout, " "));
}

void E_Card::SetChroniIllnes(string ill)
{
	chronicIllness.push_back(ill);
}

int E_Card::GetDailyPressure(int index)
{
	return dailypressure[index];
}

void E_Card::SetDailyPressure(int pressure)
{
	dailypressure.push_back(pressure);
}

int E_Card::GetDailyPulse(int index)
{
	return dailypulse[index];
}

void E_Card::SetDailyPulse(int pulse)
{
	dailypulse.push_back(pulse);
}

int E_Card::GetNightPressure(int index)
{
	return nightpressure[index];
}

void E_Card::SetNightPressure(int pressure)
{
	nightpressure.push_back(pressure);
}

int E_Card::GetNightPulse(int index)
{
	return nightpulse[index];
}

void E_Card::SetNightPulse(int pulse)
{
	nightpulse.push_back(pulse);
}

bool E_Card::GetEncelograph(int index)
{
	return encelograph[index];
}

void E_Card::SetEncelograph(bool encelograph)
{
	this->encelograph.push_back(encelograph);
}

float E_Card::GetKaplograms(int index)
{
	return kaplogram[index];
}

void E_Card::SetKaplogram(float kaplogram)
{
	this->kaplogram.push_back(kaplogram);
}

float E_Card::GetUrinalysis(int index)
{
	return urinalysis[index];
}

void E_Card::SetUrinalys(float urinalys)
{
	urinalysis.push_back(urinalys);
}

void E_Card::GetDiagnosis()
{
	copy(diagnosis.begin(), diagnosis.end(), ostream_iterator<string>(cout, " "));
}

void E_Card::SetDiagnos(string diagnos)
{
	diagnosis.push_back(diagnos);
}

void E_Card::GetAppointments()
{
	copy(appointment.begin(), appointment.end(), ostream_iterator<string>(cout, " "));
}

void E_Card::SetAppointment(string appointment)
{
	this->appointment.push_back(appointment);
}

void E_Card::GetResultsOfSurvey()
{
	copy(resultofsurvey.begin(), resultofsurvey.end(), ostream_iterator<string>(cout, " "));
}

void E_Card::SetResultOfSurvey(string resultsurvey)
{
	resultofsurvey.push_back(resultsurvey);
}

