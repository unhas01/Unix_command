#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "add.h"
#include "sub.h"
#include "mul.h"
#include "dvd.h"
#include "mod.h"

int main(int argc, char **argv)
{
	int oprd1, oprd2, res;
	char line[128], exitstr[20], opr[20];

	setbuf(stdout, NULL);
	printf("지원되는 연산자 +, -, *, /\n");
	printf("사용예:2+3[enter] 또는 2 + 3 [enter]\n");
	printf("종료하려면 exit[enter]\n\n");

	for(;;) {

		printf("Expression: ");
		fgets(line, 128, stdin);
		sscanf(line, "%s", exitstr);
		if (!strcmp(exitstr, "exit"))
			exit(0);
		sscanf(line, "%d %s %d", &oprd1, opr, &oprd2);
		if (strlen(opr) > 1) {
			sscanf(opr+1, "%d", &oprd2);
			opr[1] = 0;
		}
		if(opr[0] == '+')
			res = add(oprd1, oprd2);
		else if (opr[0] == '-')
			res = sub(oprd1, oprd2);
		else if (opr[0] == '*')
			res = mul(oprd1, oprd2);
		else if (opr[0] == '/') {
			double res2 = dvd(oprd1, oprd2);
			printf("Result: %d %s %d = %f\n", oprd1, opr, oprd2, res2);
			continue;
		}
		else if (opr[0] == '%')
			res = mod(oprd1, oprd2);
		else{
        	printf("%s: 정의되지 않은 연산자임!!\n", opr);
			continue;
	
		}
		printf("Result: %d %s %d = %d\n", oprd1, opr, oprd2, res);
	}
}
