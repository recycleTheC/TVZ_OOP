#include<iostream>
#include<vector>

using namespace std;

class Filter {
public:
    virtual vector<int> uvjet(vector<int> vec) final {
        vector<int> rezultat;
        for (int element : vec) {
            if (provjera(element)) {
                rezultat.push_back(element);
            }
        }
        return rezultat;
    }

    virtual bool provjera(int element) = 0;
};

class FilterVeciOd : public Filter {
private:
    int vrijednost = 0;
public:
    FilterVeciOd(int v) : vrijednost(v) {}

    bool provjera(int element) {
        return element > vrijednost;
    }
};

class FilterManjiOd : public Filter {
private:
    int vrijednost = 0;
public:
    FilterManjiOd(int v) : vrijednost(v) {}

    bool provjera(int element) {
        return element < vrijednost;
    }
};

ostream& operator << (ostream& izlaz, const vector<int>& v) {
    for (int br : v)
        izlaz << br << " ";
    
    izlaz << endl;
    return izlaz;
}

int main() {
    vector<int> v = { 14, 3, 18, 5, 6, 10, 2, 8, 1, 7 };

    Filter* filter = new FilterVeciOd(5); // propusti samo vrijednosti vece od 5
    vector<int> rezultat = filter->uvjet(v);
    cout << rezultat; // ispisuje 14 18 6 10 8 7
    delete filter;

    filter = new FilterManjiOd(5); // propusti samo vrijednosti manje od 5
    rezultat = filter->uvjet(v);
    cout << rezultat; // ispisuje 3 2 1
    delete filter;

    return 0;
}