#include<iostream>

using namespace std;

//template<class T>
//void ispis(T arg) {
//	cout << arg << endl;
//}
//
//template<class T, class... TOstali>
//void ispis(T arg, TOstali... ostali) {
//	cout << arg << endl;
//	ispis(ostali...);
//}

template<class... T>
void ispis(T... args) {
	((cout << args << endl), ...);
}

int main() {

	ispis(100, -1, 'A');

	return 0;
}