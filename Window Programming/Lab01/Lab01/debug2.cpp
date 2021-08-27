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
// it displays "123“
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


//최종 - 수정한 코드
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
int i = 0; //오류원인 2 해결 위한.count 용 변수 추가
while (*s++ != '\0') // Find the end of
n++; 		//the string s

p->ndigits = n;
s -= 2; //추가함 / 오류원인 1. 주솟값이 실제 값이 들어있는 곳보다 2개 더 +되어있음
while (i < n) { //오류원인 2. 거꾸로 저장해야하는데, 올바른 순서로 저장됨.
p->digits[i++] = *s--;
}
}

// Prints BigInt structures.
// e.g.) For (digits = [3, 2, 1], ndigits = 3),
// it displays "123“
void print(BigInt x) {
int ASCII_NUM = 48; //추가부분
int n = x.ndigits;
while (--n >= 0)
cout << x.digits[n] - ASCII_NUM; //오류원인 3. 아스키이 출력됨.,,
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