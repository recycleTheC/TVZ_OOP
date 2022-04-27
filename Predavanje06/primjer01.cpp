#include<iostream>

using namespace std;

class Osoba {
public:
    string ime;
    string prezime;
    Osoba(string _ime, string _prezime) : ime(_ime), prezime(_prezime) {
        //...
    }
};
class Student : public Osoba {
public:
    // prosljeðivanje parametara baznom konstruktoru
    Student(string ime, string prezime) : Osoba(ime, prezime) {
        //...
    }
};


int main() {

    Student student("Ivica", "Ivic");

	return 0;
}