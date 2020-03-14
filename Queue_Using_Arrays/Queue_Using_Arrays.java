/*
 * This code is designed to create a special data structure called queue
 * Queue works on the first come first out(FIFO) logic
 *
 */

import java.util.Scanner;

class queue {
	//initialization
	private int data[];
	private int first;
	private int last;
	private int size;
	
	//constructor
	public queue() {
		data = new int[10];
		first = -1;
		last = -1;
		size = 0;
	}
	
	//parametric constructor
	public queue(int capacity){
		data = new int[capacity];
		first = -1;
		last = -1;
		size = 0;
	}
	
	//isEmpty function - returns true if empty, false otherwise
	public boolean isEmpty() {
		return (size == 0);
	}
	
	//size function - returns the number of elements of queue
	public int size() {
		return size;
	}
		
	//returns the first element in the queue
	public int first() throws QueueEmptyException {
		if(isEmpty()) {
			QueueEmptyException e = new QueueEmptyException();
			throw e;
		}
		return data[first];
	}
		
	//adds an element in the last
	public void push(int element) {
		if(isEmpty()) {
			first = 0;
		}
		if(size ==  data.length) {     //if there is no space left in the queue
			doubleArray();             //double the size of queue
		}
		if(last == data.length) {
			last = -1;
		}
		last = (last + 1) % data.length;
		data[last] = element;
		size++;
	}
		
	//remove and returns the first element of queue
	public int pop() throws QueueEmptyException {
		if(isEmpty()) {
			QueueEmptyException e = new QueueEmptyException();
			throw e;
		}
		int temp = data[first];
		first = (first + 1) % data.length;
		size--;
		if(first == 0) {
			first = -1;
			last = -1;
		}
		return temp;
	}
		
	//doubles the size of array/queue
	private void doubleArray() {
		int temp[] = data;
		data = new int[2 * data.length];
		int j = 0;
		int temp1 = first;
		for(int i = first; i < temp.length; i++, j++) {
			data[j] = temp[i];
		}	
		for(int i = 0; i <= first - 1; i++, j++) {
			data[j] = temp[i];
		}
		last = temp.length - 1;
		first = 0;
	}	
}

//main class to use the class queueUsingArray
public class QueueUsingArray {
	public static void main(String[] args) throws QueueEmptyException {
		Scanner s = new Scanner(System.in);
		queue q = new queue();
		System.out.println("=============================");
		System.out.println("          OPERATIONS         ");
		System.out.println("=============================");
		System.out.println("1. Enqueue ");
		System.out.println("2. Dequeue ");
		System.out.println("3. Size ");
		System.out.println("4. Check isEmpty ");
		System.out.println("5. First element ");
		System.out.println("0. Exit ");
		
		System.out.print("Enter the operaton you want to perform - ");
		int op = s.nextInt();
		while(op != 0) {
			if(op == 1) {
				System.out.print("Enter the data you want to add - ");
				int data = s.nextInt();
				q.push(data);
			}else if(op == 2) {
				if(q.isEmpty()) {
					System.out.println("Sorry, queue has no element");
				}else {
					System.out.println("Poped data is " + q.pop());
				}
			}else if(op == 3) {
				System.out.println("Size of queue is " + q.size());
			}else if(op == 4) {
				if(q.isEmpty()) {
					System.out.println("Yes, the queue is empty");
				}else {
					System.out.println("No, the queue is not empty");
				}
			}else if(op == 5) {
				if(q.isEmpty()) {
					System.out.println("Sorry, queue has no element");
				}else {
					System.out.println("First element in the queue is " + q.first());
				}
			}else {
				System.out.println("Input is invalid, please enter the correct option");
			}
			System.out.print("Enter the operaton you want to perform - ");
			op = s.nextInt();
		}
		
	}
	
}

//exception class
class QueueEmptyException extends Exception {
	private static final long serialVersionUID = 1L;
}

/*
 *==============================
 *Sample Input-Output
 *==============================
 *
 *==============================
          OPERATIONS         
 *==============================
 *1. Enqueue 
 *2. Dequeue 
 *3. Size 
 *4. Check isEmpty 
 *5. First element 
 *0. Exit 
 *
 *Enter the operaton you want to perform - 1
 *Enter the data you want to add - 24
 *Enter the operaton you want to perform - 1
 *Enter the data you want to add - 30
 *Enter the operaton you want to perform - 2
 *Poped data is 24
 *Enter the operaton you want to perform - 3
 *Size of queue is 1
 *Enter the operaton you want to perform - 4
 *No, the queue is not empty
 *Enter the operaton you want to perform - 5
 *First element in the queue is 30
 *Enter the operaton you want to perform - 6
 *Input is invalid, please enter the correct option
 *Enter the operaton you want to perform - 0
 */
