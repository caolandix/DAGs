#include "tarjandag.h"


TarjanDAG::TarjanDAG(const int numVertices) {
    m_numVertices = numVertices;
    m_adjList = new list<int>[m_numVertices];
}

void TarjanDAG::addEdge(int v, int w) {
    m_adjList[v].push_back(w);
}

// A recursive function that finds and prints strongly connected
// components using DFS traversal
// nextVertex --> The vertex to be visited next
// discTimes[] --> Stores discovery times of visited vertices
// earliestVertex[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// *pConnectedAncestors -- >> To store all the connected ancestors (could be part
//           of SCC)
// stackMember[] --> bit/index array for faster check whether
//                  a node is in stack
void TarjanDAG::SCCUtil(int nextVertex, int discTimes[], int earliestVertex[], stack<int> *pConnectedAncestors, bool nodeinStack[]) {

    // A static variable is used for simplicity, we can avoid use of static variable by passing a pointer.
    static int time = 0;

    // Initialize discovery time and low value
    discTimes[nextVertex] = earliestVertex[nextVertex] = ++time;
    pConnectedAncestors ->push(nextVertex);
    nodeinStack[nextVertex] = true;

    // Go through all vertices adjacent to this
    for (list<int>::iterator iter = m_adjList[nextVertex].begin(); iter != m_adjList[nextVertex].end(); ++iter) {
        int currVertex = *iter;  // v is current adjacent of 'u'

        // If v is not visited yet, then recur for it
        if (discTimes[currVertex] == -1) {
            SCCUtil(currVertex, discTimes, earliestVertex, pConnectedAncestors, nodeinStack);

            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low value)
            earliestVertex[nextVertex]  = min(earliestVertex[nextVertex], earliestVertex[currVertex]);
        }

        // Update low value of 'u' only of 'currVertex' is still in stack
        // (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low value)
        else {
            if (nodeinStack[currVertex])
                earliestVertex[nextVertex] = min(earliestVertex[nextVertex], discTimes[currVertex]);
        }
    }

    // head node found, pop the stack and print an SCC
    int w = 0;  // To store stack extracted vertices
    if (earliestVertex[nextVertex] == discTimes[nextVertex]) {
        while (pConnectedAncestors ->top() != nextVertex) {
            w = (int)pConnectedAncestors ->top();
            cout << w << " ";
            nodeinStack[w] = false;
            pConnectedAncestors ->pop();
        }
        w = (int) pConnectedAncestors ->top();
        cout << w << "\n";
        nodeinStack[w] = false;
        pConnectedAncestors ->pop();
    }
}

// The function to do DFS traversal. It uses SCCUtil()
void TarjanDAG::SCC() {
    int *pDiscTimes = new int[m_numVertices];
    int *pEarliestVertex = new int[m_numVertices];
    stack<int> *pConnectedAncestors = new stack<int>();
    bool *pNodeinStack = new bool[m_numVertices];

    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < m_numVertices; i++) {
        pDiscTimes[i] = NIL;
        pEarliestVertex[i] = NIL;
        pNodeinStack[i] = false;
    }

    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < m_numVertices; i++) {
        if (pDiscTimes[i] == NIL)
            SCCUtil(i, pDiscTimes, pEarliestVertex, pConnectedAncestors, pNodeinStack);
    }
}
