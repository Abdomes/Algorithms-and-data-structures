#include<iostream>
#include<vector>

using namespace std;

bool dfs(int vertex, int col, vector<vector<int>>& g, vector<int>& colour)
{
    colour[vertex] = col;
    for (auto to : g[vertex])
    {
        if (colour[to] == 0)
        {
            if (!dfs(to, 3 - col, g, colour))
            {
                return false;
            }
        }
        if (colour[to] == col)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int v, n;
    cin >> v >> n;
    vector<vector<int>>g(v);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>colour(v);
    (dfs(0, 1, g, colour)) ? cout << "YES" : cout << "NO";
}
