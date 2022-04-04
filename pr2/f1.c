#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SZ_STR_BUF		256

int *cmd;
char cmd_line[SZ_STR_BUF];

void
cp(void)
{
	char *oldname = strtoken(NULL, " \t\n");
	char *newname = strtoken(NULL, " \t\n");

	if ((oldname == NULL) || (newname == NULL)) {
		printf("%s: Insufficient arguments\n", cmd);
		goto usage;
	}
	else if (strtoken(NULL, " \t\n") != NULL) {
		printf("%s: Too many arguments\n", cmd);
		goto usage;
	}
	// 여기에 파일 복사하는 코드를 삽입하라.
	printf("현재 이 명령어는 구현되지 않았습니다.\n");
	printf("직접 구현해 넣기 바랍니다.\n");
	return;

usage:
	printf("Usage: %s oldname newname\n", cmd);
}

void
pwd(void)
{
	// 전역변수 cwd에 저장된 문자열을 화면에 출력한다.
	printf("현재 이 명령어는 구현되지 않았습니다.\n");
	printf("직접 구현해 넣기 바랍니다.\n");
}

void
echo(void)
{
	// 명령어 라인에서 입력된 토컨들을 하나씩 짤라 화면에 출력한다.
	// 그리고 마지막에 개행(new line)을 출력한다.
	printf("현재 이 명령어는 구현되지 않았습니다.\n");
	printf("직접 구현해 넣기 바랍니다.\n");
}

void
mv(void)
{
	char *oldnime = strtoken(NULL, " \t\n");
	char *newnime = strtoken(NULL, " \t\n");

	if ((oldnime == NULL) || (newnime == NULL)) 
		printf("%s: Insufficient arguments\n", cmd);
	else if (strtoken(NULL, " \t\n") != NULL) 
		printf("%s: Too many arguments\n", cmd);
	// 여기에 파일 복사하는 코드를 삽입하라.
	printf("현재 이 명령어는 구현되지 않았습니다.\n");
	printf("직접 구현해 넣기 바랍니다.\n");
	return;
}

void
rm(void)
{
	char *name = strtoken(NULL, " \t\n");

	if (name == NULL) {
		printf("%s: Insufficient arguments\n", cmd);
		goto usage;
	}
	else if (strtoken(NULL, " \t\n") != NULL) {
		printf("%s: Too many arguments\n", cmd);
		goto usage;
	}
	// 여기에 화일을 삭제하는 코드를 삽입한다. 
	// 삭제한고자 하는 것이 화일인지 또는 디렉토리인지 체크하고 
	// 각각의 경우를 구분하여 시스템(API) 함수를 호출해야 함
	printf("현재 이 명령어는 구현되지 않았습니다.\n");
	printf("직접 구현해 넣기 바랍니다.\n");
	return;

usage:
	printf("Usage: %s file or empty directory name\n", cmd);
}

void
quit()
{
	exit(0);
}

void help(void);

typedef struct {
	char *cmd;
	void (*func)();
} cmd_disp_t;

// 새로운 명령어가 추가될 때마다, 아래의 배열에 해당 명령어의
// 문자열 이름과 그 명령어를 수행하는 함수의 이름을 추가해야 한다.
cmd_disp_t cmd_disp[] = {
	{ "cp",			cp },
	{ "echo",		echo },
	{ "help",		help },
	{ "pwd",		pwd },
	{ "exit",		quit },
	{ "move",		move },
	{ "rm",			rm },
}

int num_cmd = sizeof(cmd_disp) / sizeof(cmd_disp[0]);


void
help(void)
{
	int  k;
	
	for (k = 0; k < num_cmd; ++k)
		printf("%s ", cmd_disp[k].cmd);
	printf("\n");
}

void
proc_cmd(void)
{
	int  k;
	
	cmd = strtoken(cmd_line, " \t\n");
	if (cmd == NULL)
		return;
	for (k = 0; k < num_cmd; ++k)
		if (!strcmp(cmd, cmd_disp[k].cmd)) {
			cmd_disp[k].func();
			break;
		}
	if (k == num_cmd)
		printf("%s : Command not found.\n", cmd);
}

int 
main(int argc, char *argv[])
{
	int a,bb,ccc;
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	for (;;) {
	 printf(">> ");
	 gets(cmd_line);
 	 proc_cmd(); abc();
	 }
}
	


