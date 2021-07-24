#include "main.h"

void printStat(char *pathname, char *file, struct stat *st, char* option, int op){
	
	int i = 0;
	int j = 0;
	int o = 0;
	char *xperms;
		
	// option i
	for(i = 0; i < op; i++){
		if(option[i] == 'i'){
			printf("%10lld ", st->st_ino);
			break;
		}
	}
	
	// option s
	for(i = 0; i < op; i++){
		if(option[i] == 's'){
			printf("%9lld ", st->st_size);
			break;
		}
	}

	// option o, l
	o = 0;
	for(i = 0; i < op; i++){
		if(option[i] == 'o'){
			o = 1; //have o option
			break;
		}
	}
	for(i = 0; i < op; i++){
		if(option[i] == 'l' || option[i] == 'o'){
			printf("%c%s ", type(st->st_mode), perm(st->st_mode));
			printf("%3d ", st->st_nlink);
			printf("%s ", getpwuid(st->st_uid)->pw_name);

			if(o != 1){ //have o option
				printf("%s ", getgrgid(st->st_gid)->gr_name);
			}
			printf("%9lld ", st->st_size);
			printf("%.12s ", ctime(&st->st_mtime) + 4);
			break;
		}
	}

	printf("%s", file);

	// option F
	for(i = 0; i < op; i++){

		if(option[i] == 'F'){
			if(type(st->st_mode) == 'd'){ //directory
				printf("/");
				break;

			} else if(type(st->st_mode) == 'l'){ //symbolic link
				printf("@");
				break; 

			} else{ //execute file
				xperms = perm(st->st_mode);
				for(j = 0; j < sizeof(xperms); j++){
					if(xperms[j] == 'x'){
						printf("*");
						break;
					}
				}
			}
			break;
		}

	}

}
