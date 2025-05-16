# C 언어로 구현한 ls -l 명령어

유닉스/리눅스의 `ls -l` 명령어와 유사하게 동작하는 프로그램입니다.  
디렉토리 내 파일 및 서브디렉토리의 상세 정보를 직접 시스템 호출을 통해 출력합니다.

---

## 📂 코드 설명

### 주요 기능
- 파일/디렉토리 타입 식별 (일반파일, 디렉토리, 링크 등)
- 소유자, 그룹, 권한, 하드링크 수, 파일 크기, 최종 수정 시간, 파일명 출력
- `ls -l`과 유사한 포맷

### 주요 함수
| 함수명          | 역할                                   |
|-----------------|----------------------------------------|
| `main()`        | 디렉토리 열고 파일 목록 순회            |
| `printStat()`   | 파일 메타데이터 출력                    |
| `type()`        | 파일 타입 문자 반환                     |
| `perm()`        | 권한 문자열 반환 (rwxrwxrwx)            |

---

## 🛠️ 빌드 및 실행

### 컴파일
gcc -o list2 list2.c


### 실행 예시
./list2 # 현재 디렉토리 출력
./list2 [경로명] # 지정한 경로 출력


---

## ⚠️ 참고 및 개선점

- `perm()` 함수는 정적 버퍼를 사용하므로, 멀티스레드 환경에서는 주의가 필요합니다.
- `getpwuid()`와 `getgrgid()`가 NULL을 반환할 경우를 대비한 예외처리가 필요합니다.
- 파일 경로 조합 시 `snprintf()` 사용을 권장합니다.

---

## 📄 소스 코드
```
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>   // exit() 함수 사용을 위해 추가
#include <time.h>     // ctime() 함수 사용을 위해 추가

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

/* 디렉터리 내용을 자세히 리스트한다. */
int main(int argc, char **argv)
{
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];

    if (argc == 1)
        dir = ".";
    else dir = argv[1];

    if ((dp = opendir(dir)) == NULL) // 디렉터리 열기
        perror(dir);

    while ((d = readdir(dp)) != NULL) { // 디렉터리의 각 파일에 대해
        sprintf(path, "%s/%s", dir, d->d_name); // 파일경로명 만들기
        if (lstat(path, &st) < 0) // 파일 상태 정보 가져오기
            perror(path);
        printStat(path, d->d_name, &st); // 상태 정보 출력
        putchar('\n');
    }
    closedir(dp);
    exit(0);
}

/* 파일 상태 정보를 출력 */
void printStat(char *pathname, char *file, struct stat *st) {
    printf("%5ld ", st->st_blocks); // %d → %ld
    printf("%c%s ", type(st->st_mode), perm(st->st_mode));
    printf("%3lu ", st->st_nlink);  // %d → %lu
    printf("%s %s ", getpwuid(st->st_uid)->pw_name,
                     getgrgid(st->st_gid)->gr_name);
    printf("%9ld ", st->st_size);   // %d → %ld
    printf("%.12s ", ctime(&st->st_mtime)+4);
    printf("%s", file);
}

/* 파일 타입을 리턴 */
char type(mode_t mode) {
    if (S_ISREG(mode))
        return('-');
    if (S_ISDIR(mode))
        return('d');
    if (S_ISCHR(mode))
        return('c');
    if (S_ISBLK(mode))
        return('b');
    if (S_ISLNK(mode))
        return('l');
    if (S_ISFIFO(mode))
        return('p');
    if (S_ISSOCK(mode))
        return('s');
    return('?');
}

/* 파일 사용권한을 리턴 */
char* perm(mode_t mode) {
    int i;
    static char perms[10] = "---------";
    for (i=0; i < 3; i++) {
        if (mode & (S_IREAD >> i*3))
            perms[i*3] = 'r';
        if (mode & (S_IWRITE >> i*3))
            perms[i*3+1] = 'w';
        if (mode & (S_IEXEC >> i*3))
            perms[i*3+2] = 'x';
    }
    return(perms);
}
```
---

## 👀 학습 포인트

- 시스템 콜을 통한 파일/디렉토리 정보 획득
- 비트 연산을 통한 권한 파싱
- 사용자/그룹명 변환 함수 활용
- 파일 경로 조합 및 에러 처리

---

## 📝 개선 아이디어

- 숨김 파일 표시(`-a` 옵션)
- 파일 정렬 기능 추가
- 심볼릭 링크 대상 표시
- 컬러 출력 지원

---

