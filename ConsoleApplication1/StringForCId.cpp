#include "StringForCId.h"
#include "String.h"
#include "pch.h"
using namespace std;

//инициализируем счетчик конструктора копированния
int StringForCId::copyConstractorCounter = 0;

//метод вывода счетчика конструктора окпированния
void StringForCId::printCounter()
{
	cout << "Copy constractor called " << copyConstractorCounter << " times" << endl;
}

//проверям строку на допустимые символы
const char* StringForCId::checkAllChars(const char* string) const
{
	//Если длина больше допустимой для с идентификатора
	if (strlen(string) > 31)
	{
		//возвращаем пустую строку
		return nullptr;
	}

	//если первый сивол не nondigit
	if (string[0] != '_' && (!(string[0] >= 'a' && string[0] <= 'z') && !(string[0] >= 'A' && string[0] <= 'Z')))
	{ 
		//возвращаем пустую строку
		return nullptr;
	}

	//проходим всю строку
	for (int i = 1; i < strlen(string); i++)
	{
		//если есть технический символ языка
		if (string[i] != '_' && 
			!(string[i] >= 'a' && string[i] <= 'z') &&
			!(string[i] >= 'A' && string[i] <= 'Z') && 
			!(string[i] >= '0' && string[i] <= '9'))
		{
			//возвращаем нулевую строку
			return nullptr;
		}
	}
	
	//в любом ином случае возвращаем исходную строку
	return string;
}

//проверяем символ на допустимость
const char StringForCId::checkAllChars(const char string) const
{
	//если сивол не nondigit
	if (string != '_' && (!(string >= 'a' && string <= 'z') && !(string >= 'A' && string <= 'Z')))
	{
		//возвращаем NULL
		return NULL;
	}

	//иначе возвращем символ
	return string;
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
{
	copyConstractorCounter++;
}


//диструктор
StringForCId::~StringForCId()
{}

//перевод всей строки в верхний регистр
StringForCId& StringForCId::toUpper()
{
	//проходим всю строку
	for (int i = 0; i < this->length - 1; i++)
	{
		//если прописная буква
		if(this->_string[i]>='a' && this->_string[i] <= 'z')
			//переводим символ по askii в заглавный
		this->_string[i] -= 32;
	}
	//возвращаем измененный объект
	return *this;
}

//перевод в нижний регистр
StringForCId& StringForCId::toLower()
{
	//проходим всю строку 
	for (int i = 0; i < this->length - 1; i++)
	{
		//если заглавная буква
		if (this->_string[i] >= 'A' && this->_string[i] <= 'Z')
			//переводим по askii в прописной
			this->_string[i] += 32;
	}
	//возвращаем изменненый объект
	return *this;
}

//номер первого вхождения
int StringForCId::find(const StringForCId &string)const
{
	//если хоть что то пустое то возвращаем NULL
	if (this->_string == nullptr)return -1;
	if (string._string == nullptr)return -1;

	//ищем символ первого вхождения
	char *res = strstr(this->_string,string._string);

	//если нет таких под строк возвращаем 0
	if (res == NULL)return -1;
	//если есть возвразаем разницу в номере между первым и найденным символами
	else return res - this->_string + 1;
}
int StringForCId::find(const char string)const
{
	//если хоть что то пустое то возвращаем NULL
	if (this->_string == nullptr)return -1;
	
	//ищем символ первого вхождения
	char *res = strchr(this->_string, string);

	//если нет таких под строк возвращаем 0
	if (res == NULL)return -1;
	//если есть возвразаем разницу в номере между первым и найденным символами
	else return res - this->_string + 1;
}

int StringForCId::find(const char *string)const
{
	//если хоть что то пустое то возвращаем NULL
	if (this->_string == nullptr)return -1;
	if (string == nullptr)return -1;

	//ищем символ первого вхождения
	char *res = strstr(this->_string, string);

	//если нет таких под строк возвращаем 0
	if (res == NULL)return -1;
	//если есть возвразаем разницу в номере между первым и найденным символами
	else return res - this->_string + 1;
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
StringForCId StringForCId::operator+(const StringForCId &rightString)
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
	strcpy(newString._string + this->length-1, rightString._string);

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
	if (rightString.length > this->length) minLength = this->length - 1;
	else  minLength = rightString.length - 1;

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
	if (rightString.length > this->length) minLength = this->length - 1;
	else  minLength = rightString.length - 1;

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

