#include<iostream>

using namespace std;

class A {
public:
    static inline int kol = 0;
    static inline int zive = 0;
    int rb;
    A() { rb = ++kol; zive++; }
    ~A() { zive--; }
};


int main() {
    A obj1, obj2, objX[5];
    cout << "Kreirano je " << A::kol << " instanci tipa A\n"; // A::kol = 7 
    // ispis rednih brojeva instanci 
    cout << obj1.rb << obj2.rb << endl; // 12 

    cout << "zive: " << A::zive << endl;

    for (int i = 0; i < 5; i++)
        cout << objX[i].rb; // 34567 

    cout << "\n" << A::zive << endl;
    return 0;
}
