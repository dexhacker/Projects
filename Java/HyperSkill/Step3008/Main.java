public class Main {
    public static void main(String[] args) {
        MyClass myClass = new MyClass();
        myClass.doDo();
    }

}

class MyClass {
    static final String TEXT = "Hello";

    int magic = 10;

    static void doSomething() {
        System.out.println(TEXT);
    }

    public void doDo() {
        System.out.println(TEXT);
    }
}
