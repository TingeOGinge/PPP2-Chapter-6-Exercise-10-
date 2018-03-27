#include "stdafx.h"
#include "std_lib_facilities.h"

//Permutations P(a,b) = a! / (a-b)!
//Combinations C(a,b) = P(a,b) / b! 

int factorial(int a) {
	//Calculates factorial
	//Pre-condition: Cannot equate factorial of a negative number 
	//Post-condition: Result cannot cause integer overflow

	if (a < 0) error("Factorial of a negative is undefined");	//Pre-condition
	if (a == 0) return 1;
	else 
		for (int x = a - 1; x > 0; x--) {
			if (numeric_limits<int>::max() - a < a * x) error("factorial(); integer overflow");	//Post-condtion
			a *= x;
		}
	return a;
}

int permutations(int a, int b) {
	//Calculates permutations 
	//Post-condition: Result cannot cause integer overflow	
	int result = 1;
	for (int x = a-b+1; x <= a; ++x) {
		if (numeric_limits<int>::max() - result < result * x) error("permutations(); integer overflow");	//Post-condition
		result *= x;
	}
	return result;
}

int combinations(int a, int b) {
	//Calculcates Permutations
	return permutations(a, b) / factorial(b);
}

int main() {
	//Permutations and Combinations program
	//Pre-conditions: (1. cin must not fail) (2. 'a' and 'b' must be positive integers)
	//Post-conditions: (1. 'a' cannot be smaller than 'b') (2. 'ch' must be a valid input)
	//The program also checks to see if the user has entered a decimal value and rejects it if so 
	try
	{
		int a, b, value;
		double a_dec, b_dec; 
		cout << "Permutations: For P(5,3) please enter '5 3 p' \n"
			"Combinations: For C(5,3) please enter '5 3 c' \n";
		while (cin) {
			cin >> a_dec >> b_dec;
			if (!cin) error("Number expected in main()");	//Pre-condition 
			a = a_dec;
			b = b_dec;
			if (a != a_dec || b != b_dec) error("Whole integers only");	//Prevents users entering values with decimals
			if (a < b) error("Cannot have 'a < b'");	//Post-condition (1)
			if (a < 0 || b < 0) error("Positive integers only");
			char ch;
			cin >> ch;
			switch (ch) {
			case 'c': case 'C':
				value = combinations(a, b);
				cout << "C(" << a << ", " << b << ") = " << value << endl;
				break;
			case 'p': case 'P':
				value = permutations(a, b);
				cout << "P(" << a << ", " << b << ") = " << value << endl;
				break;
			default:
				error("'c' or 'p' expected in main()");	//Post-condition (2)
				break;
			}
		}
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
	}
}
