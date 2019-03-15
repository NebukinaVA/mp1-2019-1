#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iosfwd>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <memory.h>

#define n 1000

using namespace std;

class Menu
{
	int item;
	int lastitem;
	char *command[n];
public:
	Menu()
	{
		item = 0;
		char** command = new char*[item]; // !
	}
	Menu(int _n)
	{
		item = _n;
		char** command = new char*[item];
		for (int i = 0; i < item; i++)
			command[i] = new char[n]; // !
	}
	void SetSize(int size)
	{
		delete[] command;
		item = size;
		char *command = new char[item];
		Menu(item);
	}
	int GetSize()
	{
		return item;
	}
	void SetStr(int i, char &s)
	{
		char *str1 = new char[n];
		char *str2 = new char[n];
		*str1 = command[i][n];
		*str2 = s;
		strcpy(str1, str2);
		command[i][n] = *str1;
		delete[] str1, str2;
		lastitem = i;
	}
	int GetItem()
	{
		return lastitem;
	}
	void GetMenu()
	{
		for (int i = 0; i < item; i++)
		{
			cout << command[i][n] << "\n";
		}
	}
};