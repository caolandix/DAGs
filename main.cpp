#include <QCoreApplication>

#include "dagraph.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    DAGraph dsGraph(4);

    for (int i = 0; i < dsGraph.NumVertices(); i++) {
        dsGraph.addEdge(0, 1);
        dsGraph.addEdge(0, 2);
        dsGraph.addEdge(1, 3);
        dsGraph.addEdge(2, 3);
    }

    cout << "Following is Depth First Traversal\n";
    dsGraph.DFS(0);

    return a.exec();
}
