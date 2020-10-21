import java.lang.reflect.Constructor;
import java.lang.reflect.Modifier;

public class Main {

    public static void main(String[] args) throws Exception {
        ConstructorChecker constructorChecker = new ConstructorChecker();
        boolean result = constructorChecker.checkPublicParameterlessConstructor(Example.class);
        System.out.println(result);
    }

}

class Example {
    public Example() {
        System.out.println("HERE");
    }

    public Example(String message) {
        System.out.println(message);
    }
}

class ConstructorChecker {

    public boolean checkPublicParameterlessConstructor(Class<?> clazz) {
        for (Constructor constructor : clazz.getDeclaredConstructors()) {
            Class[] params = constructor.getParameterTypes();
            int modifiers = constructor.getModifiers();

            if (params.length == 0 && Modifier.isPublic(modifiers)) {
                return true;
            }
        }
        return false;
    }

}
