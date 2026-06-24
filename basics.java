



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
        List<Integer> list = new ArrayList<>();
        list.add(3);
        list.add(1);
        list.add(2);
        int max = Collections.max(list);
        System.out.println(max); // Output: 3// Output: [1, 2, 3]
    }
}