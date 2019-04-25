#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Client
{
	string name;
	int card;
	long int cash;
	int PIN;
	int wrongPIN = 0;
	bool AccountAccess = true;
public:
	Client()
	{
	}
	Client(string _name, int _card, long int _cash, int _PIN)
	{
		name = _name;
		card = _card;
		cash = _cash;
		PIN = _PIN;
	}
	Client& operator=(const Client &c)
	{
		name = c.name;
		card = c.card;
		cash = c.cash;
		PIN = c.PIN;
		return *this;
	}
	string GetName()
	{
		return name;
	}
	int GetCard()
	{
		return card;
	}
	long int GetCash()
	{
		return cash;
	}
	int GetPIN()
	{
		return PIN;
	}
	void Card(int c)
	{
		card = c;
	}
	void WrongsCount()
	{
		wrongPIN++;
		if (wrongPIN == 3)
		{
			AccountAccess = false;
		}
	}
};

class Center: public Client
{
	vector <Client> ClientBase;
public:
	Center() 
	{
	}
	// destructor?
	Client GetInfo(int n)
	{
		Client c;
		c = ClientBase.at(n);
		return c;
	}
};

class Cassette
{
	const int value[6] = { 100,200,500,1000,2000,5000 };
	int amount[6];
	int max[6];
 public:
	 Cassette()
	 {
		 for (int i = 0; i < 6; i++)
		 {
			 max[i] = 2000000;
			 amount[i] = 0.8 * max[i];
		 }
	 }
};

class ATM: public Center, public Cassette
{
	Client cl;
	int ind;
	bool flag = false;
	bool access = false;
public:
	ATM()
	{
	}
	void GetCard(int cardnumb)
	{
		cl.Card(cardnumb);
	}
	Client FindClient()
	{
		Client c;
		Center cent;
		for (int i = 0; i < INT_MAX; i++)
		{
			c = cent.GetInfo(i);
			if (cl.GetCard() == c.GetCard)
			{
				ind = i;
				cl = c;
				flag = true;
				break;
			}
		}
		return cl;
	}
	void CheckPIN(int pin)
	{
		if (flag)
			if (pin == cl.GetPIN())
				access = true;
			else
			{ 
				cout << "Wrong PIN.\n";
				
			}
		else cout << "No card to check PIN.\n";

	}
};
