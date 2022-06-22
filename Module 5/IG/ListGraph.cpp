#include "ListGraph.h"

ListGraph::ListGraph(int n) :g(n), reversed_g(n) {}

ListGraph::ListGraph(const IGraph& graph)
{
    g.resize(graph.VerticesCount());
    reversed_g.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        std::vector<int>ver;
        graph.FindAllAdjacentOut(i, ver);
        for (auto to : ver)
        {
            AddEdge(i, to);
        }
    }
}

void ListGraph::AddEdge(int from, int to)
{
    g[from].push_back(to);
    reversed_g[to].push_back(from);
}

int ListGraph::VerticesCount() const
{
    return g.size();
}

void ListGraph::FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const
{
    for (auto to : reversed_g[vertex])
    {
        vertices.push_back(to);
    }
}

void ListGraph::FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const
{
    for (auto to : g[vertex])
    {
        vertices.push_back(to);
    }
}
