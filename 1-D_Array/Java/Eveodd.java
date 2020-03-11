import java.util.* ;
class Eveodd
{
    public static void main(String args[])
    {
        int o = 0,e = 0,i ,n;
        Scanner sc = new Scanner(System.in);
        //take input for the array size
        System.out.print("Enter number of elemnts in array:");
        n = sc.nextInt();
        //declare array of size n
        int arr[] = new int[n];
        System.out.print("Enter elements:");
        //take input for array elements
        for(i = 0;i < n;i ++ )
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("Even numbers of the array are:");
        for(i = 0;i < n;i ++ )
        {    
            //numbers divisible by 2 are even.
            if((arr[i] % 2) == 0)
            {
                e ++ ;
                System.out.println(arr[i] + " ");
            }
        }
        System.out.println("Odd numbers of the array are:");
        for(i = 0;i < n;i ++)
        {
            //numbers which are not divisible by 2 are odd.
            if((arr[i] % 2) != 0)
            {
                o++ ;
                System.out.println(arr[i] + " ");
            }
        }
        System.out.println("Number of even terms in the array is:" + e +  "\nAnd number of odd terms is:" +o);
    }
}
//sample output:
/*Enter number of elemnts in array:6
Enter elements:1 34 0 47 134 9
Even numbers of the array are:
34 
0 
134 
Odd numbers of the array are:
1 
47 
9 
Number of even terms in the array is:3
And number of odd terms is:3
/
