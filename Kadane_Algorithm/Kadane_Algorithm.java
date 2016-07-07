
public class kadane_Algorithm 
{
	public static int kadane(int input[], int n) // Function implementing Kadane's Algorithm (array contains at least one positive number)
	{
		int current_max = 0;
		int max_so_far = 0;
		
		for(int i = 0; i < n; i++)
		{
			current_max = Math.max(0, current_max + input[i]);
			max_so_far = Math.max(max_so_far, current_max);
		}

		return max_so_far; // Maximum subarray sum
	}


	public static void main(String[] args) 
	{
		int n, max_subarray_sum;
		int input[] = { -2, 1, -6, 4, -1, 2, 1, -5, 4 }; // Input array
		n = input.length; // Size of array

		int flag = 0; // Flag variable to check if all the numbers in array are negative or not
		int largest_in_negative = input[0]; // Smallest_negative variable will store the maximum subarray sum if all the numbers are negative in array

		for(int i = 0; i < n; i++) // Scanning each element in array
		{
			if(input[i] >= 0) // If any element is positive, kadane's algo can be applied
			{
				flag = 1;
				break;
			}

			else if(input[i] > largest_in_negative) // If all the elements are negative, find the largest in them
				largest_in_negative = input[i];
		}

		if(flag == 1) // Kadane's algo applicable
		     max_subarray_sum = kadane(input, n);
		else
		     max_subarray_sum = largest_in_negative; // Kadane 's algo not applicable,
	  // Hence the max_subarray_sum will be the largest number in array itself
		System.out.println("Maximum Subarray Sum is " + max_subarray_sum);
	}
	
}

/*
output : Maximum Subarray Sum is 6
*/
	

