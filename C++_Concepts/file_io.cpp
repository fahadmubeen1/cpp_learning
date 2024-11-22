#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    /* File has three classes
    ifstream - to read a file.
    ofstream - to write to a file.
    fstream  - to both read & write a file. */

    ofstream f1("f1.txt");
    ofstream f2;
    // another way of opening file
    f2.open("f2.txt", ios::out | ios::app);

    // to check if file has been opened successfully
    if (f2.fail() == false) {
        cout << "file opened successfully" << endl;
        // other wasy are
        f2.is_open();  // method
    } else {
        // file wasn't opened
    }

    // the 2nd parameter is about how to open a file with permission which are
    // as follows
    /*
    ate - open the end.
    in - open for reading.
    out - open for writing.
    trunc - previous contents are overwritten when opened for output
    app - apend things to the end of file.
    binary - read file in binary. */

    // write the flowing one,two and three line by line
    f1 << "one 1 one" << endl;
    f1 << "two" << endl;
    f1 << "three" << endl;

    // close the file after it has been written
    f1.close();

    // open the file and append four and five in it
    // with app passed no need for ate to append the the end of file
    f1.open("f1.txt", ios::out | ios::app);
    f1 << "four" << endl;
    f1 << "five" << endl;

    /* add data in the start of the file.
    In standard C/C++ this is not possible, we can override the data but that
    destroys the file if opreation is interrupted, only clean way is to create a
    new file and rename it.
    */
    f1 << "six" << endl;
    f1.close();

    // reading this file
    ifstream f3("f1.txt");
    // reading a file line by line
    string line;
    while (getline(f3, line)) {
        cout << "line::" << line << endl;
    }

    /* offset from files provides the following
    ios::beg, ios::cur, ios::end */

    /*reset to the start of file, following code will only work if we haven't
    reached end of the file, if we have than all subsequent opration will fail,
    to reset the state to good we call clear. than it can work again. */
    f3.clear();
    f3.seekg(0, ios::beg);

    // read the file as complete string
    std::stringstream ss;
    ss << f3.rdbuf();
    string fullFile = ss.str();
    cout << "full file" << endl << ss.str() << endl;

    // reset to the start of file
    f3.clear();
    f3.seekg(0, ios::beg);

    // read the file string by string break at spaces
    string s;
    while (f3 >> s) {
        cout << "strings::" << s << ",";
    }
    cout << endl;

    f3.close();

    // Jump to a specific line in flie
    ofstream f("test.txt");
    for (int i = 0; i < 50; i++) {
        f << "line::" << to_string(i * 10) << endl;
    }
    f.close();

    // jump to a specific line
    ifstream file;
    file.open("test.txt");
    int line_no = 4;
    for (int i = 0; i < line_no; i++) {
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string line;
    file >> line;
    cout << "line::" << line << endl;

    /* Can a file be read in reverse just like we read in forwards?
    Nopes, C++ doesn't support it directly. */

    // Read a binary file, read and write functions

    return 0;
}