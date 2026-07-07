
class Product{
    private String name;
    private String category;
    private double price ;
    Product(String name  , String category , double price){
        this.name = name ;
        this.category = category ;
        this.price = price ;
    }

    void displayDeatails(){
        System.out.println("Name :" + name);
        System.out.println("Price :" + price);
        System.out.println("Category :" + category);

    }

}

class Electronics extends Product{
    private int warrantyPeriodInYears;
    private String brand ;

    Electronics (int warrantyPeriodInYears , String brand , String name , double price){
        super(name , category: "Electronics" , price);
        this.warrantyPeriodInYears = warrantyPeriodInYears;
        this.brand = brand;
    }

    void displayDeatails(){
        System.out.println("warranty:" + warrantyPeriodInYears);
        System.out.println("brand:" + brand);
    }


}

class Tshirt extends Product{
    private String size;
    private String color;

    Tshirt(String size , String color , double price , String name) {
        super(name , "Tshirt" , price);
        this.size=size;
        this.color = color ;
    }
    void displayDeatails(){
        System.out.println("Size" + size);
        System.out.print("Color" + color);
    }

    
}

public class Main2{
    public static void main(String[] args){
        Student student = new Student("abs");
        student.demo(198);
        student.demo("18");
    }

}