#include<iostream>

using namespace std;

class Razlomak {
public:
    int brojnik, nazivnik;
    Razlomak(int br, int naz) : brojnik(br), nazivnik(naz) {}
    Razlomak() = default;

    Razlomak& operator = (int br) {
        this->brojnik = br;
        this->nazivnik = 1;
        return *this;
    }

    Razlomak operator * (Razlomak r) {
        return Razlomak(this->brojnik * r.brojnik, this->nazivnik * r.nazivnik);
    }

    Razlomak& operator ++() {
        this->brojnik += nazivnik;
        return *this;
    }
};

ostream& operator << (ostream & izlaz, Razlomak r) {
    izlaz << r.brojnik << "/" << r.nazivnik;
    return izlaz;
}

Razlomak operator + (int br, Razlomak r) {
    // b1/1 + b2/n2 = (b1 * n2 + b2)/(n2)
    return Razlomak(br * r.nazivnik + r.brojnik, r.nazivnik);
}

int main() {
    Razlomak r1(2, 3), r2;
    r2 = 2; // 2/1
    cout << r1 * r2 << endl;  // 4/3
    cout << 2 + ++r2 << endl; // 5/1
    return 0;
}
