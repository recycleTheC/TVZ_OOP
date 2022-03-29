#include<iostream>

using namespace std;

class Sat {
private:
    int h, m, s;
public:
    void setSekunde(int noveSekunde) {
        s = noveSekunde;
    }
    int getSekunde() const {
        return s;
    }
};

int main() {

    const Sat budilica;
    budilica.setSekunde(10); // nije moguce jer je objekt konstantan

    cout << budilica.getSekunde() << endl;

	return 0;
}