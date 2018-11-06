// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "String.h"
#include "StringForCId.h"
#include <conio.h>
using namespace std;

int main()
{
	typedef String * StringPtr;
	typedef StringForCId* StringForCIdPtr;
	int k = 0 , j= 0 , h = 0;
	char  b = ' ';
	char *read = new char[1024];


	system("cls");
	cout << "print amount of strings" << endl;
	cin >> k;
	StringPtr *mas = new StringPtr[k];

	for (int i = 0; i < k; i++)
	{
		mas[i] = nullptr;
	}

	while (true)
	{
		system("cls");
		cout << "1.Add string" << endl << "2.Plus strings" << endl << "3.Cast to upper case" << endl
			<< "4.Compare strings" << endl << "5.Output all strings"
			<< endl << "6.cast to lower case" << endl << "7.Find string" << endl
			<< "8.Substraction strings" << endl<<"9.Clear string"<<endl<<"a.Equal strings"<<endl<<"0.Exit" << endl;
		StringForCId::printCounter();
		char choice = _getch();
		switch (choice)
		{
		case '1':
			system("cls");
			while (cin.get() != '\n');
			cout << "print string number" << endl;
			cin >> h;
			if (h > k)break;
			cout << "print string" << endl;
			cin >> read;
			mas[h - 1] = new StringForCId(read);
			break;
		case'2':
			system("cls");
			while (cin.get() != '\n');
			cout << "print number of first string" << endl;
			cin >> j;
			if (j > k)break;
			cout << "print number of second string" << endl;
			cin >> h;
			if (h > k)break;
			cout << "string 1:";
			mas[j - 1]->printString();
			cout << endl << "string 2:";
			mas[h - 1]->printString();
			cout << endl << "result:";
			(*(StringForCIdPtr)mas[j - 1] + *(StringForCIdPtr)mas[h - 1]).printString();
			system("pause");
			break;
		case'3':
			system("cls");
			while (cin.get() != '\n');
			cout << "print string number" << endl;
			cin >> h;
			if (h > k)break;
			((StringForCIdPtr)mas[h - 1])->toUpper().printString();
			system("pause");
			break;
		case'4':
			system("cls");
			while (cin.get() != '\n');
			cout << "print number of first string" << endl;
			cin >> j;
			if (j > k)break;
			cout << "print number of second string" << endl;
			cin >> h;
			if (h > k)break;
			cout << "string 1:";
			mas[j - 1]->printString();
			cout << endl << "string 2:";
			mas[h - 1]->printString();
			cout << "print compare operarion" << endl;
			cin >> b;
			if (b == '>')
			{
				if (*(StringForCIdPtr)mas[j - 1] > *(StringForCIdPtr)mas[h - 1])
					cout << "String 1 is bigger then string 2" << endl;
				else cout << "String 1 isn't bigger then string 2" << endl;
			}
			else
			{
				if (*(StringForCIdPtr)mas[j - 1] < *(StringForCIdPtr)mas[h - 1])
					cout << "String 1 is smaller then string 2" << endl;
				else cout << "String 1 isn't smaller then string 2" << endl;
			}
			system("pause");
			break;
		case'5':
			system("cls");
			for (int i = 0; i < k; i++)
			{
				if(mas[i] != nullptr) mas[i]->printString();
			}
			system("pause");
			break;
		case'6':
				system("cls");
				while (cin.get() != '\n');
				cout << "print string number" << endl;
				cin >> h;
				if (h > k)break;
				((StringForCIdPtr)mas[h - 1])->toLower().printString();
				system("pause");
				break;
		case'7':
			system("cls");
			while (cin.get() != '\n');
			cout << "print string number" << endl;
			cin >> h;
			if (h > k)break;
			cout << "String is:";
			mas[h - 1]->printString();
			cout << "print symbol" << endl;
			cin >> b;
			cout << "symbol finded at position:" << ((StringForCIdPtr)mas[h - 1])->find(b) << endl;
			system("pause");
			break;
		case '8':
			system("cls");
			while (cin.get() != '\n');
			cout << "print number of first string" << endl;
			cin >> j;
			if (j > k)break;
			cout << "print number of second string" << endl;
			cin >> h;
			if (h > k)break;
			cout << "string 1:";
			mas[j - 1]->printString();
			cout << endl << "string 2:";
			mas[h - 1]->printString();
			cout << endl << "result:";
			(*(StringForCIdPtr)mas[j - 1] - *(StringForCIdPtr)mas[h - 1]).printString();
			system("pause");
			break;
		case'9':
			system("cls");
			while (cin.get() != '\n');
			cout << "print string number" << endl;
			cin >> h;
			if (h > k)break;
			mas[h - 1]->clearString();
			break;
		case'a':
			system("cls");
			while (cin.get() != '\n');
			cout << "print number of first string" << endl;
			cin >> j;
			if (j > k)break;
			cout << "print number of second string" << endl;
			cin >> h;
			if (h > k)break;
			cout << "string 1:";
			mas[j - 1]->printString();
			cout << endl << "string 2:";
			mas[h - 1]->printString();
			cout << endl << "result:";
			(*(StringForCIdPtr)mas[j - 1] = *(StringForCIdPtr)mas[h - 1]).printString();
			system("pause");
			break;
		case'0':
			system("cls");
			StringForCId::printCounter();
			system("pause");
			return 0;
		default:break;
		}

	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
