package RegularExpressionMatching;

import java.util.regex.*;

public class Solution {
    public boolean isMatch(String s, String p) {
        return Pattern.matches(p, s);
    }
}
