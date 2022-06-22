#include<iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"

int main()
{
    std::vector<int>vert;
    ListGraph lg(6);
    lg.AddEdge(0, 2);
    lg.AddEdge(0, 3);
    lg.AddEdge(1, 3);
    lg.AddEdge(1, 4);
    lg.AddEdge(2, 5);
    lg.AddEdge(2, 3);
    lg.AddEdge(3, 4);
    ArcGraph lss(lg);
    std::cout << lss.VerticesCount() << std::endl;
    lss.FindAllAdjacentOut(3, vert);
    for (auto to : vert)
    {
        std::cout << to << " ";
    }
}