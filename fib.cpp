#include<iostream>
int main(){
    int a[60],n,i,c,b[60],j;
    a[0]=0;
    a[1]=1;
    b[0]=0;
    b[1]=1;
    for(i=2;i<60;i++){
        a[i]=(a[i-1]+a[i-2])%10;
        c=a[i];
        b[i]=(c*c)%10;
    }
    std::cout<<"Please enter the position Fibonacci number: ";
    std::cin>>n;
    std::cout<<"\nThe Last digit of square of this position : "<<b[n%60];
    return 0;
}