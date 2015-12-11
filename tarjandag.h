#ifndef TARJANDAG_H
#define TARJANDAG_H

// A C++ program to find strongly connected components in a given directed graph using Tarjan's algorithm
// (single DFS)

#include<iostream>
#include <list>
#include <stack>

#define NIL -1

using namespace std;

// A class that represents an directed graph
class TarjanDAG {
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists

    // A Recursive DFS based function used by SCC()
    void SCCUtil(int u, int disc[], int low[],
                 stack<int> *st, bool stackMember[]);
public:
    TarjanDAG(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void SCC();    // prints strongly connected components
};
#endif // TARJANDAG_H
