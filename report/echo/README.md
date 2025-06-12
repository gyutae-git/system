# echo 명령어 구현

## 1. 명령어 설명
`echo`는 인자로 받은 문자열을 화면(표준 출력)에 출력하는 명령어입니다.

## 2. 구동 원리
- 프로그램 실행 시 전달받은 인자(문자열)를 순서대로 출력합니다.
- 각 인자를 공백으로 구분하여 출력하고, 마지막에 개행 문자를 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
for (int i = 1; i < argc; i++) {
printf("%s", argv[i]);
if (i < argc - 1) {
printf(" ");
}
}
printf("\n");
return 0;
}
```
