#include <stdio.h>
#include <sys/statvfs.h>

int main(void) {
struct statvfs fs;
if (statvfs("/", &fs) != 0) {
perror("statvfs");
return 1;
}

unsigned long total = fs.f_blocks * fs.f_frsize;
unsigned long free = fs.f_bfree * fs.f_frsize;
unsigned long used = total - free;

printf("파일시스템   전체(MB)   사용(MB)   남음(MB)\n");
printf("/           %8lu  %8lu  %8lu\n", total/1024/1024, used/1024/1024, free/1024/1024);

return 0;
}
