#pragma once

#include<iostream>
#include <string>

using namespace std;

class DobavljacIznimka {
private:
	int id;
public:
	DobavljacIznimka(int id) : id(id) {}

	string info() {
		return "Iznimka: Dobavljac " + to_string(id) + " nije pronadjen!";
	}
};