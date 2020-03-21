#include<stdio.h>
#include<conio.h>
#inlcude<string.h>

int main(){
    char str[100];
    int i,length,flag=0;
    
    length=strlen(str)
    scanf("%s",&str);     //input string from user
    
    for(i=0;i<length(str);i++){
        if(str[i]!=str[length-i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("given string is not a palindrome");
    else
        printf("given string is a plaindrome");
    return 0;
}   
