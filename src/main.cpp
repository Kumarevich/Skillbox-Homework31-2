#include <iostream>
#include "MatrixGraph.h"
#include "ListGraph.h"

void printResult(std::vector<int> &result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " " << std::endl;
    }
}

int main()
{
    ListGraph* list1 = new ListGraph(10);
    list1->AddEdge(1, 3);
    list1->AddEdge(1, 7);
    list1->AddEdge(1, 9);
    list1->AddEdge(5, 2);
    list1->AddEdge(5, 6);
    list1->AddEdge(8, 4);
    list1->AddEdge(8, 0);
    MatrixGraph* matrix1 = new MatrixGraph(list1);
    ListGraph* list2 = new ListGraph(list1);
    MatrixGraph* matrix2 = new MatrixGraph(matrix1);

    std::vector<int> vector1;
    list1->GetNextVertices(1, vector1);
    printResult(vector1);
    matrix1->GetNextVertices(1, vector1);
    printResult(vector1);
    list2->GetNextVertices(1,vector1);
    printResult(vector1);
    matrix2->GetNextVertices(1, vector1);
    printResult(vector1);
    return 0;
}