#pragma once
#include"IGraph.h"
#include<unordered_set>

class SetGraph :public IGraph
{
public:
    SetGraph(int n);
    SetGraph(const IGraph& graph);
    void AddEdge(int from, int to);
    int VerticesCount() const;
    void FindAllAdjacentIn(int vertex, std::vector<int>& vertices) const;
    void FindAllAdjacentOut(int vertex, std::vector<int>& vertices) const;
private:
    std::vector<std::unordered_set<int>>g;
    std::vector<std::unordered_set<int>>reversed_g;
};