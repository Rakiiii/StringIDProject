#pragma once
#ifndef STRINGID_STRINGFORCID_H

#define STRINGID_STRINGFORCID_H

#include "String.h"

class StringForCId : public String
{

private:
    //метод проверки всех символов на допустимость
	 const char* checkAllChars(const char* string);
	 const char checkAllChars(const char string);
	 const String checkAllChars(const String string);
	 
	
public:
	//конструктор пустой строки
	StringForCId();

	//конструктор принимающий массив символов
	StringForCId(const char *string);

	//конструктор принимающий на вход символ
	StringForCId(const char ch);

	//конструктор копированния
	StringForCId(const StringForCId &string);

	//конструктор принимающий на вход строку
	StringForCId(const String &string);

	//деструктор
	~StringForCId();

	//перевод в верхний регистр
	void toUpper();

	//перевод в нижний регистр

	void toLower();

	//поиск первого вхождения в подстроку

	int find(const StringForCId &string);

	//перегрузка оператора присваивания
	StringForCId& operator=(const StringForCId &rightString);

	//перегрузка операции конкатенации

	StringForCId operator+(const StringForCId &rightString);

	//перегрузка оператора сравнения
	const bool operator>(const StringForCId &rightString);
	const bool operator<(const StringForCId &rightString);

	//перегрузка операции вычитания

	StringForCId operator-(const StringForCId &rightString);

};


#endif // !STRINGID_STRINGFORCID_H
