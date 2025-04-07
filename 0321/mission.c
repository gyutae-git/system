#include <stdio.h>

int main() {
    char a[10];
    int b;
    
    printf("학번 : ");
    scanf("%d", &b);
    printf("이름 : ");
    scanf("%s", a);
    printf("학번 : %d, 이름 : %s\n", b, a);
    
    return 0;
}
