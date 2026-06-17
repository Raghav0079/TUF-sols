import java.util.Scanner;

class Test{
    public static void printTest(){
        System.out.println("hello");
    }
}

class Basic{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Test test = new Test();
        test.printTest();
    }
}