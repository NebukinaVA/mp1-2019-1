#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

class Methods
{
	int size;
	int numb;
	int bull = 0;
	int cow = 0;
	vector <int> number;
	vector <int> comp;
	int attempt = 0;
public:
	Methods() 
	{
	}
	Methods(int n)
	{
		size = n;
		number.reserve(size);
		comp.reserve(size);
	}
	void ChangeSize(int _size)
	{
		size = _size;
	}
	void CreateNumber() // число компьютера
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
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
	vector <int> RetSplit()
	{
		return number;
	}
	void SplitNumber(int _numb) // разбить число игрока на разряды
	{
		int a = _numb;
		for (int i = number.size() - 1; i >= 0; i--)
		{
			int d = pow(10, i);
			number[i] = a / d;
			a %= d;
		}
	}
	int CountBulls()
	{
		SplitNumber(numb);
		for (int i = 0; i < size; i++)
		{
			if (number[i] == comp[i])
				bull++;
		}
		return bull;
	}
	int CountCows()
	{
		SplitNumber(numb);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if ((i != j) && (number[i] == comp[j]))
					cow++;
			}
		}
		return cow;
	}
	void Attempts()
	{
		attempt++;
	}
};

class BullsAndCows: public Methods
{
	int size;
//	Methods game = Methods(n);
public:
	BullsAndCows()
	{
		cout << "Welcome to the game 'Bulls and Cows'!\n";
	}
	void GetSize()
	{
		cout << "Enter the size of nubmer: ";
		cin >> size;
		ChangeSize(size);
	}
	void EnterNumber()
	{
		bool flag = true;
		int numb;
		while (flag)
		{
			cout << "Enter your number: ";
			cin >> numb;
			if ((numb < pow(10, (size - 1))) || (numb >= pow(10, (size + 1))))
				cout << "Number doesn't sync with chosen size.\n";
			SplitNumber(numb);
			vector <int> points = RetSplit();
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if ((i = j) && (points[i] == points[j]))
					{
						flag = true;
						cout << "Digits match.\n";
					}
					else flag = false;
				}
			}
		}
	    GetNumber(numb);
		SplitNumber(numb);
	}
	void PrintResult()
	{
		int bull = CountBulls();
		int cow = CountCows();
		if (bull == size)
		{
			cout << "Congrats! The made-up number is:" << numb << endl;
		}
		cout << "Bulls: " << bull << "   Cows: " << cow << endl;
	}
	void GamingProcess()
	{
		GetSize();
		EnterNumber();

	}
};
