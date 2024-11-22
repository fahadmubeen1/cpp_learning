// This is incomplete

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

class Node {
   public:
    Node* left;
    Node* right;
};

class BinaryTree {
   public:
    Node root;
    list<Node*> queue;

    void bfs(Node* root) {
        // if root is not null
        if (root != nullptr) {
            // visit left and push to queue
            if (root->left != nullptr) {
                queue.push_back(root->left);
            }

            // visit right and push to queue
            if (root->right != nullptr) {
                queue.push_back(root->right);
            }

            // if queue is not empty
            if (queue.empty() != true) {
                Node* newRoot = queue.front();
                queue.pop_front();
                bfs(newRoot);
            }
        }
    }
};
