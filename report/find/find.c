#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void find_file(const char *dir, const char *target) {
DIR *dp = opendir(dir);
if (!dp) return;

struct dirent *entry;
char path[1024];

while ((entry = readdir(dp)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;

    snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            find_file(path, target); // 재귀 탐색
        }
        if (strcmp(entry->d_name, target) == 0) {
            printf("%s\n", path);
        }
    }
}
closedir(dp);
}

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [디렉토리] [파일명]\n", argv);
return 1;
}
find_file(argv, argv);
return 0;
}
