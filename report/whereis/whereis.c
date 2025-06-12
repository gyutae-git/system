#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char *dirs[] = {
"/bin", "/usr/bin", "/sbin", "/usr/sbin", "/usr/local/bin", NULL
};

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [명령어]\n", argv);
return 1;
}

int found = 0;
for (int i = 0; dirs[i] != NULL; i++) {
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirs[i], argv);
    if (access(fullpath, X_OK) == 0) {
        printf("%s ", fullpath);
        found = 1;
    }
}
if (!found)
    printf("%s: 파일을 찾을 수 없습니다.", argv);
printf("\n");
return found ? 0 : 1;
}
