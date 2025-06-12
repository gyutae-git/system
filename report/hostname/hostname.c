#include <stdio.h>
#include <unistd.h>

int main(void) {
char name;
if (gethostname(name, sizeof(name)) != 0) {
perror("gethostname");
return 1;
}
printf("%s\n", name);
return 0;
}
