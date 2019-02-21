#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iosfwd>

using namespace std;

class Time
{
	int hrs;
	int mins;
	int secs;
public:
	Time()
	{
		hrs = 0;
		mins = 0;
		secs = 0;
	}
	Time(int h, int m, int s) //h, m, s = 0, если не было введено новое значение
	{
		hrs = h;
		mins = m;
		secs = s;
	}
	void PrintTime() // вывод значения
	{
		cout << hrs << " h ";
		cout << mins << " m ";
		cout << secs << " s";
		cout << endl;
	}
	void DiffTime(int h, int m, int s) // узнать разницу между заданным и установленным
	{
		hrs = abs(h - hrs);
		mins = abs(m - mins);
		secs = abs(s - secs);
	}
	void ShiftBackTime(int h, int m, int s) // изменить на заданное значение //для вычитания
	{
		hrs = hrs - h;
		mins = mins - m;
		secs = secs - s;
		hrs = 24 + (hrs % 24);
		if ((hrs == 24) || (hrs == -24))
			hrs = 0;
		hrs = hrs + mins / 60;
		if (mins != 0)
			hrs--;
		mins = 60 + (mins % 60);
		if ((mins == 60) || (mins == -60))
			mins = 0;
		mins = mins + secs / 60;
		if (secs != 0)
			mins--;
		s = 60 + (secs % 60);
		if ((secs == 60) || (secs == -60))
			secs = 0;
	}
	void ShiftForwTime(int h, int m, int s) // изменить на заданное значение //для сложения
	{
		hrs = hrs + h;
		mins = mins + m;
		secs = secs + s;
		if (secs > 59)
		{
			mins = mins + secs / 60;
			secs = secs % 60;
		}
		if (mins > 59)
		{
			hrs = hrs + mins / 60;
			mins = mins % 60;
		}
		if (hrs > 23)
			hrs = hrs % 24;
	}

};

void main()
{
//	int clock[3] = { 0 };
	int h = 0;
	int m = 0;
	int s = 0;
	int mode;
	int add;
	int i = 0;
	Time t;
	cout << "Time setted: 0 h 0 m 0 s.\n";
	while (i == 0)
	{
		cout << "\nWhat do you want to do?\n";
		cout << "Press 1 to set the time\n";
		cout << "Press 2 to check the time\n";
		cout << "Press 3 to compare setted time with entered time.\n";
		cout << "Press 4 to change the time\n";
		cin >> mode;
		switch (mode)
		{
		case 1:
		{
			cout << "Enter the time value you want to set.\n";
			cout << "Hours: ";
			cin >> h;
			cout << "Minutes: ";
			cin >> m;
			cout << "Seconds: ";
			cin >> s;
			cout << endl;
			while ((h < 0) || (h > 23) || (m < 0) || (m > 59) || (s < 0) || (s > 59))
			{
				cout << "Incorrect input. Try again.\n";
				cout << "Hours: ";
				cin >> h;
				cout << "Minutes: ";
				cin >> m;
				cout << "Seconds: ";
				cin >> s;
				cout << endl;
			}
			Time(h, m, s);
			break;
		}
		case 2:
		{
			t.PrintTime();
			break;
		}
		case 3:
		{
			cout << "Enter the time value you want to compare.\n";
			cout << "Hours: ";
			cin >> h;
			cout << "Minutes: ";
			cin >> m;
			cout << "Seconds: ";
			cin >> s;
			cout << endl;
			while ((h < 0) || (h > 23) || (m < 0) || (m > 59) || (s < 0) || (s > 59))
			{
				cout << "Incorrect input. Try again.";
				cout << "Hours: ";
				cin >> h;
				cout << "Minutes: ";
				cin >> m;
				cout << "Seconds: ";
				cin >> s;
				cout << endl;
			}
			t.DiffTime(h, m, s);
			cout << "The difference is: ";
			t.PrintTime();
			break;
		}
		case 4:
		{
			cout << "Insert the time value you want to add or to subtract.\n";
			cout << "Hours: ";
			cin >> h;
			cout << "Minutes: ";
			cin >> m;
			cout << "Seconds: ";
			cin >> s;
			cout << endl;
			cout << "Press 0 to add.\nPress 1 to subtract.\n";
			cin >> add;
			if (add == 0)
				t.ShiftForwTime(h, m, s);
			else t.ShiftBackTime(h, m, s);
			t.PrintTime();
		}
		cout << "Press 0 to continue\nPress 1 to exit\n";
		cin >> i;
		while ((i < 0) || (i > 1))
		{
			cout << "Press 0 to continue\nPress 1 to exit\n";
			cin >> i;
		}
	}
}