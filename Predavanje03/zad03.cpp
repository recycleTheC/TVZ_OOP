#include<iostream>

using namespace std;

void f(const int& r) {
	cout << "lvalue: " << r << endl;
}

void f(const int&& r) {
	cout << "rvalue: " << r << endl;
}

int main() {
	int x = 5;
	f(x);
	f(5);

	return 0;
}