import java.util.Scanner;

class RotationCount
{

	static int findRotations(int[] arr)
	{
		/*
		* returns no. of times a sorted array was rotated.
		* e.g., if we had values 5, 6, 1, 2, 3, 4 then, function will return 2
		*/
		int size = arr.length;
		int left = 0, right = size - 1;

		while(left <= right)
		{
			int middle = (right + left)/2;
			int previous = (middle+size-1) % size, next = (middle+1) % size;
			
			// variables previous and next store the array elements before and after the middle element respectively.
			
			if(arr[left] <= arr[right])
				return left;
			
			if(arr[middle] <= arr[next] && arr[middle] <= arr[previous])
				return middle;
			
			if(arr[middle] <= arr[right])
				right = middle - 1;
			
			else if(arr[middle] >= arr[left])
				left = middle + 1;
		}
		return 0;

	}
	
	public static void main(String[] args)
	{

		Scanner scan = new Scanner(System.in);

		System.out.println("Enter size of the array: ");
		int size = scan.nextInt();

		int[] arr = new int[size];

		System.out.println("Enter " + size + " elements: ");
		for(int i = 0; i < size; i++)
			arr[i] = scan.nextInt();

		// Let's assume array to have values 5, 6, 1, 2, 3, 4
		// With 5, 6 being shifted to the start of the array, the function findRotations() will return 2.

		int count = findRotations(arr);

		System.out.println("The array is rotated " + count + " times");

	}

}
