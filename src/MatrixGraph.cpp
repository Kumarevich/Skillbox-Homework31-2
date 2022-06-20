//
// Created by Igor Makarevich on 6/16/2022.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int _ver) : IGraph()
{
    *vertices = _ver;
    myMatrix = new bool[_ver * _ver];
    for (int i = 0; i < sizeof(myMatrix); ++i) {
        myMatrix[i] = 0;
    }
}
/*
MatrixGraph::MatrixGraph(MatrixGraph *_oth) : IGraph(_oth)
{
    myMatrix = new bool[(*vertices) * (*vertices)];
    for (int i = 0; i < sizeof(myMatrix); ++i)
    {
        myMatrix[i] = _oth->myMatrix[i];
    }
}
*/
MatrixGraph::MatrixGraph(IGraph *_oth)
{
    myMatrix = new bool[(*vertices) * (*vertices)];
    for (int i = 0; i < *vertices; ++i)
    {
        std::vector<int> tempVec;
        _oth->GetNextVertices(i, tempVec);
        for (int j = 0; j < tempVec.size(); ++j) {
            myMatrix[i * (*vertices) + j] = 1;
        }
    }
}

MatrixGraph::~MatrixGraph()
{
    delete myMatrix;
}

void MatrixGraph::AddEdge(int from, int to)
{
    myMatrix[from * (*vertices) + to] = 1;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &verticesVector)
{
    for (int i = 0; i < *vertices; ++i) {
        if (myMatrix[vertex * (*vertices) + i] == 1) verticesVector.push_back(i);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &verticesVector)
{
    for (int i = 0; i < *vertices; ++i) {
        if (myMatrix[i * (*vertices) + vertex] == 1) verticesVector.push_back(i);
    }
}