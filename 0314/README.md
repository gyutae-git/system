# WSL 디렉토리 트리 구조 만들기

이 가이드는 Linux 환경에서 `tree` 명령어를 사용하여 주어진 디렉토리 구조를 만드는 방법을 설명합니다.

## 1. **`tree` 명령어 사용 준비**

### **`tree` 명령어 설치**

`tree` 명령어는 디렉토리 구조를 트리 형태로 보여주는 명령어입니다. 시스템에 설치되지 않은 경우 아래 명령어로 설치할 수 있습니다.

#### **Ubuntu/Debian 계열에서 `tree` 설치**
- `sudo apt-get update`: 시스템의 패키지 목록을 업데이트합니다.
- `sudo apt-get install tree`: `tree` 명령어를 설치합니다.

#### **CentOS/RHEL 계열에서 `tree` 설치**
- `sudo yum install tree`: `tree` 명령어를 설치합니다.

---

## 2. **디렉토리 구조 만들기**

주어진 트리 구조를 만들기 위해서는 먼저 필요한 디렉토리들을 생성해야 합니다.

### **디렉토리 생성**
- `mkdir`: 디렉토리를 생성하는 명령어입니다.
- `-p`: 상위 디렉토리가 없으면 자동으로 상위 디렉토리까지 생성합니다.
- `software/app`, `system/Compiler`, `system/interpreter`, `system/LP`, `system/OS`, `system/Util`: 이 디렉토리들이 위 명령어로 한 번에 생성됩니다.

---

## 3. **텍스트 파일 생성하기**

이제 각 디렉토리 내에 필요한 텍스트 파일을 생성합니다.

### **파일 생성**
- `touch`: 지정한 파일의 날짜를 업데이트하는 명령어입니다. 파일이 없다면 파일이 생성됩니다.
- `software/app/d.txt`, `system/Compiler/a.txt`, `system/interpreter/b.txt`, `system/Util/c.txt`: 각 디렉토리 안에 파일을 생성합니다.

---

## 4. **`tree` 명령어로 디렉토리 구조 출력하기**

위에서 만든 디렉토리 구조를 확인하려면 `tree` 명령어를 사용합니다.

### **디렉토리 구조 출력**
- `tree`: 현재 디렉토리의 하위 디렉토리 구조를 트리 형태로 보여줍니다.

### **출력 예시**

---

## 5. **전체 명령어 요약**
- `sudo apt-get update`
- `sudo apt-get install tree`
- `mkdir -p software/app system/Compiler system/interpreter system/LP system/OS system/Util`
- `touch software/app/d.txt`
- `touch system/Compiler/a.txt`
- `touch system/interpreter/b.txt`
- `touch system/Util/c.txt`
- `tree`
- 이 모든 명령어를 한 번에 실행하면, 주어진 트리 구조를 생성하고 확인할 수 있습니다.
