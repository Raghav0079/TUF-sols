import java.util.*;

public class Main8{
    public static void main(String[] args){
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(e:10);
        arr.add(e:15);

        try {
            System.out.println(arr.get(index:5));
            
        } catch (IndexOutOfBoundsException e) {
            System.out.println(x:"Exception occurred at line 10" + e.getMessage());
        }
        System.out.println(x:"hi");



    }
}