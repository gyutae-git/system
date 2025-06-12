#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
DIR *dir = opendir("/proc");
struct dirent *entry;

printf("PID\tNAME\n");

while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_DIR) {
        int pid = atoi(entry->d_name);
        if (pid > 0) {
            char stat_path;
            snprintf(stat_path, sizeof(stat_path), "/proc/%d/stat", pid);
            FILE *fp = fopen(stat_path, "r");
            if (fp) {
                int p;
                char name;
                fscanf(fp, "%d (%255[^)])", &p, name);
                printf("%d\t%s\n", p, name);
                fclose(fp);
            }
        }
    }
}
closedir(dir);
return 0;
}
