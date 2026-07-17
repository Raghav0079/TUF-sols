import java.util.*;

public class Main9 {
    
    public static void main(String[] args) {
        
    }
}

class GenericMethod<T> {
    T value;

    public void setValue(T value){
        this.value = value;
    }

    public T getValue(){
        return value;
    }
}