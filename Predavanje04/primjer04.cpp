#include<iostream>

using namespace std;

class A {
private:
    static int staticka;
    int nijeStaticka;
public:
    static int f() {
        return staticka + nijeStaticka; // greška! 
    }
};