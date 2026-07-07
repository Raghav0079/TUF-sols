
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

class Student extends School {
    private String name ; 
    Student(String name){
        super(name : "dps");
        this.name = name ;

    }
    void printStudentName(){
        super.printSchoolName();
        System.out.println("Student name:" + name);

    }
    @Override
    void demo(){
        super.demo();
        System.out.println(x:"demo of student");
    }

}



public class Main{
    public static void main(String[] args) {
        Student student = new Student (name : "abs");
        student.printStudentname();
        student.demo();
        student.printSchoolName();
        
    }
}