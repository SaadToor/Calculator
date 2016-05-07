//Work in progress
#ifndef SK_BASIC_H_
#define SK_BASIC_H_
#include <iostream>

namespace SK {
	class Basic {
		double numberOne;
		double numberTwo;
		double total;
	public:
		Basic();
		Basic(double numOne, double numTwo);

		double add() const;
		double subtract() const;
		double multiply() const;
		double divide() const;
		double powerOf() const;
		double squareroot() const;

		double numberOneGetter() const;
		double numberTwoGetter() const;
		double totalGetter() const;

		int menu();
		std::ostream& display(std::ostream& ostr);

		std::istream& input(std::istream& istr);
	};
	std::istream& operator>>(std::istream& istr, Basic& B);
	std::ostream& operator<<(std::ostream& ostr, Basic& B);
}

#endif
