#include<iostream>
using namespace std;


int mergefn(int arr[],int temp[],int left,int mid,int right)
{
// temp[] is the auxillary array to store the sorted elements



    int i=left;
    int j=mid;
    int k=left;
    int inv_cnt=0;



    while((i<=mid-1 ) && (j<=right))
    {

        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {

            temp[k++]=arr[j++];
            inv_cnt+=(mid-i);
            
            /* 
             if arr[i] is greater than arr[j], then there are (mid – i) inversions. because left and right subarrays are sorted,
             so all the remaining elements in left-subarray (arr[i+1], arr[i+2] … arr[mid]) will be greater than arr[j]*/
        }



    }


    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];



    for(i=left;i<=right;i++)
        arr[i]=temp[i];

    return inv_cnt;


}


int mergesort(int arr[],int temp[],int left,int right)
{

 int inv_cnt=0;

    if(right>left)
    {

        int mid=(left+right)/2;


        inv_cnt+=mergesort(arr,temp,left,mid);// counting inversions in left subarray
        inv_cnt+=mergesort(arr,temp,mid+1,right);//counting inversions in the right subarray 
        inv_cnt+=mergefn(arr,temp,left,mid+1,right);// count overall inversions while merging the left subarray and right subarray

    }
    return inv_cnt;
}




int main()
{
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int temp[n];
    cout<<mergesort(arr,temp,0,n-1)<<endl;
    }
    return 0;

}


/* 
Sample Input
2
4
1 2 4 3
3
3 2 1
Sample Output
1
3
*/
