#include "main.h"

void re_input(char *cmd[], int index)
{ /* < 입력 리다이렉션 */

    int fd;
    int i;
    char *filename;

    /* 명령어 배열 수정 */
    cmd[index] = NULL;
    filename = cmd[index + 1];
    for (i = index + 1; i < strlen(cmd); i++)
    {
        cmd[i] = NULL;
    }

    /* 파일에 표준 입력 복제 */
    if ((fd = open(filename, O_RDONLY, 0600)) != -1)
    {
        dup2(fd, 0);
        close(fd);
        execvp(cmd[0], cmd);
    }
    else
    {
        printf("file open error !\n");
    }
}

void re_output(char *cmd[], int index)
{ /* > 출력 리다이렉션 */

    int fd;
    int i;
    char *filename;

    /* 명령어 배열 수정 */
    cmd[index] = NULL;
    filename = cmd[index + 1];
    for (i = index + 1; i < strlen(cmd); i++)
    {
        cmd[i] = NULL;
    }

    /* 파일에 표준 출력 복제 */
    if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600)) != -1)
    {
        dup2(fd, 1);
        close(fd);
        execvp(cmd[0], cmd);
    }
    else
    {
        printf("file open error !\n");
    }
}
