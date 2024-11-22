#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define ff(i, length) for (int i = 0; i < length; i++)

#define debug 1
#define debug2 1

/* Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a weighted graph, which may represent, for example, road networks. */

class Node {
   public:
    vector<int> connections;
    vector<int> time;
    int mark = -1;
};
#define maxD (99000000)
class DirectedGraph {
   public:
    int numOfNodes;
    vector<int> visited;
    vector<Node> nodes;
    vector<int> distance;

    DirectedGraph(int n) : visited(n, 0), nodes(n), distance(n, maxD) {
        numOfNodes = n;
    }

    ~DirectedGraph() {}

    void addConnection(int n1, int n2, int t) {
        // main connection
        nodes[n1].connections.push_back(n2);
        nodes[n1].time.push_back(t);
    }

    void visitALL(int source) {
        source--;
        fullDFS(source);
    }
    void calculateTime(int source) {
        source--;
        // mark distance of source 0;
        nodes[source].mark = 0;
        distance[source] = 0;
        set<int> s;
        s.insert(source);

        vector<int> newNodes;

        while (1) {
            // visit nodes adajacent to source
            newNodes.clear();
            ff(i, nodes[source].connections.size()) {
                int nodeNo = nodes[source].connections[i];
                int newDistance = distance[source] + nodes[source].time[i];
                if (distance[nodeNo] > newDistance) {
                    distance[nodeNo] = newDistance;
                }
                newNodes.push_back(nodeNo);
            }

            // pick new node which has the minimum distance
            int cmin = maxD;
            int pick = -1;
            ff(i, numOfNodes) {
                // make sure node is not in set
                auto itr = s.find(i);
                if (itr != s.end()) {
                    // found
                    continue;
                }
                if (distance[i] < cmin) {
                    cmin = distance[i];
                    pick = i;
                }
            }
            s.insert(pick);
            if (s.size() == numOfNodes) {
                // all visited break;
                break;
            }
            source = pick;
        }
    }

    void fullDFS(int root) {
        if (visited[root] == 1) {
            return;  // this has already been visited
        }

        // mark this as visited
        visited[root] = 1;

        // visit all sub-nodes
        for (int i = 0; i < nodes[root].connections.size(); i++) {
            int node = nodes[root].connections[i];
            fullDFS(node);
        }
    }
};

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        int ans = -1;
        DirectedGraph g(N);

        // add nodes
        ff(i, times.size()) {
            g.addConnection(times[i][0] - 1, times[i][1] - 1, times[i][2]);
        }

        // run DFS
        g.visitALL(k);

        // see if we can visit all
        ff(i, N) {
            if (g.visited[i] != 1) {
                return -1;
            }
        }

        g.calculateTime(k);
        ff(i, N) { ans = max(ans, g.distance[i]); }
        if (ans == 99000000) {
            return -1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int arr[][3] = {{1, 2, 1}, {2, 3, 7}, {1, 3, 4}, {2, 1, 2}};
    int l = 4;
    int n = 3;
    int k = 1;
    vector<vector<int>> v;
    ff(i, l) {
        vector<int> t;
        t.push_back(arr[i][0]);
        t.push_back(arr[i][1]);
        t.push_back(arr[i][2]);
        v.push_back(t);
    }

    int ans = sol.networkDelayTime(v, n, k);
    cout << "ans::" << ans << endl;
}
