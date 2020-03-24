/* Binary Insertion sort is a special type up of Insertion sort which uses binary search algorithm to find out the correct position 
   of the inserted element in the array. */

CODE:

void insertionSort(List ar)
{
  for(int i=0;i<ar.length;i++)
  {
    int temp = ar[i];
    int pos = binarySearch(ar, temp, 0, i) + 1;
    for(int k=i;k>pos;k--)
    {
      ar[k] = ar[k-1];
    }
    ar[pos] = temp;
  }
}

int binarySearch(List ar, int key, int start, int end)
{
  if(end-start <= 1)
  {
    if(key<ar[start])
    {
      return start-1;
    }
    else
    {
      return start;
    }
  }
  int mid = (start+end)~/2;
  if(ar[mid] < key)
  {
    return binarySearch(ar, key, mid, end);
  }
  else if(ar[mid] > key)
  {
    return binarySearch(ar, key, start, mid);
  }
  else
  {
    return mid;
  }
      
}
main()
{
  List ar = [1,5,3,4,8,6];
  int n = ar.length;
  insertionSort(ar);
  print("Sorted array is:");
  for(int i=0;i<n;i++)
  {
    print(ar[i]);
  }
}

/* OUTPUT:
   Sorted Array is: [1,3,4,5,6,8] */
   

