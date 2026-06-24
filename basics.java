
import java.util.ArrayDeque;
import java.util.ArrayList;
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
        ArrayList<Integer> al = ArrayList<>();
        al.add(e:1);
        al.add(e:5);


        Iterator<Integer> iterator = al.iterator();
        while(iterator , hasNext()){
            Integer num = iterator.next();
            System.out.println(num);
        }
    }
}