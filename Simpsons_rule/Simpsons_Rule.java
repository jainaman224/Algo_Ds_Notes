//Simpson's Rule in java
//It is used to calculate numerical approximation of definite integral
//In this rule, number of intervals must be EVEN

import java.util.Scanner;

public class Main {

    //Function to calculate f(x) where f(x) = x * x
    static float func(float x){
        return x * x;
    }
    //Function to calculate approximate integral
    static float simpsons(float lb, float ub, int n){
        float h = (ub - lb) / n;
        float result = 0;
        for (int i = 0; i <= n; i++){
            if(i == 0 || i == n)
                result += func(lb + i * h);
            else if( i % 2 != 0)
                result += 4 * func(lb + i * h);
            else
                result += 2 * func(lb + i * h);
        }
        result = result * (h / 3);
        return result;

    }

    public static void main(String[] args) {
        float lower_limit, upper_limit, output;
        int intervals;
        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter lower limit = ");
        lower_limit = scanner.nextFloat();
        System.out.println("Enter upper limit = ");
        upper_limit = scanner.nextFloat();
        System.out.println("Enter number of intervals = ");
        intervals = scanner.nextInt();
        if(intervals % 2 == 0){
            output = simpsons(lower_limit, upper_limit, intervals);
            System.out.println("Output = "+output);
        }
        else
            System.out.println("Interval must be even.");
    }
}

//output -
//        Enter lower limit =
//        4
//        Enter upper limit =
//        5.2
//        Enter number of intervals =
//        6
//        Output = 25.535994

