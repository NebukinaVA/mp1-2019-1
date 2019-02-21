#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iosfwd>

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
	void PrintTime() // вывод значения
	{
		cout << hrs << " h ";
		cout << mins << " m ";
		cout << secs << " s";
		cout << endl;
	}
/*	int GetTime(int (&cl)[3]) // узнать время
	{
		cl[0] = hrs;
		cl[1] = mins;
		cl[2] = secs;
		return cl[3];
	}*/
	int CalcTimeP(int (&cl)[3]) // для сложения
	{
		int h = cl[0];
		int m = cl[1];
		int s = cl[2];
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
		cl[0] = h;
		cl[1] = m;
		cl[2] = s;
		return cl[3];
	}
	int CalcTimeM(int (&cl)[3]) // для вычитания
	{
		int h = cl[0];
		int m = cl[1];
		int s = cl[2];
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
		cl[0] = h;
		cl[1] = m;
		cl[2] = s;
		return cl[3];
	}
	void SetTime(int (&cl)[3]) // установить время
	{
		hrs = cl[0];
		mins = cl[1];
		secs = cl[2];
	}
	
	int DiffTime(int (&cl)[3]) // узнать разницу между заданным и установленным
	{
		cl[0] = abs(cl[0] - hrs);
		cl[1] = abs(cl[1] - mins);
		cl[2] = abs(cl[2] - secs);
		return cl[3];
	}
	int ShiftTime(int (&cl)[3], int add) // изменить на заданное значение
	{
		if (add == 1)
		{
			cl[0] = hrs - cl[0];
			cl[1] = mins - cl[1];
			cl[2] = secs - cl[2];
		}
		else 
		{
			cl[0] = cl[0] + hrs;
			cl[1] = cl[1] + mins;
			cl[2] = cl[2] + secs;
		}
		return cl[3];
	}	
};

int EnterTime(int(&cl)[3]) // ввод значения
{
		cout << "Hours: ";
		cin >> cl[0];
		cout << "Minutes: ";
		cin >> cl[1];
		cout << "Seconds: ";
		cin >> cl[2];
		cout << endl;
		return cl[3];
}

void main()
{	
	int clock[3] = { 0 };
	int h = clock[0];
	int m = clock[1];
	int s = clock[2];
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
			EnterTime(clock);
			while ((h < 0) || (h > 23) || (m < 0) || (m > 59) || (s < 0) || (s > 59))
			{
				cout << "Incorrect input. Try again.";
				EnterTime(clock);
			}
			t.SetTime(clock);
			break;
		}
		case 2:
		{
		//	t.GetTime(clock);
			t.PrintTime();			
			break;
		}
		case 3:
		{
			cout << "Enter the time value you want to compare.\n";
			EnterTime(clock);
			while ((h < 0) || (h > 23) || (m < 0) || (m > 59) || (s < 0) || (s > 59))
			{
				cout << "Incorrect input. Try again.";
				EnterTime(clock);
			}
			t.DiffTime(clock);
			cout << "The difference is: ";
			t.PrintTime();
			break;
		}
		case 4:
		{
			cout << "Insert the time value you want to add or to subtract.\n";
			EnterTime(clock);
			cout << "Press 0 to add.\nPress 1 to subtract.\n";
			cin >> add;
			t.ShiftTime(clock, add);
			if (add == 0)
				t.CalcTimeP(clock);
			else t.CalcTimeM(clock); 
			t.PrintTime();
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
