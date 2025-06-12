# alias 명령어 구현

## 1. 명령어 설명
`alias`는 자주 사용하는 명령어에 별칭을 만들어주는 명령어입니다.

## 2. 구동 원리
- 실제로는 셸 내부에서 별칭을 관리하지만, 여기서는 간단하게 별칭과 명령어 쌍을 파일(`alias.txt`)에 저장/출력하는 방식으로 구현합니다.
- 인자가 없으면 별칭 목록을 출력하고, 인자가 있으면 별칭을 추가합니다.

## 3. C 구현 코드
```c
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
```
