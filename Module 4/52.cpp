#include<iostream>
#include<vector>

using namespace std;

class Tree
{
public:
    Tree(int n)
    {
        this->n = n;
        tree.resize(n);
        count.resize(n);
        d.resize(n);
        summ.resize(n);
    }

    void add(int a, int b)
    {
        tree[a].push_back(b);
    }

    void number_elements_in_subtree(int i)
    {
        for (int j = 0; j < tree[i].size(); ++j)
        {
            number_elements_in_subtree(tree[i][j]);
            count[i] += count[tree[i][j]];
        }
        ++count[i];
    }

    void sum_len_to_children(int i)
    {
        for (int j = 0; j < tree[i].size(); ++j)
        {
            sum_len_to_children(tree[i][j]);
            d[i].second += d[tree[i][j]].first;
            d[i].first += (d[tree[i][j]].first * 2 - d[tree[i][j]].second + 1);
        }
    }

    void fill_root()
    {
        summ[0] = d[0].first;
    }

    void sum_lengths_to_all(int i)
    {
        for (int j = 0; j < tree[i].size(); ++j)
        {
            summ[tree[i][j]] = summ[i] + n - 2 * count[tree[i][j]];
            sum_lengths_to_all(tree[i][j]);
        }
    }

    void print()
    {
        for (int i = 0; i < n; ++i)
        {
            cout << summ[i] << " ";
        }
    }

private:
    int n;
    vector<vector<size_t>>tree;
    vector<size_t>count;
    vector<pair<size_t, size_t>>d;
    vector<size_t>summ;
};

int main()
{
    int n, a, b;
    cin >> n;
    Tree tre(n);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        tre.add(a, b);
    }
    tre.number_elements_in_subtree(0);
    tre.sum_len_to_children(0);
    tre.fill_root();
    tre.sum_lengths_to_all(0);
    tre.print();
}
