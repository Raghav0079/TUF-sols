
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


class Parent extends Student{
    private String name ;
    Parent(String name , String studentName){
        super(studentName);
        this.name = name;

    }
    void printParentName(){
        System.out.println("Parent name:" + name);
    }

}
public class Main{
    public static void main(String[] args) {
        Parent parent = new Parent (name : "dad" , studentName : "abs");
        parent.printParentName();
        parent.printStudentName();
        parent.printSchoolName();
    }
}