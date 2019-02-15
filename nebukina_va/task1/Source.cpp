#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <iosfwd>
#include <windows.h>

using namespace std;

class Time
{
	int hrs, mins, secs;
public:
	Time()
	{
		hrs = 0;
		mins = 0;
		secs = 0;
	}
	Time(int h, int m, int s) 
	{
		hrs = h;
		mins = m;
		secs = s;
	}
	void PrintTime(int h, int m, int s)
	{
		cout << h << " h ";
		cout << m << " m ";
		cout << s << " s";
		cout << endl;
	}
	int CalcTimeP(int h, int m, int s) // для сложения
	{
		if (s > 59)
		{
			m = m + s / 60;
			s = s % 60;
		}
		if (m > 59)
		{
			h = h + m / 60;
			m = m % 60;
		}
		if (h > 23)
			h = h % 24;
		return h, m, s;
	}
	int CalcTimeM(int h, int m, int s) // для вычитания
	{
		if (s < -59)
		{
			m = m + s / 60;
			s = 60 + (s % 60);
			if ((s == 60) || (s == -60))
				s = 0;
		}
		if (m < -59)
		{
			h = h + m / 60;
			m = 60 + (m % 60);
			if ((m == 60) || (m == -60))
				m = 0;
		}
		if (h < -23)
		{
			h = 24 + (h % 24);
			if ((h == 24) || (h == -24))
				h = 0;
		}
		return h, m, s;
	}
	void SetTime(int h, int m, int s) //1. установить время
	{
		hrs = h;
		mins = m;
		secs = s;
	}
	int GetTime(int h, int m, int s) // 2. узнать время
	{
		h = hrs;
		m = mins;
		s = secs;
		return h, m, s;
	}
	int DiffTime(int h, int m, int s) // 3. узнать разницу между заданным и установленным
	{
		h = abs(h - hrs);
		m = abs(m - mins);
		s = abs(s - secs);
		return h, m, s;
	}
	int ChangeTime(int h, int m, int s, int add) //4. изменить на заданное значение
	{
		if (add = 1)
		{
			h = hrs - h;
			m = mins - m;
			s = secs - s;
		}
		else 
		{
			h = h + hrs;
			m = m + mins;
			s = s + secs;
		}
		return h, m, s;
	}
};

void main()
{
	int h = 0, m = 0, s = 0;
	int hr, mn, sc;
	int hdiff, mdiff, sdiff;
	int mode;
	char add;
	int i = 0;
	long long curr;
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
			cout << "Enter the time value you want to set.";
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
			t.SetTime(h, m, s);
			break;
		}
		case 2:
		{
			t.GetTime(h, m, s);
			t.PrintTime(h, m, s);			
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
			t.PrintTime(h, m, s);
			break;
		}
		case 4:
		{
			cout << "Insert the time value you want to add or to subtract.\n";
			cout <<	"Hours: ";
			cin >> h;
			cout << "Minutes: ";
			cin >> m;
			cout << "Seconds: ";
			cin >> s;
			cout << "Press 0 to add.\nPress 1 to subtract.\n";
			cin >> add;
			t.ChangeTime(h, m, s, add);
			/*
			if (add == 0)
				t.CalcTimeP(h, m, s);
			else t.CalcTimeM(h, m, s); */
			t.PrintTime(h, m, s);
		}
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
