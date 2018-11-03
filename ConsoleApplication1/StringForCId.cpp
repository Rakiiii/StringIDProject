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

const String StringForCId::checkAllChars(const String string)
{
	return 
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
StringForCId::StringForCId(const StringForCId &string):String()