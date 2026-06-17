
class Test{
    int age ;
    public void assignAge(int num1, int num2){
        return num1 + num2 ;
    }
}

class Basic{
    private static int sum(){
        return 10;
    }
    public static void main(String[] args){
        Test test = Test();
        System.out.println(test.sum(num1:10 , num2:20));
    }
}