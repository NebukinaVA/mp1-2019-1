#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>

using namespace std;

struct Song
{
	string info[5];
	int day, month, year;
};

class Player
{
	vector <Song> playlist;
	const string DATA[6] = { "Название", "Поэт", "Композитор", "Исполнитель", "Альбом", "Дата" };
	int OrderList(string str, int ind);
	void PrintList() const;
public:
	Player()
	{
	}
	~Player()
	{
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
	Player& operator= (const Player &p);
};
