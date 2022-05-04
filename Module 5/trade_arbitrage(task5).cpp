#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class graph {
private:
    int n;
    vector<vector<double>>arbit;
public:
    graph(int n) {
        this->n = n;
        arbit.resize(n);
        for (int i = 0; i < n; i++) {
            arbit[i].resize(n);
        }
    }

    void add_edges(int from, int to, double course)
    {
        arbit[from][to] = course;
    }

    bool trade() {
        for (int i = 0; i < n; ++i) {
            queue<int> tr;
            vector<double>exchange(n, 1);
            tr.push(i);
            while (!tr.empty()) {
                int vertex = tr.front();                                    
                tr.pop();
                if (exchange[i] > 1 && i == vertex)
                {
                    return true;
                }
                for (int j = 0; j < n; ++j) {
                    if (arbit[vertex][j] == -1) {
                        continue;
                    }
                    double trade = arbit[vertex][j] * exchange[vertex];
                    if (trade > exchange[j]) {
                        tr.push(j);
                        exchange[j] = trade;
                    }
                }
            }
        }
        return false;
    }
};


int main() {
    int n;
    cin >> n;
    graph gr(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                gr.add_edges(i, j, 1);
            }
            else
            {
                double course;
                cin >> course;
                gr.add_edges(i, j, course);
            }
        }
    }
    cout << (gr.trade() ? "YES" : "NO");
}
