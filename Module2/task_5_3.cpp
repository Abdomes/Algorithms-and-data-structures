#include<iostream>

using namespace std;

void couting_sort(long long* arr, int n, int nibble)
{
    int count[16];
    for (int i = 0; i < 16; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] >> nibble) % 16]++;
    }
    for (int i = 1; i < 16; i++)
    {
        count[i] += count[i - 1];
    }
    long long* tmp = new long long[n];
    for (int j = n - 1; j >= 0; j--)
    {
        tmp[--count[(arr[j] >> nibble) % 16]] = arr[j];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = tmp[i];
    }
    delete[]tmp;
}

void lsd(long long* arr, int n)
{
    for (int i = 0; i < 61; i += 4)
    {
        couting_sort(arr, n, i);
    }
}

int main()
{
    int n;
    cin >> n;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lsd(arr, n);
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}
