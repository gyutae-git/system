# 💡 생성형 AI를 이용한 프로그래밍

## 📌 미션 주제  
**0~255 사이의 수를 입력받아 다음 작업을 수행하는 프로그램을 생성형 AI를 이용하여 작성한다.**

### 🎯 구현 기능
1. 입력받은 수를 **8비트 2진수로 출력**
2. 해당 2진수에서 **1의 개수 출력**
3. **상위 4비트 출력**

---

## 🤖 사용한 생성형 AI  
**ChatGPT** (OpenAI GPT-4)

---

## 💬 사용한 명령 프롬프트 (Prompt)

1. `"0~255 사이의 수를 입력 받아 2진수로 출력하고, 1의 개수가 몇 개인지 출력하고, 8비트 중에 상위 4비트를 출력하는 프로그램을 만들어줘."`  
2. `"위 기능을 다양한 언어로도 구현해줘 (Python, C, Java, JavaScript, C++, Go, Rust 등)."`
3. `"GitHub README에 쓸 수 있도록 마크다운 형식으로 정리해줘."`

---

## 🧑‍💻 생성된 코드 언어별 예시

### ✅ Rust (예시 언어)

```rust
use std::io;

fn main() {
    println!("0~255 사이의 정수 입력:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let num: u8 = match input.trim().parse() {
        Ok(n) if n <= 255 => n,
        _ => {
            println!("잘못된 입력입니다.");
            return;
        }
    };

    let binary = format!("{:08b}", num);
    let ones_count = binary.chars().filter(|&c| c == '1').count();
    let upper_4 = &binary[..4];

    println!("입력된 숫자: {}", num);
    println!("2진수(8비트): {}", binary);
    println!("1의 개수: {}", ones_count);
    println!("상위 4비트: {}", upper_4);
}
```

> 📌 다른 언어(Python, C, Java 등) 버전은 언어별 파일로 정리되어 있습니다.

---

## 🎯 실행 예시

```
0~255 사이의 정수 입력:
213
입력된 숫자: 213
2진수(8비트): 11010101
1의 개수: 5
상위 4비트: 1101
```


---

## 📌 정리하며

이 프로젝트는 생성형 AI(ChatGPT)를 활용하여 간단한 논리적 사고 기반 프로그래밍을 자동화하고, 다국어 코드 생성을 테스트해보는 데에 의의가 있습니다.  
각 언어 간 구현 차이, 표현 방식, 타입 시스템 등을 비교해보는 것도 좋은 학습 경험이 될 것입니다.
