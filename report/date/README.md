# date 명령어 구현

## 1. 명령어 설명
`date`는 현재 시스템의 날짜와 시간을 출력하는 명령어입니다.

## 2. 구동 원리
- `time()` 함수로 현재 시간을 얻습니다.
- `localtime()` 함수로 현지 시간대로 변환합니다.
- `strftime()` 또는 `printf()`로 날짜와 시간을 사람이 읽기 쉬운 형식으로 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <time.h>

int main(void) {
time_t now = time(NULL);
struct tm *t = localtime(&now);

if (t == NULL) {
    perror("localtime");
    return 1;
}

printf("%04d-%02d-%02d %02d:%02d:%02d\n",
       t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
       t->tm_hour, t->tm_min, t->tm_sec);

return 0;
}
```
