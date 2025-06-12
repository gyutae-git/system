# df 명령어 구현

## 1. 명령어 설명
`df`(disk free)는 파일 시스템의 디스크 사용량과 남은 공간을 출력하는 명령어입니다.

## 2. 구동 원리
- `statvfs()` 함수를 사용해 파일 시스템의 블록 크기, 전체 블록 수, 남은 블록 수 등 정보를 얻습니다.
- 각 정보를 바탕으로 전체 용량, 사용 중 용량, 남은 용량을 계산해 출력합니다.
- 여기서는 루트 파일시스템(`/`)만 대상으로 합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <sys/statvfs.h>

int main(void) {
struct statvfs fs;
if (statvfs("/", &fs) != 0) {
perror("statvfs");
return 1;
}

unsigned long total = fs.f_blocks * fs.f_frsize;
unsigned long free = fs.f_bfree * fs.f_frsize;
unsigned long used = total - free;

printf("파일시스템   전체(MB)   사용(MB)   남음(MB)\n");
printf("/           %8lu  %8lu  %8lu\n", total/1024/1024, used/1024/1024, free/1024/1024);

return 0;
}
```
