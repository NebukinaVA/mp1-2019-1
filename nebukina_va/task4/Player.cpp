#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include "Song.h"

using namespace std;

void Player::PrintList() const
{
	for (int j = 0; j < playlist.size(); j++)
	{
		cout << j + 1 << ") " << playlist.at(j).info[0] << " - " << playlist.at(j).info[3] << "\n";
	}
}

void Player::OrderList() // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	for (int i = playlist.size() - 1; i <= 0; i--)
	{

		for (int j = 0; j < playlist.max_size(); j++)
		{
			if (playlist.back[0] == playlist[i])
				;
		}
	}
}

void Player::AddSong(Song s)
{
	playlist.push_back(s);
}

void Player::ChangeData()
{
	int i, n;
	cout << "Choose a song:\n";
	PrintList();
	cin >> i;
	cout << "What do you want to change?";
	cout << "1. " << DATA[0] << "\n2. " << DATA[1] << "\n3. " << DATA[2] << "\n4. " << DATA[3] << "\n5. " << DATA[4] << "\n6. " << DATA[5] << "\n";
	cin >> n;
	if (n == 6)
	{
		cout << "Enter day, month, year: ";
		cin >> playlist.at(i - 1).day >> playlist.at(i - 1).month >> playlist.at(i - 1).year;
	}
	else
	{
		string str;
		cout << "Enter " << DATA[n - 1] << ":";
		cin >> str;
		playlist.at(i - 1).info[n - 1] = str;
	}
}

void Player::DeleteSong(string str1, string str2)
{
	int ind;
	for (int j = 0; j < playlist.size(); j++)
	{
		if (playlist.at(j).info[0] == str1)
		{
			if (playlist.at(j).info[3] == str2)
			{
				ind = j;
				break;
			}
			else
				throw (1); //!! no songs found
		}
	}
	playlist.erase(playlist.begin() + ind);
}
Song Player::FindSong(string str1, string str2) //!!!!!!!!!!!!!!!!!!!!1
{
/*	string str2, str1;
	cout << "Enter name: ";
	cin >> str1;
	cout << "Enter performer: ";
	cin >> str2; 
*/
	int ind;
	vector <string> retstr(2);
	for (int j = 0; j < playlist.size(); j++)
	{
		if (playlist.at(j).info[0] == str1)
		{
			if (playlist.at(j).info[3] == str2)
			{
				ind = j;
				break;
			}
			else 
				throw (1); //!! no songs found
		}
	}
	return playlist.at(ind);
}
vector <string> Player::GetPoet(string str)
{
	/*
	string str;
	cout << "Enter name of the poet: ";
	cin >> str;
	*/
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
			throw (1); //!! no songs found
	}
	return retstr;
}
vector <string> Player::GetComposer(string str)
{
	/*
	string str;
	cout << "Enter name of the composer: ";
	cin >> str;*/
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
			throw (1); //!! no songs found
	}
	return retstr;
}
vector <string> Player::GetPerformer(string str)
{
	/*
	string str;
	cout << "Enter name of the performer: ";
	cin >> str;*/
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
			throw (1); //!! no songs found
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
	string songinfo[5];
	int y, m, d;
	while (!file.eof())
	{
		file >> songinfo[0];
		file >> songinfo[1];
		file >> songinfo[2];
		file >> songinfo[3];
		file >> songinfo[4];
		file >> d >> m >> y;
		playlist.push_back(songinfo);
		i++;
	}
	file.close();
	return songinfo;
}
