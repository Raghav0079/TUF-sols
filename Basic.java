class Vehicle{

    String numberOfVehicle;
    public Vehicle(String numberOfVehicle){
        this.numberOfVehicle=numberOfVehicle;
    }

    public void honk(){
        System.out.println("honk");

    }

    public void NumberOfVehicle(){
        System.out.println(numberOfCar);
    }
}


class Car extends Vehicle{
    
    public Car(String numberOfCar){
        super(numberOfCar);
    }
    
}

class Bus extends Vehicle{
    public Bus(String numberOfBus){
        super(numberOfBus);
    }
}
class Basic{
    public static void main(String[] args){
        Car car = new Car(numberOfCar:"MP095645");
        car.printCarNumber();
        car.honk();

        Bus bus = new Bus(numberOfBus:"MP085645");
        bus.printBusnumber();
        bus.honk();
    }

}
