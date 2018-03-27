#include "stdafx.h"
#include "std_lib_facilities.h"

//Permutations P(a,b) = a! / (a-b)!
//Combinations C(a,b) = P(a,b) / b! 

int factorial(int a) {
//Calculates factorial
//Pre-condition: Cannot equate factorial of a negative number 
//Post-condition: Result cannot cause integer overflow
	constexpr int int_max = numeric_limits<int>::max();

	if (a < 0) error("Factorial of a negative is undefined");	//Pre-condition
	if (a == 0) return 1;
	else
		for (int x = a - 1; x > 0; x--) {
			if (int_max - a < a * x) error("factorial(); integer overflow");	//Post-condtion
			a *= x;
		}
	return a;
}

int permutations(int a, int b) {
//Calculates permutations 
	return factorial(a) / factorial(a - b);
}

int combinations(int a, int b) {
//Calculcates Permutations
	return permutations(a, b) / factorial(b);
}

int main() {
//Permutations and Combinations program
//Pre-condition: cin must not fail 
//Post-conditions: (1. 'a' cannot be smaller than 'b') (2. 'ch' must be a valid input)
	try
	{
		int a, b, value;
		cout << "Permutations: For P(5,3) please enter '5 3 p'"
			"Combinations: For C(5,3) please enter '5 3 c' \n";
		while (cin) {			
			cin >> a >> b;
			if (!cin) error("Number expected in main()");	//Pre-condition 
			if (a < b) error("Cannot have 'a < b'");	//Post-condition (1)
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
