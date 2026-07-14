import java.util.*;

class Passport{
    private string passportNumber;

    public Passport(String passportNumber) {
        this.passportNumber = passportNumber;
    }
    public string getpassportNumber(){
        return passportNumber;
    }
}

class Student{
    private String name ;
    private String passport;

    Student(String name , Passport passport){
        this.name = name ;
        this.passport = passport;

    }

    public void displayDetails(){
        System.out.println("student name :" + name);
        System.out.println("Passport number" + passport.getpassportNumber());
    }

}

public class Main6{
    public static void main(String[] args) {
        Passport passport = new Passport(passportNumber : "123456789");
        Student student = new Student("abs" , passport); 
        
    }
}