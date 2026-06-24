
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;



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
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(1);
        pq.offer(2);

        System.out.println(pq.peek());
        pq.pull();
        System.out.println(pq.peek());
        pq.pull();
        System.out.println(pq.peek());



}
