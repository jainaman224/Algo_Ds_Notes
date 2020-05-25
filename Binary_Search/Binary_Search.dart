//Binary Search is an efficient algorithm for finding an item from a sorted list of items.
//This is the implementation of Binary Search in dart language to insert and search the elements.
import 'dart:io';

void binarySearch(List<int> list, int x){
    int size = list.length;
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = ((low + high) / 2).floor();
        if(list[mid] == x){
            print('Found $x in the List at Index $mid!');
            return;
        }
        if(list[mid] > x){
            high = mid - 1;
            continue;
        }
        low = mid + 1;
    }
    print('Did not $x in the List!');
    return;
}

main(){
    List<int> list = new List();
    int task = 0;
    print('Binary Search Program');
    while(task != 4){
        print('0 - Display List\n1 - Insert element in List \n2 - Search element in List\n3 - Quit\nSelect task:-');
        try{
            task = int.parse(stdin.readLineSync());
        } on Exception{
            print('Please enter valid Integer value!');
            continue;
        }
        switch(task){
            case 0:
                if(list.length == 0){
                    print('Empty List!');
                } 
                else{
                    print('List:-');
                    list.forEach((val){
                        print(val);
                    });
                }
                break;
            case 1:
                int val = null;
                print('Enter value that needs to be inserted in List:- ');
                try{
                    val = int.parse(stdin.readLineSync());
                } on Exception{
                    print('Please enter valid Integer value!');
                    continue;
                }
                if(val == null){
                    print('Failed to insert element in List!');
                    continue;
                }
                list.add(val);
                list.sort();
                print('Successfully inserted $val in List!');
                break;

            case 2:
                int val = null;
                print('Enter value that needs to be searched in List:- ');
                try{
                    val = int.parse(stdin.readLineSync());
                } on Exception{
                    print('Please enter valid Integer value!');
                    continue;
                }
                if(val == null){
                    print('Failed to search element in List!');
                    continue;
                }
                binarySearch(list, val);
                break;
            
            case 3:
                print('Binary Search Program Complete');
                break;
                default:
                continue;
        }
    }
}


/*
Sample Input/Output:
Binary Search Program
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-		//to add element
1
Enter value that needs to be inserted in List:- 
1
Successfully inserted 1 in List!
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-
1
Enter value that needs to be inserted in List:- 
2
Successfully inserted 2 in List!
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-
1
Enter value that needs to be inserted in List:- 
3
Successfully inserted 3 in List!
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-		//to display the list
0
List:-
1
2
3
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-		//to search the element
2
Enter value that needs to be searched in List:- 
2
Found 2 in the List at Index 1!
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-		//quiting the program
3
Binary Search Program Complete
*/
