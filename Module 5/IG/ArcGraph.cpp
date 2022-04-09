#include"SetGraph.h"
#include "ArcGraph.h"

ArcGraph::ArcGraph(int n) :size(n) {}

ArcGraph::ArcGraph(const IGraph& graph)
{
    size = graph.VerticesCount();
    for (int i = 0; i < size; ++i)
    {
        std::vector<int>vert;
        graph.FindAllAdjacentOut(i, vert);
        for (auto to : vert)
        {
            AddEdge(i, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to)
{
    g.push_back({ from,to });
}

int ArcGraph::VerticesCount() const
{
    return size;
}

void ArcGraph::FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const
{
    for (int i = 0; i < g.size(); ++i)
    {
        if (vertex == g[i].second)
        {
            vertices.push_back(g[i].first);
        }
    }
}

void ArcGraph::FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const
{
    for (int i = 0; i < g.size(); ++i)
    {
        if (vertex == g[i].first)
        {
            vertices.push_back(g[i].second);
        }
    }
}
