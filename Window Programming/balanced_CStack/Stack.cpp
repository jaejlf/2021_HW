#include "Stack.h"
#include <iostream>
using namespace std;

#define SIZE 100
#define BALANCED 0
#define MISMATCHING 1

//생성자
CStack::CStack()
{
	capacity = SIZE;
	top = 0;
	store = new char[SIZE];
}

//소멸자
CStack::~CStack()
{
	delete[] store;
}

//멤버함수
void CStack::push(CStack& s, char val) {
	if (s.top < s.capacity) {
		s.store[s.top++] = val;
	}
	else
		cerr << "Error: stack full, can't push" << endl;
}

char CStack::pop(CStack& s) {
	if (s.top > 0) {
		return s.store[--s.top];
	}
	else {
		cerr << "Error: pop from an empty stack" << endl;
		return 0;
	}
}

void CStack::check_balance(CStack& s, char expr[]) {

	int i = 0;
	int check = BALANCED;

	while (expr[i] != 0) { //remains a next character

		cout << expr[i];
		//check : opening - par
		if (expr[i] == '[' || expr[i] == '{' || expr[i] == '(') {
			push(s, expr[i]);
		}

		//chekc : closing - par
		else if ((expr[i] == ']' || expr[i] == '}' || expr[i] == ')')) {

			if (s.top == 0) { //stack is empty
				check = MISMATCHING;
				break;
			}

			if (expr[i] == ']' && (s.store[s.top - 1] != '[')) {
				check = MISMATCHING;
				break;
			}
			else if (expr[i] == '}' && (s.store[s.top - 1] != '{')) {
				check = MISMATCHING;
				break;
			}
			else if (expr[i] == ')' && (s.store[s.top - 1] != '(')) {
				check = MISMATCHING;
				break;
			}
			else {
				check = BALANCED;
				pop(s);
			}

		}

		i++;

	} //while-end

	if (s.top == 0 && check == BALANCED) {
		check = BALANCED;
	}
	else {
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