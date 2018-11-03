#include "StringForCId.h"
using namespace std;


const char* StringForCId::checkAllChars(const char* string)
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

const char StringForCId::checkAllChars(const char string)
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