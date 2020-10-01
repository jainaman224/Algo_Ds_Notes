import 'dart:io';

class MergeSort {
    List<int> array;
    MergeSort(this.array);

    void readArray(List<int> a, int n) 
    {
        for (int i = 0; i < n; i++) 
        {
            print('Add number to array : ');
            var input = stdin.readLineSync();
            int x = int.parse(input);
            assert(x is int);
            a.add(x);
        }
    }

    void printArray(List<int> a) 
    {
        for (var i = 0; i < a.length; i++) 
        {
            print(a[i]);
        }
    }

    void merge(List list, int leftIndex, int middleIndex, int rightIndex) 
    {
        int leftSize = middleIndex - leftIndex + 1; // specifying the size of left array
        int rightSize = rightIndex - middleIndex; // right array size

        List leftList = new List(leftSize); // make the array
        List rightList = new List(rightSize);

        for (int i = 0; i < leftSize; i++)
        {
            leftList[i] = list[leftIndex + i];
         } // making the arrays
        for (int j = 0; j < rightSize; j++)
        {
            rightList[j] = list[middleIndex + j + 1];
        }
        int i = 0, j = 0;
        int k = leftIndex;

        while (i < leftSize && j < rightSize) 
        {
            if (leftList[i] <= rightList[j]) 
            {
                list[k] = leftList[i];
                i++;
            } 
            else 
            {
                list[k] = rightList[j];
                j++;
            }
            k++;
        }

        while (i < leftSize) 
        {
            list[k] = leftList[i];
            i++;
            k++;
        }

        while (j < rightSize) 
        {
            list[k] = rightList[j];
            j++;
            k++;
        }
    }

    void mergeSort(List list, int leftIndex, int rightIndex) 
    {
        if (leftIndex < rightIndex) 
        {
            int middleIndex = (rightIndex + leftIndex) ~/ 2;

            mergeSort(list, leftIndex, middleIndex);
            mergeSort(list, middleIndex + 1, rightIndex);

            merge(list, leftIndex, middleIndex, rightIndex);
        }
    }
}

void main()
{
    List<int> array = []; // new empty array
    MergeSort sort = MergeSort(array); // pass it as argument
    print('Enter number of elements:');
    var input = stdin.readLineSync();
    int n = int.parse(input);
    sort.readArray(sort.array, n); 
    sort.mergeSort(array, 0, n-1); // use the objects' array to do the sort
    print('Sorted array is:');
    sort.printArray(sort.array); //print out the sorted array
}

/* Sample Input and Output
Enter number of elements:
6
Add number to array :
2
Add number to array :
5
Add number to array :
4
Add number to array :
1
Add number to array :
6
Add number to array :
3
Sorted array is:
1
2
3
4
5
6
*/
