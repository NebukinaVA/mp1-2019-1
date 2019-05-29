#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <clocale>
#include "Song.h"

using namespace std;

void Player::PrintList() const
{
	for (int j = 0; j < playlist.size(); j++)
	{
		cout << j + 1 << ") " << playlist.at(j).info[0] << " - " << playlist.at(j).info[3] << "\n";
	}
}

int Player::OrderList(string str, int ind) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	if ((str[ind] >= 'А') && (str[ind] <= 'Я'))
	{
		str[ind] = str[ind] + 32;
		return 1;
	}
	else
		return 0;

}

void Player::AddSong(Song s)
{
//	playlist.push_back(s);
	int length = playlist.size();
	int len = s.info[0].length();
	int *v = new int[len];
	for (int i = 0; i < len; i++)
		v[i] = OrderList(s.info[0], i);
	int i = 0;
	while ((i < length) && (s.info[0] <= playlist[i].info[0]))
		i++;
	length++;
	playlist.resize(length);
	for (int j = length - 1; j > i; j--)
		playlist [j] = playlist[j - 1];
	playlist[i] = s;
	for (int j = 0; j < len; j++)
	{
		if (v[j] == 1)
			playlist[i].info[0][j] =playlist[i].info[0][j] - 32;
	}
	delete[] v;
}

void Player::ChangeData()
{
	int i, n;
	cout << "Выберите песню:\n";
	PrintList();
	cin >> i;
	cout << "Что Вы хотите изменить?";
	cout << "1. " << DATA[0] << "\n2. " << DATA[1] << "\n3. " << DATA[2] << "\n4. " << DATA[3] << "\n5. " << DATA[4] << "\n6. " << DATA[5] << "\n";
	cin >> n;
	if (n == 6)
	{
		cout << "Введите день, месяц, год: ";
		cin >> playlist.at(i - 1).day >> playlist.at(i - 1).month >> playlist.at(i - 1).year;
	}
	else
	{
		string str;
		cout << "Введите " << DATA[n - 1] << ":";
		cin >> str;
		playlist.at(i - 1).info[n - 1] = str;
	}
}

void Player::DeleteSong(string str1, string str2)
{
	for (int j = 0; j < playlist.size(); j++)
	{
		if (playlist.at(j).info[0] == str1)
		{
			if (playlist.at(j).info[3] == str2)
			{
				playlist.erase(playlist.begin() + j);
				break;
			}
			else
				throw "Ничего не найдено.\n";
		}
	}
}
Song Player::FindSong(string str1, string str2) //!!!!!!!!!!!!!!!!!!!!1
{
	vector <string> retstr(2);
	for (int j = 0; j < playlist.size(); j++)
	{
		if (playlist.at(j).info[0] == str1)
		{
			if (playlist.at(j).info[3] == str2)
				return playlist.at(j);
			else
				throw "Ничего не найдено.\n";
		}
	}
}
vector <string> Player::GetPoet(string str)
{
	int count = 0;
	for (int j = 0; j < playlist.size(); j++)
	{
		if (playlist.at(j).info[1] == str)
			count++;
	}
	vector <string> retstr(count);
	int i = 0;
	for (int k = 0; k < playlist.size(); k++)
	{
		if (playlist.at(k).info[1] == str)
		{
			retstr[i] = playlist.at(k).info[0];
			i++;
		}
		else
			throw "Ничего не найдено.\n";
	}
	return retstr;
}
vector <string> Player::GetComposer(string str)
{
	int count = 0;
	for (int j = 0; j < playlist.size(); j++)
	{
		if (playlist.at(j).info[2] == str)
			count++;
	}
	vector <string> retstr(count);
	int i = 0;
	for (int k = 0; k < playlist.size(); k++)
	{
		if (playlist.at(k).info[2] == str)
		{
			retstr[i] = playlist.at(k).info[0];
			i++;
		}
		else
			throw "Ничего не найдено.\n";
	}
	return retstr;
}
vector <string> Player::GetPerformer(string str)
{
	int count = 0;
	for (int j = 0; j < playlist.size(); j++)
	{
		if (playlist.at(j).info[3] == str)
			count++;
	}
	vector <string> retstr(count);
	int i = 0;
	for (int k = 0; k < playlist.size(); k++)
	{
		if (playlist.at(k).info[3] == str)
		{
			retstr[i] = playlist.at(k).info[0];
			i++;
		}
		else
			throw "Ничего не найдено.\n";
	}
	return retstr;
}
int Player::GetNumber()
{
	int track = playlist.size();
	return track;
}
void Player::SaveToFile(string str)
{
	ofstream file;
	file.open(str + ".txt");
	for (int i = 0; i < playlist.size(); i++)
	{
		file << playlist.at(i).info[0] << " ";
		file << playlist.at(i).info[1] << " ";
		file << playlist.at(i).info[2] << " ";
		file << playlist.at(i).info[3] << " ";
		file << playlist.at(i).info[4] << " ";
		file << playlist.at(i).day << " " << playlist.at(i).month << " " << playlist.at(i).year << endl;
	}
	file.close();
}
Player Player::GetFromFile(string str)
{
	ifstream file;
	int i = 0;
	file.open(str + ".txt");
	Player FileList;
	Song s;
	while (!file.eof())
	{
		file >> s.info[0];
		file >> s.info[1];
		file >> s.info[2];
		file >> s.info[3];
		file >> s.info[4];
		file >> s.day >> s.month >> s.year;
		playlist.push_back(s);
		i++;
	}
	file.close();
	return FileList;
}

Player& Player::operator=(const Player &p)
{
	playlist.clear();
	playlist.reserve(p.playlist.size());
	playlist = p.playlist;
	return *this;
}