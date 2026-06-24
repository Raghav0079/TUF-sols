
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
        Stack<Integer> st = new Stack ;
        st.push(item:2);
        st.push(item:30);
        st.push(item:15);
        System.out.println(st);
        System.out.print(st.peek());

    }
}