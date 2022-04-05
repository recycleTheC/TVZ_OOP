#include<iostream>

using namespace std;

class Osoba {
public:
    char* ime;
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
};

int main() {
    Osoba Ante("Ante");
    Osoba Ivica = Ante; // kopirni konstruktor (kreiranje i inicijalizacija)

    strcpy_s(Ivica.ime, 25, "Ivica");

    cout << Ante.ime << endl;
    cout << Ivica.ime << endl;

}