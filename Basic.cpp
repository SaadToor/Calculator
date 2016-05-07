//Work in progress
#include "Basic.h"
#include "Defines.h"
#include "math.h"
#include "ctype.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace SK {
	Basic::Basic() {
		numberOne_ = 0;
		numberTwo_ = 0;
	}
	Basic::Basic(double numOne, double numTwo) {
		numberOne_ = numOne;
		numberTwo_ = numTwo;
	}
	double Basic::add() const {
		return numberOne_ + numberTwo_;
	}
	double Basic::subtract() const {
		return numberOne_ - numberTwo_;
	}
	double Basic::multiply() const {
		return numberOne_ * numberTwo_;
	}
	double Basic::divide() const {
		return numberOne_ / numberTwo_;
	}
	double Basic::numberOneGetter() const{
		return numberOne_;
	}
	double Basic::numberTwoGetter() const{
		return numberTwo_;
	}
	double Basic::powerOf() const{
		return pow(numberOne_, numberTwo_);
	}
	double Basic::squareroot() const{
		return sqrt(numberOne_);
	}
	int Basic::menu() {
		int selection;
		cout << "Please select one of the options" << endl
			<< "0. Exit" << endl
			<< "1. Set Decimal" << endl
			<< "2. Addition" << endl
			<< "3. Subtraction" << endl
			<< "4. Divition" << endl
			<< "5. Multiplaction" << endl
			<< "6. Exponent Power" << endl
			<< "7. Square root" << endl
			<< ">";
		cin >> selection;
		if (selection < 0 || selection > 7 || isdigit(selection)) {
			selection = -1;
		}
		cin.clear();
		cin.ignore();
		cout << endl;
		return selection;
	}
	ostream& Basic::display(ostream& ostr){
		int choise;
		int decimal;
		while ((choise = menu()) != 0) {
			switch (choise) {
			case -1:
				ostr << "Invalid Number..." << endl
					<< "Please enter one of the options..." << endl << endl;
				break;
			case 0:
				ostr << "Goodbye!!" << endl;
				break;
			case DECIMAL:
				ostr << "Please enter the number of decimal places needed" << endl << endl;
				cin >> decimal;
				ostr << fixed << setprecision(decimal);
				ostr << endl;
				break;
			case ADDITION:
				ostr << "Please enter the two numbers with a space between them to add" << endl
					<< "For example, 52 25" << endl << endl;
				input(cin);
				ostr << add();
				ostr << endl << endl;
				break;
			case SUBTRACTION:
				ostr << "Please enter the two numbers with a space between them to subtract" << endl
					<< "For example, 52 25" << endl << endl;
				input(cin);
				ostr << subtract();
				ostr << endl << endl;
				break;
			case DIVTION:
				ostr << "Please enter the two numbers with a space between them to divide" << endl
					<< "For example, 52 25" << endl << endl;
				input(cin);
				ostr << endl;
				ostr << divide();
				ostr << endl << endl;
				break;
			case MULTIPLACTION:
				ostr << "Please enter the two numbers with a space between them to multiply" << endl
					<< "For example, 52 25" << endl << endl;
				input(cin);
				ostr << multiply();
				ostr << endl << endl;
				break;
			case POWER:
				ostr << "Please enter the two numbers with a space between them to calculator the power" << endl
					<< "For example, 5 7" << endl << endl;
				input(cin);
				ostr << powerOf();
				ostr << endl << endl;
				break;
			case SQUAREROOT:
				ostr << "Please enter the a number to calculate the square root" << endl
					<< "For example, 5" << endl << endl;
				cin >> numberOne_;
				ostr << squareroot();
				ostr << endl << endl;
				break;
			}
		}
		return ostr;
	}
	std::istream & Basic::input(std::istream & istr){
		return istr >> numberOne_ >> numberTwo_;
	}
	std::istream & operator>>(std::istream & istr, Basic & B){
		return B.input(istr);
	}
	ostream& operator<<(ostream& ostr, Basic& B) {
		return B.display(ostr);
	}
}