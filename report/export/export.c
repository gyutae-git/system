#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [변수=값]\n", argv);
return 1;
}

char *eq = strchr(argv, '=');
if (!eq) {
    fprintf(stderr, "형식 오류: 변수=값 형태여야 합니다.\n");
    return 1;
}
*eq = '\0';
char *name = argv;
char *value = eq + 1;

if (setenv(name, value, 1) != 0) {
    perror("setenv");
    return 1;
}

printf("환경 변수 등록: %s=%s\n", name, value);
return 0;
}
