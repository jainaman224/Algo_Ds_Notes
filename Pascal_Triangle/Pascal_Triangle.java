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
        int val = sc.nextInt();
        pascalTriangleGenerator(val);
    }

}