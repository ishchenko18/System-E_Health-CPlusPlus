#if !defined(__E_Mediciana_SmartBracelet_h)
#define __E_Mediciana_SmartBracelet_h

/*!
\brief Клас відповідає за зняття аналізів вдень
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class SmartBracelet//інтерфейс класу
{
public:
	/*!
	\param pulse - результат денного пульсу 
	\param pressure - результат денного тиску
	*/
   void TakeTests(short pulse,short pressure);///<Метод відповідає за зняття аналізів

   /*!
   \return Результат денного тиску
   */
   short GetPulse();///<Гетер денного пульсу користувача

   /*!
   \return Результат денного тиску
   */
   short GetPressure();///<Гетер денного тиску користувача
   
   SmartBracelet& operator ++();///<Перевантаження унарного оператора постфіксного інкременту

   SmartBracelet operator ++(int);///<Перевантаження унарного оператора префіксного інкременту

   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   SmartBracelet();///<конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param _pulse денний пульс
   \param _pressure денний тиск
   */
   SmartBracelet(short _pulse, short _pressure);///<конструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~SmartBracelet();///<деструктор

protected:
private:
   short pulse;///<Денний пульс
   short pressure;///<Денний тиск

};

#endif