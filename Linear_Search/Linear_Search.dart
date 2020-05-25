//Linear search or sequential search is a method for finding an element within a list.
//It sequentially checks each element of the list until a match is found or the whole list has been searched.
import 'dart:io';

void linearSearch(List<int> list, int x) {
    int pass = 0;
    list.forEach((val) {
        if (val == x) {
            print('Found $x in the List!');
            pass = 1;
        }
    });
    if (pass == 0) print('Did not find $x in the List!');
}

main() {
    List<int> list = new List();
    int task = 0;
    print('Linear Search Program');
    while (task != 4) {
        print(
                '0 - Display List\n1 - Insert element in List \n2 - Search element in List\n3 - Quit\nSelect task:-');
        try {
            task = int.parse(stdin.readLineSync());
        } on Exception {
            print('Please enter valid Integer value!');
            continue;
        }
        switch (task) {
            case 0:
                if (list.length == 0) {
                    print('Empty List!');
                } else {
                    print('List:-');
                    list.forEach((val) {
                        print(val);
                    });
                }
                break;
            case 1:
                int val = null;
                print('Enter value that needs to be inserted in List:- ');
                try {
                    val = int.parse(stdin.readLineSync());
                } on Exception {
                    print('Please enter valid Integer value!');
                    continue;
                }
                if (val == null) {
                    print('Failed to insert element in List!');
                    continue;
                }
                list.add(val);
                print('Successfully inserted $val in List!');
                break;

            case 2:
                int val = null;
                print('Enter value that needs to be searched in List:- ');
                try {
                    val = int.parse(stdin.readLineSync());
                } on Exception {
                    print('Please enter valid Integer value!');
                    continue;
                }
                if (val == null) {
                    print('Failed to search element in List!');
                    continue;
                }
                linearSearch(list, val);
                break;

            case 3:
                print('Linear Search Program Complete');
                break;

            default:
                continue;
        }
    }
}

/*
Sample Input/Output:
Linear Search Program
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-		//to insert element in list
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
Select task:-		//to search the given element
2
Enter value that needs to be searched in List:- 
2
Found 2 in the List!
0 - Display List
1 - Insert element in List
2 - Search element in List
3 - Quit
Select task:-		//to end the linear program algorithm
3
Linear Search Program Complete
*/
