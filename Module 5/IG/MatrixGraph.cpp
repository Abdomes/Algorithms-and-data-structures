#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int n) : g(n, std::vector<bool>(n)), size(n) {}

MatrixGraph::MatrixGraph(const IGraph& graph)
{
    size = graph.VerticesCount();
    g.resize(size, std::vector<bool>(size));
    for (int i = 0; i < size; ++i)
    {
        std::vector<int>ver;
        graph.FindAllAdjacentOut(i, ver);
        for (auto to : ver)
        {
            AddEdge(i, to);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to)
{
    g[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
    return size;
}

void MatrixGraph::FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const
{
    for (int i = 0; i < size; ++i)
    {
        if (g[i][vertex])
        {
            vertices.push_back(i);
        }
    }
}

void MatrixGraph::FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const
{
    for (int i = 0; i < size; ++i)
    {
        if (g[vertex][i])
        {
            vertices.push_back(i);
        }
    }
}
