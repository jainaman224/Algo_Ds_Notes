// Regula Falsi method in java
import java.util.Scanner;

import static java.lang.StrictMath.abs;

public class Main {
    // Function to calculate f(x) where f(x) = x^3 - 2x - 5
    static double f(float x) {
        return (x * x * x - 2 * x - 5);
    }
    // Function to find root of f(x)
    private static void regulaFalsi(float x1, float x2) {
        if (f(x1) * f(x2) >= 0) {
            System.out.println("You have assumed incorrect x1 and x2");
            return;
        }
        float x3 = x1;
        do {
            x3 = (float)(x1 - (x2 - x1) / (f(x2) - f(x1)) * f(x1));
            if (f(x3) * f(x1) < 0)
                x2 = x3;
            else
                x1 = x3;
        } while (abs(f(x3)) > 0.001);
        System.out.println("Value of root is " + x3);
    }

    public static void main(String[] args) {
        float x1, x2;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter x1 = ");
        x1 = scanner.nextFloat();
        System.out.println("Enter x2 = ");
        x2 = scanner.nextFloat();
        regulaFalsi(x1, x2);
    }
}

// Output -
// Enter x1 =
// 2
// Enter x2 =
// 3
// Value of root is 2.0945182
