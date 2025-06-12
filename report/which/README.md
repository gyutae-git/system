# which 명령어 구현

## 1. 명령어 설명
`which`는 지정한 명령어가 실행될 때 실제로 어느 경로에 있는지(실행 파일의 경로)를 출력하는 명령어입니다.

## 2. 구동 원리
- 환경 변수 `PATH`에서 각 디렉토리를 추출합니다.
- 각 디렉토리에서 해당 파일이 존재하고 실행 가능한지(`access()` 함수로) 확인합니다.
- 처음 발견한 경로를 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [명령어]\n", argv);
return 1;
}

char *path_env = getenv("PATH");
if (!path_env) {
    fprintf(stderr, "PATH 환경변수를 찾을 수 없습니다.\n");
    return 1;
}

char *path = strdup(path_env);
char *dir = strtok(path, ":");
while (dir) {
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, argv);
    if (access(fullpath, X_OK) == 0) {
        printf("%s\n", fullpath);
        free(path);
        return 0;
    }
    dir = strtok(NULL, ":");
}
printf("%s: 명령어를 찾을 수 없습니다.\n", argv);
free(path);
return 1;
}
```
