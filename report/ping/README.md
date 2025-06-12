# ping 명령어 구현

## 1. 명령어 설명
`ping`은 네트워크 상의 호스트(서버)로 ICMP ECHO 요청을 보내 응답을 확인하는 명령어입니다.

## 2. 구동 원리
- 실제 ping은 ICMP 패킷을 직접 생성해 전송하지만, 일반 사용자 권한으로는 raw socket 사용이 제한됩니다.
- 여기서는 `system()` 함수를 이용해 OS의 ping 명령을 호출하는 매우 단순한 버전을 제공합니다.
- 또는, 네트워크 연결 여부만 확인하려면 `gethostbyname()` 등으로 DNS 확인만 할 수도 있습니다.

## 3. C 구현 코드 (system 함수 이용)
```c
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
```
