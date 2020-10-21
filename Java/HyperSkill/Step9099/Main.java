import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int charAsNumber = reader.read();
        boolean wasSpace = charAsNumber == 32;
        boolean anyLetter = false;
        int words = 1;
        // while (charAsNumber != -1) {
        while (charAsNumber != 10) {
            if (charAsNumber == 32) {
                if (wasSpace == false) {
                    words++;
                }
                wasSpace = true;
            } else {
                wasSpace = false;
                anyLetter = true;
            }
            charAsNumber = reader.read();
        }
        if (anyLetter == false) {
            words--;
        }

        System.out.println(words);
        reader.close();
    }
}
