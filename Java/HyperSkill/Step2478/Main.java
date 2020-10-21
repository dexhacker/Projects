public class Main {
    public static void main(String[] args){
        double result = Converter.convertStringToDouble(null);
        System.out.println(result);
    }
}

class Converter {

    /**
     * It returns a double value or 0 if an exception occurred
     */
    public static double convertStringToDouble(String input) {
        if (input == null) {
            return 0;
        }
        try {
            return Double.parseDouble(input);
        } catch (NumberFormatException e) {
            return 0;
        }
    }
}
