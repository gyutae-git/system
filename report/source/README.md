# source 명령어 구현

## 1. 명령어 설명
`source`(또는 `.`)는 셸 스크립트 파일을 현재 셸 환경에서 실행하는 명령어입니다.

## 2. 구동 원리
- 실제로는 셸 내장 명령어로, 별도의 프로세스를 만들지 않고 현재 셸 환경에서 스크립트의 각 줄을 실행합니다.
- C 프로그램에서는 완벽하게 구현할 수 없지만, 여기서는 파일의 각 줄을 읽어 `system()` 함수로 실행하는 방식으로 흉내낼 수 있습니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [스크립트파일]\n", argv);
return 1;
}

FILE *fp = fopen(argv, "r");
if (!fp) {
    perror("fopen");
    return 1;
}

char buf[BUF_SIZE];
while (fgets(buf, sizeof(buf), fp)) {
    // 줄 끝 개행 제거
    buf[strcspn(buf, "\n")] = '\0';
    if (buf == '\0') continue;
    printf("실행: %s\n", buf);
    system(buf);
}
fclose(fp);
return 0;
}
```
