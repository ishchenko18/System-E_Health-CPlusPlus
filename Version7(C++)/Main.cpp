#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "ChipForIdentification.h"
#include "Clinic.h"
#include "Doctor.h"
#include "E_Card.h"
#include "SmartBed.h"
#include "SmartBracelet.h"
#include "SmartToilet.h"
#include "SystemE_Health.h"
#include "User.h"
#include "Errors.h"
#include <ctime>
#include <Windows.h>
#include <cctype>  
#include <cstdlib>  

using namespace std;

void main()
{
	system("color F0");
	srand(time(0));
	char exit = 'y',  choose, year[256];
	string helps;
	int periodOfVisit;

	//========Визначення поточного року=======//
	time_t t;
	struct tm *nabor;
	time(&t);
	nabor = localtime(&t);
	//===============//

	system("title Electronic Health(by Ishchenko Vladyslav)");
	system("START task.txt");
	cout << "Author: Ishchenko Vladyslav\nGroup: IS-63\nCourse: 2\n";

	SystemE_Health MySystem;//створення об*єкту
	User user;//створення об*єкту
	Clinic clinic;//створення об*єкту

	cin.get();
	system("cls");

	cin >> clinic.doctor[0];//введення імені та прізвища лікуючого лікаря(перевантажений оператор введення)

	clinic.SetListOfDoctor();//додавання лікуючого лікаря до списку лікарів

	system("cls");

	cout << "Name of your clinic: ";
	cout << Clinic::GetName() << endl;

	clinic.doctor[0].ShowInfo();//виведення імені та прізвища лікуючого лікаря(перевантажений оператор виведення)

	cout << "You should register in system\n";

	cout << "Enter your firstname: ";
	cin >> helps;//введення імені користувача
	user.chipForIdentification[0].SetFirstname(helps);//запис імені до чипу

	cout << "Enter your surname: ";
	cin >> helps;//введення прізвища користувача
	user.chipForIdentification[0].SetSurname(helps);//запис прізвища до чипу

	do{
		try
		{
			cout << "Enter year of your Birthday: ";
			cin >> year;

			if (!isdigit(year[0]))//введення дати народження
			{
				throw Errors(2);
			}
		}
		catch (Errors er)
		{
			er.error();
			cin.get();
		}
	} while (!isdigit(year[0]));

	user.chipForIdentification[0].SetBirthday(atoi(year));//запис дати народження до чипу
	
	MySystem.cards[0].SetAge((nabor->tm_year + 1900) - user.chipForIdentification[0]);//неявне перетворення типів

	user.chipForIdentification[0].SetTerm(100);//створення терміну дії чипу

	user.SetFirstname((string)user.chipForIdentification[0]);//запам'ятовування імені користувача(використовується явне приведення типів)
	user.SetSurname(user.chipForIdentification[0].GetSurname());//запам'ятовування прізвища користувача

	system("cls");

	cout << "Secondly, fill out the card." << endl;
	system("pause");

	MySystem.cards[0].Write();//занесення даних до картки

	system("cls");

	cout << "Process of registration\n";

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dw = 0u;
	char  cadr[] = "-\\|/";
	const char* ptr;
	int counter = 0;

	COORD pos = { 3, 3 }; // позиція вивода анімації

	while (counter != 3) {

		counter++;
		for (ptr = cadr; *ptr != '\0'; *ptr++) {
			FillConsoleOutputCharacter(hout, *ptr, 1u, pos, &dw);
			Sleep(200u);
		}
	}

	system("cls");

	do{

		user.ShowInfo();//виведення привітання

		do
		{
			cin.get();
			choose = '0';

			system("cls");
			cout << "Choose one of variety:\n1 - Change data in electronic card\n2 - Show information from electronic card\n3 - Next Step\n";
			try
			{
				cin >> choose;//вибір дії

					switch (choose)
					{
					case '1':
						MySystem.cards[0].Change();//зміна даних в картці
						break;
					case '2':
						MySystem.cards[0].Read();//виведення даних з картки
						cin.get();
						break;
					case '3':
						break;
					default:
						throw Errors(1);
						cout << "You chose wrong variant. Please, choose one of the variety\n";
						break;
					}
				}
			catch (Errors ex)
			{
				ex.error();
			}
		} while (choose != '3');

		MySystem.SetEtalon();//встановлення еталонних значень

		system("cls");

		int days,//к-ть днів, протягом яких будуть проводитись зняття результатів
			counter = 0;
		days = rand() % 3 + 3;

		while (counter != days)
		{
			cin.get();
			system("cls");

			HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
			DWORD dw = 0u;
			char  cadr[] = "-\\|/";
			const char* ptr;
			int coun = 0;

			COORD pos = { 3, 3 }; // позиція вивода анімації

			cout << "==========Geting results from devices==========\n";

			while (coun != 3) {
				coun++;
				for (ptr = cadr; *ptr != '\0'; *ptr++) {
					FillConsoleOutputCharacter(hout, *ptr, 1u, pos, &dw);
					Sleep(200u);
				}
			}

			system("cls");

			//================Зняття результатів з смарт застосувань/================
			MySystem.bracelet[0].TakeTests((rand() % 51 + 45), (rand() % 51 + 90));
			MySystem.bed[0].TakeTests(rand() % 2, rand() % 51 + 45, rand() % 51 + 90);
			MySystem.toilet[0].TakeTests(rand() % 5 + 1, rand() % 5 + 1);
			//=====================================================

			cout << "Results of analysis on " <<MySystem.cards[0].GetSizeDailyPulse() + 1 << " day\n";
			//==============Виведення результатів аналізів==============///
			cout << "=====Results from Smart Bracelet=====\n";
			cout << "   Pulse     Pressure     \n";
			cout << setw(7) << MySystem.bracelet[0].GetPulse() << setw(10) << MySystem.bracelet[0].GetPressure() << endl;

			cout << "=====Results from Smart Bed=====\n";
			cout << "   Pulse     Pressure     Encephalography\n";
			cout << setw(7) << MySystem.bed[0].GetPulse() << setw(10) << MySystem.bed[0].GetPressure() << setw(20) << MySystem.bed[0].GetEncephalography() << endl;

			cout << "=====Results from Smart Toilet=====\n";
			cout << "   Urinalysis     Caplogramme     \n";
			cout << setw(10) << MySystem.toilet[0].GetUrinalysis() << setw(10) << MySystem.toilet[0].GetCaplogramme() << endl;
			//====================================================//
			MySystem.DataInCard();//занесення даних до картки

			counter++;
		}

		cin.get();
		system("cls");
		MySystem.cards[0].Read();

		if (!MySystem.Compare())//порівняння результатів аналізів з еталоном
		{
			system("cls");
			cout << "=====All recommendation from system Electronic Medicin=====\n" << MySystem.RecomendationOfTreatment();//виведення рекомендацій від системи
			cin.get();
			system("cls");

			cout << "=====INVITATION=====" << endl;
			cout << MySystem.InvitationToDoctor() << endl;//запрошення до лікаря

			//==============Проходження огляду у лікаря===============//

			//============перевірка коректності вводу=================
			do
			{
				cout << "Will you go to the doctor? y/n" << endl;
				cin >> helps;

				if (helps != "y" && helps != "n")
				{
					cout << "Enter one of variety\n";
				}
				cin.get();

			} while (helps != "y" && helps != "n");
			//====================================================

			if (helps == "y")
			{
				string diagnos;
				system("cls");
				user.VisitDoctor();//візит до лікаря
				diagnos = clinic.doctor[0].Examination();//встановлення діагноз
				MySystem.cards[0].SetDiagnos(diagnos);//занесення діагнозу в картку
				cout << "Result of examination in doctor: " << diagnos  << endl;
				MySystem.cards[0].SetAppointment(clinic.doctor[0].MakeAppointment());
				cin.get();
			}
			else
			{
				cout << "Ok. You will not visit to doctor. You have such right.\n";
				cin.get();
			}
			//==========================================//
		}
		else
		{
			cout << "All results is normal\n";
			cin.get();
		}

		if (MySystem.cards[0].GetSizeDiagnosis() != 0)
		{
			periodOfVisit = 6;
			MySystem.cards[0].SetLastVisit(rand() % 3 + 4);//встановлення дати останнього медичного огляду
		}
		else
		{
			periodOfVisit = 12;
			MySystem.cards[0].SetLastVisit(rand() % 3 + 10);//встановлення дати останнього медичного огляду
		}

		//============Проходження медичного огляду=============//
		if (MySystem == periodOfVisit)//використовується перевантажений оператор
		{
			char value;

			//=============Перевірка коректності вводу================
			do
			{
				system("cls");
				cout << "Your last medical examination was "<< MySystem.cards[0].GetLastVisit()<<" month ago. Will you go to the examination? y/n" << endl;
				cin >> value;

				if (value != 'y' && value != 'n')
				{
					cout << "Enter one of variety\n";
				}

				cin.get();

			} while (value != 'y' && value != 'n');
			//=======================================

			//============Результат медичного обстеження==============//
			if (value == 'y')
			{
				cout << "====You will be going to the clinic====\n";

				user.Survey();

				switch (rand() % 3 + 1)
				{
				case 1:
					MySystem.ResultsOfSurvey("Everythink is ok. All results is normal\n");//встановлення результату огляду
					cin.get();
					break;
				case 2:
					MySystem.ResultsOfSurvey("You have some bad results of analysis. You should visit to your treatment doctor\n");//встановлення результату огляду
					cin.get();
					break;
				case 3:
					//=============Перевірка коректності вводу================
					do
					{
						system("cls");
						MySystem.ResultsOfSurvey("Results of analysis are not normal. We recommend going to clinic.");
						cout<<"Are you agree? y/n\n";

						cin >> value;

						if (value != 'y' && value != 'n')
						{
							cout << "Enter one of variety\n";
						}
						cin.get();
					} while (value != 'y' && value != 'n');
					//==========================================================

					break;
				default:
					break;
				}

				cin.get();
			}
			else
			{
				cout << "You won't be going to the clinic. It's your choice\n";
				cin.get();
			}
		}
		else
		{
			system("cls");
			cout << "Your last medical examination was " << MySystem.cards[0].GetLastVisit() << " month ago.\nAfter " << periodOfVisit - MySystem.cards[0].GetLastVisit() << " month will be examination in clinic" << endl;//виведення періоду перед наступним медичним оглядом
			cin.get();
		}

		system("cls");

		do
		{
			system("cls");
			cout << "Choose one of variety:\n1 - Change data in electronic card\n2 - Show information from electronic card\n3 - Next Step\n";//варіанти операцій
			try
			{
				cin >> choose;//вибір дії

					switch (choose)
					{
					case '1':
						MySystem.cards[0].Change();//зміна даних в картці
						break;
					case '2':
						MySystem.cards[0].Read();//виведення даних з картки
						cin.get();
						break;
					case '3':
						break;
					default:
						throw Errors(1);	
						break;
					}
			}
			catch (Errors ex)
			{
				ex.error();
				cin.get();
			}
		} while (choose != '3');

		cin.get();

		//=============Перевірка коректності вводу================
		do
		{
			system("cls");

			cout << "Do you wanna repeat the program? y/n"<<endl;
			cin >> exit;

			if (exit != 'y' && exit != 'n')
			{
				cout << "Please, choose one of variety\n";
				cin.get();
			}


		} while (exit!='y' && exit!='n');
		//==================================================


	}while (exit=='y');
}