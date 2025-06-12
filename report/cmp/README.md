# cmp 명령어 구현

## 1. 명령어 설명
`cmp`는 두 파일을 바이트 단위로 비교하여, 처음으로 다른 위치를 출력하는 명령어입니다.

## 2. 구동 원리
- 두 파일을 동시에 열고, 한 바이트씩 읽어가며 비교합니다.
- 처음으로 다른 바이트가 나오면 그 위치(바이트 오프셋)와 값을 출력합니다.
- 파일의 끝까지 다르면 "파일이 동일합니다"라고 출력합니다.

## 3. C 구현 코드
```c
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
```
