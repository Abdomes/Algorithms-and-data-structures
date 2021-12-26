#include<iostream>

#include<vector>

using namespace std;

struct dates
{
    int num;
    int month;
    int year;
    int j;
};

void siftdown(vector<dates>& arr, int i, int n)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int max = i;
    if ((l < n && arr[i].year < arr[l].year) || (l < n && arr[i].year == arr[l].year && arr[i].month < arr[l].month) ||
        (l < n && arr[i].year == arr[l].year && arr[i].month == arr[l].month && arr[i].num < arr[l].num) ||
        (l < n && arr[i].year == arr[l].year && arr[i].month == arr[l].month && arr[i].num == arr[l].num && arr[i].j < arr[l].j))
    {
        max = l;
    }
    if ((r < n && arr[max].year < arr[r].year) || (r < n && arr[max].year == arr[r].year && arr[max].month < arr[r].month) ||
        (r < n && arr[max].year == arr[r].year && arr[max].month == arr[r].month && arr[max].num < arr[r].num) ||
        (r < n && arr[max].year == arr[r].year && arr[max].month == arr[r].month && arr[max].num == arr[r].num && arr[max].j < arr[r].j))
    {
        max = r;
    }
    if (max != i)
    {
        swap(arr[i], arr[max]);
        siftdown(arr, max, n);
    }
}

void builtheap(vector<dates>& arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        siftdown(arr, i, n);
    }
}

void heapsort(vector<dates>& arr, int n)
{
    builtheap(arr, n);    
    int heapsize = n;
    while (heapsize > 1)
    {
        swap(arr[0], arr[heapsize - 1]);
        heapsize--;
        siftdown(arr, 0, heapsize);
    }
}

void count(vector<dates>& arr, int n)
{
    int answer = 0, amount = 0;
    for (int i = 0; i < n; i++)
    {
        amount += arr[i].j;
        if (amount > answer)
        {
            answer = amount)
        }
    }
    cout << answer;
}

int main()
{
    int n;
    cin >> n;
    vector<dates>arr;
    for (int i = 0; i < n; i++)
    {
        int birthnum, birthmonth, birthyear, deathnum, deathmonth, deathyear;
        cin >> birthnum >> birthmonth >> birthyear >> deathnum >> deathmonth >> deathyear;
        int tmpbirthyear = birthyear + 18;
        if ((tmpbirthyear < deathyear) || (tmpbirthyear == deathyear && birthmonth < deathmonth) ||
            (tmpbirthyear == deathyear && birthmonth == deathmonth && birthnum < deathnum))
        {
            arr.push_back({ birthnum,birthmonth,tmpbirthyear,1 });
            tmpbirthyear = birthyear + 80;
            if ((tmpbirthyear < deathyear) || (tmpbirthyear == deathyear && birthmonth < deathmonth) ||
                (tmpbirthyear == deathyear && birthmonth == deathmonth && birthnum < deathnum))
            {
                arr.push_back({ birthnum,birthmonth,tmpbirthyear,-1 });
            }
            else
            {
                arr.push_back({ deathnum,deathmonth,deathyear,-1 });
            }
        }
    }
    heapsort(arr, arr.size());
    count(arr, arr.size());
}
