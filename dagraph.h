#ifndef DAGRAPH_H
#define DAGRAPH_H

// C++ program to print DFS traversal from a given vertex in a given graph
#include <iostream>
#include <list>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class DAGraph {
public:
    DAGraph(const int);

    // function to add an edge to graph
    void addEdge(const int, const int);

    // DFS traversal of the vertices reachable from v
    void DFS(int);
    int NumVertices() const { return m_numVertices; }
private:

    // A function used by DFS
    void DFSUtil(int, bool []);

    // No. of vertices
    int m_numVertices;

    // Pointer to an array containing adjacency lists
    list<int> *m_adjList;
};

#endif // DAGRAPH_H
