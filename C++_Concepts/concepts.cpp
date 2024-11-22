#include <iostream>
#include <vector>
using namespace std;

/*
TODO
    const function, arguments 
    exceptions
    const pointer, pointer to a constant different
    :: operator
    C++11
    C++14
    C++17

*/

#define namepsace_  // #concept
/* A namespace is a declarative region that provides a scope to the identifiers
(the names of types, functions, variables, etc) inside it. Namespaces are used
to organize code into logical groups and to prevent name collisions that can
occur especially when your code base includes multiple libraries.

e.g. two namespace can have same name of global variable and functions */

// defining a namepsace
namespace germany {
int john = 2;
void print_name() { cout << "john germany" << endl; }
}  // namespace germany

namespace uk {
int john = 3;
void print_name() { cout << "john uk" << endl; }
}  // namespace uk

#define constant_functions  // #concepts
/* constant function
A constant member function can't modify any non-static data members or call any
member functions that aren't constant. Only allowed inside a class.

For objects that are declared as const, you can only call constant member
functions. The compiler ensures that the constant object is never modified.
*/
class consta_class{
    private:
    public:
    int get_data() const;
    int get_data() const{
        cout<<"constant member funcctions"<<endl;
        return 0;
    }
    int set_data(){
        return 2;
    }
};


void func_const() {
    const class consta_class obj;
    obj.get_data() //we can only call constant function from constant object
    //obj.set_data() //error

#define constant_pointer  // #concepts

    // constant pointer
    //  Value can be modifed address can't be
    char this_char{'a'}, that_char{'b'};
    char *mybuf = &this_char, *yourbuf = &that_char;
    char* const aptr = mybuf;
    *aptr = 'c';  // OK
    // aptr = yourbuf;  Error C3892

    // pointer to a constant
    // Can only point to constant data, pointing address can be modified, but
    // value can't be
    const char* mybuf = "test";
    char* yourbuf = "test2";
    printf_s("%s\n", mybuf);

    const char* bptr = mybuf;  // Pointer to constant data
    printf_s("%s\n", bptr);

    // *bptr = 'a';   // Error
}

// #concept
#define Inheritance

/* Inheritence */
class Car {
    /* If public/protected/private keyword is not used data is assumed to be
     * private by default. */
   private:
    /* Only for this class, not for daughter classes
    Friend class/function can access private data. */

    // Since C++11 or C++14 data can be initialized inline
    // ? maybe it wasn't possible initially.
    int parentData = 1;

    const int c_data = 1;
    const int c_data2;

protected:
    /* Daughter classes have access to this. */

    string name;
    // #concept
#define initializer_list
    /* If no constructor/destructor is defined compiler automatically generates
     * a default constructor which does nothing. */
    Car()
        : c_data2(3)  // This is the only way of initializing constant data if
        // it's not initialized inline
        // This is known as initializer list.
    {
        parentData = -1;
        name = "default car (parent contructor)";
        cout << "Car has been constructed :: " << name << endl;
    }

    /* If we use daughter class like mercedes = new mercedes("some name") we
    won't be able to use parent class constructor unless we explicility overload
    it in daughter class. */
    Car(string name) : c_data2(3) {
        this->name = name;
        cout << "Car has been constructed :: " << name << endl;
    }

public:
    void start() { cout << "[parent]car has been started" << endl; }
    void modelNo() { cout << "[parent]This is a normal car" << endl; }

    // This can't take an argument.
    ~Car() {
        cout << "[parent]car::" << name << " is going to get destroyed" << endl;
    }
};

#define public_private_protected_inheritance_difference
// Inheritance syntax
/* If public is not used than by default it will be
#1 private inheritance meaning, all members of car will be private in daughter
class (while daughter class can't access private member of parent class).
#2 for
protected inheritence public/protected memeber of parent class become protected
in daughter class.
#3 for public inheritance means no change, public member will
be public in daughter class, protected members will be protected in daughter
class */
class AA {
public:
    int x;

protected:
    int y;

private:
    int z;
};

class BB : public AA {
    // x is public
    // y is protected
    // z is not accessible from B
};

class CC : protected AA {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class DD : private AA  // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

// Daughter class
class Mercedes : public Car {
private:
protected:
public:
    /* A private constructor isn't assesble by a daughter class. It will result
    in an error. If we do that. Also a private constructor can't be assessed
    while creating objects in main function. */
    Mercedes() {
        name = "[daugher]default mercedes";
        cout << "[daugher]Mercedes has been created::" << name << endl;
    }

    /* Following is the syntax of calling super class constructor. */
    Mercedes(string name) : Car(name) {
        cout << "[daugher]Mercedes has been created::" << name << endl;
    }

