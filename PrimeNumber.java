import java.util.Scanner;
class PrimeNumber{
    public static boolean isPrime(int num){
        for(int i=2;i<=Math.sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    public static void main(String args[]){
        System.out.println("Enter two numbers");
        Scanner myObj = new Scanner(System.in);
        int a = myObj.nextInt();
        int b = myObj.nextInt();
        for(int i=a;i<=b;i++){
            if(isPrime(i)){
                System.out.println(i+" ");
            }
        }
    }
}