/*В круг выстроено N человек, пронумерованных числами от 1 до N. 
Будем исключать каждого k-ого до тех пор, пока не уцелеет только один человек.*/
//53657922
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

void ochered(int& k, int& n, int *a)
{
	int c ,nn;
	nn = n; c = 0;
	while (nn != 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0) {
				c += 1;
			}
			if (c == k)
			{
				a[i] = 0;
				nn = nn - 1;
				c = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 5)
		{
			cout << i+1;
		}
	}
}

int main() 
{
	int n, k, nn;
	cin >> n>> k;
	assert(1<=k && k<=n && n<=10000);
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = 5;
	}

	ochered(k, n, a);

	delete [] a;
}