    // Overriding method modelNo
    void modelNo() { cout << "This is a mercedes." << endl; }
    // Start function is not over ridden

    ~Mercedes() {
        cout << "Mercedes::" << name << " is getting destroyed" << endl;
    }
};

#define abstract_class  // #concept
/* An abstract class is a class that is designed to be specifically used as a
base class.
#1 You can't create an object of it.
#2 It needs to have one pure virtual function.
*/
class AbstractCar {
public:
    // Syntax for pure virtual function, means it is must have for daughter
    // class to define it.
    virtual void start() = 0;
    // normal virtual function
    virtual void end() { cout << "normal virtual functions" << endl; }
};

#define static_dynamic_binding_vtable
#define virtual_functions_polymorphism  // #concepts
/* Virtual functions:
    Virtual functions are used when we use parent class pointer to access
    daughter class methods this is advantagious, as same pointer or function
    prototype can be used. static binding is compile time binding, with virtual
    function we have dynamic binding, happens at runtime.

        Performance impact:
            link:
            https://stackoverflow.com/questions/3004501/why-do-we-need-virtual-table
            https://stackoverflow.com/questions/667634/what-is-the-performance-cost-of-having-a-virtual-method-in-a-c-class

        size:
            Each object has a Vtable which means for each virtual function,
            extra pointer bytes will be added. Vtable is a table in each objects
            that contains a function reference corresponding to each function.

        Speed:
            In case of speed, one problem is runtime binding, which has to
            be computed at runtime, i.e. Vtable look up, but that usually takes a cycle. so not much of a concern, while actual cost comes due to pipe line flushing
            as compiler can't predict the brach till the function is call, so entired pipeline has to be flushed.
    */

#define virtual_destructor //#concepts
    /* virtual destructor
    Use : https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
    Virtual destructors are useful when you might potentially delete an instance of
    a derived class through a pointer to base class. Since if you are accessing
    daughter class through a base class pointer, then by default destructor of base
    class will be called. e.g.

    Base *b = new Derived();
    // use b
    delete b; // Here's the problem!
    */

class Person {
public:
    Person() { cout << "person constructor" << endl; }
    virtual void introduction() { cout << "I am a person" << endl; }
    virtual ~Person() { cout << "person desctutor" << endl; }
};

class Student : public Person {
public:
    Student() { cout << "student constructor" << endl; }
    void introduction() { cout << "I am a student" << endl; }
    ~Student() { cout << "student destrcutor" << endl; }
};

#define default_values_function // #concept
// default values
int add(int x = 2, int y = 3) {
    // incase of no values given default 2 & 3 will be used
    return (x + y);
}

#define operator_overloading //#concept
/* Operator overloading
https://www.geeksforgeeks.org/operator-overloading-c/
Note that all operators can't be overloaded e.g.
. (dot), ?:, ::, sizeof
On why they can't be overloaded see
https://www.stroustrup.com/bs_faq2.html#overload-dot
*/
class Books {
private:
public:
    vector<string> books;
    Books operator+(Books const& other) {
        Books b;
        // adding books of first class
        for (string s : this->books) {
            b.books.push_back(s);
        }
        for (string s : other.books) {
            b.books.push_back(s);
        }

        return b;
    }

    // Declaring function to be declared outside
    Books operator-(const Books& other);

    /* Friend so that this global function can access this. */
    friend bool operator>(const Books& one, const Books& two);

    // overloading greather than or less than operator
    void printBooks() {
        for (string s : books) {
            cout << "book :: " << s << endl;
        }
    }
};

#define friend_keyword //#concepts
/* Friend keyword.
    it is used to give access to private/protected members, e.g. linked list
   function can be given access to private data of node Friendship is not
   inherited. It is not mutual if B is a friend of A, A doesn't become a friend
   of B. Class, function (or member.function of another class) can be made friends
*/
class A;  // class declaration synction so C can use A as argument.

class C {
public:
    int xx;
    void showA(A& a);

    // following can't work as A members are yet to be defined
    /*void showA(A& a) {
        cout << a.a_data << endl;
    }*/
};

class B;
class A {
private:
    int a_data;

public:
    // making class B friend
    friend class B;

    // making a global function as friend
    friend void funcShowA(A&);

    // this required class declaration to be above the function
    // making another class member function as friend
    friend void C::showA(A&);

