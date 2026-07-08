import java.util.*;

interface CarInterface{
    static final int cnt =0;
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
        airBags();
        System.out.println(x:"Manual car is starting..." + doors);
    }
    public void numberOfGears{
        System.out.println(x:"Manual cas has 6 gears");
    }
    @Override
    public void airBags(){
        System.out.println(x:"car has 6 airbags");
    }
}

interface SunRoof{
    public void SunRoof();
}

public class Main4{
    public static void main(String[] args){
        CarInterface manualCar = new manualCar;
        manualCar.start();
        manualCar.numberOfGears();;
        manualcar.sunRoof();


    }
}