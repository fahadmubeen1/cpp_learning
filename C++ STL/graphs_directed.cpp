#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/* Uni-directional graphs are called directed graphcs
While bi-directional graphs are known as undirected_graphs*/

class Node {
   public:
    vector<int> connections;
    vector<int> reverse;
    int children = 0;
    int siblings = 0;
    int mark = -1;  // indicate it has not been popped
    int rank = -1;
};

class DirectedGraph {
   public:
    int numOfNodes;
    vector<int> visited;
    vector<Node> nodes;

    DirectedGraph(int n) : visited(n, -1), nodes(n) { numOfNodes = n; }

    ~DirectedGraph() {}

    void addConnection(int n1, int n2) {
        // main connection
        nodes[n1].connections.push_back(n2);
        // for info
        nodes[n1].reverse.push_back(n2);
    }

    void fullDFS(int root, int rank) {
        // visit all sub-nodes
        for (int i = 0; i < nodes[root].connections.size(); i++) {
            fullDFS(nodes[root].connections[i], rank + 1);
        }
    }
};
