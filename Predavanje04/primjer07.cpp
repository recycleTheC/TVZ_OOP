#include<iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5 };

	try
	{
		v.at(5);
	}
	catch (const std::out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
}