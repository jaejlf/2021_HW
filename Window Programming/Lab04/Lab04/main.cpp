#include "Stack.h"
#include <iostream>
#include <strstream>
using namespace std;

#define SIZE 100

void main() {
	
	char par[SIZE] = { 0, };
	while (cin.getline(par, SIZE)) {
		istrstream is(par);
		CStack s;
		s.check_balance(s, par);
	}
}