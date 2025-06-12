#include <stdio.h>

int main(int argc, char *argv[]) {
if (argc < 3) {
fprintf(stderr, "사용법: %s [파일1] [파일2]\n", argv);
return 1;
}

FILE *fp1 = fopen(argv, "rb");
FILE *fp2 = fopen(argv, "rb");
if (!fp1 || !fp2) {
    perror("fopen");
    return 1;
}

int c1, c2;
long pos = 1;
while (1) {
    c1 = fgetc(fp1);
    c2 = fgetc(fp2);

    if (c1 == EOF && c2 == EOF) {
        printf("파일이 동일합니다.\n");
        break;
    }
    if (c1 != c2) {
        printf("다름: 바이트 %ld, 파일1=0x%02x, 파일2=0x%02x\n", pos, c1, c2);
        break;
    }
    pos++;
}

fclose(fp1);
fclose(fp2);
return 0;
}
