//Permutations P(a,b) = a! / (a-b)!
//Combinations C(a,b) = P(a,b) / b! 

factorial(int a){
	if (a < 0) error("Invalid argument factorial()");
	if (a == 0) return 1;
	else 
		for (int x = a - 1; x > 0; x--) {
			a *= x; 
			return a;
		}
}

int permutations(int a, int b){
	if (a < b) error("Invalid arguments permutations()")
	int value = factorial(a) / factorial(a - b);
	return value; 
}

int combinations(int a, int b){
	int value = permutations(a, b); 
	value /= factorial(b);
	return value; 
}

void print_results(int a){
	cout << "= " << a << endl;
}

int main()
try
{
    while (cin) {
	int a = 0, b = 0; 
        cin >> a >> b;
	if (!cin) error("Number expected main()") 
	char ch; 
	cin >> ch; 
	switch (ch) {
	case 'c': 
		value = combinations(a, b); 
	case 'p': 
		value = permutations(a, b); 
	case 'x':
		break;
	default: 
		error ("'c' 'p' or 'x' expected in main()");
	
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
