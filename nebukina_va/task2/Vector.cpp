#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iosfwd>

using namespace std;

class Vector 
{
	int n;
	long int *vector = new long int[n];
public:
	Vector()
	{
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			vector[i] = rand() % 2001 - 1000;
		}
	}
	Vector(int _n)
	{
		n = _n;
	}
	Vector& operator=(const Vector &v)
	{
		for (int i = 0; i < n; i++)
		{
			vector[i] = v.vector[i];
		}
		return *this;
	}
	void SetSize(int size)
	{
		n = size;
	}
	void GetSize()
	{
		cout << "The size of the verctor is " << n << ".\n";
		cout << endl;
	}
	void SetComp(int i, long int a)
	{
		vector[i-1] = a;
	}
	void GetComp(int i)
	{
		cout << "The " << i << " component of vector is ";
		cout << vector[i-1] << ".\n";
		cout << endl;
	}
	void CalcLen()
	{
		long double len = 0;
		for (int i = 0; i < n; i++)
		{
			len = len + vector[i] * vector[i];
		}
		len = sqrt(len);
		cout << "The length is" << len << ".\n";
	}
	long double ScalarComp(Vector v)
	{
		long double scomp = 0;
		for (int i = 0; i < n; i++)
		{
			scomp = scomp + vector[i] * v.vector[i];
		}
		return scomp;
	}
	Vector& operator+(const Vector &v) 
	{
		for (int i = 0; i < n; i++)
		{
			v.vector[i] = vector[i] + v.vector[i];
		}
		return *this;
	}
	~Vector()
	{
		delete[] vector;
	}
};

void main()
{
	int n = 1;
	int mode = 0;
	int i, j;
	long int comp;
	int cycle = 0;
	long double scalcompos;
	Vector v1, v2, v3;
	cout << "Default size - 0, default length is random.\n";
	while (cycle == 0)
	{
		do
		{
			cout << "\nWhat do you want to do?\n";
			cout << "Press 1 to set the size of the vector.\n";
			cout << "Press 2 to get the size of the vector.\n";
			cout << "Press 3 to set the component of the vector.\n";
			cout << "Press 4 to get the component of the vector.\n";
			cout << "Press 5 to calculate the length of the vector.\n";
			cout << "Press 6 to calculate the scalar composition of two vectors.\n";
			cout << "Press 7 to calculate the sum of two vectors.\n";
			cin >> mode;
		} while ((mode < 1) || (mode > 7));
		switch (mode)
		{
		case 1:
		{
			do
			{
				cout << "Enter the size of the vector from 1 to 20.\n";
				cin >> n;
			} while ((n < 1) || (n > 20));
			v1.SetSize(n);
			break;
		}
		case 2:
			v1.GetSize();
			break;
		case 3:
		{
			cout << "Enter the number of component from 1 to " << n << ".\n";
			cin >> i;
			cout << "Enter the value you want to set.\n";
			cin >> comp;
			v1.SetComp(i, comp);
			break;
		}
		case 4:
		{
			cout << "Enter the number of component from 1 to " << n << ".\n";
			cin >> i;
			v1.GetComp(i);
			break;
		}
		case 5:
		{
			v1.CalcLen();
			break;
		}
		case 6:
		{	
			do
			{
				cout << "Enter the size of two vectors from 1 to 20.\n";
				cin >> n;
			} while ((n < 1) || (n > 20));
			v1.SetSize(n);
			v2.SetSize(n);
			scalcompos = v2.ScalarComp(v1);
			cout << "Scalar Composition: " << scalcompos << "\n";
			break;
		}
		case 7:
		{
			do
			{
				cout << "Enter the size of two vectors from 1 to 20.\n";
				cin >> n;
			} while ((n < 1) || (n > 20));
			v1.SetSize(n);
			v2.SetSize(n);
			v1 = v1 + v2;
			cout << "The result of sum is a new vector. You can check components.\n";
		}
		}
		do
		{
			cout << "Press 0 to continue\nPress 1 to exit\n";
			cin >> cycle;
		} while ((cycle < 0) || (cycle > 1));
	}
}