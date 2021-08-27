#include <iostream>
using namespace std;
struct BigInt {
	int digits[100];
	int ndigits;
};
// Converts digit strings into BigInt structures.
// e.g.) "123" ==> (digits = [3, 2, 1], ndigits = 3)
void convert(BigInt *p, char *s) {
	int n = 0;
	int i = 0;
	while (*s++ != '\0') // Find the end of
		n++; 		//the string s

	p->ndigits = n;
	s -= 2;
	while (i < n)
		p->digits[i++] = *s--;
}

// Prints BigInt structures.
// e.g.) For (digits = [3, 2, 1], ndigits = 3),
// it displays "123��
void print(BigInt x) {
	int n = x.ndigits;
	while (--n >= 0)
		cout << x.digits[n] - 48;
}
// Prints "a = 123456789123456789"
void main() {
	BigInt a;
	convert(&a, "123456789123456789");
	cout << "a = ";
	print(a);
	cout << endl;
}


//���� - ������ �ڵ�
/*#include <iostream>
using namespace std;
struct BigInt {
int digits[100];
int ndigits;
};

// Converts digit strings into BigInt structures.
// e.g.) "123" ==> (digits = [3, 2, 1], ndigits = 3)
void convert(BigInt *p, char *s) {
int n = 0;
int i = 0; //�������� 2 �ذ� ����.count �� ���� �߰�
while (*s++ != '\0') // Find the end of
n++; 		//the string s

p->ndigits = n;
s -= 2; //�߰��� / �������� 1. �ּڰ��� ���� ���� ����ִ� ������ 2�� �� +�Ǿ�����
while (i < n) { //�������� 2. �Ųٷ� �����ؾ��ϴµ�, �ùٸ� ������ �����.
p->digits[i++] = *s--;
}
}

// Prints BigInt structures.
// e.g.) For (digits = [3, 2, 1], ndigits = 3),
// it displays "123��
void print(BigInt x) {
int ASCII_NUM = 48; //�߰��κ�
int n = x.ndigits;
while (--n >= 0)
cout << x.digits[n] - ASCII_NUM; //�������� 3. �ƽ�Ű�� ��µ�.,,
}
// Prints "a = 123456789123456789"
void main() {
BigInt a;
convert(&a, "123456789123456789");
cout << "a = ";
print(a);
cout << endl;
}
*/