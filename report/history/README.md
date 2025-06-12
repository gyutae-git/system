# history 명령어 구현

## 1. 명령어 설명
`history`는 사용자가 입력한 명령어의 기록(히스토리)을 출력하는 명령어입니다.

## 2. 구동 원리
- 실제로는 셸이 명령어를 입력받을 때마다 `.bash_history` 등 파일에 저장합니다.
- 여기서는 단순히 현재 디렉토리의 `history.txt` 파일을 읽어 한 줄씩 출력하는 방식으로 구현합니다.

## 3. C 구현 코드
```c
#include <stdio.h>

#define HISTORY_FILE "history.txt"
#define BUF_SIZE 1024

int main(void) {
FILE *fp = fopen(HISTORY_FILE, "r");
if (!fp) {
perror("fopen");
return 1;
}

char buf[BUF_SIZE];
int line = 1;
while (fgets(buf, sizeof(buf), fp)) {
    printf("%4d  %s", line++, buf);
}

fclose(fp);
return 0;
}
```
