class Data{
    private Integer num ;
    private String name ;
    private InternalData internalData ;

    Data(int _num , String _name){
        this.num = _num ;
        this.name = _name ;
        this.internalData= new InternalData(_revenue : 10000);
    }
    public void setNum(Integer _num){
        this.num = _num ;

    }
    public void setName(String _name){
        this.name = _name;

    }   
    public Integer getNum() {
        return num ;
    } 
    public String getName(){
        return name;
    }
}

class InternalData{
    public Integer revenue ;
    InternalData(Integer _revenue){
        this.revenue = -revenue;
    }
}
public class basics{
    public static void main (String [] args){
        Data dataObj1 = new Data(_num:9 , _name : "abc");
        Data dataObj2 = new Data(_num:7 , _name : "xyz");
        dataObj1.setName(_name:"TUF");
        System.out.println(dataObj2.getName());
    }
}