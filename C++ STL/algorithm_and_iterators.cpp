
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// sort(start,end, function)
// binary_search(start,end,value to find) requires the array to be sorted,
// returns boolean reverse(start,end) to reverse a vector 
// max_element(start,end)
// min_element(star,end)
// min(first,second)
// max(first,second)
// accumulate(start,end, initial_sum) sums up element
// count(start,end,element) return number of occurances
// find(start,end, element) returns true if element is found
// lower_bound(start,end,element) returns first element >= element
// upper_bound(start,end,element) returns first element > element
// Note lower_bound and upper_bound don't work for maps, for maps use
// map::lower_bound same for upper bound
// abs() returns absolute of a value

/*
        array algorithms, they return boolean true and false
        any_of(start, end, condition)
        all_of
        none_of
        copy_n(start,end, destination_array_start)

        syntax
        all_of(arr , arr+6, [](int x){ return x>0} );
        //this will ony return true, if all elements are positive else false
*/

/* General container algorithem
        .erase(start, ending value);
*/

int main() {
    vector<int> v;
    vector<pair<int, string>> v2;
    for (int i = 0; i < 20; i++) {
        v.push_back(i);
        v2.push_back({i * 10, to_string(i * 100)});
    }
    auto it = v.begin();

    // There are two types of iterator, random access and other
    it = it + 3;  // This only words with random access iterator like in case of
                  // vectors.

    // For other iterator only ++ and -- operator are overloaded
    it++;
    it--;

    // in those cases for advancing them use two functions next and advance.
    advance(it, 3);  // it updates the iterator it, and increment it by three,
                     // it doesn't return anything
    auto itr_2 = next(v.begin(), 3);  // it doesn't update first argument.

    // adding a custom function to algos, this is lambda notation, note that to
    // use by reference notation you ahve to use const otherwise it will throw
    // compilation error.
    auto ans2 = lower_bound(v.begin(), v.end(), 20,
                            [](int one, int two) { return (one < two); });

    auto ans = lower_bound(
        v2.begin(), v2.end(), pair<int, string>(20, ""),
        [](const pair<int, string> &one, const pair<int, string> &two) {
            return (one.first < two.first);
        });

    cout << ans->second << endl;  // shoudl print 200

    return 0;
}
