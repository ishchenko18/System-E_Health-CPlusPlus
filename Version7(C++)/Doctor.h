#if !defined(__E_Mediciana_Doctor_h) DOCTOR_H
#define __E_Mediciana_Doctor_h DOCTOR_H
#include <string>
#include <vector>
#include <iostream>
#include "Person.h"

using namespace std;

/*!
\brief Клас відповідає за проведення оглядів користувача та встановлення діагнозів.
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class Doctor : public Person
{
public:
   string MakeAppointment(void);///<Метод відповідає за призначення користувачу лікування лікарем 
   string Examination(void);///<Метод відповідає за проведення медичного огляду користувача
   /*!
   \param special спеціалізація лікуючого лікаря
   */
   void SetSpecialization(string special);///<Сетер для встановлення спеціалізації лікуючого лікаря
   /*!
   \param qualific рівень кваліфікації лікуючого лікаря
   */
   void SetQualification(int qualific);///<Сетер для встановлення рівня кваліфікації лікуючого лікаря

   friend ostream& operator << (ostream& os, const Doctor& doc);///<Перевантажений оператор виведення
   friend istream& operator >> (istream& is, Doctor& doc);///<Перевантажений оператор введення
   /*!
   Виведення імені та прізвища лікаря
   */
   void ShowInfo() override;///<Віртуальна функція виведення інформації
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   Doctor();///<Конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param fname ім*я користувач
   \param sname прізвище користувача
   \param special спеціалізація лікаря
   \param  qualific рівень кваліфікації лікаря
   */
   Doctor(string fname, string sname, string special, int qualific);///<Конструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~Doctor();///<Деструктор

protected:
private:
   string specialization;///<Спеціалізація лікаря
   int qualification;///<Рівень кваліфікації лікаря
};

#endif