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
