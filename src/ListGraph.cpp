//
// Created by Igor Makarevich on 6/16/2022.
//

#include "ListGraph.h"

ListGraph::ListGraph() : IGraph()
{
    myList = new std::map<int, std::vector<int>>;
    for (int i = 0; i < *vertices; ++i) {
        myList->insert(std::pair<int, std::vector<int>> (i, {}));
    }
}

ListGraph::ListGraph(int _ver) : ListGraph()
{
    *vertices = _ver;
}
/*
ListGraph::ListGraph(ListGraph *_oth) : IGraph(_oth)
{
    myList = new std::map<int, std::vector<int>>;
    for (int i = 0; i < _oth->myList->size(); ++i) {
        std::map<int, std::vector<int>>::iterator it = _oth->myList->find(i);
        myList->insert(std::pair<int, std::vector<int>> (it->first, it->second));
    }
}
*/
ListGraph::ListGraph(IGraph *_oth) : IGraph(_oth)
{
    myList = new std::map<int, std::vector<int>>;
    for (int i = 0; i < *vertices; ++i)
    {
        std::vector<int> tempVec;
        _oth->GetNextVertices(i, tempVec);
        myList->insert(std::pair<int, std::vector<int>> (i, tempVec));
    }
}

ListGraph::~ListGraph()
{
    delete vertices;
    delete myList;
}

void ListGraph:: AddEdge(int from, int to)
{
    std::map<int, std::vector<int>>::iterator it = myList->find(from);
    if (it != myList->end()) it->second.push_back(to);
    else myList->insert(std::pair<int, std::vector<int>> (from, {to}));
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &verticesVector)
{
    std::map<int, std::vector<int>>::iterator it = myList->find(vertex);
    for (int i = 0; i < it->second.size(); ++i) {
        verticesVector.push_back(it->second[i]);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &verticesVector)
{
    for (int i = 0; i < *vertices; ++i) {
        std::map<int, std::vector<int>>::iterator it = myList->find(i);
        for (int j = 0; j < it->second.size(); ++j) {
            if (it->second[j] == vertex) verticesVector.push_back(it->second[i]);
            break;
        }
    }
}