import java.util.*;

public class Main9 {
    
    public static <T> void printArray(T[] arr){
        for(T val : arr){
            System.out.print(val + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Integer[] arr = {1,6,7};
        printArray(arr);
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