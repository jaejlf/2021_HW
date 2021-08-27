/* 이 프로그램은 정수 n을 매개변수로 받아
(1! + 2! + ... + n!)를 계산하여 출력하도록 되어 있다.
factorial(n)은 n!을 리턴한다.
fact_sum(n)은 1! + 2! + ... + n!을 리턴한다. */

#include <iostream>
using namespace std;
#include <stdio.h>

int factorial(int n) {
	int i, prod;
	prod = 1;
	for (i = 2; i <= n; i++)
		prod *= i;
	return prod;
}

int fact_sum(int n) {
	int i, sum;
	sum = 0;
	for (i = n; i > 0; i--)
		sum += factorial(i);
	return sum;
}
void main() {
	int number, sum;
	cout << "Input a number (< 7): ";
	scanf("%d", &number);
	sum = fact_sum(number);
	cout << "Sum is " << sum << endl;
}