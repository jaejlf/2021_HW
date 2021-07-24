#include "main.h"

char *perm(mode_t mode){

	int i;
	static char perms[10] = "---------.";
	
	for(i = 0; i < 3; i++){

		if(mode & (S_IREAD >> i*3)){
			perms[i*3] = 'r';

		} else perms[i*3] = '-';

		if(mode & (S_IWRITE >> i*3)){
			perms[i*3+1] = 'w';

		} else perms[i*3+1] = '-';

		if(mode & (S_IEXEC >> i*3)){
			perms[i*3+2] = 'x';

		} else perms[i*3+2] = '-';

	}

	return(perms);
}
