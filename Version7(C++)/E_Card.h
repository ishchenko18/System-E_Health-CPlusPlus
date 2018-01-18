#if !defined(__E_Mediciana_E_Card_h)
#define __E_Mediciana_E_Card_h
#include <string>
#include <vector>

using namespace std;

/*!
\brief Клас описує необхідні медичні параметри користувача та всю історію обстежень\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class E_Card
{
public:
   void Write(void);///<Метод відповідає за занесення даних до електронної картки
   void Read(void);///<Метод відповідає за перегляд даних, що містить електронна картка
   void Change(void);///<Метод відповідає за зміну даних в електронній картці
   
   /*!
   \return Довжина вектору денних тисків
   */
   int GetSizeDailyPressure();///<Метод відповідає за отримання довжини вектору денних тисків

   /*!
   \return Довжина вектору нічних тисків
   */
   int GetSizeNightPressure();///<Метод відповідає за отримання довжини вектору ічних тисків

   /*!
   \return Довжина вектору денних пульсів
   */
   int GetSizeDailyPulse();///<Метод відповідає за отримання довжини вектору денних пульсів

   /*!
   \return Довжина вектору нічних пульсів
   */
   int GetSizeNightPulse();///<Метод відповідає за отримання довжини вектору нічних пульсів

   /*!
   \return Довжина вектору результатів енцефалограм
   */
   int GetSizeEncephalograph();///<Метод відповідає за отримання довжини вектору енцефалограм

   /*!
   \return Довжина вектору результатів загальних аналізів сечі
   */
   int GetSizeUrinalysis();///<Метод відповідає за отримання довжини вектору загальних аналізів сечі

   /*!
   \return Довжина вектору результатів каплограм
   */
   int GetSizeCaplogramme();///<Метод відповідає за отримання довжини вектору каплограмм
   int GetAge();///<Гетер для віку користувача
   /*!
   \param age вік користувача
   */
   void SetAge(int age);///<Сетер для віку користувача
   int GetLastVisit();///<Гетер для останнього медичного огляду
   /*!
   \param lastvisit к-ть місяців з часу останнього обстеження
   */
   void SetLastVisit(int lastvisit);///<Сетер для останнього медичного огляду
   int GetGroupOfBlood();///<Гетер для групи крові користувача
   /*!
   \param groupBlood група крові користувача
   */
   void SetGroupOfBlood(int groupBlood);///<Сетер для групи крові користувача
   char GetRh();///<Гетер для резус-фактору користувача
   /*!
   \param rh резус-фактор користувача
   */
   void SetRh(char rh);///<Сетер для резус-фактору користувача
   float GetWeight();///<Гетер для ваги користувача
   /*!
   \param weight вага користувача
   */
   void SetWeight(float weight);///<Сетер для ваги користувача
   float GetHeight();///<Гетер для зросту користувача
   /*!
   \param height зріст користувача
   */
   void SetHeight(float height);///<Сетер для зросту користувача
   string GetSex();///<Гетер для статі користувача
   /*!
   \param sex стать користувача
   */
   void SetSex(string sex);///<Сетер для статі користувача
   /*!
   \param result булевий результат обстеження
   \param index індекс елементу масива
   */
   void SetBadresults(bool result, int index);///<Сетер для результатів аналізів користувача
   /*!
   \param index індекс елементу вектора
   */
   bool GetBadresults(int index);///<Гетер для результатів аналізів користувача
   void GetChronicIllnes();///<Гетер для хронічних захворювань користувача
   /*!
   \param ill хронічне захворювання
   */
   void SetChroniIllnes(string ill);///<Сетер для хронічних захворювань користувача
   /*!
   \param index індекс елементу вектора
   */
   int GetDailyPressure(int index);///<Гетер для денного тиску користувача
   /*!
   \param pressure денний тиск
   */
   void SetDailyPressure(int pressure);///<Сетер для денного тиску користувача
   /*!
   \param index індекс елементу вектора
   */
   int GetDailyPulse(int index);///<Гетер для денного пульсу користувача
   /*!
   \param pulse денний пульс
   */
   void SetDailyPulse(int pulse);///<Сетер для денного пульсу користувача
   /*!
   \param index індекс елементу вектора
   */
   int GetNightPressure(int index);///<Гетер для нічного тиску користувача
   /*!
   \param pressure нічний тиск
   */
   void SetNightPressure(int pressure);///<Сетер для нічного тиску користувача
   /*!
   \param index індекс елементу вектора
   */
   int GetNightPulse(int index);///<Гетер для нічного пульсу користувача
   /*!
   \param pulse нічний пульс
   */
   void SetNightPulse(int pulse);///<Сетер для нічного пульсу користувача
   /*!
   \param index індекс елементу вектора
   */
   bool GetEncelograph(int index);///<Гетер для енцелограми користувача
   /*!
   \param encelograph результат енцелограмми
   */
   void SetEncelograph(bool encelograph);///<Сетер для енцелограми користувача
   /*!
   \param index індекс елементу вектора
   */
   float GetKaplograms(int index);///<Гетер для каплограмми користувача
   /*!
   \param kaplogram результат каплограмми
   */
   void SetKaplogram(float kaplogram);///<Сетер для дкаплограмми користувача
   /*!
   \param index індекс елементу вектора
   */
   float GetUrinalysis(int index);///<Гетер для ЗАС користувача
   /*! 
   \param urinalys результат ЗАС
   */
   void SetUrinalys(float urinalys);///<Сетер для ЗАС користувача
   void GetDiagnosis();///<Гетер для діагнозів користувача
   /*!
   \param diagnos діагноз
   */
   void SetDiagnos(string diagnos);///<Сетер для діагнозів користувача
   void GetAppointments();///<Гетер для призначень користувача
   /*!
   \param appointment призначення лікаря
   */
   void SetAppointment(string appointment);///<Сетер для призначень користувача
   void GetResultsOfSurvey();///<Гетер для результатів обстежень користувача
   /*!
   \param resultsurvey результат медичного огляду
   */
   void SetResultOfSurvey(string resultsurvey);///<Сетер для результатів обстежень користувача
   int GetSizeDiagnosis();
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   E_Card();///<Конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param age вік
   \param groupblood група крові
   \param _rh резус-фактор
   \param _weight вага
   \param _height зріст
   \param lastvisit к-ть місяців з часу останнього візиту
   \param _sex стать
   \param _chronicIll список хронічних захворювань
   \param pressurenight список нічного тиску
   \param pressureday список денного тиску
   \param pulsenight список нічного пульсу
   \param pulseday список денного пульсу
   \param encelogra результат енцелограми
   \param kaplo список результатів каплограми
   \param urinal список результатів аналізів сечі
   \param diagnos список діагнозів
   \param appoint список призначень
   \param resultsurv список результатів обстеження
   */
   E_Card(int _age, int groupblood, char _rh, float _weight, float _height, int lastvisit, string _sex, vector <string>  _chronicIll, vector <int> pressurenight, vector <int> pressureday,
	   vector <int> pulsenight, vector <int> pulseday, vector <bool> encelogra, vector <float> kaplo, vector <float> urinal, vector <string> diagnos, vector <string> appoint, vector <string> resultsurv);///<Kонструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~E_Card();///<Деструктор

protected:
private:
   int age;///<Вік 
   int groupOfBlood;///<Група крові
   char rh;///<Резус-фактор
   float weight;///<Вага користувача
   float height;///<Зріст користувача
   int lastvisit; ///<К-ть місяців з часу останнього обстеження
   string sex;///<Стать користувача
   vector <string> chronicIllness;///<Список хронічних захворювань користувача та його батьків
   bool badresults[7];///<Масив для збереження результатів аналізів у булевій формі( 1 - денний тиск 2 - нічний тиск
					  ///<3 -денний пульс 4 - нічний пульс 5 - енцелографіка 6 - каплограмма 7 - анлізів сечі
   vector <int> dailypressure;///<Список денного тиску
   vector <int> nightpressure;///<Список нічного тиску
   vector <int> dailypulse;///<Список денного пульсу
   vector <int> nightpulse;///<Список нічного пульсу
   vector <bool> encelograph;///<Список результатів енцелографіки
   vector <float> kaplogram;///<Список результатів каплограми
   vector <float> urinalysis;///<Список результатів аналізів сечі
   vector <string> diagnosis;///<Список діагнозів
   vector <string> appointment;///<Список призначень
   vector <string> resultofsurvey;///<Список результатів огляду

};

#endif