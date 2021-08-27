#include <iostream>
#include <strstream>
using namespace std;

#define SIZE 100
#define BALANCED 0
#define MISMATCHING 1

struct Stack {
	char* store;
	int capacity;
	int top;
};

int create(Stack& s, int size = 100) {
	s.capacity = size;
	s.top = 0;
	return (s.store = new char[size]) != 0;
}

void push(Stack& s, char val) {
	if (s.top < s.capacity) {
		s.store[s.top++] = val;
	}
	else
		cerr << "Error: stack full, can't push" << endl;
}

char pop(Stack& s) {
	if (s.top > 0) {
		return s.store[--s.top];
	}
	else {
		cerr << "Error: pop from an empty stack" << endl;
		return 0;
	}
}

void check_balance(char expr[]) {
	
	Stack s;
	create(s);

	int i = 0;
	int check = BALANCED;

	while (expr[i] != 0) { //remains a next character

		cout << expr[i];
		//check : opening - par
		if (expr[i] == '[' || expr[i] == '{' || expr[i] == '(') {
			push(s, expr[i]);
		}
		
		//chekc : closing - par
		else if((expr[i] == ']' || expr[i] == '}' || expr[i] == ')')){

			if (s.top == 0) { //stack is empty
				check = MISMATCHING;
				break;
			}

			if (expr[i] == ']' && (s.store[s.top - 1] != '[')) {
				check = MISMATCHING;
				break;
			} else if (expr[i] == '}' && (s.store[s.top - 1] != '{')){
				check = MISMATCHING;
				break;
			}
			else if (expr[i] == ')' && (s.store[s.top - 1] != '(')) {
				check = MISMATCHING;
				break;
			} else {
				check = BALANCED;
				pop(s);
			}

		}

		i++;

	} //while-end
	
	if (s.top == 0 && check == BALANCED) {
		check = BALANCED;
	} else{
		check = MISMATCHING;
	}

	//print
	if (check == BALANCED) {
		cout << " : BALANCED !!" << endl;
	}
	else {
		cout << " : MISMATCHING !!" << endl;
	}

}

void main() {

	char par[SIZE] = { 0, };
	while (cin.getline(par, SIZE)) {
		istrstream is(par);
		check_balance(par);
	}
}