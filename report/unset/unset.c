#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [변수이름]\n", argv);
return 1;
}

if (unsetenv(argv) != 0) {
    perror("unsetenv");
    return 1;
}

printf("환경 변수 삭제: %s\n", argv);
return 0;
}
