class School {
    private String name;

    // Constructor
    School() {
        name = "DPS";
    }

    void printSchoolName() {
        System.out.println("School name: " + name);
    }
}

class Student {
    private String name;

    // Parameterized Constructor
    Student(String name) {
        this.name = name;
    }

    void printStudentName() { // Fixed a minor typo in method name capitalization
        System.out.println("Student name: " + name);
    }
}

public class Main {
    public static void main(String[] args) {
        // 1. Create an object of the School class
        School mySchool = new School();
        // Call the method to print the school name
        mySchool.printSchoolName();

        System.out.println("--------------------"); // Visual separator

        // 2. Create an object of the Student class (passing the name to the constructor)
        Student myStudent = new Student("John Doe");
        // Call the method to print the student name
        myStudent.printStudentName();
    }
}