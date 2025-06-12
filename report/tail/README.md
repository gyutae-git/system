# tail 명령어 구현

## 1. 명령어 설명
`tail`은 파일의 마지막 몇 줄(기본 10줄)을 출력하는 명령어입니다.

## 2. 구동 원리
- 파일을 `fopen()`으로 읽기 모드로 엽니다.
- 파일 전체를 한 줄씩 읽어 배열에 저장하며, 최대 10줄만 순환 저장합니다.
- 파일 끝까지 읽은 후, 저장된 최근 10줄을 순서대로 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <string.h>

#define MAX_LINES 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

FILE *fp = fopen(argv, "r");
if (!fp) {
    perror("fopen");
    return 1;
}

char lines[MAX_LINES][BUF_SIZE];
int count = 0, idx = 0;

while (fgets(lines[idx % MAX_LINES], BUF_SIZE, fp)) {
    idx++;
}
fclose(fp);

int start = idx > MAX_LINES ? idx % MAX_LINES : 0;
int total = idx < MAX_LINES ? idx : MAX_LINES;

for (int i = 0; i < total; i++) {
    printf("%s", lines[(start + i) % MAX_LINES]);
}

return 0;
}
```
