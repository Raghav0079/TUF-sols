
abstract class Car {
    abstract public void start();
    
    public void noise() {
        System.out.println("Noise...."); // Fixed syntax and added semicolon
    }
}


class CarInterface{
    public void start();
}

class ManualCar implements CarInterface{
    public void start(){
        System.out.println(x:"Manual car is starting");
    }
}


class ManualCar extends Car {
    public void start() {
        System.out.println("Manual car is starting"); // Fixed syntax
    }
    
    public void printName() {
        System.out.println("Hey I am manual"); // Fixed syntax
    }
}

class AutomaticCar extends Car {
    public void start() {
        System.out.println("Automatic car is starting"); // Fixed syntax
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
    }
}