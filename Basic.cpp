//Work in progress
#include "Basic.h"
#include "Defines.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace SK {
	Basic::Basic() {
		numberOne = 0;
		numberOne = 0;
	}
	Basic::Basic(double numOne, double numTwo) {
		numberOne = numOne;
		numberTwo = numTwo;
	}
	double Basic::add() const {
		return numberOne + numberTwo;
	}
	double Basic::subtract() const {
		return numberOne - numberTwo;
	}
	double Basic::multiply() const {
		return numberOne * numberTwo;
	}
	double Basic::divide() const {
		return numberOne / numberTwo;
	}
	int Basic::menu() {
		int selection;
		cout << "Please select one of the options" << endl
			<< "0. Exit" << endl
			<< "1. Addition" << endl
			<< "2. Subtraction" << endl
			<< "3. Divition" << endl
			<< "4. Multiplaction" << endl
			<< ">";
		cin >> selection;
		if (selection < 0 || selection > 4) {
			selection = -1;
		}
		cin.clear();
		cout << endl;
		return selection;
	}
	istream& Basic::input(istream& istr) {
		return istr >> numberOne >> numberTwo;
	}
	istream& operator>>(istream & istr, Basic & B) {
		return B.input(istr);
	}
	ostream& operator<<(ostream & ostr, Basic & B) {
		int choise;
		int decimal;
		while ((choise = B.menu()) != 0) {
			switch (choise) {
			case -1:
				ostr << "Invalid Number..." << endl
					<< "Please enter one of the options..." << endl << endl;
				break;
			case 0:
				ostr << "Goodbye!!" << endl;
				break;
			case ADDITION:
				ostr << "Please enter the two numbers with a space between them to add" << endl 
					<< "For example, 52 25" << endl << endl;
				cin >> B;
				ostr << B.add();
				ostr << endl << endl;
				break;
			case SUBTRACTION:
				ostr << "Please enter the two numbers with a space between them to subtract" << endl
					<< "For example, 52 25" << endl << endl;
				cin >> B;
				ostr << B.subtract();
				ostr << endl << endl;
				break;
			case DIVTION:
				ostr << "Please enter the two numbers with a space between them to divide" << endl
					<< "For example, 52 25" << endl << endl;
				cin >> B;
				ostr << endl;
				ostr << "How many decimal places: ";
				cin >> decimal;
				ostr << fixed << setprecision(decimal) << B.divide();
				ostr << endl << endl;
				break;
			case MULTIPLACTION:
				ostr << "Please enter the two numbers with a space between them to multiply" << endl
					<< "For example, 52 25" << endl << endl;
				cin >> B;
				ostr << B.multiply();
				ostr << endl << endl;
				break;
			}
		}
		return ostr;
	}
}