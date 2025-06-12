# find 명령어 구현

## 1. 명령어 설명
`find`는 지정한 디렉토리 아래에서 파일이나 디렉토리를 이름 기준으로 검색하는 명령어입니다.

## 2. 구동 원리
- `opendir()`과 `readdir()`로 디렉토리의 엔트리를 순회합니다.
- 각 엔트리가 파일인지 디렉토리인지 구분하고, 디렉토리면 재귀적으로 탐색합니다.
- 파일 이름이 검색 패턴과 일치하면 경로를 출력합니다.
- 여기서는 하위 디렉토리까지 모두 탐색하며, 이름이 정확히 일치하는 파일만 찾습니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void find_file(const char *dir, const char *target) {
DIR *dp = opendir(dir);
if (!dp) return;

struct dirent *entry;
char path[1024];

while ((entry = readdir(dp)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;

    snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            find_file(path, target); // 재귀 탐색
        }
        if (strcmp(entry->d_name, target) == 0) {
            printf("%s\n", path);
        }
    }
}
closedir(dp);
}

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [디렉토리] [파일명]\n", argv);
return 1;
}
find_file(argv, argv);
return 0;
}
```
