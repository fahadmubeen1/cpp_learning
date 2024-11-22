// AlgoPractice.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>
#include <set>

using namespace std;
/*
Set are container with unique elements, these elements are sorted inside a set
and can be found by using set.find() function return iterator if element found
else point to ending iterator. They are stored in a given order. Implemented as
Binary search trees

Complexity:
        Most operation are log(n)
Insertion log(n)
find log(n)

unordered_set is hash table with O(1) lookup complexity.

multi-set
        they are same as set, but they can have duplicate elements
*/
void printSet(set<int>& s1) {
    for (auto itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << ",";
    }
    cout << endl;
}

void printSetGreather(set<int, greater<int>>& s1) {
    for (auto itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << ",";
    }
    cout << endl;
}
int main() {
    set<int, greater<int>> s1;
    set<int> s2;

    int arr[] = {10, 60, 5, 80, 300, 75, 43, 20, 20, 20, 55};  // length = 11

    for (int i = 0; i < 11; i++) {
        s1.insert(arr[i]);
        s2.insert(arr[i]);
    }

    cout << "set 1 is::";
    printSetGreather(s1);
    cout << "set 2 is ::";
    printSet(s2);

    // check to see if there is 20 inside the set
    auto itr = s1.find(20);
    if (itr != s1.end()) {
        cout << "element found " << endl;
    } else {
        cout << "element not found " << endl;
    }

    // remove elemnt with value 55
    s1.erase(55);
}
