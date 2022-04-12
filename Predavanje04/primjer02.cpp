#include<iostream>

using namespace std;

class A {
public:
    static inline int n = 0; // radi na standardu C++ 17
};

//int A::n = 0; // inicijalizacija statièkog èlana 

int main() {
    A obj1, obj2;
    cout << obj1.n << " " << obj2.n << endl; // 0 0 
    obj1.n = 1;
    cout << obj1.n << " " << obj2.n << endl; // 1 1 
    obj2.n = 2;
    cout << obj1.n << " " << obj2.n << endl; // 2 2 
    return 0;
}