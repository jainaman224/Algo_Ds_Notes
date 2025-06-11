import java.util.*;


public class Gcd {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the First number");
        int num1 = sc.nextInt();
        System.out.println("Enter the second number");
        int num2 = sc.nextInt();
        
        int gcd = calculategcd(num1,num2);
        System.out.println("The Greatest Common Divisor of First and Second number is -> " + gcd);
    
    }

    
    //function to calculate the gcd of num1 and num2
    static int calculategcd(int num1,int num2){
        int gcd = 1;
        for(int i = 1;i<=(Math.min(num1,num2));i++){
            if(num1%i==0&&num2%i==0){
                gcd = i;
            }
        }
        return gcd;
    }
}
