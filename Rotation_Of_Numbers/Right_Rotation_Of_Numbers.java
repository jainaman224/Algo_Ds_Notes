public class RightRotationOfNumber {
		//Driver code
	   public static void main(String args[]) {
		   
		   Scanner obj=new Scanner(System.in);
		   int num=obj.nextInt();
		   Right_Rotation(num);
		     
		   }
	   	//Right_Rotation method to rotate the number
	public static void Right_Rotation(int num) 
	{
		//Convert the number to string
		String number=String.valueOf(num);
		//Find the length of the number to run the loop
		int len=number.length();
		//Loop runs 1 less the length of the number.
		for(int i=1;i<len;i++)
		{
			//Main rule to rotate the number
			//eg:-old number 12345 ---> how the number splits(2345 + 1) 
			//new number=23451 
			number=number.substring(1,len)+number.substring(0,1);
			//convert the string to an integer and then print
			System.out.print(Integer.valueOf(number) + " ");
		}
		
	}
	   
	   }

/*
Input:
1234
Output:
2341 3412 4123 
*/
