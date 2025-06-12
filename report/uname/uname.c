#include <stdio.h>
#include <sys/utsname.h>

int main(void) {
struct utsname buf;
if (uname(&buf) == -1) {
perror("uname");
return 1;
}
printf("%s\n", buf.sysname); // 운영체제 이름만 출력
// 전체 정보 출력하려면 아래 주석 해제
// printf("Sysname: %s\nNodename: %s\nRelease: %s\nVersion: %s\nMachine: %s\n",
// buf.sysname, buf.nodename, buf.release, buf.version, buf.machine);
return 0;
}
