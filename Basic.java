import java.util.Scanner;

class Basic{
    public static void main ( String[] args){
        Scanner scanner = new Scanner(System.in);

        int i =2;

        while(i <= 50){
            System.out.println(i);
            i = i +2 ;
        }
        scanner.close();
    }

}