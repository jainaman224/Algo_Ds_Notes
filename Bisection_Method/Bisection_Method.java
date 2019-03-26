//java program to find roots of equation using bisection method

public class BisectionMethod 
{
	//value for accuracy of root. more smaller it is more accurate will be root

	static final float  err= 0.01f; 

	// the equation whose roots are to be determined. in this case it is x^3-x^2+2
    static double function(double x) 
    { 
        return x*x*x - x*x + 2; 
    } 
  
    // function to find root with error of err
    static void bisection(double start, double end) 
    { 
    	// check if root does not lies in range (start,end)
        if (function(start) * function(end) >= 0) 
        { 
            System.out.println("You have not assumed"
                        + " right start and end"); 
            return; 
        } 
  
        double mid=0; 
        while ((end-start) >= err) 
        { 
            // finding mid point 
            mid = (start+end)/2; 
  
            // check if mid is root 
            if (function(mid) == 0.0) 
                break; 
  
            // to check te side where root lies.
            else if (function(mid)*function(start) < 0) 
                end = mid;
            else
                start = mid; 
        } 
        //prints mid upto 4 digits of precision
        System.out.printf("The value of root for above equation is : %.4f"
                        ,mid); 
    } 
  
    // main program for finding roots 
    public static void main(String[] args) 
    { 
        //  values assumed for start and end
        double start =-500, end = 500; 
        bisection(start, end); 
    } 
    // This code is contributed by Pankaj Poply
} 

//OUTPUT
//
//The value of root for above equation is : -0.9995
