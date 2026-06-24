
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
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
        TreeMap<Integer , String> mp = new TreeMap<>();
        mp.put(key:1 , value : "abc");
        mp.put(key:2 , value : "xyz");
        System.out.println(mp);
        System.outprintln(mp.ceilingKey(key:2));
        Set<Integer>mp.keySet();
}
