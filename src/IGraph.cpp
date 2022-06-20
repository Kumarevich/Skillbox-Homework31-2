//
// Created by Igor Makarevich on 6/16/2022.
//

#include "IGraph.h"

IGraph::IGraph() : vertices(new int)
{
    *vertices = 10;
}

IGraph::IGraph(IGraph *_oth) : IGraph()
{
    *vertices = *_oth->vertices;
}

int IGraph::VerticesCount() // Метод должен считать текущее количество вершин
{
    return *vertices;
}

IGraph::~IGraph() {}