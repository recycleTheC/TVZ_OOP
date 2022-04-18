#pragma once

namespace Matematika {
	class Operacija {
	private:
		short operand1, operand2;
		char operacija;
	public:
		Operacija(short a, short b, char operacija);
		short rezultat() const;
	};
}
