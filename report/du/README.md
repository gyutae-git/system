# du 명령어 구현

## 1. 명령어 설명
`du`(disk usage)는 파일이나 디렉토리의 디스크 사용량을 출력하는 명령어입니다.

## 2. 구동 원리
- `stat()` 함수를 사용하여 파일의 크기를 구합니다.
- 디렉토리라면 `opendir()`과 `readdir()`로 하위 파일/디렉토리를 순환하며 크기를 합산합니다.
- 여기서는 지정한 경로(또는 현재 디렉토리)의 전체 사용량만 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

long get_size(const char *path) {
struct stat st;
long total = 0;

if (stat(path, &st) == -1) return 0;

if (S_ISDIR(st.st_mode)) {
    DIR *dir = opendir(path);
    if (!dir) return 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        total += get_size(fullpath);
    }
    closedir(dir);
}
total += st.st_size;
return total;
}

int main(int argc, char *argv[]) {
const char *path = (argc > 1) ? argv : ".";
long size = get_size(path);
printf("%ld\t%s\n", size/1024, path); // KB 단위
return 0;
}
```
