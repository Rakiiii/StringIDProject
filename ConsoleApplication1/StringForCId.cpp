#include "StringForCId.h"
#include "String.h"
#include "pch.h"
using namespace std;


//поиск минимальнорого из 2 чисел

const char* StringForCId::checkAllChars(const char* string) const
{
	if (strlen(string) > 31)
	{
		return nullptr;
	}
	if (string[0] != '_' && (!(string[0] >= 'a' && string[0] <= 'z') || !(string[0] >= 'A' && string[0] <= 'Z')))
	{
		return nullptr;
	}
	for (int i = 1; i < strlen(string); i++)
	{
		if (string[i] != '_' && 
			!(string[i] >= 'a' && string[i] <= 'z') &&
			!(string[i] >= 'A' && string[i] <= 'Z') && 
			!(string[i] >= '0' && string[i] <= '9'))
		{
			return nullptr;
		}
	}
	
	return string;
}

const char StringForCId::checkAllChars(const char string) const
{
	if (string != '_' && (!(string >= 'a' && string <= 'z') || !(string >= 'A' && string <= 'Z')))
	{
		return NULL;
	}
	return string;
}

const String StringForCId::checkAllChars(const String string)const
{
	if (this->checkAllChars(((StringForCId)string)._string) == nullptr)
		return String();
	else return string;
}

//конструктор пустой строки
StringForCId::StringForCId():String()
{}

//конструктор из символа
StringForCId::StringForCId(const char ch):String(this->checkAllChars(ch))
{}

//конструктор из строки
StringForCId::StringForCId(const char *string):String(this->checkAllChars(string))
{}

//конструктор копированния
StringForCId::StringForCId(const StringForCId &string):String((String)string)
{}

//конструктор из String
StringForCId::StringForCId(const String &string):String(this->checkAllChars(string))
{}

//диструктор
StringForCId::~StringForCId()
{}

//перевод всей строки в верхний регистр
void StringForCId::toUpper()
{
	for (int i = 0; i < this->length; i++)
	{
		if(this->_string[i]>='a' && this->_string[i] <= 'z')
		this->_string[i] -= 32;
	}
}

//перевод в нижний регистр
void StringForCId::toLower()
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->_string[i] >= 'A' && this->_string[i] <= 'Z')
			this->_string[i] += 32;
	}
}

//номер первого вхождения
template<class T>
int StringForCId::find(const T &string)const
{
	//ищем символ первого вхождения
	char *res = strstr(this->_string,((StringForCId)string)._string);

	//если нет таких под строк возвращаем 0
	if (res == NULL)return NULL;
	//если есть возвразаем разницу в номере между первым и найденным символами
	else return res - this->_string;
}
int StringForCId::find(const char string)const
{
	char *res = strchr(this->_string, string);

	//если нет таких под строк возвращаем 0
	if (res == NULL)return NULL;
	//если есть возвразаем разницу в номере между первым и найденным символами
	else return res - this->_string;
}

int StringForCId::find(const char *string)const
{
	char *res = strstr(this->_string, string);

	//если нет таких под строк возвращаем 0
	if (res == NULL)return NULL;
	//если есть возвразаем разницу в номере между первым и найденным символами
	else return res - this->_string;
}

//перегрузка оператора присваивания
StringForCId& StringForCId::operator=(const StringForCId &rightString)
{
	//если присваиваем к не нулевой строке то очищаем память и обнуляем указтель
	if (this->_string != nullptr)
	{
		delete[] this->_string;
		this->_string = nullptr;
	}
	//если справа 0 строка
	if (rightString._string == nullptr)
	{
		//то длинна тоже 0
		this->length = 0;
	}
	else
	{
		//если не нулевая строка, то копируем длинну
		this->length = rightString.length;

		//выделяем память и копируем строку
		this->_string = new char[this->length];
		strcpy(this->_string, rightString._string);
	}
	return *this;
}

//перегрузка операции конкатенации
StringForCId StringForCId::operator+(const StringForCId &rightString)const
{
	//случай если одна их строк пустая
	if (rightString._string == nullptr)return *this;
	if (this->_string == nullptr)return rightString;

	//создаем результируюшую строку
	StringForCId newString;

	//получаем длину новой строки
	newString.length = this->length + rightString.length - 1;

	//выделяем память строки
	newString._string = new char[newString.length];

	//складываем непосредственно строки
	strcpy(newString._string, this->_string);
	strcpy(newString._string + this->length, rightString._string);

	//возвращаем наш объект
	return newString;
}

//перегрузка оператора сравнения
const bool StringForCId::operator>(const StringForCId &rightString)const
{
	//если обе строки пустые то сразу возвращаем 0
	if (this->_string == nullptr && rightString._string == nullptr)return false;

	//если левая строка пустая ,а правая нет,то возарвщаем 0
	if (this->_string == nullptr)return false;

	//если правая строка пустая а левая нет,то возвращаем 1
	if (rightString._string == nullptr)return true;

	//храним минимальную длинну из 2 строк
	int minLength = 0;

	//определяем мин длинну
	if (rightString.length > this->length) minLength = this->length;
	else  minLength = rightString.length;

	//проверяем все символы
	for (int i = 0; i < minLength; i++)
	{
		//если код символа на i позиции в левой строке меньше или равен коду символа во второй строке
		//то возрващаем 0
		if (this->_string[i] <= rightString._string[i])return false;
	}

	//иначе возвращаем 1
	return true;
}

const bool StringForCId::operator<(const StringForCId &rightString)const
{
	//если обе строки пустые то сразу возвращаем 0
	if (this->_string == nullptr && rightString._string == nullptr)return false;

	//если левая строка пустая ,а правая нет,то возарвщаем 1
	if (this->_string == nullptr)return true;

	//если правая строка пустая а левая нет,то возвращаем 0
	if (rightString._string == nullptr)return false;

	//храним минимальную длинну из 2 строк
	int minLength = 0;

	//определяем мин длинну
	if (rightString.length > this->length) minLength = this->length;
	else  minLength = rightString.length;

	//проверяем все символы
	for (int i = 0; i < minLength; i++)
	{
		//если код символа на i позиции в левой строке больше или равен коду символа во второй строке
		//то возрващаем 0
		if (this->_string[i] >= rightString._string[i])return false;
	}
	return true;
}

//метод добавления символа к строке
void StringForCId::addChar(const char chr)
{
	//создаем строку из символа
	StringForCId plusString(chr);

	//складываем строки
	*this = *this + plusString;
}

//перегрузка операции вычитания
StringForCId StringForCId::operator-(const StringForCId &rightString)const
{
	//если одна из строк пустая то возвращаем левую строку
	if (this->_string == nullptr || rightString._string == nullptr)return *this;

	//создаем пустую результируюшую строку
	StringForCId resString;

	//перебираем все символы в правой строке
	for (int i = 0; i < this->length; i++)
	{
		//если символа из левой строки нет в правой строке то приписываем его к результирующей
		if (strchr(rightString._string, this->_string[i]) == NULL)resString.addChar(this->_string[i]);
	}
	return resString;
}

void StringForCId::printString()const
{
	cout << this->_string << endl;
}

