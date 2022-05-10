#include<iostream>

using namespace std;

//template<class T1, class T2>
//auto suma(T1 a, T2 b) {
//	return a + b;
//}
//
//template<class T1, class T2, class... TOstali>
//auto suma(T1 a, T2 b, TOstali... ostali) {
//	return a + suma(b, ostali...);
//}

template<class... T>
auto suma(T... args) {
	//return (args + ...);
	return (... + args);
}

template<class... T>
auto razlika(T... args) {
	// TEORIJA - razliciti rezultai zbog nacina raspakiravanja
	
	return (args - ...);
	//return (... - args);
}

int main() {

	cout << razlika(100, 10, 20) << endl;

	return 0;
}