#include<iostream>
#include"Bubble.h"

using namespace std;

int main() {
	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);

	Bubble x = a + b; //nastat æe novi bubble obujma 6275.27
	cout << x; //blue: 11.44
	Bubble y = x + c;
	cout << y; //green: 20.12

	Bubble z = y - x;
	cout << z; //green: 18.8

	if (z == c)
		cout << "OK" << endl; //OK

	return 0;
}