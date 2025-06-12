#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [디렉토리명]\n", argv);
return 1;
}

if (rmdir(argv[1]) != 0) {
    perror("rmdir");
    return 1;
}

printf("디렉토리 '%s' 삭제 완료\n", argv[1]);
return 0;
}
