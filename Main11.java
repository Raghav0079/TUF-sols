import java.util.ArrayList;
import java.util.List;

class MemoryLeakExample {
    private List<Object> list = new ArrayList<>();

    public void addToList(Object obj) {
        list.add(obj);
    }

    public void clearList() {
        list.clear();
    }
}

public class Main11 {
    public static void main(String[] args) {
        MemoryLeakExample example = new MemoryLeakExample();

        for (int i = 0; i < 100000; i++) {
            example.addToList(new Object());
        }

        System.out.println("objects added to list");
        example.clearList();
    }
}