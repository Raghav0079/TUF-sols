
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


class Teacher extends School{
    private String name;
    private String subjectName;

    Teacher(String name , String subjectName){
        this.name = name ;
        this.subjectName = subjectName; 

    }
    void printTeacherInfo(){
        System.out.println("Name : " + name);
        System.out.println("Subject name :" + subjectName);
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