#include<iostream>
#include<functional>
#include<vector>

using namespace std;

int main() {
    vector<int> brojevi = { 1, 4 , 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22,
                            1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

    int brParnih = 0;
    
    [&brParnih](const vector<int>& v) {
        for (int i = 0; i < v.size(); i++)
            if (v[i] % 2 == 0) brParnih++;
    }(brojevi);

    cout << brParnih << endl; //13
    return 0;
}
