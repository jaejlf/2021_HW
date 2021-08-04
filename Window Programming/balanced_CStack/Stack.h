#pragma once
class CStack
{
private:
	char* store;
	int capacity;
	int top;

public:
	CStack();
	~CStack();

	void push(CStack& s, char val);
	char pop(CStack& s);
	void check_balance(CStack& s, char expr[]);

};

