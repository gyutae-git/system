
# WSL (Windows Subsystem for Linux) 설치 가이드

## ■ WSL이란 무엇인가?
- **WSL**은 **Windows Subsystem for Linux**의 약자로, **Microsoft Windows 운영 체제에서 Linux 환경을 실행**할 수 있게 해줍니다.
- **WSL**의 두 가지 버전:
  - **WSL1**: Windows 커널과 Linux 커널 간에 가교 역할을 하는 하이퍼바이저 기술을 사용하여, Linux 바이너리를 Windows에서 실행하도록 지원하지만 파일 시스템 성능이 다소 떨어집니다.
  - **WSL2**: Linux 커널을 Windows 시스템 위에 가상 머신 형태로 실행하여 성능과 호환성이 향상되었으며, Docker와 같은 컨테이너 기술을 효율적으로 지원합니다. **Windows 10, 버전 1903 이상에서만 사용 가능합니다.**
- **무료로 사용할 수** 있으며, Microsoft Store에서 Ubuntu, Debian과 같은 **Linux 배포판을 다운로드하여 설치**할 수 있습니다.

---

## ■ WSL 설치 방법

### 1. **Linux용 Windows 하위 시스템 기능 확인**
   - **Windows 기능 켜기/끄기**에서 **Linux용 Windows 하위 시스템** 옵션을 활성화해야 합니다.

### 2. **Windows PowerShell을 관리자 권한으로 실행**
   - `Windows PowerShell`을 **관리자 권한으로 실행**합니다.

### 3. **WSL 설치 명령어 입력**
   - PowerShell에서 `wsl --install` 명령어를 입력하고 **Enter**를 눌러 설치를 진행합니다.
   - 설치 과정에서 **Ubuntu**와 같은 리눅스 배포판이 자동으로 설치됩니다.

### 4. **버전 변경 및 재부팅**
   - 설치가 완료되면, 기본 WSL 버전을 `wsl --set-default-version 2` 명령어로 **WSL2**로 설정합니다.
   - 이후 **재부팅**을 진행합니다.

### 5. **Linux 사용자 이름 및 비밀번호 설정**
   - 재부팅 후, **Linux용 Windows 하위 시스템 창**이 뜨며 **username**과 **password**를 설정합니다.
   - 사용자 이름은 Windows 사용자 이름과 일치할 필요는 없습니다.

### 6. **설치 완료 및 확인**
   - 설정이 완료되면, **Windows 시작 버튼**을 클릭하여 **Ubuntu**와 같은 앱을 확인할 수 있습니다.

### 7. **다른 배포판 설치**
   - 추가적으로 다른 리눅스 배포판을 설치하려면 **Microsoft Store**에서 원하는 배포판을 검색하여 설치할 수 있습니다.

---

### ■ 참고: 윈도우 버전 확인
1. 실행창(Ctrl + R) 입력 후, `winver` 입력하여 윈도우 버전을 확인할 수 있습니다.
