#if !defined(__E_Mediciana_ChipForIdentification_h)
#define __E_Mediciana_ChipForIdentification_h
#include <string>//підключення заголовкового файлу для роботи з класом string
#include <vector>//підключення заголовкового файлу для роботи з класом vector

using namespace std;//оголошення простору імен

/*!
\brief Клас відповідає за роботу з чипом
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class ChipForIdentification//інтерфейс класу
{
public:   
   string GetFirstname();///<Гетер для імені користувача
   /*!
   \param fname ім*я користувач
   */
   void SetFirstname(string fname);///<Сетер для імені користувача
   string GetSurname();///<Гетер для прізвища користувача
   /*!
   \param sname прізвище користувач
   */
   void SetSurname(string sname);///<Сетер для прізвища користувача
   int GetBirthday();///<Гетер для дати народження користувача
   /*!
   \param _birthday дата народження користувача
   */
   void SetBirthday(int _birthday);///<Сетер для дати народження користувача
   int GetTerm();///<Гетер для терміну дії чипу користувача
   /*!
   \param _term термін дії чипу
   */
   void SetTerm(int _term);///<Сетер для терміну дії чипу користувача

   operator int() const//неявне перетворення типів
   {
	   return birthday;
   }

   explicit operator string() const//явне перетворення типів
   {
	   return firstname;
   }

   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   ChipForIdentification();///<Конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param fname ім*я користувач
   \param sname прізвище користувача
   \param _birthday дата народження
   \param  term термін дії чипу
   */
   ChipForIdentification(string fname, string sname, int _birthday, int _term);///<Конструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~ChipForIdentification();///<Деструктор

protected:
private:
	string firstname, ///<Ім*я користувач
		surname;///<Прізвище користувача
	int birthday;///<Дата народження 
	int term;///<Термін дії чипу


};

#endif