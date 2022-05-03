#pragma once

class IgracIznimka {
private:
	string id;
public:

	IgracIznimka(string id) : id(id) {}

	string poruka() {
		return "Igrac " + id + " vec postoji!";
	}
};