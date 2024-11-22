#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/*
Queue vs Priority Queue
        Queue is a list where insertion is done at one end and removal is done
at the other end. Priority queue does not have any ends.

Details : https://www.geeksforgeeks.org/list-cpp-stl/
*/

void printdequeue(deque<int> &d) {
    for (auto itr = d.begin(); itr != d.end(); itr++) {
        cout << *itr << ",";
    }
    cout << endl;
}

int main() {
    // dequeue
    deque<int> dq;

    dq.push_back(1);
    dq.push_front(3);
    dq.push_front(4);
    dq.push_front(5);
    printdequeue(dq);

    // to show elements, index start from 0
    cout << "at 2nd palce " << dq.at(2) << endl;  // at 2 place
    dq.front();
    dq.back();

    // removing elements
    dq.pop_back();
    dq.pop_front();

    // stack, queue, priority queue are implemented on top of normal containers
    // and contains only push and pop functions
    stack<int> s;

    s.push(1);
    s.push(2);

    cout << "stack top" << s.top() << endl;
    s.pop();
    cout << "stack top" << s.top() << endl;

    // queue and priority queue has front() and back()
}

/* other info less
 */