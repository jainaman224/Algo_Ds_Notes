import java.util.*; 

public class Extended_Euclidean_Algorithm
{ 
    // extended Euclidean Algorithm 
    public static int getGCD(int a, int b, int x, int y) 
    { 
        // Base Case 
        if (a == 0) 
        { 
            x = 0; 
            y = 1; 
            return b; 
        } 
  
        int x1 = 1, y1 = 1; // To store results of recursive call 
        int gcd = getGCD(b % a, a, x1, y1); 
  
        // Update x and y after recursive call
        x = y1 - (b / a) * x1; 
        y = x1; 
  
        return gcd; 
    } 
  
// Main function
    public static void main(String[] args) 
    { 
        int x = 1, y = 1; 
        Scanner s = new Scanner(System.in);
        int a = s.nextInt(); 
        int b = s.nextInt();
        int g = getGCD(a, b, x, y);
        System.out.print("GCD of " + a + " , " + b + " = " + g);
   } 
}



/*
   INPUT
   a = 35, b = 15; 

   Output: 
   GCD of 35 , 15 = 5
*/
