# ls 명령어 구현

## 1. 명령어 설명
디렉토리 내용을 출력하는 명령어 ([POSIX 표준](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/ls.html))

## 2. 구동 원리
1. `opendir()` 시스템 콜로 디렉토리 열기
2. `readdir()` 함수로 엔트리 순차적 읽기
3. `closedir()`로 디렉토리 닫기
4. `.`(현재 디렉토리) 및 `..`(상위 디렉토리) 숨김 처리

## 3. C 구현 코드
```C
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
DIR *dir;
struct dirent *entry;
char *path = "."; // 기본값: 현재 디렉토리
if (argc > 1) path = argv[1];

if ((dir = opendir(path)) == NULL) {
    perror("opendir");
    return 1;
}

while ((entry = readdir(dir)) != NULL) {
    if (entry->d_name != '.') {  // 숨김 파일 제외
        printf("%s\n", entry->d_name);
    }
}

closedir(dir);
return 0;
}
```
