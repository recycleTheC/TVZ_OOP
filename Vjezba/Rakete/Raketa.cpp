#include"Raketa.h"

Raketa::Raketa(void) {
	this->gradProizvodnje = new Grad();
	this->domet = 0;
}

Raketa::Raketa(string naziv, double domet) {
	this->naziv = naziv;
	this->domet = domet;
	this->gradProizvodnje = new Grad();
}

Raketa::Raketa(const Raketa& other) {
	this->naziv = other.naziv;
	this->gradProizvodnje = new Grad(*other.gradProizvodnje);
	this->domet = other.domet;

	for (int i = 0; i < other.ciljevi.size(); i++)
	{
		ciljevi.push_back(new Grad(*other.ciljevi[i]));
	}
}

Raketa::~Raketa(void) {
	delete this->gradProizvodnje;

	for (int i = 0; i < ciljevi.size(); i++)
	{
		delete ciljevi[i];
	}
}

Raketa& Raketa::operator=(const Raketa& other) {
	if (this != &other) {
		if (this->gradProizvodnje != NULL) {
			delete this->gradProizvodnje;
		}

		this->gradProizvodnje = new Grad();

		this->naziv = other.naziv;
		*this->gradProizvodnje = *other.gradProizvodnje;
		this->domet = other.domet;

		int n = this->ciljevi.size();

		for (int i = 0; i < n; i++)
		{
			delete this->ciljevi[i];
		}

		this->ciljevi.clear();

		for (int i = 0; i < other.ciljevi.size(); i++)
		{
			ciljevi.push_back(new Grad(*other.ciljevi[i]));
		}
	}

	return *this;
}

Raketa& Raketa::operator=(Raketa&& other) {

	if (this->gradProizvodnje != NULL) {
		delete this->gradProizvodnje;
	}

	this->naziv = other.naziv;
	this->gradProizvodnje = new Grad(*other.gradProizvodnje);
	this->domet = other.domet;

	int n = this->ciljevi.size();

	for (int i = 0; i < n; i++)
	{
		delete this->ciljevi[i];
	}

	this->ciljevi.clear();

	for (int i = 0; i < other.ciljevi.size(); i++)
	{
		ciljevi.push_back(new Grad(*other.ciljevi[i]));
	}

	return *this;
}

void Raketa::setGradProizvodnje(Grad& grad) {
	if (this->gradProizvodnje != NULL) {
		delete this->gradProizvodnje;
	}

	this->gradProizvodnje = new Grad(grad);
}
Grad* Raketa::getGradProizvodnje() {
	return this->gradProizvodnje;
}

void Raketa::dodajCilj(Grad* grad) {
	this->ciljevi.push_back(grad);
}

Grad* Raketa::dohvatiCilj(int index) {
	return this->ciljevi[index];
}

int Raketa::ukCiljeva() {
	return ciljevi.size();
}