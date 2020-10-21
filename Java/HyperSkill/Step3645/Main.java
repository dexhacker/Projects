import java.io.File;

public class Main {
    private static int max = 0;
    private static String word = "";

    public static void main(String[] args) {
        findDeepHierarchy(0, "basedir");
        System.out.println(max);
        System.out.println(word);
    }

    private static void findDeepHierarchy(int count, String path) {
        File file = new File(path);
        try {
            for (String folder : file.list()) {
                findDeepHierarchy(count + 1, path + "/" + folder);
            }
        } catch (NullPointerException e) {
            if (max < count) {
                max = count;
                word = path;
            }
        }
    }

}
