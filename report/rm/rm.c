#include <stdio.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

if (remove(argv) != 0) {
    perror("remove");
    return 1;
}

printf("파일 '%s' 삭제 완료\n", argv);
return 0;
}
