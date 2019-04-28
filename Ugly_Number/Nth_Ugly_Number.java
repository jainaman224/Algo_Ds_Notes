// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

class Ugly{
	
    /* Function to check if a number is ugly or not */
    public static boolean isUgly(int num) { 
        boolean x = true;
        while (num != 1) {  
            // To check if number is divisible by 5 or not
            if (num % 5 == 0) {  
                num /= 5;  
            } 
            // To check if number is divisible by 3 or not
            else if (num % 3 == 0) {  
                num /= 3;  
            }
            // To check if number is divisible by 2 or not
            else if (num % 2 == 0) {  
                num /= 2;  
            } 
            else {  
                x = false;  
                break;  
            }  
        }
        return x; 
    }     

    /* Function to get the nth ugly number*/
    public static int NthUglyNumber(int n) { 
        int i = 1;  
        int count = 1;   /* ugly number count */ 
        /* Check for all integers untill ugly count  becomes n*/ 
        while (n > count) { 
            i++;       
            if ( isUgly(i) ) {
                count++;  
            }
        } 
        return i; 
    } 

    public static void main(String args[]) { 
        int number = 100;
        int no = NthUglyNumber(number); 
        System.out.println("The Ugly no. at position " + number + " is " + no );
    }
}

/*
Input : number: 100
Output : The Ugly no. at position 100 is 1536
*/
