#if !defined(__E_Mediciana_Clinic_h)
#define __E_Mediciana_Clinic_h
#include <string>//підключення заголовкового файлу для роботи з класом string
#include <vector>//підключення заголовкового файлу для роботи з класом vector

using namespace std;

class Doctor;//підключення класу

/*!
\brief Клас описує клініку в якій обстежується користувач
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class Clinic//інтерфейс класу
{
public:
   void SetListOfDoctor();///<Сетер для списку лікарів клініки(Об*єднує прізвище та ім*я лікаря, а потім записує до списку лікарів
   void GetListOfDoctor();///<Гетер для списку лікарів клініки
   
   /*!
   \return Назва клініки
   \param Без параметрів
   */
   static const string GetName()///<Статична та константна функція для отримання назви клініки
   {
	   return name;
   }
   
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   Clinic();///<Конструктор за змовчуванням
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~Clinic();///<Деструктор
  
   vector<Doctor> doctor;///<Вектор об'єктів

private:
   static const string name;///<Назва клініки
   vector <string> listOfDoctors;///<Вектор лікарів клініки
};

#endif