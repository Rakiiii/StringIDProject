#pragma once
#ifndef STRINGID_STRINGFORCID_H

#define STRINGID_STRINGFORCID_H

#include "String.h"
#include "pch.h"

class StringForCId : public String
{

private:

	//счетчик вызова конструктора копированния
	  static int copyConstractorCounter;

    //метод проверки всех символов на допустимость
	  const char* checkAllChars(const char* string)const;
	  const char checkAllChars(const char string)const;

	 //метод добавления символа
	 void addChar(const char chr);
	 
	
public:

	//метод вывода счетчика вывода конструктора копированния
	static void printCounter();

	//конструктор пустой строки
	StringForCId();

	//конструктор принимающий массив символов
	StringForCId(const char *string);

	//конструктор принимающий на вход символ
	StringForCId(const char ch);

	//конструктор копированния
	StringForCId(const StringForCId &string);


	//деструктор
	~StringForCId();

	//перевод в верхний регистр
	StringForCId& toUpper();

	//перевод в нижний регистр
	StringForCId& toLower();

	//поиск первого вхождения в подстроку
	int find(const StringForCId &string)const;
	int find(const char string)const;
	int find(const char *string)const;

	//перегрузка оператора присваивания
	StringForCId& operator=(const StringForCId &rightString);

	//перегрузка операции конкатенации
	StringForCId operator+(const StringForCId &rightString);
	

	//перегрузка оператора сравнения
	const bool operator>(const StringForCId &rightString)const;
	const bool operator<(const StringForCId &rightString)const;

	//перегрузка операции вычитания
	StringForCId operator-(const StringForCId &rightString)const;


};


#endif // !STRINGID_STRINGFORCID_H
