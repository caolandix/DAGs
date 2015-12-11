#ifndef DAGRAPH_H
#define DAGRAPH_H

// C++ program to print DFS traversal from a given vertex in a  given graph
#include<iostream>
#include <list>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class DAGraph {
public:
    DAGraph(const int);         // Constructor
    void addEdge(const int, const int);             // function to add an edge to graph
    void DFS(int);                        // DFS traversal of the vertices reachable from v
    int NumVertices() const { return m_numVertices; }
private:
    void DFSUtil(int, bool []);    // A function used by DFS

    int m_numVertices;                      // No. of vertices
    list<int> *m_adjList;                   // Pointer to an array containing adjacency lists

};

#endif // DAGRAPH_H
