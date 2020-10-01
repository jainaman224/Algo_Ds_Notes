//Java program to approximate number of people in Birthday Paradox problem
class Birthday_Paradox 
{

    static double find(double p) // Returns approximate number of people for a given probability
    {
        return Math.ceil(Math.sqrt(2*365*Math.log(1/(1-p))));
    }

    public static void main(String[] args)
    {
        System.out.println(find(0.70));
    }
}

/* Output
30.0
*/
