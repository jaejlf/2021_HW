#include "main.h"
#define REINPUT 10
#define REOUTPUT 11

int main()
{
    char buf[256];
    char *args[MAXARG];
    char *command[MAXARG];
    char *s;
    char *save;
    int argn;
    static const char delim[] = " \t\n"; /* 공백, 탭, 개행으로 이루어진 구분자 선언 */
    int pid, status;
    int i, j;
    int check;
    int reindex;
    int count;

    while (1)
    { /* 무한 반복 */

        printf("[shell] ");             /* 프롬프트 출력 */
        memset(buf, NULL, sizeof(buf)); /* buf 초기화 */
        gets(buf);

        /* command 초기화 */
        for (j = 0; j < MAXARG; j++)
        {
            command[j] = NULL;
        }

        /* 문자열에서 ; 을 기준으로 단어를 잘라냄 */
        count = 0;
        s = strtok_r(buf, ";", &save);
        if (s == NULL)
            continue; /* 명령어가 없으면 루프 계속 */
        while (s)
        {
            command[count++] = s;
            s = strtok_r(NULL, ";", &save);
        }

        /* command 실행 */
        for (i = 0; i < count; i++)
        {

            /* 변수 초기화 */
            argn = 0;
            check = 0;
            reindex = 0;

            /* args 초기화 */
            for (j = 0; j < MAXARG; j++)
            {
                args[j] = NULL;
            }

            /* 문자열에서 delim을 기준으로 단어를 잘라냄 */
            s = strtok_r(command[i], delim, &save);
            while (s)
            {
                args[argn++] = s;
                s = strtok_r(NULL, delim, &save);
            }
            args[argn] = (char *)0; /* 인수가 더 없음을 의미하는 문자 추가 */

            /* 입출력 리다이렉션 체크 */
            for (j = 0; j < argn; j++)
            {
                if (!strcmp(args[j], "<"))
                {
                    check = REINPUT;
                    reindex = j;
                    break;
                }
                if (!strcmp(args[j], ">"))
                {
                    check = REOUTPUT;
                    reindex = j;
                    break;
                }
            } //end - redirection check

            if (!strcmp(args[0], "quit"))
            { /* 프롬프트로 입력받은 단어가 ‘quit’이면 프로그램 종료 */
                exit(0);
            }
            if ((pid = fork()) == -1)
            { /* fork 호출에 실패하면 */
                perror("fork failed");
            }
            else if (pid != 0)
            { /* 부모 프로세스는 자식 프로세스가 종료되기를 기다림 */
                if (!strcmp(args[argn - 1], "&"))
                {
                    continue;
                }
                pid = waitpid(pid, &status, 0);
            }
            else
            { /* 자식 프로세스는 execvp를 이용하여 args[0] 실행 */
                if (!strcmp(args[argn - 1], "&"))
                {
                    args[argn - 1] = NULL;
                }

                if (check == REINPUT)
                { // < 입력 리다이렉션
                    re_input(args, reindex);
                }
                if (check == REOUTPUT)
                { // > 출력 리다이렉션
                    re_output(args, reindex);
                }

                if (execvp(args[0], args) == -1)
                {
                    printf("exe error !\n");
                    exit(0); //자식 프로세스 종료
                }

            } // child-end

        } //for-end

    } //while-end

    exit(0);
}