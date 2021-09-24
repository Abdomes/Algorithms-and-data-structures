/*Найти, на сколько нулей оканчивается n!*/
#include<iostream>
#include<assert.h>
using namespace std;

void NumZero(int &n)
{
	int c2 = 0, c5 = 0;
	for (int i = 1; i <= n; i++)
	{
		int chislo = i;
		while (chislo % 5 == 0 || chislo % 2 == 0) 
		{
			if (chislo % 5 == 0) 
			{
				c5 += 1;
				chislo /= 5;
			}
			if (chislo % 2 == 0)
			{
				c2 += 1;
				chislo /= 2;
			}
		}
	}
	cout << min(c5, c2);
}

int main() 
{
	int n;
	cin >> n;
	assert(n <= 1000);
	NumZero(n);
}
