package StringToIntegerAtoi;

public class Solution {
    public int myAtoi(String str) {
        StringBuilder builder = new StringBuilder();
        boolean hasMinus = false;
        boolean hasDote = false;
        boolean hasPlus = false;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))) {
                builder.append(str.charAt(i));
                hasPlus = true;
                hasMinus = true;
            } else if (str.charAt(i) == '-' && !hasMinus) {
                hasMinus = true;
                hasPlus = true;
                builder.append(str.charAt(i));
            } else if (str.charAt(i) == ' ') {
                if (!builder.toString().equals("")) {
                    break;
                }
            } else if (str.charAt(i) == '.' && !hasDote) {
                hasDote = true;
                builder.append(str.charAt(i));
            } else if (str.charAt(i) == '+' && !hasPlus) {
                hasPlus = true;
                hasMinus = true;
                builder.append(str.charAt(i));
            } else {
                break;
            }
        }

        try {
            double number = Double.parseDouble(builder.toString());
            if (number > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            } else if (number < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            } else {
                return (int)number;
            }
        } catch (java.lang.NumberFormatException error) {
            return 0;
        }
    }
}
