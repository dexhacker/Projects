import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Main {

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("dataset_91007.txt"));
            int max = 0;
            while (scanner.hasNextInt()) {
                int number = scanner.nextInt();
                if (max < number) {
                    max = number;
                }
            }
            System.out.println(max);
        } catch (FileNotFoundException e) {
            System.out.println("Error");
        }
    }

}
