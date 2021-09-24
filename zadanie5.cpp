/*Дано натуральное число N. Представить N в виде A + B, так, что НОД(A, B) максимален, 1 ≤ A ≤ B.
Вывести A и B. Если возможно несколько ответов - вывести ответ с минимальным A.*/
#include<iostream>
#include<assert.h>
using namespace std;

void gcf(int& n)
{
	int A, B;
	for (int i = 2; i <= n; i++) 
	{
		if (n % i == 0) 
		{
			A = n/i;
			break;
		}
	}
	B = n - A;
	cout << A << " " << B;
}

int main()
{
	int n;
	cin >> n;
	assert(1 < n);
	assert(n< 10000000);
	gcf(n);
}