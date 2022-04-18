#include<iostream>
#include"Matematika.h"
#include <string>

using namespace std;

int main() { 

	short a, b; 
	cin >> a >> b; 
	try { 
		cout << Matematika::Operacija(a, b, '+').rezultat() << endl;
		cout << Matematika::Operacija(a, b, '-').rezultat() << endl;
		cout << Matematika::Operacija(a, b, '*').rezultat() << endl;
		cout << Matematika::Operacija(a, b, '/').rezultat() << endl;
	} catch (short n) { 
		cout << "Broj " << n << " se ne moze dijeliti s 0!\n"; 
	} catch (const char* s) { 
		cout << s;
	} 
	
	return 0; 
}