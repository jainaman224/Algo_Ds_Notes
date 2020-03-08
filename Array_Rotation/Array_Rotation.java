//Program to rotate array Arr[] of size n by d Elements to either left or right
import  java.util.Scanner;
class Array_Rotation
{
    private static void leftRotate(int arr[], int n) 
    { 
        int temp = arr[0], i; 
        // shifting all the elements of the array to left
        for (i = 0; i < n - 1; i++) 
            arr[i] = arr[i + 1]; 

        arr[i] = temp; 
    } 
    
    private static void rightRotate(int arr[], int n)
    {
        int temp = arr[n-1], i;
        // shifting all the elements of the array to right
        for (i = n-1; i > 0; i--)
            arr[i] = arr[i - 1];
        
        arr[0] = temp;
    }
    private static void RotateArrayLeft(int arr[], int rotations, int n) 
    { 
        // call for rotation one by one
        for (int i = 0; i < rotations; i++) 
            leftRotate(arr, n); 

        // print the array
        for (int i = 0; i < n; i++) 
            System.out.print(arr[i] + " ");    
    } 
    private static void RotateArrayRight(int arr[], int rotations, int n) 
    { 
        // call for rotation one by one
        for (int i = 0; i < rotations; i++) 
            rightRotate(arr, n); 

        // print the array
        for (int i = 0; i < n; i++) 
            System.out.print(arr[i] + " ");    
    } 

    public static void main(String args[]) 
    { 
        // Sample input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements in array");
        int n=sc.nextInt();
        System.out.println("Enter "+ n +" elements");
        //declare an array that has n elements in it
        int a[] = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        System.out.println("Enter number of rotations");
        int d = sc.nextInt();
        System.out.println("To rotate left press 1,\nTo rotate right press 2");
        int choice = sc.nextInt();
        
        switch(choice)
        {
            case 1:
                {
                    RotateArrayLeft(a, d, n);
                    break;
                }
            case 2:
                {
                    RotateArrayRight(a, d, n);
                    break;
                }
            default:
                {
                    System.out.println("Enter correct choice(1 / 2");
                    break;
                }
        }
            
    } 
}
/*
INPUT
Enter number of elements in array                                                                                                               
5                                                                                                                                               
Enter 5 elements                                                                                                                                
1                                                                                                                                               
2                                                                                                                                               
3                                                                                                                                               
4                                                                                                                                               
5                                                                                                                                               
Enter number of rotations                                                                                                                       
2                                                                                                                                               
To rotate left press 1,                                                                                                                         
To rotate right press 2                                                                                                                         
1   
OUTPUT
3 4 5 1 2 
*/
