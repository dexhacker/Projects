import java.io.File;

public class Main {

    public static void main(String[] args) {
        File file = new File("basedir");
        String[] folders = file.list();
        int max = 0;
        String result = "";

        for (String folder : folders) {
            File folderObject = new File("basedir/" + folder);
            if (folderObject.list().length > max) {
                max = folderObject.list().length;
                result = folder;
            }
        }

        System.out.println(result + " " + max);
    }

}
