#include<iostream>
#include<vector>

using namespace std;
template<class T>
void ZamjeniVektor(vector<T>& a, vector<T>& b) {
	vector<T> tmp = a;

	a.clear();
	a = b;

	b.clear();
	b = tmp;
}

int main() {
	vector<int> A = { 1,2,3 };
	vector<int> B = { 10,20,30,40 };

	ZamjeniVektor(A, B);

	for (int x : A) cout << x << " ";
	cout << endl;

	for (int x : B) cout << x << " ";
	cout << endl;

	return 0;
}