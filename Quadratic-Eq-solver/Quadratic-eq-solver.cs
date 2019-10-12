using System;

namespace if_else_strong
{
    class Program
    {
        static void Main(string[] args)
        {
            // Using if-elseif-else statement to create a Quadratic Equation Solver
            double a, b, c, root1, root2, D, img;
            Console.Write("Enter the coefficient of x^2 : ");
            
            //             Taking the first coefficient
            a = Convert.ToDouble(Console.ReadLine());
            
            Console.Write("Enter the coefficient of x : ");
            
            //             Taking the Second coefficient
            b = Convert.ToDouble(Console.ReadLine());
            
            Console.Write("Enter the c : ");
            
            //             Taking the Third coefficient
            c = Convert.ToDouble(Console.ReadLine());

//             Calculating the Discriminent
            D = b * b - (4 * a * c);
            
//             Checking the case of Quadratic Equation using Discriminent

            if(D == 0)
            {
//                 Calculating roots if D is 0
                root1 = root2 = -b / (2 * a);
                Console.WriteLine("The two roots are " + root1 + " and " + root2);
            }
            else if(D > 0)
            {
//                 Calculating root if D is greater then 0
                root1 = (-b + Math.Sqrt(D)) / (2 * a);
                root2 = (-b - Math.Sqrt(D)) / (2 * a);
                Console.WriteLine("The two roots are " + root1 + " and " + root2);
            }
            else
            {
//                 Calculating root if D is less then 0
                root1 = root2 = -b / (2 * a);
                img = Math.Sqrt(-D) / (2 * a);
                Console.WriteLine("The two roots are " + root1 + " and " + root2);
                Console.WriteLine("The imaginary part is " + img);
            }

        }
    }
}




// ---------------------------Output----------------------------

// Enter the coefficient of x^2 : 3
// Enter the coefficient of x : 6
// Enter the c : -6
// The two roots are 0.732050807568877 and -2.73205080756888
