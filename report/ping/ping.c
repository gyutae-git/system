#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [호스트]\n", argv);
return 1;
}

char cmd;
snprintf(cmd, sizeof(cmd), "ping -c 4 %s", argv);
system(cmd);

return 0;
}
