import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Main {

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("dataset_91069.txt"));
            long max = 0;
            int maxYear = 0;
            int previousYear = 0;
            long previousPopulation = 0;

            if (scanner.hasNext()) {
                scanner.nextLine();
            }

            while (scanner.hasNext()) {
                int year = scanner.nextInt();
                String populationString = scanner.next();
                String populationReplaced = populationString.replace(",", "");
                long population = Long.parseLong(populationReplaced);

                long difference = population - previousPopulation;
                System.out.println(difference + " " + year);


                if (previousPopulation != 0 && difference > max) {
                    max = difference;
                    maxYear = year;
                }
                previousYear = year;
                previousPopulation = population;
            }


            System.out.println(previousYear);
        } catch (FileNotFoundException e) {
            System.out.println("Error");
        }
    }

}
