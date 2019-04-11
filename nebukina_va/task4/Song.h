#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Song
{
	string name;
	string poet;
	string composer;
	string performer;
	string album;
	string info[5];
	int day, month, year;
};

class Player
{
	vector <Song> playlist;
	vector <int> iSongsByName;
	const string DATA[6] = { "Name", "Poet", "Composer", "Performer", "Album", "Date" };
	void OrderList();
	void PrintList() const;
public:
	Player()
	{
	}
	~Player()
	{
		playlist.clear();
		iSongsByName.clear();
	}
	void AddSong(Song s);
	void ChangeData();
	Song FindSong(string str1, string str2);
	vector <string> GetPoet(string str);
	vector <string> GetComposer(string str);
	vector <string> GetPerformer(string str);
	int GetNumber();
	void DeleteSong(string str1, string str2);
	void SaveToFile(string str);
	Player GetFromFile(string str);
};