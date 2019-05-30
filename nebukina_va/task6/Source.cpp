#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

class Methods
{
	int size;
	int numb;
	int bull;
	int cow;
	vector <int> number;
	vector <int> comp;
	int attempt = 0;
//	srand(time(NULL));
	srand(0);
public:
	Methods()
	{
	}
	Methods(int n)
	{
		size = n;
	}
	void ChangeSize(int _size)
	{
		size = _size;
	}
	void CreateNumber() // число компьютера
	{
		for (int i = 0; i < size; i++)
		{
			comp.push_back(rand() % 9 + 1);
			for (int j = 0; j < i; j++)
			{
				while (comp[i] == comp[j])
				{
					comp.push_back(rand() % 9 + 1);
				}
			}
		}
	//	cout << comp[0] << comp[1] << comp[2] << "made up number\n";
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
		number.clear();
		for (int i = size - 1; i >= 0; i--)
		{
			int d = pow(10, i);
			number.push_back(a / d);
			a %= d;
		}
	}
	int CountBulls()
	{
		bull = 0;
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
		cow = 0;
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
	int ReturnAttempts()
	{
		return attempt;
	}
};

class BullsAndCows : public Methods
{
	int size;
	int numb;
	bool cycle = true;
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
					if ((i != j) && (points[i] == points[j]))
					{
						flag = true;
						cout << "Digits match.\n";
					}
					else flag = false;
				}
			}
		}
		GetNumber(numb);
	}
	void PrintResult()
	{
		int bull = CountBulls();
		int cow = CountCows();
		if (bull == size)
		{
			cout << "Congrats! The made-up number is:" << numb << endl;
			cycle = false;
		}
		cout << "Bulls: " << bull << "   Cows: " << cow << endl;
	}
	void GamingProcess()
	{
		GetSize();
		CreateNumber();
		while (cycle)
		{
			EnterNumber();
			PrintResult();
			Attempts();
		}
		int att = ReturnAttempts();
		cout << "Number of attempts: " << att << endl;
		cout << "The end!!!" << endl;
	}
};

void main()
{
	BullsAndCows game;
	int cycle = 1;
	while (cycle)
	{
		game.GamingProcess();
		cout << "1 - new game\n0 - exit\n";
		cin >> cycle;
	}
}