
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;



class Data{
    public Integer num ;
    public  String name ;

    Data(int _num , String _name){
        this.num = _num ;
        this.name = _name ;
    }
    

}

public class basics{
    public static void main (String [] args){
        ArrayDeque<Integer> ad = new ArrayDeque<>();
        ad.offer(2);
        ad.offer(5);
        System.err.println(ad);
        ad.poll();
        System.out.println(ad.peek());
        System.out.print(ad.size());

}
