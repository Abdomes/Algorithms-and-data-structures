#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int cities(vector<vector<pair<int, int>>>& g, vector<int>& d, vector<bool>visited, int from, int to)
{
    priority_queue<pair<int, int>>q;
    q.push({ 0,from });
    while (!q.empty())
    {
        int dist = -q.top().first;
        int vert = q.top().second;
        visited[vert] = true;
        q.pop();
        if (dist > d[vert])
        {
            continue;
        }
        for (int i = 0; i < g[vert].size(); ++i)
        {
            if (d[g[vert][i].first] > g[vert][i].second + d[vert] && !visited[g[vert][i].first])
            {
                d[g[vert][i].first] = g[vert][i].second + d[vert];
                q.push({ -d[g[vert][i].first] ,g[vert][i].first });
            }
        }
    }
    return d[to];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>>g(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ b,c });
        g[b].push_back({ a,c });
    }
    vector<int>d(n);
    vector<bool>visited(n, false);
    for (int i = 0; i < n; ++i)
    {
        d[i] = 1e9;
    }
    int from, to;
    cin >> from >> to;
    d[from] = 0;
    cout << cities(g, d, visited, from, to);
}
