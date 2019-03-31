#include<stdio.h>
//#include<stdlib.h>

void mergesort(long int *arr1, int p , int q ,long int *arr2);
int merge(long int *arr1,int l,int m1, int m2, int h, long int *arr2 );

int main()
{ 

  int length;

  long int n;
  printf("Number of elements in the array : ");
  scanf("%ld",&n);
  
  long int* arr1 = (long int *)malloc(n * sizeof(long int));
  long int* arr2=(long int *)malloc (n * sizeof(long int ));
  
  int i=0;
  long int num;

  

  while(i<n)
  {
    printf("Enter the %d number : ", i + 1);
    scanf("%ld",&num);
	  arr1[i]=num;
	  arr2[i]=num;
	  i++;
  }
  length =i;
  
  
  i=0;
 
  mergesort(arr1, i, length,arr2);
  
  for(i=0;i<length;i++)
  {
	  printf("%ld ", arr1[i]); 
  }
  
 return(0); 
}

void mergesort(long int *arr2, int start , int end,long int *arr)
{
  int r1, r2;
  if( end -start <2 )
	return;
  
  
	r1 = start+(end-start)/3;
	r2= start +(end-start)*2 /3 ;
		
	mergesort(arr, start, r1,arr2);
	
	mergesort(arr, r1, r2, arr2);
	
	mergesort(arr, r2, end,arr2);
	merge(arr, start, r1, r2, end, arr2);
  
}

int merge(long int *arr2,int l,int m1, int m2, int h,long int *arr)
{
   
   int i =l ;
   int j=m1;
   int p=m2;
   //int q=h;
   int k =l;
   while((i<m1) && (j< m2) && ( p< h))
   {
	if (arr2[i]<arr2[j])
	{
		if(arr2[i]< arr2[p])
			arr[k++] = arr2[i++];
		else 
			arr[k++]= arr2[p++];				
	}
	else
	{
		if(arr2[j]< arr2[p])
			arr[k++] = arr2[j++];
		else
			arr[k++] = arr2[p++];
	}
   }

   while((i<m1) && ( j < m2))
   {
	if(arr2[i]< arr2[j])
		arr[k++] = arr2[i++];
	else
		arr[k++]= arr2[j++];
   }
   while((j<m2) && ( p < h))
   {
	if(arr2[j]< arr2[p])
		arr[k++] = arr2[j++];
	else
		arr[k++]= arr2[p++];
   }
   while((i<m1) && ( p < h))
   {
	if(arr2[i]< arr2[p])
		arr[k++] = arr2[i++];
	else
		arr[k++]= arr2[p++];
   }
   while(i<m1)
   	arr[k++] = arr2[i++];
   while(j<m2)
   	arr[k++] = arr2[j++];
   while(p<h)
   	arr[k++] = arr2[p++]; 
  
   
}


