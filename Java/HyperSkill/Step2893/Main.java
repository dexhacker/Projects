import java.io.PrintStream;

class Main {

    public static void main(String[] args) throws Exception {
        System.class
                .getField("out").getType()
                .getMethod("println", String.class)
                .invoke(new PrintStream(System.err), "Hello!");
    }

}
