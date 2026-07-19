import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

class Logger {
    private String path;

    Logger(String path) throws IOException {
        File file = new File(path);
        if (!file.exists()) {
            file.createNewFile();
        }
        this.path = path;
    }

    public void log(String message) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(path, true))) {
            bw.write(message);
            bw.newLine();
        } catch (Exception e) {
            System.out.println("failed to log this message " + message);
        }
    }
}

public class Main10 {
    public static void main(String[] args) throws IOException {
        Logger logger = new Logger("C:\\Users\\Raghav\\OneDrive\\Desktop\\TUF-sols\\TUF-sols\\logfile.txt");
        logger.log("log1");
    }
}