#ifndef TARJANDAG_H
#define TARJANDAG_H

// A C++ program to find strongly connected components in a given directed graph using Tarjan's algorithm
// (single DFS)

#include <iostream>
#include <list>
#include <stack>

#define NIL -1

using namespace std;

// A class that represents an directed graph
class TarjanDAG {
public:
    TarjanDAG(const int);

    // function to add an edge to graph
    void addEdge(const int v, const int w);

    // prints strongly connected components
    void SCC();

private:
    // A function used by DFS
    void SCCUtil(int, int [], int [], stack<int> *, bool []);

    int m_numVertices;

    // Pointer to an array containing adjacency lists
    list<int> *m_adjList;

};
#endif // TARJANDAG_H
