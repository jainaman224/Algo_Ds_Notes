import 'dart:io';

class CountingSort {
  List<int> array = [];
  CountingSort(this.array);

  //function to accept values into the array for sorting
  void inputArray(List<int> arr, int size) {
    for (int i = 0; i < size; i++) {
      print('Enter element number $i: ');
      var input = stdin.readLineSync();
      int foo = int.parse(input);
      assert(foo is int && foo > 0); //make sure that the input foo is an integer
      arr.add(foo);
    }
  }


  //function to print the array
  void printArray(List<int> arr) {
    for (var i = 0; i < arr.length; i++)
      print(arr[i]);
  }
  
  
  //function to perform counting sort
  void sortingLogic(List<int> arr, int size) {
    
    //find the value of the largest element
    int max = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i] > max) 
        max = arr[i];
    }
    
    List<int> count = new List(max+1);
    //populate temporary array with zeroes
    for (int i = 0; i < max+1; i++)
      count[i] = 0;
    
    //update newly created count array with number of occurrences 
    for (int i = 0; i < size; i++)
      count[arr[i]]++;
    
    int j = 0;
    for (int i = 0; i < max+1; i++) {
      if (count[i] != 0) {
        int times  = count[i];
        while (times > 0) {
          arr[j++] = i;
          times--;
        }
      }
    }
  }
}

void main() {
  List<int> array = []; //initializing an empty list of integers
  CountingSort countingSort = new CountingSort(array);

  print('How many elements to sort? ');
  var numberOfElements = stdin.readLineSync();
  int size = int.parse(numberOfElements);

  countingSort.inputArray(countingSort.array, size);
  countingSort.sortingLogic(countingSort.array, size);
  
  print('Sorted array is: ');
  countingSort.printArray(countingSort.array);
}

// How many elements to sort?
// 5
// Enter element number 0:
// 23
// Enter element number 1:
// 33
// Enter element number 2:
// 43
// Enter element number 3:
// 53
// Enter element number 4:
// 63
// Sorted array is:
// 23
// 33
// 43
// 53
// 63
