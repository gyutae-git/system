#include <stdio.h>

void analyze_binary(unsigned char num) {
    printf("입력된 숫자: %d\n", num);
    printf("2진수(8비트): ");
    int count = 0;
    for (int i = 7; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        if (bit) count++;
    }
    printf("\n1의 개수: %d\n", count);
    printf("상위 4비트: ");
    for (int i = 7; i >= 4; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int num;
    printf("0~255 사이의 정수 입력: ");
    scanf("%d", &num);
    if (num < 0 || num > 255) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }
    analyze_binary((unsigned char)num);
    return 0;
}
