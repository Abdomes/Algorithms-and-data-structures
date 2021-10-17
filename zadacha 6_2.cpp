//https://contest.yandex.ru/contest/29212/problems/6_2/
//54842123
#include<iostream>

#include<assert.h>

using namespace std;

void SiftDown(int* arr, int i, int& n)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int large = i;
	if (arr[i] > arr[left] && left < n)
	{
		large = left;
	}
	if (arr[large] > arr[right] && right < n)
	{
		large = right;
	}
	if (large != i)
	{
		swap(arr[i], arr[large]);
		SiftDown(arr, large, n);
	}
}

void SiftUp(int* arr, int i)
{
	while (i > 0)
	{
		int parent = (i - 1) / 2;
		if (arr[i] <= arr[parent])
		{
			swap(arr[i], arr[parent]);
		}
		i = parent;
	}
}

void PushBack(int*& arr, int element, int& n)
{
	int* newarr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[n] = element;
	n++;
	delete[] arr;
	arr = newarr;
	SiftUp(arr, n - 1);
}

void BuiltHeap(int* arr, int& n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		SiftDown(arr, i, n);
	}
}

int min(int* arr, int& n)
{
	int temp = arr[0];
	arr[0] = arr[n - 1];
	n -= 1;
	SiftDown(arr, 0,n);
	return temp;
}

void time(int *&arr,int &n)
{
	int sum = 0, tempsum = 0;
	while (n != 1)
	{
		tempsum += min(arr, n);
		tempsum += min(arr, n);
		PushBack(arr, tempsum, n);
		sum += tempsum;
		tempsum = 0;
	}
	cout << sum;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	BuiltHeap(arr, n);
	time(arr, n);
	delete[] arr;
}