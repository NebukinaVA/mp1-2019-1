#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

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
			m = 60 + (m & 60);
		if (h < -23)
			h = 24 + (h % 24);		
		else h = -h;
		if ((h == 24) || (h == -24))
			h = 0;
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
		// tm* localtime(const time_t* timer);
		current = *tm;

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
