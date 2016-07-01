/*                                                               KADANE ALGORITHM
                                                    (To Find Largest Sum Contiguous Subarray)
*/
#include <iostream>
#define max(a,b) (a>=b)? a:b

using namespace std;

int max_contigious_sum(int array[] ,int size)
{
  int max_so_far      = INT_MIN;        
  int max_ending_here = 0;
  int max_element     = INT_MIN;

  for (int i = 0; i < size; i++)
  {
    max_ending_here = max(max_ending_here + array[i], 0);
    max_so_far      = max(max_ending_here, max_so_far);
    max_element     = max(max_element, array[i]);
  }

  if (max_so_far == 0)                        //       It means when all numbers are negative,
    max_so_far = max_element;                 // we need to return maximum number though it is negative.

  return max_so_far;
}

int main()
{ 
  int array[100],size;
  cout << "Enter size of array : ";
  cin >> size;
  for(int i = 0; i < size; i++)
    cin>>array[i];

  int max_sum = max_contigious_sum(array, size);
  cout << max_sum << endl;
  return 0;
}

/*
------------------------------------EXAMPLE OUTPUT------------------------------
 
       Array                         Maximum Sub-Array              sum 
-----------------------            -----------------------          ---- 
{5, 7, 12, 0, -8, 6}                   {5, 7, 12}                    24 
{6, -2, -3, 4, -1, 10 }            {6, -2, -3, 4, -1, 10 }           14
 {-1, -3, -4, -7, -8, -2}                 {-1}                       -1 
 {1, -5, 2, -1, 3}                      {2, -1, 3}                    4

*/
