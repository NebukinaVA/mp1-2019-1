#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class BullsCows
{
	int numb;
	int bulls = 0;
	int cows = 0;
	vector <int> number;
	vector <int> comp;
	int attempt = 0;
public:
	BullsCows()
	{
	}
	BullsCows(int n)
	{
		number.reserve(n);
		comp.reserve(n);
	}
	~BullsCows()
	{
		//~number;
		//~comp;
	}
	void CreateNumber() // число компьютера
	{
		for (int i = 0; i < comp.size(); i++)
		{
			comp[i] = (rand() % 9 + 1);
			for (int j = 0; j < i; j++)
			{
				while (comp[i] == comp[j])
				{
					comp[i] = (rand() % 9 + 1);
				}
			}
		}
	}
	void GetNumber(int n) //число игрока
	{
		numb = n;
	}
	void SplitNumber() // разбить на разряды
	{
		int a;
		for (int i = number.size() - 1; i >= 0; i--)
		{
			int d = pow(10, i);
			number[i] = a / d;
			a %= d;
		}
	}
	int CountBulls()
	{

	}

};
