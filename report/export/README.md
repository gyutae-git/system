# export 명령어 구현

## 1. 명령어 설명
`export`는 환경 변수(변수)를 자식 프로세스에서도 사용할 수 있도록 등록하는 명령어입니다.

## 2. 구동 원리
- C에서는 `setenv()` 함수를 사용해 환경 변수를 설정합니다.
- 실제로는 셸 내부에서 관리되지만, 여기서는 별도의 환경 변수 설정만 구현합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [변수=값]\n", argv);
return 1;
}

char *eq = strchr(argv, '=');
if (!eq) {
    fprintf(stderr, "형식 오류: 변수=값 형태여야 합니다.\n");
    return 1;
}
*eq = '\0';
char *name = argv;
char *value = eq + 1;

if (setenv(name, value, 1) != 0) {
    perror("setenv");
    return 1;
}

printf("환경 변수 등록: %s=%s\n", name, value);
return 0;
}
```
