#include "bank.h"
#define START_ACC 202100001

int main(int argc, char *argv[]){

	struct account acc;
	FILE *fp;
	int menu;
	int id;
	char name[20];
	int money;
	long pos;

	if(argc != 2){
		printf("file name error ! (파일 이름이 잘못되었습니다.)\n");
		printf("(ex) ./bank filename\n");
		exit(1);
	}

	if((fp = fopen(argv[1], "rb+"))==NULL){
		fp = fopen(argv[1], "ab+");
		fclose(fp);
		fp = fopen(argv[1], "rb+");
	}

	while(1){

		//menu print
		printf("----Menu----\n");
		printf("1. 계좌생성\n");
		printf("2. 입금\n");
	 	printf("3. 출금\n"); 
		printf("4. 잔액조회\n");
		printf("5. 프로그램 종료\n");
		printf("------------\n");
		printf("원하는 메뉴를 입력하시오 : ");
		scanf("%d", &menu);

		//메뉴 입력 오류
		if(menu <= 0 || menu > 5){
			printf("잘못된 메뉴를 입력하였습니다. (메뉴 1 ~ 5)\n");
			printf("\n");
		}

		//5번 :: 종료
		if(menu == 5) return 0;

		//1번 :: 계좌 생성
		else if(menu == 1){

			printf("계좌 생성 메뉴 - 계좌번호, 이름, 초기 입금액을 띄어쓰기로 구분하여 입력해주시기 바랍니다.\n");
			scanf("%d %s %d", &id, name, &money);
		
			//잘못된 계좌번호 입력
			if(id < 202100001 || id > 999999999){
				printf("잘못된 계좌 번호를 입력하였습니다. (유효 계좌번호 202100001 ~ 999999999)\n");
			}
			else{
				pos = (id - START_ACC)*sizeof(acc);
				fseek(fp, pos, SEEK_SET);			
				if(fread(&acc, sizeof(acc), 1, fp) > 0 && (acc.id != 0)){
					printf("이미 존재하는 계좌번호입니다.\n");
				} else{
					fseek(fp, pos, SEEK_SET);
					acc.id = id;
					strcpy(acc.name, name);
					acc.money = money;
					fwrite(&acc, sizeof(acc), 1, fp);
				}
			}
			printf("\n"); 
		} 

		//2번 :: 입금
		else if(menu == 2){

			printf("입금 메뉴\n");
			printf("계좌 번호를 입력하세요 : ");
			scanf("%d", &id);

			//잘못된 계좌번호 입력
			if(id < 202100001 || id > 999999999){
				printf("잘못된 계좌 번호를 입력하였습니다. (유효 계좌번호 202100001 ~ 999999999)\n");
			}
			else{
				pos = (id - START_ACC)*sizeof(acc);
				fseek(fp, pos, SEEK_SET);
				if(fread(&acc, sizeof(acc), 1, fp) > 0 && (acc.id != 0)){
					printf("입금할 금액을 입력하세요 : ");
					scanf("%d", &money);

					fseek(fp, pos, SEEK_SET);
					acc.money += money;
					fwrite(&acc, sizeof(acc), 1, fp);

				} else{
					printf("NO RECORD !\n");
				}
			}
			printf("\n");

		}

		//3번 :: 출금
		else if(menu == 3){

			printf("출금 메뉴\n");
			printf("계좌 번호를 입력하세요 : ");
			scanf("%d", &id);

			//잘못된 계좌번호 입력
			if(id < 202100001 || id > 999999999){
				printf("잘못된 계좌 번호를 입력하였습니다. (유효 계좌번호 202100001 ~ 999999999)\n");
			}
			else{
				pos = (id - START_ACC)*sizeof(acc);
				fseek(fp, pos, SEEK_SET);
				if(fread(&acc, sizeof(acc), 1, fp) > 0 && (acc.id != 0)){
					printf("출금할 금액을 입력하세요 : ");
					scanf("%d", &money);
		
					fseek(fp, pos, SEEK_SET);
					if(acc.money < money) printf("잔액 부족 !\n");
					else{
						acc.money -= money;
						fwrite(&acc, sizeof(acc), 1, fp);
					}
					
				} else{
					printf("NO RECORD !\n");
				}
			}
			printf("\n");

		}

		//4번 :: 잔액조회
		else if(menu == 4){

			printf("잔액조회 메뉴\n");
			printf("계좌 번호를 입력하세요 : ");
			scanf("%d", &id);

			//잘못된 계좌번호 입력
			if(id < 202100001 || id > 999999999){
				printf("잘못된 계좌 번호를 입력하였습니다. (유효 계좌번호 202100001 ~ 999999999)\n");
			}
			else{
				pos = (id - START_ACC)*sizeof(acc);
				fseek(fp, pos, SEEK_SET);
				if(fread(&acc, sizeof(acc), 1, fp) > 0 && (acc.id != 0)){
					fseek(fp, pos, SEEK_SET);
					printf("* 계좌번호 : %d\n", acc.id);
					printf("* 이름 : %s\n", acc.name);
					printf("* 잔액 : %d\n", acc.money);

				} else{
					printf("NO RECORD !\n");
				}
			}
			printf("\n");

		}

		getchar();
	} //while-end
	
	fclose(fp);
	return 0;
	
}	