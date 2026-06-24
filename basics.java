
import java.util.*;

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
        ArrayList<Data> aList = new ArrayList <> () ;
        aList.add(e:10);
        aList.add(e:16);
        aList.add(e:18);
        aList.add(e:20);
        System.out.println(aList);
        System.out.println(aList.size());
        System.out.println(aList.remove(index:2));
        System.out.println(aList);
    }
}