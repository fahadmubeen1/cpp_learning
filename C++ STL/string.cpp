#include <cstring>
#include <iostream>
#include <string>
using namespace std;

/*
     str.push_back('s');
     str.pop_back();
     all iterator funtion like begin,end, rebing(), rend() are present

*/

int main() {
    string s = "abc";
    s += 'd';  // concatenating char

    string a = "a", b = "b", c = "d";
    string abc = a + b + c + "e" + 'f';  // concatenating strings

    abc.append("gh");           // add to end
    abc.append("12345", 1, 3);  // append at the end, with position 1 of string
                                // "12345" with , 3 characters
    // i.e. 234 are appended in the end

    // string.size() or string.lenght() are same thing
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];  // accessing by array
    }

    // using enhanced for loop
    for (char c : s) {
        cout << c << endl;
    }

    string s1 = "abc";
    string s2 = "def";

    // swap string s1 & s2
    s1.swap(s2);

    // copies a string to a buffer here it comes 2 elements from position 1 of
    // string s1 into buffer ch it replaces the characters present in buffer
    // from the start
    char ch[] = "12345";
    s1.copy(ch, 2, 1);  // char *, length, pos

    string str1 = "01234567";
    auto s4 = str1;

    // to get 34567 via substring
    auto s3 = str1.substr(3, 5);

    // delete 123 by erase
    str1.erase(1, 3);

    // repalce 012 by abc
    s4.replace(0, 3, "abc");

    // find index of 45 in s4
    auto f = s4.find("45");
    if (f != string::npos) {
        // string found
        cout << f << endl;
    }
}