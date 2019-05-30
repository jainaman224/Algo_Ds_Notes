import 'dart:io';

class QuickSort {
    List<int> array = [];
    QuickSort(this.array);

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

    int partition(List<int> list, int low, int high) 
    {
        int pivot = list[low];
        int i = high;
        int temp;
        for (int j = high; j > low; j--) 
        {
            if (list[j] > pivot) 
            {
                temp = list[j];
                list[j] = list[i];
                list[i] = temp;
                i--;
            }
        }
        list[low] = list[i];
        list[i] = pivot;
        return i;
    }

    void quickSort(List<int> a, int low, int high) 
    {
        if (low < high) 
        {
            int pi = partition(a, low, high);
            quickSort(a, low, pi - 1);
            quickSort(a, pi + 1, high);
        }
    }
}

void main() 
{
    List<int> array = [];
    QuickSort sort = new QuickSort(array);
    print('Enter the number of elements : ');
    var input = stdin.readLineSync();
    int n = int.parse(input);
    sort.readArray(sort.array, n);
    print('The array is:');
    sort.printArray(sort.array);
    sort.quickSort(sort.array, 0, n - 1);
    print('The sorted array is :');
    sort.printArray(sort.array);
}

/* Sample Input Output
Enter the number of elements :
6
Add number to array :
2
Add number to array :
3
Add number to array :
5
Add number to array :
6
Add number to array :
1
Add number to array :
4
The array is:
2
3
5
6
1
4
The sorted array is :
1
2
3
4
5
6
 */
