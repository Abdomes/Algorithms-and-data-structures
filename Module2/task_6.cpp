#include"sort.h"

#include<iostream>

#include<stack>

using namespace std;

void insertionsort(unsigned int* arr, unsigned int size)
{
    for (int i = 1; i < size; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > tmp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

int partition(unsigned int* arr, unsigned int size)
{
    unsigned int mid = size / 2;
    if (arr[mid] < arr[0]) swap(arr[mid], arr[0]);
    if (arr[size - 1] < arr[0]) swap(arr[size - 1], arr[0]);
    if (arr[mid] < arr[size - 1]) swap(arr[size - 1], arr[mid]);
    unsigned int pivot = arr[size - 1];
    int i = 0;
    int j = 0;
    while (j < size - 1)
    {
        if (arr[j] > pivot)
        {
            j++;
        }
        else
        {
            swap(arr[i++], arr[j++]);
        }
    }
    swap(arr[size - 1], arr[i]);
    return i;
}

void Sort(unsigned int* arr, unsigned int size)
{
    stack<int>stck;
    stck.push(0);
    stck.push(size - 1);
    while (!stck.empty())
    {
        int right = stck.top();
        stck.pop();
        int left = stck.top();
        stck.pop();
        if (right - left + 1 < 2)
        {
            insertionsort(arr, size);
        }
        else
        {
            int piv = partition(arr + left, right - left + 1) + left;
            if (piv - left > 1)
            {
                stck.push(left);
                stck.push(piv - 1);
            }
            if (right - piv > 1)
            {
                stck.push(piv + 1);
                stck.push(right);
            }
        }
    }
}
