
#if !defined(__E_Mediciana_SystemE_Health_h)
#define __E_Mediciana_SystemE_Health_h
#include <vector>
#include <string>

class SmartBed;
class SmartBracelet;
class SmartToilet;
class E_Card;

/*!
\brief Клас відповідає за обробку отриманої інформації
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class SystemE_Health
{
public:
	/*!
	\return Рекомендацію, про необхідність відвідати лікуючого лікаря
	*/
   std::string InvitationToDoctor(void);///<метод відповідає за виведення  рекомендації, щодо необхідності з'явитись до лікаря
   /*!
   \return Рекомендацію, щодо лікування
   */
   std::string RecomendationOfTreatment();///<метод відповідає за виведення рекомендації, щодо лікування
   /*!
   \return Істину, коли аналізи в нормі або хибність в іншому випадку
   */
   bool Compare(void);///<метод порівнює результати аналізів з еталоном
   /*!
   \return Запрошення на медичний огляд
   */
   std::string SendInvation(void);///<метод відповідає за надсилання запрошень на обстеження
   /*!
   \param resultsurvey результат обстеження
   */
   void ResultsOfSurvey(string resultsurvey);///<метод відповідає за відображення результатів обстеження
   void DataInCard(void);///<метод відповідає за занесення даних до електронної картки
   void GetEtalon();///<Гетер еталоних значень результатів аналізів користувачів
   void SetEtalon();///<Встановлення еталонних значень
   
   /*!
   \return Булевий результат порівняння денного тиску з еталоном
   \param index індекс елемента вектору з кінця
   */
   bool CompareDailyPressure(int index);///<Порівняння денного тиску з еталоном
  
   /*!
   \return Булевий результат порівняння нічного тиску з еталоном
   \param index індекс елемента вектору з кінця
   */
   bool CompareNightPressure(int index);///<Порівняння нічного тиску з еталоном
   
   /*!
   \return Булевий результат порівняння денного пульсу з еталоном
   \param index індекс елемента вектору з кінця
   */
   bool CompareDailyPulse(int index);///<Порівняння денного пульсу з еталоном
  
   /*!
   \return Булевий результат порівняння нічного тиску з еталоном
   \param index індекс елемента вектору з кінця
   */
   bool CompareNightPulse(int index);///<Порівняння нічного тиску з еталоном
   
   /*!
   \return Булевий результат порівняння енцефалограми з еталоном
   \param index індекс елемента вектору з кінця
   */
   bool CompareEncephalogram(int index);///<Порівняння енцефалограми з еталоном
   
   /*!
   \return Булевий результат порівняння загального аналізу сечі з еталоном
   \param index індекс елемента вектору з кінця
   */
   bool CompareUrinalysis(int index);///<Порівняння загального аналізу сечі з еталоном
   
   /*!
   \return Булевий результат порівняння каплограми з еталоном
   \param index індекс елемента вектору з кінця
   */
   bool CompareCaplogramme(int index);///<Порівняння каплограми з еталоном

   /*!
   \return Булевий результат порівняння 
   \param obj - об*єкт класу SystemE_Health
   \param month - к-ть місяців для порівняння
   */
   bool operator == (int month);///<Перевантаження оператора порівняння

   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   SystemE_Health();///<конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param engraphy результат енцелографії
   \param etal вектор еталонних значень результатів аналізів
   \param invit текст запрошення на огляд
   \param recom текст рекомендації
   */
   SystemE_Health(vector <float> etal, string recom);///<конструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~SystemE_Health();///<деструктор

   vector<E_Card> cards;///<вектор об'єктів
   vector<SmartToilet> toilet;///<вектор об'єктів
   vector<SmartBracelet> bracelet;///<вектор об'єктів
   vector<SmartBed> bed;///<вектор об'єктів

protected:
private:
   vector<float> etalon;///<вектор з еталонними значеннями аналізів
   std::string recomendation;///<текст рекомендації
   std::string invitationToDoctor="You need in undergo medical examination in your treatment doctor";///<текст запрошення на огляд
   std::string invitationToClinic="You need in undergo medical examination in your clinic";///<текст запрошення на огляд

};

#endif