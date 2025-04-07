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
