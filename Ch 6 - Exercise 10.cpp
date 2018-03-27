#include "std_lib_facilities.h"

//Permutations P(a,b) = a! / (a-b)!
//Combinations C(a,b) = P(a,b) / b! 

int factorial(int a) {
	constexpr int int_max = numeric_limits<int>::max();

	if (a < 0) error("Factorial of a negative is undefined");
	if (a == 0) return 1;
	else
		for (int x = a - 1; x > 0; x--) {
			if (int_max - a < a * x) error("factorial(); int overflow");
				a *= x;
		}
	return a;
}

int permutations(int a, int b) {
	if (a < b) error("Permutations(); Cannot have a < b");
	return factorial(a) / factorial(a - b);
}

int combinations(int a, int b) {
	return permutations(a, b) / factorial(b);
}

void print_results(int a) {
	cout << "= " << a << endl;
}

int main() {
	try
	{
		while (cin) {
			int a, b, value = 0;
			cin >> a >> b;
			if (!cin) error("Number expected in main()");
			char ch;
			cin >> ch;
			switch (ch) {
			case 'c':
				value = combinations(a, b);
				cout << "C(" << a << ", " << b << ") = " << value << endl;
				break;
			case 'p':
				value = permutations(a, b);
				cout << "P(" << a << ", " << b << ") = " << value << endl;
				break;
			default:
				error("'c' or 'p' expected in main()");
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
