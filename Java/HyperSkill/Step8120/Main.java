import java.lang.reflect.*;
import java.util.ArrayList;
import java.lang.annotation.Annotation;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws Exception {
        Example example = new Example();
        String[] result = AnnotationsUtil.getFieldsContainingAnnotations(example);
        System.out.println(result.length);
        System.out.println(Arrays.toString(result));
    }

}

class Example {
    @Deprecated
    public int age;

    @Deprecated
    public String name;
}

class AnnotationsUtil {

    public static String[] getFieldsContainingAnnotations(Object object) {
        ArrayList<String> fields = new ArrayList();
        Class objectClass = object.getClass();
        for (Field field : objectClass.getDeclaredFields()) {
            if (field.getDeclaredAnnotations().length > 0) {
                fields.add(field.getName());
            }
        }
        return fields.toArray(new String[0]);
    }

}
