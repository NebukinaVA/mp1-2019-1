#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <iosfwd>

using namespace std;

class Time
{
	int hrs = 0;
	int mins = 0;
	int secs = 0;
public:
	void PrintTime(int h, int m, int s)
	{
		cout << h;
		cout << " h ";
		cout << m;
		cout << " m ";
		cout << s;
		cout << " s";
		cout << endl;
	}
	int CalcTime(int h, int m, int s)
	{
		if (s >= 60)
			m = m + (s / 60);
		if (m >= 60)
			h = h + (m / 60);
		if (h >= 24)
			h = h % 24;
		return h, m, s;
	}
    int ConvertTime(int time, int h, int m, int s) //!!!!!!!!!
    {
    	s = time % 60;
    	m = time / 60;
    	h = m / 60;
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
	void Diff(int h, int m, int s) //?? 3. узнать разницу между текущим и установленным
	{
		// tm* localtime(const time_t* timer);
		h = hrs; 
		m = mins;
		s = secs;
	}
	int ChangeTime(int h, int m, int s, char add) //4. изменить на заданное значение. add: + or -
	{
		if (add = '-') //уменьшить на заданное значение
		{
			h = -h;
			m = -m;
			s = -s;
		}
		h = h + hrs;
		m = m + mins;
		s = s + secs;
		return h, m, s;
	}
};

void main()
{
	int h = -1, m = -1, s = -1;
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
		cout << "Press 3 to check the difference between set time and current time\n";
		cout << "Press 4 to change the time\n";
		cin >> mode;
		switch (mode)
		{
		case 1:
		{
			cout << "Insert the time value you want to set.\nHours: ";
			cin >> h;
			cout << "\nMinutes: ";
			cin >> m;
			cout << "\nSeconds: ";
			cin >> s;
			while ((h < 0) || (h > 23) || (m < 0) || (m > 59) || (s < 0) || (s > 59))
			{
				cout << "Incorrect input. Try again.";
				cout << "\nHours: ";
				cin >> h;
				cout << "\nMinutes: ";
				cin >> m;
				cout << "\nSeconds: ";
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
			hr = 0;
			mn = 0;
			sc = 0;
			curr = clock();
			cout << curr;
			t.ConvertTime(curr, hr, mn, sc);
			t.CalcTime(hr, mn, sc);
			t.GetTime(h, m, s);
			hdiff = abs(h - hr);
			mdiff = abs(m - mn);
			sdiff = abs(s - sc);
			cout << "Time difference:";
			t.PrintTime(hdiff, mdiff, sdiff);
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
//дополнительно
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>

using namespace std;

class Time
{
	int hrs;
	int mins;
	int secs;
	int hr, mn, sc;
	long long current;
public:
	int interpret(int h, int m, int s)  //для №3
	{
		mn = m + s / 60;
		s = s % 60;
		m = mn % 60;
		hr = h + m / 60;
		h = hr % 24;
		return h, m, s;
	}
	int ConvTimeP(int h, int m, int s) // для сложения
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
	int ConvTimeM(int h, int m, int s) // для вычитания???????????
	{
		if (m < -59)
			h = h + m / 60;
		m = 60 + (m % 60);
		if (h < -23)
		{
			h = 24 + (h % 24);
			if ((h == 24) || (h == -24))
				h = 0;
		}
		else h = -h;
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
	}
	void Diff(int h, int m, int s) //?? 3. узнать разницу между текущим и установленным
	{
		SYSTEMTIME lt;
		GetLocalTime(&lt);

	}
	int SubtractTime(int h, int m, int s) // вычесть значение
	{
		
	}
	int AddTime(int h, int m, int s) //4. изменить на заданное значение. add
	{
		h = h + hrs;
		m = m + mins;
		s = s + secs;
	}
};
int main()
{
	int h, m, s;
	int add; // 1 or 0
	long long *tp;
	time_t time(time_t *tp);
}
