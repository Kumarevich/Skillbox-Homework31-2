//
// Created by Igor Makarevich on 6/16/2022.
//

#pragma once
#include "IGraph.h"
#include "ListGraph.h"


class MatrixGraph : public IGraph
{
    bool *myMatrix;

public:
    MatrixGraph();

    MatrixGraph(int _ver);

    //MatrixGraph(MatrixGraph *_oth);

    MatrixGraph(IGraph *_oth);

    ~MatrixGraph();

    void AddEdge(int from, int to);

    void GetNextVertices(int vertex, std::vector<int> &verticesVector);

    void GetPrevVertices(int vertex, std::vector<int> &verticesVector);
};


