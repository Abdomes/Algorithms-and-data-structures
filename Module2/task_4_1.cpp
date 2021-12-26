#include<iostream>

using namespace std;

void merge(int* arr, int l, int r)
{
    int m = (l + r) / 2;
    int i = l;
    int j = m + 1;
    int k = 0;
    int* c = new int[(r - l) + 1];
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            c[k] = arr[i];
            i++;
        }
        else
        {
            c[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
	    c[k] = arr[i];
	    k++;
	    i++;
    }
    while (j <= r)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (int i = 0; i < k; i++)
    {
        arr[l + i] = c[i];
    }
    delete[] c;
}

void mergesort(int* arr, int l, int r)
{
    if (l < r)
    {
    int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, r);
    }
}

void kelements(int *arr,int &k,int tmpk,int n)
{
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, k - 1);
    while (k + tmpk - 1 < n)
    {
	    k = k + tmpk;
	    int* newarr = new int[tmpk];
	    for (int i = 0; i < tmpk; i++)
	    {
            cin >> newarr[i];
        }
        mergesort(newarr, 0, tmpk - 1);
        int i = 0;
        for (int j = tmpk; j < 2 * tmpk; j++)
        {
            arr[j] = newarr[i];
            i++;
        }
        merge(arr, 0, tmpk * 2 - 1);
        delete[]newarr;
    }
    int count = 0;
    while (k < n)
    {
        count++;
        k++;
    }
    int* newarr = new int[count];
    for (int i = 0; i < count; i++)
    {
        cin >> newarr[i];
    }
    mergesort(newarr, 0, count - 1);
    int i = 0;
    for (int j = tmpk; j < tmpk + count; j++)
    {
        arr[j] = newarr[i];
        i++;
    }
    merge(arr, 0, tmpk * 2 - 1);
    delete[]newarr;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int* arr = new int[2 * k];
    int tmpk = k;
    kelements(arr, k, tmpk, n);
    for (int i = 0; i < tmpk; i++)
    {
        cout << arr[i] << " ";
	}
    delete[]arr;
}
