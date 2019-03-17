#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class Menu
{
	int item;
	int lastitem;
	bool flag = false;
	vector <string> command;
	void gotoxy(int x, int y) const
	{
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		if (!Console)
			return;
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(Console, pos);
	}
public:
	Menu(int i = 1)
	{
		item = i;
		command.reserve(item);
		//	command.at(0) = '\0';
	}
	Menu(const Menu &m)
	{
		item = m.item;
		command = m.command;
		lastitem = m.lastitem;
	}
	~Menu()
	{
		command.clear();
	}
	void SetSize(int size)
	{
		item = size;
		command.reserve(item);
		Menu(item);
	}
	int GetSize() const
	{
		return item;
	}
	void SetStr(int i, string s)
	{
		command.at(i - 1) = s;
	}
	void GetMenu(int x, int y) const
	{
		for (int i = 0; i < item; i++)
		{
			gotoxy(x, y);
			y++;
			cout << i + 1 << ") " << command.at(i) << "\n";
		}
	}
	void ChooseItem(int n)
	{
		lastitem = n;
		flag = true;
		cout << "You've chosen " << n << ") " << command.at(n - 1) << "\n";
	}
	int GetItem() const
	{
		if (flag == true)
			return lastitem;
		else
			return 0;
	}
};

int main()
{
	int n;
	int mode = 0;
	int i;
	int x = 0, y = 0;
	int cycle = 0;
	int opt;
	int last;
	string str;
	Menu m;
	cout << "Default number of options - 1.\n";
	while (cycle == 0)
	{
		do
		{
			cout << "\nWhat do you want to do?\n";
			cout << "Press 1 to set the number of options.\n";
			cout << "Press 2 to get the number of options.\n";
			cout << "Press 3 to set the name of the option.\n";
			cout << "Press 4 to get the menu in wanted position.\n";
			cout << "Press 5 to choose the option.\n";
			cout << "Press 6 to get the last chosen option.\n";
			cin >> mode;
		} while ((mode < 1) || (mode > 6));
		switch (mode)
		{
		case 1:
		{
			do
			{
				cout << "Enter the number of options.\n";
				cin >> n;
			} while ((n < 1) || (n > 20));
			m.SetSize(n);
			break;
		}
		case 2:
			n = m.GetSize();
			cout << "The  number of options is " << n << ".\n";
			cout << endl;
			break;
		case 3:
		{
			cout << "Enter the number of option from 1 to " << n << ".\n";
			cin >> i;
			cout << "Enter the name you want to set.\n";
			cin >> str;
			m.SetStr(i, str);
			break;
		}
		case 4:
		{
			cout << "Enter coordinates:";
			cin >> x, y;
			m.GetMenu(x, y);
			break;
		}
		case 5:
		{
			cout << "Enter the number:";
			cin >> opt;
			m.ChooseItem(opt);
			break;
		}
		case 6:
		{
			last = m.GetItem();
			cout << "The last one is " << last << ". (0 - if you haven't chosen any option.\n";
			break;
		}
		}
		do
		{
			cout << "Press 0 to continue\nPress 1 to exit\n";
			cin >> cycle;
		} while ((cycle < 0) || (cycle > 1));
	}
}