#include <stdio.h>
#include <string.h>

#define ALIAS_FILE "alias.txt"

int main(int argc, char *argv[]) {
if (argc == 1) {
// 별칭 목록 출력
FILE *fp = fopen(ALIAS_FILE, "r");
if (!fp) {
perror("fopen");
return 1;
}
char buf[1024];
while (fgets(buf, sizeof(buf), fp)) {
printf("%s", buf);
}
fclose(fp);
} else if (argc == 3) {
// 별칭 추가
FILE *fp = fopen(ALIAS_FILE, "a");
if (!fp) {
perror("fopen");
return 1;
}
fprintf(fp, "%s='%s'\n", argv, argv);
fclose(fp);
printf("별칭 추가: %s='%s'\n", argv, argv);
} else {
fprintf(stderr, "사용법: %s [별칭] [명령어]\n", argv);
return 1;
}
return 0;
}
