#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iosfwd>

using namespace std;

class Vector // вектор целых чисел
{
	int n;
	int *vector = new int[n];
public:
	Vector()
	{
		for (int i = 0; i <= n; i++)
		{
			vector[i] = 0;
		}
	}
	Vector(int _n)
	{
		n = _n;
	}
	Vector& operator=(const Vector &v)
	{
		for (int i = 0; i <= n; i++)
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
		cout << "The size of the verctor is" << n << "\n";
		cout << endl;
	}
	void SetComp(int i, int a)
	{
		vector[i] = a;
	}
	void GetComp(int i)
	{
		cout << "The" << i << "component of vector is";
		cout << vector[i] << "\n";
		cout << endl;
	}
	void CalcLen()
	{
		double len = 0;
		for (int i = 0; i <= n; i++)
		{
			len = len + vector[i] * vector[i];
		}
		len = sqrt(len);
		cout << "The length is" << len << "\n";
	}
	Vector ScalarComp(Vector v1, Vector v2)
	{
		double scomp = 0;
		for (int i = 0; i <= n; i++)
		{
			scomp = scomp + v1.vector[i]*v2.vector[i];
		}
		return scomp;
	}
	Vector Sum(Vector v1, Vector v2)
	{
		for (int i = 0; i <= n; i++)
		{
			v1.vector[i] = v1.vector[i] + v2.vector[i];
		}
		return v1;
	}
};

void main()
{
	int n = 0;
	int mode = 0;
	int i;
	int comp;
	int cycle;
	Vector v1, v2, v3;
	while (cycle == 0)
	{
		while ((mode<1) && (mode>8))
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
		}
		switch (mode)
		{
		case 1:
		{
			while ((n < 1) && (n > 20))
			{
				cout << "Enter the size of the vector from 1 to 20.\n";
				cin >> n;
			}
			v1.SetSize(n);
			break;
		}
		case 2:
			v1.GetSize;
			break;
		case 3:
		{
			cout << "Enter the number of component you want to set.\n";
			cin >> i;
			cout << "Enter the value you want to set.\n";
			cin >> comp;
			v1.SetComp(i, comp);
			break;
		}
		case 4:
		{
			cout << "Enter the number of component you want to get.\n";
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
			while ((n < 1) && (n > 20))
			{
				cout << "Enter the size of the vectors from 1 to 20.\n";
				cin >> n;
			}
			v1.SetSize(n);
			v2.SetSize(n);

		}

		}
	}
}