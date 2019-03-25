
#include<stdio.h>
#include<conio.h>
#include<math.h>
/* function for polynomial x*x - x -1 */
float f(float number)
{
   return number*number - number -1 ;
}
void main()
{
   int iteration_no;
   float first_no,second_no,middle,error=0.0001;
   clrscr();
   printf("Enter value of a: ");
   scanf("%f",&first_no); 
   printf("Enter value of b: ");
   scanf("%f",&second_no); 
   if(f(first_no)*f(second_no) > 0)
   {
     printf("Invalid interval"); }
   else{
     middle = (first_no+second_no)/2;
     iteration_no=1;
     while(fabs(f(middle))>error)
     {
       printf("\niteration_no =%d,first_no=%f,second_no=%f,middle=%f,f(middle)=%f,f(first_no)*f(middle)=%f",iteration_no,first_no,second_no,middle,f(middle),f(first_no)*f(middle));
       if(f(first_no)*f(middle) > 0)
	  first_no=middle;
       else
	  second_no=middle;
       middle=(first_no+second_no)/2;
       iteration_no++;
     }
     printf("\niteration_no =%d,first_no=%f,second_no=%f,middle=%f,f(middle)=%f,f(first_no)*f(middle)=%f",iteration_no,first_no,second_no,middle,f(middle),f(first_no)*f(middle));
     printf("\nroot = %f",middle);
   }
   getch();
}

/*
input = 2 3
output = Invalid interval
input = 1 2
output = 

iteration_no =1,first_no=1.000000,second_no=2.000000,middle=1.500000,f(middle)=-0.250000,f(first_no)*f(middle)=0.250000
iteration_no =2,first_no=1.500000,second_no=2.000000,middle=1.750000,f(middle)=0.312500,f(first_no)*f(middle)=-0.078125
iteration_no =3,first_no=1.500000,second_no=1.750000,middle=1.625000,f(middle)=0.015625,f(first_no)*f(middle)=-0.003906
iteration_no =4,first_no=1.500000,second_no=1.625000,middle=1.562500,f(middle)=-0.121094,f(first_no)*f(middle)=0.030273
iteration_no =5,first_no=1.562500,second_no=1.625000,middle=1.593750,f(middle)=-0.053711,f(first_no)*f(middle)=0.006504
iteration_no =6,first_no=1.593750,second_no=1.625000,middle=1.609375,f(middle)=-0.019287,f(first_no)*f(middle)=0.001036
iteration_no =7,first_no=1.609375,second_no=1.625000,middle=1.617188,f(middle)=-0.001892,f(first_no)*f(middle)=0.000036
iteration_no =8,first_no=1.617188,second_no=1.625000,middle=1.621094,f(middle)=0.006851,f(first_no)*f(middle)=-0.000013
iteration_no =9,first_no=1.617188,second_no=1.621094,middle=1.619141,f(middle)=0.002476,f(first_no)*f(middle)=-0.000005
iteration_no =10,first_no=1.617188,second_no=1.619141,middle=1.618164,f(middle)=0.000291,f(first_no)*f(middle)=-0.000001
iteration_no =11,first_no=1.617188,second_no=1.618164,middle=1.617676,f(middle)=-0.000801,f(first_no)*f(middle)=0.000002
iteration_no =12,first_no=1.617676,second_no=1.618164,middle=1.617920,f(middle)=-0.000255,f(first_no)*f(middle)=0.000000
iteration_no =13,first_no=1.617920,second_no=1.618164,middle=1.618042,f(middle)=0.000018,f(first_no)*f(middle)=-0.000000
root = 1.618042


*/
