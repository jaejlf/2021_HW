//quiz3.cpp

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

void main() {

	int rand_num[2];
	int sum = 0;
	int user_answer;
	char again;

	int correct = 0;
	int total = 0;

	while (1) {

		srand((unsigned)time(NULL));
		for (int i = 0; i < 2; i++) {
			rand_num[i] = 10 + rand() % 90;;
		}

		sum = rand_num[0] + rand_num[1];

		cout << rand_num[0] << " + " << rand_num[1] << " = ";
		cin >> user_answer;

		if (sum == user_answer) {
			cout << "Correct!" << endl;
			correct++;
		}
		else {
			cout << "Wrong answer! Try again." << endl;
		}

		total++;

		//입력 버퍼 비우기
		cin.clear();
		cin.ignore();

		cout << "계속하려면 Y, 아니면 아무 키나 : ";
		cin >> again;
		
		if (again != 'Y') break;

	} //while - end

	cout << correct << " correct answers out of " << total << " problems" << endl;

}
