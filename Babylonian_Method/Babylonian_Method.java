/* Babylonian method for square root
  1. Start with an arbitrary positive start value x (the closer to the 
     root, the better).
  2. Initialize y = 1.
  3. Do following until desired approximation is achieved.
      a) Get the next approximation for root using average of x and y
      b) Set y = n/x */
      
class Babylonian{
    public static double squareRoot(double num) {    
        double number = num; 
        double guess = 1; 
        double accuracy = 0.000001; /* it decides the accuracy level*/
        while (number - guess > accuracy)
        { 
            number = (number + guess) / 2; 
            guess = num / number; // to get next approximation 
        } 
        return number; 
    } 
  
    public static void main(String args[]) 
    { 
        int num = 2;
        System.out.printf("Square root of " + num + " is %.6f" , squareRoot(num));    
    }
}
/*Enter a number :
2
Square root of 2 is 1.414214 */
