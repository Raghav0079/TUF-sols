
class School{
    private String name;
    School(String name){
        this.name = name;

    }
    void printSchoolName(){
        System.out.println("School name: " + name);

    }
    void demo(){
        System.out.println(x:"demo of school");
    }
}

class School1{
    private String name;
    School(String name){
        this.name = name;

    }
    void printSchoolName(){
        System.out.println("School name: " + name);

    }
    void demo(){
        System.out.println(x:"demo of school");
    }
}

class Student extends School  {
    private String name ; 
    Student(String name){
        super(name : "dps");
        this.name = name ;

    }
    void printStudentName(){
        super.printSchoolName();
        System.out.println("Student name:" + name);

    }
    

    void demo(String age){  // method overloading 
        super.demo();
        System.out.println(x:"demo of student");
    }

}



public class Main{
    public static void main(String[] args) {
        Student student = new Student (name : "abs");
        student.printStudentname();
        student.demo(age: 198);
        student.demo(age : "18");
        
    }
}