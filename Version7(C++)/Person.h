#ifndef PERSON_H
#define PERSON_H
#include <string>

/*!
\brief Клас, що використовується для наслідування
\author Ishchenko Vladyslav
\version 7
\date 8 грудня 2017
*/
class Person
{
	public:
		Person();///<Конструктор за змовчуванням
		Person(std::string fname, std::string sname);///<Конструктор ініціалізації
		/*!
		Функція для виведення імені та прізвища людини
		*/
		virtual void ShowInfo();
		/*!
		\return ім*я людини
		*/
		std::string GetFirstname();///<Гетер для отримання імені людини
		/*!
		\param fname ім*я людини
		*/
		void SetFirstname(std::string fname);///<Сетер для встановлення імені людини
		/*!
		\return прізвище людини
		*/
		std::string GetSurname();///<Гетер для отримання прізвища людини
		/*!
		\param sname прізвище людини
		*/
		void SetSurname(std::string fname);///<Сетер для встановлення прізвища людини
protected:
		std::string firstname,///<ім'я людини
			surname;///<прізвище людини
	private:

};
#endif