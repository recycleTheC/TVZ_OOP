#include<iostream>

using namespace std;

class Tekst {
private: 
    string niz;
public:
    Tekst() = default;
    Tekst(string t) : niz(t) {}
    Tekst(const char* t) : niz(t) {}

    Tekst operator + (const Tekst& t) {
        Tekst novi = *this;
        novi.niz += t.niz;
        return novi;
    }

    Tekst operator - (const char znak) {
        Tekst novi;
        
        for (int i = 0; i < this->niz.size(); i++)
        {
            if (this->niz[i] != znak) novi.niz += this->niz[i];
        }

        return novi;
    }

    Tekst operator * (int k) {
        Tekst novi;

        for (int i = 0; i < k; i++)
            novi.niz += this->niz;

        return novi;
    }

    friend ostream& operator << (ostream& izlaz, const Tekst t);
    friend Tekst operator * (int k, Tekst& t);
};

ostream& operator << (ostream& izlaz, const Tekst t) {
    izlaz << t.niz;
    return izlaz;
}

Tekst operator * (int k, Tekst& t) {
    return (t * k);
}

int main() {
    Tekst t = "abc";
    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;                // ispisuje abcabcabc
    cout << 2 * t << endl;            // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;                // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << t + p - 'a' << endl;    // ispisuje bcbcbcbc

    // p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc

    return 0;
}