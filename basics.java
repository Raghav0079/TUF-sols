
import java.util.Deque;
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
        LinkedList<Integer> ll = new Linkedlist <> () ;
        ll.add (e:1);
        ll.add(e:2);
        ll.addFirst(e:3);
        ll.addList(e:6);
        System.out.println(ll);
        ll.removeLast();
        System.out.println(ll);

    }
}