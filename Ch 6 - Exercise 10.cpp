class Token {
public:
	int a; 
	int b; 
	char kind; 
	Token get(); 
	Token(int a, int b, char ch)
		:a(a), b(b), kind(ch) { }
};


Token Token::get(){
	int a, b; 
	char ch; 
	cin >> a >> b >> ch;
	if (!cin) error("Invalid input") 
	switch(ch) {
	case 'p': case 'c': 
		return Token(a, b, ch)
	default:
		error("Bad token"); 
	}
	
}

factorial(int a){
	for (int x = a; x > 0; x--) a *= x; 
	return a;
}

int permutations(Token t){
	int value = factorial(t.a) / factorial(t.a - t.b);
	ts.putback(t);
	return value; 
}

int combinations(Token t){
	int value = permutations(); 
	switch (t.kind) {
	case 'c':
		value /= factorial(t.b);
		return value; 
	default:
		error("combinations() unexpected kind");
	}
}

int main()
try
{
    while (cin) {
	int value; 
        Token t = t.get();
	switch (t.kind) {
	case 'c': 
		value = combinations(t); 

	case 'p': 
		value = permutations(t); 
	default: 
		error ("Bad token in main()")
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
