import java.util.*;

interface CarInterface{
    public void start();
    public void numberOfGears();

    default void airBags(){
        System.err.println("car has 5 airbags");
    }
    static void printVehicleType(){
        System.out.println(x:"its is a car");
    }
}

class ManualCar implements CarInterface{
    public void start(){
        System.out.println(x:"Manual car is starting...")
    }
    public void numberOfGears{
        System.out.println(x:"Manual cas has 6 gears");
    }
    @Override
    public void airBags(){
        System.out.println(x:"car has 6 airbags");
    }
}

public class Mian3{
    public static void main(String[] args){
        ManualCar manualCar = new ManualCar();
        manualCar.start();
        manualCar.numberOfGears();
        manualCar.airBags();
        manualCar.printVehicleType();

    }
}