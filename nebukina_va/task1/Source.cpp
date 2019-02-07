#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iosfwd>

class Time
{
	int hrs;
	int mins;
	int secs;
public:
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
	}
};
void main()
{
	int h, m, s;
	char add;
}