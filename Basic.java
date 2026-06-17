
class Test{
    int age ;
    public void assignAge(int num){
        age =num ;
    }
}

class Basic{
    public static void main(String[] args){
        Test test1 = new Test();
        test1.assignAge(num:10);


        Test test2 = new Test();
        test2.assignAge(num:19);

        System.out.println(test1.age);
        System.out.println(test2.age);
    }
}