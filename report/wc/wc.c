#include <stdio.h>
#include <ctype.h>

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

int lines = 0, words = 0, chars = 0;
int in_word = 0;
int c;

while ((c = fgetc(fp)) != EOF) {
    chars++;
    if (c == '\n') lines++;
    if (isspace(c))
        in_word = 0;
    else if (!in_word) {
        in_word = 1;
        words++;
    }
}

fclose(fp);
printf("%d %d %d %s\n", lines, words, chars, argv);
return 0;
}
