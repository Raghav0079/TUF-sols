abstract class Car {
    abstract public void start();
    
    public void noise() {
        System.out.println("Noise...."); 
    }
}


interface CarInterface {
    public void start();

    default void noise() {
        System.out.println("Noise...");
    }

    
    static void numberOfWheels() {
        System.out.println("Wheels : 4");
    }
}


abstract class Dealer extends Car {
    int numberOfCars;
    
    public void start() {
        System.out.println("Dealer car is starting");
    }
}


class ManualCar extends Dealer implements CarInterface {
    @Override
    public void start() {
        System.out.println("Manual car is starting"); 
    }
    
    
    @Override
    public void noise() {
        super.noise(); 
    }
    
    public void printName() {
        System.out.println("Hey I am manual"); 
    }
}

class AutomaticCar extends Car {
    public void start() {
        System.out.println("Automatic car is starting"); 
    }
}

public class Main3 {
    public static void main(String[] args) {
        Car manualCar = new ManualCar();
        manualCar.start();
        manualCar.noise();

        System.out.println();

        Car automaticCar = new AutomaticCar();
        automaticCar.start();
        automaticCar.noise();

        System.out.println();
        

        CarInterface.numberOfWheels();
    }
}