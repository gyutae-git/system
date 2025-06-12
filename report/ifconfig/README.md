# ifconfig 명령어 구현

## 1. 명령어 설명
`ifconfig`는 네트워크 인터페이스의 설정과 상태(예: IP 주소, MAC 주소 등)를 출력하는 명령어입니다.

## 2. 구동 원리
- 실제로는 소켓 프로그래밍과 ioctl 시스템 콜을 이용해 네트워크 인터페이스 정보를 가져옵니다.
- 여기서는 표준 라이브러리만 사용하여, `system("ifconfig")`로 외부 명령을 호출하는 기본 버전을 제공합니다.

## 3. C 구현 코드 (system 함수 이용)
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
system("ifconfig");
return 0;
}
```
