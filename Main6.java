import java.util.*;


class Passport{
    private String name ;
    Passport (String name){
        this.name = name ;
    }
}

class Student{
    private String name;
    private Passport passport;

    Student(String name , Passport passport ){
        this.name = name ;
        this.passport = new Passport(passportNumber) ;
    }
}


public class Main6{
    public static void main(String[] args) {
        
        Student student = new Student(name: "abs" , passportNumber:"123456789");
        

    }
}