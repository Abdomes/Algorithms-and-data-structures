#include<iostream>

#include<vector>

#include<assert.h>

using namespace std;

struct boxes
{
    int x, y, z, i;
};

void insertionsort(vector<boxes>& box, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int tmpx = box[i].x;
        int tmpy = box[i].y;
        int tmpz = box[i].z;
        int tmpi = box[i].i;
        for (; j >= 0 && box[j].x > tmpx; j--)
        {
            box[j + 1].x = box[j].x;
            box[j + 1].y = box[j].y;
            box[j + 1].z = box[j].z;
            box[j + 1].i = box[j].i;
        }
        box[j + 1].x = tmpx;
        box[j + 1].y = tmpy;
        box[j + 1].z = tmpz;
        box[j + 1].i = tmpi;
    }
}

int main()
{
    int n;
    cin >> n;
    assert(n <= 10000);
    vector<boxes>box(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        box[i].x = min(x, min(y, z));
        box[i].z = max(x, max(y, z));
        box[i].y = x + y + z - box[i].x - box[i].z;
        box[i].i = i;
    }
    insertionsort(box, n);
    for (auto now : box)
    {
        cout << now.i << " ";
    }
}
