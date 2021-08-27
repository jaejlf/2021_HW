#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 512
#define NUMLIST 1
#define NUMRANGE 2
#define ALLNUM 3
#define ONENUM 4

//global
FILE* fp;
int table[BUFSIZE][2];
char buffer[BUFSIZE];

void print(int line_index){

	char printline[BUFSIZE];
	off_t offset = table[line_index][0];

	lseek(fp, offset, SEEK_SET);
	read(fp, printline, table[line_index][1]);
	printf("[%d] %s\n", line_index + 1, printline);

	memset(printline, '\0', sizeof(printline));
	
}

int main(int argc, char *argv[]){
	
	ssize_t nread;
	long bytes = 0;

	int line_index, line_len, line_count;

	int printcase;
	
	int token[BUFSIZE];
	char *tok;
	int tok_len = 0;

	char input[BUFSIZE];

	
	//file check
	fp = open(argv[1], O_RDONLY);
	if(fp == -1){
		printf("file open error\n");
		return 0;
	}
	
	//file size
	while((nread = read(fp, buffer, BUFSIZE)) > 0){
		bytes += nread;
	}
	
	//table set
	line_index = 0;
	line_len = 0;
	line_count = 0;
	table[line_index][0] = 0;
	
	for(int i = 0; i < bytes; i++){

		if(buffer[i] != '\n'){
			line_len++;
		} else{
			line_count++;
			table[line_index][1] = line_len;
			if(i != bytes - 1){
				table[++line_index][0] = i + 1;
			}
			line_len = 0;
		}
	
	} //for-end

	//print
	while(1){

		scanf("%s", input);
		if(input[0] == 'q') break;

		//what case?
		tok_len = 0;
		printcase = ONENUM; //Defalut case
		memset(token, '\0', sizeof(token));

		for(int i = 0; i < strlen(input); i++){
			if(input[i] == ','){ //NUMLIST

				printcase = NUMLIST;
				tok = strtok(input, ",");
				while(tok != NULL){
					token[tok_len] = atoi(tok);
					tok = strtok(NULL, ",");
					tok_len++;
				}
				break;

			} else if(input[i] == '-'){ //NUMRANGE

				printcase = NUMRANGE;
				tok = strtok(input, "-");
				while(tok != NULL){
					token[tok_len] = atoi(tok);
					tok = strtok(NULL, "-");
					tok_len++;
				}
				break;
			
			} else if(input[i] == '*'){ //ALLNUM

				printcase = ALLNUM;
				break;

			}

		}//for-end
		
		//print
		switch(printcase){

		case NUMLIST:
			for(int i = 0; i < tok_len; i++){
				print(token[i] - 1);
			}
			break;

		case NUMRANGE:
			for(int i = token[0]; i < token[1] + 1; i++){
				print(i - 1);
			}
			break;

		case ALLNUM:
			for(int i = 0; i < line_count; i++){
				print(i);
			}
			break;

		case ONENUM: 
			print(atoi(input) - 1);
			break;

		} //switch-case-end
	
	} //while-end


	close(fp);

} //end
