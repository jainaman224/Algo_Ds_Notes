//=====*****=====*****=====*****======******//


/*Time-Complexity:O(n)*/


//****************************************//


#include<stdio.h>
double e(int x,int n)
{

    static double s;
    if(n==0)
    {

        return s;
    }
    s=1+x*(s/n);
    return e(x,n-1);
}
int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    printf("%lf \n",e(x,n));
}
/*Input:-2 10
  Output:-
7.388713
*/
