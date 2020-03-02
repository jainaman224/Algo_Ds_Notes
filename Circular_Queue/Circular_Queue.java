/* Circular Queue works by the process of circular increment
i.e. when we try to increment any variable and we reach the end of queue,
we start from the beginning of queue by modulo division with the queue size.*/

import java.util.Scanner;

public class Circular_Queue {
    int front, rear, size;
    int[] arr;

    public Circular_Queue(int s) {
        size = s;
        arr = new int[s];
        front = rear = -1;
    }

    public static void main(String[] args) {
        int choice, value, s;
        Scanner in = new Scanner(System.in);

        System.out.println("Enter the size of queue:");
        s = in.nextInt();
        Circular_Queue q = new Circular_Queue(s);
        do {
            System.out.println("\n1. Insert");
            System.out.println("2. Delete");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            System.out.println("Enter choice: ");
            choice = in.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("\nEnter the value: ");
                    value = in.nextInt();
                    q.enQueue(value);
                    break;
                case 2:
                    value = q.deQueue();
                    if(value == -1) {
                        System.out.println("\nUNDERFLOW! Queue is Empty.");
                        break;
                    }
                    System.out.println("\n" + value + " Deleted from queue.");
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice.");

            }
        } while (choice != 4);

    }

    /*
Insertion:
1) Check whether queue is Full by (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)).
2) If it is full then display Queue is full. If queue is not full then, check
    if (front == -1) then set front = rear = 0 and insert the first element.
3) If (rear == SIZE – 1 && front != 0) if it is true then set rear = 0 and insert element.
4) Otherwise increment rear by 1 and insert an element.
*/
// Inserting the value in the queue
    public void enQueue(int value) {
        if ((front == 0 && rear == size - 1) ||
                (rear == (front - 1) % (size - 1))) {
            System.out.println("\nOVERFLOW! Queue is Full.");
            return;
        } else if (front == -1) /* Insert First Element */ {
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            rear++;
            arr[rear] = value;
        }
    }

    /*
Deletion:
1) Check whether queue is Empty with (front==-1).
2) If it is empty then display Queue is empty.
3) If queue is not empty then remove the element and Check if (front==rear)
   if it is true then set front = rear= -1 else set front = (front + 1) % size and return the element.
*/
// Deleting from queue
    public int deQueue() {
        if (front == -1) {
            return -1;

        }
        int element = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            if (front == size - 1)
                front = 0;
            else
                front = front + 1;
        }
        return element;
    }

    // Displaying the queue
    public void display() {
        if (front == -1) {
            System.out.println("UNDERFLOW! Queue is Empty.");
            return;
        }
        System.out.println("\nElements in Circular Queue are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                System.out.print(arr[i] + "\t");
        } else {
            for (int i = front; i < size; i++)
                System.out.println(arr[i] + "\t");

            for (int i = 0; i <= rear; i++)
                System.out.println(arr[i] + "\t");
        }
    }

}
/*
Enter the size of queue:
4

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
1

Enter the value:
10

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
1

Enter the value:
20

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
1

Enter the value:
30

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
1

Enter the value:
40

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
1

Enter the value:
50

OVERFLOW! Queue is Full.

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
3

Elements in Circular Queue are:
10	20	30	40
1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
2

10 Deleted from queue.

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
2

20 Deleted from queue.

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
2

30 Deleted from queue.

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
2

40 Deleted from queue.

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
2

UNDERFLOW! Queue is Empty.

1. Insert
2. Delete
3. Display
4. Exit
Enter choice:
4
 */
