#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <clocale>

using namespace std;
/*
void main()
{
    setlocale(LC_ALL, "Rus");
	int n;
	int number;
	int mode = 0;
	int i;
	int cycle = 0;
	string str[2];
	string *pstr = str;
	Player p;
	cout << "Default number of options - 1.\n";
	while (cycle == 0)
	{
		do
		{
			cout << "\nWhat do you want to do?\n";
			cout << "Press 1 to add a song.\n";
			cout << "Press 2 to change chosen song's data.\n";
			cout << "Press 3 to find the song.\n";
			cout << "Press 4 to get all songs of chosen poet.\n";
			cout << "Press 5 to get all songs of chosen composer.\n";
			cout << "Press 6 to get all songs of chosen performer.\n";
			cout << "Press 7 to get current number of songs.\n";
			cout << "Press 8 to delete the song.\n";
			cout << "Press 9 to save player in the file.\n";
			cout << "Press 10 to get player from the file.\n";
			cin >> mode;
		} while ((mode < 1) || (mode > 10));
		switch (mode)
		{
		case 1:
		{
			p.AddSong();
			cout << "The song has been added.\n";
			break;
		}
		case 2:
			p.ChangeData();
			break;
		case 3:
		{
			//	pstr = p.FindSong();
			break;
		}
		case 4:
		{
			p.GetPoet();
			break;
		}
		case 5:
		{
			p.GetComposer();
			break;
		}
		case 6:
		{
			p.GetPerformer();
			break;
		}
		case 7:
		{
			n = p.GetNumber();
			break;
		}
		case 8:
		{
			p.DeleteSong();
			break;
		}
		}
		do
		{
			cout << "Press 0 to continue\nPress 1 to exit\n";
			cin >> cycle;
		} while ((cycle < 0) || (cycle > 1));
	}
	delete[] str;
}
*/
