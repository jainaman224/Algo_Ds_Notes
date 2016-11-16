import java.util.*;
import java.lang.*;
import java.io.*;

class activity_selection
{
	public static void activities(int start[], int finish[], int n)
	{
		int i = 0, j;
		System.out.print((i + 1) + " ");
		for (j = 1; j < n; j++)
		{
			if (start[j] >= finish[i])
			{
				System.out.print((j + 1) + " ");
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

// Output
// 1 2 5
