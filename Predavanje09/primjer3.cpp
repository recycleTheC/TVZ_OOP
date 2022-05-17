#include<iostream>
#include<vector>
#include<functional>

using namespace std;

int sumaIzabranih(const vector<int>& v, function<bool(int)>kriterij) {
    int s = 0;
    for (int i = 0; i < v.size(); i++) {
        if (kriterij(v[i])) // ukoliko v[i] zadovoljava kriterij
            s += v[i];
    }
    return s;
}

bool isParan(int n) { return n % 2 == 0; }

class CParan {
public:
    bool operator()(int n) const {
        return n % 2 == 0;
    }
};

int main() {

    vector<int> v = { 1,2,3,4,5 };
    
    cout << sumaIzabranih(v, isParan) << endl;
    cout << sumaIzabranih(v, CParan()) << endl;
    cout << sumaIzabranih(v, [](int n) {return n % 2 == 0; }) << endl;

    return 0;
}