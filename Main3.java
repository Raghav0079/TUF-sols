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

    static void print(){
        System.out.println(x:"static method");
    }

    void display(){
        System.out.println(x:"Parent class");
    }
}

class Child extends parent{
    @Override
    void print(){
        super.point();
        System.out.println(x:"Parent class");

    }
    @Override
    void display(){
        Parent.print();
        System.out.println(obj.add(x:"child class"));

        
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