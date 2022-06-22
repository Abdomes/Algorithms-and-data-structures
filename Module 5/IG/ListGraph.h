#pragma once
#include "IGraph.h"

class ListGraph :public IGraph
{
public:
    ListGraph(int n);
    ListGraph(const IGraph& graph);
    void AddEdge(int from, int to);
    int VerticesCount() const;
    void FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const;
    void FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const;
private:
    std::vector<std::vector<int>>g, reversed_g;
};