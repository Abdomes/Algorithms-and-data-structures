//Output the decomposition of a natural number n into prime factors.
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