#include<iostream>
#include<vector>
#include<functional>

using namespace std;

int main() {

    int a = 1, b = 2, suma;

    // 1. nacin

    suma = [](int a, int b) {
        return a + b;
    }  (a, b);

    cout << suma << endl;

    // 2. nacin

    suma = [a, b]() {
        return a + b;
    } ();

    cout << suma << endl;

    // 3. nacin

    [&suma, a, b]() {
        suma = a + b;
    }();

    cout << suma << endl;

    // 4. nacin

    suma = [=]() {
        return a + b;
    }();

    cout << suma << endl;

    // 5. nacin

    [&, a,b]() { // sve se prenosi po referenci osim a i b
        suma = a + b;
    }();

    cout << suma << endl;

    // ili

    [=, &suma]() { // sve se prenosi po vrijednosti osim sume
        suma = a + b;
    }();

    cout << suma << endl;

    // rekurzivno pozivanje!!!

    function<int(int, int)> sumiraj = [&sumiraj](int a, int b) -> int {
        if (a > b)
            return 0;
        return a + sumiraj(a + 1, b);
    };
    
    cout << sumiraj(1, 3); // 6

    return 0;
}