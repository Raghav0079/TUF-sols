class School {
    private String schoolName; // Renamed to avoid confusion with student's name

    School() {
        schoolName = "DPS";
    }

    void printSchoolName() {
        System.out.println("School name: " + schoolName);
    }
}

class Student extends School {
    private String studentName;

    Student(String name) {
        // Java automatically calls super() here to run School's constructor
        this.studentName = name;
    }

    void printStudentName() { 
        System.out.println("Student name: " + studentName);
    }
    
    
    void printStudentDetails() {
        printStudentName();  // Student's own method
        printSchoolName();   // Inherited from School class!
    }
}

public class Main {
    public static void main(String[] args) {
        Student myStudent = new Student("John Doe");
        
        // This will print both the student name and the school they inherited
        myStudent.printStudentDetails();
    }
}