    // this works, with class declaration only
    void showB(B& b) {}
};

class B {
private:
    int b_data;

public:
    void showA(A& a) { cout << a.a_data << endl; }
};

// class C friend function
void C::showA(A& a) {}

void funcShowA(A& a) { cout << a.a_data << endl; }

// sizes are as follows
bool operator>(const Books& one, const Books& two) {
    cout << "greater than oprator";
    return (one.books.size() > two.books.size());
}

// overloading outside the class
Books Books::operator-(const Books& other) {
    cout << "minux overloaded" << endl;
    return other;
}

#define templates  // #concepts
// Templates examples
template <class Type>
Type sub(Type a, Type b) {
    // cout << "size of type::"sizeof(Type) << endl;
    cout << "size of a::" << sizeof(a) << endl;
    return (a + b);
}

int main() {
#define exception_try_catch  // #concepts
    /*
    The try statement allows you to define a block of code to be tested for
    errors while it is being executed. The throw keyword throws an exception
    when a problem is detected, which lets us create a custom error. The catch
    statement allows you to define a block of code to be executed, if an error
    occurs in the try block.

    We can throw multiple type of exceptions, and have multiple catch blocks. If
    we don't know the type of exception, or we want to make a generic catch
    block we use catch(...)

    TODO: write about catching exception in external functions
    */

    /* You can define your own exceptions by inheriting and overriding exception
     * class functionality. Following is the example, which shows how you can
     * use std::exception class to implement your own exception in standard way
     */
    class MyException : public exception {
       public:
        const char* what() const throw() { return "C++ Exception"; }
    };

    int x;
    while (1) {
        cout << "press 8 to break loop, enter exception code" << endl;
        cin >> x;
        try {
            if (x == 1) {
                cout << "throw 404" << endl;
                throw 404;  // caught in int block
            } else if (x == 2) {
                throw "const string";  // caught in generic
            } else if (x == 3) {
                throw 234.234234;  // caught in generic block
            } else if (x == 4) {
                string str = "string error";  // string catch
                throw str;
            } else if (x == 5) {
                char c[] = "char error";  // char pointer catch
                throw c;
            } else if (x == 6) {
                throw MyException();
            } else {
                break;
            }
        } catch (int error_code) {
            cout << "integer caught" << error_code << endl;
        } catch (string s) {
            cout << "string caught::" << s << endl;
        } catch (char* c) {
            cout << "char pointer" << c << endl;
        } catch (MyException& e) {
            cout << "class exception" << e.what() << endl;
        } catch (...) {
            cout << "generic catch block" << endl;
        }
    }

    //Examples onwards

    //namespaces
    cout<<"namespaces"<<endl;
    cout << "germany john" << germany::john << endl;
    cout << "UK john::" << uk::john << endl;
    germany::print_name();
    uk::print_name();

    cout<<"inheritance"<<endl;
    Mercedes* mer =
        new Mercedes("Marsa Marsa");  // first car constructor is called than
    // mercedes constructor
    Mercedes m2;

    // if we don't delete it's destructor will not be called.
    delete mer;  // important, make sure all allocated memory is deleted.

    cout << endl << endl;
    cout << "add::" << add(3) << endl;
    cout << "add::" << add() << endl;
    // add(, 3); This syntax is wrong

    cout << endl << endl;
    Person* p = new Student();
    delete p;

    cout << endl << endl;
    // operator overloading
    Books b1;
    b1.books.push_back("12 rules for life");
    Books b2;
    b2.books.push_back("Crackign the coding intervview");

    Books b3 = b1 + b2;
    b3.printBooks();

    // general

    // References or aliases
    int a = 3;
    int& b = a;  // b is an alias of a
    /* unlike pointers references are permanent. */

    int* ptr = new int[3];
    ptr[0] = 0;
    ptr[1] = 1;
    ptr[2] = 2;

    ptr++;
    ptr++;
    // now ptr point to 2, i.e. ptr[0] will spit 2 instead of 0
    cout << "ptr[0]" << ptr[0] << endl;

    // before deleting bring it back
    ptr--;
    ptr--;
    // freeing up poitner memory
    delete[] ptr;

    cout << endl;
    cout << "tmepate flaot" << sub<float>(3.4, 3.4) << endl;
    cout << "template double" << sub<double>(3.4, 3.4) << endl;
    cout << "template ints " << sub(2, 3) << endl;

    // by default following assume char * whic is 4 bytes
    // cout << "template strings" << sub("fasdfasdf", "adsfasdfasdfadsf") <<
    // endl;

    cout << "template string 2 " << sub<string>("fasdfasdf", "adsfasdfasdfadsf")
        << endl;

    // size of a pointer, by default it compiles to 64 bit type.
    int* x;
    cout << "size of ptr::" << sizeof(x) << endl;

    cout << endl << endl;
}
