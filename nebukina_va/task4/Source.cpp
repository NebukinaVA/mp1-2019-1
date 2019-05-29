#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <clocale>
#include "Song.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int mode = 0;
	int cycle = 0;
	vector <string> getstr;
	Song sin, sout;
	Player p;
	cout << "0 ����� � ��������.\n";
	while (cycle == 0)
	{
		do
		{
			cout << "\n�������� ��������:\n";
			cout << "1 - �������� �����.\n";
			cout << "2 - �������� ������ �����.\n";
			cout << "3 - ����� ����� �� �������� � �����������.\n";
			cout << "4 - ������ ��� ����� ��������� �����.\n";
			cout << "5 - ������ ��� ����� ��������� �����������.\n";
			cout << "6 - ������ ��� ����� ��������� �����������.\n";
			cout << "7 - ������ ������� ����� �����.\n";
			cout << "8 - ������� �����.\n";
			cout << "9 - ��������� �������� � ����.\n";
			cout << "10 - ������� �������� �� �����.\n";
			cin >> mode;
		} while ((mode < 1) || (mode > 10));
		switch (mode)
		{
		case 1:
		{
			p.AddSong(sout);
			cout << "����� ����������.\n";
			break;
		}
		case 2:
			p.ChangeData();
			break;
		case 3:
		{
			string str2, str1;
			cout << "��������: ";
			cin >> str1;
			cout << "�����������: ";
			cin >> str2;
            sin = p.FindSong(str1, str2);
			break;
		}
		case 4:
		{
			string str;
			cout << "������� ��� �����: ";
			cin >> str;
			getstr = p.GetPoet(str);
			break;
		}
		case 5:
		{
			string str;
			cout << "������� ��� �����������: ";
			cin >> str;
			getstr = p.GetComposer(str);
			break;
		}
		case 6:
		{
			string str;
			cout << "������� ��� �����������: ";
			cin >> str;
			getstr = p.GetPerformer(str);
			break;
		}
		case 7:
		{
			n = p.GetNumber();
			break;
		}
		case 8:
		{
			string str2, str1;
			cout << "��������: ";
			cin >> str1;
			cout << "�����������: ";
			cin >> str2;
			p.DeleteSong(str1, str2);
			break;
		}
		case 9:
		{
			string str;
			cout << "������� ��� �����:";
			cin >> str;
			p.SaveToFile(str);
		}
		case 10:
		{
			Player pfile;
			string str;
			cout << "������� ��� �����:";
			cin >> str;
			pfile = p.GetFromFile(str);
		}
		}
		do
		{
			cout << "0 - ����������\n1 - �����\n";
			cin >> cycle;
		} while ((cycle < 0) || (cycle > 1));
	}
}

