import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String regexNumber = "(\\d|\\d{2}|1\\d{2}|2[01234]\\d|25[012345])";
        String regexDot = "\\.";
        String regex = regexNumber + regexDot + regexNumber + regexDot + regexNumber + regexDot + regexNumber;

        Scanner scanner = new Scanner(System.in);
        String ip = scanner.nextLine();
        System.out.println(ip.matches(regex) ? "YES" : "NO");
    }
}
