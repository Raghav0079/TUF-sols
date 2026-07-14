import java.util.*;



class Student{
    private String name ;
    private List<Course> course;
    Student(String name){
        this.name = name ;
        courses = new ArrayList<>();
    }

    public void addCourse(Course course){
        courses.add(course);
    }

    public void displayAllStudents() {
        for(int  i =0 ; i<students.size() ; i++){
            System.out.println("Name" + students.get(i).getName());
        }
    }
 
}

class Course{
    private String name;
    private List<Course> students;

    Course(String name){
        this.name = name;
        students = new ArrayList<> ();
    }

    public void addStudent(Student student){
        students.add(student);
    }

    public void displayAllStudents() {
        for(int  i =0 ; i<students.size() ; i++){
            System.out.println("Name" + students.get(i).getName());
        }
    }
}


public class Main6{
    public static void main(String[] args) {
        Course maths = new Course(name:"Math");
        Course cs = new Course(name:"CS");

        Student abs = new Student(name : "abs");
        Student abc = new Student(name : "abc");
        Student abj = new Student(name : "abj");

        abs.addCourse(math);
        abs.addCourse(cs);

    }
}