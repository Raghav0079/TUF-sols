class Product {
    private String name;
    private String category;
    private double price;

    Product(String name, String category, double price) {
        this.name = name;
        this.category = category;
        this.price = price;
    }

    void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Category: " + category);
        System.out.println("Price: $" + price);
    }
}

class Electronics extends Product {
    private int warrantyPeriodInYears;
    private String brand;

    // Fixed the constructor parameters and syntax
    Electronics(int warrantyPeriodInYears, String brand, String name, double price) {
        super(name, "Electronics", price); // Fixed: Removed 'category:' syntax
        this.warrantyPeriodInYears = warrantyPeriodInYears;
        this.brand = brand;
    }

    @Override
    void displayDetails() {
        super.displayDetails(); // Calls Product's displayDetails to show name, category, price
        System.out.println("Brand: " + brand);
        System.out.println("Warranty: " + warrantyPeriodInYears + " year(s)");
    }
}

class Tshirt extends Product {
    private String size;
    private String color;

    Tshirt(String size, String color, double price, String name) {
        super(name, "Tshirt", price);
        this.size = size;
        this.color = color;
    }

    @Override
    void displayDetails() {
        super.displayDetails(); // Calls Product's displayDetails to show name, category, price
        System.out.println("Size: " + size);
        System.out.println("Color: " + color);
    }
}

public class Main2 {
    public static void main(String[] args) {
        // 1. Instantiate an Electronics object
        // Parameters: warranty, brand, name, price
        Electronics laptop = new Electronics(2, "Dell", "XPS 13", 1200.00);
        
        System.out.println("--- Electronics Details ---");
        laptop.displayDetails();

        System.out.println("\n----------------------------\n");

        // 2. Instantiate a Tshirt object
        // Parameters: size, color, price, name
        Tshirt shirt = new Tshirt("L", "Crimson Red", 24.99, "Vintage Graphic Tee");
        
        System.out.println("--- T-Shirt Details ---");
        shirt.displayDetails();
    }
}