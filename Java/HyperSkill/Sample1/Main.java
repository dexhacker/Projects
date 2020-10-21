import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        String a = "qweqwe";
        String b = "qweqwe";
        System.out.println(Objects.equals(a, b));

        Long l1 = Long.valueOf("2000");;
        Long l2 = Long.valueOf("2000");;
        System.out.println(l1 == l2);
        System.out.println(l1.equals(l2));
    }
}
