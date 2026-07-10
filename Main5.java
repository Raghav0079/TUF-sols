
import java.util.ArrayList;



public class Main5{
    public static void main(String[] args) {
        ArrayList <Integer> list = new ArrayList<>(){
            @Override
            public boolean add(Integer val){
                System.out.println("val is not added:" ++ val);
                if( val % 2 == 1) return false;
                return super.add(val);
            }

        }
        list.add(e:18);
        list.add(e:7);
        System.out.println(list);
    }
}
