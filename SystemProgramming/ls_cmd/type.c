#include "main.h"

char type(mode_t mode){
	
	if(S_ISREG(mode)) return('-');
	if(S_ISDIR(mode)) return('d');
	if(S_ISCHR(mode)) return('c');
	if(S_ISBLK(mode)) return('b');
	if(S_ISLNK(mode)) return('l');
	if(S_ISFIFO(mode)) return('p');
	if(S_ISSOCK(mode)) return('s');

}
