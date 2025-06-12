#include <stdio.h>
#include <time.h>

int days_in_month(int year, int month) {
int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
if (month == 2) {
// 윤년 계산
if ((year%4==0 && year%100!=0) || (year%400==0))
return 29;
}
return days[month-1];
}

int main(void) {
time_t now = time(NULL);
struct tm *t = localtime(&now);

int year = t->tm_year + 1900;
int month = t->tm_mon + 1;

struct tm first = {0};
first.tm_year = year - 1900;
first.tm_mon = month - 1;
first.tm_mday = 1;
mktime(&first);

int start_weekday = first.tm_wday;
int last_day = days_in_month(year, month);

printf("      %d년 %d월\n", year, month);
printf("일 월 화 수 목 금 토\n");

for (int i = 0; i < start_weekday; i++)
    printf("   ");

for (int day = 1; day <= last_day; day++) {
    printf("%2d ", day);
    if ((start_weekday + day - 1) % 7 == 6)
        printf("\n");
}
printf("\n");

return 0;
}
