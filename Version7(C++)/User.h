#if !defined(__E_Mediciana_User_h) USER_H
#define __E_Mediciana_User_h USER_H

#include <string>
#include "Person.h"

using namespace std;

class Doctor;
class SystemE_Health;
class ChipForIdentification;

/*!
\brief Клас описує користувача системи
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class User : public Person
{
public:
   void Survey(void);///<метод відповідає за проходження обстеження користувачем
   void VisitDoctor(void);///<метод відповідає за відвідування лікаря користувачем
   void ShowInfo() override;///<метод виводить прізвище та ім*я користувача

   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   User();///<конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param engraphy результат енцелографії
   \param fname ім'я користувача
   \param sname прізвище користувача
   */
   User(string fname, string sname);///<конструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~User();///<деструктор

   ChipForIdentification* chipForIdentification;///<посилання на об'єкт
   Doctor* doctor;///<посилання на об'єкт
   SystemE_Health* systemE_Health;///<посилання на об'єкт

protected:
private:
   
};

#endif