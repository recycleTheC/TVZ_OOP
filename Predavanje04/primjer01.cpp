#include<iostream>

using namespace std;

class BankovniRacun {
private:
    double stanje;
    friend double getStanje(BankovniRacun r); // funkcija izvana, ne metoda!
};
double getStanje(BankovniRacun r) {
    return r.stanje; // OK!
}

int main() {
	
}