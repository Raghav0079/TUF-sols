class Data{
    public Integer num ;
    public String name ;
    Data(int _num , String _name){
        this.num = _num ;
        this.name = _name ;
    }    
}


public class basics{
    public static void main (String [] args){
        Data dataObj1 = new Data(_num:9 , _name : "abc");
        Data dataObj2 = new Data(_num:7 , _name : "xyz");
        dataObj1.name = "TUF";
        System.out.println(dataObj2.name);
    }
}