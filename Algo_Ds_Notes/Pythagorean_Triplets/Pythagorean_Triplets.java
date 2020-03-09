/*
PYTHAGOREAN TRIPLETS

Three numbers - a, b and c are said to be pythagorean triplets if following
formula holds :

a^2 + b^2 = c^2
*/

import java.util.Scanner;

class Pythagorean_Triplets {

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int a, b, c;
        System.out.print("Enter a: ");
        a = s.nextInt();
        System.out.print("Enter b: ");
        b = s.nextInt();
        System.out.print("Enter c: ");
        c = s.nextInt();
        int sq_a = a * a;
        int sq_b = b * b;
        int sq_c = c * c;
        if (sq_a + sq_b == sq_c || sq_a + sq_c == sq_b || sq_b + sq_c == sq_a) {
            System.out.print("It is a pythagorean triplet");
        }
        else {
            System.out.print("It is not a pythagorean triplet");
        }
    }
}

/*
    INPUT : a = 8 b = 6 c = 10
    OUTPUT: It is a pythagorean triplet
    VERIFICATION : 6^2 + 8^2 = 36 + 64 = 100
                   10^2 = 100
*/
