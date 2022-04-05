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
    Osoba(Osoba&& osoba) {
        // prijenosni konstruktor
        ime = osoba.ime;
        osoba.ime = NULL;
    }
    Osoba& operator = (Osoba&& osoba) {
        delete[] ime;
        ime = osoba.ime;
        osoba.ime = NULL;

        return *this;
    }
};

int main() {
    Osoba Ante = Osoba("Ante");
    Ante = Osoba("Ivica");
    
    cout << Ante.ime << endl;
}