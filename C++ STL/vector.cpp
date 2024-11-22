#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
Details : https://www.geeksforgeeks.org/vector-in-cpp-stl/
*/
void printVector(vector<int> &v) {
    // printing
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ",";
    }
    cout << endl;
}

int main() {
    // creation
    vector<int> v;
    vector<int> v2(10);     // create a vector with size 10
    vector<int> v3(10, -1); /* creates a vector with size 10, with
     each element initialized to -1. */

    // adding elements at back
    v.push_back(1);
    v.push_back(10);
    v.push_back(2);

    printVector(v);

    // using enhanced for loop for accessing all elements of vector
    for (int i : v) {
        cout << i << endl;  // i will be v[0], v[1], v[2] and so on
    }
    // sort a vector ascending
    cout << "assending sort" << endl;
    sort(v.begin(), v.end());
    printVector(v);

    // sort a vector desending
    cout << "desending sort" << endl;
    sort(v.begin(), v.end(), greater<int>());
    printVector(v);

    // remove last element
    v.pop_back();
    cout << "after poping" << endl;
    printVector(v);

    /* remove all elemtns)*/
    v.clear();

    /* reverse iterators move from last to end, forward iterator move from start
    to end there are other functions like size, max size, capacity function like
    swap, at help things. erase like erase a vector*/
}

/* other info less

        begin() – Returns an iterator pointing to the first element in the
   vector end() – Returns an iterator pointing to the theoretical element that
   follows the last element in the vector rbegin() – Returns a reverse iterator
   pointing to the last element in the vector (reverse beginning). It moves from
   last to first element rend() – Returns a reverse iterator pointing to the
   theoretical element preceding the first element in the vector (considered as
   reverse end) cbegin() – Returns a constant iterator pointing to the first
   element in the vector. cend() – Returns a constant iterator pointing to the
   theoretical element that follows the last element in the vector. crbegin() –
   Returns a constant reverse iterator pointing to the last element in the
   vector (reverse beginning). It moves from last to first element crend() –
   Returns a constant reverse iterator pointing to the theoretical element
   preceding the first element in the vector (considered as reverse end)

        size() – Returns the number of elements in the vector.
        max_size() – Returns the maximum number of elements that the vector can
   hold. capacity() – Returns the size of the storage space currently allocated
   to the vector expressed as number of elements. resize(n) – Resizes the
   container so that it contains ‘n’ elements. empty() – Returns whether the
   container is empty. shrink_to_fit() – Reduces the capacity of the container
   to fit its size and destroys all elements beyond the capacity. reserve() –
   Requests that the vector capacity be at least enough to contain n elements.

        assign() – It assigns new value to the vector elements by replacing old
   ones push_back() – It push the elements into a vector from the back
        pop_back() – It is used to pop or remove elements from a vector from the
   back. insert() – It inserts new elements before the element at the specified
   position erase() – It is used to remove elements from a container from the
   specified position or range. swap() – It is used to swap the contents of one
   vector with another vector of same type. Sizes may differ. clear() – It is
   used to remove all the elements of the vector container emplace() – It
   extends the container by inserting new element at position emplace_back() –
   It is used to insert a new element into the vector container, the new element
   is added to the end of the vector
*/