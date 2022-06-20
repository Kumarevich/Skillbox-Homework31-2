//
// Created by Igor Makarevich on 6/16/2022.
//

#pragma once
#include <vector>


class IGraph {
protected:
    int* vertices; //кол-во вершин

public:
    IGraph();

    IGraph(IGraph *_oth);

    int VerticesCount(); // Метод должен считать текущее количество вершин

    virtual ~IGraph();

    virtual void AddEdge(int from, int to); // Метод принимает вершины начала и конца ребра и добавляет ребро

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices); // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices); // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
};
