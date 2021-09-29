/*Дано натуральное число N. Представить N в виде A + B, так, что НОД(A, B) максимален, 1 ≤ A ≤ B.
Вывести A и B. Если возможно несколько ответов - вывести ответ с минимальным A.*/
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