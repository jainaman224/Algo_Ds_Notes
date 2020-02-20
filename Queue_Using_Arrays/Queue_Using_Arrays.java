/*
 * This code is designed to create a special data structure called queue
 * Queue works on the first come first out(FIFO) logic
 */
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
		last = (last + 1)% data.length;
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
		first = (first + 1)% data.length;
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
		data = new int[2*data.length];
		int j = 0;
		int temp1 = first;
		for(int i=first; i<temp.length; i++, j++) {
			data[j] = temp[i];
		}	
		for(int i=0; i<=first-1; i++, j++) {
			data[j] = temp[i];
		}
		last = temp.length -1;
		first = 0;
	}	
}

//main class to use the class queueUsingArray
public class Queue_Using_Arrays {
	public static void main(String[] args) throws QueueEmptyException {
		queue q = new queue();
		for(int i=1; i<16; i++) {
			q.push(i);
		}
		
		while(!q.isEmpty()) {
			try {
				System.out.print(q.pop() + " ");
			} catch (QueueEmptyException e) {
				// will never reach
			}
		}
		
		System.out.println();
	}
}

//exception class
class QueueEmptyException extends Exception {
	private static final long serialVersionUID = 1L;
}
