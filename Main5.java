
class OuterClass{
    static int  val = 10;
    String name = "OuterClass";

    public void execute(){
        final int x = 10;

        class InnerClass(){
            public void execute(){
                System.out.println(x : "inner class executed" + name);
            }
        }
        

        InnerClass innerClass = new InnerClass();
        InnerClass.execute();
    }

}

public class Main5{
    public static void main(String[] args) {
        OuterClass.InnerClass innerClass = new OuterClass().new InnerClass();
        innerClass.execute();
    }
}
