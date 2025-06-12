#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

long get_size(const char *path) {
struct stat st;
long total = 0;

if (stat(path, &st) == -1) return 0;

if (S_ISDIR(st.st_mode)) {
    DIR *dir = opendir(path);
    if (!dir) return 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        total += get_size(fullpath);
    }
    closedir(dir);
}
total += st.st_size;
return total;
}

int main(int argc, char *argv[]) {
const char *path = (argc > 1) ? argv : ".";
long size = get_size(path);
printf("%ld\t%s\n", size/1024, path); // KB 단위
return 0;
}
