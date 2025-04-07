package main

import (
	"fmt"
	"strconv"
)

func main() {
	var num int
	fmt.Print("0~255 사이의 정수 입력: ")
	fmt.Scan(&num)

	if num < 0 || num > 255 {
		fmt.Println("잘못된 입력입니다.")
		return
	}

	binary := fmt.Sprintf("%08b", num)
	count := 0
	for _, ch := range binary {
		if ch == '1' {
			count++
		}
	}
	upper4 := binary[:4]

	fmt.Println("입력된 숫자:", num)
	fmt.Println("2진수(8비트):", binary)
	fmt.Println("1의 개수:", count)
	fmt.Println("상위 4비트:", upper4)
}
