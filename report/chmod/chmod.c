#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [권한(8진수)] [파일명]\n", argv);
return 1;
}

mode_t mode = strtol(argv, NULL, 8);
if (chmod(argv, mode) != 0) {
    perror("chmod");
    return 1;
}

printf("파일 '%s'의 권한이 %o(8진수)로 변경되었습니다.\n", argv, mode);
return 0;
}
