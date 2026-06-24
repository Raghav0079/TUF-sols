
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
        HashSet<Integer> hs = new HashSet<>();
        hs.add(e:1);
        hs.add(e:2);
        hs.add(e:1);
        hs.add(0);
        System.out.println(hs);
        hs.remove(2);
        for ( var num : hs){
            System.out.println(num);
        }
    }
}