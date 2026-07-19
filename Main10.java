import java.io.BufferedReader;
import java.io.FileReader;

public class Main10 {
    public static void main(String[] args) {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("C:\\Users\\Raghav\\OneDrive\\Desktop\\TUF-sols\\TUF-sols\\testing.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}