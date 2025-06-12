# whoami 명령어 구현

## 1. 명령어 설명
`whoami`는 현재 사용자의 이름(로그인한 유저명)을 출력하는 명령어입니다.

## 2. 구동 원리
- `getuid()` 함수로 현재 프로세스의 사용자 ID를 얻습니다.
- `getpwuid()` 함수로 사용자 ID에 해당하는 사용자 정보를 가져옵니다.
- 사용자 정보 구조체에서 사용자 이름을 출력합니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(void) {
uid_t uid = getuid();
struct passwd *pw = getpwuid(uid);

if (pw) {
    printf("%s\n", pw->pw_name);
} else {
    perror("getpwuid");
    return 1;
}

return 0;
}
```
