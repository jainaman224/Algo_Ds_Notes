include<stdio.h>


int main()
{
   
   
    int d = 0;
   
    int a[20][20] ;
    int i = 0;
    int j = 0;
   
    int ra = 0;
    int ca = 0;
    int r = 0;
    int c = 0;
    int k = 0;
   
   
   
   
    do
    {
    printf("enter number of rows:");
    scanf("%d" , &ra);
    }while(ra<1);
   
    do
    {
    printf("enter number of columns:");
    scanf("%d" , &ca);
    }while(ca<1);
   
   
    printf("\n\t enter elements:");
   
    printf("\n");
   
    for(i=0 ; i<ra ; i++)
    {
        for(j=0 ; j<ca ; j++)
        {
            scanf("%d" , &a[i][j]);
        }
    }
   
    printf(" INTIAL MATRIX = ");
   
    for(i=0 ; i<ra ; i++)
    {
        printf("\n");
       
        for(j=0 ; j<ca ; j++)
        {
            printf("%d" , a[i][j]);
        }
    }
   
   
    printf("\n");
    printf("spiral form = ");
    printf("\n");
   
    r = ra - 1;
    c = ca - 1;
   
    i = 0;
    j = 0;
   
    while(i<=c && j<=r)
    {
        if(d == 0)
        {
            for(k=i ; k<=c ; k++)
            {
                printf("%d" , a[j][k]);
            }
           
            j++;
            d = 1;
           
        }
       
        else if(d == 1)
        {
            for(k=j ; k<=r ; k++)
            {
                printf("%d" , a[k][c]);
            }
               
            c--;
            d = 2;
           
        }
       
        else if(d == 2)
        {
            for(k=c ; k>=i ; k--)
            {
                printf("%d" , a[r][k]);
            }
           
            r--;
            d=3;
        }
       
        else if(d == 3)
        {
            for(k=r ; k>=j ; k--)
            {
                printf("%d" , a[k][i]);
            }
           
            i++;
            d = 0;
        }
    }


return 0;

}


// Test Cases

Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

//
