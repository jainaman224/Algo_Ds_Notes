// C# program to implement Pigeonhole Sort

using System; 
  
class Pigeonhole {

    public static void pigeonhole_sort(int []array, int n) 
    { 
        int min = array[0]; 
        int max = array[0]; 
        int range, i, j, index;  
  
        for(int k = 0; k < n; k++) 
        { 
            if(array[k] > max) 
                max = array[k]; 
            if(array[k] < min) 
                min = array[k]; 
        } 
  
        range = max - min + 1; 
        int[] pighole = new int[range]; 
      
        for(i = 0; i < n; i++) 
            pighole[i] = 0; 
  
        for(i = 0; i < n; i++) 
            pighole[array[i] - min]++; 
  
        index = 0; 
  
        for(j = 0; j < range; j++) 
            while(pighole[j] --> 0) 
                array[index++] = j + min; 
  
    }
  
    static void Main() 
    { 
        int size;
        Console.Write("How many numbers do you want to sort : ");

        size = Convert.ToInt32(Console.ReadLine());  
        int[] array = new int[size];
        Console.Write("\nEnter the numbers : ");
        for (int i = 0; i < size; i++) 
            array[i] = Convert.ToInt32(Console.ReadLine()); 
        pigeonhole_sort(array,array.Length); 
        Console.Write("\nAfter sorting  : ");      
        for(int i = 0 ; i < array.Length ; i++) 
            Console.Write(array[i] + " "); 
    } 
} 

//SAMPLE INPUT AND OUTPUT
/*SAMPLE 1
How many numbers do you want to sort : 7 
Enter the numbers : 
 4
 9 
 3
 9
 4
 7
 5
After sorting : 3 4 4 5 7 9 9 

//SAMPLE 2
How many numbers do you want to sort : 5 
Enter the numbers :
 5 
 1 
 7 
 3 
 2
 After sorting : 1 2 3 5 7
*/
  

