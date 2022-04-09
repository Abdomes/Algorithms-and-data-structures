#include "SetGraph.h"

SetGraph::SetGraph(int n) : g(n), reversed_g(n) {}

SetGraph::SetGraph(const IGraph& graph)
{
    g.resize(graph.VerticesCount());
    reversed_g.resize(graph.VerticesCount());
    for (int i = 0; i < g.size(); ++i)
    {
        std::vector<int>vert;
        graph.FindAllAdjacentOut(i, vert);
        for (auto to : vert)
        {
            AddEdge(i, to);
        }
    }
}

void SetGraph::AddEdge(int from, int to)
{
    g[from].insert(to);
    reversed_g[to].insert(from);
}

int SetGraph::VerticesCount() const
{
    return g.size();
}

void SetGraph::FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const
{
    for (auto to : reversed_g[vertex])
    {
        vertices.push_back(to);
    }
}

void SetGraph::FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const
{
    for (auto to : g[vertex])
    {
        vertices.push_back(to);
    }
}
