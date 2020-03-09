
#include<stdio.h>
#define max 1000 
int res[max]; 
int rs,x,i; 
void multiply(int x) 
{   
    int i,c=0;
    for(i=0; i<rs; i++){ 
        int pro=res[i]*x+c; 
        res[i]=pro%10; 
        c=pro/10;     
    }
    while (c){ 
        res[rs] = c%10; 
        c = c/10; 
        rs++; 
    } 
}
void factorial(int n) 
{     
    res[0] = 1; 
    rs = 1; 
    for (x=2; x<=n; x++) 
    {
        multiply(x);  
    }
    for (i=rs-1; i>=0; i--){ 
	printf("%d",res[i]); 
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Factorial is ");
    factorial(n);  
} 

/* 
Input :

Enter a number: 40

Output:

Factorial is 815915283247897734345611269596115894272000000000

*/
