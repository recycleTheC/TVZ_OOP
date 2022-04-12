#include<iostream>

using namespace std;

class Iznimka_Dijeljenje {
public:
    double broj1, broj2;
    Iznimka_Dijeljenje(double x, double y) : broj1(x), broj2(y) {}
    // ispis poruke o grešci 
    void ispis() {
        cout << "Iznimka_Dijeljenje: broj " << broj1
            << " ne moze se podijeliti s " << broj2 << "!";
    }
};

int main() {
    double a, b, c;

    try
    {
        cin >> a >> b;

        if (b == 0)
            throw Iznimka_Dijeljenje(a, b);

        c = a / b;

        cout << c;
    }
    catch (Iznimka_Dijeljenje iznimka)
    {
        iznimka.ispis();
    }
}