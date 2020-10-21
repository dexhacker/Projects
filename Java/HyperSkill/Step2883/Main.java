import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

class Main {

    public static void main(String[] args) {
        Example example = new Example();
        FieldGetter fieldGetter = new FieldGetter();
        List<String> result = fieldGetter.getPrivateFields(example);
        System.out.println(result.toString());
    }

}

class Example {
    private int lastName;
    private int age;
    private int firstName;
}

class FieldGetter {

    public List<String> getPrivateFields(Object object) {
        Class objectClass = object.getClass();
        Field[] fields = objectClass.getDeclaredFields();
        List<String> result = new ArrayList<>();
        for (Field field : fields) {
            if (Modifier.isPrivate(field.getModifiers())) {
                result.add(field.getName());
            }
        }
        Collections.sort(result);
        return result;
    }

}
