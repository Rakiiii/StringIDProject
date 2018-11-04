#pragma once
#ifndef STRINGID_STRING_H


#define STRINGID_STRING_H
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string.h>
#include "pch.h"

class String
{
protected:
	char *_string;
	int length;
private:
	void nullString();

public:

	//конструктор

	String();

	//конструктор копированния

	String(const String &secondString);

	//конструктор новой строки

	String(const char *newString);

	//конструктор строки из символа

	String(const char ch);

	//очистка строки

	void clearString();

	//геттер для длины строки
	
	int getLength();

	//диструктор
	virtual ~String();


};
#endif 
