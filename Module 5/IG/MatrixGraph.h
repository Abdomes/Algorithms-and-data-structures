#pragma once
#include "IGraph.h"

class MatrixGraph :public IGraph
{
public:
    MatrixGraph(int n);
    MatrixGraph(const IGraph& graph);
    void AddEdge(int from, int to);
    int VerticesCount() const;
    void FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const;
    void FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const;
private:
    std::vector<std::vector<bool>>g;
    int size;
};
