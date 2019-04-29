//A number is called Automorphic number if and only if its square ends in the same digits as the number itself.

class  Automorphic_Number 
{ 	
    public static void main(String[] args) 
    { 
        int num = 5;
        int square = num * num; 

        // Start Comparing digits 
        while (num > 0)
        { 
            //if any digit of N doesn't 
            // match with its square's digits from last 
            if (num % 10 != square % 10) 
            {
                System.out.println("Not Automorphic");
                return;
            }

            num /= 10; 
            square /= 10;
        }
        System.out.println("Automorphic"); 
    } 
} 

//OUTPUT:Automorphic
