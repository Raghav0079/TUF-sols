import java.util.ArrayList;
import java.util.List;

class MemoryLeakExample{
    private  static List<Object> staticList = new ArrayList<>();

    public void addToStaticList(Object obj){
        staticList.add(obj);
    }

}

public class Main{
    public static void main(String[] args) {
        MemoryLeakExample example = new MemoryLeakExample();

        for(int i=0 ; i < 100000 ; i++){
            example.addToStaticList(new Object());

        }

        System.out.println(x:"objects added to static list");

    }
    
}