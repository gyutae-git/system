#include <stdio.h>

int main() {
    char input;

    while (1) {
        printf("문자 입력 : ");
        scanf(" %c", &input);

        if (input == '0') {
            break;
        }
        if (input >= 'A' && input <= 'Z') {
            printf("%c의 소문자는 %c입니다.\n", input, input + 32);
        }
else if (input >= 'a' && input <= 'z') {
            printf("%c의 대문자는 %c입니다.\n", input, input - 32);
        }
        else {
            printf("입력한 문자는 알파벳이 아닙니다.\n");
        }
    }

    return 0;
}
