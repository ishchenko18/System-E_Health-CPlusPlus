

#if !defined(__E_Mediciana_SmartToilet_h)
#define __E_Mediciana_SmartToilet_h

/*!
\brief Клас відповідає за зняття основних внутрішніх аналізів
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class SmartToilet
{
public:
	/*!
	\param urinal - результат загального аналізу сечі
	\param caplograme - результат каплограми
	*/
   void TakeTests(float urinal,float caplograme);///<Метод відповідає за зняття аналізів

   /*!
   \param urinal - результат загального аналізу сечі
   \param caplograme - результат каплограми
   */
   void TakeTests(short caplograme);///<Перевантажений метод TakeTests

   /*!
   \return Результат загального аналізу сечі
   */
   float GetUrinalysis();///<Гетер для ЗАС користувача

   /*!
   \return Результат закаплограми
   */
   float GetCaplogramme();///<Гетер для каплограмми користувача
   
   SmartToilet operator +(int  i);///<Перевантаження бінарного оператора 
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   SmartToilet();///<конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param urin результат аналізів сечі
   \param caplo результат каплограми
   */
   SmartToilet(float urin, float caplo);///<конструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~SmartToilet();///<деструктор

protected:
private:
   float urinalysis;///<результат аналізу сечі
   float caplogramme;///<результат аналізу каплограми
};

#endif