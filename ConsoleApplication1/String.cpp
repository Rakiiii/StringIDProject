#include "String.h"
using namespace std;

//обнуление строки
void String::nullString()
{
	this->length = 0;

	this->_string = nullptr;
}
//конструктор пустой строки

String::String()
{
	this->nullString();
}

//конструктор копированния

String::String(const String &secondString)
{
	//если строка не нулевая
	if (secondString._string != nullptr)
	{
		//копируем длину
		this->length = secondString.length;

		//выделяем память под строку
		this->_string = new char[this->length];

		//копируе саму строку
		strcpy(this->_string, secondString._string);
	}
	else
	{
		//создаем нулевую строку
		this->nullString();
	}
}


//конструктор новой строки
String::String(const char *newString)
{
	if (newString != nullptr)
	{
		//длина равная количеству символов
		this->length = strlen(newString) + 1;

		//выделяем память
		this->_string = new char[this->length];

		//копируем все символы
		strcpy(this->_string, newString);
	}
	else
	{
		this->nullString();
	}
}


String::String(const char ch)
{
	//если символ есть
	if (ch != NULL)
	{
		//строка содержит символ и закрывающий 0
		this->length = 2;

		//выделяем память
		this->_string = new char[this->length];

		//заполням строку
		this->_string[0] = ch;
		this->_string = '\0';
	}
	else
	{
		//обнуляем строку
		this->nullString();
	}
}

//очизение строки

void String::clearString()
{
	if (this->_string != nullptr)
	{
		//освобождаем память
		delete[] this->_string;

		//обнуляем строку
		this->nullString();
	}
}

//геттер для длинны строки

int String::getLength()
{
	return this->length;
}

//деструктор

 String::~String()
{
	//если указатель не нулевой
	if (this->_string != nullptr)
	{
		//освобождаем выделенную под строку память 
		delete[] this->_string;

		//обнуляем указатель,память которого освободили
		this->_string = nullptr;
	}
}