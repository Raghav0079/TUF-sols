
class Test{
    public Test(){
        System.out.println("test constructor");
    }
    public void printHello(){
        System.out.println("hello");
    }
}
    

class Basic{
   public static void main(String[] args) {
       Test test = new Test();
       test.printHello();
   }
}