#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Stog { // Last In First Out princip
public:
	vector<T> stog; 

	void push(T el);
	void pull();
};

template<class T>
void Stog<T>::push(T el) {
	this->stog.insert(this->stog.begin(), el);
}

template<class T>
void Stog<T>::pull() {
	this->stog.erase(this->stog.begin());
}

int main() {

	Stog<int> s1;

	s1.push(1);
	s1.push(2);
	s1.push(3);

	for (int i = 0; i < s1.stog.size(); i++)
		cout << s1.stog[i] << " ";
	cout << endl;

	s1.pull();
	for (int i = 0; i < s1.stog.size(); i++)
		cout << s1.stog[i] << " ";
	cout << endl;

	s1.pull();
	for (int i = 0; i < s1.stog.size(); i++)
		cout << s1.stog[i] << " ";
	cout << endl;

	return 0;
}