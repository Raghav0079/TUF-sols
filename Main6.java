import java.util.*;



class Student{
    private String name ;
    private String id;

    Student(String name , String id){
        this.name = name ;
        this.id = id;

    }
    public void getName(){
        return name;
    }
    public String getId(){
        return id;
    }

    

}

class College{
    private String name ;
    private List<Student>  students;
    College(String name){
        this.name = name;
        students = new ArrayList<>();
    }
    public static void addStudent(Student student) {
        students.add(student);
    }
    public void printAllStudents(){
        for(int i =0 ; i< students.size() ; i++){
            Student student = students.get(i);
            System.out.println("Name" + student.getName() + "id:" + student.getId());
        }
    }
}
public class Main6{
    public static void main(String[] args) {
        Student student1 = new Student(name:"aabs" , id :"1");
        Student student2 = new Student(name:"abbs" , id :"2");

        College college = new College(name : "JKL");
        college.addStudent(student1);
        college.addStudent(student2);

        college.printAllStudents();


    }
}