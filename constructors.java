import java.util.*;

class Rectangle {
    private double length;
    private double width;
    private double area;

    // Default constructor
    public Rectangle() {
        this.length = 1.0;
        this.width = 1.0;
    }

    // Parameterized constructor
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Method to calculate the area of the rectangle
    public void calculateArea() {
        this.area = this.length * this.width;
    }

    // Method to display the details of the rectangle
    public void displayDetails() {
        System.out.printf("Length : %.2f\n", this.length);
        System.out.printf("Width : %.2f\n", this.width);
        System.out.printf("Area : %.2f\n", this.area);
    }
}



class constructorDemo {
    public static void main(String[] args) {
        // Using default constructor
        Rectangle defaultRect = new Rectangle();
        defaultRect.calculateArea();
        defaultRect.displayDetails();
 
        // Using parameterized constructor
        Rectangle customRect = new Rectangle(5.0, 3.0);
        customRect.calculateArea();
        customRect.displayDetails();
    }
}