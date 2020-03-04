import java.util.Scanner;
public class Pascal_Triangle{

    public static void pascalTriangleGenerator(int n){
        
        for(int i = 1; i <= n; i++){ 
          
            int count=1;// used to represent C(line, i) 
            for(int j = 1; j <= i; j++) {  
            // The first value in a line is always 1 
                System.out.print(count +" "); 
                count = count * (i - j) / j;  
            } 
            System.out.println(" "); 
        } 
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value to generate Pascal Traingle: ");
        int val = sc.nextInt();
        pascalTriangleGenerator(val);
    }

}

// Basic Input and Output Operations.
/**
 * Enter the value to generate Pascal Traingle: 5
 * 
 *  1  
    1 1  
    1 2 1  
    1 3 3 1  
    1 4 6 4 1  
 * 
 */