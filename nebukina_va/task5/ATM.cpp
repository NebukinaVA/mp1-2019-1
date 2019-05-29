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
	~Client()
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
	bool WrongsCount(bool f)
	{
		if ((wrongPIN != 3) && (f == true))
			wrongPIN++;
		if (wrongPIN == 3)
			AccountAccess = false;
	    return AccountAccess;
	}
};

class Center 
{
	vector <Client> ClientBase;
public:
	Center()
	{
	}
	~Center()
	{
	}
	Client GetInfo(int n)
	{
		Client c;
		c = ClientBase.at(n);
		return c;
	}
	void ChangeInfo(Client cl, int ind)
	{
		ClientBase[ind] = cl;
	}
	int SizeOf()
	{
		return ClientBase.size();
	}
};

class Cassette
{
	const int value[6] = { 100,200,500,1000,2000,5000 };
	int amount[6];
	int max = 2000000;
public:
	Cassette()
	{
		for (int i = 0; i < 6; i++)
			amount[i] = 0.8 * max;
	}
	void Withdraw(long int m)
	{
		int bill[6];
		for (int i = 5; i >= 0; i--)
		{
			if (amount[i] > 0)
			{
				bill[i] = m / value[i];
				if (amount[i] >= bill[i])
				{
					amount[i] = amount[i] - bill[i];
					m = m - bill[i] * value[i];
				}
				else
				{
					bill[i] = amount[i];
					amount[i] = 0;
					m = m - bill[i] * value[i];
				}
            }
		}
		if (m == 0)
			cout << "Done.\n";
		else
		{
			for (int j = 0; j < 6; j++)
			{
				amount[j] = amount[j] + bill[j];
				m = m + bill[j] * value[j];
			}
			cout << "Error: lack of bills.\n";
		}
	}
	void Deposit(long int m)
	{
		int bill[6];
		for (int i = 5; i <= 0; i--)
		{
			if (amount[i] < max)
			{
				bill[i] = m / value[i];
				int a = amount[i] + bill[i];
				if (a <= max)
				{
					amount[i] = a;
					m = m - bill[i] * value[i];
				}
				else
				{
					bill[i] = max - amount[i];
					amount[i] = max;
					m = m - bill[i] * value[i];
				}
			}
		}
		if (m == 0)
			cout << "Done.\n";
		else
		{
			for (int j = 0; j < 6; j++)
			{
				amount[j] = amount[j] - bill[j];
				m = m + bill[j] * value[j];
			}
			cout << "Error: cassette overflow.\n";
		}
	}
};

class ATM
{
	Center cent;
	Client cl;
	Cassette cas;
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
		flag = true;
	}
	Client FindClient()
	{
		Client c;
		Center cent;
		for (int i = 0; i < INT_MAX; i++)
		{
			c = cent.GetInfo(i);
			if (cl.GetCard() == c.GetCard())
			{
				ind = i;
				cl = c;
				break;
			}
		}
		return cl;
	}
	void CheckPIN(int pin)
	{
		if (cl.WrongsCount(false))
		{
			if (flag)
			{
				if (pin == cl.GetPIN())
				{
					access = true;
					cout << "The PIN is correct.\n";
				}
				else
				{
					cout << "Wrong PIN.\n";
					flag = cl.WrongsCount(true);
				}
			}
			else cout << "Access denied.\n";
		}
		else cout << "Your card is blocked.\n";
		cent.ChangeInfo(cl, ind);
	}
	long int GetCash()
	{
		if ((cl.WrongsCount(false)) && (access == true))
		{
			long int cash = cl.GetCash();
			if (flag)
				return cash;
			else cout << "Access denied.\n";
		}
		else cout << "Your card is blocked.\n";
	}
	void WithdrawCash(long int c)
	{
		if ((cl.WrongsCount(false)) && (access == true))
		{
			if (cl.GetCash >= c)
			{
				cas.Withdraw(c);
				cent.ChangeInfo(cl, ind);
			}
			else cout << "Not enought money to withdraw.\n";
		}
		else cout << "Your card is blocked.\n";
	}
	void DepositCash(long int c)
	{
		if ((cl.WrongsCount(false)) && (access == true))
		{
			cas.Deposit(c);
			cent.ChangeInfo(cl, ind);
		}
		else cout << "Your card is blocked.\n";
	}
	void BlockCard()
	{
		if (!cl.WrongsCount(false)) cout << "Card is blocked.\n";
	}
	void ReturnCard()
	{
		cl.~Client();
		cas.~Cassette();
		Client cl;
		Cassette cas;
		bool flag = false;
		bool access = false;
	}
};

void main()
{
	ATM bank;
	long int mycash;
	int card;
	Client c;
	int pin;
	int cycle = 0;
	int mode;
	while (cycle == 0)
	{
		do
		{
			cout << "\nWhat do you want to do?\n";
			cout << "Press 1 to input the card.\n";
			cout << "Press 2 to find a client.\n";
			cout << "Press 3 to check the PIN.\n";
			cout << "Press 4 to get the amount of money.\n";
			cout << "Press 5 to withdraw cash.\n";
			cout << "Press 6 to deposit cash.\n";
			cout << "Press 7 to block the card.\n";
			cout << "Press 8 to return the card.\n";
			cin >> mode;
		} while ((mode < 1) || (mode > 7));
		switch (mode)
		{
		case 1:
		{
			cin >> card;
			bank.GetCard(card);
			break;
		}
		case 2:
		{
			c = bank.FindClient();
			break;
		}
		case 3:
		{
			cin >> pin;
			bank.CheckPIN(pin);
			break;
		}
		case 4:
		{
			mycash = bank.GetCash();
			break;
		}
		case 5:
		{
			cin >> mycash;
			bank.WithdrawCash(mycash);
			break;
		}
		case 6:
		{
			cin >> mycash;
			bank.DepositCash(mycash);
			break;
		}
		case 7:
		{
			bank.BlockCard();
			break;
		}
		case 8:
		{
			bank.ReturnCard();
			break;
		}
		}
		do
		{
			cout << "Press 0 to continue\nPress 1 to exit\n";
			cin >> cycle;
		} while ((cycle < 0) || (cycle > 1));
	}
}