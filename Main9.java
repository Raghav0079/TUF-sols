import java.util.*;

public class Main9 {
    public static void main(String[] args) {
        ExampleGenerics<Integer> obj = new ExampleGenerics<>();
        obj.add(10);
        System.out.println(obj.getElement(0));
        obj.removeLast();
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