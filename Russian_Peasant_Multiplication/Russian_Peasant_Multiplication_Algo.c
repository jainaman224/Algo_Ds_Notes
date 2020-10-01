//RUSSIAN PEASANT MULTIPLICATION
#include <stdio.h> 
int main()
{
	int num1, num2, result = 0;
	int num3[100] = {0};
    int i=0;    //input numbers
	printf("1st number: ");
	scanf("%d", &num1);
	printf("2nd number: ");
	scanf("%d", &num2);
	    //displaying table format
	puts("Column1  Column2  Column3");
	puts("-----------------------");
	     //do while loop
	do
	{
	printf("%d\t|%d\t|", num1, num2);
	
	if (num1 % 2 == 1)
	{
		printf("+ %d", num2);
		num3[i] = num2;

		result += num3[i];
		i++;
	}
	
	num1 /= 2, num2 *= 2;
	
	printf("\n");
	}
	
	while (num1 != 0);
	  //loop ends
	  //printing final answer
	printf("\nResult: ");
	
	for (i -= 1; i >= 0; i--)
	{
		printf("%d", num3[i]);
		if (i > 0)
			printf(" + ");
		else
			printf(" = ");
	}
	printf("%d\n", result);
	
	return 0;
}
//end of program
/*       
		INPUT AND OUTPUT
			1st number: 36
			2nd number: 52
			Column1  Column2  Column3
			-----------------------
			36      |52     |
			18      |104    |
			9       |208    |+ 208
			4       |416    |
			2       |832    |
			1       |1664   |+ 1664
			
			Result: 1664 + 208 = 1872
*/
