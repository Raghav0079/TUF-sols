import java.io.*;

public class Main10 {
    public static void main(String[] args) throws IOException {
        File file = new File("C:\\Users\\Raghav\\OneDrive\\Desktop\\TUF-sols\\TUF-sols\\testing.txt");
        
        file.createNewFile();
        System.out.println(file.exists());
    }
}