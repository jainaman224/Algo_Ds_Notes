using System;
using System.Linq;


public class Test
{
	public static void Main()
	{
		// your code goes here
		int[,] firstMatrix = new int[2, 2];
		int[,] secondMatrix = new int[2, 2];
		int[,] productMatrix= new int[2, 2];
		
		Console.Write("Enter the 4 elements of first matrix: ");
		
		for(int i=0;i<2;i++){
		    var numList= new string[2];
		    numList=Console.ReadLine().Split();
		    for(int j=0;j<2;j++){
	        	firstMatrix[i, j] = Convert.ToInt32(numList[j]); 
	        	}
	    	 }
	    
	    	Console.Write("Enter the 4 elements of second matrix: ");
	    
	   	 for(int i=0;i<2;i++){
	         	var numList= new string[2];
		    	numList=Console.ReadLine().Split();
	         	for(int j=0;j<2;j++){
	         		secondMatrix[i, j] = Convert.ToInt32(numList[j]);
	        	}
	    	  }
	    
	    int a= (firstMatrix[0, 0] + firstMatrix[1, 1]) * (secondMatrix[0, 0] + secondMatrix[1, 1]);
	    int b= (firstMatrix[1, 0] + firstMatrix[1, 1]) * secondMatrix[0, 0];
	    int c= firstMatrix[0, 0] * (secondMatrix[0, 1] - secondMatrix[1, 1]);
	    int d= firstMatrix[1, 1] * (secondMatrix[1, 0] - secondMatrix[0, 0]);
	    int e= (firstMatrix[0, 0] + firstMatrix[0, 1]) * secondMatrix[1, 1];
	    int f= (firstMatrix[1, 0] - firstMatrix[0, 0]) * (secondMatrix[0, 0]+secondMatrix[0, 1]);
	    int g= (firstMatrix[0, 1] - firstMatrix[1, 1]) * (secondMatrix[1, 0]+secondMatrix[1, 1]);
	    
	    productMatrix[0, 0] = a + d- e + g;
	    productMatrix[0, 1] = c + e;
	    productMatrix[1, 0] = b + d;
      	    productMatrix[1, 1] = a - b + c + f;
      	
      	    Console.Write("Resultant matrix: \n");
      	
      	    for(int i=0; i<2;i++){
      	    	for(int j=0;j<2;j++){
      	        	Console.Write(productMatrix[i, j]+" ");
      	    	}
      	    	Console.Write("\n");
      	     }
	}
}

/** 
Enter the 4 elements of first matrix:
5 6
1 7
Enter the 4 elements of second matrix:
6 2
8 7
Resultant matrix:  
78 52
62 51
*/
