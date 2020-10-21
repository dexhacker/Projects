import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

public class Main {

    public static void main(String[] args) throws Exception {
        FieldGetter fieldGetter = new FieldGetter();
        Object result = fieldGetter.getFieldValue(new Example(), "age");
        System.out.println(result);
    }

}

class Example {
    private int age;

    public Example() {
        this.age = 5;
    }
}

class FieldGetter {

    public Object getFieldValue(Object object, String fieldName) throws IllegalAccessException {
        Class objectClass = object.getClass();
        Field[] fields = objectClass.getDeclaredFields();
        for (Field field : fields) {
            int modifiers = field.getModifiers();
            if (field.getName().equals(fieldName) && Modifier.isPublic(modifiers)) {
                return field.get(object);
            }
        }
        return null;
    }

}
