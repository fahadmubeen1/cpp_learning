#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

/*
    map are associative container, mapping a key and value pair, key has to
    be unique, and key is something which is use for search, value can be
    matching.
    multi-maps same as maps but allow duplication
*/

/*
    Unordered maps vs maps
    It's a hash table copmared to map which is BST (binary search tree)
    it doesn't have sorted data hence is very fast, in search used when we
    want to quickly found data and sorting of data doesn't matter. Maps on the
    other hand is used when sorting is of some importance for hash table use maps
*/

int main() {
    map<int, int> m;
    unordered_map<int, string> o_map;

    // inserting elemetns in map
    m.insert(pair<int, int>(1, 1));
    m.insert(pair<int, int>(5, 2));
    m.insert(pair<int, int>(3, 2));
    m.insert(pair<int, int>(4, 2));
    m.insert(pair<int, int>(6, 2));

    /* Another style of inserting a pair. */
    m.insert({2, 3});

    // print map
    cout << "key :: value" << endl;
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        cout << itr->first << "::" << itr->second << endl;
    }

    // finding an element by key
    auto itr2 = m.find(2);

    // algos like lower and upper bound don't work for maps for those use the
    // following
    auto it = m.upper_bound(3);  // perform uper bound on map 3

    /* Brackets notation in case of maps. */
    m[8] = 3;  // if key 8 doesn't exist it enters that into the list.

    /* Using reference copy in case of maps */
    /* When a map element is access it usually copies it, this can explode the
    complexity if elements are too large. In that case use by reference access
    to map structrue as follows. */
    auto &a = m[3];  // makes a alias to that element
    m[3];            // this access the element by refernce no copy involved
    auto b = m[3];   // this copies the map element

    return 0;
}