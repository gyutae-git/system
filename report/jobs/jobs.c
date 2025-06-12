#include <stdio.h>
#include <stdlib.h>

int main(void) {
// 실제 jobs는 셸 내장 명령어이므로, ps로 대체
system("ps -o pid,stat,cmd --ppid $$ | grep '&'");
return 0;
}
