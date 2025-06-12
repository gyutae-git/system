#include <stdio.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [원본] [대상]\n", argv);
return 1;
}

if (rename(argv, argv) != 0) {
    perror("rename");
    return 1;
}

printf("'%s' → '%s' 이동/이름 변경 완료\n", argv, argv);
return 0;
}
