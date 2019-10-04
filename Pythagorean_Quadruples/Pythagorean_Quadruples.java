/*
PYTHAGOREAN QUADRUPLES

Four numbers - a, b , c and d are said to be pythagorean quadruples if following
formula holds :

a^2 + b^2 + c^2 = d^2
*/

import java.util.Scanner;

class Pythagorean_Quadruples {

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int a, b, c, d;
        System.out.print("Enter a: ");
        a = s.nextInt();
        System.out.print("Enter b: ");
        b = s.nextInt();
        System.out.print("Enter c: ");
        c = s.nextInt();
        System.out.print("Enter d: ");
        d = s.nextInt();
        int sq_a = a * a;
        int sq_b = b * b;
        int sq_c = c * c;
        int sq_d = d * d;
        if (sq_a + sq_b + sq_d == sq_c || sq_a + sq_c + sq_d == sq_b 
        || sq_b + sq_c + sq_d == sq_a || sq_a + sq_b + sq_c == sq_d) {
            System.out.print("It is a pythagorean quadruple");
        }
        else {
            System.out.print("It is not a pythagorean quadruple");
        }
    }
}

/*
    INPUT : a = 3 b = 6 c = 2 d = 7
    OUTPUT: It is a pythagorean quadruple
    VERIFICATION : 3^2 + 6^2 + 2^2 = 9 + 36 + 4 = 49
                   7^2 = 49
*/
