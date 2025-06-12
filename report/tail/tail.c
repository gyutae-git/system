#include <stdio.h>
#include <string.h>

#define MAX_LINES 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

FILE *fp = fopen(argv, "r");
if (!fp) {
    perror("fopen");
    return 1;
}

char lines[MAX_LINES][BUF_SIZE];
int count = 0, idx = 0;

while (fgets(lines[idx % MAX_LINES], BUF_SIZE, fp)) {
    idx++;
}
fclose(fp);

int start = idx > MAX_LINES ? idx % MAX_LINES : 0;
int total = idx < MAX_LINES ? idx : MAX_LINES;

for (int i = 0; i < total; i++) {
    printf("%s", lines[(start + i) % MAX_LINES]);
}

return 0;
}
