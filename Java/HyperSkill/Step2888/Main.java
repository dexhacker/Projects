public class Main {

    public static void main(String[] args) throws Exception {
        Main.class.getMethod("hello").invoke(null);
    }

    static void hello() {
        System.out.println("Hello world!");
    }

}
