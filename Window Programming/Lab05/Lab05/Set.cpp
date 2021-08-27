#include <iostream>
using namespace std;
#include "Set.h"

#define NOPROBLEM 10
#define WRONG 11

// default constructor creates an empty set
Set::Set(void)
{
	// TO BE COMPLETED
	size = 0;
	memset(elems, 0, sizeof(elems));

}

// array copy function, local to this file
static void array_copy(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

// copy constructor
Set::Set(Set& s)
{
	// TO BE COMPLETED
	size = s.size;
	array_copy(elems, s.elems, s.size);
}

// creates a set from an array
Set::Set(int a[], int n)
{
	// TO BE COMPLETED
	// Need to make sure NO overflow occurs on the array elems[]
	if (sizeof(a) > MAXSIZE || n > MAXSIZE) cerr << "overflow !" << endl;
	else {
		size = n;
		array_copy(elems, a, n);
	}

}

// return set size
int Set::getsize()
{
	return size;
}

// return the element indexed by i; the lowest index is 1
int Set::get(int i)
{
	if (i < 1 || i > size) {
		cerr << "error in Set::get(): index out of bounds" << endl;
		cerr << "returning 0" << endl;
		return 0;
	}
	else
		return elems[i - 1];
}

// set union
Set Set::operator+(Set s)
{
	int i, j, n;
	int a[MAXSIZE];

	n = size;
	array_copy(a, elems, n);
	for (j = 0; j < s.size; j++) {
		for (i = 0; i < n; i++)
			if (a[i] == s.elems[j])
				break;
		if (i == n)
			a[n++] = s.elems[j];
	}

	return Set(a, n);
}


// set difference
Set Set::operator-(Set s)
{
	// TO BE COMPLETED
	int i, j, n, check;
	int index = 0;
	int a[MAXSIZE];

	n = size;
	for (j = 0; j < n; j++) {

		check = NOPROBLEM;
		for (i = 0; i < s.size; i++) {
			if (elems[j] == s.elems[i]) {
				check = WRONG;
				break;
			}
		} //for - end

		if (check == NOPROBLEM) {
			a[index++] = elems[j];
		}
	} //for - end

	return Set(a, index);

}

// set assignment; return the assigned set
Set Set::operator=(Set s)
{

	size = s.size;
	array_copy(elems, s.elems, size);
	return (*this);

}

// subset relation test
int Set::operator>=(Set s)
{
	// TO BE COMPLETED
	int i, j, n;
	int check = WRONG;

	n = size;

	if (n < s.size) return WRONG;

	for (j = 0; j < s.size; j++) {
		check = WRONG;
		for (i = 0; i < n; i++) {
			if (s.elems[j] == elems[i]) {
				check = NOPROBLEM;
				break;
			}
		} //for - end

		if (check == WRONG) {
			break;
		}

	} //for - end

	if (check == NOPROBLEM) return NOPROBLEM;
	else return WRONG;

}

// set equality test
int Set::operator==(Set s)
{
	// TO BE COMPLETED
	int i, j, n;
	int check = WRONG;
	int same_count;

	n = size;
	if (n != s.size) {
		return WRONG;
	}

	same_count = 0;
	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {
			if (elems[i] == s.elems[j]) {
				same_count++;
				break;
			}
		} //for - end
	} //for - end

	if (same_count == n) return NOPROBLEM;
	else return WRONG;

}

// proper subset relation test
int Set::operator>(Set s)
{
	// TO BE COMPLETED
	int i, j, n;
	int check = WRONG;

	n = size;
	if (n <= s.size) return WRONG; //wrong case

	for (j = 0; j < s.size; j++) {
		check = WRONG;
		for (i = 0; i < n; i++) {
			if (s.elems[j] == elems[i]) {
				check = NOPROBLEM;
				break;
			}
		} //for - end

		if (check == WRONG) {
			break;
		}
	} //for - end

	if (check == NOPROBLEM) return NOPROBLEM;
	else return WRONG;
	
}

// element membership test; return 1 if (*this) contains x
int Set::operator>> (int x)
{
	// TO BE COMPLETED
	int i, n;
	
	n = size;
	for (i = 0; i < n; i++) {
		if (elems[i] == x) return 1;
	}

	return 0;

}