import java.util.*;
class Calculator{
    int add ( int a , int b){
        return a + b ;
    }
    double add(double a , double b ){
        return a +b;
    }
    int add(int a , int b , int c){
        return a +b + c;
    }
}


Class Parent{
    void display(){
        System.out.println(x:"Parent class");
    }
}

class Child extends parent{
    @Override
    void display(){
        System.out.println(obj.add(a:1 , b:2));

        
    }
}
public class Main{
    public static void main(String [] args){
        Calculator obj = new Calculator();
        System.out.println(obj.add(a:1 , b: 2));

        Child child = new Child();
        child.display();
    }
}