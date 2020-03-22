import java.util.*;
public class arrayList {
    public static void main(String[] args) {
       
        // Creating a Scanner Object
        Scanner scan = new Scanner(System.in);
        
        // Creating the ArrayList
        List<Integer> li = new ArrayList<Integer>();
        
        char choice='y';
        int value, index;
        System.out.println("Enter 1 to add Objects to the list");
        System.out.println("Enter 2 to add Object at a particular index to a list");
        System.out.println("Enter 3 to check size of the list");
        System.out.println("Enter 4 to remove an element from particular index");
        System.out.println("Enter 5 to get an element at a particular index");
        System.out.println("Enter 6 to replace an element at a particular index");
        System.out.println("Enter 7 to find the index of an element");
        System.out.println("Enter 8 to search for the last occurence index of element in the list");
        System.out.println("Enter 9 to check whether an element exists in the list");
        System.out.println("Enter 10 to clear the list");
        System.out.println("Enter 11 to check whether the list is empty or not");
        System.out.println("Enter 12 to create a sublist from the list");
        System.out.println("Enter 13 to print the list");
        while(choice=='y')
        {
            System.out.println("Enter your choice");
            int input = scan.nextInt();
            switch(input)
            {
                case 1: System.out.println("Enter value to be added");
                        value=scan.nextInt();
                        li.add(value);
                    break;
                case 2: System.out.println("Enter the index and value of element to be added");
                        index=scan.nextInt();
                        value=scan.nextInt();
                        li.add(index,value);
                    break;
                case 3: System.out.println("Size of list: "+li.size());
                    break;
                case 4: System.out.println("Enter index of element to be removed");
                        index=scan.nextInt();
                        li.remove(index);
                        System.out.println("Element removed successfully!");
                        System.out.println("After Deletion: "+li);
                    break;
                case 5: System.out.println("Enter index of element");
                        index=scan.nextInt();
                        System.out.println("Element is: "+li.get(index));
                    break;
                case 6: System.out.println("Enter index and value of element to be replaced");
                        index=scan.nextInt();
                        value=scan.nextInt();
                        li.set(index,value);
                        System.out.println("After replacing: "+li);
                    break;
                case 7: System.out.println("Enter value of element whose index to be found");
                        value=scan.nextInt();
                        System.out.println("Value is: "+li.indexOf(value));
        
                    break;
                case 8: System.out.println("Enter the value of element whose last occurence index is to be found");
                        value=scan.nextInt();
                        System.out.println("Value is:"+li.lastIndexOf(value));
                    break;
                case 9: // Check if an element exists in the Array List
                        System.out.println("Enter value of element");
                        value=scan.nextInt();
                        boolean find = li.contains(value);
                        if(find) {
                            System.out.println("Element is in the list");
                        }
                        else
                        {
                            System.out.println("Element is not in the list");
                        }
                    break;
                case 10: // To clear all elements in array
                         li.clear();
                    break;
                case 11: // To check whether the list is empty or not.
                         System.out.println("Is the list empty? "+li.isEmpty());
                    break;
                case 12: // To print sublist 
                         int start,end;
                         System.out.println("Enter starting and ending index");
                         start=scan.nextInt();
                         end=scan.nextInt();
                         List<Integer> sublist = new ArrayList<Integer>();
                         sublist = li.subList(start,end);
                         System.out.println(sublist);
                    break;
                case 13: // Creating an Iterator to traverse the arraylist.
                         Iterator itr = li.iterator(); 
                         while(itr.hasNext())
                         {
                            System.out.println(itr.next());
                         }
                    break;
                default: System.out.println("Invalid option entered");
                    break;
                    
            }
            System.out.println("Do you want to continue? Enter 'y' for more inputs or 'n' to stop");
            choice=scan.next().charAt(0);
        }
    }
}

/* 
Sample Input
Enter 1 to add Objects to the list
Enter 2 to add Object at a particular index to a list
Enter 3 to check size of the list
Enter 4 to remove an element from particular index
Enter 5 to get an element at a particular index
Enter 6 to replace an element at a particular index
Enter 7 to find the index of an element
Enter 8 to search for the last occurence index of element in the list
Enter 9 to check whether an element exists in the list
Enter 10 to clear the list
Enter 11 to check whether the list is empty or not
Enter 12 to create a sublist from the list
Enter 13 to print the list
Enter your choice
1
Enter value to be added
100
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
1
Enter value to be added
200
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
1
Enter value to be added
300
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
2
Enter the index and value of element to be added
2
1000
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
3
Size of list: 4
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
4
Enter index of element to be removed
2
Element removed successfully!
After Deletion: [100, 200, 300]
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
5
Enter index of element
2
Element is: 300
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
6
Enter index and value of element to be replaced
1
200
After replacing: [100, 200, 300]
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
7
Enter value of element whose index to be found
100
Value is: 0
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
8
Enter the value of element whose last occurence index is to be found
200
Value is:1
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
9
Enter value of element
100
Element is in the list
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
11
Is the list empty? false
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
12
Enter starting and ending index
1
2
[200]
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
13
100
200
300
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
y
Enter your choice
9
Enter value of element
12
Element is not in the list
Do you want to continue? Enter 'y' for more inputs or 'n' to stop
n
*/