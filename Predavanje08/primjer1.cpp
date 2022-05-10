#include<iostream>

using namespace std;

template<class T1, class T2>
auto suma(T1 a, T2 b) {
	return a + b;
}

template<class T1, class T2, class... TOstali>
auto suma(T1 a, T2 b, TOstali... ostali) {
	return a + suma(b, ostali...);
}

int main() {

	cout << suma(1, 2.6) << endl;
	cout << suma(1.6, 2) << endl;

	cout << suma(1, 2.6, 4, 2.9, 'A', 4.5, -5) << endl;

	return 0;
}