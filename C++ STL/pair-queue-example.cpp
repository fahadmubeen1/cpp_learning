#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<pair<int, int>> dq;

    dq.push_back(pair<int, int>(1, 2));
    dq.push_back(pair<int, int>(0, 3));

    // other notation dq.push_back(make_pair(1,2));

    pair<int, int> p1(0, 3), p2(1, 2);

    cout << "p1.first::" << p1.first << endl;
    cout << "p2.second::" << p1.second << endl;

    pair<int, int> last = dq.front();

    if (last == p1) {
        cout << "elemetn equal to p1" << endl;
    } else if (last == p2) {
        cout << "element equal to p2" << endl;
    }

    cout << "last.first::" << last.first << endl;
    cout << "last.second::" << last.second << endl;

    return 0;
}
