#include <stdio.h>

int M[999];
int R[10];

//input() :: M에 입력값 저장
void input(void) {

	int input = 0; //사용자 입력값
	int index = 0;

	while (1) {

		int error = 0;

		scanf("%d", &input);

		if (getchar() != '\n') { //문자 입력
			error = 1;
			while (getchar() != '\n') {}//입력 버퍼 비우기
		}
		else if (input == -1) break; //-1 입력 시 종료
		else if (input < 0) { 	//0보다 작은 값 입력
			error = 1;
		}
		else if (input >= 1000) { 	//1000이상의 값 입력
			M[index++] = input % 1000;
		}
		else {
			M[index++] = input;
		}

		if (error == 1) printf("잘못된 값을 입력했습니다.\n"); //잘못 입력된 값 안내

	} // while-end


}


//interpret()
int interpret(void) {

	int count = 0;	//program counter
	int number = 0; //실행 횟수
	int opcode, op1, op2;

	int i = 0;

	while (1) {

		opcode = M[count] / 100;
		op1 = (M[count] / 10) % 10;
		op2 = M[count] % 10;
		count++;
		number++;

		switch (opcode) {
		case 1: //halt
			break;

		case 2:
			R[op1] = op2;
			break;

		case 3:
			R[op1] += op2;
			R[op1] %= 1000;
			break;

		case 4:
			R[op1] *= op2;
			R[op1] %= 1000;
			break;

		case 5:
			R[op1] = R[op2];
			break;

		case 6:
			R[op1] += R[op2];
			R[op1] %= 1000;
			break;

		case 7:
			R[op1] *= R[op2];
			R[op1] %= 1000;
			break;

		case 8:
			R[op1] = M[R[op2]];
			break;

		case 9:
			M[R[op2]] = R[op1];
			break;

		case 0:
			if (R[op2] != 0) {
				count = R[op1];
			}
			break;

		}
		if (opcode == 1) break; //halt

	} //while-end

	return number;
}


//main, 실행
int main(void) {

	int i = 0;
	int result;

	//M 초기화
	for (i = 0; i < 1000; i++) {
		M[i] = -1;
	}

	//R 초기화
	for (i = 0; i < 10; i++) {
		R[i] = 0;
	}

	input();
	result = interpret();

	//결과 print
	printf("==============================\n");
	printf("[명령어 실행 횟수 : %d]\n", result);
	printf("\n");

	printf("[레지스터 값 출력]\n");
	for (i = 0; i < 10; i++) {
		printf("R[%d] = %d\n", i, R[i]);
	}
	printf("\n");

	printf("[메모리 값 출력]\n");
	for (i = 0; i < 1000; i++) {
		if (M[i] != -1) {
			printf("M[%d] = %d\n", i, M[i]);
		}
	}

	return 0;
}