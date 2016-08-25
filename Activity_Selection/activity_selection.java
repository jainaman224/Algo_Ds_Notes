import java.util.*;
import java.lang.*;
import java.io.*;

class activity_selection
{
	static void activities(int start[],int finish[],int n)
	{
		int i,j;
		i = 0;
		System.out.print(i + " ");
		for(j = 1 ; j < n ; j++)
		{
			if (start[j] >= finish[i])
			{
				System.out.print(j+" ");
				i = j;
			}
		}
	}
	public static void main(String args[])
	{
		int start[] = {1, 3, 1, 5, 8, 6};
		int finish[] = {2, 6, 6, 7, 10, 8};
		int n = start.length;
		activities(start, finish, n);	
	}
}
//Output: 0 1 4