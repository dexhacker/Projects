import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String result = "";

        int charAsNumber = reader.read();
        while (charAsNumber != -1) {
        // while (charAsNumber != 10) {
            char symbol = (char) charAsNumber;
            result = symbol + result;
            charAsNumber = reader.read();
        }
        System.out.println(result);
        reader.close();
    }
}
