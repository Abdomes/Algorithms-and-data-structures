#pragma once
#include "IGraph.h"

class ArcGraph :public IGraph
{
public:
    ArcGraph(int n);
    ArcGraph(const IGraph & graph);
    void AddEdge(int from, int to);
    int VerticesCount() const;
    void FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const;
    void FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const;
private:
    std::vector<std::pair<int, int>>g;
    int size;
};