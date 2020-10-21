import java.lang.reflect.Method;

class Main {

    public static void main(String[] args) {
    	try {
	    	String[] classNames = { "java.lang.String", "java.lang.StringBuffer", "java.lang.Math" };
	    	String result = MethodFinder.findMethod("abs", classNames);
	    	System.out.println(result);
	    } catch (ClassNotFoundException e) {
	    	System.out.println("Here");
	    }
    }

}

class MethodFinder {

    public static String findMethod(String methodName, String[] classNames) throws ClassNotFoundException {
        for (String className : classNames) {
            Class klass = Class.forName(className);
            for (Method klassMethod : klass.getMethods()) {
                String klassMethodName = klassMethod.getName();
                if (klassMethodName.equals(methodName)) {
                    return klass.getName();
                }
            }
        }
        return "";
    }

}
