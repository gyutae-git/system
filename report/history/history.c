#include <stdio.h>

#define HISTORY_FILE "history.txt"
#define BUF_SIZE 1024

int main(void) {
FILE *fp = fopen(HISTORY_FILE, "r");
if (!fp) {
perror("fopen");
return 1;
}

char buf[BUF_SIZE];
int line = 1;
while (fgets(buf, sizeof(buf), fp)) {
    printf("%4d  %s", line++, buf);
}

fclose(fp);
return 0;
}
