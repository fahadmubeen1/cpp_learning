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

/* Undirected graphcs are same as bi-directional graphs

A directed graph, where edges have direction (meaning that edges with arrows
connect one vertex to another). An undirected graph, where edges have no
direction (meaning arrowless connections). It's basically the same as a directed
graph but has bi-directional connections between nodes*/

class Node {
   public:
    vector<int> connections;
};

class UndirectedGraph {
   public:
    int numOfNodes;
    vector<int> visited;
    vector<Node> nodes;

    UndirectedGraph(int n) : visited(n, 0), nodes(n) { numOfNodes = n; }

    ~UndirectedGraph() {}

    void addConnection(int n1, int n2) {
        nodes[n1].connections.push_back(n2);
        nodes[n2].connections.push_back(n1);
    }

    void fullDFS(int root, int parent) {
        // mark this node as visited
        visited[root] = 1;

        // visit all sub-nodes
        for (int i = 0; i < nodes[root].connections.size(); i++) {
            // visit all nodes except the parent one
            if (nodes[root].connections[i] != parent) {
                // if we are visiting the node first time
                if (visited[nodes[root].connections[i]] == 0) {
                    fullDFS(nodes[root].connections[i], root);
                }
            }
        }
    }
};