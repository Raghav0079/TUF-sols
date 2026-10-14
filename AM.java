import java.util.*;

class Employee {
    public String name; // Public attribute
    protected int employeeId; // Protected attribute
    private double salary; // Private attribute

    // Constructor
    public Employee(String name, int employeeId, double salary) {
        this.name = name;
        this.employeeId = employeeId;
        if (salary >= 0) {
            this.salary = salary;
        } else {
            this.salary = 0.0;
            System.out.println("Invalid salary");
        }
    }

    // Method to set the salary
    public void setSalary(double salary) {
        if (salary < 0) {
            System.out.println("Invalid salary");
            this.salary = 0.0;
            return;
        }
        this.salary = salary;
    }

    // Method to get the salary
    public double getSalary() {
        return this.salary;
    }

    // Method to display employee details
    public void displayEmployeeDetails() {
        System.out.println("Name : " + name);
        System.out.println("Employee Id : " + employeeId);
        System.out.printf("Salary : %.2f\n", salary);
    }
}

class AM {
    public static void main(String[] args) {
        // Hardcoded input
        String name = "Striver";
        int employeeId = 9656;
        double salary = 10000;
        double newSalary = 15840;

        // Creating Employee object
        Employee emp = new Employee(name, employeeId, salary);

        // Display initial salary
        System.out.printf("Salary : %.2f\n", emp.getSalary());

        // Update salary
        emp.setSalary(newSalary);

        // Display all details
        emp.displayEmployeeDetails();
    }
}