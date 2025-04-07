import java.util.Scanner;

public class BinaryAnalysis {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("0~255 사이의 정수 입력: ");
        int num = scanner.nextInt();

        if (num < 0 || num > 255) {
            System.out.println("잘못된 입력입니다.");
            return;
        }

        String binary = String.format("%8s", Integer.toBinaryString(num)).replace(' ', '0');
        long count = binary.chars().filter(ch -> ch == '1').count();
        String upper4 = binary.substring(0, 4);

        System.out.println("입력된 숫자: " + num);
        System.out.println("2진수(8비트): " + binary);
        System.out.println("1의 개수: " + count);
        System.out.println("상위 4비트: " + upper4);
    }
}
