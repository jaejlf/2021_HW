#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
// �迭 s[]�� 1���� 9������ ���ڸ� �����ϰ� �迭�� ���ڿ��� �ֱ� ���� s[i]�� ������
// ���ڸ� ���� ��, s[] ���� �ٸ� ĭ�� �ִ� ���ڿ� ��ĥ ���, i ���� �����Ų ����
// ���� s[i]�� ���ϴ� ����� ����Ѵ�.
void main() {
	char s[10];
	s[9] = '\0';
	srand((unsigned)time(NULL));
	for (int i = 0; i < 9; i++) {
		s[i] = rand() % 9 + '1';
		for (int j = 0; j < 9; j++)
			if (s[i] == s[j]) {
				if (i != j) {
					i--;
					break;
				}
			}
	}
	cout << "s = " << s << endl;
}



/*		for (int j = 0; j < 9; j++) {
if (s[i] == s[j]) {
if (i != j) {
i--;
break;
}//������ �κ�
}
}*/