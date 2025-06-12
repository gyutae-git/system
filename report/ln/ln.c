#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [원본파일] [링크이름]\n", argv);
return 1;
}

if (link(argv, argv) != 0) {
    perror("link");
    return 1;
}

printf("하드 링크 '%s' → '%s' 생성 완료\n", argv, argv);
return 0;
}
