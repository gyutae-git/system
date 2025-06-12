# ps 명령어 구현

## 1. 명령어 설명
`ps`(process status)는 현재 실행 중인 프로세스의 목록과 상태 정보를 출력하는 명령어입니다.

## 2. 구동 원리
- `/proc` 디렉토리에서 각 프로세스의 정보를 읽어옵니다.
- 각 프로세스 디렉토리(`/proc/[pid]/stat`)에서 PID, 프로세스 이름, 상태 등을 추출합니다.
- 여기서는 자신의 프로세스와 자식 프로세스만 표시하는 간단한 버전입니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
DIR *dir = opendir("/proc");
struct dirent *entry;

printf("PID\tNAME\n");

while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_DIR) {
        int pid = atoi(entry->d_name);
        if (pid > 0) {
            char stat_path;
            snprintf(stat_path, sizeof(stat_path), "/proc/%d/stat", pid);
            FILE *fp = fopen(stat_path, "r");
            if (fp) {
                int p;
                char name;
                fscanf(fp, "%d (%255[^)])", &p, name);
                printf("%d\t%s\n", p, name);
                fclose(fp);
            }
        }
    }
}
closedir(dir);
return 0;
}
```
