public class Main {

    public static void main(String args[]) {

    	A a = new B();

    	System.out.println(a instanceof B);
    	System.out.println(a.getClass() == B.class);
    	System.out.println(a.getClass() == A.class);
    	System.out.println(a instanceof A);

    }

}

class A { }

class B extends A { }
