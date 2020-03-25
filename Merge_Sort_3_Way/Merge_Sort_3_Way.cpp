#include "iostream"
#include <vector>
using namespace std;

//function for storing elements from three vectors(left,mid,right) in sorted manner in vector named sorted
// sorted vector must be passed by reference to see the effect of changes made by the function
// other vectors are passed as reference to avoid copying of elements repeatedly

void mergeVersion3(vector <int> &sorted,vector <int> &left,vector <int> &mid,vector <int> &right)
{
    int i = 0; //index pointer variable for left vector
    int j = 0; //index pointer variable for mid vector
    int k = 0; //index pointer variable for right vector
    int l = 0; //index pointer variable for sorted vector
    // selecting the minimum element of from the three vectors when all are non-empty
    while( (i < left.size()) && (j<mid.size()) && (k < right.size()) )
    {
        if ( (left[i] < mid[j]) && (left[i] < right[k]) ) 
            { 
                sorted[l++] = left[i++]; 
            }
        else if ( (mid[j] < left[i]) && (mid[j] < right[k]) ) 
            { 
                sorted[l++] = mid[j++]; 
            }
        else 
            { 
                sorted[l++] = right[k++]; 
            }
    }

    //selecting minimum of two vectors when right vector is empty

    while( (i < left.size()) && (j<mid.size()) )
    {
        if( left[i] < mid[j] )
        {
            sorted[l++] = left[i++];
        }
        else
        {
            sorted[l++] = mid[j++];
        }
    }

    //selecting minimum of two vectors when left vector is empty

    while( (j < mid.size()) && (k < right.size()) )
    {
        if( mid[j] < right[k] )
        {
            sorted[l++] = mid[j++];
        }
        else
        {
            sorted[l++] = right[k++];
        }
    }

    //selecting minimum of two vectors when mid vector is empty

    while( (i < left.size()) && (k < right.size()) )
    {
      if( left[i] < right[k] )
      {
        sorted[l++] = left[i++];
      }
      else
      {
        sorted[l++] = right[k++];
      }
    }

    // copying remaining elements from left vector when mid and right vector are empty

    while(i < left.size())
    {
        sorted[l++] = left[i++];
    }

    // copying remaining elements from mid vector when left and right vector are empty

    while( j < mid.size() )
    {
        sorted[l++] = mid[j++];
    }

    // copying remaining elements from right vector when mid and left vector are empty

    while( k < right.size() )
    {
        sorted[l++] = right[k++];
    }
}

vector <int> mergeSort3ways(vector<int> &input)
{
    if( input.size() == 1 )
    {
        return input;
    }
    else if( input.size() == 2 )
    {

        //two different vectors (element1 and element2) of size 1 to store one element each and no_element vector of size 0

        vector<int>element1,element2,no_element(0);
        element1.emplace_back(input.at(0));
        element2.emplace_back(input.at(1));

        //call merging of three vectors and then return  sorted vector

        mergeVersion3(input,element1,element2,no_element);
        return input;
    }
    else
    {   int left_size {0}, right_size {0}, mid_size {0};
        if( input.size() % 3 == 0 )
        {
            left_size = int(input.size() / 3);
            mid_size = int(input.size() / 3);
            right_size = int(input.size() / 3);
        }
        else if( input.size() % 3 == 1 )
        {
            left_size = int(input.size() / 3) + 1;
            mid_size = int(input.size() / 3);
            right_size = int(input.size() / 3);
        }
        else if( input.size() % 3 == 2 )
        {
            left_size = int(input.size() / 3) + 1;
            mid_size = int(input.size() / 3);
            right_size = int(input.size() / 3) + 1;
        }

        // dividing original vector into three vectors left_vec,mid_vec,right_vec

        vector <int> left_vec,right_vec,mid_vec;
        for (int i = 0; i < left_size ; ++i)
        {
            left_vec.emplace_back(input[i]);
        }
        for (int i = 0; i < mid_size ; ++i)
        {
            mid_vec.emplace_back(input[i + left_size]);
        }
        for (int i = 0; i < right_size ; ++i)
        {
            right_vec.emplace_back(input[i + left_size + mid_size]);
        }

        //dividing the three vectors recursively

        mergeSort3ways(left_vec);
        mergeSort3ways(mid_vec);
        mergeSort3ways(right_vec);

        // sorting the vector

        mergeVersion3(input,left_vec,mid_vec,right_vec);
        return input;
    }

}

// Driver Code

int main()
{
    int n {0} , temp {0}; //initializes the variables n  and temp to zero just after creation , it is not assignment
    cin >> n;  //input for number of elements in input array/vector
    vector <int> input , result;  //vector to take input of all elements

    // taking input of n elements in a vector

    for (int i = 0; i < n ; ++i) {
        cin >> temp;
        input.emplace_back(temp); //emplace_back is more efficient than push_back
    }

    // sorted vector is returned to result vector

    result = mergeSort3ways(input);

    // Displaying the sorted Vector

    for(auto c : result)
    {
        cout << c << " ";
    }
    return 0;
}
// Sample Test Cases
// Input
// 5
// 78 8 6 5 7
// Output
// 5 6 7 8 78
// input
// 10
// -8 45 -9 47 34 2 5 21 987 -3
// Output
// -9 -8 -3 2 5 21 34 45 47 987
