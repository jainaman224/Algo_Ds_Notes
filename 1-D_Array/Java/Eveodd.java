import java.util.*;
class Eveodd
{
 public static void main(String args[])
 {
  int o=0,e=0,i,n;
  Scanner sc=new Scanner(System.in);
  System.out.print("Enter number of elemnts in array:");
  n=sc.nextInt();
  int arr[]= new int[n];
  System.out.print("Enter elements:");
  for(i=0;i<n;i++)
   {
    arr[i]=sc.nextInt();
   }
  System.out.println("Even numbers of the array are:");
  for(i=0;i<n;i++)
   {
    if((arr[i]%2)==0)
     {
      e++;
      System.out.println(arr[i]+" ");
     }
    }
  System.out.println("Odd numbers of the array are:");
  for(i=0;i<n;i++)
   {
    if((arr[i]%2)!=0)
     {
      o++;
      System.out.println(arr[i]+" ");
     }
    }
  System.out.println("Number of even terms in the array is:" +e+ "\nAnd number of odd terms is:" +o);
 }
}
