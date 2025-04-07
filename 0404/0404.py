def analyze_binary():
    number = int(input("0~255 사이의 정수를 입력하세요: "))

    if number < 0 or number > 255:
        print("입력값이 범위를 벗어났습니다.")
        return

    binary_str = format(number, '08b')
    ones_count = binary_str.count('1')
    upper_4_bits = binary_str[:4]

    print(f"입력값: {number}")
    print(f"8비트 이진수: {binary_str}")
    print(f"1의 개수: {ones_count}")
    print(f"상위 4비트: {upper_4_bits}")

if __name__ == "__main__":
    analyze_binary()
