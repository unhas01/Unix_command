#include <stdio.h>			// printf(), gets()
#include <string.h>			// strcmp(), strlen()
#include <stdlib.h>			// exit()
#include <unistd.h>			// write(), close(), unlink(), read(), write()
#include <fcntl.h>			// open() option
#include <sys/types.h>
#include <sys/stat.h>

#define SZ_STR_BUF		256

// 메시지 큐용으로 사용될 FIFO 파일
char *s_to_c = "fifo_s_to_c";
char *c_to_s = "fifo_c_to_s";

int  in_fd, out_fd;
int  len;
char cmd_line[SZ_STR_BUF];

// ****************************************************************
// 에러 원인을 화면에 출력하고 프로그램 강제 종료
// ****************************************************************
void 
print_err_exit(char *msg)
{
	perror(msg);
	exit(1);
}


// ****************************************************************
// 클라이언트와 연결한다.
// ****************************************************************

void
connect_to_client()
{
	/* 여기에 fifo file 생성하는 코드 삽입할 것 (이건 다음 시간에 할 에정임) */
	// 서버와 클라이언트가 통신할 두 개의 FIFO 파일을 생성함.
	// char * c_to_s = "fifo_c_to_s"
	// char * s_to_c = "fifo_s_to_c"
	// 0600: 파일의 접근권한 rw-------
	mkfifo(c_to_s, 0600); // 클라이언트 -> 서버로 전송할 FIFO파일
	mkfifo(s_to_c, 0600); // 서버 -> 클라이언트로 전소할 FIFO파일

	// 클라이언트 -> 서버 방향 통신용 FIFO 연결: 클라이언트가 접속하길 대기함

	/* 여기에 클라이언트 -> 서버 방향 통신용 FIFO 연결용 코드를 삽입할 것 */

	// 서버 -> 클라이언트 방향 통신용 FIFO 연결

	/* 여기에 서버 -> 클라이언트 방향 통신용 FIFO 연결용 코드를 삽입할 것 */
	in_fd = open(c_to_s, O_RDONLY);
	if (in_fd < 0) 
		print_err_exit(c_to_s);

	out_fd = open(s_to_c, O_WRONLY);
	if (out_fd < 0)
		print_err_exit(s_to_c);
}

// ****************************************************************
// 클라이언트와 연결을 해제한다.
// ****************************************************************
void
dis_connect()
{
	close(out_fd);
	close(in_fd);
}

void duplicate_IO()
{
	dup2(in_fd, 0);
	dup2(out_fd, 1);
	dup2(out_fd, 2);

	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	dis_connect();
}
// ****************************************************************
// main() 함수
// ****************************************************************
int
main(int argc, char *argv[])
{
	char ret_buf[SZ_STR_BUF];

	connect_to_client(); // 클라이언트 프로그램 cmdc와 연결한다.
	duplicate_IO();

	while (1) {
		// 클라이언트 -> 서버 수신

		/* 여기에 클라이언트로부터 메시지 수신하는 문장 삽입할 것 */
		if (fgets(cmd_line, SZ_STR_BUF, stdin) == NULL)
			break;

		// cmdc로부터 "exit"를 전달 받으면 서버 프로그램은 여기서 종료
		if (strncmp(cmd_line, "exit", 4) == 0)
			break;

		//printf("%s", cmd_line);
		
		// 서버가 클라이언트에게 보낼 문자열을 작성함: 받은 메시지를 다시 에코해 줌
		printf("server: %s", cmd_line);
		sleep(1);
		printf("sleep: %s", cmd_line);
	}
	dis_connect(); // 클라이언트 프로그램과 연결을 해제한다.
}

// 매번 cmdc, srv 프로그램 실행 전에 
// $ ps -u계정이름
// 위 명령어를 실행하여 기존에 실행시켰던 cmdc, srv 프로그램이 있는지 확인하고, 있으면
// $ kill -9 21032(process ID)
// 하여 기존 프로그램을 죽인 후 실행해야 한다.
