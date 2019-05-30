import 'dart:io';

class HeapSort {
    List<int> array;
    HeapSort(this.array);

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

    void heap(List list, int n, int i) 
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && list[l] > list[largest]) 
        {
            largest = l;
        }

        if (r < n && list[r] > list[largest]) 
        {
            largest = r;
        }

        if (largest != i) 
        {
            swapList(list, i, largest);
            heap(list, n, largest);
        }
    }

    void swapList(List list, int i, int largest) 
    {
        int swap = list[i];
        list[i] = list[largest];
        list[largest] = swap;
    }

    void heapSort(List list) 
    {
        int n = list.length;
        for (int i = (n ~/ 2); i >= 0; i--) 
        {
            heap(list, n, i);
        }

        for (int i = n - 1; i >= 0; i--) 
        {
            swap(list, i);
            heap(list, i, 0);
        }
    }

    void swap(List list, int i) 
    {
        int temp = list[0];
        list[0] = list[i];
        list[i] = temp;
    }
}

void main() 
{
    List<int> array = []; // new empty array
    HeapSort sort = HeapSort(array); // pass it as argument
    print('Enter number of elements:');
    var input = stdin.readLineSync();
    int n = int.parse(input);
    sort.readArray(sort.array, n);
    sort.heapSort(array); // use the objects' array to do the sort
    print('Sorted array is:');
    sort.printArray(sort.array); //print out the sorted array
}

/* Sample Input and Output
  Enter number of elements:
9
Add number to array :
76
Add number to array :
45
Add number to array :
34
Add number to array :
12
Add number to array :
908
Add number to array :
67
Add number to array :
231
Add number to array :
1
Add number to array :
456
Sorted array is:
1
12
34
45
67
76
231
456
908
 */
