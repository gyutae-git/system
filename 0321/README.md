# C 프로그램 컴파일 및 실행 과정

## 1. GCC 설치 및 준비

C 언어로 코드를 컴파일하려면 GCC(GNU Compiler Collection)가 필요합니다. 대부분의 Linux 배포판에서는 이미 설치되어 있지만, 만약 설치되지 않았다면 아래 명령어로 설치할 수 있습니다.
### Ubuntu/Debian 계열에서 GCC 설치
```bash
sudo apt-get update
sudo apt-get install gcc
```

### CentOS/RHEL 계열에서 GCC 설치
```bash
sudo yum install gcc
```
### Windows에서 GCC 설치
Windows에서는 MinGW를 통해 GCC를 설치할 수 있습니다. MinGW 웹사이트에서 설치 프로그램을 다운로드한 후 설치합니다.

## 2. C 프로그램 파일 만들기

C 프로그램 파일을 작성하려면 텍스트 에디터를 사용해야 합니다. 예를 들어, `nano` 또는 `vim`을 사용하여 C 파일을 작성할 수 있습니다.

### 파일 작성
```bash
nano mission.c
```

여기서 mission.c는 파일명입니다. 아래 코드를 파일에 입력합니다:
```c
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
```
이 코드는 사용자가 학번과 이름을 입력받아 출력하는 프로그램입니다.

## 3. C 프로그램 컴파일

C 파일을 작성한 후, gcc를 사용하여 컴파일합니다.
```bash
gcc mission.c -o a.out
```

- `gcc`: C 컴파일러 명령어
- `mission.c`: 작성한 C 소스 파일
- `-o a.out`: 출력 파일 이름을 `a.out`로 지정합니다. (기본적으로 `a.out`으로 생성됩니다.)

## 4. 컴파일된 프로그램 실행

컴파일이 완료되면, 다음과 같이 실행할 수 있습니다:
```bash
./a.out
```
그러면 터미널에서 다음과 같은 입력을 요청합니다:
```
학번 : 2020575009
이름 : kimgyutae
```
입력 후, 출력은 아래와 같이 나타날 것입니다:
```
학번 : 2020575009, 이름 : kimgyutae
```
## 5. 전체 과정 요약

- **GCC 설치**: `sudo apt-get install gcc` 또는 `sudo yum install gcc`
- **C 프로그램 작성**: `nano mission.c`로 C 파일 생성 후 코드 입력
- **컴파일**: `gcc mission.c -o a.out`
- **실행**: `./a.out`
