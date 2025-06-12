#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [디렉토리명]\n", argv);
return 1;
}
if (mkdir(argv, 0755) != 0) {
    perror("mkdir");
    return 1;
}

printf("디렉토리 '%s' 생성 완료\n", argv);
return 0;
}
