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
