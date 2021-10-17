//https://contest.yandex.ru/contest/29212/problems/1_4/
//53647158
#include<iostream>

#include<assert.h>

#include<cmath>

using namespace std;

int NOD(int& n,int &A)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return A = n / i;
		}
	}
	return A=1;
}

int main()
{
	int n,A,B;
	cin >> n;
	assert(1 < n && n <= 10000000);
	NOD(n,A);
	B = n - A;
	cout << A <<" "<< B;
}
