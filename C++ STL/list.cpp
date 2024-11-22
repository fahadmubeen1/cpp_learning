#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

/*
Linked list
Details : https://www.geeksforgeeks.org/list-cpp-stl/

Complexity:
        insertion o(1) even in sorted linked list
        Finding log(n)
*/

void printList(list<int> &listo) {
    list<int>::iterator itr;
    for (itr = listo.begin(); itr != listo.end(); itr++) {
        cout << *itr << ",";
    }
    cout << endl;
}

int main() {
    // creation
    list<int> l;

    // add element to end
    l.push_back(3);
    l.push_back(1);
    l.push_back(2);

    // add element to front
    l.push_front(-50);
    l.push_front(-30);

    cout << " adding element to front and back" << endl;
    printList(l);

    // sort the list
    l.sort();
    cout << "sorted" << endl;
    printList(l);

    // reverse the list
    l.reverse();
    cout << "reverse" << endl;
    printList(l);

    // insert elemnt at index 3
    cout << "insert" << endl;
    auto itr = l.begin();
    // advance iterator to 4th position
    advance(itr, 4);
    // insert() – Inserts new elements in the list before the element at a
    // specified position.
    l.insert(itr, 100);
    cout << "itr::" << *itr << endl;
    l.insert(itr, 102);
    cout << "itr::" << *itr << endl;
    l.insert(itr, 103);
    cout << "itr::" << *itr << endl;
    l.insert(itr, 103);
    cout << "itr::" << *itr << endl;
    l.insert(itr, 103);
    cout << "itr::" << *itr << endl;
    // move back iterator by 2 position
    advance(itr, -2);
    l.insert(itr, -100);
    l.insert(itr, -100);
    printList(l);

    // remove duplicate elemnts
    l.unique();
    cout << "duplicate removed" << endl;
    printList(l);

    // first and last element
    l.front();
    l.back();

    // clear the list
    l.clear();

    /*
    reverse/const iterators are same as vector

    */
}

/* other info less

*/