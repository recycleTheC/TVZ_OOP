#include<iostream>
#include<vector>

using namespace std;

void ispis(const vector<int>& r) {
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
}

int main() {

    vector<int> v{1,2,3,4,5};
    ispis(v);

    return 0;
}