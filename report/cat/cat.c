#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "사용법: %s [파일명]\n", argv);
return 1;
}

int fd = open(argv[1], O_RDONLY);
if (fd < 0) {
    perror("open");
    return 1;
}

char buf[BUF_SIZE];
ssize_t n;
while ((n = read(fd, buf, BUF_SIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
        perror("write");
        close(fd);
        return 1;
    }
}

close(fd);
return 0;
}
