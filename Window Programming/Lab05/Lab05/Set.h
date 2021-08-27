#pragma once

#define MAXSIZE 100   // ������ �ִ� ũ��

class Set {
	int size;		// ������ ũ��
	int elems[MAXSIZE];	// ���� ����
public:
	Set(void); // default constructor creates an empty set
	Set(Set& s); // copy constructor ((*this) == s)
	Set(int a[], int n); // creates a set from an array
	int getsize(); // return set size
	int get(int i); // return the element indexed by i;                        // the lowest index is 1
	Set operator+(Set s); // set union
	Set operator-(Set s); // set difference
	Set operator=(Set s); // set assignment; return the assigned set
	int operator>(Set s); // proper subset relation test
	int operator>=(Set s); // subset relation test
	int operator==(Set s); // set equality test
	int operator >> (int x); // element membership test
};