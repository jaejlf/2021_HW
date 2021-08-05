#include <stdio.h>

int M[999];
int R[10];

//input() :: M�� �Է°� ����
void input(void) {

	int input = 0; //����� �Է°�
	int index = 0;

	while (1) {

		int error = 0;

		scanf("%d", &input);

		if (getchar() != '\n') { //���� �Է�
			error = 1;
			while (getchar() != '\n') {}//�Է� ���� ����
		}
		else if (input == -1) break; //-1 �Է� �� ����
		else if (input < 0) { 	//0���� ���� �� �Է�
			error = 1;
		}
		else if (input >= 1000) { 	//1000�̻��� �� �Է�
			M[index++] = input % 1000;
		}
		else {
			M[index++] = input;
		}

		if (error == 1) printf("�߸��� ���� �Է��߽��ϴ�.\n"); //�߸� �Էµ� �� �ȳ�

	} // while-end


}


//interpret()
int interpret(void) {

	int count = 0;	//program counter
	int number = 0; //���� Ƚ��
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


//main, ����
int main(void) {

	int i = 0;
	int result;

	//M �ʱ�ȭ
	for (i = 0; i < 1000; i++) {
		M[i] = -1;
	}

	//R �ʱ�ȭ
	for (i = 0; i < 10; i++) {
		R[i] = 0;
	}

	input();
	result = interpret();

	//��� print
	printf("==============================\n");
	printf("[��ɾ� ���� Ƚ�� : %d]\n", result);
	printf("\n");

	printf("[�������� �� ���]\n");
	for (i = 0; i < 10; i++) {
		printf("R[%d] = %d\n", i, R[i]);
	}
	printf("\n");

	printf("[�޸� �� ���]\n");
	for (i = 0; i < 1000; i++) {
		if (M[i] != -1) {
			printf("M[%d] = %d\n", i, M[i]);
		}
	}

	return 0;
}