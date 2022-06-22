#include<iostream>
#include<vector>

using namespace std;

class graph
{
private:
    vector<vector<int>>g, reversed_g, components;
    vector<int>component, top_sort, belong_to_component;
    vector<bool>visited;
    int n, component_id;
public:
    graph(int n)
    {
        g.resize(n);
        reversed_g.resize(n);
        visited.resize(n);
        belong_to_component.resize(n);
        this->n = n;
        component_id = 0;
    }

    void add_edges(int from, int to)
    {
        g[from].push_back(to);
        reversed_g[to].push_back(from);
    }

    void main_dfs()
    {
        for (size_t i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                first_dfs(i);
            }
        }

        visited.assign(n, false);
        for (int i = top_sort.size() - 1; i >= 0; --i)
        {
            if (!visited[top_sort[i]])
            {
                second_dfs(top_sort[i]);
                components.push_back(component);
                component.clear();
                ++component_id;
            }
        }
    }

    void first_dfs(int v)
    {
        visited[v] = true;
        for (size_t to : g[v])
        {
            if (!visited[to])
            {
                first_dfs(to);
            }
        }
        top_sort.push_back(v);
    }

    void second_dfs(int v)
    {
        component.push_back(v);
        belong_to_component[v] = component_id;
        visited[v] = true;
        for (size_t to : reversed_g[v])
        {
            if (!visited[to])
            {
                second_dfs(to);
            }
        }
    }

    int find_all_adjecting_in()
    {
        if (components.size() == 1)
        {
            return 0;
        }
        int in = 0;
        for (size_t i = 0; i < components.size(); ++i)
        {
            int find_in = 1;
            for (size_t from : components[i])
            {
                for (size_t to : g[from])
                {
                    if (i != belong_to_component[to])
                    {
                        find_in = 0;
                    }
                }
            }
            if (find_in)
            {
                ++in;
            }
        }
        return in;
    }

    int find_all_adjecting_out()
    {
        if (components.size() == 1)
        {
            return 0;
        }
        int out = 0;
        for (size_t i = 0; i < components.size(); ++i)
        {
            int find_out = 1;
            for (size_t from : components[i])
            {
                for (size_t to : reversed_g[from])
                {
                    if (i != belong_to_component[to])
                    {
                        find_out = 0;
                    }
                }
            }
            if (find_out)
            {
                ++out;
            }
        }
        return out;
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    graph gr(v);
    for (size_t i = 0; i < e; ++i)
    {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        gr.add_edges(from, to);
    }
    gr.main_dfs();
    cout << max(gr.find_all_adjecting_in(), gr.find_all_adjecting_out());
}
