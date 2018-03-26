//Permutations P(a,b) = a! / (a-b)!
//Combinations C(a,b) = P(a,b) / b! 

int factorial(int a){
//Factorial: if a == 5, then 5! = 5*4*3*2*1
	constexpr int INT_MAX = numeric_limits<int>::max();
	
	if (a < 0) error("Factorial of a negative is undefined");
	if (a == 0) return 1;
	else 
		for (int x = a - 1; x > 0; x--){
			if (INT_MAX - a < a*x) error("factorial(); has overflowed the int")
			a *= x; 
		}
	return a;
}

int permutations(int a, int b){
	if (a < b) error("Permutations(); Cannot have a < b");
	int value = 0;
	value = factorial(a) / factorial(a-b);
	return value; 
}

int combinations(int a, int b){
	return permutations(a,b) / factorial(b);
}

void print_results(int a){
	cout << "= " << a << endl;
}

int main()
try
{
    while (cin) {
	int a = 0, b = 0, value = 0; 
        cin >> a >> b;
	if (!cin) error("Number expected in main()") 
	char ch; 
	cin >> ch; 
	switch (ch) {
	case 'c': 
		value = combinations(a,b); 
	case 'p': 
		value = permutations(a,b); 
	default: 
		error ("'c' or 'p' expected in main()");
	
	print_results(value);	
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
