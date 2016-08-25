import java.util.*;
import java.lang.*;
import java.io.*;

class activity_selection
{
	static void activities(int s[],int f[],int n)
	{
		int i,j;
		i=0;
		System.out.print(i + " ");
		for(j=1;j<n;j++)
		{
			if(s[j] >= f[i])
			{
				System.out.print(j+" ");
				i = j;
			}
		}
	}
	public static void main(String args[])
	{
		int s[] = {1, 3, 1, 5, 8, 6};
		int f[] = {2, 6, 6, 7, 10, 8};
		int n = s.length;
		activities(s,f,n);	
	}
}