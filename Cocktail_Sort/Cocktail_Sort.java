
public class Cocktail_Sort { 

	void Cocktail_Sort(int array[]) 
	{ 
        // the starting index of the array is s and ending index is l
		int s = 0, l = array.length; 

        // a flag to check if in an iteration, any swaps were made
        // i.e. if the array was not already sorted
        boolean flag = true; 
	while (flag) { 
			
            	// resetting the flag
		flag = false; 

		// iterate through every element from left to right 
		for (int i = s; i < l - 1; i++) { 

                	// Move the bigger element to the right most position as in bubble sort
			if (array[i] > array[i + 1]) { 
				int t = array[i]; 
				array[i] = array[i + 1]; 
				array[i + 1] = t;

                   		 // setting flag to true if even one element changed its order 
				flag = true;             
				} 
			} 

			// if nothing moved, then array is sorted. 
			if (!flag) 
				break; 

			flag = false; 
			l--; 

			// moving the smaller elements to left part of the array which is modification over bubble sort
			for (int j = l - 1; j > s; j--) { 

				if (array[j-1] > array[j]) { 

					int t = array[j]; 
					array[j] = array[j - 1]; 
					array[j - 1] = t; 
					flag = true; 
                    
				} 
			} 

			s++;
		} 
	} 

	
	// Driver method 
	public static void main(String[] args) 
	{ 
		Cocktail_Sort cs = new Cocktail_Sort(); 
		int array[] = { 10, 1, 5, 2, 4, 0, 2, 8 }; 

        // before sorting the state of the array
		System.out.println("Unsorted array is:"); 

		for (int i = 0; i < array.length; i++) 	
			System.out.print(array[i] + " "); 
		System.out.println("\n"); 


		cs.Cocktail_Sort(array); 

        // after sorting the state of the array
		System.out.println("Sorted array is:"); 


		for (int i = 0; i < array.length; i++) 
			System.out.print(array[i] + " "); 
		System.out.println();  
        
	} 
} 

/*
    OUTPUT :

    Unsorted array is:
    10 1 5 2 4 0 2 8 

    Sorted array is:
    0 1 2 2 4 5 8 10 

*/
