#include<iostream>

using namespace std;

class Zivotinja {
public:
    virtual void kretanje() {
        cout << "Zivotinja se krece" << endl;
    }
};

class Pas : public Zivotinja {
public:
    void kretanje() {
        cout << "Pas hoda" << endl;
    }
};

class Riba : public Zivotinja {
public:
    void kretanje() {
        cout << "Riba pliva" << endl;
    }
};

void ispisKretanja(Zivotinja* z) {
    z->kretanje();
}

int main() {

    Pas pas;
    Riba riba;

    //Zivotinja* z = &riba; // pretvorba "na vise"
    //z->kretanje();

    ispisKretanja(&pas);
    ispisKretanja(&riba);

    return 0;
}