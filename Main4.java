import java.util.*;

interface CarInterface {
    static final int cnt = 0;
    public void start();
    public void numberOfGears();

    default void airBags() {
        System.err.println("car has 5 airbags");
    }
    
    static void printVehicleType() {
        System.out.println("it is a car");
    }
}

interface SunRoof {
    public void sunRoof(); // Changed to camelCase to match standard Java conventions
}

class ManualCar implements CarInterface, SunRoof {
    int doors = 4; // Defined 'doors' so the print statement works

    public void start() {
        airBags();
        System.out.println("Manual car is starting..." + doors);
    }
    
    public void numberOfGears() { // Added missing ()
        System.out.println("Manual car has 6 gears");
    }
    
    @Override
    public void airBags() {
        System.out.println("car has 6 airbags");
    }

    @Override
    public void sunRoof() { // Implemented the missing SunRoof interface method
        System.out.println("Manual car has a panoramic sunroof");
    }
}

public class Main4 {
    public static void main(String[] args) {
        // Changed reference type to ManualCar so it can access both interfaces' methods
        ManualCar manualCar = new ManualCar(); 
        
        manualCar.start();
        manualCar.numberOfGears();
        manualCar.sunRoof(); // Fixed typo casing 'manualcar' -> 'manualCar'
    }
}