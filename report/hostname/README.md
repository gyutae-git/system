# hostname 명령어 구현

## 1. 명령어 설명
`hostname`은 현재 시스템의 호스트 이름을 출력하거나 변경하는 명령어입니다.

## 2. 구동 원리
- `gethostname()` 함수로 현재 호스트 이름을 얻어 출력합니다.
- 인자가 있으면 `sethostname()` 함수로 호스트 이름을 변경할 수도 있습니다(루트 권한 필요).
- 여기서는 출력만 구현합니다.

## 3. C 구현 코드 (호스트 이름 출력)
```c
#include <stdio.h>
#include <unistd.h>

int main(void) {
char name;
if (gethostname(name, sizeof(name)) != 0) {
perror("gethostname");
return 1;
}
printf("%s\n", name);
return 0;
}
```
