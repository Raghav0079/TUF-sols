
class School{
    private String name;
    School(){
        name = "DPS";

    }
    void printSchoolName(){
        System.out.println("School name: " + name);

    }
}

class Student extends School {
    private String name ; 
    Student(String name){
        this.name = name ;

    }
    void printStudentName(){
        System.out.println("Student name:" + name);

    }

}

public class Main{
    public static void main(String[] args) {
        Student student = new Student (name : "abs");
        student.printStudentName();
        student.printSchoolName();
    }
}