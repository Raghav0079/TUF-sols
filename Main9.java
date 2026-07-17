import java.util.*;

public class Main9 {
    
    public static <T> void printArray(T[] arr){
        for(T val : arr){
            System.out.print(val + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Calculator<Integer> obj = new Calculator<Integer>();
        System.out.println(obj.add(1, 2));
        System.out.println(obj.add(1, 2));
    }
}

class GenericMethod {
    public <T> void printArray(T[] arr){
        for ( T val : arr){
            System.out.print(val + " ");
        }
    }
}

class Calculator<T extends Number> {
    public double add(T a , T b){
        return a.doubleValue() + b.doubleValue();
    }
}

class ExampleGenerics<T> {
    private List<T> list = new ArrayList<>();

    public void add(T val) {
        list.add(val);
    }

    public void removeLast() {
        if (list.isEmpty()) {
            System.out.println("list is empty");
            return;
        }
        list.remove(list.size() - 1);
    }

    public T getElement(int index) {
        return list.get(index);
    }
}