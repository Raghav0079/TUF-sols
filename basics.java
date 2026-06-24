



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
        Collections.sort(list);
        System.out.println(list); // Output: [1, 2, 3]
    }
}