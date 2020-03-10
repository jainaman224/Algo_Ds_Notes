#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){   return a>b? a:b;    }

int lis(int arr[],int n)
{
        // array that contains the longest increasing subsequence until element i
        int lis[n],i,ans,j;

        for (i=0; i < n; i++) {
                lis[i]=1;
        }

        ans=-1<<30; // length of the lis starts with -infinite

        for (i=1;i<n;i++) {
                for (j=0; j < i; j++) {
                        if (arr[j]<arr[i]) {
                                lis[i]=max(lis[i], lis[j]+1);
                                ans=max(ans, lis[i]);
                        }
                }
        }

        return ans;
}

int main()
{
        // arr = array of elements
        int arr[]={10, 22, 9, 33, 21, 50, 41, 60};

        printf("Size of the longest increasing subsequence: %d ",lis(arr,8));
}
