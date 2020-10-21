import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();

        double determinant = b * b - 4 * a * c;
        double sqrt = Math.sqrt(determinant);

        double firstRoot = (-b + sqrt) / (2 * a);
        double secondRoot = (-b - sqrt) / (2 * a);
        if (firstRoot < secondRoot) {
            System.out.println(firstRoot + " " + secondRoot);
        } else {
            System.out.println(secondRoot + " " + firstRoot);
        }

        scanner.close();
    }
}
