
abstract class Car {
    abstract public void start();
    
    public void noise() {
        System.out.println("Noise...."); 
    }
}


interface  CarInterface{
    public void start();

    default void noise(){
        System.out.println(x:"Noise...");
    }

    static int numberOfWheels(){
        System.out.println(x:"Wheels : 4");
    }
}

class ManualCar implements CarInterface{
    public void start(){
        System.out.println(x:"Manual car is starting");
    }
}


class ManualCar extends Car {
    public void start() {
        System.out.println("Manual car is starting"); 
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
    }
}