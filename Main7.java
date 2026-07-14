class Passport{
    STring passportNumber;
    Passport(String passportNumber){
        this.passportNumber = passportNumber;
    }
}

class Student implements Cloneable{
    String name ;
    Passport passport ;

    Student(String name , Passport passport){
        this.name = name ;
        this.passport = passport ;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException{
        return super.clone();
    }

}

public class Main{
    public static void main(String[] args) throws CloneNotSupportedException{
        Passport passport = new Passport("123456789");
        Student student = new Student (name : "abs" , passport);

        Student clonedStudent = (Student) student.clone();

        System.out.println(student.name);
        System.out.println(student.passport.passportNumber);
        System.out.println(clonedStudent.name);
        System.out.println(clonedStudent.passport.passportNumber);
    }
}