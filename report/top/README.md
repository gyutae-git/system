# top 명령어 구현

## 1. 명령어 설명
`top`은 시스템의 실시간 프로세스 상태, CPU/메모리 사용량 등을 주기적으로 갱신하여 출력하는 명령어입니다.

## 2. 구동 원리
- `/proc` 파일시스템에서 전체 프로세스 정보를 읽어와 반복적으로 화면에 출력합니다.
- CPU 사용률, 메모리 사용량 등은 `/proc/stat`, `/proc/meminfo` 등에서 읽을 수 있습니다.
- 여기서는 1초마다 전체 프로세스의 PID와 이름만 반복 출력하는 간단한 버전입니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void print_processes() {
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
}

int main(void) {
while (1) {
printf("\033[H\033[J"); // 화면 클리어
print_processes();
sleep(1); // 1초 대기
}
return 0;
}
```
