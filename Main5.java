
class OuterClass{
    static int  val = 10;
    String name = "OuterClass";

    static class InnerClass{
        public void execute(){
            System.out.println(x:"inner class executed");
        }
    }
    public void execute(){
        InnerClass innerClass = new InnerClass();
        InnerClass.execute();

    }
}

public class Main5{
    public static void main(String[] args) {
        OuterClass outerClass = new OuterClass();
        innerClass.execute();
    }
}
