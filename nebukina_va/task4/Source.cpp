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
	cout << "0 песен в песеннке.\n";
	while (cycle == 0)
	{
		do
		{
			cout << "\nВыберите действие:\n";
			cout << "1 - добавить песню.\n";
			cout << "2 - изменить данные песни.\n";
			cout << "3 - найти песню по названию и исполнителю.\n";
			cout << "4 - выдать все песни заданного поэта.\n";
			cout << "5 - выдать все песни заданного композитора.\n";
			cout << "6 - выдать все песни заданного исполнителя.\n";
			cout << "7 - узнать текущее число песен.\n";
			cout << "8 - удалить песню.\n";
			cout << "9 - сохранить песенник в файл.\n";
			cout << "10 - считать песенник из файла.\n";
			cin >> mode;
		} while ((mode < 1) || (mode > 10));
		switch (mode)
		{
		case 1:
		{
			p.AddSong(sout);
			cout << "Песня добавлениа.\n";
			break;
		}
		case 2:
			p.ChangeData();
			break;
		case 3:
		{
			string str2, str1;
			cout << "Название: ";
			cin >> str1;
			cout << "Исполнитель: ";
			cin >> str2;
            sin = p.FindSong(str1, str2);
			break;
		}
		case 4:
		{
			string str;
			cout << "Введите имя поэта: ";
			cin >> str;
			getstr = p.GetPoet(str);
			break;
		}
		case 5:
		{
			string str;
			cout << "Введите имя композитора: ";
			cin >> str;
			getstr = p.GetComposer(str);
			break;
		}
		case 6:
		{
			string str;
			cout << "Введите имя исполнителя: ";
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
			cout << "Название: ";
			cin >> str1;
			cout << "Исполнитель: ";
			cin >> str2;
			p.DeleteSong(str1, str2);
			break;
		}
		case 9:
		{
			string str;
			cout << "Введите имя файла:";
			cin >> str;
			p.SaveToFile(str);
		}
		case 10:
		{
			Player pfile;
			string str;
			cout << "Введите имя файла:";
			cin >> str;
			pfile = p.GetFromFile(str);
		}
		}
		do
		{
			cout << "0 - продолжить\n1 - выход\n";
			cin >> cycle;
		} while ((cycle < 0) || (cycle > 1));
	}
}

