import java.util.* ;

abstract class Car{
    abstract public void start();
    public void noise(){
        System.out.println(x: "Noise....")
    }
}


class ManualCar extends Car{
    public void start(){
        System.out.println(x:"Manual car is starting");
    }
    public void printName(){
        System.out.println(x:"Hey I am manual");
    }
}
public class Main3{

    public static void main(String[] args) {
        Car manualCar = new ManualCar();
        manualCar.start();
        manualCar.noise();

    }

}