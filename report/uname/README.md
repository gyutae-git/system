# uname 명령어 구현

## 1. 명령어 설명
`uname`은 운영체제 및 시스템 정보를 출력하는 명령어입니다.

## 2. 구동 원리
- `uname()` 시스템 콜을 사용하여 시스템 정보를 가져옵니다.
- 구조체의 다양한 필드 중 `sysname`(운영체제 이름)을 출력합니다.
- 필요에 따라 nodename, release, version, machine 등도 출력할 수 있습니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <sys/utsname.h>

int main(void) {
struct utsname buf;
if (uname(&buf) == -1) {
perror("uname");
return 1;
}
printf("%s\n", buf.sysname); // 운영체제 이름만 출력
// 전체 정보 출력하려면 아래 주석 해제
// printf("Sysname: %s\nNodename: %s\nRelease: %s\nVersion: %s\nMachine: %s\n",
// buf.sysname, buf.nodename, buf.release, buf.version, buf.machine);
return 0;
}
```
