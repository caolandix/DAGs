#include "dagraph.h"


DAGraph::DAGraph(const int numVertices) {
    m_numVertices = numVertices;
    m_adjList = new list<int>[m_numVertices];
}

void DAGraph::addEdge(const int vertex, const int edge) {
    m_adjList[vertex].push_back(edge); // Add edges to vertex’s list.
}

void DAGraph::DFSUtil(const int vertex, bool visited[]) {

    // Mark the current node as visited and print it
    visited[vertex] = true;
    cout << vertex << " ";

    // Recur for all the vertices adjacent to this vertex
    for (list<int>::iterator iter = m_adjList[vertex].begin(); iter != m_adjList[vertex].end(); ++iter) {
        if (!visited[*iter])
            DFSUtil(*iter, visited);
    }
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void DAGraph::DFS(const int vertex) {

    // Mark all the vertices as not visited
    bool *pVisited = new bool[m_numVertices];
    for (int i = 0; i < m_numVertices; i++)
        pVisited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(vertex, pVisited);
}
