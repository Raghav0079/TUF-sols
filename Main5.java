
class OuterClass{
    static int  val = 10;
    String name = "OuterClass";

    static class InnerClass{
        public void execute(){
            System.out.println(x:"inner class executed");
        }
    }
}

public class Main5{
    public static void main(String[] args) {
        OuterClass.InnerClass innerClass = new OuterClass.InnerClass();
        innerClass.execute();
    }
}
