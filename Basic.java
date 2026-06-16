import java.util.Scanner;

class Basic{
    public static void main ( String[] args){
        Scanner scanner = new Scanner(System.in);
        
        String firstName = scanner.next();
        String lastName = scanner.next();
        System.out.println(firstName + "" + lastName);

        scanner.close(); 
    }
}