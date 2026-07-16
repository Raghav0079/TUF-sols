import java.util.*;

public class Main8{
    public static void main(String[] args){
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(e:10);
        arr.add(e:15);

        try {
            int x = 2/0 ;
            System.out.println(arr.get(index:5));
            
        } catch (ArithmeticException e) {
            System.out.println(x:"Exception occurred at line 10" + e.getMessage());
        }
        catch(IndexOutOfBoundsException e){
            System.out.println(e.getMessage());

        }

        System.out.println(x:"Hi");





    }
}