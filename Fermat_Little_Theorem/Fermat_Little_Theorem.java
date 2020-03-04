public class Fermat_Little_Theorem {
    public static void main(String[] args) {
        findModInverse(3,11);
    }
    public static void findModInverse(int x, int n){
        if(recursiveGCD(x,n)!=1){
            System.out.println("inverse does not exist! returning...");
            return;
        }
        else{
            System.out.println("Modular Multiplicative inverse is..."+ fastModuloExponentiation(x,n-2,n));
        }


    }
    public static int recursiveGCD(int a, int b){
        return a==0 ? b:recursiveGCD(b%a,a);
    }

    public static long fastModuloExponentiation(int number, int power, int modulus){
        if(power==0)
            return 1;
        if(power==1)
            return number;
        long sub_number = fastModuloExponentiation(number,power/2,modulus)%modulus;
        if(power%2==0)
            return (sub_number*sub_number)%modulus;
        else
            return ((sub_number*sub_number)%modulus * number%modulus)%modulus;
    }
}
