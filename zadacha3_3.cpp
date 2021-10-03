/*Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1]. n » m. Найдите их пересечение*/ 
/*537985168*/
#include<iostream>
#include<assert.h>
using namespace std;

void FillArrs(int* A, int& n, int* B, int& m)
{
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> B[i];
	}
}

void Crossing(int* A, int& n, int* B, int& m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (B[i] == A[j])
			{
				cout << A[j] << " ";
				break;
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	assert(n <= 10000 && m <= 10000);
	int* A = new int[n];
	int* B = new int[m];
	FillArrs(A, n, B, m);
	Crossing(A, n, B, m);

	delete[] A;
	delete[] B;
}
