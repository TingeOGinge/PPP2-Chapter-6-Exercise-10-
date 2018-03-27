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
	for (int i = a - b + 1; i < = a; ++i) {
	if (numeric_limits<int>::max() - result < result * i) error("permutations(); integer overflow");	//Post-condition
        result *= i;
	}
	return result;
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
		cout << "Permutations P(a,b): For P(5,3) please enter '5 3 p'"
			"Combinations C(a,b): For C(5,3) please enter '5 3 c' \n";
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
