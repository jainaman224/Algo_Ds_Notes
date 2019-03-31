// Java program of rainwater trapping problem

class Test 
{ 
	static int a[] = new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	
	// Calculating maximum amount of water 
	static int WaterCalculator(int size) 
	{ 
		// left[i] stores ht of tallest bar to the lf of the i'th bar including itself 
		 
		int left[] = new int[size]; 
	
		// Right [i] stores ht of tallest bars to the rt of ith bar including itself 
		// 
		int right[] = new int[size]; 
	
		
		int waterVolume = 0; 
	
		//  left collected water 
		left[0] = a[0]; 
		for (int i = 1; i < size; i++) 
		left[i] = Math.max(left[i-1], a[i]); 
	
		//  right right collected water
		right[size-1] = a[size-1]; 
		for (int i = size-2; i >= 0; i--) 
		right[i] = Math.max(right[i+1], a[i]); 
	
		// Calculating the collected water element by element 
	 
		for (int i = 0; i < size; i++) 
		waterVolume += Math.min(left[i],right[i]) - a[i]; 
	
		return waterVolume; 
	} 
	
	// Driver method to test the above function 
	public static void main(String[] args) 
	{ 
		
		System.out.println("Maximum collected water  is " + 
										WaterCalculator(a.length)); 
	} 
} 
//output Maximum collected water is 6