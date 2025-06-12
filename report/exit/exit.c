#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
int code = 0;
if (argc > 1) {
code = atoi(argv);
}
printf("프로그램을 종료합니다. (종료 코드: %d)\n", code);
exit(code);
}
