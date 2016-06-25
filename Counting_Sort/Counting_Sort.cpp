#include <iostream>

using namespace std;

// The main function that sort the given input
void counting_sort(int input[] ,int k, int n)
{
  // The output will have sorted input array
   int output[n];
   //Create a count_array to store count of each individual input value
   int count_array[k],i,j;
   std::fill_n(count_array,k,0);//Initialize count_array elements as zero

    //store count of each individual input value
    for(i=0;i<n;i++)
    {
        count_array[input[i]]++;
    }


    //Change count_array so that count_array now contains actual
    // position of input values in output array
    for(i=1;i<k;i++)
    {
        count_array[i]+=count_array[i-1];
    }

    //populate output array using count_array and input array
    for(i=n-1;i>=0;i--)
    {
        output[(count_array[input[i]])-1]=input[i];
        count_array[input[i]]--;

    }

    //Copy the output array to input, so that input now contains sorted values
    for(i=0;i<n;i++)
        input[i]=output[i];
}


// Driver program to test above function
int main()
{
    int n,i,k=0;
    cout <<"Enter Input Array size"<< endl;
    cin>>n;

    int *input= new int[n];
    cout<<"Enter Input Values"<<endl;

    for(i=0;i<n;i++)
    {
        cin>>input[i];
        if (input[i] > k)//find the range of input values
        k = input[i];
    }
    k++; //k is the size of count_array

    counting_sort(input,k,n);

    cout<<"Output: ";
    for(i=0;i<n;i++)
        cout<<input[i]<<"  ";

    return 0;
}
