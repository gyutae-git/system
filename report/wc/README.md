# wc 명령어 구현

## 1. 명령어 설명
`wc`(word count)는 파일의 행(line), 단어(word), 문자(character) 수를 세어 출력하는 명령어입니다.

## 2. 구동 원리
- 파일을 한 줄씩 읽으면서, 각 줄의 문자 수, 단어 수, 줄 수를 누적합니다.
- 단어는 공백(스페이스, 탭, 개행 등)으로 구분하여 셉니다.

## 3. C 구현 코드
```c
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
```
