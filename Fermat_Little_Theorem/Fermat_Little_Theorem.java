import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
x^(n-1) cong== 1modn
where x and n are coprime (gcd is 1)
multiplying by x inverse on both sides
x inverse = x^(n-2) mod n which is found using fast modular exponentiation
 */
public class Fermat_Little_Theorem {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x;
        int n;
        System.out.println("Enter space separated coprime numbers x and n");
        String input[] = br.readLine().split(" ");
        x = Integer.parseInt(input[0]);
        n = Integer.parseInt(input[1]);
        findModInverse(x,n);
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

/*
input :
3 11
output :
Modular Multiplicative inverse is...4
 */