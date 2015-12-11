#include <QCoreApplication>

#include "dagraph.h"
#include "tarjandag.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    DAGraph dsGraph(4);

    cout << "Testing the standard DAG" << endl;
    for (int i = 0; i < dsGraph.NumVertices(); i++) {
        dsGraph.addEdge(0, 1);
        dsGraph.addEdge(0, 2);
        dsGraph.addEdge(1, 3);
        dsGraph.addEdge(2, 3);
    }

    cout << "Following is Depth First Traversal" << endl;
    dsGraph.DFS(0);

    cout << endl << "testing the Tarjan DAG" << endl;
    cout << endl << "SCCs in first graph" << endl;
    TarjanDAG g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.SCC();

    cout << endl << "SCCs in second graph" << endl;
    TarjanDAG g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.SCC();

    cout << endl << "SCCs in third graph" << endl;
    TarjanDAG g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.SCC();

    cout << endl << "SCCs in fourth graph" << endl;
    TarjanDAG g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);
    g4.SCC();

    cout << endl << "SCCs in fifth graph" << endl;
    TarjanDAG g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);
    g5.SCC();

    return a.exec();
}
