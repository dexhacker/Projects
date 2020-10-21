import java.util.Arrays;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;

class Main {

    public static void main(String[] args) {
        Example example = new Example();
        FieldGetter fieldGetter = new FieldGetter();
        String[] result = fieldGetter.getPublicFields(example);
        System.out.println(Arrays.toString(result));
    }

}

class Example {
    public int age;
    public int name;
}

class FieldGetter {

    public String[] getPublicFields(Object object) {
        Class objectClass = object.getClass();
        Field[] fields = objectClass.getDeclaredFields();
        String[] oldResult = new String[0];
        for (Field field : fields) {
            if (Modifier.isPublic(field.getModifiers())) {
                String[] result = new String[oldResult.length + 1];
                System.arraycopy(oldResult, 0, result, 0, oldResult.length);
                result[oldResult.length] = field.getName();
                oldResult = result.clone();
            }
        }
        return oldResult;
    }

}
