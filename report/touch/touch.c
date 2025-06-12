#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

int fd = open(argv, O_CREAT | O_WRONLY, 0644);
if (fd == -1) {
    perror("open");
    return 1;
}

close(fd);
printf("'%s' 파일 touch 완료\n", argv);
return 0;
}
