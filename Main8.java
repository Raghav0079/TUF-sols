import javax.naming.InsufficientResourcesException;

class SelfMadeException extends Exception {
    SelfMadeException(String message) {
        super(message);
        System.out.println("I was created!"); 
    }
}

class BankBalance {
    String name;
    double amount;

    BankBalance(String name, double amount) { 
        this.name = name;
        this.amount = amount;
    }

    public void addBalance(double val) {
        amount += val;
    }
    
    // Fixed: Added 'throws InsufficientResourcesException' to method signature
    public void withdrawBalance(double val) throws InsufficientResourcesException {
        if (val > amount) {
            // Fixed: Added 'new', complete class name, constructor message, and semicolon
            throw new InsufficientResourcesException("Error: Insufficient funds! Current balance: $" + amount);
        }
        amount -= val; // Deduct amount if successful
        System.out.println("Successfully withdrew $" + val + ". New balance: $" + amount);
    }
}

public class Main8 {
    
    private static void readFile() throws SelfMadeException {
        throw new SelfMadeException("Custom Error: File path is empty."); 
    }

    public static void main(String[] args) {
        // --- Testing File Reader Exception ---
        try {
            readFile();
        } catch (SelfMadeException e) { 
            System.out.println("Caught custom exception: " + e.getMessage());
        }

        System.out.println("\n---------------------------------------\n");

        // --- Testing Bank Balance Exception ---
        BankBalance account = new BankBalance("Raghav", 500.0);
        
        try {
            System.out.println("Attempting to withdraw $200...");
            account.withdrawBalance(200.0); // Should succeed
            
            System.out.println("Attempting to withdraw $400...");
            account.withdrawBalance(400.0); // Should fail! (Remaining balance is $300)
            
        } catch (InsufficientResourcesException e) {
            System.out.println("Caught banking exception: " + e.getMessage());
        }
    }
}