#include "main.h"

char type(mode_t);
char *perm(mode_t);
void printStat(char *, char *, struct stat *, char *, int);

int main(int argc, char **argv)
{

	DIR *dp;
	char *dir;
	struct stat st;
	struct dirent *d;
	char path[BUFSIZ + 1];

	int i = 0;
	int op = 0; //num of option
	char option[BUFSIZ];

	//command input
	if (argc == 1)
	{
		dir = ".";
	}

	else if (argc == 2)
	{

		if (*argv[1] == '-')
		{ //argv[1] is option
			dir = ".";

			i = 0;
			while (1)
			{
				if (*(argv[1] + i) == NULL)
					break;
				else
				{
					option[i] = *(argv[1] + i);
					op++;
				}
				i++;
			}
		}
		else
		{
			dir = argv[1];
		}
	}
	else
	{ //argc == 3
		if (*argv[1] == '-')
		{ //argv[1] is option
			dir = argv[2];

			i = 0;
			while (1)
			{
				if (*(argv[1] + i) == NULL)
					break;
				else
				{
					option[i] = *(argv[1] + i);
					op++;
				}
				i++;
			}
		}
		else
		{ //argv[2] is option
			dir = argv[1];

			i = 0;
			while (1)
			{
				if (*(argv[2] + i) == NULL)
					break;
				else
				{
					option[i] = *(argv[2] + i);
					op++;
				}
				i++;
			}
		}
	}

	//main
	if ((dp = opendir(dir)) == NULL)
	{
		perror(dir);
	}

	while ((d = readdir(dp)) != NULL)
	{

		if (!strncmp(d->d_name, ".", 1))
			continue;

		sprintf(path, "%s/%s", dir, d->d_name);
		if (lstat(path, &st) < 0)
		{
			perror(path);
		}

		if (op == 0)
		{
			printf("%s", d->d_name);
		}
		else
		{ //ls with option : s, i, l, F, o
			printStat(path, d->d_name, &st, option, op);
		}

		putchar('\n');

	} // while-end;

	closedir(dp);
	exit(0);
}
