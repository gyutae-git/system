# whereis 명령어 구현

## 1. 명령어 설명
`whereis`는 지정한 명령어의 실행 파일, 소스 파일, 매뉴얼 파일의 위치를 찾아 출력하는 명령어입니다.

## 2. 구동 원리
- 일반적으로 `/bin`, `/usr/bin`, `/sbin`, `/usr/sbin`, `/usr/local/bin` 등 여러 디렉토리에서 해당 파일을 찾습니다.
- 각 디렉토리에서 파일이 존재하는지 `access()` 함수로 확인합니다.
- 여기서는 실행 파일 위치만 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char *dirs[] = {
"/bin", "/usr/bin", "/sbin", "/usr/sbin", "/usr/local/bin", NULL
};

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [명령어]\n", argv);
return 1;
}

int found = 0;
for (int i = 0; dirs[i] != NULL; i++) {
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirs[i], argv);
    if (access(fullpath, X_OK) == 0) {
        printf("%s ", fullpath);
        found = 1;
    }
}
if (!found)
    printf("%s: 파일을 찾을 수 없습니다.", argv);
printf("\n");
return found ? 0 : 1;
}
```
