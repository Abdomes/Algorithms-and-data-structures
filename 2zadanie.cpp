/*Вывести разложение натурального числа n на простые множители. 
Простые множители должны быть упорядочены по возрастанию и разделены пробелами.*/
#include<iostream>
#include<assert.h>
using namespace std;
void PrimeFactors(int& n)
{
	int an;
	an = n;
	int chislo;
	for (int i = 2; i <= n; i++)
	{
		chislo = i;
		while (an % chislo == 0)
		{
			an /= chislo;
			cout << chislo<<" ";
		}
	}
}

int main()
{
	int n;
	cin >> n;
	assert(2 <= n);
	assert(n <= 1000000);
	PrimeFactors(n);
}
