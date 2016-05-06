//Work in progress
#ifndef SK_BASIC_H_
#define SK_BASIC_H_
#include <iostream>
using namespace std;

namespace SK {
	class Basic {
		double numberOne;
		double numberTwo;
	public:
		Basic();
		Basic(double numOne, double numTwo);

		double add() const;
		double subtract() const;
		double multiply() const;
		double divide() const;
		double roundUp() const;
		double roundDown() const;

		int menu();

		istream& input(istream& istr);
	};
	istream& operator>>(istream& istr, Basic& B);
	ostream& operator<<(ostream& ostr, Basic& B);
}

#endif SK_BASIC_H_
