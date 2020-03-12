using System; 
  
class GFG { 
      
    static void cocktailSort(int[] b) 
    { 
        bool swapped = true; 
        int start = 0; 
        int end = b.Length; 
  
        while (swapped == true)
    { 
              
           swapped = false; 
  
             
          
            for (int i = start; i < end - 1; ++i) { 
                if (b[i] > b[i + 1]) { 
                    int temp = b[i]; 
                    b[i] = b[i + 1]; 
                    b[i + 1] = temp; 
                    swapped = true; 
          } 
     } 
  
             if (swapped == false) 
                break; 
  
             swapped = false; 
             end = end - 1; 
  
            for (int i = end - 1; i >= start; i--) { 
                if (b[i] > b[i + 1]) { 
                    int temp = b[i]; 
                    b[i] = b[i + 1]; 
                    b[i + 1] = temp; 
                    swapped = true; 
                } 
            } 
  
            
            start = start + 1; 
        } 
    } 
  
   static void printArray(int[] b) 
    { 
        int n = b.Length; 
        for (int i = 0; i < n; i++) 
            Console.Write(b[i] + " "); 
        Console.WriteLine(); 
    } 
  
    public static void Main() 
    { 
        int[] b = { 5, 1, 4, 2, 8, 0, 2 }; 
        cocktailSort(b); 
        Console.WriteLine("Sorted array "); 
        printArray(b); 
    } 
} 
  

