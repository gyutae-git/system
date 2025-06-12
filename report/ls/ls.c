#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
DIR *dir;
struct dirent *entry;
char *path = "."; // 기본값: 현재 디렉토리
if (argc > 1) path = argv[1];

if ((dir = opendir(path)) == NULL) {
    perror("opendir");
    return 1;
}

while ((entry = readdir(dir)) != NULL) {
    if (entry->d_name != '.') {  // 숨김 파일 제외
        printf("%s\n", entry->d_name);
    }
}

closedir(dir);
return 0;
}
