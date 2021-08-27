/* �� ���α׷��� ���� n�� �Ű������� �޾�
(1! + 2! + ... + n!)�� ����Ͽ� ����ϵ��� �Ǿ� �ִ�.
factorial(n)�� n!�� �����Ѵ�.
fact_sum(n)�� 1! + 2! + ... + n!�� �����Ѵ�. */

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