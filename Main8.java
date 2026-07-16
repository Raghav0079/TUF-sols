class SelfMadeException extends Exception {
    SelfMadeException(String message) {
        super(message); // Passes the message to the parent Exception class
        System.out.println("I was created!"); 
    }
}

public class Main8 {
    
    private static void readFile() throws SelfMadeException {
        
        throw new SelfMadeException("Custom Error: File path is empty."); 
    }

    public static void main(String[] args) {
        try {
            readFile();
        } catch (SelfMadeException e) { 
            System.out.println("Caught custom exception: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Caught general exception: " + e.getMessage());
        }
    }
}