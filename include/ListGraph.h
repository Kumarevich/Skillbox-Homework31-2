//
// Created by Igor Makarevich on 6/16/2022.
//

#pragma once
#include <map>
#include "IGraph.h"
#include "MatrixGraph.h"



class ListGraph : public IGraph
{

    std::map<int, std::vector<int>>* myList;

public:
    ListGraph();

    ListGraph(int _ver);

    ListGraph(IGraph *_oth);

   //ListGraph(ListGraph *_oth);

    ~ListGraph();

    void AddEdge(int from, int to);

    void GetNextVertices(int vertex, std::vector<int> &verticesVector);

    void GetPrevVertices(int vertex, std::vector<int> &verticesVector);
};
