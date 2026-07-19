import java.io.BufferedWriter;
import java.io.FileWriter;

public class Main10 {
    public static void main(String[] args) {
        BufferedWriter bw = null;
        try {
            bw = new BufferedWriter(new FileWriter("C:\\Users\\Raghav\\OneDrive\\Desktop\\TUF-sols\\TUF-sols\\testing.txt"));
            bw.write("hey bro ");
            bw.flush();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            try {
                if (bw != null) {
                    bw.close();
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}