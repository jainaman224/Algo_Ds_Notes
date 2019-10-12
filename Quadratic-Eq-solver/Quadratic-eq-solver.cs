using System;

namespace if_else_strong
{
    class Program
    {
        static void Main(string[] args)
        {
            // Using if-elseif-else statement to create a complex program
            double a, b, c, root1, root2, D, img;
            Console.Write("Enter the coefficient of x^2 : ");
            a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter the coefficient of x : ");
            b = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter the c : ");
            c = Convert.ToDouble(Console.ReadLine());

            D = b * b - (4 * a * c);

            if(D == 0)
            {
                root1 = root2 = -b / (2 * a);
                Console.WriteLine("The two roots are " + root1 + " and " + root2);
            }
            else if(D > 0)
            {
                root1 = (-b + Math.Sqrt(D)) / (2 * a);
                root2 = (-b - Math.Sqrt(D)) / (2 * a);
                Console.WriteLine("The two roots are " + root1 + " and " + root2);
            }
            else
            {
                root1 = root2 = -b / (2 * a);
                img = Math.Sqrt(-D) / (2 * a);
                Console.WriteLine("The two roots are " + root1 + " and " + root2);
                Console.WriteLine("The imaginary part is " + img);
            }

        }
    }
}
