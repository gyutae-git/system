#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [명령어]\n", argv);
return 1;
}

char *path_env = getenv("PATH");
if (!path_env) {
    fprintf(stderr, "PATH 환경변수를 찾을 수 없습니다.\n");
    return 1;
}

char *path = strdup(path_env);
char *dir = strtok(path, ":");
while (dir) {
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, argv);
    if (access(fullpath, X_OK) == 0) {
        printf("%s\n", fullpath);
        free(path);
        return 0;
    }
    dir = strtok(NULL, ":");
}
printf("%s: 명령어를 찾을 수 없습니다.\n", argv);
free(path);
return 1;
}
