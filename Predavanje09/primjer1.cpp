#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// funkcijski objekt:
class Veci {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};


int main() {
	
    vector<int> v = { 1,2,3,4,5 };
    sort(v.begin(), v.end(), Veci());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;

	return 0;
}