#include<iostream>

using namespace std;

class Osoba {
public:
    char* ime; // koristi se char* za demonstraciju
    Osoba(const char* _ime) {
        ime = new char[25];
        strcpy_s(ime, 25, _ime);
    }
    ~Osoba() {
        delete[] ime;
    }
    Osoba(const Osoba& osoba) {
        // duboko kopiranje
        ime = new char[25];
        strcpy_s(ime, 25, osoba.ime);
    }
    Osoba& operator = (const Osoba& osoba) {
        if (this != &osoba) {
            // 1. dealocirati postojece pokazivace
            delete[] ime;
            // 2. provesti duboko kopiranje
            ime = new char[25];
            strcpy_s(ime, 25, osoba.ime);
        }
        return *this;
    }
};

int main() {
    Osoba Ante("Ante");
    Osoba Ivica("Ivica");

    cout << Ante.ime << endl;
    cout << Ivica.ime << endl;

    Ivica = Ante;

    strcpy_s(Ivica.ime, 25, "Ivica");

    cout << Ante.ime << endl;
    cout << Ivica.ime << endl;

}