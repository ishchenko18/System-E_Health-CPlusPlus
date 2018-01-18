
#if !defined(__E_Mediciana_SmartBed_h)
#define __E_Mediciana_SmartBed_h

/*!
\brief Клас відповідає за зняття результатів аналізів під час сну
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class SmartBed
{
public:
	/*!
	\param encel - результат енцефалограми 
	\param pulse - результат нічного пульсу 
	\param pressure - результат нічного тиску
	*/
   void TakeTests(bool encel, short pulse, short pressure);///<Метод відповідає за зняття аналізів

   /*!
   \return Результат енцефалограми
   */
   bool GetEncephalography();///<Гетер для енцелографіки користувача

   /*!
   \return Результат нічного пульсу
   */
   short GetPulse();///<Гетер для нічного пульсу користувача

   /*!
   \return Результат нічного тиску
   */
   short GetPressure();///<Гетер для нічного тиску користувача
   
   SmartBed operator =(SmartBed bed);///<Перевантаження оператора присвоєння

   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param Без параметрів
   */
   SmartBed();///<Конструктор за змовчуванням
   /*!
   Виведення повідомлення, що конструктор спрацював\n
   Початкова ініціалізація атрибутів
   \param engraphy результат енцелографії
   \param _pulse нічний пульс
   \param _pressure нічний тиск
   */
   SmartBed(bool engraphy, short _pulse, short _pressure);///<Конструктор інінціалізації
   /*!
   Виведення повідомлення, що деструктор спрацював
   \param Без параметрів
   */
   ~SmartBed();///<Деструктор

protected:
private:
	/*!
	\param encel - результат енцефалограми pulse - результат нічного пульсу pressure - результат нічного тиску
	*/
   bool encephalography;///<Результат енцелограми
   short pulse;///<Нічний пульс
   short pressure;///<Нічний тиск


};

#endif