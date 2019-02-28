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
	Time(int h, int m, int s)
	{
		hrs = h;
		mins = m;
		secs = s;
	}
	Time& operator=(const Time &t)
	{
		hrs = t.hrs;
		mins = t.mins;
		secs = t.secs;
		return *this;
	}
	void SetTime(int h, int m, int s)
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
	Time DiffTime(Time t) // узнать разницу между заданным и установленным
	{
		int h = t.hrs;
		int m = t.mins;
		int s = t.secs;
		h = hrs - h;
		m = mins - m;
		s = secs - s;
		if (h < 0)
		{
			h = 24 + (h % 24);
			if (h == -24)
				h = 0;
		}
		if (m < 0)
		{
			h = h + m / 60;
			if (m != 0)
				h--;
			m = 60 + (m % 60);
			if (m == -60)
				m = 0;
		}
		if (s < 0)
		{
			m = m + s / 60;
			if (s != 0)
				m--;
			s = 60 + (s % 60);
			if (s == -60)
				s = 0;
		}
		t.hrs = h;
		t.mins = m;
		t.secs = s;
		return t;
	}
	Time ShiftBackTime(Time t) // изменить на заданное значение //для вычитания
	{
		int h = t.hrs;
		int m = t.mins;
		int s = t.secs;
		h = h - hrs;
		m = m - mins;
		s = s - secs;
		h = 24 + (h % 24);
		if ((h == 24) || (h == -24))
			h = 0;
		h = h + m / 60;
		if (m != 0)
			h--;
		m = 60 + (m % 60);
		if ((m == 60) || (m == -60))
			m = 0;
		m = m + s / 60;
		if (s != 0)
			m--;
		s = 60 + (s % 60);
		if ((s == 60) || (s == -60))
			s = 0;
		hrs = h;
		mins = m;
		secs = s;
		t.hrs = h;
		t.mins = m;
		t.secs = s;
		return t;
	}
	Time ShiftForwTime(Time t) // изменить на заданное значение //для сложения
	{
		int h = t.hrs;
		int m = t.mins;
		int s = t.secs;
		h = hrs + h;
		m = mins + m;
		s = secs + s;
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
		hrs = h;
		mins = m;
		secs = s;
		t.hrs = h;
		t.mins = m;
		t.secs = s;
		return t;
	}

};

void main()
{
	int h = 0;
	int m = 0;
	int s = 0;
	int mode;
	int add;
	int i = 0;
	Time t1, t2, t3;
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
			t1.SetTime(h, m, s);
			break;
		}
		case 2:
		{
			t1.PrintTime();
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
			t2.SetTime(h, m, s);
			t3 = t1.DiffTime(t2);
			cout << "The difference is: ";
			t3.PrintTime();
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
			t2.SetTime(h, m, s);
			if (add == 0)
				t3 = t1.ShiftForwTime(t2);
			else t3 = t1.ShiftBackTime(t2);
			t3.PrintTime();
			break;
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