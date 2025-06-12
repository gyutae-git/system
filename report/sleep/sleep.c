#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [초]\n", argv);
return 1;
}

int sec = atoi(argv);
printf("%d초 동안 대기...\n", sec);
sleep(sec);
printf("대기 종료\n");
return 0;
}
