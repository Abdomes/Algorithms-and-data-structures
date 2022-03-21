#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max_tower(vector < pair<int, int>>& vec)
{
    int count = 0, weight = 0;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i].second >= weight)
        {
            weight += vec[i].first;
            ++count;
        }
    }
    return count;
}

int main()
{
    vector<pair<int, int>>vec;
    int m, s;
    while (cin >> m >> s)
    {
        vec.push_back({ m,s });
    }
    sort(vec.begin(), vec.end());
    cout << max_tower(vec);
}
