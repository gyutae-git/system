#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [디렉토리]\n", argv);
return 1;
}
if (chdir(argv) != 0) {
    perror("chdir");
    return 1;
}

// 이동 후 현재 디렉토리 출력(확인용)
char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("현재 디렉토리: %s\n", cwd);
} else {
    perror("getcwd");
}

return 0;
}
