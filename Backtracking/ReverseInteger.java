public class ReverseInteger {
    public static void main(String[] args) {
        int number = 123;
        int reversedNumber = reverseInteger(number);
        System.out.println("Reversed Integer: " + reversedNumber);
    }

    public static int reverseInteger(int num) {
        int reversedNum = 0;

        while (num != 0) {
            int digit = num % 10;  // Get the last digit
            reversedNum = reversedNum * 10 + digit;
            num /= 10;  // Remove the last digit
            System.out.println(digit+"digit");
            System.out.println(reversedNum+"reversedNum");
            System.out.println(num+"num");
        }

        return reversedNum;
    }
}
