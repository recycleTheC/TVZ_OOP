#include<iostream>

using namespace std;

class Osoba {
public:
    string ime, prezime, OIB;
    Osoba(string oib) : OIB(oib)  {}
    void RadniStatus() {
        cout << "Osoba nema radni status" << endl;
    }
};

class Student : public Osoba {
public:
    string nazivStudija, smjer;
    int semestar;

    Student(string oib, int sem) : Osoba(oib), semestar(sem) {}

    void RadniStatus() {
        cout << "Nezaposlen" << endl;
    }
};

int main() {

    Student student("123", 1);

    student.RadniStatus();
    student.Osoba::RadniStatus();

    Student grupaA[3] = {
        Student("1", 1),
        Student("2", 2),
        Student("3", 2)
    };

    // krace

    Student grupaB[3] = {
        {"1", 1},
        {"2", 2},
        {"3", 3},
    };

    int n{ 0 }; // bolje nego int n = 0;

    return 0;
}