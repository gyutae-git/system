# chown 명령어 구현

## 1. 명령어 설명
`chown`(change owner)은 파일이나 디렉토리의 소유자(UID)와 그룹(GID)을 변경하는 명령어입니다.

## 2. 구동 원리
- `chown()` 시스템 콜을 사용하여 지정한 파일의 소유자와 그룹을 변경합니다.
- 사용자 이름과 그룹 이름을 받아 각각의 UID, GID로 변환 후 적용합니다.
- 여기서는 사용자 이름만 받아 UID로 변환하고, 그룹은 변경하지 않습니다.

## 3. C 구현 코드
```c
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [사용자이름] [파일명]\n", argv);
return 1;
}

struct passwd *pw = getpwnam(argv);
if (!pw) {
    fprintf(stderr, "사용자 '%s'를 찾을 수 없습니다.\n", argv);
    return 1;
}

if (chown(argv, pw->pw_uid, -1) != 0) {
    perror("chown");
    return 1;
}

printf("파일 '%s'의 소유자가 '%s'(UID: %d)로 변경되었습니다.\n", argv, argv, pw->pw_uid);
return 0;
}
```
